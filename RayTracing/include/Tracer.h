/*****************************************************************************/
/**
 * @file    Tracer.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for a tracer
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once

#include <SFML/Graphics/Color.hpp>

class World;
class Ray;

class Tracer
{
 public:
  /**
   * @brief default constructor
   */
		Tracer() = default;

  /**
   * @brief constructor with world
   * @param world is a pointer to the world to trace
   */
  Tracer(World* world) : m_pWorld(world) {};

  /**
   * @brief check if the ray hit with geometri
   * @param ray is the ray with check the hits
   * @return a color
   */
  virtual sf::Color
  traceRay(const Ray& ray) {
    return sf::Color::Black;
  };

  virtual sf::Color
  traceRay(const Ray& ray, int depth) {
    return sf::Color::Black;
  };

  virtual sf::Color
  traceRay(const Ray& ray,const float& tmin, int depth) {
    return sf::Color::Black;
  };


  /**
   * @brief pointer to the world to do trace
   */
  World* m_pWorld = nullptr;
};