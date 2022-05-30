#pragma once
#include"Function.h"
#include"Print.h"
#include"AdminMENU.h"
#include"CustomMenu.h"
#include"StartMENU.h"
#include<stdlib.h>
#include<mysql.h>
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
	//int Choice = StartMENU(U, P);
	//������ͼ���ڣ���СΪ1280x720���أ�û�йرհ�ť
//	initgraph(1280, 720, EW_NOCLOSE);
	//if (Choice == 0)
//		AdminMENU(ID, DATA, FlightID_Count);
	//else
	//	CustomMenu(ID, DATA, FlightID_Count, P, U, FO, &custom, Choice);

	MYSQL mysql;    //���ݿ���
	MYSQL_RES* res; //��ѯ�����
	MYSQL_ROW row;  //��¼�ṹ��

	//��ʼ�����ݿ�
	mysql_init(&mysql);

	//�����ַ�����
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�
	if (mysql_real_connect(&mysql, "127.0.0.1", "B19030314", "B19030314", "dbexp3", 3306, NULL, 0) == NULL) {
		printf("����ԭ�� %s\n", mysql_error(&mysql));
		printf("����ʧ�ܣ�\n");
		exit(-1);
	}

	//��ѯ����
	int ret = mysql_query(&mysql, "select * from flightid;");
	printf("ret: %d\n", ret);

	//��ȡ�����
	res = mysql_store_result(&mysql);

	//��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res))
	{
		printf("%s  ", row[0]);  //��ӡID
		printf("%s  ", row[1]);  //��ӡ�༶
		printf("%s\n", row[2]);  //��ӡ����
	}
	//�ͷŽ����
	mysql_free_result(res);

	//�ر����ݿ�
	mysql_close(&mysql);

	return 0;
}