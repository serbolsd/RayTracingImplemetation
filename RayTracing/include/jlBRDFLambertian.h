/*****************************************************************************/
/**
 * @file    jlBRDFLambertian.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    02/08/2021
 * @brief   A class for a BRDF Lambertian in materials
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlBRDF.h"

class BRDFLambertian : public BRDF
{
public:
  BRDFLambertian() {};
  ~BRDFLambertian() {};

  virtual sf::Color
  f(const ShadeRec& sr, const JDVector3& wi, const JDVector3& wo) override;

  virtual sf::Color
  sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) override;

  virtual sf::Color
  rho(const ShadeRec& sr, const JDVector3& wo) override;

  float m_kd;
  sf::Color m_cd;

};