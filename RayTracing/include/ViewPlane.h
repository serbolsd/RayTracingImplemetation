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

class ViewPlane
{
 public:
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

};