#include"Match.h"
//和数据库匹配飞机图片
void MatchPlaneImage(IMAGE& plane, char* AircraftType)
{
	int type;
	sscanf(AircraftType, "%d", &type);
	switch (type)
	{
	case 737:
	case 738:
		loadimage(&plane, _T(".\\IMAGES\\plane\\737.jpg"), 219, 146);
		return;
	case 74:
	case 744:
	case 747:
		loadimage(&plane, _T(".\\IMAGES\\plane\\747.jpg"), 219, 146);
		return;
	case 76:
		loadimage(&plane, _T(".\\IMAGES\\plane\\767.jpg"), 219, 146);
		return;
	case 77:
	case 772:
	case 773:
	case 777:
		loadimage(&plane, _T(".\\IMAGES\\plane\\777.jpg"), 219, 146);
		return;
	case 788:
	case 789:
		loadimage(&plane, _T(".\\IMAGES\\plane\\787.jpg"), 219, 146);
		return;
	case 319:
	case 320:
	case 321:
		loadimage(&plane, _T(".\\IMAGES\\plane\\320.jpg"), 219, 146);
		return;
	case 330:
	case 333:
		loadimage(&plane, _T(".\\IMAGES\\plane\\330.jpg"), 219, 146);
		return;
	case 343:
		loadimage(&plane, _T(".\\IMAGES\\plane\\340.jpg"), 219, 146);
		return;
	default:
		loadimage(&plane, _T(".\\IMAGES\\plane\\default.png"), 219, 146);
		return;
	}
}
//和数据库匹配机型中文全称（输入字符串，输出字符串）
void MatchPlaneType(char* AircraftType, char* AIRCRAFTTYPE)
{
	int type;
	sscanf(AircraftType, "%d", &type);
	switch (type)
	{
	case 737:
	case 738:
		strcpy(AIRCRAFTTYPE, "波音B737系列飞机");
		return;
	case 74:
	case 744:
	case 747:
		strcpy(AIRCRAFTTYPE, "波音B747系列飞机");
		return;
	case 76:
		strcpy(AIRCRAFTTYPE, "波音B767系列飞机");
		return;
	case 77:
	case 772:
	case 773:
	case 777:
		strcpy(AIRCRAFTTYPE, "波音B777系列飞机");
		return;
	case 788:
	case 789:
		strcpy(AIRCRAFTTYPE, "波音B787系列飞机");
		return;
	case 319:
	case 320:
	case 321:
		strcpy(AIRCRAFTTYPE, "空中客车A320系列飞机");
		return;
	case 330:
	case 333:
		strcpy(AIRCRAFTTYPE, "空中客车A330系列飞机");
		return;
	case 343:
		strcpy(AIRCRAFTTYPE, "空中客车A340系列飞机");
		return;
	case 350:
		strcpy(AIRCRAFTTYPE, "空中客车A350系列飞机");
		return;
	case 380:
		strcpy(AIRCRAFTTYPE, "空中客车A380系列飞机");
		return;
	default:
		strcpy(AIRCRAFTTYPE, "没有找到机型数据");
		return;
	}
}
//和数据库匹配航空公司中文全称（输入字符串，输出字符串）
void MatchCarrier(char* carrier, char* CARRIER)
{
	if (!strcmp(carrier, "CA")) { strcpy(CARRIER, "中国国际航空公司"); return; }
	if (!strcmp(carrier, "CZ")) { strcpy(CARRIER, "中国南方航空公司"); return; }
	if (!strcmp(carrier, "PN")) { strcpy(CARRIER, "西部航空有限责任公司"); return; }
	if (!strcmp(carrier, "MU")) { strcpy(CARRIER, "中国东方航空公司"); return; }
	if (!strcmp(carrier, "MF")) { strcpy(CARRIER, "厦门航空公司"); return; }
	if (!strcmp(carrier, "SC")) { strcpy(CARRIER, "山东航空公司"); return; }
	if (!strcmp(carrier, "EU")) { strcpy(CARRIER, "成都航空公司"); return; }
	if (!strcmp(carrier, "FM")) { strcpy(CARRIER, "上海航空公司"); return; }
	if (!strcmp(carrier, "ZH")) { strcpy(CARRIER, "深圳航空公司"); return; }
	if (!strcmp(carrier, "X2")) { strcpy(CARRIER, "中国新华航空公司"); return; }
	if (!strcmp(carrier, "JR")) { strcpy(CARRIER, "幸福航空责任有限公司"); return; }
	if (!strcmp(carrier, "3Q")) { strcpy(CARRIER, "云南航空公司"); return; }
	if (!strcmp(carrier, "UQ")) { strcpy(CARRIER, "新疆航空公司"); return; }
	if (!strcmp(carrier, "3U")) { strcpy(CARRIER, "四川航空公司"); return; }
	if (!strcmp(carrier, "Z2")) { strcpy(CARRIER, "中原航空公司"); return; }
	if (!strcmp(carrier, "WU")) { strcpy(CARRIER, "武汉航空公司"); return; }
	if (!strcmp(carrier, "G4")) { strcpy(CARRIER, "贵州航空公司"); return; }
	if (!strcmp(carrier, "HU")) { strcpy(CARRIER, "海南航空公司"); return; }
	if (!strcmp(carrier, "GP")) { strcpy(CARRIER, "中国通用航空公司"); return; }
	if (!strcmp(carrier, "3W")) { strcpy(CARRIER, "南京航空公司"); return; }
	if (!strcmp(carrier, "ZJ")) { strcpy(CARRIER, "浙江航空公司"); return; }
	if (!strcmp(carrier, "G8")) { strcpy(CARRIER, "长城航空公司"); return; }
	if (!strcmp(carrier, "FJ")) { strcpy(CARRIER, "福建航空公司"); return; }
	if (!strcmp(carrier, "9H")) { strcpy(CARRIER, "长安航空公司"); return; }
	if (!strcmp(carrier, "GJ")) { strcpy(CARRIER, "浙江长龙航空公司"); return; }
	if (!strcmp(carrier, "JD")) { strcpy(CARRIER, "首都航空公司"); return; }
	if (!strcmp(carrier, "HO")) { strcpy(CARRIER, "上海吉祥航空公司"); return; }
	if (!strcmp(carrier, "9C")) { strcpy(CARRIER, "上海春秋航空公司"); return; }
	if (!strcmp(carrier, "GS")) { strcpy(CARRIER, "天津航空公司"); return; }
	if (!strcmp(carrier, "G5")) { strcpy(CARRIER, "华夏航空有限公司"); return; }
	if (!strcmp(carrier, "KA")) { strcpy(CARRIER, "港龙航空公司"); return; }
	if (!strcmp(carrier, "KE")) { strcpy(CARRIER, "大韩航空公司"); return; }
	if (!strcmp(carrier, "OZ")) { strcpy(CARRIER, "韩亚航空公司"); return; }
	if (!strcmp(carrier, "JL")) { strcpy(CARRIER, "日本航空公司"); return; }
	if (!strcmp(carrier, "NH")) { strcpy(CARRIER, "全日空公司"); return; }
	if (!strcmp(carrier, "SQ")) { strcpy(CARRIER, "新加坡航空公司"); return; }
	if (!strcmp(carrier, "TG")) { strcpy(CARRIER, "泰国国际航空公司"); return; }
	if (!strcmp(carrier, "NW")) { strcpy(CARRIER, "美国西北航空公司"); return; }
	if (!strcmp(carrier, "AC")) { strcpy(CARRIER, "加拿大国际航空公司"); return; }
	if (!strcmp(carrier, "UA")) { strcpy(CARRIER, "美国联合航空公司"); return; }
	if (!strcmp(carrier, "BA")) { strcpy(CARRIER, "英国航空公司"); return; }
	if (!strcmp(carrier, "KL")) { strcpy(CARRIER, "荷兰皇家航空公司"); return; }
	if (!strcmp(carrier, "LH")) { strcpy(CARRIER, "德国汉莎航空公司"); return; }
	if (!strcmp(carrier, "AF")) { strcpy(CARRIER, "法国航空公司"); return; }
	if (!strcmp(carrier, "LX")) { strcpy(CARRIER, "瑞士航空公司"); return; }
	if (!strcmp(carrier, "OS")) { strcpy(CARRIER, "奥地利航空公司"); return; }
	if (!strcmp(carrier, "SU")) { strcpy(CARRIER, "俄罗斯国际航空公司"); return; }
	if (!strcmp(carrier, "QF")) { strcpy(CARRIER, "澳洲航空公司"); return; }
	if (!strcmp(carrier, "AY")) { strcpy(CARRIER, "芬兰航空公司"); return; }
	if (!strcmp(carrier, "AZ")) { strcpy(CARRIER, "意大利航空公司"); return; }
	if (!strcmp(carrier, "SK")) { strcpy(CARRIER, "斯堪的纳维亚航空公司"); return; }
	if (!strcmp(carrier, "BI")) { strcpy(CARRIER, "文莱皇家航空公司"); return; }
	if (!strcmp(carrier, "GA")) { strcpy(CARRIER, "印度尼西亚鹰航空公司"); return; }
	if (!strcmp(carrier, "MI")) { strcpy(CARRIER, "新加坡胜安航空公司"); return; }
	if (!strcmp(carrier, "MH")) { strcpy(CARRIER, "马来西亚航空公司"); return; }
	if (!strcmp(carrier, "ET")) { strcpy(CARRIER, "埃塞俄比亚航空公司"); return; }
	if (!strcmp(carrier, "EZ")) { strcpy(CARRIER, "美国长青国际航空公司"); return; }
	if (!strcmp(carrier, "LO")) { strcpy(CARRIER, "波兰航空公司"); return; }
	if (!strcmp(carrier, "RO")) { strcpy(CARRIER, "罗马尼亚航空公司"); return; }
	if (!strcmp(carrier, "HY")) { strcpy(CARRIER, "乌兹别克斯坦航空公司"); return; }
	if (!strcmp(carrier, "VI")) { strcpy(CARRIER, "伏尔加第聂伯航空公司"); return; }
	if (!strcmp(carrier, "K4")) { strcpy(CARRIER, "哈萨克斯坦航空公司"); return; }
	if (!strcmp(carrier, "OM")) { strcpy(CARRIER, "蒙古航空公司"); return; }
	if (!strcmp(carrier, "PK")) { strcpy(CARRIER, "巴基斯坦国际航空公司"); return; }
	if (!strcmp(carrier, "PR")) { strcpy(CARRIER, "菲利宾航空公司"); return; }
	if (!strcmp(carrier, "RA")) { strcpy(CARRIER, "王家尼泊尔航空公司"); return; }
	if (!strcmp(carrier, "IR")) { strcpy(CARRIER, "伊朗航空公司"); return; }
	if (!strcmp(carrier, "JD")) { strcpy(CARRIER, "日本航空系统株氏会航空公司"); return; }
	if (!strcmp(carrier, "JS")) { strcpy(CARRIER, "高丽航空公司"); return; }
	if (!strcmp(carrier, "LY")) { strcpy(CARRIER, "以色列航空公司"); return; }
	if (!strcmp(carrier, "NX")) { strcpy(CARRIER, "澳门航空公司"); return; }
	if (!strcmp(carrier, "UB")) { strcpy(CARRIER, "缅甸国际航空公司"); return; }
	if (!strcmp(carrier, "VN")) { strcpy(CARRIER, "越南航空公司"); return; }
	if (!strcmp(carrier, "CX")) { strcpy(CARRIER, "国泰航空公司"); return; }
	if (!strcmp(carrier, "EK")) { strcpy(CARRIER, "阿拉伯联合酋长国航空公司"); return; }
	if (!strcmp(carrier, "KN")) { strcpy(CARRIER, "中国联合航空公司"); return; }
	strcpy(CARRIER, "没有找到匹配的航空公司");
	return;
}
//和数据库匹配机场中文全称（输入字符串，输出字符串）
void MatchAirport(char* airport, char* AIRPORT)
{
	char _airport[4] = "\0";
	strncpy(_airport, airport, 3);
	//只匹配前三位
	_airport[3] = '\0';
	if (!strcmp(_airport, "PEK")) { strcpy(AIRPORT, "北京首都国际机场"); return; }
	if (!strcmp(_airport, "CAN")) { strcpy(AIRPORT, "广州白云国际机场"); return; }
	if (!strcmp(_airport, "SHA")) { strcpy(AIRPORT, "上海虹桥国际机场"); return; }
	if (!strcmp(_airport, "PVG")) { strcpy(AIRPORT, "上海浦东国际机场"); return; }
	if (!strcmp(_airport, "CTU")) { strcpy(AIRPORT, "成都双流国际机场"); return; }
	if (!strcmp(_airport, "SZX")) { strcpy(AIRPORT, "深圳宝安国际机场"); return; }
	if (!strcmp(_airport, "KMG")) { strcpy(AIRPORT, "昆明长水国际机场"); return; }
	if (!strcmp(_airport, "XIY")) { strcpy(AIRPORT, "西安咸阳国际机场"); return; }
	if (!strcmp(_airport, "CKG")) { strcpy(AIRPORT, "重庆江北国际机场"); return; }
	if (!strcmp(_airport, "HGH")) { strcpy(AIRPORT, "杭州萧山国际机场"); return; }
	if (!strcmp(_airport, "XMN")) { strcpy(AIRPORT, "厦门高崎国际机场"); return; }
	if (!strcmp(_airport, "CSX")) { strcpy(AIRPORT, "长沙黄花国际机场"); return; }
	if (!strcmp(_airport, "NKG")) { strcpy(AIRPORT, "南京禄口国际机场"); return; }
	if (!strcmp(_airport, "WUH")) { strcpy(AIRPORT, "武汉天河国际机场"); return; }
	if (!strcmp(_airport, "DLC")) { strcpy(AIRPORT, "大连国际机场"); return; }
	if (!strcmp(_airport, "TAO")) { strcpy(AIRPORT, "青岛流亭国际机场"); return; }
	if (!strcmp(_airport, "SYX")) { strcpy(AIRPORT, "三亚凤凰国际机场"); return; }
	if (!strcmp(_airport, "HAK")) { strcpy(AIRPORT, "海口美兰国际机场"); return; }
	if (!strcmp(_airport, "TSN")) { strcpy(AIRPORT, "天津滨海国际机场"); return; }
	if (!strcmp(_airport, "HKG")) { strcpy(AIRPORT, "香港国际机场"); return; }
	if (!strcmp(_airport, "MFM")) { strcpy(AIRPORT, "澳门国际机场"); return; }
	if (!strcmp(_airport, "URC")) { strcpy(AIRPORT, "乌鲁木齐机场"); return; }
	if (!strcmp(_airport, "TPE")) { strcpy(AIRPORT, "台北桃园国际机场"); return; }
	if (!strcmp(_airport, "NRT")) { strcpy(AIRPORT, "东京成田国际机场"); return; }
	if (!strcmp(_airport, "HND")) { strcpy(AIRPORT, "东京羽田国际机场"); return; }
	if (!strcmp(_airport, "KIX")) { strcpy(AIRPORT, "大阪关西国际机场"); return; }
	if (!strcmp(_airport, "FUK")) { strcpy(AIRPORT, "福冈国际机场"); return; }
	if (!strcmp(_airport, "OKA")) { strcpy(AIRPORT, "冲绳那霸国际机场"); return; }
	if (!strcmp(_airport, "ITM")) { strcpy(AIRPORT, "大阪国际机场"); return; }
	if (!strcmp(_airport, "NGO")) { strcpy(AIRPORT, "名古屋国际机场"); return; }
	if (!strcmp(_airport, "ICN")) { strcpy(AIRPORT, "首尔仁川国际机场"); return; }
	if (!strcmp(_airport, "GMP")) { strcpy(AIRPORT, "首尔金浦国际机场"); return; }
	if (!strcmp(_airport, "PUS")) { strcpy(AIRPORT, "釜山金海国际机场"); return; }
	if (!strcmp(_airport, "CJU")) { strcpy(AIRPORT, "济州岛国际机场"); return; }
	if (!strcmp(_airport, "BKK")) { strcpy(AIRPORT, "曼谷素万那普国际机场"); return; }
	if (!strcmp(_airport, "DMK")) { strcpy(AIRPORT, "曼谷廊曼国际机场"); return; }
	if (!strcmp(_airport, "CNX")) { strcpy(AIRPORT, "清迈国际机场"); return; }
	if (!strcmp(_airport, "HKT")) { strcpy(AIRPORT, "普吉国际机场"); return; }
	if (!strcmp(_airport, "KUL")) { strcpy(AIRPORT, "吉隆坡国际机场"); return; }
	if (!strcmp(_airport, "PEN")) { strcpy(AIRPORT, "槟城国际机场"); return; }
	if (!strcmp(_airport, "BKI")) { strcpy(AIRPORT, "亚庇国际机场"); return; }
	if (!strcmp(_airport, "MNL")) { strcpy(AIRPORT, "马尼拉国际机场"); return; }
	if (!strcmp(_airport, "CRK")) { strcpy(AIRPORT, "克拉克国际机场"); return; }
	if (!strcmp(_airport, "CGK")) { strcpy(AIRPORT, "雅加达国际机场"); return; }
	if (!strcmp(_airport, "BDO")) { strcpy(AIRPORT, "万隆国际机场"); return; }
	if (!strcmp(_airport, "DPS")) { strcpy(AIRPORT, "巴厘岛登巴萨机场"); return; }
	if (!strcmp(_airport, "DEL")) { strcpy(AIRPORT, "新德里国际机场"); return; }
	if (!strcmp(_airport, "BLR")) { strcpy(AIRPORT, "班加罗尔国际机场"); return; }
	if (!strcmp(_airport, "CMB")) { strcpy(AIRPORT, "科伦坡国际机场"); return; }
	if (!strcmp(_airport, "SIN")) { strcpy(AIRPORT, "新加坡樟宜机场"); return; }
	if (!strcmp(_airport, "SGN")) { strcpy(AIRPORT, "胡志明国际机场"); return; }
	if (!strcmp(_airport, "HAN")) { strcpy(AIRPORT, "河内国际机场"); return; }
	if (!strcmp(_airport, "DEL")) { strcpy(AIRPORT, "印度新德里甘地机场"); return; }
	if (!strcmp(_airport, "KHI")) { strcpy(AIRPORT, "卡拉奇国际机场"); return; }
	if (!strcmp(_airport, "BOM")) { strcpy(AIRPORT, "印度孟买机场"); return; }
	if (!strcmp(_airport, "BLR")) { strcpy(AIRPORT, "印度班加罗尔机场"); return; }
	if (!strcmp(_airport, "KTM")) { strcpy(AIRPORT, "尼珀尔加德满都机场"); return; }
	if (!strcmp(_airport, "DXB")) { strcpy(AIRPORT, "阿联酋迪拜国际机场"); return; }
	if (!strcmp(_airport, "DOH")) { strcpy(AIRPORT, "卡塔尔多哈国际机场"); return; }
	if (!strcmp(_airport, "AUH")) { strcpy(AIRPORT, "阿联酋阿布扎比机场"); return; }
	if (!strcmp(_airport, "DAC")) { strcpy(AIRPORT, "孟加拉达卡机场"); return; }
	if (!strcmp(_airport, "JED")) { strcpy(AIRPORT, "沙特阿拉伯吉达国王机场"); return; }
	if (!strcmp(_airport, "CCU")) { strcpy(AIRPORT, "印度加尔各答机场"); return; }
	if (!strcmp(_airport, "THR")) { strcpy(AIRPORT, "伊朗德黑兰机场"); return; }
	if (!strcmp(_airport, "BAK")) { strcpy(AIRPORT, "阿塞拜疆巴库机场"); return; }
	if (!strcmp(_airport, "ISB")) { strcpy(AIRPORT, "巴基斯坦伊斯兰堡机场"); return; }
	if (!strcmp(_airport, "ASB")) { strcpy(AIRPORT, "土库曼阿什哈巴德机场"); return; }
	if (!strcmp(_airport, "DYU")) { strcpy(AIRPORT, "塔吉克斯坦杜尚别机场"); return; }
	if (!strcmp(_airport, "LBD")) { strcpy(AIRPORT, "塔吉克斯坦库德贾德机场"); return; }
	if (!strcmp(_airport, "OSS")) { strcpy(AIRPORT, "吉尔吉斯斯坦奥什机场"); return; }
	if (!strcmp(_airport, "TBS")) { strcpy(AIRPORT, "格鲁吉亚第比利斯机场"); return; }
	if (!strcmp(_airport, "MDL")) { strcpy(AIRPORT, "缅甸曼德勒机场"); return; }
	if (!strcmp(_airport, "MEL")) { strcpy(AIRPORT, "墨尔本国际机场"); return; }
	if (!strcmp(_airport, "SYD")) { strcpy(AIRPORT, "悉尼史密斯国际机场"); return; }
	if (!strcmp(_airport, "BNE")) { strcpy(AIRPORT, "布里斯班国际机场"); return; }
	if (!strcmp(_airport, "PER")) { strcpy(AIRPORT, "珀斯国际机场"); return; }
	if (!strcmp(_airport, "AKL")) { strcpy(AIRPORT, "奥克兰国际机场"); return; }
	if (!strcmp(_airport, "LHR")) { strcpy(AIRPORT, "伦敦希罗斯国际机场"); return; }
	if (!strcmp(_airport, "LGW")) { strcpy(AIRPORT, "伦敦盖威克国际机场"); return; }
	if (!strcmp(_airport, "STN")) { strcpy(AIRPORT, "伦敦斯坦斯特德机场"); return; }
	if (!strcmp(_airport, "LTN")) { strcpy(AIRPORT, "伦敦卢顿机场"); return; }
	if (!strcmp(_airport, "LCY")) { strcpy(AIRPORT, "伦敦城市机场"); return; }
	if (!strcmp(_airport, "LPL")) { strcpy(AIRPORT, "利物浦国际机场"); return; }
	if (!strcmp(_airport, "MAN")) { strcpy(AIRPORT, "曼彻斯特国际机场"); return; }
	if (!strcmp(_airport, "CDG")) { strcpy(AIRPORT, "巴黎戴高乐机场"); return; }
	if (!strcmp(_airport, "ORY")) { strcpy(AIRPORT, "巴黎奥利机场"); return; }
	if (!strcmp(_airport, "MRS")) { strcpy(AIRPORT, "马赛国际机场"); return; }
	if (!strcmp(_airport, "LYS")) { strcpy(AIRPORT, "里昂国际机场"); return; }
	if (!strcmp(_airport, "TXL")) { strcpy(AIRPORT, "柏林泰戈尔机场"); return; }
	if (!strcmp(_airport, "BER")) { strcpy(AIRPORT, "柏林勃兰登堡机场"); return; }
	if (!strcmp(_airport, "MUC")) { strcpy(AIRPORT, "慕尼黑国际机场"); return; }
	if (!strcmp(_airport, "BRE")) { strcpy(AIRPORT, "不莱梅机场BRE"); return; }
	if (!strcmp(_airport, "FRA")) { strcpy(AIRPORT, "法兰克福机场"); return; }
	if (!strcmp(_airport, "STR")) { strcpy(AIRPORT, "斯图加特机场"); return; }
	if (!strcmp(_airport, "HAM")) { strcpy(AIRPORT, "汉堡国际机场"); return; }
	if (!strcmp(_airport, "NUE")) { strcpy(AIRPORT, "纽伦堡机场"); return; }
	if (!strcmp(_airport, "ZRH")) { strcpy(AIRPORT, "苏黎世国际机场"); return; }
	if (!strcmp(_airport, "BRN")) { strcpy(AIRPORT, "伯尔尼贝尔普机场"); return; }
	if (!strcmp(_airport, "GVA")) { strcpy(AIRPORT, "日内瓦国际机场"); return; }
	if (!strcmp(_airport, "BSL")) { strcpy(AIRPORT, "巴塞尔国际机场"); return; }
	if (!strcmp(_airport, "MAD")) { strcpy(AIRPORT, "马德里巴拉哈斯机场"); return; }
	if (!strcmp(_airport, "BCN")) { strcpy(AIRPORT, "巴塞罗那安普拉特机场"); return; }
	if (!strcmp(_airport, "VLC")) { strcpy(AIRPORT, "巴伦西亚机场"); return; }
	if (!strcmp(_airport, "SVQ")) { strcpy(AIRPORT, "塞维利亚机场"); return; }
	if (!strcmp(_airport, "AMS")) { strcpy(AIRPORT, "阿姆斯特丹史基浦机场"); return; }
	if (!strcmp(_airport, "RTM")) { strcpy(AIRPORT, "鹿特丹机场"); return; }
	if (!strcmp(_airport, "FCO")) { strcpy(AIRPORT, "罗马菲乌米奇诺机"); return; }
	if (!strcmp(_airport, "MXP")) { strcpy(AIRPORT, "米兰马尔蓬萨机场"); return; }
	if (!strcmp(_airport, "VCE")) { strcpy(AIRPORT, "威尼斯机场"); return; }
	if (!strcmp(_airport, "FLR")) { strcpy(AIRPORT, "佛罗伦萨机场"); return; }
	if (!strcmp(_airport, "TRN")) { strcpy(AIRPORT, "都灵机场"); return; }
	if (!strcmp(_airport, "LIS")) { strcpy(AIRPORT, "里斯本国际机场"); return; }
	if (!strcmp(_airport, "OPO")) { strcpy(AIRPORT, "奥波多国际机场"); return; }
	if (!strcmp(_airport, "CPH")) { strcpy(AIRPORT, "哥本哈根凯斯楚普机场"); return; }
	if (!strcmp(_airport, "PRG")) { strcpy(AIRPORT, "布拉格鲁济涅机场"); return; }
	if (!strcmp(_airport, "HEL")) { strcpy(AIRPORT, "赫尔辛基万塔机场"); return; }
	if (!strcmp(_airport, "ATH")) { strcpy(AIRPORT, "雅典国际机场"); return; }
	if (!strcmp(_airport, "ARN")) { strcpy(AIRPORT, "斯德哥尔摩阿兰达机场"); return; }
	if (!strcmp(_airport, "OSL")) { strcpy(AIRPORT, "奥斯陆加勒穆恩机场"); return; }
	if (!strcmp(_airport, "WAW")) { strcpy(AIRPORT, "华沙奥肯切机场"); return; }
	if (!strcmp(_airport, "BUD")) { strcpy(AIRPORT, "布达佩斯费里海吉机场"); return; }
	if (!strcmp(_airport, "VIE")) { strcpy(AIRPORT, "维也纳施韦夏特机场"); return; }
	if (!strcmp(_airport, "BRU")) { strcpy(AIRPORT, "布鲁塞尔国际机场"); return; }
	if (!strcmp(_airport, "LUX")) { strcpy(AIRPORT, "卢森堡国际机场"); return; }
	if (!strcmp(_airport, "SVO")) { strcpy(AIRPORT, "莫斯科谢列梅捷沃机场"); return; }
	if (!strcmp(_airport, "DME")) { strcpy(AIRPORT, "莫斯科多莫杰多沃机场"); return; }
	if (!strcmp(_airport, "KBP")) { strcpy(AIRPORT, "基辅机场"); return; }
	if (!strcmp(_airport, "IEV")) { strcpy(AIRPORT, "基辅茹良尼机场"); return; }
	if (!strcmp(_airport, "BEG")) { strcpy(AIRPORT, "贝尔格莱德机场"); return; }
	if (!strcmp(_airport, "BUH")) { strcpy(AIRPORT, "布加勒斯特机场"); return; }
	if (!strcmp(_airport, "ZAG")) { strcpy(AIRPORT, "萨格勒布机场"); return; }
	if (!strcmp(_airport, "LAX")) { strcpy(AIRPORT, "洛杉矶国际机场"); return; }
	if (!strcmp(_airport, "SAN")) { strcpy(AIRPORT, "圣地亚哥机场"); return; }
	if (!strcmp(_airport, "SNA")) { strcpy(AIRPORT, "橘子郡机场"); return; }
	if (!strcmp(_airport, "SFO")) { strcpy(AIRPORT, "旧金山国际机场"); return; }
	if (!strcmp(_airport, "SJC")) { strcpy(AIRPORT, "圣何塞机场"); return; }
	if (!strcmp(_airport, "SEA")) { strcpy(AIRPORT, "西雅图国际机场"); return; }
	if (!strcmp(_airport, "PDX")) { strcpy(AIRPORT, "波特兰机场"); return; }
	if (!strcmp(_airport, "PHX")) { strcpy(AIRPORT, "菲尼克斯机场"); return; }
	if (!strcmp(_airport, "LAS")) { strcpy(AIRPORT, "拉斯维加斯机场"); return; }
	if (!strcmp(_airport, "SLC")) { strcpy(AIRPORT, "盐湖城机场"); return; }
	if (!strcmp(_airport, "DEN")) { strcpy(AIRPORT, "丹佛机场"); return; }
	if (!strcmp(_airport, "AUS")) { strcpy(AIRPORT, "奥斯汀机场"); return; }
	if (!strcmp(_airport, "IAH")) { strcpy(AIRPORT, "休斯顿国际机场"); return; }
	if (!strcmp(_airport, "HOU")) { strcpy(AIRPORT, "休斯顿哈比机场"); return; }
	if (!strcmp(_airport, "DFW")) { strcpy(AIRPORT, "达拉斯机场"); return; }
	if (!strcmp(_airport, "MCI")) { strcpy(AIRPORT, "堪萨斯城机场"); return; }
	if (!strcmp(_airport, "STL")) { strcpy(AIRPORT, "圣·路易斯机场"); return; }
	if (!strcmp(_airport, "MSY")) { strcpy(AIRPORT, "新奥尔良机场"); return; }
	if (!strcmp(_airport, "BHM")) { strcpy(AIRPORT, "伯明翰机场"); return; }
	if (!strcmp(_airport, "MEM")) { strcpy(AIRPORT, "孟菲斯机场"); return; }
	if (!strcmp(_airport, "BNA")) { strcpy(AIRPORT, "纳什维尔机场"); return; }
	if (!strcmp(_airport, "ORD")) { strcpy(AIRPORT, "芝加哥机场"); return; }
	if (!strcmp(_airport, "DTW")) { strcpy(AIRPORT, "底特律机场"); return; }
	if (!strcmp(_airport, "IND")) { strcpy(AIRPORT, "印第安那波利斯"); return; }
	if (!strcmp(_airport, "CVG")) { strcpy(AIRPORT, "辛辛那提机场"); return; }
	if (!strcmp(_airport, "CMH")) { strcpy(AIRPORT, "哥伦布机场"); return; }
	if (!strcmp(_airport, "CLE")) { strcpy(AIRPORT, "克利夫兰机场"); return; }
	if (!strcmp(_airport, "PWM")) { strcpy(AIRPORT, "波特兰机场"); return; }
	if (!strcmp(_airport, "BOS")) { strcpy(AIRPORT, "波士顿机场"); return; }
	if (!strcmp(_airport, "LGA")) { strcpy(AIRPORT, "纽约拉瓜地机场"); return; }
	if (!strcmp(_airport, "JFK")) { strcpy(AIRPORT, "纽约肯尼迪机场"); return; }
	if (!strcmp(_airport, "EWR")) { strcpy(AIRPORT, "纽约纽华克机场"); return; }
	if (!strcmp(_airport, "PIT")) { strcpy(AIRPORT, "匹兹堡机场"); return; }
	if (!strcmp(_airport, "PHL")) { strcpy(AIRPORT, "费城机场"); return; }
	if (!strcmp(_airport, "DCA")) { strcpy(AIRPORT, "华盛顿国际机场"); return; }
	if (!strcmp(_airport, "BWI")) { strcpy(AIRPORT, "巴尔地磨机场"); return; }
	if (!strcmp(_airport, "IAD")) { strcpy(AIRPORT, "华盛顿达拉斯机场"); return; }
	if (!strcmp(_airport, "CLT")) { strcpy(AIRPORT, "夏洛特机场"); return; }
	if (!strcmp(_airport, "ILM")) { strcpy(AIRPORT, "威尔明顿机场"); return; }
	if (!strcmp(_airport, "CAE")) { strcpy(AIRPORT, "哥伦比亚机场"); return; }
	if (!strcmp(_airport, "CHS")) { strcpy(AIRPORT, "查尔斯顿机场"); return; }
	if (!strcmp(_airport, "ATL")) { strcpy(AIRPORT, "亚特兰大机场"); return; }
	if (!strcmp(_airport, "MCO")) { strcpy(AIRPORT, "奥兰多机场"); return; }
	if (!strcmp(_airport, "TPA")) { strcpy(AIRPORT, "坦帕机场"); return; }
	if (!strcmp(_airport, "MIA")) { strcpy(AIRPORT, "迈阿密机场"); return; }
	if (!strcmp(_airport, "HNL")) { strcpy(AIRPORT, "火奴鲁鲁机场"); return; }
	if (!strcmp(_airport, "YVR")) { strcpy(AIRPORT, "温哥华机场"); return; }
	if (!strcmp(_airport, "YYZ")) { strcpy(AIRPORT, "多伦多国际机场"); return; }
	if (!strcmp(_airport, "YUL")) { strcpy(AIRPORT, "蒙特利尔特鲁多机场"); return; }
	if (!strcmp(_airport, "YOW")) { strcpy(AIRPORT, "渥太华国际机场"); return; }
	if (!strcmp(_airport, "YHZ")) { strcpy(AIRPORT, "哈利法克斯国际机场"); return; }
	if (!strcmp(_airport, "YYC")) { strcpy(AIRPORT, "卡尔加里国际机场"); return; }
	if (!strcmp(_airport, "YEG")) { strcpy(AIRPORT, "埃德蒙顿国际机场"); return; }
	if (!strcmp(_airport, "TIJ")) { strcpy(AIRPORT, "蒂华纳国际机场"); return; }
	if (!strcmp(_airport, "MEX")) { strcpy(AIRPORT, "墨西哥国际机场"); return; }
	if (!strcmp(_airport, "CUN")) { strcpy(AIRPORT, "坎昆国际机场"); return; }
	if (!strcmp(_airport, "HLD")) { strcpy(AIRPORT, "呼伦贝尔东山国际机场"); return; }

	if (!strcmp(_airport, "ATH")) { strcpy(AIRPORT, "雅典机场"); return; }
	if (!strcmp(_airport, "BAV")) { strcpy(AIRPORT, "包头机场"); return; }
	if (!strcmp(_airport, "BHY")) { strcpy(AIRPORT, "北海机场"); return; }
	if (!strcmp(_airport, "BJS")) { strcpy(AIRPORT, "北京机场"); return; }
	if (!strcmp(_airport, "BKK")) { strcpy(AIRPORT, "曼谷机场"); return; }
	if (!strcmp(_airport, "BLR")) { strcpy(AIRPORT, "班加罗尔机场"); return; }
	if (!strcmp(_airport, "BOM")) { strcpy(AIRPORT, "孟买机场"); return; }
	if (!strcmp(_airport, "BPX")) { strcpy(AIRPORT, "昌都机场"); return; }
	if (!strcmp(_airport, "CAN")) { strcpy(AIRPORT, "广州机场"); return; }
	if (!strcmp(_airport, "CGO")) { strcpy(AIRPORT, "郑州机场"); return; }
	if (!strcmp(_airport, "CGQ")) { strcpy(AIRPORT, "长春机场"); return; }
	if (!strcmp(_airport, "CHG")) { strcpy(AIRPORT, "朝阳机场"); return; }
	if (!strcmp(_airport, "CIF")) { strcpy(AIRPORT, "赤峰机场"); return; }
	if (!strcmp(_airport, "CIH")) { strcpy(AIRPORT, "长治机场"); return; }
	if (!strcmp(_airport, "CKG")) { strcpy(AIRPORT, "重庆机场"); return; }
	if (!strcmp(_airport, "CSX")) { strcpy(AIRPORT, "长沙机场"); return; }
	if (!strcmp(_airport, "CTU")) { strcpy(AIRPORT, "成都机场"); return; }
	if (!strcmp(_airport, "CZX")) { strcpy(AIRPORT, "常州机场"); return; }
	if (!strcmp(_airport, "DAT")) { strcpy(AIRPORT, "大同机场"); return; }
	if (!strcmp(_airport, "DAX")) { strcpy(AIRPORT, "达州机场"); return; }
	if (!strcmp(_airport, "DDG")) { strcpy(AIRPORT, "丹东机场"); return; }
	if (!strcmp(_airport, "DEL")) { strcpy(AIRPORT, "德里机场"); return; }
	if (!strcmp(_airport, "DLC")) { strcpy(AIRPORT, "大连机场"); return; }
	if (!strcmp(_airport, "DNH")) { strcpy(AIRPORT, "敦煌机场"); return; }
	if (!strcmp(_airport, "DQA")) { strcpy(AIRPORT, "大庆机场"); return; }
	if (!strcmp(_airport, "DSN")) { strcpy(AIRPORT, "鄂尔多斯机场"); return; }
	if (!strcmp(_airport, "DUS")) { strcpy(AIRPORT, "杜塞尔多夫机场"); return; }
	if (!strcmp(_airport, "DXB")) { strcpy(AIRPORT, "迪拜机场"); return; }
	if (!strcmp(_airport, "DYG")) { strcpy(AIRPORT, "张家界机场"); return; }
	if (!strcmp(_airport, "FNJ")) { strcpy(AIRPORT, "平壤机场"); return; }
	if (!strcmp(_airport, "FOC")) { strcpy(AIRPORT, "福州机场"); return; }
	if (!strcmp(_airport, "FRA")) { strcpy(AIRPORT, "法兰克福机场"); return; }
	if (!strcmp(_airport, "FUG")) { strcpy(AIRPORT, "阜阳机场"); return; }
	if (!strcmp(_airport, "FUK")) { strcpy(AIRPORT, "福冈机场"); return; }
	if (!strcmp(_airport, "GYS")) { strcpy(AIRPORT, "广元机场"); return; }
	if (!strcmp(_airport, "HAK")) { strcpy(AIRPORT, "海口机场"); return; }
	if (!strcmp(_airport, "HET")) { strcpy(AIRPORT, "呼和浩特机场"); return; }
	if (!strcmp(_airport, "HFE")) { strcpy(AIRPORT, "合肥机场"); return; }
	if (!strcmp(_airport, "HGH")) { strcpy(AIRPORT, "杭州机场"); return; }
	if (!strcmp(_airport, "HIJ")) { strcpy(AIRPORT, "广岛机场"); return; }
	if (!strcmp(_airport, "HKG")) { strcpy(AIRPORT, "香港机场"); return; }
	if (!strcmp(_airport, "HKT")) { strcpy(AIRPORT, "普吉机场"); return; }
	if (!strcmp(_airport, "HLD")) { strcpy(AIRPORT, "海拉尔机场"); return; }
	if (!strcmp(_airport, "HLH")) { strcpy(AIRPORT, "乌兰浩特机场"); return; }
	if (!strcmp(_airport, "HRB")) { strcpy(AIRPORT, "哈尔滨机场"); return; }
	if (!strcmp(_airport, "HTA")) { strcpy(AIRPORT, "赤塔机场"); return; }
	if (!strcmp(_airport, "HTN")) { strcpy(AIRPORT, "和田机场"); return; }
	if (!strcmp(_airport, "HYN")) { strcpy(AIRPORT, "黄岩机场"); return; }
	if (!strcmp(_airport, "INC")) { strcpy(AIRPORT, "银川机场"); return; }
	if (!strcmp(_airport, "JDZ")) { strcpy(AIRPORT, "景德镇机场"); return; }
	if (!strcmp(_airport, "JGS")) { strcpy(AIRPORT, "井冈山机场"); return; }
	if (!strcmp(_airport, "JJN")) { strcpy(AIRPORT, "晋江机场"); return; }
	if (!strcmp(_airport, "JKT")) { strcpy(AIRPORT, "雅加达机场"); return; }
	if (!strcmp(_airport, "JMU")) { strcpy(AIRPORT, "佳木斯机场"); return; }
	if (!strcmp(_airport, "JZH")) { strcpy(AIRPORT, "九寨沟机场"); return; }
	if (!strcmp(_airport, "KHG")) { strcpy(AIRPORT, "喀什机场"); return; }
	if (!strcmp(_airport, "KHI")) { strcpy(AIRPORT, "卡拉奇机场"); return; }
	if (!strcmp(_airport, "KHN")) { strcpy(AIRPORT, "南昌机场"); return; }
	if (!strcmp(_airport, "KMG")) { strcpy(AIRPORT, "昆明机场"); return; }
	if (!strcmp(_airport, "KOW")) { strcpy(AIRPORT, "赣州机场"); return; }
	if (!strcmp(_airport, "KRL")) { strcpy(AIRPORT, "库尔勒机场"); return; }
	if (!strcmp(_airport, "KTM")) { strcpy(AIRPORT, "加德满都机场"); return; }
	if (!strcmp(_airport, "KUL")) { strcpy(AIRPORT, "吉隆坡机场"); return; }
	if (!strcmp(_airport, "KWE")) { strcpy(AIRPORT, "贵阳机场"); return; }
	if (!strcmp(_airport, "KWL")) { strcpy(AIRPORT, "桂林机场"); return; }
	if (!strcmp(_airport, "LHW")) { strcpy(AIRPORT, "兰州机场"); return; }
	if (!strcmp(_airport, "LJG")) { strcpy(AIRPORT, "丽江机场"); return; }
	if (!strcmp(_airport, "LON")) { strcpy(AIRPORT, "伦敦机场"); return; }
	if (!strcmp(_airport, "LXA")) { strcpy(AIRPORT, "拉萨机场"); return; }
	if (!strcmp(_airport, "LYG")) { strcpy(AIRPORT, "连云港机场"); return; }
	if (!strcmp(_airport, "LZH")) { strcpy(AIRPORT, "柳州机场"); return; }
	if (!strcmp(_airport, "LZO")) { strcpy(AIRPORT, "泸州机场"); return; }
	if (!strcmp(_airport, "LZY")) { strcpy(AIRPORT, "林芝机场"); return; }
	if (!strcmp(_airport, "MAD")) { strcpy(AIRPORT, "马德里机场"); return; }
	if (!strcmp(_airport, "MEL")) { strcpy(AIRPORT, "墨尔本机场"); return; }
	if (!strcmp(_airport, "MFM")) { strcpy(AIRPORT, "澳门机场"); return; }
	if (!strcmp(_airport, "MIG")) { strcpy(AIRPORT, "绵阳机场"); return; }
	if (!strcmp(_airport, "MIL")) { strcpy(AIRPORT, "米兰机场"); return; }
	if (!strcmp(_airport, "MNL")) { strcpy(AIRPORT, "马尼拉机场"); return; }
	if (!strcmp(_airport, "MOW")) { strcpy(AIRPORT, "莫斯科机场"); return; }
	if (!strcmp(_airport, "MUC")) { strcpy(AIRPORT, "幕尼黑机场"); return; }
	if (!strcmp(_airport, "NDG")) { strcpy(AIRPORT, "齐齐哈尔机场"); return; }
	if (!strcmp(_airport, "NGB")) { strcpy(AIRPORT, "宁波机场"); return; }
	if (!strcmp(_airport, "NGO")) { strcpy(AIRPORT, "名古屋机场"); return; }
	if (!strcmp(_airport, "NNG")) { strcpy(AIRPORT, "南宁机场"); return; }
	if (!strcmp(_airport, "NTG")) { strcpy(AIRPORT, "南通机场"); return; }
	if (!strcmp(_airport, "NYC")) { strcpy(AIRPORT, "纽约机场"); return; }
	if (!strcmp(_airport, "NZH")) { strcpy(AIRPORT, "满洲里机场"); return; }
	if (!strcmp(_airport, "OKA")) { strcpy(AIRPORT, "冲绳机场"); return; }
	if (!strcmp(_airport, "OSA")) { strcpy(AIRPORT, "大阪机场"); return; }
	if (!strcmp(_airport, "PAR")) { strcpy(AIRPORT, "巴黎机场"); return; }
	if (!strcmp(_airport, "PUS")) { strcpy(AIRPORT, "釜山机场"); return; }
	if (!strcmp(_airport, "PVG")) { strcpy(AIRPORT, "上海浦东机场"); return; }
	if (!strcmp(_airport, "RGN")) { strcpy(AIRPORT, "仰光机场"); return; }
	if (!strcmp(_airport, "RKZ")) { strcpy(AIRPORT, "日喀则机场"); return; }
	if (!strcmp(_airport, "RLK")) { strcpy(AIRPORT, "巴彦淖尔机场"); return; }
	if (!strcmp(_airport, "RMQ")) { strcpy(AIRPORT, "台中机场"); return; }
	if (!strcmp(_airport, "ROM")) { strcpy(AIRPORT, "罗马机场"); return; }
	if (!strcmp(_airport, "SAO")) { strcpy(AIRPORT, "圣保罗机场"); return; }
	if (!strcmp(_airport, "SDJ")) { strcpy(AIRPORT, "仙台机场"); return; }
	if (!strcmp(_airport, "SEL")) { strcpy(AIRPORT, "首尔机场"); return; }
	if (!strcmp(_airport, "SGN")) { strcpy(AIRPORT, "胡志明市机场"); return; }
	if (!strcmp(_airport, "SHE")) { strcpy(AIRPORT, "沈阳机场"); return; }
	if (!strcmp(_airport, "SIA")) { strcpy(AIRPORT, "西安机场"); return; }
	if (!strcmp(_airport, "SIN")) { strcpy(AIRPORT, "新加坡机场"); return; }
	if (!strcmp(_airport, "SPK")) { strcpy(AIRPORT, "札幌机场"); return; }
	if (!strcmp(_airport, "STO")) { strcpy(AIRPORT, "斯德哥尔摩机场"); return; }
	if (!strcmp(_airport, "SWA")) { strcpy(AIRPORT, "汕头机场"); return; }
	if (!strcmp(_airport, "SYD")) { strcpy(AIRPORT, "悉尼机场"); return; }
	if (!strcmp(_airport, "SYX")) { strcpy(AIRPORT, "三亚机场"); return; }
	if (!strcmp(_airport, "SZX")) { strcpy(AIRPORT, "深圳机场"); return; }
	if (!strcmp(_airport, "TAE")) { strcpy(AIRPORT, "大邱机场"); return; }
	if (!strcmp(_airport, "TAO")) { strcpy(AIRPORT, "青岛机场"); return; }
	if (!strcmp(_airport, "TGO")) { strcpy(AIRPORT, "通辽机场"); return; }
	if (!strcmp(_airport, "TNA")) { strcpy(AIRPORT, "济南机场"); return; }
	if (!strcmp(_airport, "TPE")) { strcpy(AIRPORT, "台北机场"); return; }
	if (!strcmp(_airport, "TSA")) { strcpy(AIRPORT, "台北淞山机场"); return; }
	if (!strcmp(_airport, "TSN")) { strcpy(AIRPORT, "天津机场"); return; }
	if (!strcmp(_airport, "TXN")) { strcpy(AIRPORT, "黄山机场"); return; }
	if (!strcmp(_airport, "TYN")) { strcpy(AIRPORT, "太原机场"); return; }
	if (!strcmp(_airport, "TYO")) { strcpy(AIRPORT, "东京机场"); return; }
	if (!strcmp(_airport, "ULN")) { strcpy(AIRPORT, "乌兰巴托机场"); return; }
	if (!strcmp(_airport, "URC")) { strcpy(AIRPORT, "乌鲁木齐机场"); return; }
	if (!strcmp(_airport, "WEH")) { strcpy(AIRPORT, "威海机场"); return; }
	if (!strcmp(_airport, "WNZ")) { strcpy(AIRPORT, "温州机场"); return; }
	if (!strcmp(_airport, "WUH")) { strcpy(AIRPORT, "武汉机场"); return; }
	if (!strcmp(_airport, "WUX")) { strcpy(AIRPORT, "无锡机场"); return; }
	if (!strcmp(_airport, "WXN")) { strcpy(AIRPORT, "万州机场"); return; }
	if (!strcmp(_airport, "XFN")) { strcpy(AIRPORT, "襄樊机场"); return; }
	if (!strcmp(_airport, "XIC")) { strcpy(AIRPORT, "西昌机场"); return; }
	if (!strcmp(_airport, "XIL")) { strcpy(AIRPORT, "锡林浩特机场"); return; }
	if (!strcmp(_airport, "XIY")) { strcpy(AIRPORT, "西安机场"); return; }
	if (!strcmp(_airport, "XMN")) { strcpy(AIRPORT, "厦门机场"); return; }
	if (!strcmp(_airport, "XNN")) { strcpy(AIRPORT, "西宁机场"); return; }
	if (!strcmp(_airport, "XUZ")) { strcpy(AIRPORT, "徐州机场"); return; }
	if (!strcmp(_airport, "YBP")) { strcpy(AIRPORT, "宜宾机场"); return; }
	if (!strcmp(_airport, "YCU")) { strcpy(AIRPORT, "运城机场"); return; }
	if (!strcmp(_airport, "YIH")) { strcpy(AIRPORT, "宜昌机场"); return; }
	if (!strcmp(_airport, "YIW")) { strcpy(AIRPORT, "义乌机场"); return; }
	if (!strcmp(_airport, "YNJ")) { strcpy(AIRPORT, "延吉机场"); return; }
	if (!strcmp(_airport, "YNT")) { strcpy(AIRPORT, "烟台机场"); return; }
	if (!strcmp(_airport, "YNZ")) { strcpy(AIRPORT, "盐城机场"); return; }
	if (!strcmp(_airport, "YTY")) { strcpy(AIRPORT, "扬州机场"); return; }
	if (!strcmp(_airport, "YVR")) { strcpy(AIRPORT, "温哥华机场"); return; }
	if (!strcmp(_airport, "ZHA")) { strcpy(AIRPORT, "湛江机场"); return; }
	if (!strcmp(_airport, "ZUH")) { strcpy(AIRPORT, "珠海机场"); return; }
	if (!strcmp(_airport, "YIN")) { strcpy(AIRPORT, "伊宁机场"); return; }
	if (!strcmp(_airport, "HMI")) { strcpy(AIRPORT, "哈密机场"); return; }
	strcpy(AIRPORT, "没有匹配到机场信息");
	strcat(AIRPORT, airport);
	return;
}
//将开航日输出为中文字符串（输入字符串，输出字符串）
void MatchFlyDay(char* flyday, char* FLYDAY)
{
	strcpy(FLYDAY, "\0");
	if (flyday[1] == '1')strcat(FLYDAY, "一"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[2] == '2')strcat(FLYDAY, "二"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[3] == '3')strcat(FLYDAY, "三"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[4] == '4')strcat(FLYDAY, "四"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[5] == '5')strcat(FLYDAY, "五"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[6] == '6')strcat(FLYDAY, "六"); else strcat(FLYDAY, "  ");
	strcat(FLYDAY, "  ");
	if (flyday[7] == '7')strcat(FLYDAY, "日"); else strcat(FLYDAY, "  ");
	return;
}
//将日期输出为中文字符串（输入字符串，输出字符串）
void MatchDate(int year, int  date, char* Date)//输入一年开始的天数，返回字符串形式的日期
{
	int mday[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
	int month = 1;
	char IntChange[8];
	//_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);

	if (year % 4 == 0 && year % 100 != 0)
	{
		for (int i = 2; i < 12; i++)
			mday[i]++;
	}
	for (int i = 11; i >= 0; i--)
	{
		if ((date - mday[i]) >= 0)
		{
			month = i;
			date = date - mday[i];
			break;
		}
	}
	_stprintf(IntChange, _T("%4d"), year);
	strcpy(Date, IntChange);
	strcat(Date, "/");
	_stprintf(IntChange, _T("%2d"), month + 1);
	strcat(Date, IntChange);
	strcat(Date, "/");
	_stprintf(IntChange, _T("%2d"), date + 1);
	strcat(Date, IntChange);
	return;
}
//计算正晚点情况并返回字符串（航线数据库，航班数据库，航线数据下标，查询日期，返回字符串）
void MatchTimeAccuracy(FlightID* ID, FlightTicket DATA[][999], int n, int day, char* ACCURACY, COLORREF& TextColor)
{
	time_t NOW;
	tm* Local;
	int Arrival;
	int NowTime;//四字码表示的现在时间
	NOW = time(NULL);
	Local = localtime(&NOW);
	NowTime = Local->tm_hour * 100 + Local->tm_min;
	if (DATA[day][n].ActuralDepartureTime == 2600)
	{
		strcpy(ACCURACY, " 无数据");
		TextColor = BLACK;//设置颜色为黑色
		return;
	}
	if (day > Local->tm_yday)//未来的日期
	{
		strcpy(ACCURACY, "  计划");
		TextColor = RGB(112, 128, 144);//设置颜色为石板灰
		return;
	}
	if (day == Local->tm_yday)//如果是今天
	{
		if (NowTime < DATA[day][n].ActuralArrivalTime)//飞机还未到达，
		//当然在现实生活中是不会出现这个问题的，没到达的飞机是不可能有实际到达时间的。
		//但是本程序的数据库里直接导入了计划时间作为实际时间，故需要先排除一下。
		{
			strcpy(ACCURACY, "  计划");
			TextColor = RGB(112, 128, 144);//设置颜色为石板灰
			return;
		}
	}
	if (DATA[day][n].ActuralDepartureTime == 2500)
	{
		strcpy(ACCURACY, "航班取消");
		TextColor = RGB(220, 20, 60);//设置颜色为猩红
		return;
	}
	if ((ID[n].ArrivalTime % 100) >= 45)
		Arrival = ID[n].ArrivalTime + 65;
	else
		Arrival = ID[n].ArrivalTime + 15;
	if (DATA[day][n].ActuralArrivalTime > Arrival)
	{
		strcpy(ACCURACY, "航班延误");
		TextColor = RGB(255, 165, 0);//设置颜色为橙色
		return;
	}
	strcpy(ACCURACY, "正点到达");
	TextColor = RGB(0, 128, 0);//设置颜色为绿色
	return;
}
//将星期输出为中文字符串（输入字符串，输出字符串）
void MatchWeekDay(int wday, char* WEEKDAY)
{
	switch (wday)
	{
	case 1:
		strcpy(WEEKDAY, "星期一");
		return;
	case 2:
		strcpy(WEEKDAY, "星期二");
		return;
	case 3:
		strcpy(WEEKDAY, "星期三");
		return;
	case 4:
		strcpy(WEEKDAY, "星期四");
		return;
	case 5:
		strcpy(WEEKDAY, "星期五");
		return;
	case 6:
		strcpy(WEEKDAY, "星期六");
		return;
	case 0:
		strcpy(WEEKDAY, "星期日");
		return;
	}
}
//将舱位输出为中文字符串（输入字符串，输出字符串）
void MatchClass(char x, char* Class)
{
	if (x == 'f')
	{
		strcpy(Class, "头等舱");
		return;
	}
	if (x == 'e')
	{
		strcpy(Class, "经济舱");
		return;
	}
	if (x == 'b')
	{
		strcpy(Class, "商务舱");
		return;
	}
}
//将座位输出为中文字符串（输入数字，输出字符）
void MatchSeatY(int x, char* sy)
{
	if (x == 0)
		*sy = 'A';
	if (x == 1)
		*sy = 'B';
	if (x == 2)
		*sy = 'C';
	if (x == 3)
		*sy = 'D';
	if (x == 4)
		*sy = 'E';
	if (x == 5)
		*sy = 'G';
	if (x == 6)
		*sy = 'H';
	if (x == 7)
		*sy = 'J';
	if (x == 8)
		*sy = 'K';
	if (x == 9)
		*sy = 'L';
}
//对应头像
void MatchPic(int x, IMAGE& pic, int big)
{
	switch (x)
	{
	case 1:
		loadimage(&pic, ".\\IMAGES\\picture\\P1.jpg", big, big);
		return;
	case 2:
		loadimage(&pic, ".\\IMAGES\\picture\\P2.jpg", big, big);
		return;
	case 3:
		loadimage(&pic, ".\\IMAGES\\picture\\P3.jpg", big, big);
		return;
	case 4:
		loadimage(&pic, ".\\IMAGES\\picture\\P4.jpg", big, big);
		return;
	case 5:
		loadimage(&pic, ".\\IMAGES\\picture\\P5.jpg", big, big);
		return;
	case 6:
		loadimage(&pic, ".\\IMAGES\\picture\\P6.jpg", big, big);
		return;
	case 7:
		loadimage(&pic, ".\\IMAGES\\picture\\P7.jpg", big, big);
		return;
	case 8:
		loadimage(&pic, ".\\IMAGES\\picture\\P8.jpg", big, big);
		return;
	case 9:
		loadimage(&pic, ".\\IMAGES\\picture\\P9.jpg", big, big);
		return;
	case 10:
		loadimage(&pic, ".\\IMAGES\\picture\\P10.jpg", big, big);
		return;
	case 11:
		loadimage(&pic, ".\\IMAGES\\picture\\P11.jpg", big, big);
		return;
	case 12:
		loadimage(&pic, ".\\IMAGES\\picture\\P12.jpg", big, big);
		return;
	case 13:
		loadimage(&pic, ".\\IMAGES\\picture\\P13.jpg", big, big);
		return;
	case 14:
		loadimage(&pic, ".\\IMAGES\\picture\\P14.jpg", big, big);
		return;
	case 15:
		loadimage(&pic, ".\\IMAGES\\picture\\P15.jpg", big, big);
		return;
	}
}