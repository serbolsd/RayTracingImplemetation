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
#include <jdVector3.h>
class ShadeRec;

class Material
{
public:
  Material() {};
  ~Material() {};

  virtual JDVector3
  shade(ShadeRec& sr) {
    return { 0, 0, 0};
  };

  virtual JDVector3
  areaLightShade(ShadeRec& sr) {
    return { 0, 0, 0 };
  };

  virtual JDVector3
  pathShade(ShadeRec& sr) {
    return { 0, 0, 0 };
  };
};
