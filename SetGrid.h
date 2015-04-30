#include "stdafx.h"
#include "Dim2Array.h"
#include "MyTriBandSolver.h"


#ifndef SETGRID_H
#define SETGRID_H

using namespace std;
using namespace DIM2ARRAY;

namespace SETGRID
{
	class SetGrid
	{

	public:
		SetGrid(int m, int n);
		~SetGrid();
		int Size1;
		int Size2;
		int Time = 0;
		Dim2Array ThisGrid;
		Dim2Array NextGrid;

		void gaussUpdate();
		void jacobiUpdate();
		void lineUpdate();


	private:
		void initialize();
		void matrixGenerator();
		void setBoundary(Dim2Array &Grid);
		
		void gauss();
		void jacobi();
		void line();
		Dim2Array Matrix;
		double *temp;

	};

}
#endif 

