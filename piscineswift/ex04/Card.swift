//
//  Card.swift
//  day01
//
//  Created by dbraghis2 on 4/18/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation

class Card: NSObject
{
    var color: Color
    var value: Value
    init(color:Color, value:Value)
    {
        self.color = color;
        self.value = value;
    }
   
    override var description: String{
        return "(\(value.rawValue),\(color.rawValue))"
    }
    
    override func isEqual(_ object: Any?) -> Bool {
        if let card = object as? Card
        {
            if  card.value == value && card.color == color
            {
                return true
            }
        }
        return false
    }
}


