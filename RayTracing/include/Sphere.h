/*****************************************************************************/
/**
 * @file    Sphere.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for a sphere heredated by geometricObject
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once
#include "geometriObject.h"

class Sphere : public GeometricObject {
 public:
  /**
   * @brief defaul constructor
   */
  Sphere() = default;

  /**
   * @brief constructor with point and normal
   * @param pos is the sphere's position
   */
  Sphere(const Point3D& pos, const float& radius);
  
  /**
   * @brief function to detected a hit
   * @param ray is the ray whit check the hit
   * @pram t is the theta minimun
   * @pram s is the shade rec
   */
  virtual bool
  hit(const Ray& ray, double& t, ShadeRec& s) override;
  
  /**
   * @brief defaul destructor
   */
  ~Sphere() {};
 public:
  /**
   * @brief sphere´s position
   */
  Point3D m_position;

  /**
   * @brief sphere´s radius
   */
  float m_radius;

  /**
   * @brief epislon const
   */
  static const double kEpsilon;
};