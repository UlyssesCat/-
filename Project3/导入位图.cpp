#include <graphics.h>
#include <conio.h>

void main()
{
	initgraph(400, 300);

	// ���� IMAGE ����
	IMAGE img;


	loadimage(&img, L"D://2.jpg",400,300);	// ��ȡͼƬ�� img ������
	putimage(0, 0, &img);	// ������ (0, 0) λ����ʾ IMAGE ����

	//// ��������
	//circle(100, 100, 20);
	//line(70, 100, 130, 100);
	//line(100, 70, 100, 130);

	//// ���������� img ����
	//getimage(&img, 70, 70, 60, 60);

	//// �� img �Զ�����ʾ����Ļ��ĳ��λ��
	//putimage(200, 200, &img);

	_getch();
	closegraph();
}