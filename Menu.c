#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* 菜单函数 */
void Menu() {
	system("cls");

	system("color E0");//背景色为淡黄色，前景色为黑色
	
	printf("\n\n");
	printf("                             Welcome to                          \n");
	printf("            Staff Information Management System (SIMS)           \n\n");
	printf("*****************************************************************\n");
	printf("*          1.录入职工信息");	printf("	§	2.输出职工信息          *\n");
	printf("*          3.添加职工信息");	printf("	§	4.修改职工信息          *\n");
	printf("*          5.删除职工信息");	printf("	§	6.查找职工信息          *\n");
	printf("*          7.职工信息排序");	printf("	§	8.职工工资统计          *\n");
	printf("*          9.退出职工系统       §                              *\n");
	printf("*****************************************************************\n");

	printf("说明：*如首次使用 尚未输入数据 请先输入数据 \n      *输入的数据将自动保存 \n\
      *录入职工信息时请使用连续的工号 \n      *再次选择输入功能时原数据将被覆盖\n\n");
}

