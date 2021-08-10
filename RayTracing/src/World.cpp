#include "World.h"
//tracers
#include "tSingleSphere.h"
#include "tMultipleObject.h"
#include "jlTRayCast.h"
//Geometry
#include "Plane.h"
#include "jlBox.h"
#include "jlCylinder.h"
//Samplers
#include "jlSJittered.h"
#include "jRegularSampler.h"
//Cameras
#include "jlCPinhole.h"
#include "jlCThinLens.h"
//Lights
#include "jlAmbientLight.h"
#include "jlPointLight.h"
//Materials
#include "jlMaterial.h"
#include "jlMMatte.h"
#include "jlMPhong.h"
//Util
#include <jdPoint.h>

World::World() {
}

World::~World() {
		if (nullptr != m_window)	{
				delete m_window;
    m_window = nullptr;
		}
  if (nullptr != m_pTracer) {
    delete m_pTracer;
    m_pTracer = nullptr;
  }
  if (nullptr != m_camera) {
    delete m_camera;
    m_camera = nullptr;
  }
}

void World::build(const int width, const int height) {
  m_vp.m_height = height;
  m_vp.m_width = width;
  m_vp.m_pixelSize = 1;
  m_vp.m_gamma = 1.0f;
  m_vp.m_invGamma = 1.0f / m_vp.m_gamma;
  m_vp.m_numSamplers = 200;
  //m_vp.setSampler(new SRegular(8));
  auto sampler = new SJittered(16);
  //auto sampler = new SRegular(0);
  m_vp.setSampler(sampler);
  m_vp.m_pSampler->m_numSets = width * height;
  m_vp.m_pSampler->generateSamples();
  m_vp.m_pSampler->setupShuffledIndices();
  m_vp.m_pSampler->mapSamplerToUnitDisk();

  //m_pTracer = new TSingleSphere();
  //m_pTracer = new TMultipleObjects();
  m_pTracer = new RayCast();
  m_pTracer->m_pWorld = this;

  //m_sphere.m_position = { 50,0,0 };
  //m_sphere.m_radius = 85.0f;
  //m_sphere.color = JDVector3::Cyan;
  
  //Sphere* sp = new Sphere();
  //sp->m_position = { 80,30,0 };
  //sp->m_radius = 80.0f;
  //sp->color = JDVector3::Cyan;
  //addObject(sp);
  
  //sp = new Sphere();
  //sp->m_position = { -80,30,0 };
  //sp->m_radius = 80.0f;
  //sp->color = JDVector3(255, 255, 0, 255);
  //addObject(sp);
  
  //Point3D min(-60, 0, -60);
  //Point3D max(60, 120, 60);
  //Point3D pos(-200, 0, -50);
  //Box* bs = new Box(min, max, pos);
  //bs->color = { 255, 0, 0, 255 };
  //addObject(bs);
  //min={-60, 0, -60};
  //max={60, 250, 60};
  //pos.x = 0;
  //pos.z = 0;
  //bs = new Box(min, max, pos);
  //bs->color = { 0, 0, 255, 255 };
  //addObject(bs);
  //
  //pos.x = 200;
  //pos.z = 200;
  ////bs = new Box(min, max, pos);
  ////bs->color = { 100, 0, 255, 255 };
  ////addObject(bs);
  //
  //Cylinder* cs = new Cylinder(60.f, 200, pos);
  //cs->color = { 100, 0, 255, 255 };
  //addObject(cs);
  //
  //Plane* plane = new Plane(Point3D(0, -10, 0), JDVector3(0, 1, 0).getnormalize());
  //plane->color = JDVector3(0, 100, 0);
  //addObject(plane);

  auto pPCam = new CPinhole;
  pPCam->m_viewDistance = 850;
  pPCam->m_zoom = 1;
  m_camera = pPCam;

  //auto pTLCam = new CThinLens;
  //pTLCam->setSampler(sampler);
  //pTLCam->m_viewDistance = 400;
  //pTLCam->m_focalDistance = 40;
  //pTLCam->m_lendsRadius = 0;
  //m_camera = pTLCam;

  m_camera->m_eye = {0, 0, 500 };
  m_camera->m_lookAt = {0,0,0};
  m_camera->m_up = {0,1,0};
  m_camera->m_exposureTime = 1;
  m_camera->computeUVW();

  AmbientL* ambient = new AmbientL();
  ambient->m_ls = 1;
  m_pAmbientlight = ambient;
  m_lights.push_back(ambient);

  PointLight* pl = new PointLight;
  pl->m_ls = 3;
  pl->m_location = { 100, 50, 150 };
  pl->m_color = { 1, 1, 1 };
  m_lights.push_back(pl);

  Matte* matte = new Matte;
  matte->setKa(0.25);
  matte->setKd(0.65);
  matte->setCd(JDVector3(1,1,0));

  MPhong* phong = new MPhong();
  phong->setKa(0.25);
  phong->setKd(0.6);
  phong->setKS(0.2);
  phong->setSExp(100);
  phong->setCd(JDVector3(1, 1, 0));

  Sphere* sp = new Sphere();
  sp->m_position = { 10,-50,0 };
  sp->m_radius = 80;
  sp->color = { 100,100,255 };
  sp->color.normalize();
  sp->m_pMaterial = phong;
  
  addObject(sp);

  //Point3D min(-60, 0, -60);
  //Point3D max(60, 120, 60);
  //Point3D pos(0, 0, 0);
  //Box* bs = new Box(min, max, pos);
  //bs->color = { 1, 0, 0 };
  //bs->m_pMaterial = matte;
  //addObject(bs);

  openWindow(width, height);
}

