#include <iostream>

#include <SFPhysics.h>

#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 0.5;

void LoadTex(Texture& tex, string filename) {
	if (!tex.loadFromFile(filename)) {
		cout << "Could not Load " << filename << endl;
		exit(1);
	}
}


void MoveCrossbow(PhysicsSprite& crossbow, int elapsedMS) {
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		Vector2f newPos(crossbow.getCenter());
		newPos.x = newPos.x + (KB_SPEED * elapsedMS);
		crossbow.setCenter(newPos);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		Vector2f newPos(crossbow.getCenter());
		newPos.x = newPos.x - (KB_SPEED * elapsedMS);
		crossbow.setCenter(newPos);
	}
}



int main() {

	RenderWindow window(VideoMode(800, 600), "Balloon Buster");
	World world(Vector2f(0, 0));

	PhysicsSprite& crossBow = *new PhysicsSprite();
	Texture cbowTex;
	LoadTex(cbowTex, "images/crossbow.png");
	crossBow.setTexture(cbowTex);
	Vector2f sz = crossBow.getSize();
	crossBow.setCenter(Vector2f(400, 600 - (sz.x / 2)));

	Clock clock;
	Time lastTime(clock.getElapsedTime());
	Time currentTime(lastTime);

	while (true) {
		window.clear();
		MoveCrossbow(crossbow, deltaMS);
		
		window.draw(crossBow);
		window.display();
	}

}