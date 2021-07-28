/*****************************************************************************/
/**
 * @file    Sphere.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    25/07/2021
 * @brief   A basic class for a Box heredated by geometricObject
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "geometriObject.h"

class Box : public GeometricObject {
 public:
  /**
   * @brief defaul constructor
   */
  Box() = default;

  /**
   * @brief constructor with point and normal
   * @param pos is the sphere's position
   */
  Box(const Point3D& vmin, const Point3D& vmax) {
    m_vmin = vmin;
    m_vmax = vmax;
  }

  Box(const Point3D& vmin, const Point3D& vmax, const Point3D& pos) {
    m_vmin = pos + vmin;
    m_vmax = pos + vmax;
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
  ~Box() {};
 public:
  /**
   * @brief sphere´s position
   */
  Point3D m_vmin;

  /**
   * @brief sphere´s position
   */
  Point3D m_vmax;

  /**
   * @brief epislon const
   */
  static const double kEpsilon;

  JDVector3
  getNormalFace(int faceHit);
};
