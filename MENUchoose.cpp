#include"MENUchoose.h"
int AdminMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
		}
	}
}
int AdminMENU_MainMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入航线数据库区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导入机票数据库区域
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在导出航线数据库区域
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在导出机票数据库区域
				return 54;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//鼠标按在退出并保存区域
				return 61;
			if (m.x > 100 && m.y > 600 && m.x < 300 && m.y < 640)//鼠标按在直接退出区域
				return 62;
		}
	}
}
int AdminMENU_MainMENU_Import_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入航线数据库区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导入机票数据库区域
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在导出航线数据库区域
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在导出机票数据库区域
				return 54;
			if (m.x > 400 && m.y > 300 && m.x < 550 && m.y < 390)//鼠标按在确认导入区域
				return 57;
			if (m.x > 550 && m.y > 300 && m.x < 700 && m.y < 390)//鼠标按在取消导入区域
				return 58;
			if (m.x > 700 && m.y > 300 && m.x < 850 && m.y < 390)//鼠标按在修改路径区域
				return 59;
		}
	}
}

int AdminMENU_SearchMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
		}
	}
}
int AdminMENU_SearchMENU_SingleFlight_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//鼠标按在正晚点查询区域
				return 17;
		}
	}
}
int AdminMENU_SearchMENU_MultiFlight_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//鼠标按在上一页区域
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在下一页区域
				return 16;
			if (m.x > 460 && m.y > 200 && m.x < 540 && m.y < 230)//鼠标按在起飞时间区域（排序）
				return 19;
			for (int i = 0; i < 15; i++)//i用来计算行数
			{
				if (m.x > 380 && m.y > 230 + 30 * i && m.x < 1220 && m.y < 260 + 30 * i)//鼠标按在具体航班区域
					return i + 101;
			}
		}
	}
}
int AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//鼠标按在正晚点查询区域
				return 17;
		}
	}
}

int AdminMENU_DeleteMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在删除区域
				return 31;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在取消区域
				return 32;
		}
	}
}

int AdminMENU_AddMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.x > A_LEFT_LINE_START && m.y > 100 && m.x < A_LEFT_LINE_END && m.y < 125)//鼠标按在更改航班号区域
				return 201;
			if (m.x > A_LEFT_LINE_START + 20 && m.y > 125 && m.x < A_LEFT_LINE_START + 40 && m.y < 150)//鼠标按在开航日期周一区域
				return 2031;
			if (m.x > A_LEFT_LINE_START + 60 && m.y > 125 && m.x < A_LEFT_LINE_START + 80 && m.y < 150)//鼠标按在开航日期周二区域
				return 2032;
			if (m.x > A_LEFT_LINE_START + 100 && m.y > 125 && m.x < A_LEFT_LINE_START + 120 && m.y < 150)//鼠标按在开航日期周三区域
				return 2033;
			if (m.x > A_LEFT_LINE_START + 140 && m.y > 125 && m.x < A_LEFT_LINE_START + 160 && m.y < 150)//鼠标按在开航日期周四区域
				return 2034;
			if (m.x > A_LEFT_LINE_START + 180 && m.y > 125 && m.x < A_LEFT_LINE_START + 200 && m.y < 150)//鼠标按在开航日期周五区域
				return 2035;
			if (m.x > A_LEFT_LINE_START + 220 && m.y > 125 && m.x < A_LEFT_LINE_START + 240 && m.y < 150)//鼠标按在开航日期周六区域
				return 2036;
			if (m.x > A_LEFT_LINE_START + 260 && m.y > 125 && m.x < A_LEFT_LINE_START + 280 && m.y < 150)//鼠标按在开航日期周日区域
				return 2037;
			if (m.x > A_LEFT_LINE_START && m.y > 150 && m.x < A_LEFT_LINE_END && m.y < 175)//鼠标按在更改执飞机型区域
				return 204;
			if (m.x > A_LEFT_LINE_START && m.y > 175 && m.x < A_LEFT_LINE_END && m.y < 200)//鼠标按在更改起飞机场区域
				return 205;
			if (m.x > A_LEFT_LINE_START && m.y > 200 && m.x < A_LEFT_LINE_END && m.y < 225)//鼠标按在更改起飞时间区域
				return 206;
			if (m.x > A_LEFT_LINE_START && m.y > 225 && m.x < A_LEFT_LINE_END && m.y < 250)//鼠标按在更改降落机场区域
				return 207;
			if (m.x > A_LEFT_LINE_START && m.y > 250 && m.x < A_LEFT_LINE_END && m.y < 275)//鼠标按在更改降落时间区域
				return 208;
			if (m.x > A_LEFT_LINE_START && m.y > 275 && m.x < A_LEFT_LINE_START + 50 && m.y < 300)//鼠标按在更改飞行小时区域
				return 2091;
			if (m.x > A_RIGHT_TEXT_START && m.y > 275 && m.x < A_RIGHT_TEXT_START + 50 && m.y < 300)//鼠标按在更改飞行分钟区域
				return 2092;
			if (m.x > A_LEFT_LINE_START && m.y > 325 && m.x < A_LEFT_LINE_END && m.y < 350)//鼠标按在更改基本舱位区域
				return 211;
			if (m.x > 60 && m.y > 400 && m.x < 240 && m.y < 440)//鼠标按在确认添加区域
				return 21;
			if (m.x > 240 && m.y > 400 && m.x < 420 && m.y < 440)//鼠标按在取消添加区域
				return 22;
		}
	}
}

