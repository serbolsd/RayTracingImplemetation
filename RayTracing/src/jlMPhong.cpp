#include "jlMPhong.h"
#include "shadeRec.h"
#include "World.h"

JDVector3 
MPhong::shade(ShadeRec& sr) {
  JDVector3 wo = -sr.m_ray.m_direction;
  JDVector3 L = m_ambientBRDF.rho(sr, wo) * sr.m_world->m_pAmbientlight->L(sr);
  int num_lights = sr.m_world->m_lights.size();
  for (int j = 0; j < num_lights; j++) {
    JDVector3 wi = sr.m_world->m_lights[j]->getDirection(sr);
    float ndotwi = sr.m_normal.dot(wi);
    if (ndotwi > 0.0) {
      auto difF = m_difuseBRDF.f(sr, wi, wo); 
      auto specF = m_SpecularBRDF.f(sr, wo, wi);
      auto lightL = sr.m_world->m_lights[j]->L(sr);
      auto sum = difF + specF;
      auto mult = sum * lightL;
      mult *= ndotwi;
      L += mult;
    }

  }
  return L;
}
