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

/*
The mazes are built carefully to closely match design patterns deduced from the original maps found in Pac-Man and Ms. Pac-Man:

Map is 28x31 tiles.
Paths are only 1 tile thick
No sharp turns (i.e. intersections are separated by atleast 2 tiles).
There are 1 or 2 tunnels
No dead-ends.
Only I, L, T, or + wall shapes are allowed, including the occasional rectangular wall.
Any non-rectangular wall pieces must only be 2 tiles thick.

*/

/*
############################
#............##............#
#.####.#####.##.#####.####.#
#.####.#####.##.#####.####.#
#.####.#####.##.#####.####.#
#..........................#
#.####.##.########.##.####.#
#.####.##.########.##.####.#
#......##....##....##......#
######.#####.##.#####.######
     #.#####.##.#####.#
     #.##..........##.#
     #.##.###--###.##.#
######.##.#      #.##.######
..........#      #..........
######.##.#      #.##.######
     #.##.########.##.#     
     #.##..........##.#     
     #.##.########.##.#     
######.##.########.##.######
#............##............#
#.####.#####.##.#####.####.#
#.####.#####.##.#####.####.#
#...##................##...#
###.##.##.########.##.##.###
###.##.##.########.##.##.###
#......##....##....##......#
#.##########.##.##########.#
#.##########.##.##########.#
#..........................#
############################
*/

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