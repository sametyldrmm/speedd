#pragma once

#include <iostream>
#include <memory>

class AngleManager {
private:
    double head_angle;
    double waist_angle;
    static std::unique_ptr<AngleManager> instance;
    AngleManager() : head_angle(0.0), waist_angle(0.0) {}

public:
    static AngleManager& getInstance() {
        if (!instance) {
            instance = std::unique_ptr<AngleManager>(new AngleManager());
        }
        return *instance;
    }

    double getHeadAngle() const {
        return head_angle;
    }

    void setHeadAngle(double angle) {
        head_angle = angle;
    }

    double getWaistAngle() const {
        return waist_angle;
    }

    void setWaistAngle(double angle) {
        waist_angle = angle;
    }
};

std::unique_ptr<AngleManager> AngleManager::instance = nullptr;
