#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "dataStructure.h"
#include "lxz.h"
#include "menu.h"

void main()
{
	int option;
	// system("chcp 65501"); //���ն���UTF-8�����ʽ���
	system("chcp 936");
	ReadFromFile();
	printf("\n");
	calculatePerformanceData();
	printf("\n");
	system("pause");
	system("cls");
	while (1)
	{
		printf("=================��ӭʹ��ѧ���ɼ�����ϵͳ=================\n");
		printf("||      1-����ά��                       2-��������      ||\n");
		printf("||      3-�������                       4-��ѯ��Ϣ      ||\n");
		printf("||      5-�ɼ�ͳ��                       6-�����˳�      ||\n");
		printf("==========================================================\n");
		while (1)
		{
			fflush(stdin);
			printf("�������˵����:");
			scanf("%d", &option);
			if (option < 1 || option > 6)
				printf("������������������.\n");
			else
				break;
		}
		switch (option)
		{
		case 1: Data_maintenance();		 system("pause");    system("cls"); break;
		case 2: Calculate_rank();      	 system("pause"); 	 system("cls"); break;
		case 3: Sort_print();          	 system("pause"); 	 system("cls"); break;
		case 4: Inquire_information();   system("pause");	 system("cls"); break;
		case 5: Performance_statistic(); system("pause");	 system("cls"); break;
		case 6: SaveToFile();             return;
		}
	}
//	SaveToFile();
//	printf("�ɹ�������Ϣ\n");
//	printf("���������ллʹ��\n");
}