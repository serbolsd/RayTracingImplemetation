#pragma once
#include "ray.h"
#include <SFML/Graphics/Color.hpp>
#include "shadeRec.h"

class GeometricObject {
public:
    virtual bool
    hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;
protected:
  sf::Color color; // only used in first step
};