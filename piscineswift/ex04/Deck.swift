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
    public static let allSpades : [Card] = Value.allValues.map({
        return Card(color: .Spades, value: $0)
    })
    public static let allDiamonds : [Card] = Value.allValues.map({
        return Card(color: .Diamonds, value: $0)
    })
    public static let allHearts : [Card] = Value.allValues.map({
        return Card(color: .Hearts, value: $0)
    })
    public static let allClubs : [Card] = Value.allValues.map({
        return Card(color: .Clubs, value: $0)
    })
    public var cards : [Card] = allSpades + allHearts + allDiamonds + allClubs
    public var discards : [Card] = []
    public var outs : [Card] = []
    
    init (b : Bool)
    {
        if b == true
        {
            self.cards.shuffle()
        }
    }
    
    override var description: String{
        return "(\(self.cards))"
    }
    
    func draw() -> Card?
    {
        var tmp : Card
        if self.cards.count != 0
        {
            tmp = self.cards[0]
            outs.append(self.cards[0])
            self.cards.remove(at: 0)
            return (tmp)
        }
        return (nil)
    }
    
    func fold(c: Card)
    {
        if let i = self.outs.index(of: c)
        {
            discards.append(outs[i])
            outs.remove(at: i)
        }
        else
        {
            return
        }
    }
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



