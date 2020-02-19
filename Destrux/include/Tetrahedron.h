#pragma once
#include "Polyhedron.h"
#include "Globals.h"
#include <Eigen/Dense>
#include <array>
#include "TetrahedronAnalysis.h"
namespace Destrux {
	class Tetrahedron : public Polyhedron
	{
	private:
		std::array<Point3, 4> Nodes;
		friend class TetrahedronAnalysis;
	};
}

