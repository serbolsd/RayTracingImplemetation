#include "Sphere.h"

Sphere::Sphere(const Point3D point, const JDVector3& normal) {
  m_point = point;
  m_normal = normal;
}

const double Sphere::kEpsilon = 0.00001;

bool
Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double t;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_center.x;
  temp.y = ray.m_origin.y - m_center.y;
  temp.z = ray.m_origin.z - m_center.z;
  double a = ray.m_direction.dot(ray.m_direction);
  double b = 2.0 * temp.dot(ray.m_direction);
  double c = temp.dot(temp) - (m_radius * m_radius);
  double disc = b * b - 4.0 * a * c;
  if (disc < 0.0)
    return(false);
  else {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    t = (-b - e) / denom; // smaller root
    if (t > kEpsilon) {
      tmin = t;
      sr.m_normal = (temp + t * ray.m_direction) / m_radius;
      auto dir = t * ray.m_direction;
      sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
      sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
      sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
      return (true);
    }
    t = (-b + e) / denom; // larger root
    if (t > kEpsilon) {
      tmin = t;
      sr.m_normal = (temp + t * ray.m_direction) / m_radius;
      auto dir = t * ray.m_direction;
      sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
      sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
      sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
      //sr.m_localHitPoint = ray.o + t * ray.d;
      return (true);
    }
  }
  return false;
}
