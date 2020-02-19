#pragma once
#include "Globals.h"
#include <CGAL/Combinatorial_map.h>
#include "VolumetricMesh.h"


typedef CGAL::Combinatorial_map<3> CMap_3;

CMap_3 MeshComplexToCombinatorialMap(C3t3);
