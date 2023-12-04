// Application.cpp

#include "Application.hpp"

Application::Application() {
    // Initialize any application-specific resources or states
    // Initialize UI and Simulation instances if needed
}

void Application::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulation");
    // Initialize ImGui with SFML
    
    bool ImGui_initialization = ImGui::SFML::Init(window);
    if (!ImGui_initialization) {
        // Handle initialization failure
        std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    }


    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the simulation
        simulation.update();

        // Start the ImGui frame
        ImGui::SFML::Update(window, deltaClock.restart());
        ui.render();  // Assuming this method encapsulates ImGui render calls

        // Clear the window
        window.clear();
        // Render your simulation here
        // ...

        // Render ImGui over everything else
        ImGui::SFML::Render(window);

        // Display the rendered frame
        window.display();
    }

    ImGui::SFML::Shutdown();
}