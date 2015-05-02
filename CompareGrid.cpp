#include "stdafx.h"
#include "CompareGrid.h"
#include <omp.h>
#include <math.h>
#include <algorithm>


using namespace std;

/**********************************************

���ǱȽ�����һά��������ĺ���
���룺
int n �������ά��
int num_threads �ǲ����߳�����Ĭ��Ϊ8
double* A B �ǱȽϵ�������׵�ַ
double Sum�ǲ�ľ���ֵ�ļӺ�
double Max�ǲ�ľ���ֵ�����ֵ
ֵ����ҫ���ǣ��ҿ���openMP����
��Ȼֻ�к���һ�㡭��

***********************************************/


namespace COMPAREGRID
{

	double compareGridSum(int n, double* A, double* B, int num_threads)
	{

		/*��openMP���٣�*/

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

		/*��openMP���٣�*/

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