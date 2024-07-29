#pragma once
#include <iostream>
#include <memory>
#include <cmath>
#include "SpeedManager.hpp"

class Character {
private:
    double current_position; // -1 to 1
    double previous_position; // -1 to 1
    double camera_speed; // Speed of the camera
    double character_speed; // Speed of the character
    double direction; // -1 for left, 1 for right, 0 for none

public:
    Character() : current_position(0.0), previous_position(0.0), camera_speed(0.0), character_speed(0.0), direction(0.0) {}
    SpeedManager& speedManager = SpeedManager::getInstance();

    void setPosition(double position) {
        previous_position = current_position;
        current_position = position;
        calculateSpeeds();
        calculateDirection();
    }

    void calculateSpeeds() {
        character_speed = current_position - ((previous_position - current_position) - speedManager.getCameraSpeed()  ) ; // 0.8 ilk poz , ikinci poz 0.4 camera_speed 0.4
        speedManager.setCharacterSpeed(character_speed);
    }

    // void setCamaraSpeeds(double camareSpeeds)
    // {
    //     camera_speed = camareSpeeds;
    // }

    void calculateDirection() {
        direction = (camera_speed > 0) ? 1.0 : (camera_speed < 0) ? -1.0 : 0.0;
    }

    // double getCameraSpeed() const {
    //     return camera_speed;
    // }

    double getCharacterSpeed() const {
        return character_speed;
    }

    double getCurrentPosition() const {
        return current_position;
    }

    double getDirection() const {
        return direction;
    }
};