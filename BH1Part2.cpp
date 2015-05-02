
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>

#include "Dim2Array.h"
#include "SetGrid.h"
#include "MyTriBandSolver.h"
#include "CompareGrid.h"

using namespace DIM2ARRAY;
using namespace SETGRID;
using namespace COMPAREGRID;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	int Size1 = 501;
	int Size2 = 501;
	int Times = 100001;
	int ThermoStep = 10;
	double CompareSum,CompareMax,CompareAverage;
	SetGrid Temp(Size1, Size2);
	Dim2Array Standard(Size1, Size2);

	ofstream File;
	File.open("Jacobi500.txt", ios::trunc);



	for (int i = 0; i < Size1; i++)
	{
		for (int j = 0; j < Size2; j++)
		{
			Standard.get(i, j) = (double(i) / (Size1 - 1))*(double(i) / (Size1 - 1)) - (double(j) / (Size2 - 1))*(double(j) / (Size2 - 1));
		}
	}


	//cout << Standard.get(2, 3)<<endl;

	double t1 = clock();
	for (int i = 0; i < Times; i++)
	{
		if (i%ThermoStep == 0)
		{
			CompareSum = compareGridSum(Size1*Size2, Temp.ThisGrid.Array, Standard.Array, 8);
			CompareMax = compareGridMax(Size1*Size2, Temp.ThisGrid.Array, Standard.Array, 8);
			CompareAverage = CompareSum / (Size1*Size2);

			File << i << "  " << CompareAverage << "  " << CompareMax << endl;
		}
		Temp.jacobiUpdate();
		
	}
	double t2 = clock();


	//cout << Temp.ThisGrid.get(2, 3) << endl;
	//printf("%1.16f\n", Temp.ThisGrid.get(2, 3));
	cout << "Time for iteration is  "<< t2-t1 <<"ms"<< endl;
	
	File.close();



	return 0;
}

