#pragma once

#include <iostream>
#include <memory>

class SpeedManager {
private:
    double head_speed;
    double waist_speed;
    double leg_speed;
    double character_speed;
    double camera_speed;
    static std::unique_ptr<SpeedManager> instance;
    SpeedManager() : head_speed(0.0), waist_speed(0.0), leg_speed(0.0), character_speed(0.0), camera_speed(0.0) {}

public:
    static SpeedManager& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<SpeedManager>(new SpeedManager());
        }
        return *instance;
    }

    double getHeadSpeed() const {return head_speed;}
    void setHeadSpeed(double speed) {head_speed = speed;}

    double getWaistSpeed() const {return waist_speed;}
    void setWaistSpeed(double speed) {waist_speed = speed;}

    double getLegSpeed() const {return head_speed;}
    void setLegSpeed(double speed) {leg_speed = speed;}
    
    double getCharacterSpeed() const {return character_speed;}
    void setCharacterSpeed(double speed) {character_speed = speed;}

    double getCameraSpeed() const {return camera_speed;}
    void setCameraSpeed(double speed) {camera_speed = speed;}
};

std::unique_ptr<SpeedManager> SpeedManager::instance = nullptr;
