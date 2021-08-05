#include "jlPointLight.h"
#include "shadeRec.h"
JDVector3 
PointLight::getDirection(ShadeRec& sr) {
  JDVector3 vec = { (float)sr.m_HitPoint.x, (float)sr.m_HitPoint.y, (float)sr.m_HitPoint.z };
  return (m_location - vec).getnormalize();
}
