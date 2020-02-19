#pragma once
#include "Globals.h"
#include "CombinatorialMap.h"
#include <CGAL/Dart.h>
#include <CGAL/Cell_attribute.h>
#include <CGAL/Triangulation.h>

CMap_3 MeshComplexToCombinatorialMap(C3t3 c) {
	//C3t3::Edges_in_complex_iterator c.edges_in_complex_begin();
	CMap_3 map;
	for (C3t3::Edges_in_complex_iterator it = c.edges_in_complex_begin(); it != c.edges_in_complex_end(); it++) {
		
		CMap_3::Dart_handle dh = map.create_dart();
		int a = it->second;
		int b = it->third;
		
		
		//map.set_attribute<3>(dh, map.create_attribute<3>(a));
	}
	//for (C3t3::Vertices_in_complex_iterator it = c.vertices_in_complex_begin(); it != c.vertices_in_complex_end(); it++) {
	//	std::cout << it->point() << std::endl;
	//}
	return map;
}