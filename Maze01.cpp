#include<stdio.h>
#include<iostream>
using namespace std;
int num[10][10];
int w;
int min1 = 100;
int n;
struct book {								//显而易见，x代表x轴上的位置，y轴代表y轴上的运动 
	int x;
	int y;
}p[100];
void rearch(int n1)							//n1为当前的步数 
{
	if (p[n1].x == n - 2 && p[n1].y == n - 2)			//从此处记录到达中点时的步数 
	{
		if (min1 > n1)
			min1 = n1;
		return;
	}
	if (num[p[n1].y - 1][p[n1].x] == 0)			//以下四个if分别代表 上，下，左，右 四个方向的移动 
	{
		p[n1 + 1].x = p[n1].x;
		p[n1 + 1].y = p[n1].y - 1;				//将移动的值储存到下一位数组中，以供search(n+1)使用 
		num[p[n1].y][p[n1].x] = 1;
		rearch(n1 + 1);
		num[p[n1].y][p[n1].x] = 0;			//完成一次搜索后将值改回来 ，否则将找不到最小值 
	}
	if (num[p[n1].y][p[n1].x + 1] == 0)
	{
		p[n1 + 1].x = p[n1].x + 1;
		p[n1 + 1].y = p[n1].y;
		num[p[n1].y][p[n1].x] = 1;
		rearch(n1 + 1);
		num[p[n1].y][p[n1].x] = 0;
	}
	if (num[p[n1].y + 1][p[n1].x] == 0)
	{
		p[n1 + 1].x = p[n1].x;
		p[n1 + 1].y = p[n1].y + 1;
		num[p[n1].y][p[n1].x] = 1;
		rearch(n1 + 1);
		num[p[n1].y][p[n1].x] = 0;
	}
	if (num[p[n1].y][p[n1].x - 1] == 0)
	{
		p[n1 + 1].x = p[n1].x - 1;
		p[n1 + 1].y = p[n1].y;
		num[p[n1].y][p[n1].x] = 1;
		rearch(n1 + 1);
		num[p[n1].y][p[n1].x] = 0;
	}
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> num[i][j];
	p[0].x = 1;
	p[0].y = 1;												//这里为出发点，（n-2,n-2）为终点 
	rearch(0);
	if (min1 == 100)											//如果min的值不改变，说明没有找到路劲 
		cout << "No solution" << endl;
	else
		cout << min1 << endl;
}
