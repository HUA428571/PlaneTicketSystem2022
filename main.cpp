#pragma once
#include"Function.h"
#include"Print.h"
#include"AdminMENU.h"
#include"CustomMenu.h"
#include"StartMENU.h"
#include<stdlib.h>
using namespace std;
//������
int main()
{
	static USER U[999];
	static Passenger P[999];
	static FlyhistoryAndOrder FO[100];
	static bookiinginformation custom;
	//���е�XXcount���Ǹ��������Ƕ�Ӧ�±꣡�±�Ҫ��һ
	static FlightID ID[999];//Ĭ�����洢999������
	static FlightTicket DATA[366][999];//�洢һ��ĺ�����
	int FlightID_Count = 0;//�洢��ǰ����Ÿ���
	int fail = 0;
	fail = ImportUserDatabase(U, P);
	if (fail == -1)
	{
		cout << "�޷����û������ļ������������˳�" << endl;
		Sleep(1000);
		exit(1);
	}
	FlightID_Count = ImportFlightDatabase(ID, ".\\Data\\Default_FlightID_Database.txt");
	fail = ImportTicketDatabase(DATA, FlightID_Count, ".\\Data\\Default_Ticket_Database.dat");
	if (FlightID_Count == -1)
	{
		cout << "�޷���Ĭ�Ϻ������ݿ��ļ������������˳�" << endl;
		Sleep(1000);
		exit(1);
	}
	if (fail == -1)
	{
		cout << "�޷��򿪻�Ʊ���ݿ��ļ������������˳�" << endl;
		Sleep(1000);
		exit(1);
	}
	int Choice = StartMENU(U, P);
	//������ͼ���ڣ���СΪ1280x720���أ�û�йرհ�ť
	initgraph(1280, 720, EW_NOCLOSE);
	if (Choice == 0)
		AdminMENU(ID, DATA, FlightID_Count);
	else
		CustomMenu(ID, DATA, FlightID_Count, P, U, FO, &custom, Choice);
	return 0;
}