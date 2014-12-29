//
//  FAGame.h
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAGame__
#define __FireArrow__FAGame__

#include "FAEngine.h"
#include "shadowScene.h"

class FAGame : public FAEngine {

private:
	
public:
    FAGame();
    
    
    void setWindowAttributes();
    
    ~FAGame();
    
protected:
    void init();
    FAScene* setInitialScene();
};

#endif /* defined(__FireArrow__FAGame__) */
