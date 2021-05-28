/*****************************************************************************/
/**
 * @file    tSingleSphere.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A class fro a tracer for a singel sphere
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Tracer.h"
#include "World.h"

class TSingleSphere : public Tracer
{
 public:
  /**
   * @brief defaul constructor
   */
  TSingleSphere() {};

  /**
   * @brief check if the ray hit with geometri
   * @param ray is the ray with check the hits
   * @return a color
   */
  sf::Color
  traceRay(const Ray& ray) override {
    ShadeRec sr(m_pWorld);
    double t;
    if (m_pWorld->m_sphere.hit(ray, t,sr))
    {
      return m_pWorld->m_sphere.color;
    }
    return sf::Color::Black;
  }
};