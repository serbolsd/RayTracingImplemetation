#include "jlMMatte.h"
#include <jdVector3.h>
#include "shadeRec.h"
#include "World.h"
#include "jlLight.h"
JDVector3 
Matte::shade(ShadeRec& sr) {
  JDVector3 wo = -sr.m_ray.m_direction;
  JDVector3 al = sr.m_world->m_pAmbientlight->L(sr);
  JDVector3 l = m_ambientBRDF.rho(sr, wo);
  l *= al;

  int numLights = sr.m_world->m_lights.size();
  for (int i = 0; i < numLights; ++i)
  {
    JDVector3 wi = sr.m_world->m_lights[i]->getDirection(sr);
    float ndotwi = sr.m_normal.dot(wi);
    if (ndotwi > 0.0f)
    {
      auto df = m_difuseBRDF.f(sr, wo, wi);
      auto cl = sr.m_world->m_lights[i]->L(sr);
      l += df * cl * ndotwi;
    }
  }
  return l;
}
