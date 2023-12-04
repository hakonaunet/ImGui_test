// SharedData.hpp

#ifndef SHAREDDATA_HPP
#define SHAREDDATA_HPP

#include <SFML/Graphics.hpp>

struct SharedData {
    sf::Vector2f innerSize;
    sf::Vector2f outerBounds;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float deltaTime;
    int frameCount;
    double runtime;

    bool isSimulationRunning;

    SharedData() : innerSize(50.0f, 20.0f), outerBounds(2000.0f, 1300.0f),
                    position(100.0f, 100.0f), velocity(50.0f, 50.0f),
                    deltaTime(0.016f), frameCount(0), runtime(0.0),
                    isSimulationRunning(false) {}
};

#endif // SHAREDDATA_HPP