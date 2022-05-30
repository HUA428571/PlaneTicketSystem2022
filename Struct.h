#pragma once
//在本文件中存储结构体定义和宏定义
//本文件被所有的其余文件包含
#include<iostream>
#define PI 3.1415926536
//全局字体格式
#define FONT "黑体"
#define FONT2_ZH "宋体"
#define FONT2_EN "Consolas"

//添加界面格式
#define A_LEFT_MARGIN 60
#define A_LEFT_LINE_START 150
#define A_LEFT_LINE_END 240
#define A_RIGHT_TEXT_START 260

using namespace std;

typedef struct FlightID //用于表示航班号，航班号只代表航班基本信息。
{
	char Carrier[3] = { 'X','X','\0' };										//航空公司，用两个大写字母表示
	char ID[8] = { 'X','X','X','X','X','X','X','\0' };						//航班号
	char FlyDay[9] = { 'X','X','X','X','X','X','X','X','\0' };				//开航日期，以星期为周期，星期几与数组下标对应，开航为数字，不开航为0
	char DepartureAirport[5] = { 'X','X','X','X','\0' };					//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	char ArrivalAirport[5] = { 'X','X','X','X','\0' };						//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	int DepartureTime = 2500;												//出发时刻，四字码
	int ArrivalTime = 2500;													//到达时刻，四字码。eg 1230（12时30分）
	int TravelTimeHour = 0;													//飞行时间(时)
	int TravelTimeMinute = 0;												//飞行时间(分)
	int Price = 0;															//基准票价，由飞行时间自动计算而得
	char AircraftType[4] = { 'X','X','X','\0' };							//飞机型号，三字码。eg 787，350
	char Class[4] = { 'X','X','X','\0' };									//舱位，两舱或三舱，注意结尾的\0。
}FlightID;

typedef struct FlightTicket //每日机票情况
{
	short Seat[50][10] = { 0 };
	short FirstClassTicketRemain = 0;
	short BusinessClassTicketRemain = 0;
	short EconomyClassTicketRemain = 0;
	short ActuralDepartureTime = 2600;		//2400及以下的是正常时间，2500代表航班取消，2600代表没有相关信息
	short ActuralArrivalTime = 2600;		//2400及以下的是正常时间，2500代表航班取消，2600代表没有相关信息
}FlightTicket;

typedef struct Passenger
{
	char id[21] = "\0";			//账号
	char name[11] = "\0";		//姓名
	char IdCard[19] = "\0";		//身份证号码
	char TelNum[12] = "\0";		//电话号码
	int i = 0;                  //判断是否为空

}Passenger;

typedef struct USER//用户
{
	char id[21] = "\0";			//账号 
	char pwd[21] = "\0";		//密码 
	char Identity = -1;			//身份为单个字符（0为用户，1为管理员）
	char phone[12] = "\0";		//电话号码
	int p[5] = { 0 };           //存储乘机人数组下标
	int Credi = 2;				//用户信用
	int pic = 1;				//头像
}USER;

typedef struct FlyhistoryAndOrder// 订单
{
	int flyday[100];			//每单的起飞日期
	int flight[100];			//每单的航班号
	int seat_x[100];			//每单的座位坐标
	int seat_y[100];			//每单的座位坐标
	int price[100];				//每单的票价
	char Class[100];			//每单的机舱
	int id[100];				//每单的乘客Id
}FlyhistoryAndOrder;

typedef struct bookiinginformation
{
	int year, month, day;
	int primary;
	char departure[12];
	char destination[12];
	int flyday;
	int flynumber[999];
}bookiinginformation;