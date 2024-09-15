#pragma once
#include "Graph.h"
// 界面设计
void Main_Menu();

// 景点查询
void Spot_Inquiry();
void Find_Inform(int place, int num, char* spot[][6]);
void Intro(int place, char* spot[][6]);

// 附近景点推荐
void Recommend_Spot();
void Advise(Graph G, int P);
void CostAdvise(Graph G, int P);

// 路径规划
void Path_Planning();
void Find(int P1, Graph G, int P2);
void PName();

// 游览规划
void Tour_Planning();
void Average(Graph G, int P);

//图操作
void CreateGraph(Graph& G);

