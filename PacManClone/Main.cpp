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
// TODO: Investigate the best way to store the board format and to then render it -> This is the solution: https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php -> DONE
// TODO: Scale Map file to proper window size

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

    //for (int i = 0; i < 180; i++)
    //{
    //    cout << i << ", ";
    //}

    const int level[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("C:\\Users\\gonca\\source\\repos\\PacManClone\\assets\\Map.png", sf::Vector2u(16, 16), level, 14, 12))
        cout << "Error" << endl;

    window.draw(map);

}

int main() {

    // SETTINGS
    int windowWidth = 800;
    int windowHeight = 960;

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