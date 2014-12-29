//
//  FACheatTerminal.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 8/11/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FACheatTerminal.h"

FACheatTerminal::FACheatTerminal() {
//	background = new FAPlane2D();
	Deactivate();
}

FACheatTerminal::FACheatTerminal(FAShaderNode *shaders) {
//	FACheatTerminal::shaders = shaders;
//	Deactivate();
//	
//	background = new FAPlane2D();
//	background->setShader(*(*shaders)["Plane2D"]);
//	background->setColor(glm::vec4(1,1,1,0.3));
//	background->setPos(glm::vec3(-1,-0.64,0));
//	background->setScale(glm::vec3(1,0.06 * 5,1));
//	this->addNode(background);
//	
//	texBox = new FAPlane2D();
//	texBox->setShader(*(*shaders)["Plane2D"]);
//	texBox->setColor(glm::vec4(0.7,0.7,0.7,0.3));
//	texBox->setPos(glm::vec3(-1,-1,0));
//	texBox->setScale(glm::vec3(1,0.06,1));
//	this->addNode(texBox);
//	
//	font = new FAFont("Helvetica.ttf", 20);
//	input = new FAText2D(font);
//	input->setShader(*(*shaders)["Text2D"]);
//	input->setText("");
//	input->setPos(glm::vec3(10,10,0));
//	this->addNode(input);
//	
//	history = new FATextList();
//	history->setPos(glm::vec3(100,100,0));
//	this->addNode(history);
}

void FACheatTerminal::getCharacter(int i) {
	char c;
	if (isCaps) {
		if (isShift) {
			c = i + 32;
		} else {
			c = i;
		}
	} else {
		if (isShift) {
			c = i;
		} else {
			c = i + 32;
		}
	}
	
	input->setText(input->getText() + c);
}

void FACheatTerminal::setShader(FAShaderNode *shaders) {
	FACheatTerminal::shaders = shaders;
}

void FACheatTerminal::capsLock(bool b) {
	isCaps = b;
}

void FACheatTerminal::capsLock() {
	isCaps = !isCaps;
}

void FACheatTerminal::shift(bool b) {
	isShift = b;
}

void FACheatTerminal::backSpace() {
	if (input->getText().length() > 0) {
		input->setText(input->getText().substr(0, input->getText().size()-1));
	}
}

void FACheatTerminal::enter() {
	
	//execute command
	
//	FAText2D *text = new FAText2D(font);
//	text->setShader(*(*shaders)["Text2D"]);
//	text->setText(input->getText());
//	text->setPos(input->getPos());
//	history->addElement(text);
//	input->setText("");
//	
//	Deactivate();
}

void FACheatTerminal::space() {
	input->setText(input->getText() + ' ');
}

void FACheatTerminal::escape(){
	input->setText("");
	Deactivate();
}

void FACheatTerminal::addSetCommand(std::string name, std::string *value) {
	
}

FACheatTerminal::~FACheatTerminal() {
	
}