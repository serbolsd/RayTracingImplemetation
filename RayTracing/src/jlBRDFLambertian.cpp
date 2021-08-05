#include "jlBRDFLambertian.h" 
#include "shadeRec.h"

sf::Color 
BRDFLambertian::f(const ShadeRec& sr, const JDVector3& wi, const JDVector3& wo) {
  auto cd = m_cd;
  cd.r *= m_kd * (1/PI);
  cd.g *= m_kd * (1/PI);
  cd.b *= m_kd * (1/PI);
  return cd;
}

sf::Color 
BRDFLambertian::sampleF(const ShadeRec& sr, JDVector3& wi, const JDVector3& wo) {
  return sf::Color::Black;
}

sf::Color 
BRDFLambertian::rho(const ShadeRec& sr, const JDVector3& wo) {
  auto cd = m_cd;
  cd.r *= m_kd;
  cd.g *= m_kd;
  cd.b *= m_kd;
  return cd;
}
