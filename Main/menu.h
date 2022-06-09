/* �������в˵�չʾ���� */


/* �Զ��庯�� */

int checkSUGScore(SUG *pSUG);
int checkSPGScore(SPG *pSPG);
void printSUGTitle();
void printSPGTitle();
void printSUGBaseData(SUG *pSUG);
void printSPGBaseData(SPG *pSPG);
void printSUGInfo(SUG *pSUG);
void printSPGInfo(SPG *pSPG);
void calculateSUGTotalScore();
void calculateSPGTotalScore();

/* �Զ��庯�� */


/* 1.A.�������ݹ��������� */

void BaseData_maintenance();
void addBaseData();
void addStudent(int stu, int quantity);
void modifyBaseData();
void modifyStudent(int stu, int id);
void deleteBaseData();
void deleteStudent(int stu, int id);
void deleteUStu(int id);
void deletePStu(int id);
void inquireBaseData();
void inquireStu(int stu, int id);

/* 1.A.�������ݹ��������� */


/* 1.B.�ɼ����������� */

void PerformanceData_maintenance();
void inputPerformanceData();
void inputScore(int stu, int quantity);
void modifyPerformanceData();
void modifyScore(int stu, int id);
void deletePerformanceData();
void deleteScore(int stu, int id);
void inquirePerformanceData();
void inquireScore(int stu, int id);
void calculatePerformanceData();

/* 1.B.�ɼ����������� */


/* 2.���������������� */

void Calculate_rank();
void calculateSUGRank();
void calculateSPGRank();

/* 2.���������������� */


/* 3.��������������� */

void Sort_print();

/* 3.��������������� */


/* 4.��ѯ���ܲ������� */

void Inquire_information();

/* 4.��ѯ���ܲ������� */


/* 5.ͳ�ƹ��ܲ˵����� */

void Performance_statistic();

/* 5.ͳ�ƹ��ܲ˵����� */


