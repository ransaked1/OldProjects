//
//  test.swift
//  day01
//
//  Created by dbraghis2 on 4/18/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation
let card1 = Card(color: .Spades, value: .Ace)
let card2 = Card(color: .Spades, value: .Ace)

print(card1)
print(card2)
print(card1 == card2)

card1.color = .Diamonds

print(card1)
print(card2)
print(card1 == card2)
