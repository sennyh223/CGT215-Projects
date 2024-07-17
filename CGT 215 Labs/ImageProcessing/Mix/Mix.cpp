#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
void Mix(Image& img1, Image img2) {
    int width = img1.getSize().x;
    int height = img1.getSize().y;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color pixColor = img1.getPixel(x, y);
            Color pix2Color = img2.getPixel(x, y);
            pixColor = Color(
                pixColor.r / 2 + pix2Color.r / 2,
                pixColor.g / 2 + pix2Color.g / 2,
                pixColor.b / 2 + pix2Color.b / 2,
                );
            img1.setPixel(x, y, pixColor);
        }
    }
}

int main()
{
    Image img, img2;
    img.loadFromFile("../images/alebrije.png");
    img2.loadFromFile("../images/prague.png");
    Mix(img, img2);
    RenderWindow window(VideoMode(800, 600), "Image Processing");

    Texture tex1;
    tex1.loadFromImage(img);
    Sprite sprite;
    sprite.setTexture(tex1);

    window.draw(sprite);
    window.display();

    while (true);
}