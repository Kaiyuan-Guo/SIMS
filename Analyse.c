#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 统计显示每小时平均工资以及最高工资员工姓名 */
void Analyse()
{
	int m = read();
	/* i,j用于循环，key用于记录最高工资员工的人数，H[N]记录员工在文件中的位置 */
	int i, j = 0, key = 0, H[N] = { 0 };
	float most = staff[0].wage;  //most记录最高工资
	double sum = 0, avg = 0;	 //sum是工资总和，avg是每小时平均工资
	
	for (i = 0; i < m; i++)
	{
		sum += staff[i].wage;
		if (most < staff[i + 1].wage && i < m - 1)
		{
			most = staff[i + 1].wage;  //找出最高工资
		}
	}
	for (i = 0; i < m ; i++)
	{
		/* 记录工资与most相同的员工 */
		while (j < N && staff[i].wage == most)
		{
			H[j] = i;
			key = j;
			j++;
			break;
		}
	}
	avg = sum / (m - 1);
	printf("\n\t公司全体员工每小时平均工资为：%8.2f\n",avg);
	printf("\n\t其中最高工资员工信息为：\n");
	printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
	for (j = 0; j <= key; j++)
	{
		printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[H[j]].num, staff[H[j]].name,
			staff[H[j]].year, staff[H[j]].category, staff[H[j]].duration, staff[H[j]].wage);
	}
	printf("\n\t按Enter键返回菜单\n");
	getchar();
	getchar();
	system("cls");
} 
