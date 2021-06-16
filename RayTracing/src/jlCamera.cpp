#include "jlCamera.h"
#include "World.h"

void 
Camera::computeUVW() {
  //Probale cambio a look at - eye
  m_w.x = m_eye.x - m_lookAt.x;
  m_w.y = m_eye.y - m_lookAt.y;
  m_w.z = m_eye.z - m_lookAt.z;
  m_w.normalize();
  //proable intercambio al hacer el cross
  m_u = m_up.cross(m_w);
  m_u.normalize();
  //proable intercambio al hacer el cross
  m_v = m_w.cross(m_u);
  m_v.normalize();
}
