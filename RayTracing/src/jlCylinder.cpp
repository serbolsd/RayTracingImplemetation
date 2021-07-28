#include "jlCylinder.h"

bool 
Cylinder::hit(const Ray& ray, double& t, ShadeRec& s) {
  //double t = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  auto dir = ray.m_direction;
  dir.y = 0;
  dir.normalize();
  //double a = ray.m_direction.dot(ray.m_direction);
  //double a = ray.m_direction.x * ray.m_direction.x + ray.m_direction.z * ray.m_direction.z;
  double a = dir.dot(dir);
  //double b = 2.0 * temp.dot(ray.m_direction);
  //double b = 2.0 * (ray.m_direction.x);
  double b = 2.0 * temp.dot(dir);
  double c = temp.dot(temp) - (m_radius * m_radius);
  double disc = b * b - 4.0 * a * c;
  if (disc < 0.0)
    return false;

  float t1 = (-b - sqrt(disc)) / (2 * a);
  float t2 = (-b + sqrt(disc)) / (2 * a);
  //float t;

  if (t1 > t2) 
    t = t2;
  else 
    t = t1;

  float r = ray.m_origin.y + t * ray.m_direction.y;

  if ((r >= m_position.y) and (r <= m_position.y + m_height)) {

    auto tempNormal = (temp + t * ray.m_direction) / m_radius;
    tempNormal.y = 0;
    s.m_normal = tempNormal.getnormalize();
    auto localHitP = ray.m_origin + t * ray.m_direction;
    s.m_localHitPoint.x = localHitP.x;
    s.m_localHitPoint.y = localHitP.y;
    s.m_localHitPoint.z = localHitP.z;
    return true;
  }
  else 
    return false;

  return false;
}
