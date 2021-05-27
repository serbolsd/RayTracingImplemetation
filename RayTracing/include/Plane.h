#pragma once
#include "geometriObject.h"

class Plane : public GeometricObject {
 public:
		Plane() = default;

  Plane(const Point3D point, const JDVector3& normal);
  virtual bool

  hit(const Ray& ray, double& t, ShadeRec& s) const;
		~Plane() {};
 private:
   Point3D m_point; // point through which
// plane passes
   JDVector3 m_normal; // normal to the plane
   static const double kEpsilon;
};