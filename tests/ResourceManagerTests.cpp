#include <iostream>

#include <SFML/System.hpp>

#include "../include/ResourceManager.h"

#define BEGIN_TEST { \
    std::cout.setstate(std::ios_base::failbit); \
    sf::err().setstate(std::ios_base::failbit); \
}

#define END_TEST { \
    std::cout.clear(); \
    sf::err().clear(); \
}

namespace ResourceManagerTests
{
    float test_loadTextureFromFile()
    {
        BEGIN_TEST

        ResourceManager manager;
        int failed_tests = 0;
        int total_tests = 0;

        total_tests++;
        if (!manager.loadTextureFromFile("tests/assets/images/smiley.png"))
        {
            failed_tests++;
        }

        total_tests++;
        if (manager.loadTextureFromFile("nonexistent.png"))
        {
            failed_tests++;
        }

        END_TEST

        return (float)(total_tests - failed_tests) / (total_tests);
    }

    float test_loadFontFromFile()
    {
        BEGIN_TEST

        ResourceManager manager;
        int failed_tests = 0;
        int total_tests = 0;

        total_tests++;
        if (!manager.loadFontFromFile("tests/assets/fonts/BrunoAce-Regular.ttf"))
        {
            failed_tests++;
        }

        total_tests++;
        if (manager.loadFontFromFile("nonexistent.ttf"))
        {
            failed_tests++;
        }

        END_TEST

        return (float)(total_tests - failed_tests) / (total_tests);
    }

    float test_loadSoundFromFile()
    {
        BEGIN_TEST

        ResourceManager manager;
        int failed_tests = 0;
        int total_tests = 0;

        total_tests++;
        if (!manager.loadSoundFromFile("tests/assets/sounds/6 - Shibasaki Station - War Of Tears.wav"))
        {
            failed_tests++;
        }

        total_tests++;
        if (manager.loadSoundFromFile("nonexistent.wav"))
        {
            failed_tests++;
        }

        END_TEST

        return (float)(total_tests - failed_tests) / (total_tests);
    }

    void runTests()
    {
        float loadTextureFromFile_successRate = test_loadTextureFromFile();
        std::cout << "test_loadTextureFromFile passed " << loadTextureFromFile_successRate * 100 << " percent of tests\n";

        float loadFontFromFile_successRate = test_loadFontFromFile();
        std::cout << "test_loadFontFromFile passed " << loadFontFromFile_successRate * 100 << " percent of tests\n";

        float loadSoundFromFile_successRate = test_loadSoundFromFile();
        std::cout << "test_loadSoundFromFile passed " << loadSoundFromFile_successRate * 100 << " percent of tests\n";
    }
}