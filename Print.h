#pragma once
//本文件存储显示内容的函数
#include"MENUchoose.h"
#include"Struct.h"
#include"Match.h"
#include"Function.h"
#include<time.h>
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<string>
#include <synchapi.h> 
#include<stdlib.h>
#include<Windows.h>
using namespace std;
//加载动画1280*720
void PrintLoading();
void C_PrintLoading();
//退出动画且不自动保存1280*720（）
void PrintExit();
//退出动画并自动保存1280*720（）
void PrintExit_AutoSAVE(FlightID* ID, FlightTicket DATA[][999], int IDcount);
//加载中动画
void PrintProcess();
//打印单个航线的详细信息:整页（航线数据数组，需要打印航班的数组下标）
void PrintFlightDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i);
//打印单个航线（航线数据数组，需要打印航班的数组下标）
int PrintSingleFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i);
//按页打印多个航线（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数）
int PrintMultiFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount);
//按页打印时的表格表头（）
void PrintFlightTitle();
//按页打印时的打印一页航线数据（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数，当前页数，总页数）
void PrintMultiFlightPage(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
//打印单个航线的详细信息:一行（航线数据数组，航线数据计数，需要打印航班的数组下标，行数:x位置）
void PrintSingleLineFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i, int roll);
//在详情页下方打印近期正晚点情况
void PrintTimeAccuracyBar(FlightID* ID, FlightTicket DATA[][999], int i);
//打印每日机票页标题栏
void PrintTicketTitle();
//打印每日机票详细信息
int PrintTicket(FlightID* ID, FlightTicket DATA[][999], int n);
//打印每日机票详细信息:整页
void PrintTicketPage(FlightID* ID, FlightTicket DATA[][999], int* Fly, int n, int Page, int CurrentPage, int FlyDayCountAll);
//打印背景
void PrintBG(int IDcount);
//打印主页背景
void PrintHomeBG(int IDcount);
//打印搜索页背景
void PrintSearchBG(int IDcount);
//打印删除页背景
void PrintDeleteBG(int IDcount);

//乘客部分
void c_PrintFlightDetail(FlightID* ID, FlyhistoryAndOrder* FO, int IDcount, int i, int n, Passenger* p);
void b_PrintFlightDetail(FlightID* ID, FlightTicket DATA[366][999], int IDcount, int i, int m);
void PrintRES();
void PrintORS();
void PrintRBS();
void PrintORF();
void PrintDORF();
void PrintCORF();
int C_PrintMultiFlight(FlightID* ID, FlyhistoryAndOrder* FO, int IDcount, int* SearchReasult, int SearchCount, int* flyday, Passenger* p);
int re_printmultiflight(FlightID* ID, FlightTicket DATA[366][999], FlyhistoryAndOrder* FO, Passenger* P, USER* User, int IDcount, int* SearchReasult, int SearchCount, int* flyday, int p_id, bookiinginformation* custom);
int b_printmultiflight(FlightID* ID, FlightTicket DATA[366][999], Passenger* P, USER* User, int IDcount, int* SearchReasult, int SearchCount, int flyday, int p_id);
int rb_printmultiflight(FlightID* ID, FlightTicket DATA[366][999], Passenger* P, USER* User, int IDcount, int* SearchReasult, int SearchCount, int flyday, int p_id);
void c_PrintFlightTitle();
void c_PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page, int flyday);
void C_PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page, int* flyday);
void c_PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll, int flyday);
void C_PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll, int* flyday, int m);
void CPrintProcess();
void CPrintProcess2();
void PrintCustomer(USER* User, int id);
