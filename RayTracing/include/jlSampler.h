/*****************************************************************************/
/**
 * @file    jlSampler.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    06/06/2021
 * @brief   A virtual class for any sampler
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include <jdPoint.h>
#include <jdVector2.h>
class Sampler
{
 public:
  /**
   * @brief default constructor
   */
		Sampler() = default;

  /**
   * @brief defaul destructor
   */
  virtual ~Sampler() {};
  
  /**
   * @brief generate sample patterns in a unit square
   */
  virtual void
  generateSamples() {};

  /**
   * @brief set up the randomly shuffled indices
   */
  void
  setupShuffledIndices() {
    m_shuffledIndices.reserve(m_numSamples * m_numSets);
    std::vector<int> indices;
    for (int j = 0; j < m_numSamples; j++)
      indices.push_back(j);
    for (int p = 0; p < m_numSets; p++) {
      random_shuffle(indices.begin(), indices.end());
      for (int j = 0; j < m_numSamples; j++)
        m_shuffledIndices.push_back(indices[j]);
    }
  };

  /**
   * @brief randomly shuffle the samples in each pattern
   */
  void
  shuffleSamples(); 

  /**
   * @brief get next sample on unit square
   */
  JDVector2
  sampleUnitSquare(){
    if (m_count % m_numSamples == 0) // start of a new pixel
      m_jump = (randomInt() % m_numSets) * m_numSamples;
    return (m_samples[m_jump + m_count++ % m_numSamples]);
    //return (m_samples[m_jump + m_shuffledIndices[m_jump+ m_count++ % m_numSamples]]);
    //simple
    //int index = m_count++ % (m_numSamples * m_numSets);
    //if (index >= m_samples.size())
    //  index = m_samples.size() - 1;
    //return (m_samples[index]);
  };

  /**
   * @brief get next sample on unit disk
   */
  JDVector2
  sampleUnitDisk() {
    if (m_count % m_numSamples == 0) // start of a new pixel
      m_jump = (randomInt() % m_numSets) * m_numSamples;
    return (diskSamples[m_jump + m_count++ % m_numSamples]);
  }

  void
  mapSamplerToUnitDisk();

 public:
  /**
   * @brief the number of sample points in a pattern
   */
  int m_numSamples;

  /**
   * @brief the number of sample sets (patterns) stored
   */
  int m_numSets;

  /**
   * @brief sample points on a unit square
   */
  std::vector<JDVector2> m_samples;
  std::vector<JDVector2> diskSamples;

  /**
   * @brief shuffled samples array indices
   */
  std::vector<int> m_shuffledIndices;

  /**
   * @brief the current number of sample points used
   */
  unsigned long m_count;

  /**
   * @brief random index jump
   */
  int m_jump;
};
