#pragma once
#ifndef UI_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

typedef std::weak_ptr<sf::RenderWindow> winPtr;

class UIElement
{};

class UI
{
public:
    UI(winPtr window, ResourceManager* manager);

    void draw();
    
private:
    winPtr window;
    ResourceManager* manager;

    std::vector<UIElement> elements;
};

#endif // UI_H