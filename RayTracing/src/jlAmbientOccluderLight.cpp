#include "jlAmbientOccluderLight.h"
#include "jlSampler.h"
#include "shadeRec.h"
#include "World.h"

AmbientOccluderL::AmbientOccluderL()
{
}

AmbientOccluderL::~AmbientOccluderL()
{
}

void 
AmbientOccluderL::setSampler(Sampler* sampler) {
  if (m_pSampler) {
    //delete m_pSampler;
    m_pSampler = nullptr;
  }
  m_pSampler = sampler;
  m_pSampler->mapSamplesToHemisphere(1);
}

JDVector3 
AmbientOccluderL::getDirection(ShadeRec& sr) {
  JDVector3 sp = m_pSampler->sampleHemisphere();
  return (sp.x * m_u + sp.y * m_v + sp.z * m_w);
}

JDVector3 
AmbientOccluderL::L(ShadeRec& sr) {
  m_w = sr.m_normal;
  // jitter up vector in case normal is vertical
  m_v = m_w.cross(JDVector3(0.0072, 1.0, 0.0034));
  //m_v = JDVector3(0.0072, 1.0, 0.0034).cross(m_w);
  m_v.normalize();
  m_u = m_v.cross(m_w);
  //m_u = m_w.cross(m_v);
  Ray shadow_ray;
  shadow_ray.m_origin.x = (float)sr.m_HitPoint.x;
  shadow_ray.m_origin.y = (float)sr.m_HitPoint.y;
  shadow_ray.m_origin.z = (float)sr.m_HitPoint.y;
  shadow_ray.m_direction = getDirection(sr);
  if (inShadow(shadow_ray, sr))
    return (m_minAmount * m_ls * m_color);
  else
    return (m_ls * m_color);
}

bool 
AmbientOccluderL::inShadow(const Ray& ray, const ShadeRec& sr) {
  float t = FLT_MAX;
  int num_objects = sr.m_world->m_objects.size();
  for (int j = 0; j < num_objects; j++)
    if (sr.m_world->m_objects[j]->shadowHit(ray, t)&& t<10)
      return true;
  return false;
}
