#pragma once
#include <Eigen/Dense>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>


#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/helpers.h>
#include <CGAL/refine_mesh_3.h>
#include <CGAL/Surface_mesh/Surface_mesh.h>

// Domain
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef Eigen::Vector3d vec3;
typedef Eigen::Vector2d vec2;
typedef K::Point_3 Point3;
typedef K::Point_2 Point2;