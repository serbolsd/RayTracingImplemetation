#pragma once
#include "point3D.h"
#include "Prerequisites.h"
#include <jdVector3.h>
#include <SFML/Graphics/Color.hpp>
//#include “ViewPlane.h”
//#include “RGBColor.h”
#include "Sphere.h"
//#include “Tracer.h”

class World {
public:
  World(void);
  void
  build(void);
  void
  render_scene(void) const;
  void
  open_window(const int hres, const int vres) const;
  void
  display_pixel(const int row,
                const int column,
                const sf::Color& pixel_color) const;

  //ViewPlane vp;
  sf::Color background_color;
  Sphere sphere;
  //Tracer* tracer_ptr;
};
