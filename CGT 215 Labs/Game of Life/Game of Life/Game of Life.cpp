#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 10;

int main()
{
        // Create game window
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Conway's Game of Life");

    // Create 2D array of cells
    std::vector<std::vector<bool>> cells(WIDTH / CELL_SIZE, std::vector<bool>(HEIGHT / CELL_SIZE));


    // Game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update cells according to Conway's rules
        std::vector<std::vector<bool>> nextCells = cells;
        for (int x = 0; x < WIDTH / CELL_SIZE; x++)
        {
            for (int y = 0; y < HEIGHT / CELL_SIZE; y++)
            {
                // Count number of living neighbors
                int livingNeighbors = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        if (i == 0 && j == 0) continue; // skip current cell
                        if (x + i >= 0 && x + i < WIDTH / CELL_SIZE && y + j >= 0 && y + j < HEIGHT / CELL_SIZE && cells[x + i][y + j])
                            livingNeighbors++;
                    }
                }

                // Update cell according to Conway's rules
                if (cells[x][y] && (livingNeighbors < 2 || livingNeighbors > 3))
                    nextCells[x][y] = false;
                else if (!cells[x][y] && livingNeighbors == 3)
                    nextCells[x][y] = true;
            }
        }
        cells = nextCells;

        // Clear screen
        window.clear();

        // Draw cells
        for (int x = 0; x < WIDTH / CELL_SIZE; x++)
        {
            for (int y = 0; y < HEIGHT / CELL_SIZE; y++)
            {
                if (cells[x][y])
                {
                    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                    cell.setFillColor(sf::Color::Black);
                    window.draw(cell);
                }
            }
        }

        // Display frame
        window.display();
    }

    return 0;
}