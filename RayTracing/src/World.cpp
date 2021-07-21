#include "World.h"
#include "tSingleSphere.h"
#include "tMultipleObject.h"
#include "Plane.h"
#include "jlSJittered.h"
#include "jRegularSampler.h"
#include "jlCPinhole.h"

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
  m_vp.m_pixelSize = 2.0f;
  m_vp.m_gamma = 1.0f;
  m_vp.m_invGamma = 1.0f / m_vp.m_gamma;
  m_vp.m_numSamplers = 200;
  //m_vp.setSampler(new SRegular(8));
  m_vp.setSampler(new SJittered(1));
  m_vp.m_pSampler->m_numSets = width * height;
  m_vp.m_pSampler->generateSamples();
  m_vp.m_pSampler->setupShuffledIndices();
  m_vp.m_pSampler->mapSamplerToUnitDisk();

  //m_pTracer = new TSingleSphere();
  m_pTracer = new TMultipleObjects();
  m_pTracer->m_pWorld = this;

  m_sphere.m_position = { 50,0,0 };
  m_sphere.m_radius = 85.0f;
  m_sphere.color = sf::Color::Cyan;
  
  Sphere* sp = new Sphere();
  sp->m_position = { 80,30,0 };
  sp->m_radius = 80.0f;
  sp->color = sf::Color::Cyan;
  addObject(sp);
  
  sp = new Sphere();
  sp->m_position = { -80,30,0 };
  sp->m_radius = 80.0f;
  sp->color = sf::Color(255, 255, 0, 255);
  addObject(sp);
  
  Plane* plane = new Plane(Point3D(0, -10, 0), JDVector3(0, 1, 0).getnormalize());
  plane->color = sf::Color(0, 100, 0);
  addObject(plane);

  auto pPCam = new CPinhole;
  pPCam->m_viewDistance = 400;
  pPCam->m_zoom = 1;
  m_camera = pPCam;
  m_camera->m_eye = {0, 50, 200 };
  m_camera->m_lookAt = {0,0,0};
  m_camera->m_up = {0,1,0};
  m_camera->computeUVW();
  
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
    m_window->clear(m_backgroundColor);
    m_window->draw(m_sprite);
    m_window->display();
  }

  for (int i = 0; i < m_objects.size(); i++)
  {
    delete m_objects[i];
  }
  m_objects.clear();
}

void World::openWindow(const int width, const int height)
{
		m_window = new sf::RenderWindow(sf::VideoMode(width, height), "My window");
  // Create a image filled with black color
  m_image.create(width, height, m_backgroundColor);
  //for (size_t x = 200; x < 601; x++)
  //{
  //  for (size_t y = 150; y < 451; y++)
  //  {
  //    m_image.setPixel(x, y, sf::Color::Cyan);
  //  }
  //}
  
  m_texture.create(width, height);
  m_texture.update(m_image);

  m_sprite.setTexture(m_texture);
  m_sprite.setOrigin(0,height);
  m_sprite.setScale({1,-1});
  updateRender();
}

void World::updateRender() {
  m_camera->renderScene(this);
  return;
  sf::Color pixel_color;
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
      pixel_color = sf::Color::Black;
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
      //pixel_color = classSamplerRender(x, y, zw, ray);
       
      //Regular Sampling Cambiar a funciones
      //pixel_color = regularSamplerRender(x, y, zw, ray, n);
      
      //Ramdon Sampling 
      //pixel_color = RandomSamplingRender(x, y, zw, ray);
      
      ////Jiterin Sapler
      //pixel_color = JitteredSamplerRender(x, y, zw, ray, n);

      //No Sampler
      pixel_color = noSamplerRender(x, y, zw, ray);

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

void World::displayPixel(const int row, const int column, const sf::Color& pixel_color) 
{
  m_image.setPixel(row, column, pixel_color);
  m_texture.update(m_image);
  m_sprite.setTexture(m_texture);
}

sf::Color 
World::noSamplerRender(int x, int y, const float& zw, Ray& ray) {
  static float xx, yy;
  xx = m_vp.m_pixelSize * (x - 0.5 * (m_vp.m_width - 1.0));
  yy = m_vp.m_pixelSize * (y - 0.5 * (m_vp.m_height - 1.0));
  //m_image.setPixel(x, y, sf::Color::Cyan);
  ray.m_origin.x = xx;
  ray.m_origin.y = yy;
  ray.m_origin.z = zw;
  return m_pTracer->traceRay(ray);
}

sf::Color 
World::regularSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers) {
  static sf::Color pixel_color;
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
      pColor.x += pixel_color.r;
      pColor.y += pixel_color.g;
      pColor.z += pixel_color.b;
    }
  }
  pColor /= numSamplers * numSamplers;
  pixel_color.r = pColor.x;
  pixel_color.g = pColor.y;
  pixel_color.b = pColor.z;
  return pixel_color;
}

sf::Color 
World::classSamplerRender(int x, int y, const float& zw, Ray& ray) {
  static sf::Color pixel_color;
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
    pColor.x += pixel_color.r;
    pColor.y += pixel_color.g;
    pColor.z += pixel_color.b;
  }
  pColor /= m_vp.m_numSamplers;
  pixel_color.r = pColor.x;
  pixel_color.g = pColor.y;
  pixel_color.b = pColor.z;
  return pixel_color;
}

sf::Color
World::RandomSamplingRender(int x, int y, const float& zw, Ray& ray) {
  static sf::Color pixel_color;
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
    pColor.x += pixel_color.r;
    pColor.y += pixel_color.g;
    pColor.z += pixel_color.b;
  }
  pColor /= m_vp.m_numSamplers;
  pixel_color.r = pColor.x;
  pixel_color.g = pColor.y;
  pixel_color.b = pColor.z;
  return pixel_color;
}

sf::Color World::JitteredSamplerRender(int x, int y, const float& zw, Ray& ray, int numSamplers)
{
  static sf::Color pixel_color;
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
      pColor.x += pixel_color.r;
      pColor.y += pixel_color.g;
      pColor.z += pixel_color.b;
    }
  }
  pColor /= numSamplers * numSamplers;
  pixel_color.r = pColor.x;
  pixel_color.g = pColor.y;
  pixel_color.b = pColor.z;
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