//
//  SecondViewController.swift
//  day03
//
//  Created by dbraghis2 on 4/20/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController, UIScrollViewDelegate
{
    
    @IBOutlet weak var ScrollView: UIScrollView!
    
    var image: UIImage?
    var imageView: UIImageView?
    override func viewDidLoad() {
        super.viewDidLoad()
        let a = self.navigationController?.viewControllers[0] as! ViewController
        image = a.AnImage
        imageView = UIImageView(image: image)
        self.ScrollView.addSubview(imageView!)
        self.ScrollView.minimumZoomScale = 0.1
        self.ScrollView.maximumZoomScale = 5.0
        
        ScrollView.delegate = self
        // Do any additional setup after loading the view.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return self.imageView
    }

}