void World::renderScene() {

  // run the program as long as the window is open
  while (m_window->isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (m_window->pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        m_window->close();
    }

    sf::Color backGround(m_backgroundColor.x, m_backgroundColor.y, m_backgroundColor.z);
    m_camera->renderScenePerFrame(this);
    m_window->clear(backGround);
    m_window->draw(m_sprite);
    m_window->display();
  }

  for (int i = 0; i < m_objects.size(); i++)
  {
    if (m_objects[i] != nullptr)
    {
      delete m_objects[i];
      m_objects[i] = nullptr;
    }
  }
  m_objects.clear();
  for (int i = 0; i < m_lights.size(); i++)
  {
    if (m_lights[i] != nullptr)
    {
      delete m_lights[i];
      m_lights[i] = nullptr;
    }
  }
  m_lights.clear();
}

void World::openWindow(const int width, const int height)
{
		m_window = new sf::RenderWindow(sf::VideoMode(width, height), "My window");
  // Create a image filled with black color

  sf::Color backGround(m_backgroundColor.x, m_backgroundColor.y, m_backgroundColor.z);
  m_image.create(width, height, backGround);
  //for (size_t x = 200; x < 601; x++)
  //{
  //  for (size_t y = 150; y < 451; y++)
  //  {
  //    m_image.setPixel(x, y, JDVector3::Cyan);
  //  }
  //}
  
  m_texture.create(width, height);
  m_texture.update(m_image);

  m_sprite.setTexture(m_texture);
  m_sprite.setOrigin(0,height);
  m_sprite.setScale({1,-1});
  //updateRender();
}

