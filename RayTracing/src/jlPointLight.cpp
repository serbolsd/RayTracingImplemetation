#include "jlPointLight.h"
#include "shadeRec.h"
#include "ray.h"
#include "World.h"

JDVector3 
PointLight::getDirection(ShadeRec& sr) {
  JDVector3 vec = { (float)sr.m_HitPoint.x, (float)sr.m_HitPoint.y, (float)sr.m_HitPoint.z };
  return (m_location - vec).getnormalize();
}

bool 
PointLight::castShadows() {
    return true;
}

bool PointLight::inShadow(const Ray& ray, const ShadeRec& sr) {
  float t = FLT_MAX;
  int num_objects = sr.m_world->m_objects.size();
  float d = m_location.distance(ray.m_origin);
  for (int j = 0; j < num_objects; j++)
    if (sr.m_world->m_objects[j]->shadowHit(ray, t) && t <= d) {
      return true;
    }
  return false;
}
