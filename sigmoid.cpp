#include<cmath>
#include"sigmoid.h"
#include<algorithm>
double sigmoid(double z)
{
	z = std::min(500.0, std::max(z, -500.0));
	return 1.0/(1.0+std::exp(-z));
}
// std::vector<double> sigmoid(const std::vector<double>& z)
// {
// 	std::vector<double> res;
// 	for(auto i:z)
// 	{
// 		res.push_back(1.0/(1.0+exp(-i)));
// 	}
// 	return res;
// }

/*
1/(1+exp(-z))
*/