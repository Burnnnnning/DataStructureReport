typedef struct
{
	char* Name;	//景区名字
	int Price;	//票价
	int FootTraffic;	//最大人流量
	char* Type;	//类型
}Base_inform;

typedef struct
{
	Base_inform inform;
	char* Intro;	//景区简介
	int OpenTime;	//开放时间
	char** advise;	//推荐
}FamousScene;

