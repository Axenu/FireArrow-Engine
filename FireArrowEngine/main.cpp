//
//  main.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 29/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAGame.h"

FAGame *game;

int main(int argc, const char * argv[]) {
    
    game = new FAGame();
    
    //    game->setWindowAttributes();
    
    while (game->shouldTerminate()) {
        game->update();
        game->render();
    }
    
    delete game;
    
    return 0;
}