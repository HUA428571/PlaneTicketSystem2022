#pragma once
//本文件存储功能性函数
#include"Struct.h"
#include"AdminMENU.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<graphics.h>
#include<easyx.h>
#include<stdlib.h>
#include<conio.h>
#pragma comment(lib,"Imm32.lib")
using namespace std;
//使用蔡勒公式转换日期与星期
int WeekDayTransfer(int, int, int);
//返回日期对应天数
int DateTransfer(int, int, int);
//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int JudgeAircraftSize(FlightID*, int);
//导入导出数据库
int ImportFlightDatabase(FlightID* ID, char* Location);
int SaveFlightDatabase(FlightID* ID, int IDcount, char* Location);
int ImportTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
int SaveTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
int ImportUserDatabase(USER p[], Passenger m[]);
int SaveUserDatabase(USER p[], char* Location);
int SavePassengerDatabase(Passenger m[], char* Location);
//查找航班号，返回查找到航班个数
int SearchFlightID(MYSQL mysql, FlightID*, char*, int, int*, int&);
//查找航起飞地，返回查找到航班个数
int SearchFlightDepartureAirport(MYSQL mysql, FlightID*, char*, int, int*, int&);
//查找航降落地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);
//查找航起飞降落地，返回查找到航班个数
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount);
//按照起飞时间排序
//重载，全数据库排序/搜索结果数据库排序
int SortByDepartureTime(FlightID*, int, int*);
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult);
//删除
//重载，当添加航班取消时使用第二个
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete);
int DeleteFlight(FlightID* ID, int& IDcount, int Delete);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//计算飞行数据
int CountFlyingDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int wday, int yday, int* FlyingID, int& FlyCount, int& OnTimeCount, int& DelayCount, int& CancelCount);

//乘客部分
int JudgeAircraftSizeSeat(int n);
int Passengercount(USER* users, int i);
int FirstClassTicketRemain(FlightTicket DATA[366][999], int daycount, int i, int judge);//头等舱订票人数
int BusinessClassTicketRemain(FlightTicket DATA[366][999], int daycount, int i);//商务舱人数
int EconomyClassTicketRemain(FlightTicket DATA[366][999], int daycount, int i, int judge);
int FindTheHistoryAndOrder(FlightTicket DATA[366][999], FlightID* ID, Passenger* P, USER* User, int i, FlyhistoryAndOrder* FO);
int REFindTheHistoryAndOrder(FlightTicket DATA[366][999], FlightID* ID, Passenger* P, USER* User, int i, FlyhistoryAndOrder* FO);
int year_get();
char Class_get(int seat[100], int size, int i);
int price_get(FlightID* ID, int i, char Class);
int Searching(FlightID* ID, FlightTicket DATA[366][999], bookiinginformation* custom, int IDcount);
int p_Booking(FlightID* ID, FlightTicket DATA[366][999], Passenger* P, USER* users, int i, int flyday, int flynumber);
int Refunding(FlightTicket DATA[366][999], FlyhistoryAndOrder* FO, int n);
void GetIMEString(HWND hWnd, string& str);
void C_inputCbox(char* Input, int x, int y, int Lsize, int Hsize);
int hour_get(int x);
void PicChoose(USER* users, int id);
void flushMouseMsgBuffer();