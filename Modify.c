#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* �޸ĺ��� */
void Modify() 
{
	int num;				//����
	char name[10] = { 0 };  //����
	int year;				//����
	char category[10] = { 0 };		//Ա�����
	int duration;			//�ܹ���ʱ��
	float wage;				//�ܹ���
	int m = read();
	/* a,b,c,d���䵱��ť��i����ѭ����flag�Ǳ�־ */
	int a, b, c, d, i, flag = 0;
	printf("\n");
	printf("������Ҫ�޸ĵ�ְ���Ĺ��ţ�");
	scanf("%d", &num);
	system("cls");
	for (i = 0; i < m; i++)
	{
		if (staff[i].num == num)
		{
			flag = 1;
			printf("\n���ҵ���ְ��������ϢΪ��\n");
			printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
			printf("\nȷ���޸��밴1��ȡ���޸��밴0:");
			scanf("%d", &a);
			if (a == 1)
			{
				printf("\n��Ҫ�����޸ĵ�ѡ�\n 1.���� 2.���� 3.���� 4.�ܹ���ʱ��\n");
				printf("������Ҫ�޸ĵ�ѡ�����ţ�");
				scanf("%d", &b);
				do {
					switch (b)
					{
					case 1:printf("�������޸ĺ󹤺ţ�");
						scanf("%d", &num);
						staff[i].num = num;
						break;
					case 2:printf("�������޸ĺ�������");
						scanf("%s", &name);
						strcpy(staff[i].name, name);
						break;
					case 3:printf("�������޸ĺ��䣺");
						scanf("%d", &year);
						staff[i].year = year;
						if (year >= 5) {
							strcpy(staff[i].category, "��ְ��");
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 50.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 2000.0 + 75.0 * (staff[i].duration - 40);
							}
						}
						else {
							strcpy(staff[i].category, "��ְ��");
							if (staff[i].duration <= 40)
							{
								staff[i].wage = 30.0 * staff[i].duration;
							}
							else {
								staff[i].wage = 1200.0 + 45.0 * (staff[i].duration - 40);
							}
						}
						break;
					case 4:printf("�������޸ĺ��ܹ���ʱ����");
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
					printf("\n ȷ���޸��밴1�����������밴2��");
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
		else if (i == (m - 1)) i++;  /*  ��������û�з��ϵĹ���ʱ����i=m,����ѭ�� */
	}
	if (flag == 0)
	{
		printf("\n\t\t��ְ��������!\n");
		printf("\n�����޸��밴1�����ز˵��밴0��");
		scanf("%d", &d);
	}
	else {
		printf("\n�����޸��밴1�����ز˵��밴0��");
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