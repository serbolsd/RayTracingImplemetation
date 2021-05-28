#include <SFML/Graphics.hpp>
#include "World.h"

int main()
{
  World w;
  w.build(400, 400);
  w.renderScene();
  return 0;
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  // Create a image filled with black color
  sf::Image image;
  image.create(800, 600, sf::Color::Black);
  for (size_t x = 200; x < 601; x++)
  {
    for (size_t y = 150; y < 451; y++)
    {
      image.setPixel(x,y, sf::Color::Cyan);
    }
  }
  sf::Texture texture;
  texture.create(800,600);
  texture.update(image);

  sf::Sprite s(texture);
  // run the program as long as the window is open
  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::White);
    window.draw(s);
    window.display();
  }

  return 0;
}