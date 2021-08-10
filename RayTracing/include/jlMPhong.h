/*****************************************************************************/
/**
 * @file    jlMPhong.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    09/08/2021
 * @brief   A class for Phong Materia
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlMaterial.h"
#include "jlBRDFLambertian.h"
#include "jlBRDFGlossySpecular.h"

class MPhong : public Material
{
 public:
  MPhong() {};
  ~MPhong() {};

  void
  setKa(const float& k) {
    m_ambientBRDF.m_kd = k;
  }

  void
  setKd(const float& k) {
    m_difuseBRDF.m_kd = k;
  }

  void
  setKS(const float& k) {
    m_SpecularBRDF.m_ks = k;
  }

  void
  setSExp(const int exp) {
    m_SpecularBRDF.m_exp = exp;
  }

  void
  setCd(const JDVector3& c) {
    m_ambientBRDF.m_cd = c;
    m_difuseBRDF.m_cd = c;
    m_SpecularBRDF.m_cd = c;
  }

  virtual JDVector3
  shade(ShadeRec& sr) override;

  BRDFLambertian m_ambientBRDF;
  BRDFLambertian m_difuseBRDF;
  BRDFGlossySpecular m_SpecularBRDF;

};