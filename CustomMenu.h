#pragma once
//本文件存储乘客界面菜单函数
#include<iostream>
#include<string>
#include"Function.h"
#include"Struct.h"
#include"match.h"
#include"Print.h"
#include"MENUchoose.h"
using namespace std;
int HOMEpage(Passenger* P, USER* users, int id, FlightID* ID, FlightTicket DATA[366][999], FlyhistoryAndOrder* FO);
int OrderMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, int id);
int BookingMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, bookiinginformation* custom, int id);
int Refunding_ChngeMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, int id, bookiinginformation* custom);
void SignOutMENU(FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users);
void CustomMenu(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, bookiinginformation* custom, int id);