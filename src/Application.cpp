// Application.cpp

#include "Application.hpp"

Application::Application() : simulation(sharedData), ui(sharedData) {
    // Initialize the application
}


void Application::run() {
    sf::Vector2f screensize(2000.0f, 1300.0f);
    sf::RenderWindow window(sf::VideoMode(screensize.x, screensize.y), "Physics Simulation");    // Initialize ImGui with SFML
    
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

        if (sharedData.isSimulationRunning) {
            simulation.update();
        }

        // Start the ImGui frame
        ImGui::SFML::Update(window, deltaClock.restart());
        ui.render();  // Assuming this method encapsulates ImGui render calls

        // Clear the window
        window.clear();
        if (sharedData.isSimulationRunning) {
            sf::RectangleShape rectangle(sf::Vector2f(simulation.getInnerSize()));
            rectangle.setPosition(simulation.getPosition());
            window.draw(rectangle);
        }
        ImGui::SFML::Render(window);

        // Display the rendered frame
        window.display();
    }

    ImGui::SFML::Shutdown();
}