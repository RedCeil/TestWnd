// TestWnd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{

	HWND hQQWnd =  { 0 };
	//注意一定要调用父类窗口，子窗口会提示调用失败 最高级父窗口
	hQQWnd	= FindWindow(L"TXGuiFoundation",L"QQ"); //用spy++找到窗口类和标题！！不是句柄
	int nError = GetLastError();
	int nCase = 0 ;
	int cX = 602;
	int cY = 571;
	int nScreenX = GetSystemMetrics(SM_CXSCREEN);
	int nScreenY = GetSystemMetrics(SM_CYSCREEN);
	srand(GetTickCount());
	printf("屏幕分辨率为：\t%d\t*\t",nScreenX);
	printf("%d\n",nScreenY);
	printf("\n使用空格键中断各个调试模式，QQ登录界面是由一个父窗口和一个子窗口组成的，子窗口封装性很好，很难改变大小，但是父窗口可以改变大小，可以有qq带的截图工具看出");
	printf("\n\n调整窗口方式\n1.缩小\n2.放大\n3.闪烁\n4.随机跳跃\n5.隐藏窗口但不结束进程（占系统资源）\n6.重现窗口（前提是没有杀死窗口）\n");
	//MoveWindow(hQQWnd,0,0,400,400,TRUE);
	if (hQQWnd != 0)
	{
		printf("\n调用窗口句柄成功！！！\n\n");
	}
	else
	{
		printf("\n调用窗口句柄失败！！！ 错误码为：%d\n\n",nError);
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
						POINT MousePoint = { 0 };//0值时默认跟踪鼠标？？？
						GetCursorPos(&MousePoint);
						GetWindowRect(hQQWnd,&QQrect);//LPRECT 和 RECT 之间的转化就差一个&
						printf("鼠标位置为：\t%d\t*\t",MousePoint.x);
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
				printf("输入正确的调整方式的代号!!\n");
				break;
			}
		scanf_s("%d",&nCase);
	}
	
	system("pause");
	return 0;
}

