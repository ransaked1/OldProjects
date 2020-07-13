//
//  FirstViewController.swift
//  day05
//
//  Created by dbraghis2 on 4/24/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

var region: MKCoordinateRegion?
public var pos = 0

class MyPointAnnotation: MKPointAnnotation
{
    var pinTintColor: UIColor?
    init (color: UIColor)
    {
        pinTintColor = color
    }
}

class FirstViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    @IBOutlet weak var mapView: MKMapView!
    @IBOutlet weak var segmentedController: UISegmentedControl!
    @IBOutlet weak var geoButton: UIButton!
    
    let list = ["Ecole 42", "Grenoble", "Acedemy+", "Chisinau", "Home"]
    let listsub = ["Here is the answer to everything", "Grenoble city <3", "Here we are coding!", "The city I live", "Sweet home!"]
    var indexP = 0
    var indexP2 = 0
    let manager = CLLocationManager()
    let locations: [CLLocationCoordinate2D] = [CLLocationCoordinate2DMake(48.896678, 2.318178), CLLocationCoordinate2DMake(45.185583, 5.720465), CLLocationCoordinate2DMake(47.039845, 28.824544), CLLocationCoordinate2DMake(47.025462, 28.831191), CLLocationCoordinate2DMake(47.046347, 28.889174)]
    var regions: [MKCoordinateRegion] = []
    let color: [UIColor] = [.red, .blue, .yellow, .brown, .green]
    
    @IBAction func setLocation(_ sender: Any)
    {
        mapView.setRegion(region!, animated: true)
    }
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation])
    {
        let location = locations[0]
        
        let span: MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        let myLocation: CLLocationCoordinate2D = CLLocationCoordinate2DMake(location.coordinate.latitude, location.coordinate.longitude)
        region = MKCoordinateRegionMake(myLocation, span)
        
        self.mapView.showsUserLocation = true
    }
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        print(pos)
        placePins()
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView?
    {
        if annotation is MKUserLocation {
            return nil
        }
        let annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: "pin")
        annotationView.pinTintColor = color[indexP2]
        indexP2 = indexP2 + 1
        annotationView.canShowCallout = true
        return annotationView
    }
    
    func placePins()
    {
        let span: MKCoordinateSpan = MKCoordinateSpanMake(0.005, 0.005)
        for location in locations
        {
            regions.append(MKCoordinateRegionMake(location, span))
            
            let annotation = MKPointAnnotation()
            annotation.coordinate = location
            annotation.title = list[indexP]
            annotation.subtitle = listsub[indexP]
            mapView.addAnnotation(annotation)
            
            manager.delegate = self
            manager.desiredAccuracy = kCLLocationAccuracyBest
            manager.requestWhenInUseAuthorization()
            manager.startUpdatingLocation()
            indexP = indexP + 1
        }
        mapView.setRegion(regions[pos], animated: true)
    }
    
    
    @IBAction func changeMode(_ sender: Any)
    {
        switch ((sender as AnyObject).selectedSegmentIndex) {
        case 0:
            mapView.mapType = .standard
        case 1:
            mapView.mapType = .satellite
        default:
            mapView.mapType = .hybrid
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

