/*****************************************************************************/
/**
 * @file    jlCPinhol.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    15/06/2021
 * @brief   A class for pinhole camera
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "jlCamera.h"
#include "jdVector3.h"
#include "jdPoint.h"
#include "ray.h"
#include "jlSampler.h"

#include <SFML/Graphics/Color.hpp>

class CThinLens : public Camera {
 public:
  /**
   * @brief default constructor
   */
		CThinLens() = default;
  
  /**
   * @brief default destructor
   */
  ~CThinLens() {};

  /**
   * @brief function to set sampler
   * @param sp is the sampler to set
   */
  void
  setSampler(Sampler* sp);

  /**
   * @brief function to get the ray direction with a point
   * @param pp is the pixel point
   * @param lp is the lens point
   * @return the ray's direction
   */
  JDVector3
  rayDirection(const JDPoint& pp, const JDPoint& lp);

  /**
   * @brief function to render the scene
   */
  virtual void
  renderScene(World* world) override;

  /**
   * @brief lends ratio
   */
  float m_lendsRadius = 1;

  /**
   * @brief view plane distance
   */
  float m_viewDistance = 1000;

  /**
   * @brief focal plane distance
   */
  float m_focalDistance = 1;

  /**
   * @brief zoom factor
   */
  float m_zoom = 1;

  /**
   * @brief sampler object
   */
  Sampler* m_pSampler = nullptr;
};