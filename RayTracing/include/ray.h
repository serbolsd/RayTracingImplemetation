/*****************************************************************************/
/**
	* @file    ray.h
	* @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
	* @date    21/05/2021
	* @brief   A basic class for a ray
	*
	*
	* @bug	    No known bugs.
	*/
	/*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include <jdVector3.h> 
#include "point3D.h"

class Ray
{
public:
		/**
   * @brief defaul constructor
   */
		Ray() {};
		
  /**
   * @brief constructor with origini and direction of ray
			* @param origin is the postion of the origin of the ray
			* @param direction is the direction of the ray
   */
		Ray(const Point3D origin, const JDVector3 direction) : 
				m_origin(origin), m_direction(direction) {};
		
		/**
			* @brief copy constructor
			* @param ray is the other ray to copy
			*/
		Ray(const Ray& ray) {
				m_origin = ray.m_origin;
				m_direction = ray.m_direction;
		};

		/**
			* @brief defaul destructor
			*/
		~Ray() {};

		/**
			* @brief assignment operator 
			* @param ray is the other ray to copy
			*/
		Ray&
		operator=(const Ray& ray) {
				m_origin = ray.m_origin;
				m_direction = ray.m_direction;
		};

		/**
			* @brief ray's origin
			*/
		Point3D m_origin;

		/**
			* @brief ray's direction
			*/
		JDVector3 m_direction;

private:

};