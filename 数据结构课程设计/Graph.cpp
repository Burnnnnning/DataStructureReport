//进行图的初始化
#include <iostream>
#include "Base.h"
#include "Graph.h"
using namespace std;

void CreateGraph(Graph& G)
{
    FILE* fp1;
    fopen_s(&fp1, "E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\G.vexnum.txt", "r");
    if (fp1 == NULL)
    {
        cout << "无法正确打开文件fp1";
        return;
    }
    fscanf_s(fp1, "%d", &G.vexnum);
    fclose(fp1);
    for (int i = 1; i <= G.vexnum; i++)
        G.vex[i] = i;
    FILE* fp2;
    fopen_s(&fp2, "E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\G.arcnum.txt", "r");
    if (fp2 == NULL)
    {
        cout << "无法正确打开文件fp2";
        return;
    }
    fscanf_s(fp2, "%d", &G.arcnum);
    fclose(fp2);
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].Length = G.arcs[i][j].Cost = MAX;

    int V1, V2;
    int Length, Cost;
    FILE* fp;
    fopen_s(&fp, "E:\\OneDrive\\桌面\\VS2022\\Report\\Report\\Path_data.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf_s(line, "%d;%d;%d;%d", &V1, &V2, &Length, &Cost) == 4)
        {
            G.arcs[V1][V2].Length = G.arcs[V2][V1].Length = Length;
            G.arcs[V1][V2].Cost = G.arcs[V2][V1].Cost = Cost;
        }
        else
            cout << "出现异常！！！" << line << endl;
        for (int i = 1; i <= G.vexnum; i++)
            G.arcs[i][i].Cost = 0;
    }
    fclose(fp);
}

