#include "stdafx.h"

#ifndef DIM2ARRAY_H
#define DIM2ARRAY_H



using namespace std;

namespace DIM2ARRAY
{
	class Dim2Array
	{

		/**********************************************
		  This is a class for a fake dimention 2 array
		  Define a dimention 1 array: Array
		  Then reload index operation
		  **********************************************/

	public:
		Dim2Array(int m, int n);
		~Dim2Array();
		int Size1, Size2;
		double *Array;
		double& get(int a, int b);


	private:

	};

}


#endif