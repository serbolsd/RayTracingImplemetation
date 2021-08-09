/*****************************************************************************/
/**
 * @file    jlTRayCast.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    02/08/2021
 * @brief   A class for ray cast
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "Tracer.h"
#include "World.h"
#include "jlMaterial.h"

class RayCast : public Tracer
{
public:
  RayCast() {};
  ~RayCast() {};

  virtual JDVector3
  traceRay(const Ray& ray, int depth) override {
    ShadeRec sr(m_pWorld->hitObjects(ray));
    if (sr.m_hitAnObject)
    {
      sr.m_ray = ray;
      return sr.m_pMaterial->shade(sr);
    }
    return { 0, 0, 0};
  };


};