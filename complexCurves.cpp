//#include <SFML/Graphics.hpp>
//#include <cmath>
//#include <vector>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 800), "Parametric Curve - SFML");
//
//    // Vertex array to hold the curve points
//    sf::VertexArray curve(sf::LineStrip);
//
//    // Generate the curve (parametric function)
//    for (float t = -10.0f; t <= 10.0f; t += 0.1f) {
//        float x = 400 + 50 * t;  // Linear x mapping
//        float y = 400 + 100 * sin(t) * cos(0.5f * t); // Complex function
//
//        sf::Vertex point(sf::Vector2f(x, y), sf::Color(255, 100, 255)); // Purple color
//        curve.append(point);
//    }
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear(sf::Color::Black);
//        window.draw(curve);
//        window.display();
//    }
//
//    return 0;
//}
