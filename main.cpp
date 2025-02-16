/*
*
* Program Name: Hackathon 2025 project: Team boolean ring
* Group members: Jason Taylor, Alicia Brusseau, Trevys Okamura, Yaru Gao
*
*
*/
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

const float PI = 3.14159265359f;
const int NUM_CURVES = 15; // Number of rotated curves

bool loadFont(sf::Font& font) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error: Could not load font 'arial.ttf'!" << std::endl;
        return false;
    }
    return true;
}

sf::VertexArray generateCurve() {
    sf::VertexArray curve(sf::LineStrip);
    for (float t = -10.0f; t <= 10.0f; t += 0.1f) {
        int randomNumber = rand() % 400 + 300;
        int randomNumber2 = rand() % 100 + 10;
        float x = randomNumber + randomNumber2 * t;
        float y = randomNumber + randomNumber2 * sin(t) * cos(0.5f * t);
        curve.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(rand() % 255, rand() % 255, rand() % 255)));
    }
    return curve;
}

int main() {
    sf::RenderWindow outputWindow(sf::VideoMode(800, 800), "Piet Paint");
    sf::RenderWindow inputWindow(sf::VideoMode(500, 250), "User Input");

    sf::Font font;
    if (!loadFont(font)) return -1;

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(20, 20);

    std::string input = "Enter your formula: \n";
    sf::VertexArray curve = generateCurve();
    bool inputWindowFocused = true;

    std::vector<sf::RectangleShape> palette;
    std::vector<sf::Color> colors = {
        sf::Color::Red, sf::Color::Green, sf::Color::Blue,
        sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan
    };
    for (size_t i = 0; i < colors.size(); ++i) {
        sf::RectangleShape colorBox(sf::Vector2f(40, 40));
        colorBox.setFillColor(colors[i]);
        colorBox.setPosition(750, 20 + i * 45);
        palette.push_back(colorBox);
    }

    while (outputWindow.isOpen() || inputWindow.isOpen()) {
        sf::Event event;
        while (outputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                outputWindow.close();
        }
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                inputWindow.close();
            text.setString(input);
            if (event.type == sf::Event::GainedFocus) inputWindowFocused = true;
            if (event.type == sf::Event::LostFocus) inputWindowFocused = false;
            if (inputWindowFocused && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && input.length() > 18) {
                    input.pop_back();
                }
                else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                    input += static_cast<char>(event.text.unicode);
                }
            }
        }
        if (outputWindow.isOpen()) {
            outputWindow.clear(sf::Color::Black);
            outputWindow.draw(curve);

            //for (const auto& box : palette) {
            //    outputWindow.draw(box);
            //}

            outputWindow.display();
        }
        if (inputWindow.isOpen()) {
            inputWindow.clear(sf::Color::White);
            inputWindow.draw(text);
            inputWindow.display();
        }
    }
    return 0;
}
