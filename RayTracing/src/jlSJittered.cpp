#include "jlSJittered.h"

void SJittered::generateSamples() {
  int n = (int)sqrt(m_numSamples);
  for (int p = 0; p < m_numSets; p++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        float r1 = randomFloat();
        float r2 = randomFloat();
        JDVector2 sp((k + r1) / n, (j + r2) / n);
        //if (sp.x > 0.5f)
        //{
        //  sp.x = 1;
        //}
        //if (sp.x < -0.5f)
        //{
        //  sp.x = -1;
        //}
        //if (sp.y > 0.5f)
        //{
        //  sp.y = 1;
        //}
        //if (sp.y < -0.5f)
        //{
        //  sp.y = -1;
        //}
        m_samples.push_back(sp);
      }
    }
  }
}