void World::updateRender() {
  m_camera->renderScene(this);
  return;
  JDVector3 pixel_color;
  JDVector3 pColor = { 0,0,0 };
  Ray ray;
  double zw = 100.0; // hard wired in
  float dis = 100; // view-plane distance

  int n = (int)sqrt(m_vp.m_numSamplers);
  JDPoint sp; // sampler point 
  JDPoint pp; //sampler point in pixel

  Point3D eye = {0,50,200};
  ray.m_origin = pointToVector3D(eye);

  double xx, yy;
  ray.m_direction = JDVector3(0, 0, -1);

  for (int x = 0; x < m_vp.m_width; x++) {
    for (int y = 0; y < m_vp.m_height; y++) {
      pixel_color = { 0, 0, 0};
      pColor = { 0,0,0 };
      //With Sampler class
      //for (int i = 0; i < m_vp.m_numSamplers; i++)
      //{
      //  auto su = m_vp.m_pSampler->sampleUnitSquare();
      //  pp.x = m_vp.m_pixelSize * (x - 0.5 * m_vp.m_width + su.x);
      //  pp.y = m_vp.m_pixelSize * (y - 0.5 * m_vp.m_height + su.y);
      //  ray.m_origin = { (int)pp.x, (int)pp.y, (int)zw };
      //  pixel_color = m_pTracer->traceRay(ray);
      //  pColor.x += pixel_color.r;
      //  pColor.y += pixel_color.g;
      //  pColor.z += pixel_color.b;
      //}
      pixel_color = classSamplerRender(x, y, zw, ray);
       
      //Regular Sampling Cambiar a funciones
      //pixel_color = regularSamplerRender(x, y, zw, ray, n);
      
      //Ramdon Sampling 
      //pixel_color = RandomSamplingRender(x, y, zw, ray);
      
      ////Jiterin Sapler
      //pixel_color = JitteredSamplerRender(x, y, zw, ray, n);

      //No Sampler
      //pixel_color = noSamplerRender(x, y, zw, ray);

      ////With perspective
      //auto xdir = m_vp.m_pixelSize * (x - 0.5 * (m_vp.m_width - 1.0));
      //auto ydir = m_vp.m_pixelSize * (y - 0.5 * (m_vp.m_height - 1.0));
      //ray.m_direction = { (float)xdir,
      //                    (float)ydir,
      //                    (float)-dis };
      //ray.m_direction.normalize();
      //pixel_color = m_pTracer->traceRay(ray);
      displayPixel(x,y, pixel_color);
    }
  }
}

void World::displayPixel(const int row, const int column, const JDVector3& pixel_color) 
{
  auto color = pixel_color;

  color = clampToColor(color);
  //color = maxToGama(color);
  color *= 255;
  sf::Color sfColor(color.x, color.y, color.z);
  m_image.setPixel(row, column, sfColor);
  m_texture.update(m_image);
  m_sprite.setTexture(m_texture);
}

JDVector3 
World::noSamplerRender(int x, int y, const float& zw, Ray& ray) {
  static float xx, yy;
  xx = m_vp.m_pixelSize * (x - 0.5 * (m_vp.m_width - 1.0));
  yy = m_vp.m_pixelSize * (y - 0.5 * (m_vp.m_height - 1.0));
  //m_image.setPixel(x, y, JDVector3::Cyan);
  ray.m_origin.x = xx;
  ray.m_origin.y = yy;
  ray.m_origin.z = zw;
  return m_pTracer->traceRay(ray);
}

JDVector3 
World::regularSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers) {
  static JDVector3 pixel_color;
  static JDPoint pp; //sampler point in pixel
  static JDVector3 pColor = { 0,0,0 };
  pColor = { 0,0,0 };
  for (int p = 0; p < numSamplers; p++) {
    for (int q = 0; q < numSamplers; q++) {
      pp.x = m_vp.m_pixelSize * (x - 0.5 * m_vp.m_width + (q + 0.5) / numSamplers);
      pp.y = m_vp.m_pixelSize * (y - 0.5 * m_vp.m_height + (p + 0.5) / numSamplers);
      ray.m_origin.x = pp.x;
      ray.m_origin.y = pp.y;
      ray.m_origin.z = zw;

      pixel_color = m_pTracer->traceRay(ray);
      pColor += pixel_color;
    }
  }
  pColor /= numSamplers * numSamplers;
  pixel_color = pColor;
  return pixel_color;
}

JDVector3 
World::classSamplerRender(int x, int y, const float& zw, Ray& ray) {
  static JDVector3 pixel_color;
  static JDPoint pp; //sampler point in pixel
  static JDVector3 pColor = { 0,0,0 };
  pColor = { 0,0,0 };
  for (int i = 0; i < m_vp.m_numSamplers; i++) {
    auto su = m_vp.m_pSampler->sampleUnitSquare();
    pp.x = m_vp.m_pixelSize * (x - 0.5 * m_vp.m_width + su.x);
    pp.y = m_vp.m_pixelSize * (y - 0.5 * m_vp.m_height + su.y);
    ray.m_origin.x = pp.x;
    ray.m_origin.y = pp.y;
    ray.m_origin.z = zw;
    pixel_color = m_pTracer->traceRay(ray);
    pColor += pixel_color;
  }
  pColor /= m_vp.m_numSamplers;
  pixel_color = pColor;
  return pixel_color;
}

