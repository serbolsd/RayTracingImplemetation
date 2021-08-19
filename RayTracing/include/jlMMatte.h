/*****************************************************************************/
/**
 * @file    jlMMatte.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for Matte Materia
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlMaterial.h"
#include "jlBRDFLambertian.h"
class Matte : public Material
{
 public:
  Matte() {};
  ~Matte() {};

  void
  setKa(const float& k) {
    m_ambientBRDF.m_kd = k;
  }
  void
  setKd(const float& k) {
    m_difuseBRDF.m_kd = k;
  }

  void
  setCd(const JDVector3& c) {
    m_ambientBRDF.m_cd = c;
    m_difuseBRDF.m_cd = c;
  }

  virtual JDVector3
  shade(ShadeRec& sr) override;

  BRDFLambertian m_ambientBRDF;
  BRDFLambertian m_difuseBRDF;
};