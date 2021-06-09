#include <SFML/Graphics.hpp>
#include "World.h"

int main()
{
  World w;
  w.build(400, 400);
  w.renderScene();
  return 0;
}