JDVector3
World::RandomSamplingRender(int x, int y, const float& zw, Ray& ray) {
  static JDVector3 pixel_color;
  static JDPoint pp; //sampler point in pixel
  static JDVector3 pColor = { 0,0,0 };
  pColor = { 0,0,0 };
  //Ramdon Sampling 
  for (int p = 0; p < m_vp.m_numSamplers; p++) {
    pp.x = m_vp.m_pixelSize * (x - 0.5 * m_vp.m_width + randomFloat());
    pp.y = m_vp.m_pixelSize * (y - 0.5 * m_vp.m_height + randomFloat());
    ray.m_origin.x = pp.x;
    ray.m_origin.y = pp.y;
    ray.m_origin.z = zw;
    pixel_color = m_pTracer->traceRay(ray);
    pColor += pixel_color;
  }
  pColor /= m_vp.m_numSamplers;
  pixel_color = pColor;
  return pixel_color;
}

JDVector3 World::JitteredSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers)
{
  static JDVector3 pixel_color;
  static JDPoint pp; //sampler point in pixel
  static JDVector3 pColor = { 0,0,0 };
  pColor = { 0,0,0 };
  for (int p = 0; p < numSamplers; p++) {
    for (int q = 0; q < numSamplers; q++) {
      pp.x = m_vp.m_pixelSize * (x - 0.5 * m_vp.m_width + (q + randomFloat()) / numSamplers);
      pp.y = m_vp.m_pixelSize * (y - 0.5 * m_vp.m_height + (p + randomFloat()) / numSamplers);
      ray.m_origin.x = pp.x;
      ray.m_origin.y = pp.y;
      ray.m_origin.z = zw;

      pixel_color = m_pTracer->traceRay(ray);
      pColor += pixel_color;
    }
  }
  pColor /= numSamplers * numSamplers;
  pixel_color = pColor;
  return pixel_color;
}

ShadeRec 
World::hitBareBonesObjects(const Ray& ray) {
  ShadeRec sr(this);
  double t = 0.0;
  double tmin = HUGE_VAL;
  int numObjects = m_objects.size();
  for (int i = 0; i < numObjects; i++) {
    if (m_objects[i]->hit(ray, t, sr) && (t < tmin)) {
      sr.m_hitAnObject = true;
      tmin = t;
      sr.m_color = m_objects[i]->color;
    }
  }
  return sr;
}

ShadeRec 
World::hitObjects(const Ray& ray) {
  ShadeRec sr(this);
  double t = 0.0;
  JDVector3 Normal;
  Point3D localHitPoint;

  double tmin = HUGE_VAL;
  int numObjects = m_objects.size();

  for (int i = 0; i < numObjects; ++i) {
    if (m_objects[i]->hit(ray, t, sr) && (t < tmin)) {
      sr.m_hitAnObject = true;
      tmin = t;
      sr.m_pMaterial = m_objects[i]->m_pMaterial;
      auto hitPoint = ray.m_origin + (t * ray.m_direction);
      sr.m_HitPoint = { (int)hitPoint.x, (int)hitPoint.y, (int)hitPoint.z };
      Normal = sr.m_normal;
      localHitPoint = sr.m_localHitPoint;
    }
  }
  if (sr.m_hitAnObject) {
    sr.m_depth = tmin;
    sr.m_normal = Normal;
    sr.m_localHitPoint = localHitPoint;
  }
  return sr;
}

JDVector3 World::maxToGama(const JDVector3& color)
{
  float maxValue = std::max(color.x, std::max(color.y, color.z));
  auto c = color;
  if (maxValue > 1)
  {
    c /= maxValue;
  }
  return c;
}

JDVector3 
World::clampToColor(const JDVector3& color) {
  auto c = color;
  if (color.x > 1 || color.y > 1 || color.z > 1)
  {
    c.x = 1;
    c.y = 1;
    c.z = 1;
  }
  return c;
}
