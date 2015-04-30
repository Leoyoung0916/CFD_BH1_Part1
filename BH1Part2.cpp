// BH1Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

#include "Dim2Array.h"
#include "SetGrid.h"
#include "MyTriBandSolver.h"

using namespace DIM2ARRAY;
using namespace SETGRID;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	int Size1 = 101;
	int Size2 = 101;
	int Times = 200000;

	SetGrid Temp(Size1, Size2);


	cout << Temp.ThisGrid.get(2,3) << endl;

	double t1 = clock();
	for (int i = 0; i < Times; i++)
	{
		Temp.jacobiUpdate();
	}

	double t2 = clock();

	cout << Temp.ThisGrid.get(2, 3) << endl;
	cout << t2-t1 << endl;
	
	
	return 0;
}

