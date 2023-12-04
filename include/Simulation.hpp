// Simulation.hpp

#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SFML/Graphics.hpp>
#include "SharedData.hpp"

class Simulation {
public:
    Simulation(SharedData& data);

    void update();
    sf::Vector2f getPosition() const;
    sf::Vector2f getInnerSize() const;

private:
    SharedData& sharedData;

    void checkCollision();
};

#endif // SIMULATION_HPP
