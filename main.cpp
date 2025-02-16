/*
* 
*	Program Name: Hackathon 2025 project: Team boolean ring
*	Group members: Jason Taylor, Alicia Brusseau, Trevys Okamura, 
* 
* 
* 
*/

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

int main()
{
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Red Circle");

    // Create a red circle
    sf::CircleShape circle(100.f); // Radius = 100 pixels
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(350.f, 350.f); // Centered in the window

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        // Render
        window.clear(sf::Color::Black); // Clear the screen with black
        window.draw(circle); // Draw the red circle
        window.display(); // Display everything
    }

    return 0;
}