//
//  FATextList.h
//  FireArrow
//
//  Created by Simon Nilsson on 8/22/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FATextList__
#define __FireArrow__FATextList__

#include <stdio.h>
#include "FANode.h"
#include "FAText2D.h"

class FATextList : public FANode {
private:
	std::vector<FAText2D *> history;
public:
	FATextList();
	~FATextList();
	void addElement(FAText2D *text);
	
};

#endif /* defined(__FireArrow__FATextList__) */
