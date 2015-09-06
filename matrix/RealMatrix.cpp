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
RealMatrix::RealMatrix(string name)
{
	ifstream In;
	In.open(name, ios::in);
	
	while (!In.eof()){
		string s;
		getline(In, s);
		string sNumber;
		stringstream ss(s);
		
		double a;
		vector<double> temp;
		while (!ss.eof())
		{
			ss >> a;
			temp.push_back(a);
		}
		this->matrix.push_back(temp);		
	}
	
}
void RealMatrix::printMatrix()
{
	for (size_t i = 0; i < this->matrix.size(); i++)
	{
		for (size_t j = 0; j < this->matrix[i].size(); j++)
			cout << setw(5) << this->matrix[i][j];
		cout << endl;
	}
}
RealMatrix::~RealMatrix()
{
	for (int i = 0; i < this->matrix.size(); i++)
		this->matrix[i].clear();
}
