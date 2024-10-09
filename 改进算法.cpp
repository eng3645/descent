#include <stdio.h>
#include <math.h>
double outcome(double w,double x,double b);
double loss1(double x[],double w,double b,double y[],int n);
double lossdw(double x[],double w,double b,double y[],int n);
int main()
{
	double x[9]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	double y[9]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	/*或者用scanf遍历输入数组中的数*/ 
	int n=sizeof(x)/sizeof(x[0]);
	double learningrate=0.01;
	double dw,db,w=5.0,b=5.0,k,k1;
	do
	{
		dw=lossdw(x,w,b,y,n)/n*2;
		db=loss1(x,w,b,y,n);
		w=w-learningrate*dw;
		b=b-learningrate*db;
		k=pow(dw,2.0)+pow(db,2.0);
	    k1=sqrt(k);
	}while(k1>=0.00000001);
	printf("y=%lfx+%lf",w,b);
	return 0;
}
double outcome(double w,double x,double b)
{
	return w*x+b;
}
double loss1(double x[],double w,double b,double y[],int n)
{
	double totalerror=0;
	double error,h;
	for (int i=0;i<=n-1;i++)
	{
		h=outcome(w,x[i],b);
		error=h-y[i];
		totalerror+=error;
	}
	return totalerror/n;
}
double lossdw(double x[],double w,double b,double y[],int n)
{
	double totalerror=0;
	double error,h;
	for (int i=0;i<=n-1;i++)
	{
		h=outcome(w,x[i],b);
		error=(h-y[i])*x[i];
		totalerror+=error;
	}
	return totalerror;
}
