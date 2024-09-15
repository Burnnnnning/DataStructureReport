#ifndef POWER_H  
#define POWER_H  

#define MAX 32676
#define MaxInt 32675
using namespace std;
typedef struct
{
	int Cost;
	int Length;
}Power;

typedef struct
{
	int vex[MAX];
	Power arcs[100][100];
	int vexnum, arcnum;
}Graph;

#endif

