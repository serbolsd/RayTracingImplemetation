/*****************************************************************************/
/**
 * @file    jlAmbientLight.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for a Ambient Light
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlLight.h"

class AmbientL : public Light
{
public:
  AmbientL() {};
  ~AmbientL() {};

  virtual JDVector3
  getDirection(ShadeRec& sr)override {
    return { 0, 0, 0 };
  };

  virtual sf::Color
  L(ShadeRec& sr)override { 
    auto c = m_color;
    c.r *= m_ls;
    c.g *= m_ls;
    c.b *= m_ls;
    return c;
  };

  float m_ls = 1.0f;

  sf::Color m_color = sf::Color::White;
};