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

  virtual JDVector3
  L(ShadeRec& sr)override { 
    auto c = m_color;
    c *= m_ls;
    return c;
  };

  float m_ls = 1.0f;

  JDVector3 m_color = { 1, 1, 1 };
};