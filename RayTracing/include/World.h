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
#include "ray.h"
#include "geometriObject.h"
#include "jlCamera.h"

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

  /**
   * @brief function to update the image
   */
  void
  updateRender();

  /**
   * @brief function to change color to a pixel
   */
  void
  displayPixel(const int row,
                const int column,
                const sf::Color& pixel_color);

  /**
   * @brief function to render without samplers
   * @param x is the position of pixel in x
   * @param y is the position of pixel in y
   * @param zw is hard wired in
   * @param ray is the ray to shot
   */
  sf::Color
  noSamplerRender(int x, int y, const float& zw, Ray& ray);

  /**
   * @brief function to render with regular sampler
   * @param x is the position of pixel in x
   * @param y is the position of pixel in y
   * @param zw is hard wired in
   * @param ray is the ray to shot
   * @param numSamplers is number to sampling
   */
  sf::Color
  regularSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers);

  /**
   * @brief function to render with sampler class
   * @param x is the position of pixel in x
   * @param y is the position of pixel in y
   * @param zw is hard wired in
   * @param ray is the ray to shot
   * @param numSamplers is number to sampling
   */
  sf::Color
  classSamplerRender(int x, int y, const float& zw, Ray& ray);

 /**
   * @brief function to render with random sampling
   * @param x is the position of pixel in x
   * @param y is the position of pixel in y
   * @param zw is hard wired in
   * @param ray is the ray to shot
   */
  sf::Color
  RandomSamplingRender(int x, int y, const float& zw, Ray& ray);

  /**
   * @brief function to render with jittered sampler
   * @param x is the position of pixel in x
   * @param y is the position of pixel in y
   * @param zw is hard wired in
   * @param ray is the ray to shot
   * @param numSamplers is number to sampling
   */
  sf::Color
  JitteredSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers);

  /**
   * @brief function to add objets in the vector with objects in scene
   */
  void
  addObject(GeometricObject* obj) {
    m_objects.push_back(obj);
  };

  /**
   * @brief function to check hits with many objects
   */
  ShadeRec
  hitBareBonesObjects(const Ray& ray);

  std::vector<GeometricObject*> m_objects;


  /**
   * @brief view plane
   */
  ViewPlane m_vp;

  /**
   * @brief background color
   */
  sf::Color m_backgroundColor = sf::Color::Black;

  /**
   * @brief a sphere
   */
  Sphere m_sphere;

  /**
   * @brief pointer to tracer, can be to a single sphere or multiple objects
   */
  Tracer* m_pTracer;
  
  /**
   * @brief window
   */
  sf::RenderWindow* m_window = nullptr;

  /**
   * @brief image
   * @note where the pixels are painted
   */
  sf::Image m_image;

  /**
   * @brief texture which is connected with the image
   */
  sf::Texture m_texture;

  /**
   * @brief sprtie which is setted the texture
   */
  sf::Sprite m_sprite;

  Camera* m_camera;
};
