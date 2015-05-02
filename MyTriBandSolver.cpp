# include "stdafx.h"
# include "MyTriBandSolver.h"

using namespace std;


/**********************************************

��Ϊ����vector��ֻ����һά����ģ�����
����һ�������Խ������Է�����ĺ���
���룺
int n �Ǿ����С��
double* A ��һ�� n*n��һά������׵�ַ��
double* X��һ��n��һά������׵�ַ��
double* B��һ��n��һά������׵�ַ��
��˵�������𡭡�

ֵ��ע����ǣ���ʹ�õ���Doolittle������LU�ֽ⣬��ˣ�A��˳������ʽ����0

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