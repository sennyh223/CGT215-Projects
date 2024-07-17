#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>

using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 0.2;

void LoadTex(Texture& tex, string filename) {
    if (!tex.loadFromFile(filename)) {
        cout << "Could not load " << filename << endl;
    }
}

int main()
{

    RenderWindow window(VideoMode(800, 600), "Duck Hunter");
    World world(Vector2f(0, 0));
    int score(0);
    int arrows(5);

    PhysicsSprite& player = *new PhysicsSprite();
    Texture playerTex;
    LoadTex(playerTex, "images/nimbus.png");
    player.setTexture(playerTex);
    Vector2f sz = player.getSize();
    player.setCenter(Vector2f(400,
        600 - (sz.y / 2)));

    PhysicsSprite arrow;
    Texture arrowTex;
    LoadTex(arrowTex, "images/arrow.png");
    arrow.setTexture(arrowTex);
    bool drawingArrow(false);

    PhysicsRectangle top;
    top.setSize(Vector2f(800, 10));
    top.setCenter(Vector2f(400, 5));
    top.setStatic(true);
    world.AddPhysicsBody(top);

    Texture duckTex;
    LoadTex(duckTex, "images/pillar.png");
    PhysicsShapeList<PhysicsSprite> pillars;

    PhysicsRectangle right;
    right.setSize(Vector2f(10, 600));
    right.setCenter(Vector2f(795, 300));
    right.setStatic(true);
    world.AddPhysicsBody(right);


    top.onCollision = [&drawingArrow, &world, &arrow]
    (PhysicsBodyCollisionResult result) {
        drawingArrow = false;
        world.RemovePhysicsBody(arrow);
    };

    Text scoreText;
    Font font;
    if (!font.loadFromFile("cocogoose.otf")) {
        cout << "Couldn't load font cocogoose.otf" << endl;
        exit(1);
    }
    scoreText.setFont(font);
    Text arrowCountText;
    arrowCountText.setFont(font);

    Clock clock;
    Time lastTime(clock.getElapsedTime());
    Time currentTime(lastTime);
    float ducktimer(0);


    while ((arrows > 0) || drawingArrow) {
        currentTime = clock.getElapsedTime();
        Time deltaTime = currentTime - lastTime;
        long deltaMS = deltaTime.asMilliseconds();
        if (deltaMS > 9) {
            ducktimer += deltaMS;
            lastTime = currentTime;
            world.UpdatePhysics(deltaMS);
            if (Keyboard::isKeyPressed(Keyboard::Space) &&
                !drawingArrow) {
                drawingArrow = true;
                arrow.setCenter(player.getCenter());
                arrow.setVelocity(Vector2f(0, -1.5));
                world.AddPhysicsBody(arrow);
                arrows -= 1;
            }

            if (ducktimer > 1000) {
                ducktimer = 0;
                for (int i(0); i < 1; i++) {
                    PhysicsSprite& duck = pillars.Create();
                    duck.setTexture(duckTex);
                    int x = 20 + ((700 / 4) * i);
                    Vector2f sz = duck.getSize();
                    duck.setCenter(Vector2f(x, 20 + (sz.y / 2)));
                    duck.setVelocity(Vector2f(0.25, 0));
                    world.AddPhysicsBody(duck);
                    duck.onCollision =
                        [&drawingArrow, &world, &arrow, &duck, &pillars, &score, &right]
                    (PhysicsBodyCollisionResult result) {
                        if (result.object2 == arrow) {
                            drawingArrow = false;
                            world.RemovePhysicsBody(arrow);
                            world.RemovePhysicsBody(duck);
                            pillars.QueueRemove(duck);
                            score += 10;
                        }
                        if (result.object2 == right) {
                            world.RemovePhysicsBody(duck);
                            pillars.QueueRemove(duck);
                        }

                    };
                }
            }

            window.clear();
            if (drawingArrow) {
                window.draw(arrow);
            }
            for (PhysicsShape& duck : pillars) {
                window.draw((PhysicsSprite&)duck);
            }
            window.draw(player);
            scoreText.setString(to_string(score));
            FloatRect textBounds = scoreText.getGlobalBounds();
            scoreText.setPosition(
                Vector2f(790 - textBounds.width, 590 - textBounds.height));
            window.draw(scoreText);
            arrowCountText.setString(to_string(arrows));
            textBounds = arrowCountText.getGlobalBounds();
            arrowCountText.setPosition(
                Vector2f(10, 590 - textBounds.height));
            window.draw(arrowCountText);
            //world.VisualizeAllBounds(window);

            window.display();
            pillars.DoRemovals();
        }
    }
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    FloatRect textBounds = gameOverText.getGlobalBounds();
    gameOverText.setPosition(Vector2f(
        400 - (textBounds.width / 2),
        300 - (textBounds.height / 2)
    ));
    window.draw(gameOverText);
    window.display();
    while (true);
}


