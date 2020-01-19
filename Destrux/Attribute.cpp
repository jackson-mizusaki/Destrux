#include "Attribute.h"
#include "Globals.h"

template<unsigned int I>
Attribute<I>::Attribute(void* d) {
	data = d;
}

template<unsigned int I>
void* Attribute<I>::Data()
{
	if (I == 0) {
		// Vertex data
		return static_cast<Point3*>(data);
	}
	else if (I == 1) {
		// edge data
		// TODO : Define edge data
		return nullptr;
	}
	else if (I == 2) {
		// face data
		// TODO : Define face data
		return nullptr;
	}
	else if (I == 3) {
		// 3-cell data
		// TODO : Define Cell data

		return nullptr;
	}
	else{
		return nullptr;
	}
}
