#include "jlBRDFGlossySpecular.h"
#include "shadeRec.h"

JDVector3 
BRDFGlossySpecular::f(const ShadeRec& sr, const JDVector3& wo, const JDVector3& wi) {
  JDVector3 L{ 0, 0, 0 };
  float ndotwi = sr.m_normal.dot(wi);
  JDVector3 r(-wi + 2.0 * sr.m_normal * ndotwi);
  float rdotwo = r.dot(wo);
  if (rdotwo > 0.0) {
    auto col = m_ks * Math::pow(rdotwo, m_exp);
    L = { col ,col ,col };
  }
  return L;
}

JDVector3 
BRDFGlossySpecular::sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) {
  return { 0, 0, 0 };
}

JDVector3 
BRDFGlossySpecular::rho(const ShadeRec& sr, const JDVector3& wo) {
  return { 0, 0, 0 };
}
