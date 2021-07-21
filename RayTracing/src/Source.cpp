#include <SFML/Graphics.hpp>
#include "World.h"
#include "jlQuaternion.h"
#include "jdDegree.h"
#include "jdVector4.h"

int main()
{
  //jlQuaternion temp(Degree(0), Degree(180),Degree(0));
  //JDVector3 euler = temp.getEuler();


  World w;
  w.build(400, 400);
  w.renderScene();
  return 0;
}