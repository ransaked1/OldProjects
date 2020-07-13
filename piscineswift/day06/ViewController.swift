//
//  ViewController.swift
//  day06
//
//  Created by dbraghis2 on 4/25/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

//enum Shape : UInt
//{
//    case square = 0
//    case circle
//}

class Object: UIView
{
    let size = 100
    
    func randomColor() -> UIColor
    {
        switch arc4random() % 6
        {
        case 1:
            return UIColor.green
        case 2:
            return UIColor.blue
        case 3:
            return UIColor.black
        case 4:
            return UIColor.red
        case 5:
            return UIColor.cyan
        case 6:
            return UIColor.purple
        default:
            return UIColor.yellow
        }
    }
    
    func randomShape() -> CGFloat
    {
        switch arc4random() % 2
        {
        case 1:
            return 0
        default:
            return CGFloat(size / 2)
        }
    }
    
    func deleteIt()
    {
        self.removeFromSuperview()
    }
    
    func add(point: CGPoint, abool: Bool, color: UIColor, shape: CGFloat)
    {
        if abool == true
        {
            self.backgroundColor = randomColor()
            self.layer.cornerRadius = randomShape()
        }
        else if abool == false
        {
            self.backgroundColor = color
            self.layer.cornerRadius = shape
        }
        self.layer.masksToBounds = true
        self.clipsToBounds = true
    }
    
    init(point: CGPoint)
    {
        let region = CGRect(origin: CGPoint(x: point.x - CGFloat(size / 2), y: point.y - CGFloat(size / 2)), size: CGSize(width: 100, height: size))
        super.init(frame: region)
    }
    
    required init?(coder aDecoder: NSCoder)
    {
        super.init(coder: aDecoder)
    }
    override public var collisionBoundsType: UIDynamicItemCollisionBoundsType {
        return .path
    }
    
    override public var collisionBoundingPath: UIBezierPath {
        return UIBezierPath(roundedRect: CGRect(x: -bounds.size.width / 2.0, y: -bounds.size.height / 2.0, width: bounds.width, height: bounds.height), cornerRadius: self.layer.cornerRadius)
    }
}

class ViewController: UIViewController
{
    
    var animator: UIDynamicAnimator?
    var allObjects: [Object] = []
    let vector = CGVector(dx: 0.0, dy: 1.0)
    var allgravity: UIGravityBehavior?
    
    override func viewDidLoad() {
        super.viewDidLoad()
                // Do any additional setup after loading the view, typically from a nib.
    }

    @IBAction func viewTapped(_ sender: UITapGestureRecognizer)
    {
        let blueBoxView : Object? = Object(point: sender.location(in: sender.view))
        blueBoxView?.add(point: sender.location(in: view), abool: true, color: .green, shape: 0)
        
        allObjects.append(blueBoxView!)
        self.view.addSubview(blueBoxView!)
        
        animator = UIDynamicAnimator(referenceView: self.view)
        
        let gravity = UIGravityBehavior(items: allObjects)
        gravity.gravityDirection = vector
        allgravity = gravity
        
        let collision = UICollisionBehavior(items: allObjects)
        collision.translatesReferenceBoundsIntoBoundary = true
        
        let elasticity = UIDynamicItemBehavior(items: allObjects)
        elasticity.allowsRotation = true
        elasticity.elasticity = 0.6
        
        animator?.addBehavior(collision)
        animator?.addBehavior(gravity)
        animator?.addBehavior(elasticity)
    }
//    @IBAction func viewPinched(_ sender: UIPinchGestureRecognizer)
//    {
//        switch sender.state
//        {
//        case .began:
//            for o in allObjects
//            {
//                if o.frame.contains(sender.location(in: view))
//                {
//                    go = 1
//                    print("in circle!")
//                    p = o
//                    break
//                }
//                else
//                {
//                    go = 0
//                }
//            }
//        case .changed:
//            if go == 1
//            {
//                print("yay!")
//                p?.center = sender.location(in: view)
//                p?.transform = CGAffineTransform(scaleX: sender.scale, y: sender.scale)
//                animator = UIDynamicAnimator(referenceView: self.view)
//                
//                let gravity = UIGravityBehavior(items: allObjects)
//                gravity.gravityDirection = vector
//                allgravity = gravity
//                
//                let collision = UICollisionBehavior(items: allObjects)
//                collision.translatesReferenceBoundsIntoBoundary = true
//                
//                let elasticity = UIDynamicItemBehavior(items: allObjects)
//                elasticity.allowsRotation = true
//                elasticity.elasticity = 0.6
//                animator?.addBehavior(collision)
//                animator?.addBehavior(gravity)
//                animator?.addBehavior(elasticity)
//            }
//        case .ended:
//            if go == 1
//            {
//                print("fuuuuuuuuuh!")
//                //let blueBoxView : Object? = Object(point: sender.location(in: sender.view))
//                p?.add(point: sender.location(in: view), abool: false, color: (p?.backgroundColor)!, shape: (p?.layer.cornerRadius)!)
//                p?.transform = CGAffineTransform(scaleX: sender.scale, y: sender.scale)
//                self.view.addSubview(p!)
//                
//                animator = UIDynamicAnimator(referenceView: self.view)
//                
//                let gravity = UIGravityBehavior(items: allObjects)
//                gravity.gravityDirection = vector
//                allgravity = gravity
//                
//                let collision = UICollisionBehavior(items: allObjects)
//                collision.translatesReferenceBoundsIntoBoundary = true
//                
//                let elasticity = UIDynamicItemBehavior(items: allObjects)
//                elasticity.allowsRotation = true
//                elasticity.elasticity = 0.6
//                
//                animator?.addBehavior(collision)
//                animator?.addBehavior(gravity)
//                animator?.addBehavior(elasticity)
//            }
//        //p = nil
//        default:
//            print("like wat?")
//        }
//    }
    
    
    
