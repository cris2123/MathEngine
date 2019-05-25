#pragma once
#include <vector>
#include "ivVector.h"

namespace IvVectorUtils {

bool isPerpendicular(IvVector3 &v1, IvVector3 &v2);
IvVector3 vectorProjectionX(IvVector3 &v1, IvVector3 &v2);
IvVector3 vectorProjectionY(IvVector3 &v1, IvVector3 &v2);
float scalarTripleProduct(IvVector3 &v1, IvVector3 &v2, IvVector3 &v3);
IvVector3 vectorTripleProduct(IvVector3 &v1, IvVector3 &v2, IvVector3 &v3);
std::vector<IvVector3 *> grandSchmidtR3(IvVector3 &v0, IvVector3 &v1, IvVector3 &v2);

}



