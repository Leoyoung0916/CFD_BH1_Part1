#include "stdafx.h"

#ifndef COMPAREGRID_H
#define COMPAREGRID_H

namespace COMPAREGRID
{
	double compareGridSum(int n, double* A, double* B, int num_threads=1);
	double compareGridMax(int n, double* A, double* B, int num_threads=1);
}

#endif