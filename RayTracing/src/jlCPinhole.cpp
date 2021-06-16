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
  sf::Color pixel_color;
  ViewPlane vp(world->m_vp);
  JDVector3 pColor = { 0,0,0 };
  Ray ray;
  uint32 depth;
  JDPoint sp;
  JDPoint pp;

  vp.m_pixelSize /= m_zoom;
  ray.m_origin = m_eye;
  for (int x = 0; x < vp.m_width; x++) {
    for (int y = 0; y < vp.m_height; y++) {
      pixel_color = sf::Color::Black;
      for (uint32 i = 0; i < vp.m_numSamplers; i++) {
        auto su = vp.m_pSampler->sampleUnitSquare();
        pp.x = vp.m_pixelSize * (x - 0.5f * vp.m_width + su.x);
        pp.y = vp.m_pixelSize * (y - 0.5f * vp.m_height + su.y);

        ray.m_direction = rayDirection(pp);
        pixel_color = world->m_pTracer->traceRay(ray);
        pColor.x += pixel_color.r;
        pColor.y += pixel_color.g;
        pColor.z += pixel_color.b;
      }
      pColor /= vp.m_numSamplers;
      pColor *= m_expesureTime;
      pixel_color.r = pColor.x;
      pixel_color.g = pColor.y;
      pixel_color.b = pColor.z;
      world->displayPixel(pp.x, pp.y, pixel_color);
    }
  }
}
