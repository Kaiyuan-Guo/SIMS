#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
/* ���Һ��� */
void Search()
{
	int button, flag ;
	do {
		printf("\n �����Ų�ѯ�밴1����������ѯ�밴2���������ѯ�밴3�����ز˵��밴0��");
		scanf("%d", &button);
		if (button >= 0 && button <= 3)
		{
			flag = 1;
			break;
		}
		else {
			flag = 0;
			printf("\n����������������ѡ��");
		}
	} while (flag == 0);
	system("cls");
	while (flag == 1)
	{
		switch (button)
		{
		case 0:main();
			break;
		case 1:search_num();
			break;
		case 2:search_name();
			break;
		case 3:search_year();
			break;
		default:break;
		}
		system("cls");
	}
}
void search_num() /* �����Ų��Һ���*/
{
	int m = read();
	int start, end, mid = 0, number = 0, i, button;
	start = staff[0].num;	//�����ʼ�Ĺ���
	end = staff[m - 1].num; //���ĩβ�Ĺ���
	printf("\n������Ҫ��ѯ��ְ���Ĺ��ţ�");
	scanf("%d", &number);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (number < mid)
		{
			end = mid - 1;
		}
		else if (number > mid) {
			start = mid + 1;
		}
		else {
			break;
		}
	}
	system("cls");
	if (start <= end)
	{
		printf("\n���ҵ���Ա��������ϢΪ��");
		printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
		for (i = 0; i < m; i++)	//ͨ��ѭ��ƥ�䣬��������Ϣ���
		{
			if(staff[i].num==mid)
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
		printf("\nɾ��Ա���밴1���޸���Ϣ�밴2��������ѯ�밴3��������һ���밴4�����ز˵��밴0��");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
	else {	//�����꣬start>end,˵��û���ҵ�
		printf("\n\t\t�Բ��𣬹�˾û�и�Ա����\n");
		printf("\n\t\t��Enter��������һ��\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
}
void search_name() /* ���������Һ��� */
{
	int m = read();
	char name[10] = { 0 };
	int i, button, flag = 0;  //flag�൱�ڷ���Ҫ�������
	printf("\n������Ҫ���ҵ�������");
	scanf("%s", &name);
	for (i = 0; i < m; i++)
	{
		if (strcmp(staff[i].name, name) == 0)
		{
			if (flag == 0)
			{
				printf("\n�ҵ�������Ϣ��\n");
				printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
			}
			flag++;
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
	}
	if (flag == 0)
	{
		printf("\n\t�Բ��𣬹�˾û�и�Ա����\n");
        printf("\t��Enter��������һ��\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
	else {
		printf("\n��ѯ����%d��Ա������Ҫ��\n", flag);
		printf("\nɾ��Ա���밴1���޸���Ϣ�밴2��������ѯ�밴3��������һ���밴4�����ز˵��밴0��");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
}
void search_year() /* ��������Һ��� */
{
	int m = read();
	int year;
	int i, button, flag = 0;  //flag�൱�ڷ���Ҫ�������
	printf("\n������Ҫ���ҵĹ��䣺");
	scanf("%d", &year);
	for (i = 0; i < m; i++)
	{
		if (staff[i].year == year)
		{
			if (flag == 0)
			{
				printf("\n�ҵ�������Ϣ��\n");
				printf("\n  ����\t\t����\t����(��)\t���\t�ܹ���ʱ��(ʱ)\t�ܹ���(Ԫ)  \n");
			}
			flag++;
			printf("\n  %d\t\t%s\t %d\t\t%s\t\t%d\t%8.2f\n", staff[i].num, staff[i].name,
				staff[i].year, staff[i].category, staff[i].duration, staff[i].wage);
		}
	}
	if (flag == 0)
	{
		printf("\n\t�Բ��𣬹�˾û�и�Ա����\n");
		printf("\t��Enter��������һ��\n");
		getchar();
		getchar();
		system("cls");
		Search();
	}
	else {
		printf("\n��ѯ����%d��Ա������Ҫ��\n", flag);
		printf("\nɾ��Ա���밴1���޸���Ϣ�밴2��������ѯ�밴3��������һ���밴4�����ز˵��밴0��");
		scanf("%d", &button);
		switch (button)
		{
		case 0:system("cls");
			main();
			break;
		case 1:Delete();
			break;
		case 2:Modify();
			break;
		case 3:break;
		case 4:system("cls");
			Search();
			break;
		default:break;
		}
	}
}
