#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100  //最大员工数量

//职工信息结构体
struct employee {
	int num;          //工号
	char name[10];    //姓名
	int year;         //工龄
	char category[10];//员工类别
	int duration;     //周工作时长
	float wage;       //周工资
}staff[N],temp;		  //temp用于排序时充当中间变量

//功能函数声明
void Menu();		//菜单函数
void Input();		//输入职工信息
void save(int m);	//储存信息
int  read();		//读取信息
void Output();		//输出信息
void Addition();	//添加函数
void Modify();		//修改操作
void Delete();		//删除操作
void Search();		//查找函数
void search_num();	//按工号折半查找
void search_name();	//按姓名查找
void search_year();	//按工龄查找
void Sort();		//按工号插入排序
void order();		//冒泡排序
void Analyse();		//职工数据统计

//主函数
int main()
{
	int button, flag;
	while (1)
	{
		do {
			Menu(); //调用菜单函数
			printf("请输入你需要操作的序号(1-9):  ");
			scanf("%d", &button);
			if (button >= 1 && button <= 9) {
				flag = 1;         break;
			}
			else {
				flag = 0;
				system("cls");	//清屏
				printf("\n\t\t\t您输入有误，请重新选择!");
			}
		} while (flag == 0);
		switch (button) {
		case 1:   system("cls");
			printf("\n");
			printf("\t\t录入职工信息\n");
			Input();
			break;
		case 2:   system("cls");
			printf("\n");
			printf("\t\t输出职工信息\n");
			Output();
			printf("\n按Enter键返回菜单\n");
			getchar();
			getchar();
			system("cls");
			break;
		case 3:   system("cls");
			printf("\n");
			printf("\t\t添加职工信息\n");
			Addition();
			break;
		case 4:   system("cls");
			printf("\n");
			printf("\t\t修改职工信息\n");
			Output();                      //调用输出函数
			Modify();
			break;
		case 5:   system("cls");
			printf("\n");
			printf("\t\t删除职工信息\n");
			Delete();
			break;
		case 6:   system("cls");
			printf("\n");
			printf("\t\t查找职工信息\n");
			Search();
			break;
		case 7:   system("cls");
			printf("\n");
			printf("\t\t职工信息排序\n");
			Sort();
			break;
		case 8:   system("cls");
			printf("\n");
			printf("\t\t职工工资数据统计\n");
			Analyse();
			break;
		case 9:	  system("cls");
			printf("\n\n\n\t\t\tThank you for using !\n\n\n");
			getchar();
			exit(0);
			break;
		}
	}
}
void save(int m)  /*保存文件函数*/
{
	int i;
	FILE* fp;
	if ((fp = fopen("clerk_list.txt", "wb")) == NULL)//创建文件并判断是否能打开
	{
		printf("open file error!\n");
		exit(0);
	}
	/*将内存中职工信息输出到磁盘文件中去*/
	for (i = 0; i < m; i++)
	{
		/* 二进制模式，可保证数值精度在储存前后保持一致 */
		if (fwrite(&staff[i], sizeof(struct employee), 1, fp) != 1)
			/* &staff[i]:要输出数据的地址，sizeof(struct empioyee):获取一个单体的
			长度，1:数据项的个数，fp:目标文件指针*/
			printf("file write error!\n");
	}
	fclose(fp);
}
int read() /*导入函数*/
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("clerk_list.txt", "rb")) == NULL)
	{
		printf("open flie error!\n");
		exit(0);
	}
	else {
		do {
			fread(&staff[i], sizeof(struct employee), 1, fp);//读取
			i++;
		} while (feof(fp) == 0);  //检测流上的文件结束符,没有检测到结尾时，返回0
	}
	fclose(fp);
	return(i - 1); //返回人数
}
