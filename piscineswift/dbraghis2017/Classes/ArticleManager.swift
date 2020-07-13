//
//  ArticleManager.swift
//  Pods
//
//  Created by dbraghis2 on 4/27/17.
//
//

import Foundation
import CoreData

@available(iOS 10.0, *)
public class ArticleManager
{
    public var managedObjectContext: NSManagedObjectContext
    
    public init() {
        //This resource is the same name as your xcdatamodeld contained in your project
        guard let modelURL = Bundle(for: Article.self).url(forResource: "article", withExtension:"momd") else {
            fatalError("Error loading model from bundle")
        }
        // The managed object model for the application. It is a fatal error for the application not to be able to find and load its model.
        guard let mom = NSManagedObjectModel(contentsOf: modelURL) else {
            fatalError("Error initializing mom from: \(modelURL)")
        }
        
        let psc = NSPersistentStoreCoordinator(managedObjectModel: mom)
        
        managedObjectContext = NSManagedObjectContext(concurrencyType: NSManagedObjectContextConcurrencyType.mainQueueConcurrencyType)
        managedObjectContext.persistentStoreCoordinator = psc
        
//        let queue = DispatchQueue.global(qos: DispatchQoS.QoSClass.background)
//        queue.async {
            guard let docURL = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).last else {
                fatalError("Unable to resolve document directory")
            }
            let storeURL = docURL.appendingPathComponent("dbraghis2017.sqlite")
            do {
                try psc.addPersistentStore(ofType: NSSQLiteStoreType, configurationName: nil, at: storeURL, options: nil)
                //The callback block is expected to complete the User Interface and therefore should be presented back on the main queue so that the user interface does not need to be concerned with which queue this call is coming from.
//                DispatchQueue.main.sync(execute: completionClosure)
            } catch {
                fatalError("Error migrating store: \(error)")
            }
       // }
    }
    
    public func newArticle() -> Article{
        let a = NSEntityDescription.insertNewObject(forEntityName: "Article", into: managedObjectContext) as! Article
        return a
    }
    
    public func newArticle(title: String, content: String, language: String, image: NSData) -> Article
    {
        let a = NSEntityDescription.insertNewObject(forEntityName: "Article", into: managedObjectContext) as! Article
        a.title = title
        a.context = content
        a.image = image
        return a
    }
    
    public func getAllArticles() -> [Article]
    {
        let request = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        do {
            let result = try managedObjectContext.fetch(request) as! [Article]
            return result
        }
        catch {
            return []
        }
    }
    
    public func getArticles(withLang lang: String) -> [Article]
    {
        let request = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        request.predicate = NSPredicate(format: "lang == %@", lang)
        do {
            let result = try managedObjectContext.fetch(request) as! [Article]
            return result
        }
        catch {
            return []
        }
    }
    
    public func getArticles(containString str: String) -> [Article]
    {
        let request = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        request.predicate = NSPredicate(format: "title CONTAINS %@ || content CONTAINS %@", str,str)
        var newRez: [Article] = []
        do {
                let result = try managedObjectContext.fetch(request) as! [Article]
            return result
        }
        catch {
            return []
        }
    }
    
    public func removeArticle(article: Article)
    {
        managedObjectContext.delete(article)
    }
    
    public func removeAllArticles()
    {
        let all = getAllArticles()
        for a in all
        {
            removeArticle(article: a)
        }
    }
    
    public func save()
    {
        if (managedObjectContext.hasChanges)
        {
            do
            {
                try managedObjectContext.save()
            }
            catch {
                fatalError("Fatal error: \(error)")
            }
        }
        else{
            fatalError("No changes found")
        }
    }

}
