//
//  Deck.swift
//  day01
//
//  Created by dbraghis2 on 4/18/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation

class Deck: NSObject
{
    static let allSpades : [Card] = Value.allValues.map({
        return Card(color: .Spades, value: $0)
    })
    static let allDiamonds : [Card] = Value.allValues.map({
        return Card(color: .Diamonds, value: $0)
    })
    static let allHearts : [Card] = Value.allValues.map({
        return Card(color: .Hearts, value: $0)
    })
    static let allClubs : [Card] = Value.allValues.map({
        return Card(color: .Clubs, value: $0)
    })
    static let allCards : [Card] = allSpades + allHearts + allDiamonds + allClubs
}

extension Array
{
    mutating func shuffle()
    {
        if count < 2 { return }
        
        for i in 0..<count - 1
        {
            let j = Int(arc4random_uniform(UInt32(count - i))) + i
            guard i != j else { continue }
            if i != j
            {
                swap(&self[i], &self[j])
            }
        }
    }
}
