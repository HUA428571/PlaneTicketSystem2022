#include"StartMENU.h"
int StartMENU(USER u[999], Passenger p[999])
{
	initgraph(1280, 720);	// 创建绘图窗口，大小为 1280x720 像素
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	// 设置背景色为淡白色
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 30;						// 设置字体高度为30
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// 设置字体为FONT2_EN
	settextstyle(&format);						// 设置字体样式
	IMAGE BG;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1280, 720);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 340, 60);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 340, 60);
	putimage(0, 0, &BG);
	//以上都是常规代码
	char UserName[50];
	char UserNameCheck = 0;
	char PassWord[50];
	int MENUchoice;
	MENUchoice = StartMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
		{
			putimage(0, 0, &BG);
			putimage(470, 280, &UserNameBox);
			CR_InputBox(UserName, 40, 530, 290, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 330, 800, 330);
			UserNameCheck = 1;
			MENUchoice = StartMENU_MENUChoose();
			break;
		}
		case 2:
		{
			putimage(470, 380, &PassWordBox);
			CHR_InputBox(PassWord, 40, 530, 390, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 430, 800, 430);
			if (UserNameCheck == 0)
			{
				MENUchoice = StartMENU_MENUChoose();
			}
			else
			{
				int temp;
				temp = CheckID(UserName, PassWord, u);
				if (temp >= 0)
					return temp;
				else
				{
					putimage(470, 280, &UserNameWrong);
					putimage(470, 380, &PassWordWrong);
					UserNameCheck = 0;
					MENUchoice = StartMENU_MENUChoose();
				}
			}
			break;
		}
		case 3:
		{
			int tmp = StartMENU_RegisterMENU(u, p);
			ImportUserDatabase(u, p);
			putimage(0, 0, &BG);
			MENUchoice = StartMENU_MENUChoose();
			break;
		}
		case 4:
		{
			int tmp = StartMenu_AdminRegisterMENU(u, p);
			ImportUserDatabase(u, p);
			putimage(0, 0, &BG);
			MENUchoice = StartMENU_MENUChoose();
			break;
		}
		}
	}
}
int CheckID(char* n, char* m, USER u[999])
{
	USER temp;
	int count = 0;
	while (count < 999)
	{
		temp = u[count];
		if (strcmp(temp.id, n) == 0)
		{
			if (strcmp(temp.pwd, m) == 0)
			{
				if (temp.Identity == '1')
					return 0;
				if (temp.Identity == '0')
					return count;
			}
			else
				return -1;
		}
		else
			count++;
	}
	return -1;
}
int StartMENU_RegisterMENU(USER u[999], Passenger p[999])
{
	USER temp;
	int count = 0;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE TELBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	IMAGE TELWrong;
	IMAGE BG_Register;
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&TELBox, _T(".\\IMAGES\\TELBox.png"), 340, 60);
	loadimage(&BG_Register, _T(".\\IMAGES\\Register.png"), 1280, 720);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 340, 60);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 340, 60);
	loadimage(&TELWrong, _T(".\\IMAGES\\TELWrong.png"), 340, 60);
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	char PassWord0[50] = "\0";
	char Telephone[50] = "\0";
	putimage(0, 0, &BG_Register);
	int MENUchoice_Register = StartMENU_Register_MENUChoose();
	while (true)
	{
		switch (MENUchoice_Register)
		{
		case 1:
			putimage(470, 230, &UserNameBox);
			CR_InputBox(UserName, 40, 530, 240, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 280, 800, 280);
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 2:
			putimage(470, 300, &PassWordBox);
			CHR_InputBox(PassWord, 40, 530, 310, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 350, 800, 350);
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 3:
			putimage(470, 370, &PassWordBox);
			CHR_InputBox(PassWord0, 40, 530, 380, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 420, 800, 420);
			if (strcmp(PassWord, PassWord0) != 0)
			{
				putimage(470, 370, &PassWordWrong);
			}
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 4:
			putimage(470, 440, &TELBox);
			CR_InputBox(Telephone, 40, 530, 450, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 490, 800, 490);
			if (strlen(Telephone) != 11)
			{
				putimage(470, 440, &TELWrong);
			}
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 5:
		{
			if (strlen(UserName) == 0)
			{
				putimage(470, 230, &UserNameWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(PassWord) == 0)
			{
				putimage(470, 300, &PassWordWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(PassWord0) == 0)
			{
				putimage(470, 370, &PassWordWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(Telephone) == 0)
			{
				putimage(470, 440, &TELWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			strcpy(temp.id, UserName);
			strcpy(temp.pwd, PassWord);
			strcpy(temp.phone, Telephone);
			temp.Identity = '0';
			FILE* fp;
			fp = fopen(".\\Data\\users.dat", "ab");
			fwrite(&temp, sizeof(USER), 1, fp);
			fclose(fp);
			settextcolor(RGB(30, 144, 255));
			settextstyle(30, 0, "黑体");
			outtextxy(690, 170, "注册成功！");
			Sleep(1000);
			return 1;
		}
		case 6:
			return -1;
		}
	}
}
int StartMenu_AdminRegisterMENU(USER u[999], Passenger p[999])
{
	USER temp;
	int count = 0;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE InvitationBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	IMAGE InvationWrong;
	IMAGE BG_AdminRegister;
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&InvitationBox, _T(".\\IMAGES\\InvitationBox.png"), 340, 60);
	loadimage(&BG_AdminRegister, _T(".\\IMAGES\\AdminRegister.png"), 1280, 720);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 340, 60);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 340, 60);
	loadimage(&InvationWrong, _T(".\\IMAGES\\InvitationWrong.png"), 340, 60);
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	char PassWord0[50] = "\0";
	char Invitation[50] = "\0";
	putimage(0, 0, &BG_AdminRegister);
	int MENUchoice_Register = StartMENU_AdminRegister_MENUChoose();
	while (1)
	{
		switch (MENUchoice_Register)
		{
		case 1:
			putimage(470, 230, &UserNameBox);
			CR_InputBox(UserName, 40, 530, 240, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 280, 800, 280);
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 2:
			putimage(470, 300, &PassWordBox);
			CHR_InputBox(PassWord, 40, 530, 310, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 350, 800, 350);
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 3:
			putimage(470, 370, &PassWordBox);
			CHR_InputBox(PassWord0, 40, 530, 380, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 420, 800, 420);
			if (strcmp(PassWord, PassWord0) != 0)
			{
				putimage(470, 370, &PassWordWrong);
			}
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 4:
			putimage(470, 440, &InvitationBox);
			CHR_InputBox(Invitation, 40, 530, 450, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 490, 800, 490);
			if (strcmp(Invitation, "B190303") != 0)
			{
				putimage(470, 440, &InvationWrong);
			}
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 5:
		{
			if (strlen(UserName) == 0)
			{
				putimage(470, 230, &UserNameWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(PassWord) == 0)
			{
				putimage(470, 300, &PassWordWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(PassWord0) == 0)
			{
				putimage(470, 370, &PassWordWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			if (strlen(Invitation) == 0)
			{
				putimage(470, 440, &InvationWrong);
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			strcpy(temp.id, UserName);
			strcpy(temp.pwd, PassWord);
			temp.Identity = '1';
			FILE* fp;
			fp = fopen(".\\Data\\users.dat", "ab");
			fwrite(&temp, sizeof(USER), 1, fp);
			fclose(fp);
			settextcolor(RGB(30, 144, 255));
			settextstyle(30, 0, "黑体");
			outtextxy(690, 170, "注册成功！");
			Sleep(500);
			return 1;
		}
		case 6:
		{
			return -1;
		}
		}
	}
}