#pragma once
#include <vector>
using namespace std;

class RealMatrix
{
private:
	vector < vector <double> > matrix;

public:
	RealMatrix();
	RealMatrix(int ,int );
	~RealMatrix();
};