int AdminMENU_ChangeMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
		}
	}
}

int AdminMENU_Ticket_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//鼠标按在上一页区域
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在下一页区域
				return 16;
			if (m.x > 1020 && m.y > 165 && m.x < 1050 && m.y < 195)//鼠标按在返回区域
				return 18;
			for (int i = 0; i < 18; i++)//i用来计算行数，鼠标按在第一列的起飞时间
			{
				if (m.x > 180 && m.y > 230 + 25 * i && m.x < 220 && m.y < 260 + 25 * i)//鼠标按在具体日期
					return i + 101;
			}
			for (int i = 0; i < 18; i++)//i用来计算行数，鼠标按在第一列的降落时间
			{
				if (m.x > 240 && m.y > 230 + 25 * i && m.x < 280 && m.y < 260 + 25 * i)//鼠标按在具体日期
					return i + 201;
			}
			for (int i = 0; i < 18; i++)//i用来计算行数，鼠标按在第二列的起飞时间
			{
				if (m.x > 180 + 610 && m.y > 230 + 25 * i && m.x < 220 + 610 && m.y < 260 + 25 * i)//鼠标按在具体日期
					return i + 301;
			}
			for (int i = 0; i < 18; i++)//i用来计算行数，鼠标按在第二列的降落时间
			{
				if (m.x > 240 + 610 && m.y > 230 + 25 * i && m.x < 280 + 610 && m.y < 260 + 25 * i)//鼠标按在具体日期
					return i + 401;
			}
		}
	}
}

int StartMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 280 && m.y < 340 && m.x>470 && m.x < 810)//鼠标按在输入账号区域
				return 1;
			if (m.y > 380 && m.y < 440 && m.x>470 && m.x < 810)//鼠标按在输入密码区域
				return 2;
			if (m.y > 460 && m.y < 500 && m.x>470 && m.x < 620)//鼠标按在普通用户注册区域
				return 3;
			if (m.y > 460 && m.y < 500 && m.x>660 && m.x < 810)//鼠标按在管理员用户注册区域
				return 4;
		}
	}
}
int StartMENU_Register_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 230 && m.y < 290 && m.x>470 && m.x < 810)//鼠标按在输入账号区域
				return 1;
			if (m.y > 300 && m.y < 360 && m.x>470 && m.x < 810)//鼠标按在输入密码区域
				return 2;
			if (m.y > 370 && m.y < 430 && m.x>470 && m.x < 810)//鼠标按在确认密码区域
				return 3;
			if (m.y > 440 && m.y < 500 && m.x>470 && m.x < 810)//鼠标按在输入手机区域
				return 4;
			if (m.y > 510 && m.y < 550 && m.x>470 && m.x < 620)//鼠标按在注册区域
				return 5;
			if (m.y > 510 && m.y < 550 && m.x>660 && m.x < 810)//鼠标按在取消区域
				return 6;
		}
	}
}
int StartMENU_AdminRegister_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 230 && m.y < 290 && m.x>470 && m.x < 810)//鼠标按在输入账号区域
				return 1;
			if (m.y > 300 && m.y < 360 && m.x>470 && m.x < 810)//鼠标按在输入密码区域
				return 2;
			if (m.y > 370 && m.y < 430 && m.x>470 && m.x < 810)//鼠标按在确认密码区域
				return 3;
			if (m.y > 440 && m.y < 500 && m.x>470 && m.x < 810)//鼠标按在输入邀请码区域
				return 4;
			if (m.y > 510 && m.y < 550 && m.x>470 && m.x < 620)//鼠标按在注册区域
				return 5;
			if (m.y > 510 && m.y < 550 && m.x>660 && m.x < 810)//鼠标按在取消区域
				return 6;
		}
	}
}