//��鱾�����ɼ�(��ѧ��Ӣ�C����)�Ƿ�����Ч�ɼ���-1����������򷵻�1�� ���򷵻�0
int checkSUGScore(SUG *pSUG)
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		if (pSUG->score[i] == -1)
		{
			return 1;
		}
	}
	return 0;
}
//����о����ɼ�(�ۺϿγ̡�����)�Ƿ�����Ч�ɼ���-1����������򷵻�1�� ���򷵻�0
int checkSPGScore(SPG *pSPG)
{
	int i;
	for ( i = 0; i < 2; i++)
	{
		if (pSPG->score[i] == -1)
		{
			return 1;
		}
	}
	return 0;
}
//���������������Ϣ��ɲ���
void printSUGTitle()
{printf("ѧ��\t����\t�Ա�\tרҵ\t\t�༶\n");}
//���һ���������Ļ�����Ϣ
void printSUGBaseData(SUG *pSUG)
{
	if(pSUG->sex == 0)
		printf("%d\t%s\tŮ\t%s\t%s\n", pSUG->id, pSUG->name, pSUG->profession, pSUG->class);
	else
		printf("%d\t%s\t��\t%s\t%s\n", pSUG->id, pSUG->name, pSUG->profession, pSUG->class);
}
//���һ����������ȫ����Ϣ
void printSUGInfo(SUG *pSUG)
{
	if (pSUG->sex == 0)
		printf("%d\t%s\tŮ\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
	else
		printf("%d\t%s\t��\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
}
//����о���������Ϣ��ɲ���
void printSPGTitle()
{printf("ѧ��\t����\t�Ա�\tרҵ\t�༶\t�о�����\t\t��ʦ\\n");}
//���һ���о����Ļ�����Ϣ
void printSPGBaseData(SPG *pSPG)
{
	if (pSPG->sex == 0)
		printf("%d\t%s\tŮ\t%s\t%s\t%s\t\t%s\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
	else
		printf("%d\t%s\t��\t%s\t%s\t%s\t%s\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
}
//���һ���о�����ȫ����Ϣ
void printSPGInfo(SPG *pSPG)
{
	if (pSPG->sex == 0)
		printf("%d\t%s\tŮ\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher,
		pSPG->score[0], pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
	else
		printf("%d\t%s\t��\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher,
		pSPG->score[0], pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
}
//�Ӳ˵�1������ά��
void Data_maintenance()
{
	int option;
	printf("-------����ά���˵�-------\n");
	printf("1:������������ \t 2:�ɼ�����\n");
	while (1)
	{
		printf("ѡ����Ҫ���������:");
		fflush(stdin);
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("������������������:");
		else
			break;
	}
	switch (option)
	{
	case 1:
		BaseData_maintenance();
		break;
	default:
		PerformanceData_maintenance();//�ɼ�����ά���˵�
		break;
	}
}
//��������ά���˵�
void BaseData_maintenance()
{
	int option;
	printf("-------��������ά���˵�-------\n");
	printf("1.���: ���ѧ��������������\n");
	printf("2.�޸ģ�����ѧ�����޸�����ѧ���ĳ�ѧ���������������������\n");
	printf("3.ɾ��������ѧ��ɾ��һ��ѧ��\n");
	printf("4.��ѯ������ѧ�Ų�ѯһ��ѧ���Ļ�����������\n");
	while (1)
	{
		printf("����ѡ��:");
		fflush(stdin);
		scanf("%d", &option);
		if (option < 1 || option >4)
			printf("������������������.\n");
		else
			break;
	}
	switch (option)
	{
	case 1:	addBaseData();		break;
	case 2: modifyBaseData();	break;
	case 3: deleteBaseData(); 	break;
	case 4: inquireBaseData();	break;
	}
}
//������ݵĲ˵�
void addBaseData()
{
	int stuOption;
	int quantity; //1��ʾ��ӵ�����2��ʾ��Ӷ��
	printf("��ӱ����������о�����\n");
	printf("1:������\t2:�о���\n");
	while (1)
	{
		printf("����ѡ��:");
		scanf("%d", &stuOption);
		if (stuOption != 1 && stuOption != 2)
			printf("������������������.\n");
		else
			break;
	}
	printf("��ӵ������Ƕ��?\n");
	printf("1.���� \t 2.���\n");
	while (1)
	{
		printf("����ѡ��:");
		scanf("%d", &quantity);
		if (quantity != 1 && quantity != 2)
			printf("������������������.\n");
		else
			break;
	}
	addStudent(stuOption, quantity);
}
/**����˵����stuΪҪ��ӵ�ѧ�����ͣ� 1-��������2-�о���;
 * quantityΪ���ģʽ��1-��ӵ�����2-��Ӷ�����ظ�ִ�е������)
 * */
void addStudent(int stu, int quantity)
{
	SUG *newSUG = NULL, *p1 = NULL;
	SPG *newSPG = NULL, *p2 = NULL;
	int number = 0;
	if(stu == 1)
	{
		if (quantity == 1)
			printf("����ñ����������� �Ա�(0-Ů 1-�� ) רҵ �༶:(�Ա�����-1�Խ���)\n");
		else
			printf("�������ɱ����������� �Ա�(0-Ů 1-��) רҵ �༶:(�Ա�����-1�Խ���)\n");
		fflush(stdin);
		while (1)
		{
			printf("�����%d��������:", number + 1);
			newSUG = newSUGNode();
			scanf("%s%d%s%s", &newSUG->name, &newSUG->sex, &newSUG->profession, &newSUG->class);
			if (newSUG->sex == -1) break;
			if (SUGHead == NULL) //����������������ʱ
			{
				SUGHead = newSUG; //�øýڵ�Ϊͷ�ڵ�
				SUGpage[0] = *SUGHead; //������ͷ�ڵ���뷭ҳ����
				SUGHead->id = 1;
				SUGTail = newSUG;
			}
			else
			{
				newSUG->id = SUGTail->id + 1;
				if ((newSUG->id % 10) == 1)
					SUGpage[newSUG->id / 10] = *newSUG; //������������뷭ҳ����
				SUGTail->next = newSUG;
				SUGTail = newSUG;
			}
			number++;
			if(quantity == 1) break;
		}
	printf("�����ϣ������%d������������\n", number);
	}
	else
	{
		if (quantity == 1)
			printf("������о��������� �Ա�(0-Ů 1-��) רҵ �༶ �о����� ��ʦ:(�Ա�����-1�Խ���)\n");
		else
			printf("���������о��������� �Ա�(0-Ů 1-��) רҵ �༶ �о����� ��ʦ:(�Ա�����-1�Խ���)\n");
		fflush(stdin);
		while (1)
		{
			printf("�����%d��ѧ��:", number + 1);
			newSPG = newSPGNode();
			scanf("%s%d%s%s%s%s", &newSPG->name, &newSPG->sex, &newSPG->profession,
				  &newSPG->class, &newSPG->direction, &newSPG->teacher);
			if (newSPG->sex == -1) break;
			if (SPGHead == NULL) //�о�������������ʱ
			{
				SPGHead = newSPG; //�øýڵ�Ϊͷ�ڵ�
				SPGHead->id = 1;
				SPGPage[0] = *newSPG; //���뷭ҳ����
				SPGTail = newSPG;
			}
			else
			{
				newSPG->id = SPGTail->id + 1;
				if ((newSPG->id % 10) == 1)
					SPGPage[newSPG->id / 10] = *newSPG; //������������뷭ҳ����
				SPGTail->next = newSPG;
				SPGTail = newSPG;
			}
			number++;
			if(quantity == 1) break;
		}
	printf("�����ϣ������%d���о�������\n", number);
	}
}
//�����޸Ĳ˵� ��������ѧ�����ͼ�ѧ��
void modifyBaseData()
{
	int id, option;
	printf("-------�����޸Ĳ˵�-------\n");
	printf("��Ҫ�޸ı����������о�����\n");
	printf("1.������ \t 2.�о���\n");
	while (1)
	{
		printf("����ѡ��:");
		fflush(stdin);
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("������������������.\n");
		else
			break;
	}
	printf("����ѧ��:");
	scanf("%d", &id);
	modifyStudent(option, id);
}
//����˵��:stuΪѧ������  1-������ 2-�о���; id:���޸�ѧ����ѧ��
void modifyStudent(int stu, int id)
{
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	int flag = 0; //���ҳɹ���־
	if (stu == 1) //�޸ı�����
	{
		if (SUGHead == NULL)
		{
			printf("�ޱ��������ݿ��޸ģ��������һ������������\n");
			return;
		}
		for (pSUG = SUGHead; pSUG != NULL; pSUG = pSUG->next)
		{
			if (pSUG->id == id) //���ҳɹ�
			{
				flag = 1; //�޸Ĳ��ұ�־
				printf("ѧ��Ϊ%d�ı�����������������:\n", id);
				if (pSUG->sex == 0)
					printf("%-5s Ů %-10s %-5s\n", pSUG->name, pSUG->profession, pSUG->class);
				else
					printf("%-5s �� %-10s %-5s\n", pSUG->name, pSUG->profession, pSUG->class);
				printf("������������ �Ա�0ΪŮ1Ϊ�У� רҵ �༶�Ը���:\n");
				scanf("%s%d%s%d", &pSUG->name, &pSUG->sex, &pSUG->profession, &pSUG->class);
				printf("�޸�ѧ��Ϊ%d�ı������������ϳɹ�\n", id);
				return;
			}
		}
		if (flag == 0) //����ʧ��
			printf("δ�ҵ�ѧ��Ϊ%d�ı������������Ƿ��и�ѧ��\n", id);
	}
	else //�޸��о���
	{
		if (SPGHead == NULL)
		{
			printf("���о������ݿ��޸ģ��������һ���о�������\n");
			return;
		}
		for (pSPG = SPGHead; pSPG != NULL; pSPG = pSPG->next)
		{
			if (pSPG->id == id)
			{
				flag = 1;
				printf("ѧ��Ϊ%d���о���������������:\n", id);
				if (pSPG->sex == 0)
					printf("%-5s Ů %-10s %-5s %-10s %-5s\n", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				else
					printf("%-5s �� %-10s %-5s %-10s %-5s\n", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				printf("������������ �Ա�0ΪŮ1Ϊ�У� רҵ �༶ �о����� ��ʦ�Ը���:\n");
				scanf("%s%d%s%d", &pSPG->name, &pSPG->sex, &pSPG->profession, &pSPG->class, &pSPG->direction, &pSPG->teacher);
				printf("�޸�ѧ��Ϊ%d���о����������ϳɹ�\n", id);
				return;
			}
		}
		if (flag == 0)
			printf("δ�ҵ�ѧ��Ϊ%d���о����������Ƿ��и�ѧ��\n", id);
	}
}
//ɾ�����ݲ˵�
void deleteBaseData()
{
	int stu, id;
	printf("----------ɾ�����ݲ˵�----------\n");
	printf("ɾ�������������о��������ݣ�");
	printf("1-������ 2-�о���");
	scanf("%d", &stu);
	printf("���뱻ɾ��ѧ����ѧ��:");
	scanf("%d", &id);
	deleteStudent(stu, id);
}
//ɾ�����ݺ���:ѧ��������ͷŸýڵ��ڴ�
void deleteStudent(int stu, int id)
{
	if (stu == 1)
		deleteUStu(id); // ɾ��ѧ��Ϊid�ı�����
	else
		deletePStu(id); // ɾ��ѧ��Ϊid���о���
}
//����ѧ��ɾ��һ�����������ͷŽڵ��ڴ棩
void deleteUStu(int id)
{
	SUG *pFront, *pBehind, *temp = NULL;
	pFront = SUGHead;
	pBehind = pFront->next;
	if (pFront->id == id) //����ͷ�ڵ����Ҫɾ���Ķ���ʱ
	{
		temp = pFront;
		pFront = pFront->next;
		free(temp);
		printf("�ñ������ѱ�ɾ��\n");
		return;
	}
	while(pBehind != NULL && pBehind->id != id) //ʹ��pBehindѰ����Ҫɾ���Ľڵ�
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	if(pBehind == NULL)//δ�ҵ���ɾ���Ķ���,����
	{
		printf("δ�ҵ�Ҫ��ɾ���Ķ���\n");
		return;
	}
	else//��ʱpBehind����Ҫɾ���Ķ���
	{
		temp = pBehind;
		pBehind = pBehind->next;
		pFront->next = pBehind;
		free(temp);
		printf("�ñ������ѱ�ɾ��\n");
	}
}
//����ѧ��ɾ��һ���о������ͷŽڵ��ڴ棩
void deletePStu(int id)
{
	SPG *pFront, *pBehind, *temp = NULL;
	pFront = SPGHead;
	pBehind = pFront->next;
	if (pFront->id == id) //����ͷ�ڵ����Ҫɾ���Ķ���ʱ
	{
		temp = pFront;
		pFront = pFront->next;
		free(temp);
		printf("���о�����ɾ��\n");
		return;
	}
	while(pBehind != NULL && pBehind->id != id)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	if(pBehind == NULL)//δ�ҵ���ɾ���Ķ���,����
	{
		printf("δ�ҵ�Ҫ��ɾ���Ķ���\n");
		return;
	}
	else//��ʱpBehind����Ҫɾ���Ķ���
	{
		temp = pBehind;
		pBehind = pBehind->next;
		pFront->next = pBehind;
		free(temp);
		printf("���о����ѱ�ɾ��\n");
	}
}
//��ѯ���ݲ˵� 
void inquireBaseData()
{
	int stu, id;
	printf("----------��ѯ���ݲ˵�----------\n");
	printf("��ѯ�����������о���������?\n");
	printf("1-������\t2-�о���\n");
	printf("������:");
	scanf("%d", &stu);
	while (stu != 1 && stu != 2)
	{
		printf("�����ѡ��.����������:");
		scanf("%d", &stu);
	}
	printf("��������Ҫ����ѧ����ѧ��:");
	scanf("%d", &id);
	inquireStu(stu, id);
}
//���ݽ��յ�ѧ�����ͺ�ѧ�ţ��βΣ����в��Ҳ������������
void inquireStu(int stu, int id)
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	if (stu == 1) //���ұ���������
	{
		do
		{
			if (pSUG->id == id)
			{
				// system("cls");
				printf("���ҳɹ���ѧ��Ϊ%d�ı�����������������:\n", id);
				printSUGTitle();
				printSUGBaseData(pSUG);
				if (checkSUGScore(pSUG) == 1)
					printf("��ʾ:ѧ��Ϊ%d�ı������ɼ�������Ч���ݣ�����\n", id);
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG->id != id);
	}
	else //�����о�������
	{
		do
		{
			if (pSPG->id == id)
			{
				system("cls");
				printf("���ҳɹ���ѧ��Ϊ%d���о���������������:\n", id);
				printSPGTitle();
				printSPGBaseData(pSPG);
				if (checkSPGScore(pSPG) == 1)
					printf("��ʾ:ѧ��Ϊ%d���о����ɼ�������Ч���ݣ�����\n", id);
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG->id != id);
	}
}

//�ɼ����ݹ���˵�
void PerformanceData_maintenance()
{
	int option;
	printf("-------�ɼ�����ά���˵�-------\n");
	printf("1.���: ���ѧ���ɼ���������\n");
	printf("2.�޸ģ�����ѧ�����޸�����ѧ���ĳ�ѧ����������ɼ���������\n");
	printf("3.ɾ��������ѧ��ɾ��һ��ѧ��\n");
	printf("4.��ѯ������ѧ�Ų�ѯһ��ѧ���ĳɼ���������\n");
	printf("5.���㣺������������ѧ�����ܳɼ����༶������У��������ֻ�и������ݶ�Ϊ��Ч����ʱ��-1Ϊ��Ч���ݣ������ܼ���.\n");
	while (1)
	{
		printf("����ѡ��:");
		fflush(stdin);
		scanf("%d", &option);
		if (option < 1 || option > 5)
			printf("������������������.\n");
		else
			break;
	}
	switch (option)
	{
	case 1:	inputPerformanceData();		break;
	case 2:	modifyPerformanceData();	break;
	case 3: deletePerformanceData(); 	break;
	case 4:	inquirePerformanceData();	break;
	case 5: calculatePerformanceData();	break;
	}
}
//����ɼ��˵�
void inputPerformanceData()
{
	int option, quantity;
	printf("\t\t��ѡ���������ѧ���ĳɼ�\n");
	printf("1-������ \t 2-�о���\n");
	printf("������ѡ��:");
	while (1)
	{
		scanf("%d", &option);
		if(option != 1 && option != 2)
			printf("�����������������룺");
		else
			break;
	}
	printf("\t\t��ѡ���������:\n");
	printf("1-���� \t 2-���\n");
	printf("������ѡ��:");
	while (1)
	{
		scanf("%d", &quantity);
		if(quantity != 1 && quantity != 2)
			printf("�����������������룺");
		else
			break;
	}
	inputScore(option, quantity);
}
//����˵��:stu:1-������ 2-�о��� quantity:1-���� 2-���
void inputScore(int stu, int quantity)
{
	int index;
	int score[3];
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	int id;
	printf("��������Ҫ����ɼ���ѧ����ѧ��:");
	scanf("%d", &id);
	if (stu == 1) //���ұ�����
	{
		pSUG = SUGHead;
		if(pSUG == NULL)
		{
			printf("�������ޱ���������,����������һ��\n");
			system("pause");
			return;
		}
		do{
			if(pSUG->id == id)
			{
				if(checkSUGScore(pSUG) == 0)
				{
					printf("ѧ��Ϊ%d�ı��������гɼ�����������\n", id);
					system("pause");
					return;
				}
				else
				{
					printf("ѧ��Ϊ%d�������ı������ɼ�����:(-1Ϊ��Ч�ɼ�)\n", id);
					printf("ѧ��\t\t����\t\t��ѧ\t\tӢ��\t\tC����\n");
					printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
					id, pSUG->name, pSUG->score[0], pSUG->score[1], pSUG->score[2]);
					if(quantity == 1) //���뵥���ɼ�
					{
						printf("1-��ѧ 2-Ӣ�� 3-C����\n");
						printf("����Ҫ���ĵĳɼ�:\n");
						scanf("%d", &index);
						printf("�������:");
						fflush(stdin);
						scanf("%d", &score[0]);
						pSUG->score[index - 1] = score[0];
						printf("�ɼ��޸����\n");
						system("pause");
						return;
					}
					else //�������ɼ�
					{
						printf("������������ѧ��Ӣ�C���Գɼ�:");
						fflush(stdin);
						for (index = 0; index < 3; index++)
						{
							scanf("%d", score[index]);
							pSUG->score[index] = score[index];
						}
						printf("�ñ�������ȫ���ɼ��޸����\n");
						system("pause");
						return;
					}
				}
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d�ı�����!\n", id);
	}
	else //�����о���
	{
		pSPG = SPGHead;
		if(pSPG == NULL)
		{
			printf("���������о�������,����������һ��\n");
			system("pause");
			return;
		}
		do{
			if(pSPG->id == id)
			{
				if(checkSPGScore(pSPG) == 0)
				{
					printf("ѧ��Ϊ%d���о������гɼ�����������\n", id);
					system("pause");
					return;
				}
				else
				{
					printf("ѧ��Ϊ%d�о������о����ɼ�����:(-1Ϊ��Ч�ɼ�)\n", id);
					printf("ѧ��\t\t����\t\t�ۺϿγ�\t\t����\n");
					printf("%d\t\t%s\t\t%d\t\t%d\n",
					id, pSPG->name, pSPG->score[0], pSPG->score[1]);
					if(quantity == 1) //���뵥���ɼ�
					{
						printf("1-�ۺϿγ� 2-���ĳɼ�\n");
						printf("����Ҫ���ĵĳɼ�:\n");
						scanf("%d", &index);
						printf("�������:");
						fflush(stdin);
						scanf("%d", &score[0]);
						pSPG->score[index - 1] = score[0];
						printf("�ɼ��޸����\n");
						system("pause");
						return;
					}
					else //�������ɼ�
					{
						printf("�����������ۺϿγ̺����ĳɼ�:");
						fflush(stdin);
						for (index = 0; index < 2; index++)
						{
							scanf("%d", &score[index]);
							pSPG->score[index] = score[index];
						}
						printf("���о�����ȫ���ɼ��޸����\n");
						system("pause");
						return;
					}
				}
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d���о���!", id);
	}
}
//�޸ĳɼ��˵�
void modifyPerformanceData()
{
	int option, id;
	printf("-----�޸ĳɼ��˵�-----\n");
	printf("1-�޸ı������ɼ�\t2-�޸��о����ɼ�\n");
	printf("������ѡ��:");
	do
	{
		scanf("%d", &option);
		if(option != 1 && option != 2)
			printf("������������������:");
		else
			break;
	} while (1);
	printf("�����뱻�޸ĳɼ���ѧ����ѧ��:");
	scanf("%d", &id);
	modifyScore(option, id);
}
//����ѧ���޸�ѧ���ĳɼ�
void modifyScore(int stu, int id)
{
	int index;
	int score[3];
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	if (stu == 1) //�޸ı�����
	{
		pSUG = SUGHead;
		if (pSUG == NULL)
		{
			printf("�������ޱ���������,����������һ��\n");
			system("pause");
			return;
		}
		do
		{
			if (pSUG->id == id)
			{
				printf("ѧ��Ϊ%d�ı������ɼ�����:(-1Ϊ��Ч�ɼ�)\n", id);
				printf("ѧ��\t\t����\t\t��ѧ\t\tӢ��\t\tC����\n");
				printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
					   id, pSUG->name, pSUG->score[0], pSUG->score[1], pSUG->score[2]);
				printf("������������ѧ��Ӣ�C���Գɼ�:");
				for (index = 0; index < 3; index++)
				{
					scanf("%d", &score[index]);
					pSUG->score[index] = score[index];
				}
				printf("�ñ�������ȫ���ɼ��޸����\n");
				system("pause");
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d�ı�����!\n", id);
	}
	else //�����о���
	{
		pSPG = SPGHead;
		if(pSPG == NULL)
		{
			printf("�о�������������,����������һ��\n");
			system("pause");
			return;
		}
		do
		{
			if (pSPG->id == id)
			{
				printf("ѧ��Ϊ%d���о����ɼ�����:(-1Ϊ��Ч�ɼ�)\n", id);
				printf("ѧ��\t\t����\t\t�ۺϿγ�\t\t����\n");
				printf("%d\t\t%s\t\t%d\t\t%d\n",
					   id, pSPG->name, pSPG->score[0], pSPG->score[1]);
				printf("�����������ۺϿγ̺����ĳɼ�:");
				fflush(stdin);
				for (index = 0; index < 2; index++)
				{
					scanf("%d", score[index]);
					pSPG->score[index] = score[index];
				}
				printf("���о�����ȫ���ɼ��޸����\n");
				system("pause");
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d���о���.\n", id);
		system("pause");
	}
}
//ɾ��ѧ���ɼ����ݲ˵�
void deletePerformanceData()
{
	int stu, id;
	printf("-----ɾ��ѧ���ɼ����ݲ˵�-----\n");
	printf("1-������\t2-�о���\n");
	printf("������ѡ��:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("������������������:");
	} while (stu != 1 && stu != 2);
	printf("��������Ҫɾ��ѧ����ѧ��:");
	scanf("%d", &id);
	deleteScore(stu, id);
}
//����ѧ��ɾ��һ��ѧ���ɼ����ݣ�����������ó�-1�� stu:1-������ 2-�о���
void deleteScore(int stu, int id)
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	int i;
	if (stu == 1) //ɾ��������
	{
		do
		{
			if (pSUG->id == id)
			{
				for (i = 0; i < 3; i++)
					pSUG->score[i] = -1;
				printf("ѧ��Ϊ%d�ı����������гɼ�������Ϊ-1\n", id);
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d�ı�����,��������\n", id);
	}
	else //ɾ���о���
	{
		do
		{
			if (pSPG->id == id)
			{
				for (i = 0; i < 2; i++)
					pSPG->score[i] = -1;
				printf("ѧ��Ϊ%d���о��������гɼ�������Ϊ-1\n", id);
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("δ�ҵ�ѧ��Ϊ%d���о���,��������\n", id);
	}
}
//��ѯ�ɼ��˵�
void inquirePerformanceData()
{
	int stu, id;
	printf("-----��ѯ�ɼ��˵�-----\n");
	printf("��ѯ����ѧ���ɼ�?\n");
	printf("1-������\t2-�о���\n");
	printf("����ѡ��:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("������������������:");
	} while (stu != 1 && stu != 2);
	printf("������Ҫ����ѧ����id:");
	scanf("%d", &id);
	inquireScore(stu, id);
}
//����ѧ�Ų���ѧ���ɼ� stu:1-������ 2-�о��� id:��Ҫ����ѧ����ѧ��
void inquireScore(int stu, int id)
{
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	if (stu == 1) //���ұ�����
	{
		pSUG = SUGHead;
		do
		{
			if (pSUG->id == id)
			{
				printf("���ҵ�ѧ��Ϊ%d�ı������ĳɼ���Ϣ\n", id);
				printf("ѧ��\t\t����\t\t��ѧ\t\tӢ��\t\tC����\t\t�ܳɼ�\t\t������\t\tУ����\n");
				printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
					   id, pSUG->name, pSUG->score[0], pSUG->score[1],pSUG->score[2], 
					   pSUG->score[3],pSUG->score[4],pSUG->score[5]);
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
		{
			printf("δ�ҵ�ѧ��Ϊ%d�ı������ĳɼ���Ϣ,��������\n", id);
			return;
		}
	}
	else //�����о���
	{
		pSPG = SPGHead;
		do
		{
			if (pSPG->id == id)
			{
				printf("���ҵ�ѧ��Ϊ%d���о����ĳɼ���Ϣ\n", id);
				printf("ѧ��\t\t����\t\t�ۺϿγ�\t\t����\t\t�ܳɼ�\t\t������\t\tУ����\n");
				printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
					   id, pSPG->name, pSPG->score[0], pSPG->score[1],pSPG->score[2], 
					   pSPG->score[3],pSPG->score[4]);
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
		{
			printf("δ�ҵ�ѧ��Ϊ%d���о����ĳɼ���Ϣ,��������\n", id);
			return;
		}
	}
}
//����ɼ�����
void calculatePerformanceData()
{

	SUG *pSUG = SUGHead, *psug;//СдΪ������
	SPG *pSPG = SPGHead, *pspg;
	printf("���ڼ�������ѧ���ɼ�,���Ժ󡭡�\n");
	calculateSUGTotalScore();
	while (pSUG != NULL)
	{
		if (checkSUGScore(pSUG) == 0) //��ǰѧ��û����Ч�ɼ�
		{ //��ʼ���㱾��������
			pSUG->score[4] = pSUG->score[5] = 1;
			psug = SUGHead;
			while (psug != NULL)
			{
				if (psug->score[3] > pSUG ->score[3])
				{
					if (strcmp(psug->class, pSUG->class) == 0)//������ͬһ����
					{
						pSUG->score[4]++; //��ǰѧ��������+1
						pSUG->score[5]++; //��ǰѧ��У����+1
					}
					else
						pSUG->score[5]++; //��ǰѧ��У����+1
				}
				psug = psug->next; //���ȽϽڵ����
			}
		}
		pSUG = pSUG->next;
	}
	printf("�������ɼ��������\n");
	printf("���ڼ����о����ɼ�,���Ժ󡭡�\n");
	calculateSPGTotalScore();
	while (pSPG != NULL)
	{
		if (checkSPGScore(pSPG) == 0)
		{
			pSPG->score[3] = pSPG->score[4] = 1;
			pspg = SPGHead;
			while (pspg != NULL)
			{
				if (pspg->score[2] > pSPG->score[2])
				{
					if (strcmp(pspg->class, pSPG->class) == 0)
					{
						pSPG->score[3]++;
						pSPG->score[4]++;
					}
					else
						pSPG->score[4]++;
				}
				pspg = pspg->next;
			}
		}
		pSPG = pSPG->next;
	}
	printf("�о����ɼ��������\n");
}
//���㱾�����ܳɼ�
void calculateSUGTotalScore()
{
	SUG *pSUG = SUGHead;
	while (pSUG != NULL)
	{
		if (checkSUGScore(pSUG) == 0)
		{
			if (pSUG->score[3] == -1)
				pSUG->score[3] = pSUG->score[0] + pSUG->score[1] + pSUG->score[2];
		}
		pSUG = pSUG->next;
	}
}
//�����о����ܳɼ�
void calculateSPGTotalScore()
{
	SPG *pSPG = SPGHead;
	while (pSPG != NULL)
	{
		if (checkSPGScore(pSPG) == 0)
		{
			if (pSPG->score[2] == -1)
				pSPG->score[2] = pSPG->score[0] + pSPG->score[1];
		}
		pSPG = pSPG->next;
	}
}

//�������ܲ˵�
void Calculate_rank(){
	int stu/*, option*/;
	printf("-----�������ܲ˵�-----\n");
	printf("��ѡ�������ѧ������:\n");
	printf("1-������	2-�о���\n");
	printf("������ѡ��:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("������������������:");
	} while (stu != 1 && stu != 2);
	if (stu == 1)
		calculateSUGRank();
	else
		calculateSPGRank();
}
//�������б��������ܳɼ��Ͱ�У����
void calculateSUGRank()
{
	SUG *pSUG = SUGHead, *psug;
	printf("���ڼ������б��������ܳɼ����У����,���Ժ󡭡�\n");
	calculateSUGTotalScore();
	while (pSUG != NULL)
	{
		if (checkSUGScore(pSUG) == 0) //��ǰѧ��û����Ч�ɼ�
		{ //��ʼ���㱾��������
			pSUG->score[4] = pSUG->score[5] = 1;
			psug = SUGHead;
			while (psug != NULL)
			{
				if (psug->score[3] > pSUG ->score[3])
				{
					if (strcmp(psug->class, pSUG->class) == 0)//������ͬһ����
					{
						pSUG->score[4]++; //��ǰѧ��������+1
						pSUG->score[5]++; //��ǰѧ��У����+1
					}
					else
						pSUG->score[5]++; //��ǰѧ��У����+1
				}
				psug = psug->next; //���ȽϽڵ����
			}
		}
		pSUG = pSUG->next;
	}
	printf("���б��������ܳɼ����У�����������\n");
}
//���������о������ܳɼ��Ͱ�У����
void calculateSPGRank()
{
	SPG *pSPG = SPGHead, *pspg;
	printf("���ڼ����о������ܳɼ��Ͱ�У����,���Ժ󡭡�\n");
	calculateSPGTotalScore();
	while (pSPG != NULL)
	{
		if (checkSPGScore(pSPG) == 0)
		{
			pSPG->score[3] = pSPG->score[4] = 1;
			pspg = SPGHead;
			while (pspg != NULL)
			{
				if (pspg->score[2] > pSPG->score[2])
				{
					if (strcmp(pspg->class, pSPG->class) == 0)
					{
						pSPG->score[3]++;
						pSPG->score[4]++;
					}
					else
						pSPG->score[4]++;
				}
				pspg = pspg->next;
			}
		}
		pSPG = pSPG->next;
	}
	printf("�����о������ܳɼ��Ͱ�У�����������\n");
}

//3.�����ܲ˵�
void Sort_print()
{
	int stu, option;
	char class[30];
	printf("-----��������˵�-----\n");
	printf("��ѡ����Ҫ������ѧ������\n");
	printf("1-������	2-�о���\n");
	printf("������:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("������������������:");
	} while (stu != 1 && stu != 2);
	printf("��ѡ����.\n");
	printf("1-ȫУѧ����Ϣ���ܳɼ��Ӹߵ���������ʾ\n");
	printf("2-ĳ����ѧ����Ϣ���ܳɼ��Ӹߵ���������ʾ\n");
	printf("������:");
	do
	{
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("������������������:");
	} while (option != 1 && option != 2);
	if (option == 1) //��ʾȫУѧ����Ϣ
	{
		if (stu == 1)
			schoolSort(SUGHead);
		else
			postSchoolSort(SPGHead);
	}
	else //���༶��ʾ
	{
		if (stu == 1)
		{
			printf("��������Ҫ��ʾ�ı������༶:");
			fflush(stdin);
			scanf("%s", &class);
			classSort(SUGHead, class);
		}
		else
		{
			printf("��������Ҫ��ʾ���о����༶��");
			fflush(stdin);
			scanf("%s", &class);
			postClassSort(SPGHead, class);
		}
	}
}

//4.��ѯ���ܲ˵�
void Inquire_information()
{
	int stu, option, chose;
	char class[30];
	printf("-----��ѯ���ܲ˵�-----\n");
	printf("��ѡ����Ҫ����������:\n");
	printf("1-������	2-�о���\n");
	printf("��ѡ��:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("������������������:");
	} while (stu != 1 && stu != 2);
	printf("��ѡ����Ҫʵ�ֵĹ���:\n");
	printf("1-��ҳ��ʾȫ��ѧ������Ϣ\n");
	printf("2-���༶��ʾ����ȫ��ѧ����Ϣ\n");
	printf("3-����ѧ�Ż���������ѯѧ����Ϣ\n");
	printf("4-��ĳ���༶�в�ѯĳ�ſγɼ�������ѧ����Ϣ\n");
	printf("������ѡ��:");
	do
	{
		scanf("%d", &option);
		if (option < 1 || option > 4)
			printf("������������������:");
	} while (option < 1 || option > 4);
	if (option == 1)//ѡ���˹���1
	{
		if (stu == 1)
			showAll(SUGHead);
		else
			postShowAll(SPGHead);
	}
	else if (option == 2)//ѡ���˹���2
	{
		if (stu == 1)
		{
			printf("������Ҫ��ʾ�ı������༶:");
			scanf("%s", &class);
			classShow(SUGHead, class);
		}
		else
		{
			printf("������Ҫ��ʾ���о����༶:");
			scanf("%s", &class);
			postClassShow(SPGHead, class);
		}
	}
	else if (option == 3)//ѡ���˹���3
	{
		int id;
		char name[20];
		if (stu == 1) //��������������
		{
			printf("���뱾����ѧ�Ż�������?\n");
			printf("1-ѧ��	2-����\n");
			printf("����:");
			scanf("%d", &chose);
			if (chose == 1)
			{
				printf("���뱾����ѧ��:");
				scanf("%d", &id);
				showOne1(SUGHead, id);
			}
			else
			{
				printf("���뱾��������:");
				scanf("%s", &name);
				showOne2(SUGHead, name);
			}
		}
		else //�����о�������
		{
			printf("�����о���ѧ�Ż�������?\n");
			printf("1-ѧ��	2-����\n");
			printf("����:");
			scanf("%d", &chose);
			if (chose == 1)
			{
				printf("�����о���ѧ��:");
				scanf("%d", &id);
				postShowOne1(SPGHead, id);
			}
			else
			{
				printf("�����о�������:");
				scanf("%s", &name);
				postShowOne2(SPGHead, name);
			}
		}
	}
	else //ѡ���˹���4
	{
		if (stu == 1)
		{
			printf("����༶�Ϳ�Ŀ����ѯ�ð�ÿ����в�����ı�����\n");
			printf("������Ҫ��ѯ�İ༶:");
			scanf("%s", &class);
			printf("��ѡ���Ŀ:1-����	2-Ӣ��	3-C����\n");
			scanf("%d", &chose);
			showClassPass(SUGHead, class, chose);
		}
		else
		{
			printf("����༶�Ϳ�Ŀ����ѯ�ð�ÿ����в�������о���\n");
			printf("������Ҫ��ѯ�İ༶:");
			scanf("%s", &class);
			printf("��ѡ���Ŀ:1-�ۺϿγ�	2-���ĳɼ�\n");
			scanf("%d", &chose);
			showClassPass(SUGHead, class, chose);
		}
	}
}

//5.ͳ�ƹ��ܲ˵�
void Performance_statistic()
{
	int stu, option, lesson;
	char class[20];
	printf("-----ͳ�ƹ��ܲ˵�-----\n");
	printf("ѡ����:\n");
	printf("1-ͳ�Ʋ���ʾĳ�ſ�ÿ�����ƽ���ɼ�\n");
	printf("2-��ĳ������ͳ�Ʋ���ʾĳ�ſγ̲�ͬ�ȼ���ѧ������\n");
	printf("������:");
	do
	{
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("������������������:");
	} while (option != 1 && option != 2);
	printf("��ѡ�������ѧ������:\n");
	printf("1-������	2-�о���\n");
	printf("������:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
		printf("������������������:");
	} while (stu != 1 && stu != 2);
	if (option == 1)
	{
		if (stu == 1)
		{
			printf("��ѡ����ʾ�Ŀγ�:\n");
			printf("1-��ѧ	2-Ӣ��	3-C����\n");
			printf("������:");
			scanf("%d", &lesson);
			countAverage(SUGHead, lesson);
		}
		else
		{
			printf("��ѡ����ʾ�Ŀγ�:\n");
			printf("1-�ۺϿγ�	2-���ĳɼ�\n");
			printf("������:");
			scanf("%d", &lesson);
			postCountAverage(SPGHead, lesson);
		}
	}
	else
	{
		if (stu == 1)
		{
			printf("������ҵİ༶:");
			scanf("%s", &class);
			printf("������ҵĿγ�:\n");
			printf("1-��ѧ	2-Ӣ��	3-C����\n");
			printf("������:");
			scanf("%d", &lesson);
			classCourse(SUGHead, class, lesson);
		}
		else
		{
			printf("������ҵİ༶:");
			scanf("%s", &class);
			printf("������ҵĿγ�:\n");
			printf("1-�ۺϿγ�	2-���ĳɼ�\n");
			printf("������:");
			scanf("%d", &lesson);
			postClassCourse(SPGHead, class, lesson);
		}
	}
}