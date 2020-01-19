#pragma once

template <unsigned int I> // i-Attribute
class Attribute
{
private:
	int i = I;
	void* data;
public:
	Attribute(void*);
	void* Data();
};

