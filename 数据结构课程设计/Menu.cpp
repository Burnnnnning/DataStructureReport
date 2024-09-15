#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Base.h"
#include "Graph.h"
using namespace std;

void ReFresh()
{
	system("pause");	
	//std::cout << "\033c";
	system("cls");	//清空终端
}

void Main_Menu()
{
	int num;
	while (1)
	{
		cout << "欢迎进入北京市旅游景点导游程序！" << endl; 
		cout << "============================" << endl;
		cout << "请选择一项服务：" << endl;
		cout << "1.景点查询" << endl;
		cout << "2.附近景点推荐" << endl;
		cout << "3.路径规划" << endl;
		cout << "4.游览规划" << endl;
		cout << "0.退出程序" << endl;
		cout << "============================" << endl;

		cout << "请选择(0~4)："; cin >> num;
		//std::cout << "\033c";
		switch (num)
		{
			case 1:Spot_Inquiry(); ReFresh(); break;
			case 2:Recommend_Spot(); ReFresh(); break;
			case 3:Path_Planning(); ReFresh(); break;
			case 4:Tour_Planning(); ReFresh(); break;
			case 0:return;
			default:cerr << "输入无效，请重新输入！\n" << endl; break;
		}
	}
}



