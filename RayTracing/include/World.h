/*****************************************************************************/
/**
 * @file    World.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for a world
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
#include <SFML/Graphics.hpp>
#include "ViewPlane.h"
//#include “RGBColor.h”
#include "Sphere.h"
#include "Tracer.h"

class World {
public:
  /**
   * @brief defaul constructor
   */
  World();

  /**
   * @brief defaul destructor
   */
  ~World();

  /**
   * @brief function to build the world
   * @param width is the window's width
   * @param height is the window's height
   */
  void
  build(const int width, const int height);

  /**
   * @brief function to renderScene
   */
  void
  renderScene();

  /**
   * @brief function to init and open window
   * @param width is the window's width
   * @param height is the window's height
   */
  void
  openWindow(const int width, const int height);

  void
  updateRender();

  /**
   * @brief function to change color to a pixel
   */
  void
  displayPixel(const int row,
                const int column,
                const sf::Color& pixel_color);

  ViewPlane m_vp;
  sf::Color m_backgroundColor = sf::Color::Black;
  Sphere m_sphere;
  Tracer* m_pTracer;
  
  sf::RenderWindow* m_window = nullptr;
  sf::Image m_image;
  sf::Texture m_texture;
  sf::Sprite m_sprite;
};
