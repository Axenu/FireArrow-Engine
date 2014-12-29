//
//  FATextList.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 8/22/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FATextList.h"

FATextList::FATextList() {
}

void FATextList::addElement(FAText2D *text) {
	addNode(text);
	history.push_back(text);
	for (int i = 0; i < history.size(); i++) {
		history[i]->moveY(text->getFontSize() * 2);
	}
}

FATextList::~FATextList() {
}