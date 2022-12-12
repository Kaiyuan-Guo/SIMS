#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
void Sort()  /* 用于主菜单调用 */
{
	//选择排序法
	int i, j, min;
	int m = read();

	for (i = 0; i < m-1; i++)
	{
	    min = i;
		for (j = i + 1; j < m; j++)     //走访未排序的元素
			if (staff[j].num < staff[min].num)    //找到目前最小值
				min = j;    //记录最小值
		if (min != i) {
			temp = staff[min];
			staff[min] = staff[i];
			staff[i] = temp;
		}
	}
	save(m);	/* 按工号由小到大顺序储存 */
	printf("\n\t排序后职工信息：\n");
	printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
	for (i = 0; i < m; i++)
		printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
			staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
	printf("\n");
	printf("\n按Enter键返回菜单\n");
	getchar();
	getchar();
	system("cls");
}
void order() /* 输出信息时，按工号由小到大顺序排序 */
{
	int i, j;
	int m = read();
	//冒泡法排序
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < m - 1 - i; j++) {
			if (staff[j].num > staff[j + 1].num)
			{
				temp = staff[j];
				staff[j] = staff[j + 1];
				staff[j + 1] = temp;
			}
		}
	}
	save(m); /* 按工号由小到大顺序储存 */
}
