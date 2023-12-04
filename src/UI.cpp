// UI.cpp

#include "UI.hpp"
#include "Application.hpp"

void UI::render() {
    ImGui::Begin("Simulation Controls");

    ImGui::SliderFloat2("Inner Size", &sharedData.innerSize.x, 10.0f, 100.0f);
    ImGui::SliderFloat2("Outer Bounds", &sharedData.outerBounds.x, 100.0f, 2000.0f);
    ImGui::SliderFloat("Delta Time", &sharedData.deltaTime, 0.001f, 0.1f);

    // Button to start the simulation
    if (ImGui::Button("Run Simulation")) {
        // Set flag to start simulation
        sharedData.isSimulationRunning = true;
        // Update simulation parameters based on UI input
    }

    // Display runtime information if simulation is running
    if (sharedData.isSimulationRunning) {
        ImGui::Text("Runtime: %f seconds", sharedData.runtime);
        ImGui::Text("Frames Rendered: %d", sharedData.frameCount);
    }

    ImGui::End();
}
