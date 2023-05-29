#pragma once

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::shared_ptr<sf::Font> FontPtr;
typedef std::shared_ptr<sf::SoundBuffer> SoundPtr;

template <typename K, typename V>
bool mapHasKey(const std::unordered_map<K,V>& map, const K& key)
{
    return map.find(key) != map.end();
}

class ResourceManager
{
public:
    /**
     * @brief loads a texture from a file
     * 
     * @param name filename
     * @return true if successful
     * @return false on failure
     */
    bool loadTextureFromFile(const std::string& name);

    /**
     * @brief loads a font from a file
     * 
     * @param name filename
     * @return true if successful
     * @return false on failure
     */
    bool loadFontFromFile(const std::string& name);

    /**
     * @brief loads a sound from a file
     * 
     * @param name filename
     * @return true if successful
     * @return false on failure
     */
    bool loadSoundFromFile(const std::string& name);

    /**
     * @brief Get the Texture object from given filename
     * 
     * @param name filename
     * @return TexturePtr the Texture or nullptr if it doesn't exist
     */
    TexturePtr getTexture(const std::string& name);

    /**
     * @brief Get the Font object from given filename
     * 
     * @param name filename
     * @return FontPtr the Font or nullptr if it doesn't exist
     */
    FontPtr getFont(const std::string& name);

    /**
     * @brief Get the Sound object from given filename
     * 
     * @param name filename
     * @return SoundPtr the Sound or nullptr if it doesn't exist
     */
    SoundPtr getSound(const std::string& name);

    /**
     * @brief Remove the Texture object from given filename, if it exists
     * 
     * @param name filename
     */
    void removeTexture(const std::string& name);
    /**
     * @brief Remove the Font object from the given filename, if it exists
     * 
     * @param name filename
     */
    void removeFont(const std::string& name);
    /**
     * @brief Remove the Sound object from the given filename, if it exists
     * 
     * @param name filename
     */
    void removeSound(const std::string& name);

    /**
     * @brief Get a vector of the filenames of the loaded textures
     * 
     * @return std::vector\<std::string>
     */
    std::vector<std::string> getLoadedTextures() const;
    /**
     * @brief Get a vector of the filenames of the loaded fonts
     * 
     * @return std::vector\<std::string>
     */
    std::vector<std::string> getLoadedFonts() const;
    /**
     * @brief Get a vector of the filenames of the loaded sounds
     * 
     * @return std::vector\<std::string>
     */
    std::vector<std::string> getLoadedSounds() const;

private:
    std::unordered_map<std::string, TexturePtr> textures;
    std::unordered_map<std::string, FontPtr> fonts;
    std::unordered_map<std::string, SoundPtr> sounds;

};

#endif // RESOURCEMANAGER_H