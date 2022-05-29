#include<iostream>
#include<string>
#include<vector>
#include<easyx.h>
#include<graphics.h>      // 引用图形库头文件
#include<conio.h>
#include"CustomMenu.h"
using namespace std;
int  HOMEpage(Passenger* P, USER* users, int id, FlightID* ID, FlightTicket DATA[366][999], FlyhistoryAndOrder* FO)
{
	PrintCustomer(users, id);
	clearrectangle(300, 170, 1280, 720);//开始前把显示区域清空
	IMAGE Plus;
	IMAGE Confirm;
	IMAGE Substract;
	IMAGE home;
	loadimage(&home, ".\\IMAGES\\home.jpg", 0, 0);
	putimage(720, 250, &home);
	loadimage(&Plus, _T(".\\IMAGES\\Plus.jpg"), 50, 50);
	loadimage(&Substract, _T(".\\IMAGES\\Substract.jpg"), 50, 50);
	loadimage(&Confirm, _T(".\\IMAGES\\choose.png"), 90, 40);
	char Passenger_Name[20];
	char Passenger_Idcard[20];
	char Passenger_Telephone[15];
	int SearchCount = 0;
	int i = 0, y;
	outtextxy(380, 200, "乘车人");
	outtextxy(530, 200, "身份证号");
	outtextxy(730, 200, "电话");
	int pagc = Passengercount(users, id);
	for (i = 0, y = 250; i < pagc; i++, y = y + 40)
	{
		settextcolor(BLACK);
		settextstyle(20, 0, "黑体");
		outtextxy(380, y, P[users[id].p[i]].name);
		outtextxy(530, y, P[users[id].p[i]].IdCard);
		outtextxy(730, y, P[users[id].p[i]].TelNum);
	}
	outtextxy(380, 480, "添加乘车人");
	outtextxy(500, 480, "删除乘车人");
	putimage(400, 500, &Plus);
	putimage(520, 500, &Substract);
	SearchCount = FindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	char count[6];
	_stprintf(count, _T("%02d"), SearchCount);
	outtextxy(900, 200, "您当前有");
	outtextxy(985, 200, count);
	outtextxy(1010, 200, "班预订航班待飞");
	outtextxy(900, 250, "请记得在航班起飞前尽早取票哟！");
	int Choose = CustomMENU_HomeMENU_MENUChoose();
	if (Choose == 12)
	{
		PicChoose(users, id);
		return 0;
	}
	if (Choose == 1 && users[id].p[4] == 0)
	{
		clearrectangle(260, 160, 1280, 720);
		outtextxy(530, 250, "姓名");
		outtextxy(530, 320, "身份证号码");
		outtextxy(530, 390, "手机号码");
		putimage(600, 600, &Confirm);
		while (1)
		{
			Choose = CustomMENU_AddPassenger_MENUChoose();
			switch (Choose)
			{
			case 1:
			case 10:
				break;
			case 2:
				outtextxy(480, 250, "姓名：");
				C_inputCbox(Passenger_Name, 530, 250, 270, 20);
				for (i = 0; i < 20; i++)
				{
					if (Passenger_Name[i] == '\r')
					{
						Passenger_Name[i] = '\0';
						break;
					}
				}
				Choose = CustomMENU_AddPassenger_MENUChoose();
				break;
			case 3:
				clearrectangle(900, 320, 1000, 340);
				outtextxy(420, 320, "身份证号码：");
				C_InputBox(Passenger_Idcard, 40, 530, 320, 270, 20, "");
				if (strlen(Passenger_Idcard) != 18)
					outtextxy(900, 320, "身份证错误");
				Choose = CustomMENU_AddPassenger_MENUChoose();
				break;
			case 4:
				clearrectangle(900, 390, 1000, 410);
				outtextxy(440, 390, "手机号码：");
				C_InputBox(Passenger_Telephone, 40, 530, 390, 270, 20, "");
				if (strlen(Passenger_Telephone) > 13)
					outtextxy(900, 390, "手机号错误");
				Choose = CustomMENU_AddPassenger_MENUChoose();
				break;
			case 5:
			{

				outtextxy(700, 610, "添加成功");
				int n = 0;
				for (i = 1; i < 999; i++)
				{
					if (P[i].i == 0)
					{
						n = i;
						break;
					}
				}
				strcpy(P[n].name, Passenger_Name);
				strcpy(P[n].IdCard, Passenger_Idcard);
				strcpy(P[n].TelNum, Passenger_Telephone);
				strcpy(P[n].id, users[id].id);
				P[n].i = 1;
				for (i = 0; i < 5; i++)
				{
					if (users[id].p[i] == 0)
					{
						users[id].p[i] = n;
						break;
					}
				}
				Choose = CustomMENU_AddPassenger_MENUChoose();
				break;
			}
			case 6:
				return 1;
				break;
			case 7:
				return 2;
				break;
			case 8:
				return 3;
				break;
			case 9:
				return 4;
				break;
			case 11:
				return 0;
				break;
			}

		}
	}
	if (Choose == 1 && users[id].p[4] != 0)
	{
		clearrectangle(300, 170, 1280, 720);//开始前把显示区域清空
		settextcolor(BLACK);
		settextstyle(25, 0, "黑体");
		outtextxy(380, 250, "对不起，本账号只能添加5位乘车人，谢谢理解！");
		Sleep(3000);
		return 0;
	}
	if (Choose == 10)
	{
		for (i = 0, y = 245; i < pagc; i++, y = y + 40)
		{
			IMAGE Chioce1;
			loadimage(&Chioce1, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
			putimage(350, y, &Chioce1);
		}
		IMAGE confirm, cancel;
		loadimage(&confirm, _T(".\\IMAGES\\choose.png"), 0, 0);
		loadimage(&cancel, _T(".\\IMAGES\\cancel.png"), 0, 0);
		clearrectangle(380, 480, 600, 550);
		putimage(500, 600, &confirm);
		putimage(700, 600, &cancel);
		int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
		while (true)
		{
			MOUSEMSG m;
			// 获取一条鼠标消息
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
			{
				IMAGE Chioce2;
				if (m.x > 350 && m.y > 245 && m.x < 380 && m.y < 275)
				{
					if (flag1 == 0)
					{
						flag1 = 1;
						clearrectangle(350, 245, 380, 275);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBoxActive.png"), 30, 30);
						putimage(350, 245, &Chioce2);
					}
					else if (flag1 == 1)
					{
						flag1 = 0;
						clearrectangle(350, 245, 380, 275);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
						putimage(350, 245, &Chioce2);
					}
				}
				if (m.x > 350 && m.y > 285 && m.x < 380 && m.y < 315)
				{
					if (flag2 == 0)
					{
						flag2 = 1;
						clearrectangle(350, 285, 380, 315);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBoxActive.png"), 30, 30);
						putimage(350, 285, &Chioce2);
					}
					else if (flag2 == 1)
					{
						flag2 = 0;
						clearrectangle(350, 285, 380, 315);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
						putimage(350, 285, &Chioce2);
					}
				}
				if (m.x > 350 && m.y > 325 && m.x < 380 && m.y < 355)
				{
					if (flag3 == 0)
					{
						flag3 = 1;
						clearrectangle(325, 330, 380, 355);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBoxActive.png"), 30, 30);
						putimage(350, 325, &Chioce2);
					}
					else if (flag3 == 1)
					{
						flag3 = 0;
						clearrectangle(325, 330, 380, 355);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
						putimage(350, 325, &Chioce2);
					}
				}
				if (m.x > 350 && m.y > 365 && m.x < 380 && m.y < 395)
				{
					if (flag4 == 0)
					{
						flag4 = 1;
						clearrectangle(350, 365, 380, 395);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBoxActive.png"), 30, 30);
						putimage(350, 365, &Chioce2);
					}
					else if (flag4 == 1)
					{
						flag4 = 0;
						clearrectangle(350, 365, 380, 395);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
						putimage(350, 365, &Chioce2);
					}
				}
				if (m.x > 350 && m.y > 405 && m.x < 380 && m.y < 435)
				{
					if (flag5 == 0)
					{
						flag5 = 1;
						clearrectangle(350, 405, 380, 435);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBoxActive.png"), 30, 30);
						putimage(350, 405, &Chioce2);
					}
					else if (flag5 == 1)
					{
						flag5 = 0;
						clearrectangle(350, 405, 380, 435);
						loadimage(&Chioce2, _T(".\\IMAGES\\SelectBox.png"), 30, 30);
						putimage(350, 405, &Chioce2);
					}
				}
				if (m.x > 500 && m.y > 600 && m.x < 600 && m.y < 655)//鼠标按在订票确认区域
				{
					if (flag1 + flag2 + flag3 + flag4 + flag5 == 0)
					{
						//没有选择乘车人，无反应
					}
					else
						break;
				}
				if (m.x > 700 && m.y > 600 && m.x < 800 && m.y < 655)//鼠标按在取消区域
					return 0;
			}
		}
		if (flag1 == 1)
		{
			users[id].p[0] = users[id].p[1];
			users[id].p[1] = users[id].p[2];
			users[id].p[2] = users[id].p[3];
			users[id].p[3] = users[id].p[4];
			users[id].p[4] = 0;
		}
		if (flag2 == 1)
		{
			users[id].p[1] = users[id].p[2];
			users[id].p[2] = users[id].p[3];
			users[id].p[3] = users[id].p[4];
			users[id].p[4] = 0;
		}
		if (flag3 == 1)
		{
			users[id].p[2] = users[id].p[3];
			users[id].p[3] = users[id].p[4];
			users[id].p[4] = 0;
		}
		if (flag4 == 1)
		{
			users[id].p[3] = users[id].p[4];
			users[id].p[4] = 0;
		}
		if (flag5 == 1)
			users[id].p[4] = 0;
	}
	switch (Choose)
	{
	case 6:
		return 1;
		break;
	case 7:
		return 2;
		break;
	case 8:
		return 3;
		break;
	case 9:
		return 4;
		break;
	case 11:
		return 0;
		break;
	}
}
int  OrderMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, int id)
{
	PrintCustomer(users, id);
	clearrectangle(300, 170, 1280, 680);
	int SearchCount = 0;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	SearchCount = FindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int x = C_PrintMultiFlight(ID, FO, IDcount, FO->flight, SearchCount, FO->flyday, P);
	return x;
}
int  BookingMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, bookiinginformation* custom, int id)
{
	PrintCustomer(users, id);
	clearrectangle(300, 170, 1280, 720);
	int SearchCount = 0;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	SearchCount = Searching(ID, DATA, custom, IDcount);
	int flyday = DateTransfer(custom->year, custom->month, custom->day) - 1;
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	int today = DateTransfer(Local->tm_year + 1900, Local->tm_mon + 1, Local->tm_mday);
	if (flyday - today <= 45 && flyday - today >= 0)
	{
		int x = b_printmultiflight(ID, DATA, P, users, IDcount, custom->flynumber, SearchCount, flyday, id);
		return x;
	}
	else
	{
		PrintDORF();
		Sleep(3000);
		return 2;
	}
}
int  Refunding_ChngeMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, int id, bookiinginformation* custom)
{
	PrintCustomer(users, id);
	clearrectangle(300, 170, 1280, 720);
	int SearchCount = 0;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	SearchCount = REFindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int x = re_printmultiflight(ID, DATA, FO, P, users, IDcount, FO->flight, SearchCount, FO->flyday, id, custom);
	return x;
}
void SignOutMENU(FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users)
{
	char* Location = ".\\Data\\Default_Ticket_Database.dat";
	SaveTicketDatabase(DATA, IDcount, Location);
	char* Location1 = ".\\Data\\users.dat";
	SaveUserDatabase(users, Location1);
	char* Location2 = ".\\Data\\Passenger.dat";
	SavePassengerDatabase(P, Location2);
	PrintExit();
	closegraph();			// 关闭绘图窗口
}
void CustomMenu(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, USER* users, FlyhistoryAndOrder* FO, bookiinginformation* custom, int id)
{
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	C_PrintLoading();
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Bacgr.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = HOMEpage(P, users, id, ID, DATA, FO);
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 0://主页
			CPrintProcess();
			MENUchoice = HOMEpage(P, users, id, ID, DATA, FO);
			break;
		case 1://历史订单
			CPrintProcess();
			MENUchoice = OrderMENU(ID, DATA, IDcount, P, users, FO, id);
			break;
		case 2://订票
			CPrintProcess();
			MENUchoice = BookingMENU(ID, DATA, IDcount, P, users, custom, id);
			break;
		case 3://退改签
			CPrintProcess();
			MENUchoice = Refunding_ChngeMENU(ID, DATA, IDcount, P, users, FO, id, custom);
			break;
		case 4://退出登录
			CPrintProcess();
			PrintCustomer(users, id);
			int x = 0;
			x = SignOutMenu_MENUChooce();
			if (x == 1)
				SignOutMENU(DATA, IDcount, P, users);
			else
				MENUchoice = 0;
			break;
		}
	}
}