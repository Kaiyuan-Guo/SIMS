#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* ͳ����ʾÿСʱƽ�������Լ���߹���Ա������ */
void Analyse()
{
	int m = read();
	/* i,j����ѭ����key���ڼ�¼��߹���Ա����������H[N]��¼Ա�����ļ��е�λ�� */
	int i, j = 0, key = 0, H[N] = { 0 };
	float most = staff[0].wage;  //most��¼��߹���
	double sum = 0, avg = 0;	 //sum�ǹ����ܺͣ�avg��ÿСʱƽ������
	
	for (i = 0; i < m; i++)
	{
		sum += staff[i].wage;
		if (most < staff[i + 1].wage && i < m - 1)
		{
			most = staff[i + 1].wage;  //�ҳ���߹���
		}
	}
	for (i = 0; i < m ; i++)
	{
		/* ��¼������most��ͬ��Ա�� */
		while (j < N && staff[i].wage == most)
		{
			H[j] = i;
			key = j;
			j++;
			break;
		}
	}
	avg = sum / (m - 1);
	printf("\n\t��˾ȫ��Ա��ÿСʱƽ������Ϊ��%8.2f\n",avg);
	printf("\n\t������߹���Ա����ϢΪ��\n");
	printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
	for (j = 0; j <= key; j++)
	{
		printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[H[j]].num, staff[H[j]].name,
			staff[H[j]].year, staff[H[j]].category, staff[H[j]].duration, staff[H[j]].wage);
	}
	printf("\n\t��Enter�����ز˵�\n");
	getchar();
	getchar();
	system("cls");
} 
