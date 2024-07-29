#pragma once

#include <iostream>
#include <cmath>
#include "AngleManager.hpp"

class Robot {
private:
    double head_angle; // Current head angle in radians
    double waist_angle; // Current waist angle in radians
    double head_speed;
    double waist_speed;
    double leg_speed;
    double camera_speed;

public:
    Robot() : head_angle(0.), waist_angle(0.0), head_speed(0.3), waist_speed(0.0), leg_speed(0.0), camera_speed(0.0) {
        speedManager.setHeadSpeed(head_speed);
        speedManager.setWaistSpeed(waist_angle);
        speedManager.setLegSpeed(leg_speed);
    }
    AngleManager& angleManager = AngleManager::getInstance();
    SpeedManager& speedManager = SpeedManager::getInstance();

    void calculateSpeeds() {
        // Example speeds
        // head_speed = 0.2;
        // waist_speed = 0.;
        // leg_speed = 0.;
    
        // speedManager.setHeadSpeed(head_speed);
        // speedManager.setWaistSpeed(waist_speed);
        // speedManager.setLegSpeed(leg_speed);
        
        calculateCameraSpeeds();
    }

    void calculateCameraSpeeds() {
        camera_speed = 0.;
        if (std::abs(getHeadAngle()) < 38 * M_PI / 180.0) 
            camera_speed += getHeadSpeed();
        if (std::abs(getWaistAngle()) < 38.0 * M_PI / 180.0 && std::abs(getHeadAngle()) > 20 * M_PI / 180.0) 
            camera_speed += getWaistSpeed();
        if(std::abs(getWaistAngle()) > 38.0 * M_PI / 180.0 && std::abs(getHeadAngle()) > 38 * M_PI / 180.0 )
            camera_speed += getLegSpeed();
        speedManager.setCameraSpeed(camera_speed);
    }
    
    void updateAngles() {
        head_angle += head_speed;
        if (std::abs(head_angle) > 20.0 * M_PI / 180.0) {
            waist_angle += speedManager.getWaistSpeed();
            // head_angle = 20.0 * M_PI / 180.0;
        }
        if (std::abs(waist_angle) > 20.0 * M_PI / 180.0) {
            leg_speed += 0.01; // Example: Increase leg speed
            // waist_angle = 20.0 * M_PI / 180.0;
        }
        // else ler de gelemeli 20 ile -20 arasında ise ve bel 20 den büyükse kendini küçülterek. o noktaya varmalı
        // Ensure the angles stay within -40 to 40 degrees in radians
        if (head_angle > 40.0 * M_PI / 180.0) head_angle = 40.0 * M_PI / 180.0;
        if (head_angle < -40.0 * M_PI / 180.0) head_angle = -40.0 * M_PI / 180.0;
        if (waist_angle > 40.0 * M_PI / 180.0) waist_angle = 40.0 * M_PI / 180.0;
        if (waist_angle < -40.0 * M_PI / 180.0) waist_angle = -40.0 * M_PI / 180.0;
        angleManager.setHeadAngle(head_angle);
        angleManager.setWaistAngle(waist_angle);
        // speedManager.setLegSpeed(leg_speed);
        // speedManager.setWaistSpeed(waist_speed);
    }

    void move() {
        calculateSpeeds();
        updateAngles();
    }

    double getHeadAngle() const {
        return angleManager.getHeadAngle();
    }

    double getWaistAngle() const {
        return angleManager.getWaistAngle();
    }

    double getHeadSpeed() const {
        return speedManager.getHeadSpeed();
    }

    double getWaistSpeed() const {
        return speedManager.getWaistSpeed();
    }

    double getLegSpeed() const {
        return speedManager.getLegSpeed();
    }

    double getCameraSpeed() {
        return speedManager.getCameraSpeed();
    }

    void setHeadSpeed(double speed) {
        head_speed = speed;
        speedManager.setHeadSpeed(speed);
    }

    void setWaistSpeed(double speed) {
        waist_speed = speed;
        speedManager.setWaistSpeed(speed);
    }

    void setLegSpeed(double speed) {
        speedManager.setLegSpeed(speed);
        leg_speed = speed;
    }

    void setHeadAngle(double angle) {
        if (angle > 40.0 * M_PI / 180.0) {
            head_angle = 40.0 * M_PI / 180.0;
        } else if (angle < -40.0 * M_PI / 180.0) {
            head_angle = -40.0 * M_PI / 180.0;
        } else {
            head_angle = angle;
        }
        angleManager.setHeadAngle(head_angle);
    }

    void setWaistAngle(double angle) {
        if (angle > 40.0 * M_PI / 180.0) {
            waist_angle = 40.0 * M_PI / 180.0;
        } else if (angle < -40.0 * M_PI / 180.0) {
            waist_angle = -40.0 * M_PI / 180.0;
        } else {
            waist_angle = angle;
        }
        angleManager.setWaistAngle(waist_angle);
    }

    void resetAngles() {
        head_angle = 0.0;
        waist_angle = 0.0;
        angleManager.setHeadAngle(head_angle);
        angleManager.setWaistAngle(waist_angle);
    }
};