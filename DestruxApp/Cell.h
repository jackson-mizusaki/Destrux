#pragma once
#include "Attribute.h"


template <int K> // Dimension of the k-cell
class Cell
{
private:
	int k = K;
	Attribute<K> attribute;

public:
	Cell();
	Attribute<K> Attr();
};

