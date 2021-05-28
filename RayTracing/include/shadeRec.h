/**
 * @file    shadeRec.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for shadeRec
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "point3D.h"
#include "Prerequisites.h"
#include <jdVector3.h>
#include <SFML/Graphics/Color.hpp>

class World;

class ShadeRec {
 public:
  /**
			* @brief constructo with world
			* @param world is a pointer to the world to use
			*/
  ShadeRec(World* world);

  /**
   * @brief copy constructor
   * @param sr is the other ShadeRec to copy
   */
  //ShadeRec(const ShadeRec* sr);

  /**
   * @brief defaul destructor
   */
  ~ShadeRec() {};

  /**
   * @brief assignment operator
   * @param rhs is the other ShadeRec to copy
   */
  ShadeRec&
  operator= (const ShadeRec& rhs);

  /**
   * @brief to check if the ray hitted and objetc
   */
  bool m_hitAnObject;

  /**
   * @brief world coordinates of hit point 
   */
  Point3D m_localHitPoint;

  /**
   * @brief normal at hit point
   */
  JDVector3 m_normal;

  /**
   * @brief use for debug
   */
  sf::Color m_color; 

  /**
   * @brief world reference for shading
   */
  World* m_world;
};

inline ShadeRec::ShadeRec(World* wr) 
  : m_hitAnObject(false),
    m_localHitPoint(0),
    m_normal(),
    m_color(sf::Color::Black),
    m_world(wr){}

//inline 
//ShadeRec::ShadeRec(const ShadeRec& sr) {
//  *this = sr;
//}

inline ShadeRec& 
ShadeRec::operator=(const ShadeRec& rhs) {
  m_hitAnObject = rhs.m_hitAnObject;
  m_localHitPoint = rhs.m_localHitPoint;
  m_normal = rhs.m_normal;
  m_color = rhs.m_color;
  m_world = rhs.m_world;
}