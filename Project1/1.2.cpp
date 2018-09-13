#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include <time.h> 
using namespace std;

void AIntegerBresenhamline(int x0, int y0, int x1, int y1, int color)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;//����յ�x֮��
	dy = y1 - y0;//����յ�y֮��
	e = -dx;//һ��ʼeΪd��������0.5�Ƚϣ�Ȼ����e��ʼֵΪ-0.5���Ϳ��Ը�0~1����0�Ƚϣ���*2 *dx, ���e=-dx��e=e+k   e=e+ dy/dx  e'=e'+2dy����
	x = x0;
	y = y0;
	for (int i = 0; i <= dx; i++)
	{
		//Sleep(5);
		putpixel(x, y, color);
		x++;
		e = e + 2 * dy;
		if (e >= 0) { y++; e = e - 2 * dx; }
	}

}

void BIntegerBresenhamline(int x0, int y0, int x1, int y1, int color)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;//����յ�x֮��
	dy = y1 - y0;//����յ�y֮��
	e = -dx;//һ��ʼeΪd��������0.5�Ƚϣ�Ȼ����e��ʼֵΪ-0.5���Ϳ��Ը�0~1����0�Ƚϣ���*2 *dx, ���e=-dx��e=e+k   e=e+ dy/dx  e'=e'+2dy����
	x = x0;
	y = y0;
	for (int i = 0; i <= dx; i++)
	{
		//Sleep(5);
		putpixel(x, y, color);
		x++;
		e = e + 2 * dy;
		if (e >= 0) { y++; e = e - 2 * dx; }
	}

}

void main()
{
	

	const int a = 600;
	const int b = 400;
	const int k =10;//�˵����

	initgraph(a, b);

	int x0[k];
	int y0[k];
	int x1[k];
	int y1[k];


	srand((unsigned)time(NULL));

	for (int i = 0; i < k; i++)
		x0[i] = (rand() % (a + 1));
	
	for (int i = 0; i < k; i++)
		y0[i] = (rand() % (b + 1));
	
	for (int i = 0; i < k; i++)
		x1[i] = (rand() % (a + 1));

	for (int i = 0; i < k; i++)
		y1[i] = (rand() % (a + 1));

	for (int i = 0; i < k; i++)
	{
		float c;
		float dx = x1[i] - x0[i];
		float dy = y1[i] - y0[i];
		c = dy / dx;
		if (c <= 1 && c >= -1)
		{
			AIntegerBresenhamline(x0[i], y0[i], x1[i], y1[i], GREEN);
		}
		else
		{
			BIntegerBresenhamline(y0[i], x0[i], y1[i], x1[i], RED);
		}
	}

	_getch();
	closegraph();
}