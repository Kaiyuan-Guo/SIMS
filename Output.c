#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

/* 输出信息函数 */
void Output()
{
	int i;
	int m = read();
	printf("\n\t--------------------------------公司职工信息--------------------------------\n");
	printf("\n\t| 工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  | \n");
	order();
	for (i = 0; i < m; i++)
		printf("\n%15d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
			staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
	printf("\n");
}