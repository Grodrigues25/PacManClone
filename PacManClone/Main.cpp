#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "string"

using namespace std;

// TODO Board
// --------------------------------------------
// TODO: Investigate the best way to store the board format and to then render it


void renderBoard(sf::RenderWindow& window) {

}

int main() {

    // SETTINGS
    int windowWidth = 800;
    int windowHeight = 950;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //RENDER WINDOW
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "PacMan", sf::Style::Close, settings);
    sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
    background.setFillColor(sf::Color::Black);

    //GAME DATA STRUCTURES


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            }
        }

        window.display();
    }

	return 0;
}