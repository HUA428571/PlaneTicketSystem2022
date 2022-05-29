#pragma once
//本文件存储管理员界面菜单函数
#include"Function.h"
#include"Print.h"
#include"Struct.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
int AdminMENU(FlightID*, FlightTicket[][999], int&);
int AdminMENU_MainMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount);
int AdminMENU_MainMENU_ImportFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int& IDcount, char Location[][100]);
int AdminMENU_MainMENU_ImportTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);
int AdminMENU_MainMENU_SaveFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);
int AdminMENU_MainMENU_SaveTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);

int AdminMENU_SearchMENU(FlightID* ID, FlightTicket DATA[][999], int IDcount);
int AdminMENU_SearchMENU_SearchByID(FlightID*, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID*, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID*, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount);

int AdminMENU_AddMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount);

int AdminMENU_DeleteMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount);

int AdminMENU_ChangeMENU(FlightID* ID, FlightTicket DATA[][999], int IDcount);