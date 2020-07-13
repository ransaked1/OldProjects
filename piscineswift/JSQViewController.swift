//
//  JSQViewController.swift
//  day07
//
//  Created by dbraghis2 on 4/27/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit
import RecastAI
import ForecastIO
import JSQMessagesViewController

let recastToken = "4f2c4c3ac1cc023c8b3260f9957fc918"
let forecastToken = "c9de638efcda57e5530737bfcaff2b2e"

struct User {
    let id: String
    let name: String
}

class JSQViewController: JSQMessagesViewController {
    let user1 = User(id: "1", name: "User")
    let user2 = User(id: "2", name: "Bot")
    
    var answerForUser: String?
    
    var bot : RecastAIClient?
    var forecastClient: DarkSkyClient?
    
    var currentUser: User {
        return user1
    }
    
    // all messages of users1, users2
    var messages = [JSQMessage]()
}

extension JSQViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // tell JSQMessagesViewController
        // who is the current user
        self.senderId = currentUser.id
        self.senderDisplayName = currentUser.name
        
        self.bot = RecastAIClient(token : recastToken, language: "en")
        self.forecastClient = DarkSkyClient(apiKey: forecastToken)
        self.forecastClient?.units = .auto
        
        self.messages = getMessages()
    }
    
    func getWeather(long: Double, lat: Double)
    {
        forecastClient?.getForecast(latitude: lat, longitude: long, completion: {
            result in
            switch result {
            case .success(let currentForecast, let RequestMetadata):
                print("Getting Weather")
                self.answerForUser = self.answerForUser! + " " + (result.value.0?.daily?.summary)!
                let message1 = JSQMessage(senderId: "2", displayName: "bot", text: self.answerForUser)
                self.messages.removeLast()
                print("Check")
                self.messages.append(message1!)
                self.finishSendingMessage()
            case .failure(let error):
                print(error)
                self.answerForUser = "Sorry the weather service isn't working right now :("
            }
        })
    }
    
    
    override func didPressSend(_ button: UIButton!, withMessageText text: String!, senderId: String!, senderDisplayName: String!, date: Date!) {
        let message = JSQMessage(senderId: senderId, displayName: senderDisplayName, text: text)
        var message1 = JSQMessage(senderId: "2", displayName: "bot", text: "Wait a moment...")
        
        messages.append(message!)
        messages.append(message1!)
        print("Sending initial messages")
        finishSendingMessage()
        
        if let text: String = "Weather in " + (message?.text)!.trimmingCharacters(in: CharacterSet.whitespacesAndNewlines)
        {
            if text != ""
            {
                self.bot?.textConverse(text, successHandler:
                    {success in
                        if var location: [String: Any] = (success.entities?["location"] as! [[String: Any]]?)?[0]
                        {
                            if (location["formatted"] != nil)
                            {
                            DispatchQueue.main.async {
                            self.answerForUser = (success.replies?[0])! + " " + (location["formatted"] as! String) + " is:"
                            let long = location["lng"] as! Double
                            let lat = location["lat"] as! Double
                            print("\(lat) and \(long)")
                            self.getWeather(long: long, lat: lat)
                                }
//                            message1 = JSQMessage(senderId: "2", displayName: "bot", text: self.answerForUser)
//                            self.messages.removeLast()
//                            print("Check")
//                            self.messages.append(message1!)
//                            self.finishSendingMessage()
                            }
                            else
                            {
                                message1 = JSQMessage(senderId: "2", displayName: "bot", text: "Please, give me a location to tell you the weather")
                                print("else")
                                self.messages.removeLast()
                                self.messages.append(message1!)
                                self.finishSendingMessage()
                            }
                        }
                        else
                        {
                            message1 = JSQMessage(senderId: "2", displayName: "bot", text: "Please, give me a location to tell you the weather")
                            print("else")
                            self.messages.removeLast()
                            self.messages.append(message1!)
                            self.finishSendingMessage()
                        }
                }, failureHandle:
                    { error in
                        DispatchQueue.main.async {
                           message1 = JSQMessage(senderId: "2", displayName: "bot", text: "Error1 " + error.localizedDescription)
                        }
                })
            }
        }
        
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView!, attributedTextForMessageBubbleTopLabelAt indexPath: IndexPath!) -> NSAttributedString! {
        let message = messages[indexPath.row]
        let messageUsername = message.senderDisplayName
        
        return NSAttributedString(string: messageUsername!)
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView!, layout collectionViewLayout: JSQMessagesCollectionViewFlowLayout!, heightForMessageBubbleTopLabelAt indexPath: IndexPath!) -> CGFloat {
        return 15
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView!, avatarImageDataForItemAt indexPath: IndexPath!) -> JSQMessageAvatarImageDataSource! {
        return nil
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView!, messageBubbleImageDataForItemAt indexPath: IndexPath!) -> JSQMessageBubbleImageDataSource! {
        let bubbleFactory = JSQMessagesBubbleImageFactory()
        
        let message = messages[indexPath.row]
        
        if currentUser.id == message.senderId {
            return bubbleFactory?.outgoingMessagesBubbleImage(with: .green)
        } else {
            return bubbleFactory?.incomingMessagesBubbleImage(with: .blue)
        }
    }
    
    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return messages.count
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView!, messageDataForItemAt indexPath: IndexPath!) -> JSQMessageData! {
        return messages[indexPath.row]
    }
}

extension JSQViewController {
    func getMessages() -> [JSQMessage]
    {
        var messages = [JSQMessage]()
        
        //let message1 = JSQMessage(senderId: "1", displayName: "Steve", text: "Hey Tim how are you?")
        let message2 = JSQMessage(senderId: "2", displayName: "Bot", text: "Hi! I can tell you the weather, plese tell me what you want to know.")
        
        //messages.append(message1!)
        messages.append(message2!)
        
        return messages
    }
}
