#pragma once
#include "geometriObject.h"

class Sphere : public GeometricObject {
public:
  Sphere() = default;

  Sphere(const Point3D point, const JDVector3& normal);
  
  virtual bool
  hit(const Ray& ray, double& t, ShadeRec& s) const;
  
  ~Sphere() {};
private:
  Point3D m_point; // point through which
// plane passes
  JDVector3 m_normal; // normal to the plane
  JDVector3 m_center; // normal to the plane
  float m_radius;

  static const double kEpsilon;
};