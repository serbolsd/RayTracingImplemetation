#include "Plane.h"

Plane::Plane(const Point3D point, const JDVector3& normal) {
  m_point = point;
  m_normal = normal;
}

const double Plane::kEpsilon = 0.00001;

bool 
Plane::hit(const Ray& ray, double& tmin, ShadeRec& s) {
  double t = pointVecDot((m_point - ray.m_origin), m_normal) / (ray.m_direction.dot(m_normal));
  if (t > kEpsilon) {
    tmin = t;
    s.m_normal = m_normal;
    s.m_localHitPoint.x = ray.m_origin.x + t * ray.m_direction.x;
    s.m_localHitPoint.y = ray.m_origin.y + t * ray.m_direction.y;
    s.m_localHitPoint.z = ray.m_origin.z + t * ray.m_direction.z;
    return (true);
  }
  else
    return (false);
}
