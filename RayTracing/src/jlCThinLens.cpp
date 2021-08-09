#include "jlCThinLens.h"
#include "ViewPlane.h"
#include "World.h"
void 
CThinLens::setSampler(Sampler* sp) {
  if (nullptr != m_pSampler) {
    delete m_pSampler;
    m_pSampler = nullptr;
  }
  m_pSampler = sp;
  //m_pSampler->mapSamplerToUnitDisk();
}

JDVector3 
CThinLens::rayDirection(const JDPoint& pp, const JDPoint& lp) {
  JDPoint p;
  p.x = pp.x * m_focalDistance / m_viewDistance;
  p.y = pp.y * m_focalDistance / m_viewDistance;

  JDVector3 dir = (p.x - lp.x) * m_u + (p.y - lp.y) * m_v - m_focalDistance * m_w;
  dir.normalize();
  return dir;
}

void 
CThinLens::renderScene(World* world) {
  JDVector3 pixel_color;
  JDVector3 pColor = { 0,0,0 };
  ViewPlane vp(world->m_vp);
  Ray ray;
  uint32 depth;
 
  JDPoint sp; //sample point
  JDPoint pp; //sample point on a pixel
  JDPoint dp; //sample point on unit disk
  JDPoint lp; //sample point on lens
  
  vp.m_pixelSize /= m_zoom;
  auto eye = pointToVector3D(m_eye);

  for (int x = 0; x < vp.m_width; x++) {
    for (int y = 0; y < vp.m_height; y++) {
      pixel_color = { 0, 0, 0};
      pColor = { 0,0,0 };
      for (int n = 0; n < vp.m_numSamplers; ++n) {
        auto su = world->m_vp.m_pSampler->sampleUnitSquare();
        sp.x = su.x;
        sp.y = su.y;
        pp.x = world->m_vp.m_pixelSize * (x - 0.5 * world->m_vp.m_width + su.x);
        pp.y = world->m_vp.m_pixelSize * (y - 0.5 * world->m_vp.m_height + su.y);

        auto sd = m_pSampler->sampleUnitDisk();
        dp.x = sd.x;
        dp.y = sd.y;
        lp = dp * m_lendsRadius;

        ray.m_origin = eye + lp.x * m_u + lp.y * m_v;
        //ray.m_origin = eye;
        ray.m_direction = rayDirection(pp, lp);

        pixel_color = world->m_pTracer->traceRay(ray);
        pColor += pixel_color;
      }
      pColor /= world->m_vp.m_numSamplers;
      //pColor *= m_exposureTime;
      pixel_color = pColor;

      world->displayPixel(x, y, pixel_color);
    }
  }

}
