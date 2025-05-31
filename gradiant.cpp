#include"gradiant.h"
#include<vector>


dW_dB gradiant(const std::vector<double>& A,const std::vector<double>& y,const std::vector<std::vector<double>>& x)
{
	int m=x.size();
	int n=x[0].size();

	std::vector<double> dw(n,0.0);
	double db=0.0;
	for(int i=0;i<m;i++)
	{
		double diff=A[i]-y[i];
		for(int j=0;j<n;j++)
		{
			dw[j]+=diff*x[i][j];
		}
		db+=diff;
	}
	for(int i=0;i<n;i++) dw[i]/=m;
	return {dw,db/m};
}