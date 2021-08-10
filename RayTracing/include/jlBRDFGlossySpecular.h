/*****************************************************************************/
/**
 * @file    jlBRDGlossySpecular.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    09/08/2021
 * @brief   A class for a BRDF Glossy Specular in materials
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlBRDF.h"

class BRDFGlossySpecular : public BRDF
{
 public:
  BRDFGlossySpecular() {};
  ~BRDFGlossySpecular() {};

  virtual JDVector3
  f(const ShadeRec& sr, const JDVector3& wi, const JDVector3& wo) override;

  virtual JDVector3
  sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) override;

  virtual JDVector3
  rho(const ShadeRec& sr, const JDVector3& wo) override;

  float m_ks = 1;
  int m_exp = 10;
  JDVector3 m_cd = { 1, 1, 1 };

};