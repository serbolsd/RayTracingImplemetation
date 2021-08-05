/*****************************************************************************/
/**
 * @file    jlBRDF.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    02/08/2021
 * @brief   A class for a BRDF in materials
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include <SFML/Graphics/Color.hpp>

#include "jdVector3.h"

class ShadeRec;
class Sampler;

class BRDF
{
public:
  BRDF() {};
  ~BRDF() {};


  virtual sf::Color
  f(const ShadeRec& sr, const JDVector3& wi, const JDVector3& wo) {
    return sf::Color::Black;
  };

  virtual sf::Color
  sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) {
    return sf::Color::Black;
  };

  virtual sf::Color
  rho(const ShadeRec& sr, const JDVector3& wo) {
    return sf::Color::Black;
  };

  Sampler* m_pSampler = nullptr;
};