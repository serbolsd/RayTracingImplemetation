/*****************************************************************************/
/**
 * @file    jlLight.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for a Light
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include <jdVector3.h>
#include <SFML/Graphics/Color.hpp>

class ShadeRec;

class Light
{
public:
  Light() {};
  ~Light() {};


  virtual JDVector3
  getDirection(ShadeRec& sr) = 0;

  virtual sf::Color
  L(ShadeRec& sr) = 0;
};