int CustomMENU_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在退票、改签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
		}
	}
}
int CAdminMENU_SearchMENU_MultiFlight_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在改退签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//鼠标按在上一页区域
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在下一页区域
				return 16;
			if (m.x > 460 && m.y > 200 && m.x < 540 && m.y < 230)//鼠标按在起飞时间区域（排序）
				return 19;
			for (int i = 0; i < 15; i++)//i用来计算行数
			{
				if (m.x > 380 && m.y > 230 + 30 * i && m.x < 1220 && m.y < 260 + 30 * i)//鼠标按在具体航班区域
					return i + 101;
			}
		}
	}

}
int CAdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在退票、改签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
		}
	}
}
int CAdminMENU_BOOKINGMENU_MultiFlight_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在改退签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//鼠标按在上一页区域
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在下一页区域
				return 16;
			if (m.x > 460 && m.y > 200 && m.x < 540 && m.y < 230)//鼠标按在起飞时间区域（排序）
				return 19;
			for (int i = 0; i < 15; i++)//i用来计算行数
			{
				if (m.x > 380 && m.y > 230 + 30 * i && m.x < 1160 && m.y < 260 + 30 * i)//鼠标按在具体航班区域
					return i + 101;
			}
		}
	}
}
int CAdminMENU_ReMENU_MultiFlight_FlightDetail_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在改退签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
			if (m.x > 400 && m.y > 600 && m.x < 500 && m.y < 650)//鼠标按在退票区域
				return 28;
			if (m.x > 800 && m.y > 600 && m.x < 900 && m.y < 650)//鼠标按在改签区域
				return 29;
		}
	}
}
int CAdminMENU_BookingMENU_MultiFlight_FlightDetail_MENUChoose()
{

	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在改退签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
			if (m.x > 500 && m.y > 600 && m.x < 600 && m.y < 655)//鼠标按在订票区域
				return 28;
		}
	}
}
int CAdminMENU_BookingMENU_MultiFlight_Passenger_MENUChoose()
{

	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在改退签区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 4;
			if (m.x > 500 && m.y > 600 && m.x < 600 && m.y < 655)//鼠标按在订票确认区域
				return 28;
			if (m.x > 700 && m.y > 600 && m.x < 800 && m.y < 655)//鼠标按在取消区域
				return 29;

		}
	}
}
int CustomMENU_HomeMENU_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 500 && m.y < 550 && m.x>400 && m.x < 450)//鼠标按在加号上
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 6;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 7;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在退票、改签区域
				return 8;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 9;
			if (m.y > 200 && m.y < 380 && m.x>60 && m.x < 240)//按在修改头像上
				return 12;
			if (m.y > 500 && m.y < 550 && m.x>520 && m.x < 570)//鼠标按在减号上
				return 10;
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 11;
		}
	}
}
int CustomMENU_AddPassenger_MENUChoose()
{
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 250 && m.y < 290 && m.x>530 && m.x < 800)//鼠标姓名上
				return 2;
			if (m.y > 320 && m.y < 360 && m.x>530 && m.x < 800)//鼠标按在身份证号上
				return 3;
			if (m.y > 390 && m.y < 430 && m.x>530 && m.x < 800)//鼠标按在电话号码上
				return 4;
			if (m.y > 600 && m.y < 640 && m.x>600 && m.x < 690)//鼠标按在添加上
				return 5;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在订单区域
				return 6;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在订票区域
				return 7;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在退票、改签区域
				return 8;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在退出登录区域
				return 9;
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 11;
		}
	}
}
int SignOutMenu_MENUChooce()
{
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	clearrectangle(300, 230, 1280, 720);//开始前把显示区域清空
	outtextxy(400, 320, "您确定要退出本退票系统吗？？");
	IMAGE confirm, cancel;
	loadimage(&confirm, _T(".\\IMAGES\\choose.png"), 0, 0);
	loadimage(&cancel, _T(".\\IMAGES\\cancel.png"), 0, 0);
	putimage(500, 600, &confirm);
	putimage(700, 600, &cancel);
	while (true)
	{
		FlushMouseMsgBuffer();
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 600 && m.y < 650 && m.x>500 && m.x < 600)//确认
				return 1;
			if (m.y > 600 && m.y < 650 && m.x>700 && m.x < 800)//取消
				return 2;
		}
	}
}