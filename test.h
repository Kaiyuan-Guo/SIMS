#pragma once
#ifndef _HEAD_H_
#define _HEAD_H_

/* ��ͷ�ļ������˲��Ե��ļ���Ϣ */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

//ְ����Ϣ�ṹ��
struct employee {
	int num;          //����
	char name[10];    //����
	int year;         //����
	char category[10];//Ա�����
	int duration;     //�ܹ���ʱ��
	float wage;       //�ܹ���
}staff[N], temp;	  //temp��������ʱ�䵱�м����

//������
int main();

//���ܺ�������
void Menu();		//�˵�����
void Input();		//����ְ����Ϣ
void save(int m);	//������Ϣ
int  read();		//��ȡ��Ϣ
void Output();		//�����Ϣ
void Addition();	//��Ӳ���
void Modify();		//�޸Ĳ���
void Delete();		//ɾ������
void Search();		//���Һ���
void search_num();	//�������۰����
void search_name();	//����������
void search_year();	//���������
void Sort();		//�����Ų�������
void order();		//�������Ϣ��������
void Analyse();		//ְ������ͳ��

#endif // !_HEAD_H_

