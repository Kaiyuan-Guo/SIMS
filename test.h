#pragma once
#ifndef _HEAD_H_
#define _HEAD_H_

/* 该头文件包括了测试的文件信息 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

//职工信息结构体
struct employee {
	int num;          //工号
	char name[10];    //姓名
	int year;         //工龄
	char category[10];//员工类别
	int duration;     //周工作时长
	float wage;       //周工资
}staff[N], temp;	  //temp用于排序时充当中间变量

//主函数
int main();

//功能函数声明
void Menu();		//菜单函数
void Input();		//输入职工信息
void save(int m);	//储存信息
int  read();		//读取信息
void Output();		//输出信息
void Addition();	//添加操作
void Modify();		//修改操作
void Delete();		//删除操作
void Search();		//查找函数
void search_num();	//按工号折半查找
void search_name();	//按姓名查找
void search_year();	//按工龄查找
void Sort();		//按工号插入排序
void order();		//供输出信息函数调用
void Analyse();		//职工数据统计

#endif // !_HEAD_H_

