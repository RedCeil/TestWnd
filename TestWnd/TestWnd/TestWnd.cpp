// TestWnd.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{

	HWND hQQWnd =  { 0 };
	//ע��һ��Ҫ���ø��ര�ڣ��Ӵ��ڻ���ʾ����ʧ�� ��߼�������
	hQQWnd	= FindWindow(L"TXGuiFoundation",L"QQ"); //��spy++�ҵ�������ͱ��⣡�����Ǿ��
	int nError = GetLastError();
	int nCase = 0 ;
	int cX = 602;
	int cY = 571;
	int nScreenX = GetSystemMetrics(SM_CXSCREEN);
	int nScreenY = GetSystemMetrics(SM_CYSCREEN);
	srand(GetTickCount());
	printf("��Ļ�ֱ���Ϊ��\t%d\t*\t",nScreenX);
	printf("%d\n",nScreenY);
	printf("\nʹ�ÿո���жϸ�������ģʽ��QQ��¼��������һ�������ں�һ���Ӵ�����ɵģ��Ӵ��ڷ�װ�Ժܺã����Ѹı��С�����Ǹ����ڿ��Ըı��С��������qq���Ľ�ͼ���߿���");
	printf("\n\n�������ڷ�ʽ\n1.��С\n2.�Ŵ�\n3.��˸\n4.�����Ծ\n5.���ش��ڵ����������̣�ռϵͳ��Դ��\n6.���ִ��ڣ�ǰ����û��ɱ�����ڣ�\n");
	//MoveWindow(hQQWnd,0,0,400,400,TRUE);
	if (hQQWnd != 0)
	{
		printf("\n���ô��ھ���ɹ�������\n\n");
	}
	else
	{
		printf("\n���ô��ھ��ʧ�ܣ����� ������Ϊ��%d\n\n",nError);
		system("pause");
		return 0;
	}
	scanf_s("%d",&nCase);
	while (true)
	{
		switch (nCase)
			{
			case 1:
				{
					for (int i = 60; i > 0; i--)
					{
						SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_NOMOVE|SWP_NOZORDER);
						Sleep(180);
						cX -= 10;
						cY -= 10;
						if (GetAsyncKeyState(VK_SPACE))
						{
							break;
						}
					}
					printf("Done!!!\n");
				}
				break;
			case 2:
				{
					for (int i = 60; i > 0; i--)
					{
						SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_NOMOVE|SWP_NOZORDER);
						Sleep(180);
						cX += 10;
						cY += 10;
						if (GetAsyncKeyState(VK_SPACE))
						{
							break;
						}
					}
					printf("Done!!!\n");
				}
				break;
			case 3:
				{
					while (true)
					{
						SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_NOMOVE|SWP_NOZORDER|SWP_HIDEWINDOW);
						Sleep(180);
						SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_NOMOVE|SWP_NOZORDER|SWP_SHOWWINDOW);
						Sleep(180);
						if (GetAsyncKeyState(VK_SPACE))
						{
							break;
						}
					}
					printf("Done!!!\n");
				}
				break;
			case 4:
				{
					while (true)
					{
						RECT QQrect;
						POINT MousePoint = { 0 };//0ֵʱĬ�ϸ�����ꣿ����
						GetCursorPos(&MousePoint);
						GetWindowRect(hQQWnd,&QQrect);//LPRECT �� RECT ֮���ת���Ͳ�һ��&
						printf("���λ��Ϊ��\t%d\t*\t",MousePoint.x);
						printf("%d\n",MousePoint.y);
						int QQrectX = QQrect.right - QQrect.left;
						int QQrectY = QQrect.bottom - QQrect.top;
						if (MousePoint.x > QQrect.left && MousePoint.x < QQrect.right)
						{
							if (MousePoint.y > QQrect.top && MousePoint.y < QQrect.bottom)
							{
								SetWindowPos(hQQWnd,0,rand()%(nScreenX-QQrectX),rand()%(nScreenY-QQrectY),cX,cY,SWP_NOSIZE);
							}
						}
						if (GetAsyncKeyState(VK_SPACE))
						{
							break;
						}
					}
					printf("Done!!!\n");
				}
				break;
			case 5:SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_HIDEWINDOW);
				printf("Done!!!\n");
				break;
			case 6:SetWindowPos(hQQWnd,0,0,0,cX,cY,SWP_SHOWWINDOW);
				printf("Done!!!\n");
				break;
			default:
				printf("������ȷ�ĵ�����ʽ�Ĵ���!!\n");
				break;
			}
		scanf_s("%d",&nCase);
	}
	
	system("pause");
	return 0;
}

