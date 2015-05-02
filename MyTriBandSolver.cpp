# include "stdafx.h"
# include "MyTriBandSolver.h"

using namespace std;


/**********************************************

因为不会vector，只能用一维数组模拟矩阵
这是一个算三对角阵线性方程组的函数
传入：
int n 是矩阵大小，
double* A 是一个 n*n的一维数组的首地址，
double* X是一个n的一维数组的首地址，
double* B是一个n的一维数组的首地址。
你说我容易吗……

值得注意的是，我使用的是Doolittle方法作LU分解，因此，A的顺序主子式均非0

***********************************************/


namespace MYTRIBANDSOLVER
{

	void myTriBandSolver(int n, double* A, double* X, double* B)
	{

		double *Y = new double[n];
		double *u = new double[n];
		double *l = new double[n - 1];

		u[0] = A[0];

		for (int i = 1; i < n; i++)
		{
			l[i - 1] = A[i*n + i - 1] / u[i - 1];
			u[i] = A[i*n + i] - l[i - 1] * A[(i - 1)*n + i];
		}


		Y[0] = B[0];

		for (int i = 1; i < n; i++)
		{
			Y[i] = B[i] - Y[i - 1] * l[i - 1];
		}

		X[n - 1] = Y[n - 1] / u[n - 1];

		for (int i = n - 2; i > -1; i--)
		{
			X[i] = (Y[i] - A[i*n + i + 1] * X[i + 1]) / u[i];
		}


		delete[] Y;
		delete[] u;
		delete[] l;


	}

}