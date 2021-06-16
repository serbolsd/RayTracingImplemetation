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
