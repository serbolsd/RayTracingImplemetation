#pragma once
/*****************************************************************************/
/**
 * @file    Sphere.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    25/07/2021
 * @brief   A basic class for a Cylinder heredated by geometricObject
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "geometriObject.h"

class Cylinder : public GeometricObject {
 public:
  /**
   * @brief defaul constructor
   */
  Cylinder() = default;

  /**
   * @brief constructor with point and normal
   * @param pos is the sphere's position
   */

  Cylinder(const float& radio, const float& height, const Point3D& pos) {
    m_radius = radio;
    m_height = height;
    m_position = pos;
  }

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
  ~Cylinder() {};
 public:

   Point3D m_position;
  /**
   * @brief sphere´s radius
   */
  float m_radius;
  
  /**
   * @brief sphere´s radius
   */
  float m_height;

  /**
   * @brief epislon const
   */
  static const double kEpsilon;

  JDVector3
  getNormalFace(int faceHit);
};
