/*****************************************************************************/
/**
 * @file    jlSJittered.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    06/06/2021
 * @brief   A class for jittered sampling
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once

#include "jlSampler.h"

class SJittered : public Sampler
{
 public:
  /**
   * @brief default constructor
   */
  SJittered() = default;
  
  /**
   * @brief constructor
   * @param numSamplers is the times to sampling
   */
  SJittered(int numSamplers) {
    m_numSamples = numSamplers;
  };

  /**
   * @brief default destructor
   */
  ~SJittered() {};


 private:

  /**
   * @brief generate sample patterns in a unit square
   */
  virtual void
  generateSamples() override;

};

FORCEINLINE void SJittered::generateSamples() {
  int n = (int)sqrt(m_numSamples);
  for (int p = 0; p < m_numSets; p++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        JDPoint sp((k + randomFloat()) / n, (j + randomFloat()) / n);
        m_samples.push_back(sp);
      }
    }
  }
}
