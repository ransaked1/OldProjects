//
//  ViewController.swift
//  day04
//
//  Created by dbraghis2 on 4/22/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

struct Tweet : CustomStringConvertible
{
    let name: String
    let date: String
    let text: String
    var description: String
    {
        return "(\(name), \(text))"
    }
}

protocol APITwitterDelegate: class
{
    func didTreatTweets(tweets: [Tweet])
    func didFail(error: NSError)
}

class APIController
{
    weak var delegate: APITwitterDelegate?
    var access_token : String
    
    init(Delegate: APITwitterDelegate, Token: String)
    {
        delegate = Delegate
        access_token = Token
    }
    
    func request(content: String)
    {
        var q = "https://api.twitter.com/1.1/search/tweets.json?q=\(content)&count=100&lang=fr&result_type=recent"
        q = q.addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!
        if let url = URL(string: q) {
            var request = URLRequest(url: url)
            request.httpMethod = "GET"
            request.setValue("Bearer " + access_token, forHTTPHeaderField: "Authorization")
            let task = URLSession.shared.dataTask(with: request)
            { (data, response, error) in
                print(">>> \(response)")
                if nil != error
                {
                    print(error!)
                }
                else if data != nil
                {
                    do
                    {
                        if let dic : NSDictionary = try JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary
                        {
                            //print(dic)
                            var tweets: [Tweet] = []
                            if let tweetsD  = dic["statuses"] as? [[String: AnyObject]]
                            {
                                //print(tweetsD)
                                    for tweet in tweetsD
                                    {
                                        //print(tweet)
                                        if let name: String = tweet["user"]?["screen_name"] as? String
                                        {
                                            if let text: String = tweet["text"] as? String
                                            {
                                                if let date: String = tweet["created_at"] as? String
                                                {
                                                    let dateFormatter = DateFormatter()
                                                    dateFormatter.dateFormat = "E MMM dd HH:mm:ss Z yyyy"
                                                    if let date = dateFormatter.date(from: date)
                                                    {
                                                        dateFormatter.dateFormat = "dd/MM/yyyy HH:mm"
                                                        let newDate = dateFormatter.string(from: date)
                                                        tweets.append(Tweet(name: name, date: newDate, text: text))
                                                    }
                                                }
                                            }
                                        }
                                }
                                DispatchQueue.main.async
                                    {
                                        print(tweets)
                                        self.delegate?.didTreatTweets(tweets: tweets)
                                }
                            }
                        }
                    }
                    catch (let err as NSError)
                    {
                        DispatchQueue.main.async
                            {
                                self.delegate?.didFail(error: err)
                        }
                    }
                }
            }
             task.resume()
        }
        else
        {
            DispatchQueue.main.async
                {
                    self.delegate?.didFail(error: NSError(domain: "Error with request", code: 400, userInfo: nil))
            }
        }
    }
}

class ViewController: UIViewController, APITwitterDelegate, UITextFieldDelegate, UITableViewDataSource
{
    var tweets: [Tweet] = []
    var access_token: String = ""
    
    @IBOutlet weak var searchBox: UITextField!
    @IBOutlet weak var tableView: UITableView!
    
    public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return (tweets.count)
    }
    
    public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! MyTableViewCell
        cell.layer.borderWidth = 3.0;
        cell.layer.cornerRadius = 5.0;
        cell.layer.borderColor = UIColor.black.cgColor
        cell.name.text = tweets[indexPath.row].name
        cell.date.text = tweets[indexPath.row].date
        cell.content.text = tweets[indexPath.row].text
        return (cell)
    }
    
    func getToken()
    {
        let CUSTOMER_KEY = "Gse9Pwqpp3RlQDkAB6uU6hxmW"
        let CUSTOMER_SECRET = "cGarli39V22ovgWvxbNgOzsIuRTNUYqNkggD98SjvirSgTlmoF"
        let BEARER = ((CUSTOMER_KEY + ":" + CUSTOMER_SECRET).data(using: String.Encoding.utf8))!.base64EncodedString(options: NSData.Base64EncodingOptions(rawValue: 0))
        
        let url = URL(string: "https://api.twitter.com/oauth2/token")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        request.setValue("Basic " + BEARER, forHTTPHeaderField: "Authorization")
        request.setValue("application/x-www-form-urlencoded;charset=UTF-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials".data(using: String.Encoding.utf8)
        let task = URLSession.shared.dataTask(with: request) { (data, response, error) in
            print(">>> \(response)")
            if nil != error {
                print(error!)
            }
            else if nil != data {
                do {
                    if let dic : Dictionary = try JSONSerialization.jsonObject(with: data!, options: []) as? [String: Any] {
                        self.access_token = String(describing: dic["access_token"]!)
                        //print(self.access_token)
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
    }
    
    @IBAction func performAction() {
        if searchBox.text != ""
        {
            let user = searchBox.text//?.replacingOccurrences(of: " ", with: "")
            let apiController = APIController(Delegate: self, Token: access_token)
            apiController.request(content: user!)
        }
    }
    
    internal func didFail(error: NSError)
    {
        print("----- FAil -----")
        createAlert(title: "Error", message: error.localizedDescription)
    }

    internal func didTreatTweets(tweets: [Tweet])
    {
        print("----- DONE! -----")
        for tweet in tweets
        {
            print("\(tweet) \n")
        }
        self.tweets = tweets
        tableView.reloadData()
    }

    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        getToken()
        searchBox.delegate = self
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 110
        tableView.backgroundColor = UIColor.black
        view.backgroundColor = UIColor.gray
        // Do any additional setup after loading the view, typically from a nib.
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool
    {
        textField.resignFirstResponder()  //if desired
        performAction()
        return true
    }
    
    override func didReceiveMemoryWarning()
    {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func createAlert(title: String, message: String)
    {
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: { (action) in
            alert.dismiss(animated: true, completion: nil)
        }))
        
        self.present(alert, animated: true, completion: nil)
    }
}
