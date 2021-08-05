/*****************************************************************************/
/**
	* @file    geometryObject.h
	* @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
	* @date    21/05/2021
	* @brief   A virtual class any kind of geometri
	*
	*
	* @bug	    No known bugs.
	*/
	/*****************************************************************************/
#pragma once
#include "ray.h"
#include <SFML/Graphics/Color.hpp>
#include "shadeRec.h"

class GeometricObject {
 public:
		/**
			* @brief function to detected a hit
			* @param ray is the ray whit check the hit
			* @pram tmin is the theta minimun
			* @pram sr is the shade rec
			*/
  virtual bool
  hit(const Ray& ray, double& tmin, ShadeRec& sr) { return false; };


		/**
			* @brief color use for debug
			*/
  sf::Color color; // only used in first step

		Material* m_pMaterial;
};