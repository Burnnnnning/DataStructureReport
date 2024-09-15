//（2）景点查询：可以查询某个景点，并展示该景点相关信息，例如：客流量、票价、景点类型等。(write by 陈)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Base.h"
using namespace std;

void Find_Inform(int place,int num,char* spot[][6])
{
	cout << spot[place][1] << ":" << spot[place][num + 1] << endl;
}

void Intro(int place, char* spot[][6])
{
	ifstream istrm;
	switch (place)
	{
		//case 1:istrm.open("天坛简介.txt"); break;
		//case 2:istrm.open("故宫简介.txt"); break;
		//case 3:istrm.open("天安门简介.txt"); break;
		//case 4:istrm.open("长城简介.txt"); break;
		//case 5:istrm.open("颐和园简介.txt"); break;
		//case 6:istrm.open("北海公园简介.txt"); break;
		case 1:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\天坛简介.txt"); break;
		case 2:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\故宫简介.txt"); break;
		case 3:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\天安门简介.txt"); break;
		case 4:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\长城简介.txt"); break;
		case 5:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\颐和园简介.txt"); break;
		case 6:istrm.open("E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\北海公园简介.txt"); break;
		default:cerr << "程序出错" << endl; exit(0);
	}
	/*char* str;
	str = new char[256];*/
	string str;
	istrm >> str;
	cout << spot[place][1] << str << endl;
	istrm.close();	
}

void Clear(char* spot[][6])
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			delete spot[i][j];
		}
	}
}

//景点查询
void Spot_Inquiry()
{
	int num,place;
	char* spot[7][6];
	
	//遍历文件
	FILE* file = NULL;
	//freopen_s(&file,"E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Spots.txt", "r", stdin);
	//fopen_s(&file, "Spots.txt", "r");
	fopen_s(&file, "E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Spots.txt", "r");

	if (file == NULL)	
	{
		cerr << "文件读取失败" << endl;
		return;
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			spot[i][j] = new char[128];
		}
		fscanf_s(file, "%s %s %s %s %s",spot[i][1],128,spot[i][2],128,spot[i][3],128,spot[i][4],128,spot[i][5],128);
	}
	fclose(file);

	cout << "============================" << endl;
	cout << "请输入想要查询的景点：" << endl;
	for (int i = 1; i <= 6; i++)
	{
		cout << i << "." << spot[i][1] << endl;
	}
	cout << "请选择(1~6)："; cin >> place;	//place是想要查询的景点

	while (1)
	{
		cout << "============================" << endl;
		cout << "请选择想查询的信息：" << endl;
		cout << "1.票价" << endl;
		cout << "2.开放时间" << endl;
		cout << "3.客流量" << endl;
		cout << "4.景区游玩推荐" << endl;
		cout << "5.景区简介" << endl;
		cout << "0.退出查询界面" << endl;
		cout << "============================" << endl;

		cout << "请选择(0~5)："; cin >> num;
		switch (num)
		{
			case 1:
			case 2:
			case 3:
			case 4: Find_Inform(place, num, spot); break;
			case 5: Intro(place, spot); break;
			case 0: /*system("cls"); */
				std::cout << "\033c";	// 使用ANSI转义码清空屏幕，仅在支持的Windows终端上有效
				Clear(spot); return;
			default:cerr << "输入无效，请重新输入！\n" << endl; break;
		}
	}
}


