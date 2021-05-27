#pragma once
#include "Prerequisites.h"
#include <jdVector3.h> 
#include "point3D.h"

class Ray
{
public:
		Ray();
		
		Ray(const Point3D origin, const JDVector3 direction) : 
				m_origin(origin), m_direction(direction) {};
		
		Ray(const Ray& ray) {
				m_origin = ray.m_origin;
				m_direction = ray.m_direction;
		};

		~Ray();

		Ray&
		operator=(const Ray& ray) {
				m_origin = ray.m_origin;
				m_direction = ray.m_direction;
		};

		Point3D m_origin;
		JDVector3 m_direction;

private:

};

Ray::Ray()
{
}

Ray::~Ray()
{
}