    var p: Object?
    var indexO: Int?
    var go = 1
    var diffX : CGFloat = 0.0
    var diffY : CGFloat = 0.0
    @IBAction func viewPanned(_ sender: UIPanGestureRecognizer)
    {
//        var oColor: UIColor? = .black
//        var oShape: CGFloat? = 0
        switch sender.state
        {
        case .began:
            for o in allObjects
            {
                if o.frame.contains(sender.location(in: view))
                {
                    go = 1
                    print("in circle!")
                    p = o
                    indexO = allObjects.index(of: o)

                    break
                }
                else
                {
                    go = 0
                }
            }
        case .changed:
            if go == 1
            {
            print("yay!")
            var c = sender.location(in: view)
            c.x += diffX
            c.y += diffY
            p?.center = c
            animator = UIDynamicAnimator(referenceView: self.view)
            
            let gravity = UIGravityBehavior(items: allObjects)
            gravity.gravityDirection = vector
            allgravity = gravity
            
            let collision = UICollisionBehavior(items: allObjects)
            collision.translatesReferenceBoundsIntoBoundary = true
            
            let elasticity = UIDynamicItemBehavior(items: allObjects)
            elasticity.allowsRotation = true
            elasticity.elasticity = 0.6
            animator?.addBehavior(collision)
            animator?.addBehavior(gravity)
            animator?.addBehavior(elasticity)
            }
        case .ended:
            if go == 1
            {
                print("fuuuuuuuuuh!")
                p?.add(point: sender.location(in: view), abool: false, color: (p?.backgroundColor)!, shape: (p?.layer.cornerRadius)!)
            
                p?.deleteIt()
                allObjects.remove(at: indexO!)
                allObjects.append(p!)
                self.view.addSubview(p!)
                
                animator = UIDynamicAnimator(referenceView: self.view)
            
                let gravity = UIGravityBehavior(items: allObjects)
                gravity.gravityDirection = vector
                allgravity = gravity
            
                let collision = UICollisionBehavior(items: allObjects)
                collision.translatesReferenceBoundsIntoBoundary = true
            
                let elasticity = UIDynamicItemBehavior(items: allObjects)
                elasticity.allowsRotation = true
                elasticity.elasticity = 0.6
            
                animator?.addBehavior(collision)
                animator?.addBehavior(gravity)
                animator?.addBehavior(elasticity)
            }
            //p = nil
        default:
            print("like wat?")
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    var collisionBoundsType: UIDynamicItemCollisionBoundsType
        {
            return .ellipse
    }
}

