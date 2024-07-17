// Bounce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace std;
using namespace sf;
using namespace sfp;

void Thud(PhysicsBodyCollisionResult result) {
    cout << "thud";
}

void DoInput(PhysicsSprite& lander) {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        lander.applyImpulse(Vector2f(0.0005, 0));
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        lander.applyImpulse(Vector2f(-0.0005, 0));
    }
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "Bounce");
    World world(Vector2f(0, 0.1));
    PhysicsSprite lander;
    Texture tex;
    if (!tex.loadFromFile("LunarLander.png")) {
        cout << "Couldn't load image from file" << endl;
        exit(1);
    }
    lander.setTexture(tex);
    lander.setCenter(Vector2f(400, 300));
    world.AddPhysicsBody(lander);

    PhysicsRectangle floor;
    floor.setSize(Vector2f(800, 20));
    floor.setCenter(Vector2f(400, 590));
    floor.setStatic(true);
    bool crashed = false;
    floor.onCollision = [&crashed](PhysicsBodyCollisionResult result) {
        crashed = true;
    };
    world.AddPhysicsBody(floor);

    PhysicsRectangle target;
    target.setSize(Vector2f(100, 20));
    target.setCenter(Vector2f(600, 565));
    target.setStatic(true);
    bool landed = false;
    target.onCollision = [&landed](PhysicsBodyCollisionResult result) {
        landed = true;
    };
    world.AddPhysicsBody(target);

    Clock clock;
    Time lastTime(clock.getElapsedTime());
    while (!landed && !crashed) {
            // calculate MS since last frame
            Time currentTime(clock.getElapsedTime());
            Time deltaTime(currentTime - lastTime);
            int deltaTimeMS(deltaTime.asMilliseconds());
            if (deltaTimeMS > 0) {
                world.UpdatePhysics(deltaTimeMS);
                lastTime = currentTime;
                DoInput(lander);
            }
            window.clear(Color(0, 0, 0));
            window.draw(lander);
            window.draw(floor);
            window.draw(target);
            window.display();
        }
        Text text;
        Font font;
        if (!font.loadFromFile("arial.ttf")) {
            cout << "Couldnt load font for win message" << endl;
            exit(2);
        }
        if (landed) {
            text.setString("You Win!");
        }
        else {
            text.setString("You Crashed!");
        }
        text.setFont(font);
        FloatRect textBounds = text.getGlobalBounds();
        float textLeft = 400 - (textBounds.width / 2);
        float textTop = 300 - (textBounds.height / 2);
        text.setPosition(Vector2f(textLeft, textTop));
        window.draw(text);
        window.display();
        while (true);

}
