#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100  //���Ա������

//ְ����Ϣ�ṹ��
struct employee {
	int num;          //����
	char name[10];    //����
	int year;         //����
	char category[10];//Ա�����
	int duration;     //�ܹ���ʱ��
	float wage;       //�ܹ���
}staff[N],temp;		  //temp��������ʱ�䵱�м����

//���ܺ�������
void Menu();		//�˵�����
void Input();		//����ְ����Ϣ
void save(int m);	//������Ϣ
int  read();		//��ȡ��Ϣ
void Output();		//�����Ϣ
void Addition();	//��Ӻ���
void Modify();		//�޸Ĳ���
void Delete();		//ɾ������
void Search();		//���Һ���
void search_num();	//�������۰����
void search_name();	//����������
void search_year();	//���������
void Sort();		//�����Ų�������
void order();		//ð������
void Analyse();		//ְ������ͳ��

//������
int main()
{
	int button, flag;
	while (1)
	{
		do {
			Menu(); //���ò˵�����
			printf("����������Ҫ���������(1-9):  ");
			scanf("%d", &button);
			if (button >= 1 && button <= 9) {
				flag = 1;         break;
			}
			else {
				flag = 0;
				system("cls");	//����
				printf("\n\t\t\t����������������ѡ��!");
			}
		} while (flag == 0);
		switch (button) {
		case 1:   system("cls");
			printf("\n");
			printf("\t\t¼��ְ����Ϣ\n");
			Input();
			break;
		case 2:   system("cls");
			printf("\n");
			printf("\t\t���ְ����Ϣ\n");
			Output();
			printf("\n��Enter�����ز˵�\n");
			getchar();
			getchar();
			system("cls");
			break;
		case 3:   system("cls");
			printf("\n");
			printf("\t\t���ְ����Ϣ\n");
			Addition();
			break;
		case 4:   system("cls");
			printf("\n");
			printf("\t\t�޸�ְ����Ϣ\n");
			Output();                      //�����������
			Modify();
			break;
		case 5:   system("cls");
			printf("\n");
			printf("\t\tɾ��ְ����Ϣ\n");
			Delete();
			break;
		case 6:   system("cls");
			printf("\n");
			printf("\t\t����ְ����Ϣ\n");
			Search();
			break;
		case 7:   system("cls");
			printf("\n");
			printf("\t\tְ����Ϣ����\n");
			Sort();
			break;
		case 8:   system("cls");
			printf("\n");
			printf("\t\tְ����������ͳ��\n");
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
void save(int m)  /*�����ļ�����*/
{
	int i;
	FILE* fp;
	if ((fp = fopen("clerk_list.txt", "wb")) == NULL)//�����ļ����ж��Ƿ��ܴ�
	{
		printf("open file error!\n");
		exit(0);
	}
	/*���ڴ���ְ����Ϣ����������ļ���ȥ*/
	for (i = 0; i < m; i++)
	{
		/* ������ģʽ���ɱ�֤��ֵ�����ڴ���ǰ�󱣳�һ�� */
		if (fwrite(&staff[i], sizeof(struct employee), 1, fp) != 1)
			/* &staff[i]:Ҫ������ݵĵ�ַ��sizeof(struct empioyee):��ȡһ�������
			���ȣ�1:������ĸ�����fp:Ŀ���ļ�ָ��*/
			printf("file write error!\n");
	}
	fclose(fp);
}
int read() /*���뺯��*/
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
			fread(&staff[i], sizeof(struct employee), 1, fp);//��ȡ
			i++;
		} while (feof(fp) == 0);  //������ϵ��ļ�������,û�м�⵽��βʱ������0
	}
	fclose(fp);
	return(i - 1); //��������
}
