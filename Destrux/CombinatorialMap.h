#pragma once
#include "Dart.h"
#include "Face.h"
#include <map>
#include <functional>

class CombinatorialMap
{
private:
	Dart* Darts;
	std::map<std::pair<int, int>, Dart> _V_to_D;

	std::map<Dart, Dart> _B_to_D;

	// maps v-th vertex of 3-cell C to global index V
	std::map<std::pair<int, int>, int> Cv_to_V;

	// Bi(d) = Dart
	std::map<std::pair<int, int>, Dart> Beta;
public:
	template <unsigned int I> Dart* Beta(Dart d);
	
	// map takes Cell Id and Dart Id and returns a dart
	Dart V_to_D(int, int);

	Dart B_to_D(Dart);

	int d_to_v(Dart);

	int Cv_to_V(int C, int v) {

	}

	std::function<int(int)> compose(std::function<int(int)> f, std::function<int(int)> g) {
		return [f, g](int x) { return f(g(x);)};
	}
	int D_to_V(int C, int d) {
		return Cv_to_V(C, d_to_v(d));
	}

	// i-th dart of face f
	Dart f_to_d(Face, int);



};

