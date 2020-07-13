//
//  ViewController.swift
//  day03
//
//  Created by dbraghis2 on 4/20/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource {

    var links: [NSURL] = [NSURL(string: "https://wallpaperbrowse.com/media/images/bcf39e88-5731-43bb-9d4b-e5b3b2b1fdf2.jpg")!, NSURL(string: "https://static.pexels.com/photos/1029/landscape-mountains-nature-clouds.jpg")!, NSURL(string: "https://s-media-cache-ak0.pinimg.com/736x/df/a8/cc/dfa8ccd412d80a07665976673de6f9d4.jpg")!, NSURL(string: "https://upload.wikimedia.org/wikipedia/commons/6/62/Starsinthesky.jpg")!, NSURL(string: "https://s-media-cache-ak0.pinimg.com/originals/a6/13/16/a613161ad7891d6a1a9085fda7cd279d.jpg")!, NSURL(string: "https://s-media-cache-ak0.pinimg.com/originals/2e/d3/67/2ed367e43a27f32235df07cd054e2338--edible-flowers-buttons.jpg")!]
    
    var activityIndicator: UIActivityIndicatorView = UIActivityIndicatorView()
    
    var AnImage: UIImage = UIImage()
    
    let imageCache = NSCache<AnyObject, AnyObject>()
    
    @IBOutlet weak var MyCollectionView: UICollectionView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.MyCollectionView.delegate = self
        self.MyCollectionView.dataSource = self
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewDidAppear(_ animated: Bool)
    {
        //UIApplication.shared.isNetworkActivityIndicatorVisible = false
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        return links.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath) as! MyCollectionViewCell
        cell.ActivityIndicator.hidesWhenStopped = true
        
        if let imageFromCache = imageCache.object(forKey: links[indexPath.row]) as? UIImage
        {
            cell.ActivityIndicator.stopAnimating()
            cell.MyImageView.image = imageFromCache
            return cell
        }
        else
        {
        DispatchQueue.global().async
        {
            if let data = try? Data(contentsOf: self.links[indexPath.row] as URL)
            {
                cell.ActivityIndicator.startAnimating()
                DispatchQueue.main.async
                {
                    let imageToCache = UIImage(data: data)
                    cell.ActivityIndicator.stopAnimating()
                    self.imageCache.setObject(imageToCache!, forKey: self.links[indexPath.row])
                    cell.MyImageView.image = imageToCache
                    return
                }
            }
            else
            {
                cell.ActivityIndicator.startAnimating()
                self.createAlert(title: "Error", message: "Error loading images: \(self.links[indexPath.row])")
                cell.ActivityIndicator.stopAnimating()
                return
            }
        }
        }
        return (cell)
    }
    
    func getDataFromUrl(url: URL, completion: @escaping (_ data: Data?, _  response: URLResponse?, _ error: Error?) -> Void)
    {
        URLSession.shared.dataTask(with: url)
        {
            (data, response, error) in completion(data, response, error)
        }
        .resume()
    }
    
    func createAlert(title: String, message: String)
    {
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: { (action) in
            alert.dismiss(animated: true, completion: nil)
        }))
        
        self.present(alert, animated: true, completion: nil)
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        AnImage = (imageCache.object(forKey: self.links[indexPath.row] as AnyObject) as? UIImage)!
    }
}

