#include "VolumetricMesh.h"
#include <CGAL/IO/OBJ_reader.h>
#include <fstream>
#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>

// To avoid verbose function and named parameters call
using namespace CGAL::parameters;
VolumetricMesh::VolumetricMesh(const char* fname)
{
	std::ifstream input(fname);
    std::vector<K::Point_3> points;
    std::vector<std::vector<std::size_t> > polygons;
    if (!input || !CGAL::read_OBJ(input, points, polygons) || points.empty())
    {
        std::cerr << "Cannot open file " << std::endl;
        return;
    }
    CGAL::Polygon_mesh_processing::orient_polygon_soup(points, polygons);

    CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(points, polygons, poly);
    // Number the faces because 'orient_to_bound_a_volume' needs a face <--> index map
    int index = 0;
    for (Polyhedron::Face_iterator fb = poly.facets_begin(), fe = poly.facets_end(); fb != fe; ++fb)
        fb->id() = index++;

    if (!CGAL::is_triangle_mesh(poly)) {
        std::cerr << "Input geometry is not triangulated. Attempting triangulation now." << std::endl;
        if (!CGAL::Polygon_mesh_processing::triangulate_faces(poly)) {
            std::cerr << "Could not triangulate mesh" << std::endl;
            return;
        }
    }

    // Create domain
    Mesh_domain domain(poly);


    // Mesh criteria (no cell_size set)
    Mesh_criteria criteria(facet_angle = 25, facet_size = 0.2, facet_distance = 0.01,
        cell_radius_edge_ratio = 3);

    // Mesh generation
    C3t3 c3t3 = CGAL::make_mesh_3<C3t3>(domain, criteria, no_perturb(), no_exude());
    // Output
    std::cout << "generating mesh" << std::endl;
    std::ofstream medit_file("out_1.mesh");
    c3t3.output_to_medit(medit_file);
    medit_file.close();
    // Set tetrahedron size (keep cell_radius_edge_ratio), ignore facets
    Mesh_criteria new_criteria(cell_radius_edge_ratio = 3, cell_size = 0.321);
    // Mesh refinement (and make the output manifold)
    std::cout << "refining mesh" << std::endl;

    CGAL::refine_mesh_3(c3t3, domain, new_criteria);
  
    medit_file.open("out_2.mesh");
    c3t3.output_to_medit(medit_file);
    medit_file.close();
    // Output
    medit_file.close();
}
