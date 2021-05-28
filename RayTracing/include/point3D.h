/*****************************************************************************/
/**
 * @file    point3D.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   A basic class for a point 3d
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "Prerequisites.h"
#include "jdVector3.h"

class Point3D
{
 public:
  /**
   * @brief defaul constructor
   */
  Point3D() = default;

  /**
   * @brief constructor with int params with default 0.
   * @param _x for x cordinate
   * @param _y for y cordinate
   * @param _z for z cordinate
   */
  Point3D(const int _x, const int _y = 0.0f, const int _z = 0.0f)
    : x(_x), y(_y), z(_z) {};

  /**
   * @brief constructor with a array int 4 params.
   * @param _xyz for x, y ,z cordinate
   */
  Point3D(const int _xyz[3]) : x(_xyz[0]), y(_xyz[1]), z(_xyz[2]) {};

/*****************************************************************************/
/**
 * Operators
 */
/*****************************************************************************/
 public:
  /**
   * @brief Negative operator
   * @return A new point negative of this vector
   */
  Point3D
  operator-() const;
  
  /**
   * @brief Positive operator
   * @return A new point positive of this vector
   */
  Point3D
  operator+() const;
  
  /**
   * @brief add two vectors
   * @param vec is the othe vector to add
   * @return the addition of this vector with other
   */
  Point3D     
  operator+(const Point3D& Vec) const;
  
  /**
   * @brief substraction of two vectors
   * @param vec is the othe vector to subtrac
   * @return the substraction of this vector with other
   */
  Point3D
  operator-(const Point3D& Vec) const;
  
  /**
   * @brief modificque this vector adding other vector
   * @param vec is the othe vector to add
   * @return the addition of this vector with other in this vector
   */
  Point3D&
  operator+=(const Point3D& Vec); 
  
  /**
   * @brief modificque this vector subtacting other vector
   * @param vec is the othe vector to subtrac
   * @return the substraction of this vector with other in this vector
   */
  Point3D&
  operator-=(const Point3D& Vec);
  
  /**
   * @brief Get the result of scaling on this vector.
   * @param scale What to multiply the vector by.
   * @return A new scaled vector.
   */
  Point3D
  operator*(const int scale) const;
  
  /**
   * @brief Get the result of multiply this vector with other vector.
   * @param vec What to multiply the vector by.
   * @return the result of the multiply this vector with other.
   */
  Point3D
  operator*(const Point3D& Vec) const; 
  
  /**
   * @brief Scale this vector
   * @param Scale What to multiply this vector by.
   * @return the result of the multiply in this vector.
   */
  Point3D&
  operator*=(const int scale);
  
  /**
   * @brief multiply this vector with other vector.
   * @param vec What to multiply this vector by.
   * @return the result of the multiply this vector with other in this vector.
   */
  Point3D&
  operator*=(const Point3D& Vec);      
  
  /**
   * @brief divition of vector with a scale.
   * @param scale What to divide the vector by.
   * @return the result of the dividetion.
   */
  Point3D
  operator/(const int scale) const;		
  
  /**
   * @brief divition of vector with an other vector.
   * @param vec is a vector What to divide the vector by.
   * @return a vector with the result of the dividetion.
   */
  Point3D
  operator/(const Point3D& vec) const;
  
  /**
   * @brief divition of this vector with a scale.
   * @param scale What to divide this vector by.
   * @return the result of the dividetion in this vector.
   */
  Point3D&
  operator/=(const int scale);
  
  /**
   * @brief divition of this vector with an other vector.
   * @param vec is vector What to divide this vector by.
   * @return the result of the dividetion in this vector.
   */
  Point3D&
  operator/=(const Point3D& vec);
  
  /**
   * @brief compare a vector with an other vector.
   * @param vec is vector What to compare vector by.
   * @return true if all components are equal
   */
  bool
  operator==(const Point3D& Vec) const;
  
  /**
   * @brief compare a vector with an other vector.
   * @param vec is vector What to compare vector by.
   * @return true if one component is diferent
   */
  bool
  operator!=(const Point3D& Vec) const;
  
  /**
   * @brief compare a vector with an other vector.
   * @param vec is vector What to compare vector by.
   * @return true if one component is less
   */
  bool
  operator<(const Point3D& Vec) const;	
  
  /**
   * @brief compare a vector with an other vector.
   * @param vec is vector What to compare vector by.
   * @return true if one component is major
   */
  bool
  operator>(const Point3D& Vec) const;
  
  /**
   * @brief get the component in a index
   * @param index is index of component in the vector.
   * @return a const of the component in the index
   */
  int
  operator[](int index) const;	
  
  /**
   * @brief get the component in a index
   * @param index is index of component in the vector.
   * @return a reference of the component in the index
   */
  int&
  operator[](int index);
  
  /**
   * @brief queal this vector to other vector.
   * @param vec is vector What to equal vector by.
   * @return this vector equaled
   */
  Point3D&
  operator=(const Point3D& Vec);	 	 


/*****************************************************************************/
/**
 * Friends
 */
/*****************************************************************************/

  /**
   * @brief multiplicate the components of a vector for a constant
   * @param scale multply the components
   * @return the result of multiplication.
   */
  friend Point3D
  operator*(const int a, const Point3D vec);


/*****************************************************************************/
/**
 * Functions
 */
/*****************************************************************************/
 public:

  /**
   * @brief function to get the magnitude of vector
   * @return a flot with the magnitud of vector
   */
  int
  magnitude() const;
  
  /**
   * @brief function to get the square of the magnitude of vector
   * @return a flot with the square of the magnitud of vector
   */
  int
  squareMagnitude() const;
  
  /**
   * @brief function to get the square of the magnitude of vector
   * @param vec is the vectir to
   * @return a flot with the square of the magnitud of vector
   */
  int
  distance(const Point3D& vec) const;
  
  /**
   * @brief function to normalize this vector
   * @return this vector normalized
   */
  Point3D&
  normalize();	
  
  /**
   * @brief function to get the normalize of this vector
   * @return a copy of this vector normalized
   */
  Point3D
  getnormalize();			
  
  /**
   * @brief dot product
   * @param vec if the vector with do dot product
   * @return the result of dot product
   */
  int
  dot(const Point3D& vec) const;	
  
  /**
   * @brief dot product
   * @param vec if the vector with do cross product
   * @return the result of cross product
   */
  Point3D
  cross(const Point3D& vec) const;	

/*****************************************************************************/
/**
 * Members
 */
/*****************************************************************************/
 public:
  /**
   * @brief Vector's x component.
   */
  int x;
  /**
   * @brief Vector's y component.
   */
  int y;
  /**
   * @brief Vector's z component.
   */
  int z;

};

__forceinline double 
pointVecDot(const Point3D& point, const JDVector3& vec) {
  return ((point.x * vec.x) + (point.y * vec.y) + (point.z * vec.z));
};