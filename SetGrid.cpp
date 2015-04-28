#include "stdafx.h"
#include "SetGrid.h"


namespace SETGRID
{

	SetGrid::SetGrid(int m, int n) :ThisGrid(m, n), NextGrid(m, n), Size1(m), Size2(n)
	{
		initialize();
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

	void SetGrid::setBoundary(Dim2Array Grid)
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
		for (int i = 0; i < Size1; i++)
		{
			for (int j = 0; j < Size2; j++)
			{
				ThisGrid.get(i, j) = 0.25*( ThisGrid.get(i, j + 1) +
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

}