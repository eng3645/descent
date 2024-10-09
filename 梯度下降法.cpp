#include <stdio.h>
#include <math.h> 
//求三次函数y=pow(x,3.0)+3*pow(x,2.0)-2*x的最小值以及其对应的横坐标的近似值 
double outcomef1(double x);
double outcome(double x);
int main()
{
	double x=5;
	double learningrate=0.01;
	double y1=outcomef1(x);
	double a=learningrate*y1;
	int i=0;
	for(i=0;a>=0.000000000001;i++)
	{
		x=x-a;
		y1=outcomef1(x);
		a=y1*learningrate;
	}
	printf("f(x)min=%.16lf,x=%.12lf,循环次数=%d.",outcome(x),x,i+1);
	return 0;
}
double outcomef1(double x)
{
	double y;
	y=3*pow(x,2.0)+6*x-2;
	return y;
}
double outcome(double x)
{
	double y;
	y=pow(x,3.0)+3*pow(x,2.0)-2*x;
	return y;
}

