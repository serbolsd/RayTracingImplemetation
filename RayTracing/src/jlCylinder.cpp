#include "jlCylinder.h"

const double Cylinder::kEpsilon = 0.00001;

bool 
Cylinder::hit(const Ray& ray, double& t, ShadeRec& s) {
  //double t = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  auto dir = ray.m_direction;
  auto pos = ray.m_origin;
  //dir.y = 0;
  //dir.normalize();
  auto centerToRayX = pos.x - m_position.x;
  auto centerToRayZ = pos.z - m_position.z;
  float a = (dir.x * dir.x) + (dir.z * dir.z);
  float b = 2.0 * (dir.x * (centerToRayX) + dir.z * (centerToRayZ));
  float c = (centerToRayX * centerToRayX) + (centerToRayZ * centerToRayZ) - (m_radius * m_radius);
  float disc = b * b - 4.0 * a * c;
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

  if ((r >= m_position.y) && (r <= m_position.y + m_height)) {

    auto localHitP = ray.m_origin + t * ray.m_direction;
    auto tempNormal = JDVector3(localHitP.x - m_position.x, 0, localHitP.z - m_position.z);
    tempNormal.y = 0;
    s.m_normal = tempNormal.getnormalize();
    s.m_localHitPoint.x = localHitP.x;
    s.m_localHitPoint.y = localHitP.y;
    s.m_localHitPoint.z = localHitP.z;
    return true;
  }
  else 
    return false;

  return false;
}

bool 
Cylinder::shadowHit(const Ray& ray, float& tmin) {

  //double t = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  auto dir = ray.m_direction;
  auto pos = ray.m_origin;
  //dir.y = 0;
  //dir.normalize();
  auto centerToRayX = pos.x - m_position.x;
  auto centerToRayZ = pos.z - m_position.z;
  float a = (dir.x * dir.x) + (dir.z * dir.z);
  float b = 2.0 * (dir.x * (centerToRayX)+dir.z * (centerToRayZ));
  float c = (centerToRayX * centerToRayX) + (centerToRayZ * centerToRayZ) - (m_radius * m_radius);
  float disc = b * b - 4.0 * a * c;
  if (disc < 0.0)
    return false;

  float t1 = (-b - sqrt(disc)) / (2 * a);
  float t2 = (-b + sqrt(disc)) / (2 * a);
  //float t;

  if (t1 > kEpsilon) {
    float r = ray.m_origin.y + t1 * ray.m_direction.y;

    if ((r >= m_position.y) && (r <= m_position.y + m_height)) {
      tmin = t1;
      return true;
    }
  }
  return false;
}
