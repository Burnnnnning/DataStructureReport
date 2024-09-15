#include <iostream>
#include "Base.h"
#include "Graph.h"
using namespace std;

//路径规划
bool Visited[10];
int Const;
int Time = 1;
int Flag = 1;
char Name[10][20];
char Tem[20];

void PName()
{
	FILE* fp;
	fopen_s(&fp,"E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Name for Advise.txt", "r");
	if (!fp)
		cout << "无法正确打开文件.";
	else
	{
		int i = 1;
		while (fgets(Tem, sizeof(Tem), fp) != NULL)
		{
			for (int x = 0; x < 20; x++)
			{
				if (Tem[x] == '\n')
					break;
				int temporary = Tem[x];
				Name[i][x] = temporary;
			}
			for (int j = 0; j < 20; j++)
				Tem[j] = '\0';
			i++;
		}
	}
	fclose(fp);
}

void Find(int P1, Graph G, int P2)
{
	PName();
	if (P1 != P2)
	{
		for (int i = 1; i <= G.vexnum; i++)
		{
			if (Time == 1)
			{
				Const = P1;
				Time++;
			}
			if (Flag == 1 && P1 != i)
			{
				for (int y = 0; Name[Const][y] != '\n' && Name[Const][y] != '\0'; y++)
					cout << Name[Const][y];
				Visited[Const] = true;
			}
			if (P1 == i)
				continue;
			if (G.arcs[P1][i].Cost != MAX)
			{
				if (!Visited[i])
				{
					Visited[i] = true;
						cout << "-->";
					for (int y = 0; Name[i][y] != '\n' && Name[i][y] != '\0'; y++)
						cout << Name[i][y];
					if (i == P2)
					{
						cout << endl;
						for (int i = 0; i < 10; i++)
							Visited[i] = false;
						Time++;
						Flag = 1;
						if (P1 != Const)
							return;
						continue;
					}
				}
				else
					continue;
				if (Flag == 5)
					return;
				Flag++;
				Find(i, G, P2);
				if (P1 != Const)
					return;
			}
		}
	}
}

void LengthLowest(Graph G, int P, int V)
{
	bool S[MAX];
	int D[MAX];
	int LengthPath[MAX];
	int v, w, i, min;
	for (v = 1; v <= G.vexnum; ++v)
	{
		S[v] = false;
		D[v] = G.arcs[P][v].Length;
		if (D[v] < MaxInt)
			LengthPath[v] = P;
		else
			LengthPath[v] = -1;
	}
	S[P] = true;
	D[P] = 0;
	for (i = 1; i < G.vexnum; ++i)
	{
		min = MaxInt;
		for (w = 1; w <= G.vexnum; ++w)
		{
			if (!S[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;
		for (w = 1; w <= G.vexnum; ++w)
		{
			if (!S[w] && (D[v] + G.arcs[v][w].Length < D[w]))
			{
				D[w] = D[v] + G.arcs[v][w].Length;
				LengthPath[w] = v;
			}
		}
	}
	char Name[10][20];
	char Tem[20];
	FILE* fp;
	fopen_s(&fp,"E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Name for Advise.txt", "r");
	if (!fp)
		cout << "无法正确打开文件.";
	else
	{
		int i = 1;
		while (fgets(Tem, sizeof(Tem), fp) != NULL)
		{
			for (int x = 0; x < 20; x++)
			{
				/*if (Tem[x] == '\n')
					break;*/
				int temporary = Tem[x];
				Name[i][x] = temporary;
			}
			for (int j = 0; j < 20; j++)
				Tem[j] = '\0';
			i++;
		}
	}
	fclose(fp);
	int Temp;
	Temp = V;
	for (int y = 0; Name[V][y] != '\n' && Name[V][y] != '\0'; y++)
		cout << Name[V][y] ;
	cout << "-->";
	while (LengthPath[Temp] != P)
	{
		//int x = Path[Temp];
		for (int y = 0; Name[LengthPath[Temp]][y] != '\n' && Name[LengthPath[Temp]][y] != '\0'; y++)
			cout << Name[LengthPath[Temp]][y] ;
		cout << "-->";
		Temp = LengthPath[Temp];
	}
	cout << Name[P] << endl;
}

void CostLowest(Graph G, int P, int V)
{
	bool S[MAX];
	int D[MAX];
	int Path[MAX];
	int v, w, i, min;
	for (v = 1; v <= G.vexnum; ++v)
	{
		S[v] = false;
		D[v] = G.arcs[P][v].Cost;
		if (D[v] < MaxInt)
			Path[v] = P;
		else
			Path[v] = -1;
	}
	S[P] = true;
	D[P] = 0;
	for (i = 1; i < G.vexnum; ++i)
	{
		min = MaxInt;
		for (w = 0; w < G.vexnum; ++w)
		{
			if (!S[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;
		for (w = 1; w <= G.vexnum; ++w)
		{
			if (!S[w] && (D[v] + G.arcs[v][w].Cost < D[w]))
			{
				D[w] = D[v] + G.arcs[v][w].Cost;
				Path[w] = v;
			}
		}
	}
	char Name[10][20];
	char Tem[20];
	FILE* fp;
	fopen_s(&fp, "E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Name for Advise.txt", "r");
	if (!fp)
		cout << "无法正确打开文件.";
	else
	{
		int i = 1;
		while (fgets(Tem, sizeof(Tem), fp) != NULL)
		{
			for (int x = 0; x < 20; x++)
			{
			/*	if (Tem[x] == '\n')
					break;*/
				int temporary = Tem[x];
				Name[i][x] = temporary;
			}
			for (int j = 0; j < 20; j++)
				Tem[j] = '\0';
			i++;
		}
	}
	fclose(fp);
	int Temp;
	Temp = V;
	for (int y = 0; Name[V][y] != '\n' && Name[V][y] != '\0'; y++)
		cout << Name[V][y] ;
	cout << "-->";
	while (Path[Temp] != P)
	{
		for (int y = 0; Name[Path[Temp]][y] != '\n' && Name[Path[Temp]][y] != '\0'; y++)
			cout << Name[Path[Temp]][y] ;
		cout << "-->";
		Temp = Path[Temp];
	}
	cout << Name[P] << endl;
}

void Path_Planning()
{
	int P1, P2;
	cout << "请输入两个景点（1~6）："; cin >> P1 >> P2;
	if ((P1 < 1 || P1 > 6) || (P2 < 1 || P2 > 6))
	{
		cout << "请输入正确数字！" << endl;
		return;
	}
	Graph G;
	CreateGraph(G);
	Find(P1,G,P2);
	cout << endl;
	cout << "基于最短路径推荐方案：";
	LengthLowest(G, P1, P2);
	cout << "基于花费路径推荐方案：";
	CostLowest(G, P1, P2);
}

