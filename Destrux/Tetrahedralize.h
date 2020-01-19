#pragma once
#include "VolumetricMesh.h"
#include "Globals.h"

class Tetrahedralize
{
private:
public:
	void BCCLattice(Mesh, VolumetricMesh&);
	void Refine(VolumetricMesh&);

};

