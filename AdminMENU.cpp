#include"AdminMENU.h"
int AdminMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int& IDcount)
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
	PrintLoading();
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Home.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = AdminMENU_MainMENU(mysql, ID, DATA, IDcount);		//先进入主页
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 0:
			MENUchoice = AdminMENU_MainMENU(mysql, ID, DATA, IDcount);
			break;
		case 1:
			MENUchoice = AdminMENU_SearchMENU(mysql, ID, DATA, IDcount);
			break;
		case 2:
			MENUchoice = AdminMENU_AddMENU(mysql, ID, DATA, IDcount);
			break;
		case 3:
			MENUchoice = AdminMENU_DeleteMENU(mysql, ID, DATA, IDcount);
			break;
		case 4:
			MENUchoice = AdminMENU_ChangeMENU(mysql, ID, DATA, IDcount);
			break;
		case 61:
			PrintExit_AutoSAVE(ID, DATA, IDcount);
			closegraph();			// 关闭绘图窗口
			return 0;
		case 62:
			PrintExit();
			closegraph();			// 关闭绘图窗口
			return 0;
		}
	}
}
int AdminMENU_MainMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	PrintHomeBG(IDcount);
	char Location[4][100] = { ".\\Data\\Default_FlightID_Database.txt",".\\Data\\Default_Ticket_Database.dat",".\\Data\\FlightID.txt",".\\Data\\Ticket.dat" };
	settextstyle(20, 0, FONT);
	outtextxy(380, 200, "今天是");
	char count[12];
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%04d"), Local->tm_year + 1900);
	outtextxy(440, 200, count);
	outtextxy(480, 200, "年");
	_stprintf(count, _T("%02d"), Local->tm_mon + 1);
	outtextxy(500, 200, count);
	outtextxy(520, 200, "月");
	_stprintf(count, _T("%02d"), Local->tm_mday);
	outtextxy(540, 200, count);
	outtextxy(560, 200, "日");
	MatchWeekDay(Local->tm_wday, count);
	outtextxy(600, 200, count);
	//昨日飞行数据
	outtextxy(380, 240, "昨日飞行");
	outtextxy(380, 270, "其中准点");
	outtextxy(380, 300, "其中延误");
	outtextxy(380, 330, "其中取消");
	outtextxy(500, 240, "架次");
	outtextxy(500, 270, "架次");
	outtextxy(500, 300, "架次");
	outtextxy(500, 330, "架次");
	outtextxy(380, 380, "今日飞行");
	outtextxy(500, 380, "架次");
	int TodayFlyingID[999];
	int YestFlyingID[999];
	int TodayFlyCount;
	int YestFlyCount;
	int TodayOnTimeCount;
	int YestOnTimeCount;
	int TodayDelayCount;
	int YestDelayCount;
	int TodayCancelCount;
	int YestCancelCount;
	CountFlyingDetail(ID, DATA, IDcount, Local->tm_wday - 1, Local->tm_yday - 1, YestFlyingID, YestFlyCount, YestOnTimeCount, YestDelayCount, YestCancelCount);
	CountFlyingDetail(ID, DATA, IDcount, Local->tm_wday, Local->tm_yday, TodayFlyingID, TodayFlyCount, TodayOnTimeCount, TodayDelayCount, TodayCancelCount);
	_stprintf(count, _T("%4d"), YestFlyCount);
	outtextxy(460, 240, count);
	_stprintf(count, _T("%4d"), YestOnTimeCount);
	outtextxy(460, 270, count);
	_stprintf(count, _T("%4d"), YestDelayCount);
	outtextxy(460, 300, count);
	_stprintf(count, _T("%4d"), YestCancelCount);
	outtextxy(460, 330, count);
	_stprintf(count, _T("%4d"), TodayFlyCount);
	outtextxy(460, 380, count);
	setfillcolor(RGB(220, 220, 220));//设置背景色为浅灰色
	solidrectangle(550, 240, 1220, 260);
	solidrectangle(550, 270, 1220, 290);
	solidrectangle(550, 300, 1220, 320);
	solidrectangle(550, 330, 1220, 350);
	solidrectangle(550, 380, 1220, 400);
	//昨日航班
	setfillcolor(RGB(30, 144, 255));//设置颜色为道奇蓝
	for (int i = 550; i < 550 + ((double)YestFlyCount / IDcount) * 670; i += 2)
	{
		solidrectangle(i, 240, i + 2, 260);
		//Sleep(1);
	}
	setfillcolor(RGB(0, 128, 0));//设置颜色为绿色
	for (int i = 550; i < 550 + ((double)YestOnTimeCount / IDcount) * 670; i += 2)
	{
		solidrectangle(i, 270, i + 2, 290);
		//Sleep(1);
	}
	setfillcolor(RGB(255, 165, 0));//橙色
	for (int i = 550; i < 550 + ((double)YestDelayCount / IDcount) * 670; i += 2)
	{
		solidrectangle(i, 300, i + 2, 320);
		//Sleep(1);
	}
	setfillcolor(RGB(220, 20, 60));//猩红
	for (int i = 550; i < 550 + ((double)YestCancelCount / IDcount) * 670; i += 2)
	{
		solidrectangle(i, 330, i + 2, 350);
		//Sleep(1);
	}
	//今日航班
	setfillcolor(RGB(30, 144, 255));//设置颜色为道奇蓝
	for (int i = 550; i < 550 + ((double)TodayFlyCount / IDcount) * 670; i += 2)
	{
		solidrectangle(i, 380, i + 2, 400);
		//Sleep(1);
	}
	setfillcolor(RGB(220, 220, 220));//设置背景色为浅灰色
	solidcircle(460, 500 + 40, 80);
	solidcircle(730, 500 + 40, 80);
	solidcircle(1000, 500 + 40, 80);
	setfillcolor(RGB(0, 128, 0));//设置颜色为绿色
	solidpie(380, 420 + 40, 540, 580 + 40, PI / 2, (0.25 + (double)YestOnTimeCount / YestFlyCount) * 2 * PI);
	outtextxy(550, 475 + 40, "准点率：");
	_stprintf(count, _T("%2.0f"), ((double)YestOnTimeCount / YestFlyCount) * 100);
	outtextxy(550, 505 + 40, count);
	outtextxy(570, 505 + 40, "%");
	setfillcolor(RGB(255, 165, 0));//橙色
	solidpie(650, 420 + 40, 810, 580 + 40, PI / 2, (0.25 + (double)YestDelayCount / YestFlyCount) * 2 * PI);
	outtextxy(820, 475 + 40, "延误率：");
	_stprintf(count, _T("%2.0f"), ((double)YestDelayCount / YestFlyCount) * 100);
	outtextxy(820, 505 + 40, count);
	outtextxy(840, 505 + 40, "%");
	setfillcolor(RGB(220, 20, 60));//猩红
	solidpie(920, 420 + 40, 1080, 580 + 40, PI / 2, (0.25 + (double)YestCancelCount / YestFlyCount) * 2 * PI);
	outtextxy(1090, 475 + 40, "取消率：");
	_stprintf(count, _T("%2.0f"), ((double)YestCancelCount / YestFlyCount) * 100);
	outtextxy(1090, 505 + 40, count);
	outtextxy(1110, 505 + 40, "%");
	int MENUchoice = AdminMENU_MainMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 61:
		case 62:
			return MENUchoice;
		case 51:
			MENUchoice = AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
			break;
		case 52:
			MENUchoice = AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
			break;
		case 53:
			MENUchoice = AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
			break;
		case 54:
			MENUchoice = AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
			break;
		}
	}
	return AdminMENU_MENUChoose();
}
int AdminMENU_MainMENU_ImportFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int& IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\Import.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将从以下目录导入航线数据库：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[0]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		IDcount = ImportFlightDatabase(ID, Location[0]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "导入失败");
			IDcount++;//将idcount重置回零
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导入了");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导入");
		Sleep(500);
		return 0;
	case 59:
		clearrectangle(400, 280, 1220, 300);
		char LocationTEMP[100] = "\0";
		C_InputBox(LocationTEMP, 99, 400, 280, 600, 20, Location[0]);
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
			Sleep(50);
		}
		else
		{
			strcpy(Location[0], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
	return 0;
}
int AdminMENU_MainMENU_ImportTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Import.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将从以下目录导入机票数据库：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[1]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		IDcount = ImportTicketDatabase(DATA, IDcount, Location[1]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "导入失败");
			IDcount++;//将idcount重置回零
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导入了全部机票数据库");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导入");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
			Sleep(50);
		}
		else
		{
			strcpy(Location[1], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
	return 0;
}
int AdminMENU_MainMENU_SaveFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Export.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将在以下目录导出航线数据库：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[2]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	int success;
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		success = SaveFlightDatabase(ID, IDcount, Location[2]);
		clearrectangle(400, 200, 1220, 400);
		if (success == -1)
		{
			outtextxy(400, 200, "导出失败");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导出了");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导出");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
			Sleep(50);
		}
		else
		{
			strcpy(Location[2], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
	return 0;
}
int AdminMENU_MainMENU_SaveTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Export.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将在以下目录导出机票数据库：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[3]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	int success;
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		success = SaveTicketDatabase(DATA, IDcount, Location[3]);
		clearrectangle(400, 200, 1220, 400);
		if (success == -1)
		{
			outtextxy(400, 200, "导出失败");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导出了所有机票数据");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导出");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
			Sleep(50);
		}
		else
		{
			strcpy(Location[3], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
	return 0;
}

int AdminMENU_SearchMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int IDcount)
{
	PrintSearchBG(IDcount);
	int SearchReasult[999];//用于存储搜索结果
	int SearchCount = 0;
	int MENUchoice = AdminMENU_SearchMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 11:
			MENUchoice = AdminMENU_SearchMENU_SearchByID(mysql, ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 12:
			MENUchoice = AdminMENU_SearchMENU_SearchByDepartureAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 13:
			MENUchoice = AdminMENU_SearchMENU_SearchByArrivalAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 14:
			MENUchoice = AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		}
	}
}
int AdminMENU_SearchMENU_SearchByID(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char search[12];
	C_InputBox(search, 11, 135, 300, "CA101");
	SearchFlightID(mysql, ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		settextstyle(25, 0, FONT);
		PrintSearchBG(IDcount);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char search[12];
	C_InputBox(search, 11, 135, 350, "PEK");
	SearchFlightDepartureAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char search[12];
	C_InputBox(search, 11, 135, 400, "PEK");
	SearchFlightArrivalAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char Departure[12];
	settextstyle(28, 0, FONT2_EN);
	outtextxy(105, 506, "TO:");
	setlinecolor(RGB(220, 220, 220));
	line(140, 535, 290, 535);
	setlinecolor(BLACK);
	C_InputBox(Departure, 11, 135, 450, "PEK");
	char Arrival[12];
	C_InputBox(Arrival, 11, 135, 500, "PVG");
	SearchFlightDepartureAndArrivalAirport(ID, Departure, Arrival, IDcount, SearchReasult, SearchCount);//查找航起飞地，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}

int AdminMENU_AddMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	Resize(NULL, 480, 500);
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE Right;
	IMAGE Wrong;
	IMAGE Confirm;
	IMAGE Plane;
	FlightID NEW;
	strcpy(NEW.FlyDay, "00000000");
	loadimage(&Right, _T(".\\IMAGES\\Right.png"), 25, 25);
	loadimage(&Wrong, _T(".\\IMAGES\\Wrong.png"), 25, 25);
	loadimage(&Confirm, _T(".\\IMAGES\\AddConfirm.png"), 380, 60);
	putimage(50, 390, &Confirm);
	settextstyle(24, 0, FONT);
	outtextxy(A_LEFT_MARGIN, 50, "添加航线");
	settextstyle(20, 0, FONT);
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	int SearchReasult[999];
	int SearchCount;
	char carrier[50];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char IntChange[12];
	char Check[10] = { 0 };
	setlinecolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_MARGIN, 100, "航班号：");
	line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
	outtextxy(A_LEFT_MARGIN, 125, "开航日期：");
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_LINE_START, 125, "  一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(A_LEFT_MARGIN, 150, "执飞机型：");
	line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
	outtextxy(A_LEFT_MARGIN, 175, "起飞机场：");
	line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
	outtextxy(A_LEFT_MARGIN, 200, "起飞时间：");
	line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
	outtextxy(A_LEFT_MARGIN, 225, "降落机场：");
	line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
	outtextxy(A_LEFT_MARGIN, 250, "降落时间：");
	line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
	outtextxy(A_LEFT_MARGIN, 275, "飞行时间：");
	line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START + 50, 297);
	outtextxy(A_LEFT_LINE_START + 60, 275, "小时");
	line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START + 50, 297);
	outtextxy(A_RIGHT_TEXT_START + 60, 275, "分钟");
	outtextxy(A_LEFT_MARGIN, 300, "基准票价：");
	outtextxy(A_LEFT_MARGIN, 325, "基本舱位：");
	line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 201:
			clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
			C_InputBox(Input, 9, A_LEFT_LINE_START, 100, 90, 20, "CA101");
			line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
			if (!SearchFlightID(mysql, ID, Input, IDcount, SearchReasult, SearchCount))
			{
				NEW.Carrier[0] = Input[0];
				NEW.Carrier[1] = Input[1];
				NEW.Carrier[2] = '\0';
				NEW.ID[0] = Input[2];
				NEW.ID[1] = Input[3];
				NEW.ID[2] = Input[4];
				NEW.ID[3] = Input[5];
				NEW.ID[4] = Input[6];
				NEW.ID[5] = Input[7];
				NEW.ID[6] = Input[8];
				NEW.ID[7] = 0;
				MatchCarrier(NEW.Carrier, carrier);
				outtextxy(A_RIGHT_TEXT_START, 100, carrier);
				Check[0] = 1;
			}
			else
			{
				clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
				putimage(A_RIGHT_TEXT_START, 100, &Wrong);						//错误
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2031:
			if (NEW.FlyDay[1] == '0')
			{
				NEW.FlyDay[1] = '1';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
			}
			else
			{
				NEW.FlyDay[1] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2032:
			if (NEW.FlyDay[2] == '0')
			{
				NEW.FlyDay[2] = '2';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
			}
			else
			{
				NEW.FlyDay[2] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2033:
			if (NEW.FlyDay[3] == '0')
			{
				NEW.FlyDay[3] = '3';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
			}
			else
			{
				NEW.FlyDay[3] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2034:
			if (NEW.FlyDay[4] == '0')
			{
				NEW.FlyDay[4] = '4';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
			}
			else
			{
				NEW.FlyDay[4] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2035:
			if (NEW.FlyDay[5] == '0')
			{
				NEW.FlyDay[5] = '5';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
			}
			else
			{
				NEW.FlyDay[5] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2036:
			if (NEW.FlyDay[6] == '0')
			{
				NEW.FlyDay[6] = '6';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
			}
			else
			{
				NEW.FlyDay[6] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2037:
			if (NEW.FlyDay[7] == '0')
			{
				NEW.FlyDay[7] = '7';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
			}
			else
			{
				NEW.FlyDay[7] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 204:
			clearrectangle(A_RIGHT_TEXT_START, 150, 480, 175);
			C_InputBox(NEW.AircraftType, 3, A_LEFT_LINE_START, 150, 90, 20, "747");
			line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
			Check[2] = 1;
			MatchPlaneType(NEW.AircraftType, AircraftType);
			outtextxy(A_RIGHT_TEXT_START, 150, AircraftType);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 205:
			clearrectangle(A_RIGHT_TEXT_START, 175, 480, 200);
			C_InputBox(NEW.DepartureAirport, 3, A_LEFT_LINE_START, 175, 90, 20, "PEK");
			line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
			Check[3] = 1;
			MatchAirport(NEW.DepartureAirport, DepartureAirport);
			outtextxy(A_RIGHT_TEXT_START, 175, DepartureAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 206:
			C_InputBox(Input, 4, A_LEFT_LINE_START, 200, 90, 20, "1000");
			sscanf(Input, "%d", &NEW.DepartureTime);
			line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
			Check[4] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 207:
			clearrectangle(A_RIGHT_TEXT_START, 225, 480, 250);
			C_InputBox(NEW.ArrivalAirport, 3, A_LEFT_LINE_START, 225, 90, 20, "PVG");
			line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
			Check[5] = 1;
			MatchAirport(NEW.ArrivalAirport, ArrivalAirport);
			outtextxy(A_RIGHT_TEXT_START, 225, ArrivalAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 208:
			C_InputBox(Input, 4, A_LEFT_LINE_START, 250, 90, 20, "1200");
			sscanf(Input, "%d", &NEW.ArrivalTime);
			line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
			Check[6] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2091:
			C_InputBox(Input, 2, A_LEFT_LINE_START, 275, 50, 20, "2");
			line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START + 50, 297);
			sscanf(Input, "%d", &NEW.TravelTimeHour);
			Check[7] = 1;
			if (Check[8])
			{
				NEW.Price = round(NEW.TravelTimeHour * 675 + NEW.TravelTimeMinute * 11.25);
				clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
				outtextxy(A_LEFT_LINE_START, 300, _itoa(NEW.Price, IntChange, 10));
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2092:
			C_InputBox(Input, 2, A_RIGHT_TEXT_START, 275, 50, 20, "0");
			line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START + 50, 297);
			sscanf(Input, "%d", &NEW.TravelTimeMinute);
			Check[8] = 1;
			if (Check[7])
			{
				NEW.Price = round(NEW.TravelTimeHour * 675 + NEW.TravelTimeMinute * 11.25);
				clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
				outtextxy(A_LEFT_LINE_START, 300, _itoa(NEW.Price, IntChange, 10));
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 211:
			C_InputBox(NEW.Class, 3, A_LEFT_LINE_START, 325, 90, 20, "CY");
			line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
			Check[9] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 21:
			if (Check[0] && Check[1] && Check[2] && Check[3] && Check[4] && Check[5] && Check[6] && Check[7] && Check[8] && Check[9])
			{
				ID[IDcount] = NEW;
				Resize(NULL, 1280, 720);
				PrintBG(IDcount + 1);
				outtextxy(380, 170, "已成功添加");
				PrintFlightDetail(ID, DATA, IDcount, IDcount);
				IDcount++;
				return AdminMENU_MENUChoose();
			}
			else
			{
				MENUchoice = AdminMENU_AddMENU_MENUChoose();
			}
		case 22:
			Resize(NULL, 1280, 720);
			PrintBG(IDcount);
			settextstyle(25, 0, FONT);
			outtextxy(380, 200, "已取消添加");
			Sleep(50);
			MENUchoice = 0;
		}
	}
}

int AdminMENU_DeleteMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	PrintBG(IDcount);
	settextstyle(25, 0, FONT);
	char Delete[12];
	int SearchReasult[999];
	int SearchCount;
	InputBox(Delete, 12, "请输入你想删除的航班号\n完整航班号，eg CA101");
	SearchFlightID(mysql, ID, Delete, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintDeleteBG(IDcount);
		PrintFlightDetail(ID, DATA, IDcount, SearchReasult[0]);
		int MENUchoice = AdminMENU_DeleteMENU_MENUChoose();
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 31:
			clearrectangle(100, 200, 1220, 680);//把显示区域清空
			DeleteFlight(ID, DATA, IDcount, SearchReasult[0]);
			outtextxy(380, 200, "已成功删除");
			break;
		case 32:
			clearrectangle(100, 200, 1220, 680);//把显示区域清空
			outtextxy(380, 200, "已取消删除");
			break;
		}
		break;
	}
	PrintBG(IDcount);
	return AdminMENU_MENUChoose();
}

int AdminMENU_ChangeMENU(MYSQL mysql, FlightID* ID, FlightTicket DATA[][999], int IDcount)
{
	PrintBG(IDcount);
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	int SearchReasult[999];
	int SearchCount;
	InputBox(Input, 12, "请输入需要更改航班的航班号\n完整航班号，eg CA101");
	if (SearchFlightID(mysql, ID, Input, IDcount, SearchReasult, SearchCount) != 1)
	{
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		return AdminMENU_ChangeMENU_MENUChoose();
	}
	int Object = SearchReasult[0];
	char carrier[50];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char Flyday[50];
	char IntChange[12];
	char id[12];
	Resize(NULL, 480, 500);
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE Right;
	IMAGE Wrong;
	IMAGE Confirm;
	IMAGE Plane;
	FlightID tmp = ID[Object];
	loadimage(&Right, _T(".\\IMAGES\\Right.png"), 25, 25);
	loadimage(&Wrong, _T(".\\IMAGES\\Wrong.png"), 25, 25);
	loadimage(&Confirm, _T(".\\IMAGES\\ChangeConfirm.png"), 380, 60);
	putimage(50, 390, &Confirm);
	MatchCarrier(tmp.Carrier, carrier);
	MatchPlaneType(tmp.AircraftType, AircraftType);
	MatchAirport(tmp.DepartureAirport, DepartureAirport);
	MatchAirport(tmp.ArrivalAirport, ArrivalAirport);
	MatchFlyDay(tmp.FlyDay, Flyday);
	strcpy(id, tmp.Carrier);
	strcat(id, tmp.ID);
	settextstyle(24, 0, FONT);
	outtextxy(A_LEFT_MARGIN, 50, "更改航线");
	settextstyle(20, 0, FONT);
	setlinecolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_MARGIN, 100, "航班号：");
	outtextxy(A_RIGHT_TEXT_START, 100, carrier);
	outtextxy(A_LEFT_MARGIN, 125, "开航日期：");
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_LINE_START, 125, "  一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(A_LEFT_LINE_START + 20, 125, Flyday);
	outtextxy(A_LEFT_MARGIN, 150, "执飞机型：");
	outtextxy(A_RIGHT_TEXT_START, 150, AircraftType);
	outtextxy(A_LEFT_MARGIN, 175, "起飞机场：");
	outtextxy(A_RIGHT_TEXT_START, 175, DepartureAirport);
	outtextxy(A_LEFT_MARGIN, 200, "起飞时间：");
	outtextxy(A_LEFT_MARGIN, 225, "降落机场：");
	outtextxy(A_RIGHT_TEXT_START, 225, ArrivalAirport);
	outtextxy(A_LEFT_MARGIN, 250, "降落时间：");
	outtextxy(A_LEFT_MARGIN, 275, "飞行时间：");
	outtextxy(A_LEFT_LINE_START + 60, 275, "小时");
	outtextxy(A_RIGHT_TEXT_START + 60, 275, "分钟");
	outtextxy(A_LEFT_MARGIN, 300, "基准票价：");
	outtextxy(A_LEFT_MARGIN, 325, "基本舱位：");
	line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
	line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
	line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
	line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
	line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
	line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
	line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START + 50, 297);
	line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START + 50, 297);
	line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
	settextcolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_LINE_START, 100, id);
	outtextxy(A_LEFT_LINE_START, 150, tmp.AircraftType);
	outtextxy(A_LEFT_LINE_START, 175, tmp.DepartureAirport);
	_stprintf(IntChange, _T("%04d"), tmp.DepartureTime);
	outtextxy(A_LEFT_LINE_START, 200, IntChange);
	outtextxy(A_LEFT_LINE_START, 225, tmp.ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), tmp.ArrivalTime);
	outtextxy(A_LEFT_LINE_START, 250, IntChange);
	outtextxy(A_LEFT_LINE_START, 275, _itoa(tmp.TravelTimeHour, IntChange, 10));
	outtextxy(A_RIGHT_TEXT_START, 275, _itoa(tmp.TravelTimeMinute, IntChange, 10));
	outtextxy(A_LEFT_LINE_START, 300, _itoa(tmp.Price, IntChange, 10));
	outtextxy(A_LEFT_LINE_START, 325, tmp.Class);
	settextcolor(BLACK);
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 201:
			clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
			C_InputBox(Input, 9, A_LEFT_LINE_START, 100, 90, 20, id);
			line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
			if (!SearchFlightID(mysql, ID, Input, IDcount, SearchReasult, SearchCount))
			{
				tmp.Carrier[0] = Input[0];
				tmp.Carrier[1] = Input[1];
				tmp.Carrier[2] = '\0';
				tmp.ID[0] = Input[2];
				tmp.ID[1] = Input[3];
				tmp.ID[2] = Input[4];
				tmp.ID[3] = Input[5];
				tmp.ID[4] = Input[6];
				tmp.ID[5] = Input[7];
				tmp.ID[6] = Input[8];
				tmp.ID[7] = 0;
				MatchCarrier(tmp.Carrier, carrier);
				outtextxy(A_RIGHT_TEXT_START, 100, carrier);
			}
			else
			{
				if (strcmp(id, Input))
				{
					outtextxy(A_RIGHT_TEXT_START, 100, carrier);
				}
				else
				{
					clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
					putimage(A_RIGHT_TEXT_START, 100, &Wrong);						//错误
				}
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2031:
			if (tmp.FlyDay[1] == '0')
			{
				tmp.FlyDay[1] = '1';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
			}
			else
			{
				tmp.FlyDay[1] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2032:
			if (tmp.FlyDay[2] == '0')
			{
				tmp.FlyDay[2] = '2';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
			}
			else
			{
				tmp.FlyDay[2] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2033:
			if (tmp.FlyDay[3] == '0')
			{
				tmp.FlyDay[3] = '3';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
			}
			else
			{
				tmp.FlyDay[3] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2034:
			if (tmp.FlyDay[4] == '0')
			{
				tmp.FlyDay[4] = '4';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
			}
			else
			{
				tmp.FlyDay[4] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2035:
			if (tmp.FlyDay[5] == '0')
			{
				tmp.FlyDay[5] = '5';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
			}
			else
			{
				tmp.FlyDay[5] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2036:
			if (tmp.FlyDay[6] == '0')
			{
				tmp.FlyDay[6] = '6';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
			}
			else
			{
				tmp.FlyDay[6] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2037:
			if (tmp.FlyDay[7] == '0')
			{
				tmp.FlyDay[7] = '7';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
			}
			else
			{
				tmp.FlyDay[7] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
				settextcolor(BLACK);
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 204:
			clearrectangle(A_RIGHT_TEXT_START, 150, 480, 175);
			C_InputBox(tmp.AircraftType, 3, A_LEFT_LINE_START, 150, 90, 20, tmp.AircraftType);
			line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
			MatchPlaneType(tmp.AircraftType, AircraftType);
			outtextxy(A_RIGHT_TEXT_START, 150, AircraftType);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 205:
			clearrectangle(A_RIGHT_TEXT_START, 175, 480, 200);
			C_InputBox(tmp.DepartureAirport, 3, A_LEFT_LINE_START, 175, 90, 20, tmp.DepartureAirport);
			line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
			MatchAirport(tmp.DepartureAirport, DepartureAirport);
			outtextxy(A_RIGHT_TEXT_START, 175, DepartureAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 206:
			_stprintf(IntChange, _T("%04d"), tmp.DepartureTime);
			C_InputBox(Input, 4, A_LEFT_LINE_START, 200, 90, 20, IntChange);
			sscanf(Input, "%d", &tmp.DepartureTime);
			line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 207:
			clearrectangle(A_RIGHT_TEXT_START, 225, 480, 250);
			C_InputBox(tmp.ArrivalAirport, 3, A_LEFT_LINE_START, 225, 90, 20, tmp.ArrivalAirport);
			line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
			MatchAirport(tmp.ArrivalAirport, ArrivalAirport);
			outtextxy(A_RIGHT_TEXT_START, 225, ArrivalAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 208:
			_stprintf(IntChange, _T("%04d"), tmp.ArrivalTime);
			C_InputBox(Input, 4, A_LEFT_LINE_START, 250, 90, 20, IntChange);
			sscanf(Input, "%d", &tmp.ArrivalTime);
			line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2091:
			C_InputBox(Input, 2, A_LEFT_LINE_START, 275, 50, 20, _itoa(tmp.TravelTimeHour, IntChange, 10));
			line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START + 50, 297);
			sscanf(Input, "%d", &tmp.TravelTimeHour);
			tmp.Price = round(tmp.TravelTimeHour * 675 + tmp.TravelTimeMinute * 11.25);
			clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
			outtextxy(A_LEFT_LINE_START, 300, _itoa(tmp.Price, IntChange, 10));
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2092:
			C_InputBox(Input, 2, A_RIGHT_TEXT_START, 275, 50, 20, _itoa(tmp.TravelTimeMinute, IntChange, 10));
			line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START + 50, 297);
			sscanf(Input, "%d", &tmp.TravelTimeMinute);
			tmp.Price = round(tmp.TravelTimeHour * 675 + tmp.TravelTimeMinute * 11.25);
			clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
			outtextxy(A_LEFT_LINE_START, 300, _itoa(tmp.Price, IntChange, 10));
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 211:
			C_InputBox(tmp.Class, 3, A_LEFT_LINE_START, 325, 90, 20, tmp.Class);
			line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 21:
			ID[Object] = tmp;
			Resize(NULL, 1280, 720);
			PrintBG(IDcount);
			outtextxy(380, 170, "已成功更改");
			PrintFlightDetail(ID, DATA, IDcount, Object);
			return AdminMENU_MENUChoose();
		case 22:
			Resize(NULL, 1280, 720);
			PrintBG(IDcount);
			outtextxy(380, 170, "已取消更改");
			MENUchoice = AdminMENU_MENUChoose();
		}
	}
}