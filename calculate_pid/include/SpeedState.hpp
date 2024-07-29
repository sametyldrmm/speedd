#pragma once

#include "Character.hpp"
#include "Robot.hpp"
#include <memory>
#include <cmath>
#include <iostream>

using namespace std;
enum class SpeedStateEnum {
    Start,
    Accelerating,
    Decelerating,
    ConstantSpeed
};

class SpeedState {
protected:
    SpeedManager& speedManager = SpeedManager::getInstance();
public:
    virtual void handle() = 0;
};

class SpeedingUpSpeed : public SpeedState {

public:
    void handle() override {
        cout << "SpeedingUpSpeed" << speedManager.getCharacterSpeed()  << endl;
        
        speedManager.setHeadSpeed(speedManager.getCharacterSpeed() / 2 > 1 ? 1 : speedManager.getCharacterSpeed() / 2  );
        speedManager.setWaistSpeed(speedManager.getCharacterSpeed() / 3 > 1 ? 1 : speedManager.getCharacterSpeed() / 3);
    }
};

class SpeedingDownSpeed : public SpeedState {
public:
    void handle() override {
        cout << "SlowingDownSpeed" << speedManager.getCharacterSpeed()  << endl;
        speedManager.setHeadSpeed(speedManager.getCharacterSpeed() / 2 > 1 ? 1 : speedManager.getCharacterSpeed() / 2  );
        speedManager.setWaistSpeed(speedManager.getCharacterSpeed() / 3 > 1 ? 1 : speedManager.getCharacterSpeed() / 3);
    }
};

class SpeedingConstantSpeed : public SpeedState {
public:
    void handle() override {
        cout << "ConstantSpeed" << speedManager.getCharacterSpeed()  << endl;
        speedManager.setHeadSpeed(speedManager.getHeadSpeed() * 1);
        speedManager.setWaistSpeed(speedManager.getWaistSpeed() * 1);
    }
};


std::unique_ptr<SpeedState> determineCameraSpeed(double camera_speed, double character_speed) {
    if(character_speed > camera_speed)
        return std::make_unique<SpeedingUpSpeed>();
    else if(character_speed < camera_speed)
        return std::make_unique<SpeedingDownSpeed>();
    else 
        return std::make_unique<SpeedingConstantSpeed>();
}

// hız kafanın durması ile durmalımı düşüelicek.
