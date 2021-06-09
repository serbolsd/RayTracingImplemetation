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
  setupShuffledIndices() {};

  /**
   * @brief randomly shuffle the samples in each pattern
   */
  void
  shuffleSamples(); 

  /**
   * @brief get next sample on unit square
   */
  JDPoint
  sample_unit_square(){
    if (m_count % m_numSamples == 0) // start of a new pixel
      m_jump = (randomInt() % m_numSets) * m_numSamples;
    return (m_samples[m_jump + m_count++ % m_numSamples]);
    //simple
    //return (m_samples[m_count++ % (m_numSamples * m_numSets)]);
  };

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
  std::vector<JDPoint> m_samples;

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
