/*****************************************************************************/
/**
 * @file    jRegulasSampler.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    014/06/2021
 * @brief   A class for regular sampling
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

#include "jlSampler.h"

class SRegular : public Sampler {
public:
  /**
   * @brief default constructor
   */
  SRegular() = default;

  /**
   * @brief constructor
   * @param numSamplers is the times to sampling
   */
  SRegular(int numSamplers) {
    m_numSamples = numSamplers;
  };

  /**
   * @brief default destructor
   */
  ~SRegular() {};


private:

  /**
   * @brief generate sample patterns in a unit square
   */
  virtual void
  generateSamples() override;

};

FORCEINLINE void SRegular::generateSamples() {
  int n = (int)sqrt(m_numSamples);
  for (int p = 0; p < m_numSets; p++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        JDVector2 sp((k + 0.5f) / n, (j + 0.5f) / n);
        m_samples.push_back(sp);
      }
    }
  }
}
