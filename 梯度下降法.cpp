#include <stdio.h>
#include <math.h> 
//�����κ���y=pow(x,3.0)+3*pow(x,2.0)-2*x����Сֵ�Լ����Ӧ�ĺ�����Ľ���ֵ 
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
	printf("f(x)min=%.16lf,x=%.12lf,ѭ������=%d.",outcome(x),x,i+1);
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

