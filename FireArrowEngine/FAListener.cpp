//
//  FAListener.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 02/07/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAListener.h"

//const bool active = false;

//void onFrame(const Leap::Controller &controller) {
//    const Leap::Frame frame = controller.frame();
//    if (!frame.hands().isEmpty()) {
//        // Get the first hand
//        const Leap::Hand hand = frame.hands()[0];
//        const Leap::FingerList fingers = hand.fingers();
//        if (!fingers.isEmpty()) {
//            // Calculate the hand's average finger tip position
//            Leap::Vector avgPos;
//            for (int i = 0; i < fingers.count(); ++i) {
//                avgPos += fingers[i].tipPosition();
//            }
//            avgPos /= (float)fingers.count();
//            //            std::cout << "Hand has " << fingers.count()
//            //            << " fingers, average finger tip position" << avgPos << std::endl;
//        }
//        //    std::cout << "Frame id: " << frame.id()
//        //    << ", timestamp: " << frame.timestamp()
//        //    << ", hands: " << frame.hands().count()
//        //    << ", fingers: " << frame.fingers().count()
//        //    << ", tools: " << frame.tools().count() << std::endl;
//    }
//    Leap::Pointable pointable = frame.pointables().frontmost();
//    //    Leap::Pointable::Zone zone = pointable.touchZone();
//    Leap::Vector stabilizedPosition = pointable.stabilizedTipPosition();
//    Leap::InteractionBox iBox = controller.frame().interactionBox();
//    Leap::Vector normalizedPosition = iBox.normalizePoint(stabilizedPosition);
//    float x = normalizedPosition.x * 1024;
//    float y = normalizedPosition.y * 720;
////    text->setPos(glm::vec3(x * 2,y * 2,0));
//    std::cout << "fingerPointing: " << x << std::endl;
//}

//FAListener::FAListener(FAGame *_game) {
//    game = _game;
//}

//void FAListener::onInit(const Controller& controller) {
//    if (active) {
//        std::cout << "Initialized" << std::endl;
//    }
//}
//
//void FAListener::onConnect(const Controller& controller) {
//    std::cout << "Connected" << std::endl;
//    controller.enableGesture(Gesture::TYPE_CIRCLE);
//    controller.enableGesture(Gesture::TYPE_KEY_TAP);
//    controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
//    controller.enableGesture(Gesture::TYPE_SWIPE);
//}
//
//void FAListener::onDisconnect(const Controller& controller) {
//    //Note: not dispatched when running in a debugger.
//    if (active) {
//        std::cout << "Disconnected" << std::endl;
//    }
//}
//
//void FAListener::onExit(const Controller& controller) {
//    if (active) {
//        std::cout << "Exited" << std::endl;
//    }
//}
//
//void FAListener::onFrame(const Controller& controller) {
//    if (active) {
//    game->getLeapFrame(controller);
    // Get the most recent frame and report some basic information
