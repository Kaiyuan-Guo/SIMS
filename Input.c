#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* ¼�뺯�� */
void Input()
{
	int i, m, number = 0;
	printf("��������Ҫ������Ϣ��ְ��������1��100��\n");
	scanf("%d", &m);
	system("cls");
	if (m > 100) {
		printf("\t\t\t������Χ������������!\n");
		Input();
	}
	else {
		for (i = 0; i < m; i++)
		{
			printf("��%d��ְ����Ϣ���루���س�ȷ�ϣ���\n", i + 1);
			printf("�����빤�ţ�");
			scanf("%d", &number);
			for (int j = 0; j <= i; j++) {
				if (staff[j].num == number)
				{
					printf("����Ϊ%d�����Ѵ��ڣ����������룺",number);
					scanf("%d", &number);
					j = 0;
				}
			}
			staff[i].num = number;
			printf("������������");
			scanf("%s", &staff[i].name);
			printf("�����빤�䣨��λ���꣩��");
			scanf("%d", &staff[i].year);
			printf("�������ܹ���ʱ������λ��Сʱ����");
			scanf("%d", &staff[i].duration);
			if (staff[i].year >= 5) {
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
			system("cls");
		}
		save(m);
		printf("\nһ���µ�ְ������������ϣ�\n");
		printf("\n��Enter�����ز˵�\n");
		getchar();
		getchar();
		system("cls");
	}
}