//
//  APITwitterDelegate.swift
//  day04
//
//  Created by dbraghis2 on 4/22/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation


protocol APITwitterDelegate: class {
    
    func didTreatTweets(tweets: [Tweet])
    func didFail(error: NSError)
    
}
