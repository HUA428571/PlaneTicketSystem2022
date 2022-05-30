#pragma once
#include"Function.h"
#include"Print.h"
#include"AdminMENU.h"
#include"CustomMenu.h"
#include"StartMENU.h"
#include<stdlib.h>
#include<mysql.h>
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
	//int Choice = StartMENU(U, P);
	//创建绘图窗口，大小为1280x720像素，没有关闭按钮
//	initgraph(1280, 720, EW_NOCLOSE);
	//if (Choice == 0)
//		AdminMENU(ID, DATA, FlightID_Count);
	//else
	//	CustomMenu(ID, DATA, FlightID_Count, P, U, FO, &custom, Choice);

	MYSQL mysql;    //数据库句柄
	MYSQL_RES* res; //查询结果集
	MYSQL_ROW row;  //记录结构体

	//初始化数据库
	mysql_init(&mysql);

	//设置字符编码
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//连接数据库
	if (mysql_real_connect(&mysql, "127.0.0.1", "B19030314", "B19030314", "dbexp3", 3306, NULL, 0) == NULL) {
		printf("错误原因： %s\n", mysql_error(&mysql));
		printf("连接失败！\n");
		exit(-1);
	}

	//查询数据
	int ret = mysql_query(&mysql, "select * from flightid;");
	printf("ret: %d\n", ret);

	//获取结果集
	res = mysql_store_result(&mysql);

	//给ROW赋值，判断ROW是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res))
	{
		printf("%s  ", row[0]);  //打印ID
		printf("%s  ", row[1]);  //打印班级
		printf("%s\n", row[2]);  //打印姓名
	}
	//释放结果集
	mysql_free_result(res);

	//关闭数据库
	mysql_close(&mysql);

	return 0;
}