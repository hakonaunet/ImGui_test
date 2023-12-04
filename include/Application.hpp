// Application.hpp

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Simulation.hpp"
#include "UI.hpp"

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>

#include <iostream>

class Application {

    public:
        Application();
        void run(); // Main application loop

    private:
        Simulation simulation;
        UI ui;
    };

#endif // APPLICATION_HPP
