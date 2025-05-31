//costfuction cost=-(sum(Y*np.log(A)+(1-Y)*np.log(1-A))/m)  y->arr,A->arr/*cost function is give error of calculated output and labeled input in logistic regression we do this by using formula that is combining the both possibility of getting true value and getting not true value that A^(y)---> give outputs for true ,(1-A)^(1-y) for not true combining that give out A^(y)*(1-A)^(1-y)=loss in order to minimize the loss we negate the loss-->-(loss)*/
#include<vector>
#include<cmath>
#include<algorithm>
double safe_log(double x) {
    const double eps = 1e-15;
    return std::log(std::max(std::min(x, 1.0 - eps), eps));
}

double cost(const std::vector<double>& A,const std::vector<double>& y)
{
	int n=y.size();
	double loss=0.0;
	for(int i=0;i<n;i++)
	{
		loss+=-( (y[i])* safe_log(A[i])+(1-y[i]) * safe_log(1-A[i]) );
	}
	return loss/(double)n;
}