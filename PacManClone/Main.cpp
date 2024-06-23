#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "string"
#include "Tilemap.h"

using namespace std;

// TODO Board
// --------------------------------------------
// TODO: Investigate the best way to store the board format and to then render it -> This is the solution: https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php

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

    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("C:\\Users\\gonca\\source\\repos\\PacManClone\\assets\\Pac Man tile set.png", sf::Vector2u(16, 16), level, 16, 8))
        cout << "Error" << endl;

    window.draw(map);

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

        window.clear();

        renderBoard(window);

        window.display();
    }

	return 0;
}