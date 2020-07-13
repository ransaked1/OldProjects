//
//  test.swift
//  day01
//
//  Created by dbraghis2 on 4/18/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import Foundation

//var smth = Deck(b: true)
var smth = Deck(b: false)

print ("All cards after shuffling are: \(smth.cards) \n")

if let a = smth.draw() {
    print(a)
}
else {
    print("nil")
}

if let a = smth.draw() {
    print(a)
}
else {
    print("nil")
}

print ("All cards after 2 draws are: \(smth.cards) \n")
print ("Outs after 2 draws are: \(smth.outs) \n")
print ("Discards after 2 draws are: \(smth.discards) \n")

smth.fold(c: Card(color: .Spades, value: .Three))

print ("All cards after 2 draws are: \(smth.cards) \n")
print ("Outs after 2 draws are: \(smth.outs) \n")
print ("Discards after 2 draws are: \(smth.discards) \n")
