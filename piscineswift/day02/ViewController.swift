//
//  ViewController.swift
//  day02
//
//  Created by dbraghis2 on 4/19/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

public class Person {
    var Name: String!
    var Date: String!
    var Description: String!
    
    init(name: String, date: String, description: String)
    {
        Name = name;
        Date = date;
        Description = description;
    }
}

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    var PList : [Person] = []
    
    @IBOutlet weak var table: UITableView!

    @IBOutlet weak var Minix: UIView!
    
    public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return (PList.count)
    }

    public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! ViewControllerTableViewCell
        cell.backgroundView = UIImageView(image: UIImage(named: "back.jpg"))
        cell.selectedBackgroundView = UIImageView(image: UIImage(named: "back.jpg"))
        cell.layer.borderWidth = 4.0;
        cell.layer.cornerRadius = 9.0;
        cell.MyPerson.text! = PList[indexPath.row].Name
        cell.MyDate.text! = PList[indexPath.row].Date
        cell.MyDescription.text! = PList[indexPath.row].Description
        return (cell)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        table.rowHeight = UITableViewAutomaticDimension
        table.estimatedRowHeight = 140
         navigationController?.navigationBar.barTintColor = UIColor.black
//        self.table.estimatedRowHeight = 40
//        self.table.rowHeight = UITableViewAutomaticDimension
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

