//
//  ViewControllerTableViewCell.swift
//  day02
//
//  Created by dbraghis2 on 4/19/17.
//  Copyright © 2017 dbraghis2. All rights reserved.
//

import UIKit

class ViewControllerTableViewCell: UITableViewCell {

    @IBOutlet weak var MyDate: UILabel!
    @IBOutlet weak var MyPerson: UILabel!
    @IBOutlet weak var MyDescription: UILabel!
    

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
