//
//  ViewController.swift
//  test
//
//  Created by dbraghis2 on 4/17/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var MyNumber:Int = 0;
    var OldNumber:Int = 0;
    var DoOp = false;
    var UsedEq = false;
    var Operation = 0;
    var n:Float = 0;
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func buttons(_ sender: UIButton)
    {
        if sender.tag == 12 && label.text != "" && Int(label.text!)! > 0
        {
            label.text = "-\(label.text!)"
        }
        else if sender.tag != 11 && sender.tag != 17 && label.text != "Error" && label.text != "Overflow"
        {
            OldNumber = Int(label.text!)!
            if sender.tag == 13//plus
            {
                label.text = "";
            }
            else if sender.tag == 14//minus
            {
                label.text = "";
            }
            else if sender.tag == 15//multip
            {
                label.text = "";
            }
            else if sender.tag == 16//inpartit
            {
                label.text = "";
            }
            Operation = sender.tag
            DoOp = true;
        }
        else if sender.tag == 17 && label.text != "Error" && label.text != "Overflow"
        {
            //OldNumber = Int(label.text!)!
            if Operation == 13 //adunare
            {
                let (value, o) = Int.addWithOverflow(OldNumber, MyNumber)
                if (o)
                {
                    label.text = "Overflow"
                    return
                }
                else
                {
                    label.text = String(value)
                }
            }
            if Operation == 14 //scadere
            {
                let (value, o) = Int.subtractWithOverflow(OldNumber, MyNumber)
                if (o)
                {
                    label.text = "Overflow"
                    return
                }
                else
                {
                    label.text = String(value)
                }
            }
            if Operation == 15 //inmultire
            {
                let (value, o) = Int.multiplyWithOverflow(OldNumber, MyNumber)
                if (o)
                {
                    label.text = "Overflow"
                    return
                }
                else
                {
                    label.text = String(value)
                }
            }
            if Operation == 16 //impartire
            {
                if OldNumber == 0
                {
                    label.text = "0"
                }
                else if label.text == "0"
                {
                    label.text = "Error"
                    Operation = 0;
                    OldNumber = 0;
                    MyNumber = 0;
                }
                else
                {
                    label.text = String(OldNumber / MyNumber)
                }
            }
            UsedEq = true
            DoOp = false
        }
        else if sender.tag == 11
        {
            label.text = "0"
            OldNumber = 0;
            MyNumber = 0;
            Operation = 0;
        }
    }
    
    @IBOutlet weak var label: UILabel!
    
    @IBAction func numbers(_ sender: UIButton)
    {
        let button = sender
        if DoOp == true
        {
            label.text = String(button.tag-1)
            MyNumber = Int(label.text!)!
            DoOp = false
            return
        }
        else
        {
            if label.text == "0" || label.text == "Error" || label.text == "Overflow"
            {
                label.text = String(button.tag-1)
            }
            else
            {
                label.text = label.text! + String(button.tag - 1)
            }
            if label.text!.characters.count > 9
            {
                label.text = "Overflow"
                OldNumber = 0;
                MyNumber = 0;
                Operation = 0;
                return
            }
        }
        MyNumber = Int(label.text!)!
        UsedEq = false
    }
}

