#include "stdafx.h"
#include <iostream>
#include "SetGrid.h"

using namespace std;
using namespace MYTRIBANDSOLVER;

namespace SETGRID
{

	SetGrid::SetGrid(int m, int n) :ThisGrid(m, n), NextGrid(m, n), Size1(m), Size2(n), Matrix(n - 2, n - 2)
	{
		initialize();
		matrixGenerator();
	}

	SetGrid::~SetGrid()
	{

	}

	void SetGrid::initialize()
	{
		for (int i = 0; i < Size1*Size2; i++)
		{
			ThisGrid.Array[i] = 0;
		}

		setBoundary(ThisGrid);
	}

	void SetGrid::matrixGenerator()
	{

		for (int i = 0; i < Size2 - 2; i++)
		{
			for (int j = 0; j < Size2 - 2; j++)
			{
				Matrix.get(i, j) = 0;
			}
		}
		Matrix.get(0, 0) = 1;
		Matrix.get(0, 1) = -0.25;

		Matrix.get(Size2 - 3, Size2 - 3) = 1;
		Matrix.get(Size2 - 3, Size2 - 4) = -0.25;


		for (int i = 1; i < Size2 - 3; i++)
		{
			Matrix.get(i, i - 1) = -0.25;
			Matrix.get(i, i) = 1.0;
			Matrix.get(i, i + 1) = -0.25;
		}

		/*
		for (int i = 0; i < Size2 - 2; i++)
		{
			for (int j = 0; j < Size2 - 2; j++)
			{
				cout << Matrix.get(i,j)<<"  ";
			}
			cout << endl;
		}
		*/
	}



	void SetGrid::setBoundary(Dim2Array &Grid)
	{
		for (int i = 0; i < Size1; i++)
		{
			Grid.get(i, 0) = (float(i) / float(Size1 - 1))*(float(i) / float(Size1 - 1));
			Grid.get(i, Size2 - 1) = (float(i) / float(Size1 - 1))*(float(i) / float(Size1 - 1)) - 1;
		}

		for (int i = 0; i < Size2; i++)
		{
			Grid.get(0, i) = -(float(i) / float(Size2 - 1))*(float(i) / float(Size2 - 1));
			Grid.get(Size2 - 1, i) = 1 - (float(i) / float(Size2 - 1))*(float(i) / float(Size2 - 1));
		}
	}


	void SetGrid::gauss()
	{
		for (int i = 1; i < Size1 - 1; i++)
		{
			for (int j = 1; j < Size2 - 1; j++)
			{
				ThisGrid.get(i, j) = 0.25*(ThisGrid.get(i, j + 1) +
					ThisGrid.get(i, j - 1) +
					ThisGrid.get(i + 1, j) +
					ThisGrid.get(i - 1, j));
			}
		}
	}

	void SetGrid::gaussUpdate()
	{
		Time += 1;
		gauss();
	}


	void SetGrid::jacobi()
	{
		for (int i = 1; i < Size1 - 1; i++)
		{
			for (int j = 1; j < Size2 - 1; j++)
			{
				NextGrid.get(i, j) = 0.25*(ThisGrid.get(i, j + 1) +
					ThisGrid.get(i, j - 1) +
					ThisGrid.get(i + 1, j) +
					ThisGrid.get(i - 1, j));
			}
		}
	}


	void SetGrid::jacobiUpdate()
	{
		Time += 1;
		jacobi();
		setBoundary(NextGrid);
		temp = ThisGrid.Array;
		ThisGrid.Array = NextGrid.Array;
		NextGrid.Array = temp;
	}


	void SetGrid::line()
	{

		double *B = new double[Size2 - 2];

		for (int i = 1; i < Size1 - 1; i++)
		{
			for (int j = 1; j < Size2 - 1; j++)
			{
				B[j - 1] = (ThisGrid.get(i + 1, j) + ThisGrid.get(i - 1, j))*0.25;
			}

			B[0] += ThisGrid.get(i, 0) * 0.25;
			B[Size2 - 3] += ThisGrid.get(i, Size2 - 1)*0.25;
			myTriBandSolver(Size2 - 2, Matrix.Array,NextGrid.Array+(i*Size2+1), B);

		}

		delete[] B;
		
	}

	void SetGrid::lineUpdate()
	{
		Time += 1;
		line();
		setBoundary(NextGrid);
		temp = ThisGrid.Array;
		ThisGrid.Array = NextGrid.Array;
		NextGrid.Array = temp;
	}
}