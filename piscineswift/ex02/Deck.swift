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
