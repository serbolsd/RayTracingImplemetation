#include "jlMMatte.h"
#include <jdVector3.h>
#include "shadeRec.h"
#include "World.h"
#include "jlLight.h"
sf::Color 
Matte::shade(ShadeRec& sr) {
  JDVector3 wo = -sr.m_ray.m_direction;
  sf::Color al = sr.m_world->m_pAmbientlight->L(sr);
  sf::Color l = m_ambientBRDF.rho(sr, wo);
  l.r *= al.r;
  l.g *= al.g;
  l.b *= al.b;

  int numLights = sr.m_world->m_lights.size();
  for (int i = 0; i < numLights; ++i)
  {
    JDVector3 wi = sr.m_world->m_lights[i]->getDirection(sr);
    float ndotwi = sr.m_normal.dot(wi);
    if (ndotwi > 0.0f)
    {
      auto df = m_difuseBRDF.f(sr, wi, wo);
      auto cl = sr.m_world->m_lights[i]->L(sr);
      l.r += df.r * cl.r * ndotwi;
      l.g += df.g * cl.g * ndotwi;
      l.b += df.b * cl.b * ndotwi;
    }
  }
  return l;
}
