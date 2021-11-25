//
// pch.cpp
//

#include "pch.h"

int randInt(int lo, int hi) { return rand() % (hi - lo) + lo; }
int randDouble(double lo, double hi) { return rand() * (hi - lo) + lo; }
