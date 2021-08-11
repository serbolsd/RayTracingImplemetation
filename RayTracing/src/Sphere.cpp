#include "Sphere.h"

Sphere::Sphere(const Point3D& pos, const float& radius) {
  m_position = pos;
  m_radius = radius;
}

const double Sphere::kEpsilon = 0.00001;

bool
Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) {

  //double t0 = 0;
  //double t1 = 0;
  //JDVector3 temp;
  //temp.x = m_position.x - ray.m_origin.x;
  //temp.y = m_position.y - ray.m_origin.y;
  //temp.z = m_position.z - ray.m_origin.z;

  //float tca = temp.dot(ray.m_direction);
  //float d2 = temp.dot(temp)- tca * tca;
  //if (d2 > m_radius) {
  //  return false;
  //}

  //float thc = sqrt(m_radius - d2);

  //t0 = tca - thc;
  //t1 = tca + thc;

  //if (t0 > t1)
  //{
  //  std::swap(t0, t1);
  //}

  //if (t0 < 0)
  //{
  //  t0 = t1;
  //  if (t0 < 0)
  //  {
  //    return false;
  //  }
  //}

  //tmin = t0;
  //sr.m_normal = (temp + tmin * ray.m_direction) / m_radius;
  //auto dir = tmin * ray.m_direction;
  //sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
  //sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
  //sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
  //return true;


  //double t=0;
  //JDVector3 temp;
  //temp.x = ray.m_origin.x - m_position.x;
  //temp.y = ray.m_origin.y - m_position.y;
  //temp.z = ray.m_origin.z - m_position.z;
  //double a = ray.m_direction.dot(ray.m_direction);
  //double b = 2.0 * temp.dot(ray.m_direction);
  //double c = temp.dot(temp) - (m_radius * m_radius);
  //double disc = b * b - 4.0 * a * c;
  //if (disc < 0.0)
  //  return(false);
  //else {
  //  double e = sqrt(disc);
  //  double denom = 2.0 * a;
  //  t = (-b - e) / denom; // smaller root
  //  if (t > kEpsilon) {
  //    tmin = t;
  //    sr.m_normal = (temp + t * ray.m_direction) / m_radius;
  //    auto dir = t * ray.m_direction;
  //    sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
  //    sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
  //    sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
  //    return (true);
  //  }
  //  t = (-b + e) / denom; // larger root
  //  if (t > kEpsilon) {
  //    tmin = t;
  //    sr.m_normal = (temp + t * ray.m_direction) / m_radius;
  //    auto dir = t * ray.m_direction;
  //    sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
  //    sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
  //    sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
  //    //sr.m_localHitPoint = ray.o + t * ray.d;
  //    return (true);
  //  }
  //}
  //return false;

  float t = 0;
  float t0 = 0;
  float t1 = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  float a = ray.m_direction.dot(ray.m_direction);
  float b = 2.0 * temp.dot(ray.m_direction);
  float c = temp.dot(temp) - (m_radius * m_radius);
  float disc = b * b - 4.0 * a * c;
  if (disc < 0.0)
    return false;
  else if (disc == 0)
  {
    t0 = t1 = -0.5f * b / a;
  }
  else {
    float q = (b > 0) ?
      -0.5 * (b + sqrt(disc)) :
      -0.5 * (b - sqrt(disc));
    t0 = q / a;
    t1 = c / q;
  }

  if (t0 > t1)
  {
    std::swap(t0, t1);
  }

  if (t0 < 0)
  {
    t0 = t1;
    if (t0 < 0)
    {
      return false;
    }
  }

  tmin = t0;
  sr.m_normal = (temp + tmin * ray.m_direction) / m_radius;
  auto dir = tmin * ray.m_direction;
  sr.m_localHitPoint.x = ray.m_origin.x + dir.x;
  sr.m_localHitPoint.y = ray.m_origin.y + dir.y;
  sr.m_localHitPoint.z = ray.m_origin.z + dir.z;
  return true;
}

bool 
Sphere::shadowHit(const Ray& ray, float& tmin) {
  //return false;
  float  t = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  float a = ray.m_direction.dot(ray.m_direction);
  float b = 2.0 * temp.dot(ray.m_direction);
  float c = temp.dot(temp) - (m_radius * m_radius);
  float disc = b * b - 4.0 * a * c;

  if (disc < 0.0)
    return false;
  else {
    float e = sqrt(disc);
    float denom = 2.0 * a;
    t = (-b - e) / denom; // smaller root
    if (t > kEpsilon) {
      tmin = t;
      return true;
    }
  }
  return(false);

  /*float t = 0;
  float t0 = 0;
  float t1 = 0;
  JDVector3 temp;
  temp.x = ray.m_origin.x - m_position.x;
  temp.y = ray.m_origin.y - m_position.y;
  temp.z = ray.m_origin.z - m_position.z;
  float a = ray.m_direction.dot(ray.m_direction);
  float b = 2.0 * temp.dot(ray.m_direction);
  float c = temp.dot(temp) - (m_radius * m_radius);
  float disc = b * b - 4.0 * a * c;
  if (disc < 0.0)
    return false;
  else if (disc == 0)
  {
    t0 = t1 = -0.5f * b / a;
  }
  else {
    float q = (b > 0) ?
      -0.5 * (b + sqrt(disc)) :
      -0.5 * (b - sqrt(disc));
    t0 = q / a;
    t1 = c / q;
  }

  if (t0 > t1)
  {
    std::swap(t0, t1);
  }

  if (t0 < 0)
  {
    t0 = t1;
    if (t0 < 0)
    {
      return false;
    }
  }

  tmin = t0;
  return true;*/
}
