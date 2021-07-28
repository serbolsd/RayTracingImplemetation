/*****************************************************************************/
/**
 * @file    jlCamera.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    15/06/2021
 * @brief   A class for Camera
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "point3D.h"
#include "jdVector3.h"

class World;

class Camera {
 public:
  /**
   * @brief default constructor
   */
		Camera() = default;

  /**
   * @brief default constructor
   */
  ~Camera() {};

  /**
   * @brief function to calculate the vector u, v and w
   */
  void
  computeUVW();

  /**
   * @brief function to render the scene
   */
  virtual void
  renderScene(World* world) {};

  /**
   * @brief the camera's position
   */
  Point3D m_eye;

  /**
   * @brief the camera's look at
   */
  Point3D m_lookAt;

  /**
   * @brief the camera's relative up vector
   */
  JDVector3 m_up;

  /**
   * @brief the vector to simulate a perspective viewing
   * @notes w is teh front vector, u = right vector and v = realUp vector 
   */
  JDVector3 m_u, m_v, m_w;

  /**
   * @brief the expesure time
   */
  float m_exposureTime;

};