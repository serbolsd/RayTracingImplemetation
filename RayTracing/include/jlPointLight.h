/*****************************************************************************/
/**
 * @file    jlPointLight.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for a Point Light
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlLight.h"

class PointLight : public Light
{
public:
  PointLight() {};
  ~PointLight() {};

  virtual JDVector3
  getDirection(ShadeRec& sr) override;

  virtual sf::Color
  L(ShadeRec& sr) override {
    auto c = m_color;
    c.r *= m_ls;
    c.g *= m_ls;
    c.b *= m_ls;
    return c;
  }

  float m_ls = 1.0f;
  sf::Color m_color;
  JDVector3 m_location;


};