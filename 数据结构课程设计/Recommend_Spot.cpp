#include <iostream>
#include "Base.h"
#include "Graph.h"
using namespace std;

//附近景点推荐
void Advise(Graph G, int P)
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
    for (int i = 0; i < 20; i++)
        Tem[i] = '\0';
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
                int temporary = Tem[x];
                Name[i][x] = temporary;
            }
            for (int j = 0; j < 20; j++)
                Tem[j] = '\0';
            i++;
        }
    }
    fclose(fp);
    cout << "推荐您顺便参观：";
    int TIME = 0;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (D[i] <= 20 && i != P)
        {
            for (int y = 0; Name[i][y] != '\n' && Name[i][y] != '\0'; y++)
                cout << Name[i][y];
            TIME++;
            if (i != G.vexnum)
                cout << ",";
        }
    }
    if (TIME == 0)
        cout << "无";
}

void CostAdvise(Graph G, int P)
{
    if (P < 1 || P > 6)
    {
        cout << "请输入符合要求的数字！" << endl;
        return;
    }
    bool S[MAX];    //查询是否便利
    int D[MAX];     //最小路径
    int CostPath[MAX];  //该点的前一个点
    int v, w, i, min;
    for (v = 1; v <= G.vexnum; ++v)     
    {
        S[v] = false;
        D[v] = G.arcs[P][v].Cost;
        if (D[v] < MaxInt)
            CostPath[v] = P;
        else
            CostPath[v] = -1;
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
            if (!S[w] && (D[v] + G.arcs[v][w].Cost < D[w]))
            {
                D[w] = D[v] + G.arcs[v][w].Cost;
                CostPath[w] = v;
            }
        }
    }
    char Name[10][20];
    char Tem[20];
    for (int i = 0; i < 20; i++)
        Tem[i] = '\0';
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
                int temporary = Tem[x];
                Name[i][x] = temporary;
            }
            for (int j = 0; j < 20; j++)
                Tem[j] = '\0';
            i++;
        }
    }
    fclose(fp);
    cout << "推荐您顺便参观：";
    int TIME = 0;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (D[i] <= 20 && i != P)
        {
            for (int y = 0; Name[i][y] != '\n' && Name[i][y] != '\0'; y++)
                cout << Name[i][y];
            TIME++;
            if (i != G.vexnum)
                cout << " ";
        }
    }
    if (TIME == 0)
        cout << "无";
}

void Recommend_Spot()
{
    int P, flag;
    cout << "请输入您的当前位置（数字1~6）：";
    cin >> P;
    Graph G;
    CreateGraph(G);
    cout << "请输入类型：" << endl;
    cout << "1.热爱运动型" << '\n' << "2.时间紧迫型" << endl;
    cout << "请输入（1或2）：";
    cin >> flag;
    if (flag == 1)  CostAdvise(G, P);
    else if (flag == 2) Advise(G, P);
    else
        cout << "输入错误" ;
    cout << endl;
}


