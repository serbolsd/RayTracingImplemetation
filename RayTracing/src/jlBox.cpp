#include "jlBox.h"



const double Box::kEpsilon = 0.00001;

bool 
Box::hit(const Ray& ray, double& t, ShadeRec& s) {
  //same as Listing 19.1 down to the statement float t0, t1;
  double ox = ray.m_origin.x; 
  double oy = ray.m_origin.y; 
  double oz = ray.m_origin.z;
  
  double dx = ray.m_direction.x; 
  double dy = ray.m_direction.y; 
  double dz = ray.m_direction.z;
  
  double tx_min, ty_min, tz_min;
  double tx_max, ty_max, tz_max;

  double a = 1.0 / dx;
  if (a >= 0) {
    tx_min = (m_vmin.x - ox) * a;
    tx_max = (m_vmax.x - ox) * a;
  }
  else {
    tx_min = (m_vmax.x - ox) * a;
    tx_max = (m_vmin.x - ox) * a;
  }
  double b = 1.0 / dy;
  if (b >= 0) {
    ty_min = (m_vmin.y - oy) * b;
    ty_max = (m_vmax.y - oy) * b;
  }
  else {
    ty_min = (m_vmax.y - oy) * b;
    ty_max = (m_vmin.y - oy) * b;
  }
  double c = 1.0 / dz;
  if (c >= 0) {
    tz_min = (m_vmin.z - oz) * c;
    tz_max = (m_vmax.z - oz) * c;
  }
  else {
    tz_min = (m_vmax.z - oz) * c;
    tz_max = (m_vmin.z - oz) * c;
  }

  int face_in, face_out;
  double t0, t1;
  // find largest entering t value
  if (tx_min > ty_min) {
    t0 = tx_min;
    face_in = (a >= 0.0) ? 0 : 3;
  }
  else {
    t0 = ty_min;
    face_in = (b >= 0.0) ? 1 : 4;
  }
  if (tz_min > t0) {
    t0 = tz_min;
    face_in = (c >= 0.0) ? 2 : 5;
  }
  // find smallest exiting t value
  if (tx_max < ty_max) {
    t1 = tx_max;
    face_out = (a >= 0.0) ? 3 : 0;
  }
  else {
    t1 = ty_max;
    face_out = (b >= 0.0) ? 4 : 1;
  }
  if (tz_max < t1) {
    t1 = tz_max;
    face_out = (c >= 0.0) ? 5 : 2;
  }

  if (t0 < t1 && t1 > kEpsilon) { // condition for a hit
    if (t0 > kEpsilon) {
      t = t0; // ray hits outside surface
      s.m_normal = getNormalFace(face_in);
    }
    else {
      t = t1; // ray hits inside surface
      s.m_normal = getNormalFace(face_out);
    }
    auto localHitP = ray.m_origin + t * ray.m_direction;
    s.m_localHitPoint.x = localHitP.x;
    s.m_localHitPoint.y = localHitP.y;
    s.m_localHitPoint.z = localHitP.z;
    return (true);
  }
  else
    return (false);
  //float tmin = (m_vmin.x - ray.m_origin.x) / ray.m_direction.x;
  //float tmax = (m_vmax.x - ray.m_origin.x) / ray.m_direction.x;
  //
  //if (tmin > tmax) 
  //  std::swap(tmin, tmax);
  //
  //float tymin = (m_vmin.y - ray.m_origin.y) / ray.m_direction.y;
  //float tymax = (m_vmax.y - ray.m_origin.y) / ray.m_direction.y;
  //
  //if (tymin > tymax) 
  //  std::swap(tymin, tymax);
  //
  //if ((tmin > tymax) || (tymin > tmax))
  //  return false;
  //
  //if (tymin > tmin)
  //  tmin = tymin;
  //
  //if (tymax < tmax)
  //  tmax = tymax;
  //
  //float tzmin = (m_vmin.z - ray.m_origin.z) / ray.m_direction.z;
  //float tzmax = (m_vmax.z - ray.m_origin.z) / ray.m_direction.z;
  //
  //if (tzmin > tzmax)
  //  std::swap(tzmin, tzmax);
  //
  //if ((tmin > tzmax) || (tzmin > tmax))
  //  return false;
  //
  //if (tzmin > tmin)
  //  tmin = tzmin;
  //
  //if (tzmax < tmax)
  //  tmax = tzmax;
  //
  //return true;
}

JDVector3 
Box::getNormalFace(int faceHit) {
  switch (faceHit) {
   case 0: 
    return (JDVector3(-1, 0, 0).normalize()); // -x face
   case 1: 
    return (JDVector3(0, -1, 0).normalize()); // -y face
   case 2: 
    return (JDVector3(0, 0, -1).normalize()); // -z face
   case 3: 
    return (JDVector3(1, 0, 0).normalize()); // +x face
   case 4: 
    return (JDVector3(0, 1, 0).normalize()); // +y face
   case 5: 
    return (JDVector3(0, 0, 1).normalize()); // +z face
  }
  return JDVector3();
}
