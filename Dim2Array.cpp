
#include "stdafx.h"
#include "Dim2Array.h"


namespace DIM2ARRAY
{
	Dim2Array::Dim2Array(int m, int n)
	{
		Size1 = m;
		Size2 = n;
		Array = new double [m*n];
	}

	Dim2Array::~Dim2Array()
	{
		delete[] Array;
	}

	double& Dim2Array::get(int a, int b)
	{
		return Array[a*Size2 + b];
	}
}


