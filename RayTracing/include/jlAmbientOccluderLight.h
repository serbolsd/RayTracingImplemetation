/*****************************************************************************/
/**
 * @file    jlAmbientOccluderLight.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    01/08/2021
 * @brief   A class for a Ambient Occlusion
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jlLight.h"
class Sampler;

class AmbientOccluderL : public Light
{
 public:
		AmbientOccluderL();
		~AmbientOccluderL();

  virtual void 
  setSampler(Sampler* sampler);

  virtual JDVector3
  getDirection(ShadeRec& sr) override;

  virtual JDVector3
  L(ShadeRec& sr) override;

  virtual bool
  inShadow(const Ray& ray, const ShadeRec& sr) override;

  Sampler* m_pSampler;

  JDVector3 m_u, m_v, m_w;
  JDVector3 m_minAmount;
  float m_ls = 1.0f;
  JDVector3 m_color;
 private:
};
