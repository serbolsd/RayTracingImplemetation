#include "point3D.h"

Point3D 
Point3D::operator-() const {
  return Point3D(-x, -y, -z);
}


Point3D
Point3D::operator+() const {
  return *this;
}

Point3D
Point3D::operator+(const Point3D& Vec) const {
  return Point3D(x + Vec.x, y + Vec.y, z + Vec.z);
}

Point3D
Point3D::operator-(const Point3D& Vec) const {
  return Point3D(x - Vec.x, y - Vec.y, z - Vec.z);
}

Point3D&
Point3D::operator+=(const Point3D& Vec) {
  x += Vec.x; y += Vec.y; z += Vec.z;
  return *this;
}

Point3D&
Point3D::operator-=(const Point3D& Vec) {
  x -= Vec.x; y -= Vec.y; z -= Vec.z;
  return *this;
}

Point3D
Point3D::operator*(const int scale) const {
  return Point3D(x * scale, y * scale, z * scale);
}

Point3D
Point3D::operator*(const Point3D& Vec) const {
  return Point3D(x * Vec.x, y * Vec.y, z * Vec.z);
}

Point3D&
Point3D::operator*=(const int scale) {
  x *= scale; y *= scale; z *= scale;
  return *this;
}

Point3D&
Point3D::operator*=(const Point3D& Vec) {
  x *= Vec.x; y *= Vec.y; z *= Vec.z;
  return *this;
}

Point3D
Point3D::operator/(const int scale) const {
  return Point3D(x / scale, y / scale, z / scale);
}

Point3D
Point3D::operator/(const Point3D& vec) const {
  return Point3D(x / vec.x, y / vec.y, z / vec.z);
}

Point3D&
Point3D::operator/=(const int scale) {
  x /= scale; y /= scale; z /= scale;
  return *this;
}

Point3D&
Point3D::operator/=(const Point3D& vec) {
  x /= vec.x; y /= vec.y; z /= vec.z;
  return *this;
}

bool
Point3D::operator==(const Point3D& Vec) const {
  return (x == Vec.x) && (y == Vec.y) && (z == Vec.z);
}

bool
Point3D::operator!=(const Point3D& Vec) const {
  return (x != Vec.x) || (y != Vec.y) || (z != Vec.z);
}

bool
Point3D::operator<(const Point3D& Vec) const {
  if (x < Vec.x || y < Vec.y || z < Vec.z) {
    return true;
  }
  return false;
}

bool
Point3D::operator>(const Point3D& Vec) const {
  if (x > Vec.x || y > Vec.y || z > Vec.z) {
    return true;
  }
  return false;
}

int
Point3D::operator[](int index) const {
  JD_ASSERT(index < 3);
  return (&x)[index];
}

int&
Point3D::operator[](int index) {
  JD_ASSERT(index < 3);
  return (&x)[index];
}

Point3D&
Point3D::operator=(const Point3D& Vec) {
  x = Vec.x; y = Vec.y; z = Vec.z;
  return *this;
}

Point3D
operator*(const int a, const Point3D vec) {
  return Point3D(a * vec.x, a * vec.y, a * vec.z);
}

Point3D 
operator*(const JDVector3 a, const Point3D vec) {
  return Point3D();
}

std::ostream&
operator<<(std::ostream& os, const Point3D& vec) {
  os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
  return os;
}

int
Point3D::magnitude() const {
  return Math::sqrt(x * x + y * y + z * z);
}

int
Point3D::squareMagnitude() const {
  int result = x * x + y * y + z * z;
  if (result < 0)
  {
    result = 0.000001f;
  }
  return result;
}

int
Point3D::distance(const Point3D& vec) const {
  return Math::sqrt((x - vec.x) * (x - vec.x) + (y - vec.y) *
    (y - vec.y) + (z - vec.z) * (z - vec.z));
}

Point3D&
Point3D::normalize() {
  *this = getnormalize();
  return *this;
}

Point3D
Point3D::getnormalize() {
  int sMag = squareMagnitude();
  JD_ASSERT(0.0f <= sMag);
  Point3D result = *this;

  int invLength = Math::invSqrt(sMag);
  result.x *= invLength;
  result.y *= invLength;
  result.z *= invLength;
  return result;
}

int
Point3D::dot(const Point3D& vec) const {
  return (x * vec.x + y * vec.y + z * vec.z);
}

Point3D
Point3D::cross(const Point3D& vec) const {
  return Point3D(y * vec.z - z * vec.y, -(x * vec.z - z * vec.x), x * vec.y - y * vec.x);
}