//    const Frame frame = controller.frame();
//    std::cout << "Frame id: " << frame.id()
//    << ", timestamp: " << frame.timestamp()
//    << ", hands: " << frame.hands().count()
//    << ", fingers: " << frame.fingers().count()
//    << ", tools: " << frame.tools().count()
//    << ", gestures: " << frame.gestures().count() << std::endl;
//    
//    if (!frame.hands().isEmpty()) {
//        // Get the first hand
//        const Hand hand = frame.hands()[0];
//        
//        // Check if the hand has any fingers
//        const FingerList fingers = hand.fingers();
//        if (!fingers.isEmpty()) {
//            // Calculate the hand's average finger tip position
//            Vector avgPos;
//            for (int i = 0; i < fingers.count(); ++i) {
//                avgPos += fingers[i].tipPosition();
//            }
//            avgPos /= (float)fingers.count();
//            std::cout << "Hand has " << fingers.count()
//            << " fingers, average finger tip position" << avgPos << std::endl;
//        }
//        
//        // Get the hand's sphere radius and palm position
//        std::cout << "Hand sphere radius: " << hand.sphereRadius()
//        << " mm, palm position: " << hand.palmPosition() << std::endl;
//        
//        // Get the hand's normal vector and direction
//        const Vector normal = hand.palmNormal();
//        const Vector direction = hand.direction();
//        
//        // Calculate the hand's pitch, roll, and yaw angles
//        std::cout << "Hand pitch: " << direction.pitch() * RAD_TO_DEG << " degrees, "
//        << "roll: " << normal.roll() * RAD_TO_DEG << " degrees, "
//        << "yaw: " << direction.yaw() * RAD_TO_DEG << " degrees" << std::endl;
//    }
//    
//    // Get gestures
//    const GestureList gestures = frame.gestures();
//    for (int g = 0; g < gestures.count(); ++g) {
//        Gesture gesture = gestures[g];
//        
//        switch (gesture.type()) {
//            case Gesture::TYPE_CIRCLE:
//            {
//                CircleGesture circle = gesture;
//                std::string clockwiseness;
//                
//                if (circle.pointable().direction().angleTo(circle.normal()) <= PI/4) {
//                    clockwiseness = "clockwise";
//                } else {
//                    clockwiseness = "counterclockwise";
//                }
//                
//                // Calculate angle swept since last frame
//                float sweptAngle = 0;
//                if (circle.state() != Gesture::STATE_START) {
//                    CircleGesture previousUpdate = CircleGesture(controller.frame(1).gesture(circle.id()));
//                    sweptAngle = (circle.progress() - previousUpdate.progress()) * 2 * PI;
//                }
//                std::cout << "Circle id: " << gesture.id()
//                << ", state: " << gesture.state()
//                << ", progress: " << circle.progress()
//                << ", radius: " << circle.radius()
//                << ", angle " << sweptAngle * RAD_TO_DEG
//                <<  ", " << clockwiseness << std::endl;
//                break;
//            }
//            case Gesture::TYPE_SWIPE:
//            {
//                SwipeGesture swipe = gesture;
//                std::cout << "Swipe id: " << gesture.id()
//                << ", state: " << gesture.state()
//                << ", direction: " << swipe.direction()
//                << ", speed: " << swipe.speed() << std::endl;
//                break;
//            }
//            case Gesture::TYPE_KEY_TAP:
//            {
//                KeyTapGesture tap = gesture;
//                std::cout << "Key Tap id: " << gesture.id()
//                << ", state: " << gesture.state()
//                << ", position: " << tap.position()
//                << ", direction: " << tap.direction()<< std::endl;
//                break;
//            }
//            case Gesture::TYPE_SCREEN_TAP:
//            {
//                ScreenTapGesture screentap = gesture;
//                std::cout << "Screen Tap id: " << gesture.id()
//                << ", state: " << gesture.state()
//                << ", position: " << screentap.position()
//                << ", direction: " << screentap.direction()<< std::endl;
//                break;
//            }
//            default:
//                std::cout << "Unknown gesture type." << std::endl;
//                break;
//        }
//    }
//    
//    if (!frame.hands().isEmpty() || !gestures.isEmpty()) {
//        std::cout << std::endl;
//    }
//    }
//}
//
//void FAListener::onFocusGained(const Controller& controller) {
//    if (active) {
//        std::cout << "Focus Gained" << std::endl;
//    }
//}
//
//void FAListener::onFocusLost(const Controller& controller) {
//    if (active) {
//        std::cout << "Focus Lost" << std::endl;
//    }
//}

//int main() {
    // Create a sample listener and controller
//    SampleListener listener;
//    Controller controller;
//    
//    // Have the sample listener receive events from the controller
//    controller.addListener(listener);
//    
//    // Keep this process running until Enter is pressed
//    std::cout << "Press Enter to quit..." << std::endl;
//    std::cin.get();
    
    // Remove the sample listener when done
//    controller.removeListener(listener);

//    return 0;
//}