#include <iostream>

#include "../include/ResourceManager.h"

bool ResourceManager::loadTextureFromFile(const std::string& name)
{
    TexturePtr tex = std::make_shared<sf::Texture>();
    if (!tex->loadFromFile(name))
    {   
        std::cout << "Could not load texture: " << name << "\n";
        return false;
    }

    textures.emplace(name, tex);
    return true;
}

bool ResourceManager::loadFontFromFile(const std::string& name)
{
    FontPtr font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(name))
    {   
        std::cout << "Could not load font: " << name << "\n";
        return false;
    }

    fonts.emplace(name, font);
    return true;
}

bool ResourceManager::loadSoundFromFile(const std::string& name)
{
    SoundPtr sound = std::make_shared<sf::SoundBuffer>();
    if (!sound->loadFromFile(name))
    {   
        std::cout << "Could not load sound: " << name << "\n";
        return false;
    }

    sounds.emplace(name, sound);
    return true;
}

TexturePtr ResourceManager::getTexture(const std::string& name)
{
    return mapHasKey(textures, name) ? textures[name] : nullptr;
}

FontPtr ResourceManager::getFont(const std::string& name)
{
    return mapHasKey(fonts, name) ? fonts[name] : nullptr;
}

SoundPtr ResourceManager::getSound(const std::string& name)
{
    return mapHasKey(sounds, name) ? sounds[name] : nullptr;
}

void ResourceManager::removeTexture(const std::string& name)
{
    textures.erase(name);
}

void ResourceManager::removeFont(const std::string& name)
{
    fonts.erase(name);
}

void ResourceManager::removeSound(const std::string& name)
{
    sounds.erase(name);
}

std::vector<std::string> ResourceManager::getLoadedTextures() const
{
    std::vector<std::string> out;

    for (auto pair : textures)
    {
        out.push_back(pair.first);
    }

    return out;
}

std::vector<std::string> ResourceManager::getLoadedFonts() const
{
    std::vector<std::string> out;

    for (auto pair : fonts)
    {
        out.push_back(pair.first);
    }
    
    return out;
}

std::vector<std::string> ResourceManager::getLoadedSounds() const
{
    std::vector<std::string> out;

    for (auto pair : sounds)
    {
        out.push_back(pair.first);
    }
    
    return out;
}