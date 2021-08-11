/*****************************************************************************/
/**
 * @file    Plane.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for a plane heredated by geometricObject
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "geometriObject.h"

class Plane : public GeometricObject {
 public:
  /**
   * @brief defaul constructor
   */
		Plane() = default;

  /**
   * @brief constructor with point and normal
   * @param point is the plane's point
   * @param normal is the plane's normal
   */
  Plane(const Point3D point, const JDVector3& normal);
  
  /**
   * @brief function to detected a hit
   * @param ray is the ray whit check the hit
   * @pram t is the theta minimun
   * @pram s is the shade rec
   */
  virtual bool
  hit(const Ray& ray, double& t, ShadeRec& s) override;

  bool
		shadowHit(const Ray& ray, float& tmin) override;

  /**
   * @brief defaul destructor
   */
		~Plane() {};
 private:
  /**
   * @brief point through which
   */
   JDVector3 m_point;

  /**
   * @brief normal to the plane
   */
  JDVector3 m_normal;

  /**
   * @brief epislon const
   */
  static const double kEpsilon;
};