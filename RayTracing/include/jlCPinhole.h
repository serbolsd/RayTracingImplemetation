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
#include <SFML/Graphics/Color.hpp>

class CPinhole : public Camera {
 public: 
  /**
   * @brief default constructor
   */
  CPinhole() = default;

  /**
   * @brief default constructor
   */
  ~CPinhole() {};

  /**
   * @brief function to get the ray direction with a point
   * @param p is the point
   * @return the ray's direction
   */
  JDVector3
  rayDirection(const JDPoint& p);

  /**
   * @brief function to render the scene
   */
  virtual void
  renderScene(World* world) override;

  /**
   * @brief function to render the scene
   */
  virtual void
  renderScenePerFrame(World* world) override;

  JDVector3
  classSamplerRender(int x, int y, World* world, Ray& ray);

  /**
   * @brief the view-plane distance
   */
  float m_viewDistance; 

  /**
   * @brief the zoom factor
   */
  float m_zoom;

  int x = 0;
  int y = 0;
};

