#pragma once

#include "Character.hpp"
#include "Robot.hpp"
#include <memory>
#include <cmath>
#include <iostream>

#include "SpeedState.hpp"

using namespace std;
class State {
public:
    virtual void handle(Character& character, Robot& robot) = 0;
};

class MovingLeft : public State {
public:
    void handle(Character& character, Robot& robot) override {
        cout << "MovingLeft" << endl;
        // character.setPosition(character.getCurrentPosition() - 0.1); // Karakter sola hareket ediyor
        robot.move();
        if (abs(robot.getHeadAngle()) > (20.0 * M_PI / 180.0)) {
            std::cout << "Kafa 20 dereceyi geçti. Bel hareketine geçiliyor." << std::endl;
        }
    }
};

class MovingRight : public State {
public:
    void handle(Character& character, Robot& robot) override {
        cout << "MovingRight" << endl;
        // character.setPosition(character.getCurrentPosition() + 0.1); // Karakter sağa hareket ediyor
        robot.move();
        if (abs(robot.getHeadAngle()) > (20.0 * M_PI / 180.0)) {
            std::cout << "Kafa 20 dereceyi geçti. Bel hareketine geçiliyor." << std::endl;
        }
    }
};

class WaistMoving : public State {
public:
    void handle(Character& character, Robot& robot) override {
        robot.setWaistAngle(robot.getWaistAngle() + 0.1);
        robot.setHeadAngle(robot.getHeadAngle() + 0.05);
        robot.move();
        std::cout << "Bel hareket ediyor. Kafa açısı: " << robot.getHeadAngle() << " rad, Bel açısı: " << robot.getWaistAngle() << " rad" << std::endl;
        if (abs(robot.getWaistAngle()) > (19.0 * M_PI / 180.0)) {
            std::cout << "Bel 20 dereceyi geçti. Ayak hareketine geçiliyor." << std::endl;
        }
    }
};

class LegsMoving : public State {
public:
    void handle(Character& character, Robot& robot) override {
        robot.setWaistAngle(robot.getWaistAngle() + 0.05);
        robot.setHeadAngle(robot.getHeadAngle() + 0.02);
        robot.move();
        std::cout << "Ayaklar hareket ediyor. Kafa ve bel küçük ayarlamalar yapıyor. Kafa açısı: " << robot.getHeadAngle() << " rad, Bel açısı: " << robot.getWaistAngle() << " rad" <<" ayak hızı:"<< robot.getLegSpeed()  << std::endl;
    }
};

class CorrectingPosition : public State {
public:
    void handle(Character& character, Robot& robot) override {
        robot.resetAngles();
        robot.move();
        std::cout << "Açıları düzeltiyor. Kafa açısı: " << robot.getHeadAngle() << " rad, Bel açısı: " << robot.getWaistAngle() << " rad" << std::endl;
    }
};

enum class CharacterState {
    Standing,
    SpeedingLeft,
    SpeedingRight
};

enum class RobotState {
    HeadMoving,
    WaistMoving,
    LegsMoving,
    CorrectingPosition,
    SpeedingUp,
    SlowingDown,
    MovingLeft,
    MovingRight
};
