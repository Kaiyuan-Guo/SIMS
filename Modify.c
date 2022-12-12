#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 修改函数 */
void Modify() 
{
	int num;				//工号
	char name[10] = { 0 };  //姓名
	int year;				//工龄
	char category[10] = { 0 };		//员工类别
	int duration;			//周工作时长
	float wage;				//周工资
	int m = read();
	/* a,b,c,d都充当按钮，i用于循环，flag是标志 */
	int a, b, c, d, i, flag = 0;
	printf("\n");
	printf("请输入要修改的职工的工号：");
	scanf("%d", &num);
	system("cls");
	for (i = 0; i < m; i++)
	{
		if (staff[i].num == num)
		{
			flag = 1;
			printf("\n已找到该职工，其信息为：\n");
			printf("\n  工号\t\t姓名\t工龄(年)\t类别\t周工作时长(时)\t周工资(元)  \n");
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
			printf("\n确认修改请按1，取消修改请按0:");
			scanf("%d", &a);
			if (a == 1)
			{
				printf("\n需要进行修改的选项：\n 1.工号 2.姓名 3.工龄 4.周工作时长\n");
				printf("请输入要修改的选项的序号：");
				scanf("%d", &b);
				do {
					switch (b)
					{
					case 1:printf("请输入修改后工号：");
						scanf("%d", &num);
						staff[i].num = num;
						break;
					case 2:printf("请输入修改后姓名：");
						scanf("%s", &name);
						strcpy(staff[i].name, name);
						break;
					case 3:printf("请输入修改后工龄：");
						scanf("%d", &year);
						staff[i].year = year;
						if (year >= 5) {
							strcpy(staff[i].category, "老职工");
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 50.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 2000.0 + 75.0 * (staff[i].duration - 40);
							}
						}
						else {
							strcpy(staff[i].category, "新职工");
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 30.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 1200.0 + 45.0 * (staff[i].duration - 40);
							}
						}
						break;
					case 4:printf("请输入修改后周工作时长：");
						scanf("%d", &duration);
						staff[i].duration = duration;
						if (staff[i].year >= 5) {
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 50.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 2000.0 + 75.0 * (staff[i].duration - 40);
							}
						}
						else {
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 30.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 1200.0 + 45.0 * (staff[i].duration - 40);
							}
						}
						break;
					}
					printf("\n 确认修改请按1，重新输入请按2：");
					scanf("%d", &c);
					if (c == 1)
					{
						system("cls");
						save(m);
						printf("\n");
						Output();
					}
				} while (c == 2);
			}
		}
		else if (i == (m - 1)) i++;  /*  当遍历完没有符合的工号时，令i=m,跳出循环 */
	}
	if (flag == 0)
	{
		printf("\n\t\t该职工不存在!\n");
		printf("\n继续修改请按1，返回菜单请按0：");
		scanf("%d", &d);
	}
	else {
		printf("\n继续修改请按1，返回菜单请按0：");
		scanf("%d", &d);
	}
	system("cls");
	switch (d)
	{
	case 1:Output();
		Modify();
		break;
	case 0:main();
		break;
	default:break;
	}
	system("cls");
}