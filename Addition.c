#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* ��Ӻ��� */
void Addition()
{
	int m = read();
	int i, n, number;
	printf("��������Ҫ�����Ϣ��ְ��������");
	scanf("%d", &n);
	if (m + n > 100) {
		printf("\n �Բ�������ӵ�ְ������������Χ�����������루1��%d֮��)��", 100 - m);
		Addition();
	}
	else {
		for (i = m; i < m + n; i++)
		{
			printf("��%d��ְ������Ϣ¼�루���س�ȷ�ϣ���\n", i + 1);
			printf("�����빤�ţ�");
			scanf("%d", &number);
			for (int j = 0; j <= i; j++) {
				if (staff[j].num == number)
				{
					printf("\n����Ϊ%d�����Ѵ��ڣ����������룺", number);
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
		save(m+n);
		system("cls");
		printf("\n���ְ�������ɹ���\n");
		Output();
		printf("\n��Enter�����ز˵�\n");
		getchar();
		getchar();
		system("cls");
	}
}