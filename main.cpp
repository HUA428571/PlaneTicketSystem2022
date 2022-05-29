#pragma once
#include"Function.h"
#include"Print.h"
#include"AdminMENU.h"
#include"CustomMenu.h"
#include"StartMENU.h"
#include<stdlib.h>
using namespace std;
//主函数
int main()
{
	static USER U[999];
	static Passenger P[999];
	static FlyhistoryAndOrder FO[100];
	static bookiinginformation custom;
	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线
	static FlightTicket DATA[366][999];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	int fail = 0;
	fail = ImportUserDatabase(U, P);
	if (fail == -1)
	{
		cout << "无法打开用户数据文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	FlightID_Count = ImportFlightDatabase(ID, ".\\Data\\Default_FlightID_Database.txt");
	fail = ImportTicketDatabase(DATA, FlightID_Count, ".\\Data\\Default_Ticket_Database.dat");
	if (FlightID_Count == -1)
	{
		cout << "无法打开默认航线数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	if (fail == -1)
	{
		cout << "无法打开机票数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	int Choice = StartMENU(U, P);
	//创建绘图窗口，大小为1280x720像素，没有关闭按钮
	initgraph(1280, 720, EW_NOCLOSE);
	if (Choice == 0)
		AdminMENU(ID, DATA, FlightID_Count);
	else
		CustomMenu(ID, DATA, FlightID_Count, P, U, FO, &custom, Choice);
	return 0;
}