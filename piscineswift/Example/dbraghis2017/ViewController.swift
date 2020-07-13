//
//  ViewController.swift
//  dbraghis2017
//
//  Created by ransaked1 on 04/27/2017.
//  Copyright (c) 2017 ransaked1. All rights reserved.
//

import UIKit
import dbraghis2017

@available(iOS 10.0, *)
class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let a = ArticleManager()
        
        let m = a.newArticle()
        m.title = "yay"
        m.context = "is esf aerg"
        m.language = "en"
        m.dateofcreation = NSDate()
        m.dateofmodification = NSDate()
        a.save()
        print(a.getAllArticles())
        a.removeAllArticles()
        a.save()
        //print(a.getAllArticles())
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

