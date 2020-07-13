//
//  MyTableViewCell.swift
//  day05
//
//  Created by dbraghis2 on 4/24/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

class MyTableViewCell: UITableViewCell {


    @IBOutlet weak var content: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
