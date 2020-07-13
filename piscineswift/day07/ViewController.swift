////
////  ViewController.swift
////  day07
////
////  Created by dbraghis2 on 4/26/17.
////  Copyright © 2017 dbraghis2. All rights reserved.
////
//
//import UIKit
//import RecastAI
//import ForecastIO
//import JSQMessagesViewController
//
//let recastToken = "4f2c4c3ac1cc023c8b3260f9957fc918"
//let forecastToken = "c9de638efcda57e5530737bfcaff2b2e"
//
//class ViewController: UIViewController {
//    
//
//    @IBOutlet weak var textField: UITextField!
//    @IBOutlet weak var labelText: UILabel!
//    
//    var answerForUser: String?
//    
//    var bot : RecastAIClient?
//    var forecastClient: DarkSkyClient?
//    
//    override func viewDidLoad()
//    {
//        super.viewDidLoad()
//        // Do any additional setup after loading the view, typically from a nib.
//        self.bot = RecastAIClient(token : recastToken, language: "en")
//        self.forecastClient = DarkSkyClient(apiKey: forecastToken)
//        self.forecastClient?.units = .auto
//    }
//
//    func getWeather(long: Double, lat: Double)
//    {
//        forecastClient?.getForecast(latitude: lat, longitude: long, completion: {
//            result in
//            switch result {
//            case .success(let currentForecast, let RequestMetadata):
//                self.labelText.text = self.answerForUser! + " " + (result.value.0?.daily?.summary)!
//        case .failure(let error):
//                print(error)
//            }
//        })
//    }
//    
//    @IBAction func searchButton(_ sender: Any)
//    {
//        if let text: String = "Weather in " + textField.text!
//        {
//            if text != ""
//            {
//                self.bot?.textConverse(text, successHandler:
//                    {success in
//                        self.labelText.text = "Wait a moment..."
//                        if var location: [String: Any] = (success.entities?["location"] as! [[String: Any]]?)?[0]
//                    {
//                        self.answerForUser = success.replies?[0]
//                        let long = location["lng"] as! Double
//                        let lat = location["lat"] as! Double
//                        print("\(lat) and \(long)")
//                        self.getWeather(long: long, lat: lat)
//                    }
//                    else
//                    {
//                        DispatchQueue.main.async {
//                            self.labelText.text = "Please give me a location to tell you the weather"
//                        }
//                    }
//                }, failureHandle:
//                    { error in
//                    DispatchQueue.main.async {
//                        self.labelText.text = "Error1 " + error.localizedDescription
//                    }
//                })
//            }
//        }
//        DispatchQueue.main.async {
//            self.labelText.text = "Wait a moment..."
//       }
//    }
//    
//    override func didReceiveMemoryWarning() {
//        super.didReceiveMemoryWarning()
//        // Dispose of any resources that can be recreated.
//    }
//    
//}

