#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <thread>

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(600, 800), "Nimble Nimbus");
Texture playerTexture;
Sprite player;

Texture pillarTex;
Sprite topPipe;
Sprite bottomPipe;



void loadImages()
{
    playerTexture.loadFromFile("images/bird.png");
    pillarTex.loadFromFile("images/pipe.png");
}
void loadSprites()
{
    player.setTexture(playerTexture);
    player.setPosition(100, 300);

    topPipe.setTexture(pillarTex);
    topPipe.setPosition(600, 0);

    bottomPipe.setTexture(pillarTex);
    bottomPipe.setPosition(600, 600);
}
void handleInput()
{
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        player.move(0, -5);
    }
}
void update()
{
    // makes sure the program isn't running too quick

    this_thread::sleep_for(chrono::milliseconds(1));

    player.move(0, 1);

    // Check if the player is colliding with the top or bottom pipe.
    if (player.getGlobalBounds().intersects(topPipe.getGlobalBounds()) || player.getGlobalBounds().intersects(bottomPipe.getGlobalBounds()))
    {
        // If the player is colliding with the pipe, end the game.
        window.close();
    }

    // pipe generation for the top and bottom. uses random functions to make sure they differ in position when they appear.
    if (topPipe.getPosition().x < 0)
    {
        topPipe.setPosition(600, 0);

        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, 300);
        int yPos = dist(mt);

        topPipe.setPosition(600, yPos);
    }

    if (bottomPipe.getPosition().x < 0)
    {
        bottomPipe.setPosition(600, 600);

        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist2(300, 600);
        int yPos = dist2(mt);

        bottomPipe.setPosition(600, yPos);
    }

    topPipe.move(-1, 0);
    bottomPipe.move(-1, 0);

}


// renders the player and the pipes in the window
void render()
{
    window.draw(player);
    window.draw(topPipe);
    window.draw(bottomPipe);
}


int main()
{
    loadImages();
    loadSprites();

    while (window.isOpen())
    {
      
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        handleInput();
        update();
        window.clear();
        render();
        window.display();


    }

    return 0;
}