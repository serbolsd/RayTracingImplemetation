/*****************************************************************************/
/**
 * @file    tMultipleObject.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    5/06/2021
 * @brief   A class for a tracer for a mulpleObjects
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Tracer.h"
#include "World.h"

class TMultipleObjects : public Tracer
{
public:
  /**
   * @brief defaul constructor
   */
  TMultipleObjects() {};

  /**
   * @brief check if the ray hit with geometri
   * @param ray is the ray with check the hits
   * @return a color
   */
  JDVector3
  traceRay(const Ray& ray) override {
    ShadeRec sr(m_pWorld->hitBareBonesObjects(ray));
    if (sr.m_hitAnObject)
    {
      return sr.m_color;
    }
    return { 0, 0, 0 };
  }
};