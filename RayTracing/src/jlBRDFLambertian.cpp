#include "jlBRDFLambertian.h" 
#include "shadeRec.h"

JDVector3 
BRDFLambertian::f(const ShadeRec& sr, const JDVector3& wi, const JDVector3& wo) {
  auto cd = m_cd;
  cd *= m_kd * (1/PI);
  return cd;
}

JDVector3 
BRDFLambertian::sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) {
  return { 0, 0, 0 };
}

JDVector3 
BRDFLambertian::rho(const ShadeRec& sr, const JDVector3& wo) {
  auto cd = m_cd;
  cd *= m_kd;
  return cd;
}
