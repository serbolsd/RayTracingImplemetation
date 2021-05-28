#include "World.h"
#include "tSingleSphere.h"

World::World() {
}

World::~World() {
		if (nullptr != m_window)	{
				delete m_window;
		}
  if (nullptr != m_pTracer) {
    delete m_pTracer;
  }
}

void World::build(const int width, const int height) {
  m_vp.m_height = height;
  m_vp.m_width = width;
  m_vp.m_pixelSize = 1.0f;
  m_vp.m_gamma = 1.0f;
  m_vp.m_invGamma = 1.0f / m_vp.m_gamma;

  m_pTracer = new TSingleSphere();
  m_pTracer->m_pWorld = this;

  m_sphere.m_position = { 0,0,0 };
  m_sphere.m_radius = 85.0f;
  m_sphere.color = sf::Color::Cyan;

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

  updateRender();
}

void World::updateRender() {
  sf::Color pixel_color;
  Ray ray;
  double zw = 100.0; // hard wired in
  double xx, yy;
  ray.m_direction = JDVector3(0, 0, -1);

  for (int x = 0; x < m_vp.m_width; x++)
  {
    for (int y = 0; y < m_vp.m_height; y++)
    {
      xx = m_vp.m_pixelSize * (x - 0.5 * (m_vp.m_width - 1.0));
      yy = m_vp.m_pixelSize * (y - 0.5 * (m_vp.m_height - 1.0));
      m_image.setPixel(x, y, sf::Color::Cyan);
      ray.m_origin = { (int)xx, (int)yy, (int)zw };
      pixel_color = m_pTracer->traceRay(ray);
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
