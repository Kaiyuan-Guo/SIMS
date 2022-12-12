#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 删除函数 */
void Delete()
{
	int m = read();
	/* i,j用于循环，t,n充当按钮，flag是标志 */
	int i, j, t, n, flag, number;
	Output(); //调用输出函数
	printf("请输入要删除的职工的工号：");
	scanf("%d", &number);
	for (flag = 1, i = 0; flag && i < m ; i++)
	{
		if (staff[i].num == number)
		{
			printf("已找到此人，原始信息为：\n");
			printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
			printf("确认删除请按1，取消删除请按0：");
			scanf("%d", &t);
			if (t == 1)
			{
				/* 如果删除，后面其他职工信息都向前移一位 */
				for (j = i; j < m - 1; j++)
					staff[j] = staff[j + 1]; /* 当找到第j个员工时，j自加了1，所以应该把信息赋值给第j-1个人*/
				flag = 0;
			}
			else flag = 2;

		}
	}
	system("cls");
	switch (flag)
	{
	case 0:m = m - 1;
		printf("\n\t\t\t删除成功！\n");
		save(m);  //调用保存函数
		Output(); //调用输出函数
		break;
	case 1:printf("\n\t\t\t对不起，公司没有该员工！\n");
		Output();
		break;
	case 2:printf("\n\t\t\t取消删除！\n");
		break;
	}
	printf("\n继续删除请按1，返回菜单请按0：");
	scanf("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:Delete();
		break;
	case 0:main();
		break;
	default: break;
	}
	system("cls");
}