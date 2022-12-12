#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 查找函数 */
void Search()
{
	int button, flag ;
	do {
		printf("\n 按工号查询请按1，按姓名查询请按2，按工龄查询请按3，返回菜单请按0：");
		scanf("%d", &button);
		if (button >= 0 && button <= 3)
		{
			flag = 1;
			break;
		}
		else {
			flag = 0;
			printf("\n您输入有误！请重新选择：");
		}
	} while (flag == 0);
	system("cls");
	while (flag == 1)
	{
		switch (button)
		{
		case 0:main();
			break;
		case 1:search_num();
			break;
		case 2:search_name();
			break;
		case 3:search_year();
			break;
		default:break;
		}
		system("cls");
	}
}
void search_num() /* 按工号查找函数*/
{
	int m = read();
	int start, end, mid = 0, number = 0, i, button;
	start = staff[0].num;	//标记起始的工号
	end = staff[m - 1].num; //标记末尾的工号
	printf("\n请输入要查询的职工的工号：");
	scanf("%d", &number);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (number < mid)
		{
			end = mid - 1;
		}
		else if (number > mid) {
			start = mid + 1;
		}
		else {
			break;
		}
	}
	system("cls");
	if (start <= end)
	{
		printf("\n已找到该员工，其信息为：");
		printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
		for (i = 0; i < m; i++)	//通过循环匹配，将此人信息输出
		{
			if(staff[i].num==mid)
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
		printf("\n删除员工请按1，修改信息请按2，继续查询请按3，返回上一级请按4，返回菜单请按0：");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
	else {	//遍历完，start>end,说明没有找到
		printf("\n\t\t对不起，公司没有该员工！\n");
		printf("\n\t\t按Enter键返回上一级\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
}
void search_name() /* 按姓名查找函数 */
{
	int m = read();
	char name[10] = { 0 };
	int i, button, flag = 0;  //flag相当于符合要求的人数
	printf("\n请输入要查找的姓名：");
	scanf("%s", &name);
	for (i = 0; i < m; i++)
	{
		if (strcmp(staff[i].name, name) == 0)
		{
			if (flag == 0)
			{
				printf("\n找到以下信息：\n");
				printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
			}
			flag++;
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
	}
	if (flag == 0)
	{
		printf("\n\t对不起，公司没有该员工！\n");
        printf("\t按Enter键返回上一级\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
	else {
		printf("\n查询到有%d个员工符合要求。\n", flag);
		printf("\n删除员工请按1，修改信息请按2，继续查询请按3，返回上一级请按4，返回菜单请按0：");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
}
void search_year() /* 按工龄查找函数 */
{
	int m = read();
	int year;
	int i, button, flag = 0;  //flag相当于符合要求的人数
	printf("\n请输入要查找的工龄：");
	scanf("%d", &year);
	for (i = 0; i < m; i++)
	{
		if (staff[i].year == year)
		{
			if (flag == 0)
			{
				printf("\n找到以下信息：\n");
				printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
			}
			flag++;
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
	}
	if (flag == 0)
	{
		printf("\n\t对不起，公司没有该员工！\n");
		printf("\t按Enter键返回上一级\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
	else {
		printf("\n查询到有%d个员工符合要求。\n", flag);
		printf("\n删除员工请按1，修改信息请按2，继续查询请按3，返回上一级请按4，返回菜单请按0：");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
}
