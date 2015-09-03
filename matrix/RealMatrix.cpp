#include "stdafx.h"
#include "RealMatrix.h"


RealMatrix::RealMatrix(int whidth, int height )
{
	for (int i = 0; i < height; i++)
	{
		vector<double> temp(whidth);
		this->matrix.push_back(temp);
	}
}

RealMatrix::RealMatrix()
{
	int whidth = 0;
	int height = 0;
	for (int i = 0; i < height; i++)
	{
		vector<double> temp(whidth);
		this->matrix.push_back(temp);
	}
}

RealMatrix::~RealMatrix()
{
	for (int i = 0; i < this->matrix.size(); i++)
		this->matrix[i].clear();
}
