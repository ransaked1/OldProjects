//
//  Article+CoreDataProperties.swift
//  Pods
//
//  Created by dbraghis2 on 4/27/17.
//
//

import Foundation
import CoreData


extension Article {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Article> {
        return NSFetchRequest<Article>(entityName: "Article");
    }

    @NSManaged public var title: String?
    @NSManaged public var context: String?
    @NSManaged public var language: String?
    @NSManaged public var image: NSData?
    @NSManaged public var dateofcreation: NSDate?
    @NSManaged public var dateofmodification: NSDate?
    
    override public var description: String{
        return ("\(title) \(context) Lang: \(language) Created: \(dateofcreation)")
    }
}
