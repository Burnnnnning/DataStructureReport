//（5）游览规划：可以以某个景点为起点，综合考虑时间、距离等推荐全程游览方案。
#include <iostream>
#include <cstdio>
#include "Base.h"
#include "Graph.h"
using namespace std;

void Average(Graph G, int P)
{
    if (P >= 1 && P <= 6)
    {
        bool S[MAX];
        int D[MAX];
        int Path[MAX];
        int v, w, i, min;
        for (v = 1; v <= G.vexnum; ++v)
        {
            S[v] = false;
            D[v] = G.arcs[P][v].Cost * 0.3 + G.arcs[P][v].Length * 0.7;
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
                if (!S[w] && (D[v] + G.arcs[v][w].Cost * 0.3 + G.arcs[v][w].Length * 0.7 < D[w]))
                {
                    D[w] = D[v] + G.arcs[v][w].Cost * 0.3 + G.arcs[v][w].Length * 0.7;
                    Path[w] = v;
                }
            }
        }
        char Name[20][20];
        char Tem[100];
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
                    int temporary = Tem[x];
                    Name[i][x] = temporary;
                }
                //sscanf_s(Tem[x], "%c", Name[i][x]);
                for (int j = 0; j < 20; j++)    //清空
                    Tem[j] = '\0';
                i++;
            }
        }

        fclose(fp);
        int temmin = 6666;
        int tem;
        for (int j = 1; j <= G.vexnum; j++)
        {
            for (int i = 1; i <= G.vexnum; i++)
            {
                if (temmin > D[i])
                {
                    temmin = D[i];
                    tem = i;
                }
            }
            for(int y=0;Name[tem][y]!='\n'&&Name[tem][y]!='\0';y++)
                cout << Name[tem][y];
            D[tem] = 6666;
            temmin = 6666;
            if (j != G.vexnum)
                cout << "-->";
            else
                cout << endl;
        }

    }
    else
        cout << "请输入正确的数字！" << endl;
}

void Tour_Planning()
{
    Graph G;
    int P;
    cout << "请输入起始起点（1~6）：";cin >> P;
    if (P < 1 || P> 6)
    {
        cout << "输入数字有误！" << endl;
        return;
    }
    CreateGraph(G);
    Average(G, P);
}


