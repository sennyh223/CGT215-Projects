#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

using namespace sf;
using namespace std;


vector<vector<int>> kernel({
    {1,1,1},
    {1,1,1},
    {1,1,1}
    });
    
    

void Blur(Image imgIn, Image imgOut) {
    
    int width = imgIn.getSize().x;
    int height = imgIn.getSize().y;

    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            int minX = max(x - 1, 0);
            int maxX = min(x + 1, width - 1);
            int minY = max(y - 1, 0);
            int maxY = min(y + 1, width - 1);
            int pixelCount = 0;
            int accR = 0;
            int accB = 0;
            int accG = 0;
            for (int pixY = minY; pixY <= maxY; pixY++) {
                for (int pixX = minX; pixX <= maxX; pixX++) {
                    int kernelX = pixX - x + 1;
                    int kernelY = pixY - y + 1;
                
                Color pixColor = imgIn.getPixel(pixX, pixY);
                int weight = kernel[kernelY][kernelX];
                accR += pixColor.r*weight;
                accG += pixColor.g*weight;
                accB += pixColor.b*weight;
                pixelCount += weight;
                }
                    
            }
            Color pixColor = Color(accR / pixelCount, accG / pixelCount, accB / pixelCount);
            imgOut.setPixel(x, y, pixColor);
        }
    }
}

int main()
{
	Image img;
	img.loadFromFile("../images/winter.png");
	Image outImg;
	outImg.create(img.getSize().x, img.getSize().y);

	Blur(img,outImg);
	outImg.saveToFile("blur.png");

	//show image
	Texture tex1;
	tex1.loadFromImage(outImg);
	RenderWindow window(sf::VideoMode(800, 600), "Show me a picture");
	Sprite sprite1;
	sprite1.setTexture(tex1);
	window.draw(sprite1);
	window.display();

}