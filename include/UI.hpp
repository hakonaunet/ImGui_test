// UI.hpp

#ifndef UI_HPP
#define UI_HPP

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "SharedData.hpp"

class UI {
    public:
        UI(SharedData& data) : sharedData(data) {}

        void render(); // Implement the UI rendering logic

    private:
        SharedData& sharedData;
};


#endif // UI_HPP
