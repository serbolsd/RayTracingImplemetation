/*****************************************************************************/
/**
 * @file    Prerequisites.h
 * @author  Sergio Diaz (idv17c.sdiaz@uartesdigitales.edu.mx)
 * @date    21/05/2021
 * @brief   to include utilities 
 *
 *
 * @bug	    No known bugs.
 */
/*****************************************************************************/
#pragma once

#include <jdPrerequisitesUtil.h>
using namespace jdEngineSDK;

FORCEINLINE float 
randomFloat() {
  return  ((float)rand() / (float)RAND_MAX);
}

FORCEINLINE int 
randomInt() {
  return rand();
}

FORCEINLINE void
setRandSeed(const int seed) {
  srand(seed);
}

#define PI 3.1415