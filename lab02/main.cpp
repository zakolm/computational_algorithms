// Интерполяция.cpp : Defines the entry point for the console application.
//
/*Как эта программа работает:
	Функция Load_Data() считывает  данные из файла (по умолчанию data.txt)
	Данные должны быть в следущем виде: сначала кол-во узлов по x, затем кол-во узлов по y
	далее идет последовательное (по х) представление узлов (координата х, координата y, значение функции в точке)
	функциия коррректно работает только на прямоугольной сетке.

	Функции Interpolate выдает приближенное значение функции в точке (x,y) (по методу билинейной интерполяции)
	Вне сетки возвращает 0
*/
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#define _CRT_SECURE_NO_WARNINGS 1
//string.h
class point{
public:
	double x,y,f;
	void init(double x1,double y1,double f1){
		x=x1;
		y=y1;
		f=f1;
	}
	point(){
	}
}*uk;
int n_x,n_y;
double interpolate(double x,double y){
	double h_x,h_y;
	h_x=uk[1].x-uk[0].x;
	h_y=uk[n_y].y-uk[0].y;
	int n,m;
	n=int(floor((x-uk[0].x)/h_x));
	m=int(floor((y-uk[0].y)/h_y));
	if((n<0)||(n>n_x)||(m<0)||(m>n_y)) return 0;
	if (n==n_x-1) n--;
	if (m==n_y-1) m--;
	double x_n,y_m;
	x_n=uk[n].x;
	y_m=uk[m*n_y].y;
	return	uk[n+m*n_y].f*(x_n+h_x-x)*(y_m+h_y-y)/h_x/h_y +
			uk[n+1+m*n_y].f*(x-x_n)*(y_m+h_y-y)/h_x/h_y	+
			uk[n+(m+1)*n_y].f*(x_n+h_x-x)*(y-y_m)/h_x/h_y  +
			uk[n+1+(m+1)*n_y].f*(x-x_n)*(y-y_m)/h_x/h_y;
}
int Load_Data(){
	printf("For load from file data.txt input 0 or input filename\n");
	char s[20];
	char name[9]="data.txt";
	bool flag=1;
	FILE *f;
//	name="data.txt";
	//scanf("%s",&s);
	//if (s[0]!='0') flag=0;
	if (flag) if (!fopen_s(&f,name,"r")) printf("file open\n"); 
			else {printf("%s file don't exist\n",name);return -1;}
	else if (!fopen_s(&f,s,"r")) printf("file open\n");
	else { printf("%s file don't exist\n",s); return -1;}
	double p1,p2,p3;
	fscanf(f,"%d%d",&n_x,&n_y);
	uk=new point [n_x*n_y];
	int i=0; int j=0;
	while (!feof(f)){
		fscanf(f,"%lf%lf%lf",&p1,&p2,&p3);
		uk[i+j*n_y].init(p1,p2,p3);
		i++;
		if (i==n_x) {
			i=0; j++;
			if (j==n_y) break;
		}
		
	}
	fclose(f);
	return 1;
}
int main(int argc, char argv[])
{
char c;
double x,y;
x=2;
y=3.5;
if(Load_Data()!=-1){
	printf("x:  %lf\ny:   %lf\nans:   %lf\n",x,y,interpolate(x,y));
}

	//scanf("%c",&c);
	delete []uk;
	return 0;
}

