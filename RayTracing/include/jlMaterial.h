/*****************************************************************************/
/**
 * @file    jlMaterial.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for Materia
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include <SFML/Graphics/Color.hpp>
class ShadeRec;

class Material
{
public:
  Material() {};
  ~Material() {};

  virtual sf::Color
  shade(ShadeRec& sr) {
    return sf::Color::Black;
  };

  virtual sf::Color
  areaLightShade(ShadeRec& sr) {
    return sf::Color::Black;
  };

  virtual sf::Color
  pathShade(ShadeRec& sr) {
    return sf::Color::Black;
  };
};
