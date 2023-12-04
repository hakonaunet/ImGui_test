// Application.hpp

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>

#include <iostream>

#include "UI.hpp"
#include "Simulation.hpp"
#include "SharedData.hpp"

class Application {
public:
    Application();

    void run();

private:
    SharedData sharedData;
    Simulation simulation;
    UI ui;
};


#endif
