#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* ɾ������ */
void Delete()
{
	int m = read();
	/* i,j����ѭ����t,n�䵱��ť��flag�Ǳ�־ */
	int i, j, t, n, flag, number;
	Output(); //�����������
	printf("������Ҫɾ����ְ���Ĺ��ţ�");
	scanf("%d", &number);
	for (flag = 1, i = 0; flag && i < m ; i++)
	{
		if (staff[i].num == number)
		{
			printf("���ҵ����ˣ�ԭʼ��ϢΪ��\n");
			printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
			printf("ȷ��ɾ���밴1��ȡ��ɾ���밴0��");
			scanf("%d", &t);
			if (t == 1)
			{
				/* ���ɾ������������ְ����Ϣ����ǰ��һλ */
				for (j = i; j < m - 1; j++)
					staff[j] = staff[j + 1]; /* ���ҵ���j��Ա��ʱ��j�Լ���1������Ӧ�ð���Ϣ��ֵ����j-1����*/
				flag = 0;
			}
			else flag = 2;

		}
	}
	system("cls");
	switch (flag)
	{
	case 0:m = m - 1;
		printf("\n\t\t\tɾ���ɹ���\n");
		save(m);  //���ñ��溯��
		Output(); //�����������
		break;
	case 1:printf("\n\t\t\t�Բ��𣬹�˾û�и�Ա����\n");
		Output();
		break;
	case 2:printf("\n\t\t\tȡ��ɾ����\n");
		break;
	}
	printf("\n����ɾ���밴1�����ز˵��밴0��");
	scanf("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:Delete();
		break;
	case 0:main();
		break;
	default: break;
	}
	system("cls");
}