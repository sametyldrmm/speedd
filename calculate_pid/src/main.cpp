#include "Statte.hpp"
using namespace std;

std::unique_ptr<State> StateSelector(Robot& robot) {
    if (abs(robot.getWaistAngle()) > (19.0 * M_PI / 180.0)) {
        return std::make_unique<LegsMoving>();
    } 
    else if  (abs(robot.getHeadAngle()) > (19.0 * M_PI / 180.0)) 
    {
        return std::make_unique<WaistMoving>();
    } 
    else {
        return std::make_unique<MovingLeft>(); // Default state
    }
}

int main() {
    Character character;
    Robot robot;
    std::unique_ptr<State> current_state = std::make_unique<MovingRight>();
    std::unique_ptr<SpeedState> current_speed = std::make_unique<SpeedingConstantSpeed>();

    for (int i = 0; i < 80; ++i) {
        if(i > 40)
            character.setPosition(0.8 - ((i -39) * 0.02));
        else
            character.setPosition(0.8 );

        current_speed = determineCameraSpeed(robot.getCameraSpeed(),character.getCharacterSpeed());
        current_speed->handle();

        current_state = StateSelector(robot);
        current_state->handle(character, robot);

        robot.setLegSpeed(robot.getLegSpeed() );

        std::cout << "Adım: " << i << ", Konum: " << character.getCurrentPosition() <<", character speed: "  << character.getCharacterSpeed() << ", camera speed: " << robot.getCameraSpeed() << ", Kafa Açısı: " << robot.getHeadAngle() << ", Bel Açısı: " << robot.getWaistAngle() << ", Kafa Hızı: " << robot.getHeadSpeed() << ", Bel Hızı: " << robot.getWaistSpeed() << ", Ayak Hızı: " << robot.getLegSpeed() << std::endl;

    }

    return 0;
}