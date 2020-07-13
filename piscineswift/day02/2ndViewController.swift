//
//  2ndViewController.swift
//  day02
//
//  Created by dbraghis2 on 4/19/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

var NameofPerson = ""
var DateofPerson = ""
var DescriptionofPerson = ""

class _ndViewController: UIViewController {
    
    @IBOutlet weak var Name: UITextField!
    
    @IBOutlet weak var myDate: UIDatePicker!
    
    @IBOutlet weak var Description: UITextView!
    
    
    override func loadView() {
        super.loadView()
        let components = DateComponents()
        let minDate = Calendar.current.date(byAdding: components, to: Date())
        myDate.minimumDate = minDate
    }
    
    @IBAction func BDone(_ sender: Any)
    {
        myDate.minimumDate = NSDate() as Date
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "dd-MM-yyyy HH:mm"
        DateofPerson = dateFormatter.string(from: myDate.date)
        
        NameofPerson = Name.text!
        DescriptionofPerson = Description.text!
        
        let a = self.navigationController?.viewControllers[0] as! ViewController
        var aperson : Person
        if NameofPerson != ""
        {
            aperson = Person(name: NameofPerson, date: DateofPerson, description: DescriptionofPerson)
            a.PList.append(aperson)
            a.table.reloadData()
            self.navigationController?.popToRootViewController(animated: true)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        Description.layer.borderColor = UIColor.black.cgColor;
        Description.layer.borderWidth = 1.0;
        Description.layer.cornerRadius = 3.0;
        self.view.backgroundColor = UIColor (patternImage: UIImage(named: "back1.jpeg")!)
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
