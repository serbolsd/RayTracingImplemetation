#include "jlSampler.h"
#include "jdVector2.h"
void 
Sampler::mapSamplerToUnitDisk() {
  int size = m_samples.size();
  float r, phi; // polar coordinates
  JDVector2 sp; // sample point on unit disk
  diskSamples.resize(size);
  for (int j = 0; j < size; j++) {
    // map sample point to [-1, 1] [-1,1]
    sp.x = 2.0 * m_samples[j].x - 1.0;
    sp.y = 2.0 * m_samples[j].y - 1.0;
    if (sp.x > -sp.y) { // sectors 1 and 2
      if (sp.x > sp.y) { // sector 1 
        r = sp.x;
        phi = sp.y / sp.x;
      }
      else { // sector 2
        r = sp.y;
        phi = 2 - sp.x / sp.y;
      }
    }
    else { // sectors 3 and 4
      if (sp.x < sp.y) { // sector 3
        r = -sp.x;
        phi = 4 + sp.y / sp.x;
      }
      else { // sector 4
        r = -sp.y;
        if (sp.y != 0.0) // avoid division by zero at origin
          phi = 6 - sp.x / sp.y;
        else
          phi = 0.0;
      }
    }
    phi *= PI / 4.0;
    diskSamples[j].x = r * cos(phi);
    diskSamples[j].y = r * sin(phi);
  }
}

void 
Sampler::mapSamplesToHemisphere(const float& e) {
  int size = m_samples.size();
  m_hemisphereSamples.reserve(m_numSamples * m_numSets);
  for (int j = 0; j < size; j++) {
    float cos_phi = cos(2.0 * PI * m_samples[j].x);
    float sin_phi = sin(2.0 * PI * m_samples[j].x);
    float cos_theta = pow((1.0 - m_samples[j].y), 1.0 / (e + 1.0));
    float sin_theta = sqrt(1.0 - cos_theta * cos_theta);
    float pu = sin_theta * cos_phi;
    float pv = sin_theta * sin_phi;
    float pw = cos_theta;
    //if (pw>0.5f)
    //{
    //  pw = 1;
    //}
    //if (pw < -0.5f)
    //{
    //  pw = -1;
    //}
    //if (pu > 0.5f)
    //{
    //  pu = 1;
    //}
    //if (pu < -0.5f)
    //{
    //  pu = -1;
    //}
    //if (pv > 0.5f)
    //{
    //  pv = 1;
    //}
    //if (pv < -0.5f)
    //{
    //  pv = -1;
    //}
    m_hemisphereSamples.push_back(JDVector3(pu, pv, pw));
  }
}
