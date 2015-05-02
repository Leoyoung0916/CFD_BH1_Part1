#include "stdafx.h"
#include "CompareGrid.h"
#include <omp.h>
#include <math.h>
#include <algorithm>


using namespace std;

/**********************************************

这是比较两个一维数组数组的函数
输入：
int n 是数组的维数
int num_threads 是并行线程数，默认为8
double* A B 是比较的数组的首地址
double Sum是差的绝对值的加和
double Max是差的绝对值的最大值
值得炫耀的是，我开了openMP加速
虽然只有很少一点……

***********************************************/


namespace COMPAREGRID
{

	double compareGridSum(int n, double* A, double* B, int num_threads)
	{

		/*用openMP加速！*/

		double Sum = 0.0;

		omp_set_num_threads(num_threads);

		//#pragma omp parallel for reduction(+:Sum)

		for (int i = 0; i < n; i++)
		{
			Sum += fabs(A[i] - B[i]);
		}

		return Sum;
	}


	double compareGridMax(int n, double* A, double* B, int num_threads)
	{

		/*用openMP加速！*/

		double Max = 0.0;

		omp_set_num_threads(num_threads);

		#pragma omp parallel for

		for (int i = 0; i < n; i++)
		{
			Max = max(Max, fabs(A[i] - B[i]));
		}

		return Max;
	}
}