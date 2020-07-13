//
//  test.swift
//  day01
//
//  Created by dbraghis2 on 4/18/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation

var smth = Deck.allCards

print ("All cards before shuffling are: \(smth)")
print ("\n")
smth.shuffle()
print ("All cards after shuffling are: \(smth)")
