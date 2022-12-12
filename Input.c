#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 录入函数 */
void Input()
{
	int i, m, number = 0;
	printf("请输入需要创建信息的职工人数（1—100）\n");
	scanf("%d", &m);
	system("cls");
	if (m > 100) {
		printf("\t\t\t超出范围，请重新输入!\n");
		Input();
	}
	else {
		for (i = 0; i < m; i++)
		{
			printf("第%d个职工信息输入（按回车确认）：\n", i + 1);
			printf("请输入工号：");
			scanf("%d", &number);
			for (int j = 0; j <= i; j++) {
				if (staff[j].num == number)
				{
					printf("工号为%d的人已存在，请重新输入：",number);
					scanf("%d", &number);
					j = 0;
				}
			}
			staff[i].num = number;
			printf("请输入姓名：");
			scanf("%s", &staff[i].name);
			printf("请输入工龄（单位：年）：");
			scanf("%d", &staff[i].year);
			printf("请输入周工作时长（单位：小时）：");
			scanf("%d", &staff[i].duration);
			if (staff[i].year >= 5) {
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
			system("cls");
		}
		save(m);
		printf("\n一个新的职工档案创建完毕！\n");
		printf("\n按Enter键返回菜单\n");
		getchar();
		getchar();
		system("cls");
	}
}