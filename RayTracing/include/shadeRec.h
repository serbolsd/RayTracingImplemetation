#pragma once
#include "point3D.h"
#include "Prerequisites.h"
#include <jdVector3.h>
#include <SFML/Graphics/Color.hpp>

class World;

class ShadeRec {
public:

  ShadeRec(World* wr); // constructor

  ShadeRec(const ShadeRec* sr); // copy constructor

  ~ShadeRec() {}; // destructor

  ShadeRec& // assignment operator
  operator= (const ShadeRec& rhs);


  bool m_hitAnObject; // did the ray hit an object?
  Point3D m_localHitPoint; // world coordinates of hit point 
  JDVector3 m_normal; // normal at hit point
  sf::Color m_color; // used in Chapter 3 only
  World* m_world; // world reference for shading
};

ShadeRec::ShadeRec(World* wr) 
  : m_hitAnObject(false),
    m_localHitPoint(0),
    m_normal(),
    m_color(sf::Color::Black),
    m_world(wr){}

inline 
ShadeRec::ShadeRec(const ShadeRec& sr) {
  *this = sr;
}

inline ShadeRec& 
ShadeRec::operator=(const ShadeRec& rhs) {
  m_hitAnObject = rhs.m_hitAnObject;
  m_localHitPoint = rhs.m_localHitPoint;
  m_normal = rhs.m_normal;
  m_color = rhs.m_color;
  m_world = rhs.m_world;
}
