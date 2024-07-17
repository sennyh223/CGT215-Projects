#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
void GreenSeparation(Image& img) {
    int width = img.getSize().x;
    int height = img.getSize().y;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color pixColor = img.getPixel(x, y);
            pixColor.r = 0;
            pixColor.b = 0;
            img.setPixel(x, y, pixColor);
        }
    }
}

int main()
{
    Image img;
    img.loadFromFile("../images/winter.png");
    GreenSeparation(img);
    RenderWindow window(VideoMode(800, 600), "Image Processing");

    Texture tex1;
    tex1.loadFromImage(img);
    Sprite sprite;
    sprite.setTexture(tex1);

    window.draw(sprite);
    window.display();

    while (true);
}