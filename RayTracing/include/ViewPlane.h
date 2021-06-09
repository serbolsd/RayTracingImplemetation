/*****************************************************************************/
/**
 * @file    ViewPlane.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A class to view plane
 * @note    to simulate a hortografic camera
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "jlSampler.h"
#include "jlSJittered.h"

class ViewPlane
{
 public:

  void 
  setSampler(Sampler* s) {
    if (nullptr != m_pSampler)
    {
      delete m_pSampler;
      m_pSampler = nullptr;
    }
    m_numSamplers = s->m_numSamples;
    m_pSampler = s;
  };

  /**
   * @brief width of view
   */
  int m_width;

  /**
   * @brief height of view
   */
  int m_height;
  
  /**
   * @brief the pixel size
   */
  float m_pixelSize;
  
  /**
   * @brief monitor gamma factor
   */
  float m_gamma;
  
  /**
   * @brief one over gamma
   */
  float m_invGamma;

  /**
   * @brief num samplers
   */
  int m_numSamplers;

  Sampler* m_pSampler = nullptr;
};