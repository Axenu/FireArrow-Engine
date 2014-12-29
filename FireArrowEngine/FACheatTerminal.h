//
//  FACheatTerminal.h
//  FireArrow
//
//  Created by Simon Nilsson on 8/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FACheatTerminal__
#define __FireArrow__FACheatTerminal__

#include <stdio.h>
#include "FAText2D.h"
#include "FAPlane2D.h"
#include <vector>
#include "FAShaderNode.h"
#include "FATextList.h"

class FACheatTerminal : public FANode {
private:
	FAPlane2D *background;
	FAPlane2D *texBox;
	FAText2D *input;
	FATextList *history;
	FAFont *font;
	FAShaderNode *shaders;
	bool isCaps;
	bool isShift;
	
public:
	FACheatTerminal();
	FACheatTerminal(FAShaderNode *shaders);
	void setShader(FAShaderNode *shaders);
	
	//input metohds
	void getCharacter(int i);
	~FACheatTerminal();
	void capsLock(bool b);
	void capsLock();
	void shift(bool b);
	void backSpace();
	void enter();
	void space();
	void escape();
	
	//command methods
	void addSetCommand(std::string name, std::string *value);
	
protected:
	
};

#endif /* defined(__FireArrow__FACheatTerminal__) */
