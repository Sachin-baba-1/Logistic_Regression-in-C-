#include<iostream>
#include<vector>
#include"sigmoid.h"
#include"activation.h"
#include"cost.h"
#include"gradiant.h"
using namespace std;

int main()
{
	cout<<"Logistic regression\n";

	/*
		[*]**step1** calculate sigmoid function this is for shinking the large value in range b/w 0 - 1 float
		[*]**step2** Activation fucntion takes input of w,b and multipled with x --(input value) and add 		baised  w*x+b-->this multiplication need to be a dot product
		[*]**step3** calculate loss at this step  here we are trying to find cost ""this part is very 			important because here we will know how much is the model is learning like 
			if given wights are optimal for given labeled output ,it will calculate the cost of the b/w labled data and activation function outputs 
					also we will be calculating gradinet loss ""

		[*]**step4** now as we got the gardinent loss for weight and baise will update them as and tune our wights and baise with dw,db
			dw=-->(sum(A[i]-y[i])*x[i])/m

		**step5**  prediction steps will predict the input and then classify them based on their values 
			if more then 0.5 the will take it as 1 else 0
	*/

	vector<vector<double>> x = {{47, 15, 92, 8, 34,196},
								 {76, 53, 11, 60, 29,229},
								 {4, 99, 25, 77, 68,273},
								 {39, 84, 12, 46, 92,273},
								 {23, 5, 71, 37, 58,194}};
 	vector<double> y = {1, 0, 1, 1, 0};
	vector<double> weight(x[0].size(), 0.1);


	cout<<"Initial weights \t ==>";
	for(auto i :weight)cout<<i<<" ";
	cout<<"\n";


	double bais=0.0;
	double learning_rate=0.001;
	long long  epoch=100000;


	// double z=activation(x,weight,bais);
	// double A=sigmoid(z);

	for(long long e=0;e<epoch;e++)
	{
		vector<double> A;
		for(size_t i=0;i<x.size();i++)
		{
			double Zi=activation(x[i],weight,bais);
			// cout<<"Z["<<i<<"]="<<Zi<<"\n";
			A.push_back(sigmoid(Zi));
		}

		double cost_value=cost(A,y);

		dW_dB grad=gradiant(A,y,x);

	
		for(int i=0;i<weight.size();i++)
		{
			weight[i]=weight[i]-learning_rate*grad.dw[i];
		}
		bais-=grad.db;

		if(e%10000==0) cout<<"\n"<<e<<" \n cost==>"<<cost_value<<"\n";
	}
	cout << "\nTraining complete!\nFinal Weights: ";
	for (auto w : weight) cout << w << " ";
	cout << "\nFinal Bias: " << bais << "\n";

	
	vector<vector<double>> x_test={{12, 88, 7, 59, 36}, 
 {91, 3, 67, 28, 54}, 
 {81, 64, 92, 56, 112},
 {19, 47, 83, 11, 26},  
 {34, 21, 8, 73, 65}};

	cout<<"prediction \n";
	for(size_t i=0;i<x.size();i++)
	{
		double z=activation(x_test[i],weight,bais);
		double a=sigmoid(z);
		cout<<(a>=0.5) ? "Yes":"No";
	}
	
	cout<<"output should be 01110\n";
	



	return 0;
}