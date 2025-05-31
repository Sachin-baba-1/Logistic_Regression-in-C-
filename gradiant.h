#ifndef GRADIANT_H
#define GRADIANT_H
#include<vector>
struct dW_dB
{
	std::vector<double> dw;
	double db;	
};

dW_dB gradiant(const std::vector<double>& A,const std::vector<double>& y,const std::vector<std::vector<double>>& x);

#endif