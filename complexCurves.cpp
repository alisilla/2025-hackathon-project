//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <thread>
//#include <chrono>
//
//const int WINDOW_WIDTH = 800;
//const int WINDOW_HEIGHT = 800;
//const int ANIMATION_DURATION = 1000; // Limit animation duration
//
//struct MovingShape {
//    sf::Shape* shape;
//    sf::Vector2f velocity;
//    int lifetime;
//};
//
//// Function to generate a random color tone based on user preference
//sf::Color getRandomColor(const std::string& tone) {
//    int r, g, b;
//    if (tone == "warm") {
//        r = rand() % 156 + 100;
//        g = rand() % 100;
//        b = rand() % 100;
//    }
//    else if (tone == "cold") {
//        r = rand() % 100;
//        g = rand() % 100 + 100;
//        b = rand() % 156 + 100;
//    }
//    else {
//        r = rand() % 256;
//        g = rand() % 256;
//        b = rand() % 256;
//    }
//    return sf::Color(r, g, b);
//}
//
//// Function to generate curve progressively
//void generateCurve(sf::RenderWindow& window) {
//    sf::VertexArray curve(sf::LineStrip);
//    for (float t = -10.0f; t <= 10.0f; t += 0.1f) {
//        int randomNumber = rand() % 400 + 300;
//        int randomNumber2 = rand() % 100 + 10;
//        float x = randomNumber + randomNumber2 * t;
//        float y = randomNumber + randomNumber2 * sin(t) * cos(0.5f * t);
//        curve.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(rand() % 255, rand() % 255, rand() % 255)));
//
//        window.clear();
//        window.draw(curve);
//        window.display();
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    }
//}
//
//// Function to generate shapes with movement styles
//std::vector<MovingShape> generateShapes(const std::string& shapeType, const std::string& colorTone, const std::string& animationType) {
//    std::vector<MovingShape> shapes;
//    for (int i = 0; i < 20; ++i) {
//        sf::Shape* shape = nullptr;
//        sf::Color color = getRandomColor(colorTone);
//        float x = rand() % WINDOW_WIDTH;
//        float y = rand() % WINDOW_HEIGHT;
//        float angle = rand() % 360;
//        sf::Vector2f velocity;
//
//        if (shapeType == "circle") {
//            shape = new sf::CircleShape(rand() % 50 + 20);
//        }
//        else if (shapeType == "triangle") {
//            shape = new sf::CircleShape(rand() % 50 + 20, 3);
//        }
//        else if (shapeType == "line") {
//            shape = new sf::RectangleShape(sf::Vector2f(rand() % 100 + 50, 5));
//        }
//        else if (shapeType == "curve") {
//            return {}; // Handled separately in main
//        }
//
//        if (shape) {
//            shape->setFillColor(color);
//            shape->setPosition(x, y);
//            shape->setRotation(angle);
//
//            if (animationType == "sprinkle") {
//                velocity = sf::Vector2f((rand() % 5) - 2, (rand() % 5) - 2);
//            }
//            else if (animationType == "erupt") {
//                velocity = sf::Vector2f((rand() % 10) - 5, -(rand() % 10));
//            }
//            else { // Default bounce
//                velocity = sf::Vector2f((rand() % 5) - 2, (rand() % 5) - 2);
//            }
//
//            shapes.push_back({ shape, velocity, ANIMATION_DURATION });
//        }
//    }
//    return shapes;
//}
//
//int main() {
//    srand(static_cast<unsigned>(time(0)));
//    std::string shapeType, colorTone, animationType;
//    char animatedChoice;
//    bool animated;
//
//    while (true) {
//        std::cout << "Enter shape type (circle, triangle, line, curve): ";
//        std::cin >> shapeType;
//        if (shapeType == "curve") {
//            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Generating Curve...");
//            generateCurve(window);
//            window.close();
//            continue;
//        }
//
//        std::cout << "Enter color tone (warm, cold, random): ";
//        std::cin >> colorTone;
//        std::cout << "Enable animation? (y/n): ";
//        std::cin >> animatedChoice;
//        animated = (animatedChoice == 'y' || animatedChoice == 'Y');
//        if (animated) {
//            std::cout << "Choose animation type (sprinkle, erupt, bounce): ";
//            std::cin >> animationType;
//        }
//
//        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Abstract Art Generator");
//        std::vector<MovingShape> shapes = generateShapes(shapeType, colorTone, animationType);
//
//        while (window.isOpen()) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == sf::Event::Closed)
//                    window.close();
//            }
//
//            if (animated) {
//                for (auto& movingShape : shapes) {
//                    movingShape.shape->move(movingShape.velocity);
//                }
//            }
//
//            window.clear();
//            for (const auto& movingShape : shapes) {
//                window.draw(*movingShape.shape);
//            }
//            window.display();
//            std::this_thread::sleep_for(std::chrono::milliseconds(50));
//        }
//
//        for (auto& movingShape : shapes) {
//            delete movingShape.shape;
//        }
//    }
//    return 0;
//}
