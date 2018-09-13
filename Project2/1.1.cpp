#include <graphics.h>  
#include <iostream>  
#include<windows.h>
using namespace std;
//��������㷨����ͨ�㷨
int BoundaryFill(int x, int y, int colorc)
{
	static int flag = 0;
	if (x >= 400 || x <= 0 || y >= 300 || y <= 0) 
	{
		MessageBox(NULL, L"���ͼ���ڲ�", L"��ʾ", 1);
		flag = 1;
		return 0;
	}
	if (flag == 0)
	{
	int c = 0;
	c = getpixel(x, y);
	if (c != colorc)
	{
		putpixel(x, y, colorc);
	}
	if (c == colorc)
		return 0;
	Sleep(1);
	BoundaryFill(x + 1, y, colorc);
	BoundaryFill(x, y + 1, colorc);
	BoundaryFill(x - 1, y, colorc);
	BoundaryFill(x, y - 1, colorc);
	}
}
int main()
{
	initgraph(400, 300);
	IMAGE img;
	loadimage(&img, L"D://1.bmp", 400, 300);	// ��ȡͼƬ�� img ������
	putimage(0, 0, &img);	// ������ (0, 0) λ����ʾ IMAGE ����

	int xclick = 0;
	int yclick = 0;

	MOUSEMSG m;
	int color[2];
	color[0] = WHITE;//����ɫ
	color[1] = BLACK;//ͼ��ɫ
	while (true)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			xclick = m.x;
			yclick = m.y;
			BoundaryFill(xclick, yclick, color[1]);//��������㷨  
			break;
		case WM_RBUTTONUP:
			return 0;				// ������Ҽ��˳�����
		}
	}
	getchar();
	closegraph();
	return 0;
}