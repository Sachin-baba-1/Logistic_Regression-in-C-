#include<iostream>
#include<vector>

/*
	actiavtion function
	w*x+b-->z pased to sigmoid 
	current task computer w*x+b-->w is vector b is scaller
	it will return z value
*/
double activation(const std::vector<double>& X,const std::vector<double> &w,double b)
{
	double res=0.0;

	for(size_t i=0;i<X.size();i++)
	{
		res+=X[i]*w[i];
	}

	return res+b;
}