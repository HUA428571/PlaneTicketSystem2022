#pragma once
//本文件存储用于匹配缩写与全称的函数
#include"Struct.h"
#include<iostream>
#include<math.h>
#include<graphics.h>
#include<time.h>
#include<easyx.h>
using namespace std;
//和数据库匹配飞机图片
void MatchPlaneImage(IMAGE& plane, char* AircraftType);
//和数据库匹配机型中文全称（输入字符串，输出字符串）
void MatchPlaneType(char* AircraftType, char* AIRCRAFTTYPE);
//和数据库匹配航空公司中文全称（输入字符串，输出字符串）
void MatchCarrier(char* carrier, char* CARRIER);
//和数据库匹配机场中文全称（输入字符串，输出字符串）
void MatchAirport(char* airport, char* AIRPORT);
//将开航日输出为中文字符串（输入字符串，输出字符串）
void MatchFlyDay(char* flyday, char* FLYDAY);
//将日期输出为中文字符串（输入字符串，输出字符串）
void MatchDate(int year, int date, char* Date);
//计算正晚点情况并返回字符串（航线数据库，航班数据库，航线数据下标，查询日期，返回字符串）
void MatchTimeAccuracy(FlightID* ID, FlightTicket DATA[][999], int n, int day, char* ACCURACY, COLORREF& TextColor);
//将星期输出为中文字符串（输入字符串，输出字符串）
void MatchWeekDay(int wday, char* WEEKDAY);
//将舱位输出为中文字符串（输入字符，输出字符串）
void MatchClass(char x, char* Class);
//将座位输出为中文字符串（输入数字，输出字符）
void MatchSeatY(int x, char* sy);
//对应头像
void MatchPic(int x, IMAGE& pic, int big);