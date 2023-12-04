// Simulation.cpp

#include "Simulation.hpp"

Simulation::Simulation(SharedData& data) : sharedData(data) {
    // Other initialization code, if necessary
}

void Simulation::update() {
    sharedData.position += sharedData.velocity * sharedData.deltaTime;
    checkCollision(); // Window size, adjust as needed
    sharedData.runtime += sharedData.deltaTime;
    sharedData.frameCount++;
}

void Simulation::checkCollision() {
    // Check and handle collisions with window edges
    if (sharedData.position.x < 0 || sharedData.position.x + sharedData.innerSize.x > sharedData.outerBounds.x) {
        sharedData.velocity.x = -sharedData.velocity.x;
    }
    if (sharedData.position.y < 0 || sharedData.position.y + sharedData.innerSize.y > sharedData.outerBounds.y) {
        sharedData.velocity.y = -sharedData.velocity.y;
    }
}

sf::Vector2f Simulation::getPosition() const {
    return sharedData.position;
}

sf::Vector2f Simulation::getInnerSize() const {
    return sharedData.innerSize;
}