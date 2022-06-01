#include"Print.h"
//加载动画1280*720
void PrintLoading()
{
	IMAGE Loading;
	char Location[50];
	char IntChange[4];
	cleardevice();
	settextstyle(25, 0, FONT2_ZH);
	setbkcolor(RGB(255, 255, 253));
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Loading\\loading");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Loading, Location, 800, 600);
		putimage(240, 60, &Loading);
		if (i < 60)
			outtextxy(610, 550, "你好！");
		else
			outtextxy(480, 550, "欢迎访问管理员后台管理系统");
		Sleep(2);
	}
	cleardevice();
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Loading\\loading");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Loading, Location, 800, 600);
		putimage(240, 60, &Loading);
		outtextxy(460, 550, "版权所有");
		outtextxy(570, 550, "CopyRight 2020 HuaCL");
		Sleep(8);
	}
	cleardevice();
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Loading\\loading");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Loading, Location, 800, 600);
		putimage(240, 60, &Loading);
		if ((i / 20) % 5 == 0)
			outtextxy(470, 550, "正在加载系统及数据，请稍候");
		if ((i / 20) % 5 == 1)
			outtextxy(468, 550, "正在加载系统及数据，请稍候.");
		if ((i / 20) % 5 == 2)
			outtextxy(466, 550, "正在加载系统及数据，请稍候..");
		if ((i / 20) % 5 == 3)
			outtextxy(464, 550, "正在加载系统及数据，请稍候...");
		if ((i / 20) % 5 == 4)
			outtextxy(462, 550, "正在加载系统及数据，请稍候....");
		Sleep(8);
	}
	settextstyle(25, 0, FONT);
}
//退出动画且不自动保存1280*720（）
void PrintExit()
{
	IMAGE Exit;
	char Location[100];
	char IntChange[8];
	cleardevice();
	settextstyle(25, 0, FONT2_ZH);
	setbkcolor(RGB(255, 255, 253));
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Exit\\Exit");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Exit, Location, 800, 600);
		putimage(240, 60, &Exit);
		outtextxy(590, 550, "正在退出");
		Sleep(8);
	}
	return;
}
//退出动画并自动保存1280*720（）
void PrintExit_AutoSAVE(FlightID* ID, FlightTicket DATA[][999], int IDcount)
{
	IMAGE Exit;
	char Location[100];
	char IntChange[8];
	cleardevice();
	settextstyle(25, 0, FONT2_ZH);
	setbkcolor(RGB(255, 255, 253));
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Exit\\Exit");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Exit, Location, 800, 600);
		putimage(240, 60, &Exit);
		outtextxy(480, 550, "正在退出管理员后台管理系统");
		Sleep(8);
	}
	cleardevice();
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Exit\\Exit");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Exit, Location, 800, 600);
		putimage(240, 60, &Exit);
		outtextxy(460, 550, "版权所有");
		settextstyle(25, 0, FONT2_EN);
		outtextxy(570, 550, "CopyRight 2020 HuaCL");
		settextstyle(25, 0, FONT2_ZH);
		Sleep(8);
	}
	cleardevice();
	for (int i = 0; i < 156; i++)
	{
		strcpy(Location, ".\\IMAGES\\Exit\\Exit");
		_stprintf(IntChange, _T("%03d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Exit, Location, 800, 600);
		putimage(240, 60, &Exit);
		if ((i / 20) % 5 == 0)
			outtextxy(480, 550, "正在自动保存数据，请稍候");
		if ((i / 20) % 5 == 1)
			outtextxy(478, 550, "正在自动保存数据，请稍候.");
		if ((i / 20) % 5 == 2)
			outtextxy(476, 550, "正在自动保存数据，请稍候..");
		if ((i / 20) % 5 == 3)
			outtextxy(474, 550, "正在自动保存数据，请稍候...");
		if ((i / 20) % 5 == 4)
			outtextxy(472, 550, "正在自动保存数据，请稍候....");
		Sleep(8);
	}
	time_t NOW;									//获取当前时间
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	strcpy(Location, ".\\Data\\AutoSAVE_FlightID_");
	_stprintf(IntChange, _T("%4d"), Local->tm_year + 1900);
	strcat(Location, IntChange);
	_stprintf(IntChange, _T("%02d"), Local->tm_mon + 1);
	strcat(Location, IntChange);
	_stprintf(IntChange, _T("%02d"), Local->tm_mday);
	strcat(Location, IntChange);
	strcat(Location, ".txt");
	SaveFlightDatabase(ID, IDcount, Location);
	strcpy(Location, ".\\Data\\AutoSAVE_Ticket_");
	_stprintf(IntChange, _T("%4d"), Local->tm_year + 1900);
	strcat(Location, IntChange);
	_stprintf(IntChange, _T("%02d"), Local->tm_mon + 1);
	strcat(Location, IntChange);
	_stprintf(IntChange, _T("%02d"), Local->tm_mday);
	strcat(Location, IntChange);
	strcat(Location, ".dat");
	SaveTicketDatabase(DATA, IDcount, Location);
	return;
}
//加载中动画
void PrintProcess()
{
	IMAGE BG;
	IMAGE Process;
	char Location[100];
	char IntChange[8];
	setbkcolor(RGB(255, 255, 253));
	strcpy(Location, ".\\IMAGES\\Process\\Search4.png");
	loadimage(&BG, Location, 1280, 720);
	putimage(0, 0, &BG);
	for (int i = 0; i < 53; i++)
	{
		strcpy(Location, ".\\IMAGES\\Process\\Process");
		_stprintf(IntChange, _T("%02d"), i);
		strcat(Location, IntChange);
		strcat(Location, ".png");
		loadimage(&Process, Location, 200, 200);
		putimage(540, 260, &Process);
		Sleep(12);
	}
	return;
}
//打印单个航线的详细信息:整页（航线数据数组，需要打印航班的数组下标）
void PrintFlightDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i)
{
	clearrectangle(380, 200, 1220, 720);
	IMAGE plane;
	IMAGE FlightDetail;
	LOGFONT format;
	loadimage(&FlightDetail, _T(".\\IMAGES\\FlightDetail.png"), 680, 40);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	settextstyle(20, 0, FONT);
	char carrier[20];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char Flyday[50];
	MatchCarrier(ID[i].Carrier, carrier);
	MatchPlaneImage(plane, ID[i].AircraftType);
	MatchPlaneType(ID[i].AircraftType, AircraftType);
	MatchAirport(ID[i].DepartureAirport, DepartureAirport);
	MatchAirport(ID[i].ArrivalAirport, ArrivalAirport);
	MatchFlyDay(ID[i].FlyDay, Flyday);
	putimage(1280 - 60 - 240, 200, &plane);						//飞机图片
	char IntChange[8];
	//信息输出以25px为行距
	outtextxy(380, 200, "航班号：");
	outtextxy(520, 200, ID[i].Carrier);
	outtextxy(540, 200, ID[i].ID);
	outtextxy(380, 225, "执飞航司：");
	outtextxy(520, 225, carrier);
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(520, 250, "一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(380, 250, "开航日期：");
	outtextxy(520, 250, Flyday);
	outtextxy(380, 275, "基准票价：");
	outtextxy(520, 275, _itoa(ID[i].Price, IntChange, 10));
	outtextxy(380, 300, "舱位：");
	outtextxy(520, 300, ID[i].Class);
	outtextxy(380, 325, "机型：");
	outtextxy(520, 325, AircraftType);							//飞机型号
	//飞行信息展示
	outtextxy(380, 400, "起降机场：");
	outtextxy(380, 425, "IATA代码：");
	outtextxy(380, 450, "起降时间：");
	outtextxy(520, 400, DepartureAirport);
	outtextxy(520, 425, ID[i].DepartureAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(520, 450, IntChange);
	outtextxy(580, 450, "预计");
	//航线飞机飞行小动画
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	int timer = 0;
	putimage(480, 360, &FlightDetail);							//航线示意图
	for (int i = 520; i < 1120; i += 3)
	{
		putimage(480, 360, &FlightDetail);						//航线示意图
		fillrectangle(i, 360, 1280, 400);
		Sleep((int)((timer - 300) * (timer - 300) / 10000));
		timer += 3;
	}
	putimage(480, 360, &FlightDetail);								//航线示意图
	//小动画到此结束
	outtextxy(1020, 400, ArrivalAirport);
	outtextxy(1020, 425, ID[i].ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(1020, 450, IntChange);
	outtextxy(1080, 450, "预计");
	//飞行时间
	outtextxy(790, 420, "飞行时长");
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeHour);
	outtextxy(770, 440, IntChange);
	outtextxy(790, 440, "小时");
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeMinute);
	outtextxy(835, 440, IntChange);
	outtextxy(860, 440, "分钟");
	return;
}
//打印单个航线（航线数据数组，需要打印航班的数组下标）
int PrintSingleFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i)
{
	cleardevice();
	IMAGE BG;
	IMAGE TimeAccuracy;
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	loadimage(&TimeAccuracy, _T(".\\IMAGES\\TimeAccuracy.png"), 200, 40);
	putimage(0, 0, &BG);						//显示背景
	putimage(100, 550, &TimeAccuracy);			//查询正晚点图片
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextstyle(20, 0, FONT);
	outtextxy(380, 170, "共找到一个航班");
	PrintFlightDetail(ID, DATA, IDcount, i);
	PrintTimeAccuracyBar(ID, DATA, i);
	int MENUchoice = AdminMENU_SearchMENU_SingleFlight_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 11:
		case 12:
		case 13:
		case 14:
			return MENUchoice;
		case 17:
			MENUchoice = PrintTicket(ID, DATA, i);
			break;
		case 18:
			return PrintSingleFlight(ID, DATA, IDcount, i);
		}
	}
}
//按页打印多个航线（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数）
int PrintMultiFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount)//返回菜单选择
{
	cleardevice();
	IMAGE BG;
	IMAGE PageChoiceImage;
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(0, 0, &BG);									//显示背景
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);		//上下页图片
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextstyle(20, 0, FONT);
	char IntChange[8];
	int Page = (SearchCount - 1) / 15 + 1;
	int CurrentPage = 1;
	outtextxy(380, 170, "共找到");
	_stprintf(IntChange, _T("%d"), SearchCount);
	outtextxy(450, 170, IntChange);
	outtextxy(485, 170, "个航班");
	PrintFlightTitle();
	PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
	int MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 11:
		case 12:
		case 13:
		case 14:
			return MENUchoice;
		case 15:					//上一页
			if (CurrentPage == 1)
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage--;
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 16:					//下一页
			if (CurrentPage == Page)
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage++;
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 18:					//按下了返回键，也就是还显示上一次的界面
			clearrectangle(1070, 165, 1220, 200);	//开始前把返回区域清空
			clearrectangle(380, 200, 1220, 720);	//开始前把显示区域清空
			PrintFlightTitle();
			PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 19:					//按起飞时间排序
			int SortReasult[999];												//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。
			SortByDepartureTime(ID, SearchReasult, SearchCount, SortReasult);	//冒泡排序法按照时间排序搜索航班结果；注意此函数有重载
			return PrintMultiFlight(ID, DATA, IDcount, SortReasult, SearchCount);
		case 101:
		case 102:
		case 103:
		case 104:
		case 105:
		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
		case 114:
		case 115:						//跳转到详情页面
			//首先判断该页的航班数量
			int Count = (CurrentPage - 1) * 15;//count表示之前页数总计的航班数，即本页航班应该从count+1的下标开始
			if ((MENUchoice % 100 + Count) <= SearchCount)
			{
				cleardevice();
				IMAGE Back;
				IMAGE TimeAccuracy;
				loadimage(&TimeAccuracy, _T(".\\IMAGES\\TimeAccuracy.png"), 200, 40);
				loadimage(&Back, _T(".\\IMAGES\\Back.png"), 30, 30);
				putimage(0, 0, &BG);										//显示背景
				putimage(1280 - 60 - 30, 165, &Back);						//返回键图片
				putimage(100, 550, &TimeAccuracy);							//查询正晚点图片
				settextstyle(25, 0, FONT);
				outtextxy(110, 200, "当前数据库中有");
				outtextxy(110, 230, count);
				outtextxy(162, 230, "个航线数据");
				settextstyle(20, 0, FONT);
				outtextxy(380, 170, "共找到");
				outtextxy(450, 170, IntChange);
				outtextxy(485, 170, "个航班");
				PrintFlightDetail(ID, DATA, IDcount, SearchReasult[MENUchoice % 100 + Count - 1]);
				PrintTimeAccuracyBar(ID, DATA, SearchReasult[MENUchoice % 100 + Count - 1]);
				int MenuCloice;
				MenuCloice = AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();
				if (MenuCloice == 17)
				{
					MenuCloice = PrintTicket(ID, DATA, SearchReasult[MENUchoice % 100 + Count - 1]);
					if (MenuCloice == 18)
						break;
				}
				MENUchoice = MenuCloice;
			}
			else
				MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		}
	}
}
//按页打印时的表格表头（）
void PrintFlightTitle()
{
	outtextxy(380, 200, "航班号");
	outtextxy(460, 200, "起飞时间");
	outtextxy(620, 200, "起飞机场");
	outtextxy(820, 200, "降落机场");
	outtextxy(980, 200, "降落时间");
	outtextxy(1080, 200, "机型");
	outtextxy(1140, 200, "飞行时间");
	return;
}
//按页打印时的打印一页航线数据（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数，当前页数，总页数）
void PrintMultiFlightPage(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page)//page表示当前显示第几页
{
	cleardevice();
	IMAGE BG;
	IMAGE PageChoiceImage;
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextstyle(20, 0, FONT);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//上下页图片
	char IntChange[8];
	outtextxy(380, 170, "共找到");
	_stprintf(IntChange, _T("%d"), SearchCount);
	outtextxy(450, 170, IntChange);
	outtextxy(485, 170, "个航班");
	PrintFlightTitle();
	_stprintf(IntChange, _T("%d"), CurrentPage);
	outtextxy(1280 - 60 - 120, 170, IntChange);
	outtextxy(1280 - 60 - 95, 170, "/");
	_stprintf(IntChange, _T("%d"), Page);
	outtextxy(1280 - 60 - 80, 170, IntChange);
	outtextxy(1280 - 60 - 55, 170, "页");
	int Count = (CurrentPage - 1) * 15;//count表示之前页数总计的航班数，即本页航班应该从count+1的下标开始
	for (int i = 0; i < 15; i++)//i用来计算行数
	{
		if ((i + Count) >= SearchCount)
			break;
		PrintSingleLineFlight(ID, DATA, IDcount, SearchReasult[Count + i], 230 + 30 * i);
	}
	return;
}
//打印单个航线的详细信息:一行（航线数据数组，航线数据计数，需要打印航班的数组下标，行数:x位置）
void PrintSingleLineFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i, int roll)
{
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char IntChange[5];
	MatchAirport(ID[i].DepartureAirport, DepartureAirport);
	MatchAirport(ID[i].ArrivalAirport, ArrivalAirport);
	outtextxy(390, roll, ID[i].Carrier);
	outtextxy(410, roll, ID[i].ID);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(480, roll, IntChange);
	outtextxy(570, roll, DepartureAirport);
	outtextxy(780, roll, ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(1000, roll, IntChange);
	outtextxy(1090, roll, ID[i].AircraftType);
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeHour);
	outtextxy(1150, roll, IntChange);
	outtextxy(1170, roll, "h");
	_stprintf(IntChange, _T("%02d"), ID[i].TravelTimeMinute);
	outtextxy(1180, roll, IntChange);
	outtextxy(1200, roll, "m");
	return;
}
//在详情页下方打印近期正晚点情况
void PrintTimeAccuracyBar(FlightID* ID, FlightTicket DATA[][999], int n)
{
	clearrectangle(380, 500, 1220, 650);		//开始前把显示区域清空
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char IntChange[8];
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	int yday = Local->tm_yday;
	int wday = Local->tm_wday;
	int year = Local->tm_year + 1900;
	if (wday == 0)
		wday = 7;
	int Fly[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//获取最近的10次飞行
	for (int i = 0; ; )
	{
		if (yday == -1)//如果到一年的开头，就不在往前找了（本程序只考虑本年的数据）
			break;
		if (ID[n].FlyDay[wday] != '0')
		{
			Fly[i] = yday;
			i++;
		}
		yday--;
		if (wday == 1)//再往前是星期日不是星期零
			wday = 7;
		else
			wday--;
		if (i > 9)
			break;
	}
	outtextxy(410, 500, "日期");
	outtextxy(520, 500, "起飞");
	outtextxy(580, 500, "到达");
	outtextxy(680, 500, "状态");
	outtextxy(830, 500, "日期");
	outtextxy(940, 500, "起飞");
	outtextxy(1000, 500, "到达");
	outtextxy(1100, 500, "状态");
	char Date[20];
	char Accuracy[20];
	COLORREF TextColor;
	for (int i = 0; i < 5; i++)
	{
		if (Fly[i] == -1)
			break;
		MatchDate(year, Fly[i], Date);
		outtextxy(380, 525 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i]][n].ActuralDepartureTime);
		outtextxy(520, 525 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i]][n].ActuralArrivalTime);
		outtextxy(580, 525 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[i], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(660, 525 + 25 * i, Accuracy);
		settextcolor(BLACK);
	}
	for (int i = 0; i < 5; i++)
	{
		if (Fly[i + 5] == -1)
			break;
		MatchDate(year, Fly[i + 5], Date);
		outtextxy(800, 525 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i + 5]][n].ActuralDepartureTime);
		outtextxy(940, 525 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i + 5]][n].ActuralArrivalTime);
		outtextxy(1000, 525 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[i + 5], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(1080, 525 + 25 * i, Accuracy);
		settextcolor(BLACK);
	}
}
//打印机票页标题栏
void PrintTicketTitle()
{
	outtextxy(90, 200, "日期");
	outtextxy(180, 200, "起飞");
	outtextxy(240, 200, "到达");
	outtextxy(320, 200, "状态");
	outtextxy(405, 200, "头等");
	outtextxy(475, 200, "商务");
	outtextxy(555, 200, "经济");
	outtextxy(90 + 610, 200, "日期");
	outtextxy(180 + 610, 200, "起飞");
	outtextxy(240 + 610, 200, "到达");
	outtextxy(320 + 610, 200, "状态");
	outtextxy(405 + 610, 200, "头等");
	outtextxy(475 + 610, 200, "商务");
	outtextxy(555 + 610, 200, "经济");
}
//打印每日机票详细信息
int PrintTicket(FlightID* ID, FlightTicket DATA[][999], int n)
{
	cleardevice();
	IMAGE BG;									//背景图片
	IMAGE PageChoiceImage;
	IMAGE Back;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	loadimage(&Back, _T(".\\IMAGES\\Back.png"), 30, 30);
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(0, 0, &BG);						// 更新背景
	putimage(1280 - 60 - 200, 165, &Back);		//返回键图片
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);
	outtextxy(60, 170, ID[n].Carrier);
	outtextxy(80, 170, ID[n].ID);
	char IntChange[8];
	outtextxy(160, 170, ID[n].DepartureAirport);
	outtextxy(210, 170, "->");
	outtextxy(235, 170, ID[n].ArrivalAirport);
	outtextxy(310, 170, "时刻表:");
	_stprintf(IntChange, _T("%04d"), ID[n].DepartureTime);
	outtextxy(390, 170, IntChange);
	outtextxy(440, 170, "->");
	_stprintf(IntChange, _T("%04d"), ID[n].ArrivalTime);
	outtextxy(470, 170, IntChange);
	outtextxy(550, 170, ID[n].AircraftType);
	time_t NOW;									//获取当前时间
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	int ydayNOW = Local->tm_yday;
	int year = Local->tm_year + 1900;//今年是哪年
	int Fly[366] = { 0 };//获取飞行日期
	int FlyDayCountCurrent = 0;//从今年开始到现在的飞行日数
	int FlyDayCountAll = 0;//今年的总飞行日数
	int wday = WeekDayTransfer(year, 1, 1);//计算今年第一天是周几
	int ydayCount;
	if (year % 4 == 0 && year % 100 != 0)
		ydayCount = 366;
	else
		ydayCount = 365;
	for (int yday = 0; yday < ydayCount; yday++)//本程序只考虑本年度的数据
	{
		if (ID[n].FlyDay[wday] != '0')
		{
			Fly[FlyDayCountAll] = yday;
			FlyDayCountAll++;				//年度总飞行日加一
			if (yday <= ydayNOW)
				FlyDayCountCurrent++;		//截止今天的飞行日加一
		}
		if (wday == 7)//星期日的下一天不是星期零
			wday = 1;
		else
			wday++;
	}
	int Page = (FlyDayCountAll - 1) / 36 + 1;
	//为什么要加一呢，你想想万一正好有36个
	//默认从今天开始显示
	int CurrentPage = (FlyDayCountCurrent - 1) / 36 + 1;
	PrintTicketTitle();
	PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
	int MENUchoice = AdminMENU_Ticket_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 11:
		case 12:
		case 13:
		case 14:
		case 18:
			return MENUchoice;
		case 15:					//上一页
			if (CurrentPage == 1)
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			else
			{
				CurrentPage--;
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		case 16:					//下一页
			if (CurrentPage == Page)
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			else
			{
				CurrentPage++;
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		case 101:
		case 102:
		case 103:
		case 104:
		case 105:
		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
		case 114:
		case 115:
		case 116:
		case 117:
		case 118:									//更改起飞时间
		{
			char Input[8];
			int i = MENUchoice % 100 - 1;
			int Count = (CurrentPage - 1) * 36 + i;
			if (Count < FlyDayCountAll)
			{
				C_InputBox(Input, 4, 180, 230 + 25 * i, 40, 20, "0000");
				sscanf(Input, "%4d", &DATA[Fly[Count]][n].ActuralDepartureTime);
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		}
		case 201:
		case 202:
		case 203:
		case 204:
		case 205:
		case 206:
		case 207:
		case 208:
		case 209:
		case 210:
		case 211:
		case 212:
		case 213:
		case 214:
		case 215:
		case 216:
		case 217:
		case 218:									//更改降落时间
		{
			char Input[8];
			int i = MENUchoice % 100 - 1;
			int Count = (CurrentPage - 1) * 36 + i;
			if (Count < FlyDayCountAll)
			{
				C_InputBox(Input, 4, 240, 230 + 25 * i, 40, 20, "0000");
				sscanf(Input, "%4d", &DATA[Fly[Count]][n].ActuralArrivalTime);
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		}
		case 301:
		case 302:
		case 303:
		case 304:
		case 305:
		case 306:
		case 307:
		case 308:
		case 309:
		case 310:
		case 311:
		case 312:
		case 313:
		case 314:
		case 315:
		case 316:
		case 317:
		case 318:									//更改起飞时间
		{
			char Input[8];
			int i = MENUchoice % 100 - 1;
			int Count = (CurrentPage - 1) * 36 + 18 + i;
			if (Count < FlyDayCountAll)
			{
				C_InputBox(Input, 4, 180 + 610, 230 + 25 * i, 40, 20, "0000");
				sscanf(Input, "%4d", &DATA[Fly[Count]][n].ActuralDepartureTime);
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		}
		case 401:
		case 402:
		case 403:
		case 404:
		case 405:
		case 406:
		case 407:
		case 408:
		case 409:
		case 410:
		case 411:
		case 412:
		case 413:
		case 414:
		case 415:
		case 416:
		case 417:
		case 418:									//更改降落时间
		{
			char Input[8];
			int i = MENUchoice % 100 - 1;
			int Count = (CurrentPage - 1) * 36 + 18 + i;
			if (Count < FlyDayCountAll)
			{
				C_InputBox(Input, 4, 240 + 610, 230 + 25 * i, 40, 20, "0000");
				sscanf(Input, "%4d", &DATA[Fly[Count]][n].ActuralArrivalTime);
				PrintTicketPage(ID, DATA, Fly, n, Page, CurrentPage, FlyDayCountAll);
			}
			MENUchoice = AdminMENU_Ticket_MENUChoose();
			break;
		}
		}
	}
}
//打印每日机票详细信息:整页
void PrintTicketPage(FlightID* ID, FlightTicket DATA[][999], int* Fly, int n, int Page, int CurrentPage, int FlyDayCountAll)
{
	clearrectangle(60, 230, 1220, 720);//开始前把显示区域清空
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//上下页图片
	char IntChange[8];
	_stprintf(IntChange, _T("%d"), CurrentPage);
	outtextxy(1280 - 60 - 120, 170, IntChange);
	outtextxy(1280 - 60 - 95, 170, "/");
	_stprintf(IntChange, _T("%d"), Page);
	outtextxy(1280 - 60 - 80, 170, IntChange);
	outtextxy(1280 - 60 - 55, 170, "页");
	char Date[20];
	char Accuracy[20];
	COLORREF TextColor;
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	int year = Local->tm_year + 1900;
	int Count = (CurrentPage - 1) * 36;
	for (int i = 0; i < 18; i++)
	{
		if (Count == FlyDayCountAll)
			break;
		MatchDate(year, Fly[Count], Date);
		outtextxy(60, 230 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[Count]][n].ActuralDepartureTime);
		outtextxy(180, 230 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[Count]][n].ActuralArrivalTime);
		outtextxy(240, 230 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[Count], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(300, 230 + 25 * i, Accuracy);
		settextcolor(BLACK);
		_stprintf(IntChange, _T("%2d"), DATA[Fly[Count]][n].FirstClassTicketRemain);
		outtextxy(400, 230 + 25 * i, IntChange);
		if (JudgeAircraftSize(ID, n) == 2)
		{
			outtextxy(420, 230 + 25 * i, "/6");
		}
		else
		{
			outtextxy(420, 230 + 25 * i, "/8");
		}
		if (JudgeAircraftSize(ID, n) == 2)
		{
			_stprintf(IntChange, _T("%2d"), DATA[Fly[Count]][n].BusinessClassTicketRemain);
			outtextxy(470, 230 + 25 * i, IntChange);
			outtextxy(490, 230 + 25 * i, "/36");
		}
		else
		{
			outtextxy(470, 230 + 25 * i, " N/A");
		}
		_stprintf(IntChange, _T("%3d"), DATA[Fly[Count]][n].EconomyClassTicketRemain);
		outtextxy(540, 230 + 25 * i, IntChange);
		if (JudgeAircraftSize(ID, n) == 2)
		{
			outtextxy(570, 230 + 25 * i, "/400");
		}
		else
		{
			outtextxy(570, 230 + 25 * i, "/180");
		}
		Count++;
	}
	for (int i = 0; i < 18; i++)
	{
		if (Count == FlyDayCountAll)
			break;
		MatchDate(year, Fly[Count], Date);
		outtextxy(60 + 610, 230 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[Count]][n].ActuralDepartureTime);
		outtextxy(180 + 610, 230 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[Count]][n].ActuralArrivalTime);
		outtextxy(240 + 610, 230 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[Count], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(300 + 610, 230 + 25 * i, Accuracy);
		settextcolor(BLACK);
		_stprintf(IntChange, _T("%2d"), DATA[Fly[Count]][n].FirstClassTicketRemain);
		outtextxy(400 + 610, 230 + 25 * i, IntChange);
		if (JudgeAircraftSize(ID, n) == 2)
		{
			outtextxy(420 + 610, 230 + 25 * i, "/6");
		}
		else
		{
			outtextxy(420 + 610, 230 + 25 * i, "/8");
		}
		if (JudgeAircraftSize(ID, n) == 2)
		{
			_stprintf(IntChange, _T("%2d"), DATA[Fly[Count]][n].BusinessClassTicketRemain);
			outtextxy(470 + 610, 230 + 25 * i, IntChange);
			outtextxy(490 + 610, 230 + 25 * i, "/36");
		}
		else
		{
			outtextxy(470 + 610, 230 + 25 * i, " N/A");
		}
		_stprintf(IntChange, _T("%3d"), DATA[Fly[Count]][n].EconomyClassTicketRemain);
		outtextxy(540 + 610, 230 + 25 * i, IntChange);
		if (JudgeAircraftSize(ID, n) == 2)
		{
			outtextxy(570 + 610, 230 + 25 * i, "/400");
		}
		else
		{
			outtextxy(570 + 610, 230 + 25 * i, "/180");
		}
		Count++;
	}
	return;
}
//打印背景
void PrintBG(int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}
//打印主页背景
void PrintHomeBG(int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Home.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}
//打印搜索页背景
void PrintSearchBG(int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}
//打印删除页背景
void PrintDeleteBG(int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Delete.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	char count[8];
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}