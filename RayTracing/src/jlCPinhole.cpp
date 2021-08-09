#include "jlCPinhole.h"
#include "ViewPlane.h"
#include "ray.h"
#include "World.h"
#include <SFML/Graphics/Color.hpp>
JDVector3 
CPinhole::rayDirection(const JDPoint& p) {
  JDVector3 dir = p.x * m_u + p.y * m_v - m_viewDistance * m_w;
  dir.normalize();
  return dir;
}

void 
CPinhole::renderScene(World* world) {
  JDVector3 pixel_color;
  ViewPlane vp(world->m_vp);
  JDVector3 pColor = { 0,0,0 };
  Ray ray;
  uint32 depth;
  JDPoint sp;
  JDPoint pp;

  vp.m_pixelSize /= m_zoom;
  ray.m_origin = pointToVector3D(m_eye);
  //ray.m_origin = {0, 50, 100};
  for (int x = 0; x < vp.m_width; x++) {
    for (int y = 0; y < vp.m_height; y++) {
      pixel_color = { 0, 0, 0};
      //for (uint32 i = 0; i < vp.m_numSamplers; i++) {
      //  auto su = vp.m_pSampler->sampleUnitSquare();
      //  pp.x = vp.m_pixelSize * (x - 0.5f * vp.m_width + su.x);
      //  pp.y = vp.m_pixelSize * (y - 0.5f * vp.m_height + su.y);
      //
      //  ray.m_direction = rayDirection(pp);
      //  pixel_color = world->m_pTracer->traceRay(ray);
      //  pColor.x += pixel_color.r;
      //  pColor.y += pixel_color.g;
      //  pColor.z += pixel_color.b;
      //}
       
      //No Sampler
      //auto xx = vp.m_pixelSize * (x - 0.5 * (vp.m_width - 1.0));
      //auto yy = vp.m_pixelSize * (y - 0.5 * (vp.m_height - 1.0));
      //pp = { (int)xx,(int)yy };
      //ray.m_direction = rayDirection(pp);
      //pixel_color = world->m_pTracer->traceRay(ray);
      
      //Class Sampler
      pixel_color = classSamplerRender(x, y, world, ray);
      //pColor.x += pixel_color.r;
      //pColor.y += pixel_color.g;
      //pColor.z += pixel_color.b;
      //
      ////pColor /= vp.m_numSamplers;
      //pColor *= 1;
      //pixel_color.r = pColor.x;
      //pixel_color.g = pColor.y;
      //pixel_color.b = pColor.z;
      //world->displayPixel(x, y, JDVector3::Yellow);
      world->displayPixel(x, y, pixel_color);
    }
  }
}

JDVector3 
CPinhole::classSamplerRender(int x, int y, World* world, Ray& ray) {
  {
    static JDVector3 pixel_color;
    static JDPoint pp; //sampler point in pixel
    static JDVector3 pColor = { 0,0,0 };
    pColor = { 0,0,0 };
    for (int i = 0; i < world->m_vp.m_numSamplers; i++) {
      auto su = world->m_vp.m_pSampler->sampleUnitSquare();
      pp.x = world->m_vp.m_pixelSize * (x - 0.5 * world->m_vp.m_width + su.x);
      pp.y = world->m_vp.m_pixelSize * (y - 0.5 * world->m_vp.m_height + su.y);

      ray.m_direction = rayDirection(pp);
      pixel_color = world->m_pTracer->traceRay(ray, 10);
      pColor += pixel_color;
    }
    pColor /= world->m_vp.m_numSamplers;
    pixel_color = pColor;
    return pixel_color;
  }
}
