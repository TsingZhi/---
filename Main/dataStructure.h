#define SUGLEN sizeof(SUG)
#define SPGLEN sizeof(SPG)

enum Sex{female,male};			// 0ΪŮ��1Ϊ��
typedef struct underGraduate 	//�������ṹ��
{
	int id;						//ѧ��
	char name[16];				//����
	enum Sex sex;				//�Ա�
	char profession[30];		//רҵ
	char class[30];				//�༶
	int score[6];				// 0-5�ֱ�Ϊ ��ѧ Ӣ�� C���� �ܷ� ������ У����
	struct underGraduate *next; //��һ���ڵ�
}SUG;

typedef struct postGraduate 	//�о����ṹ��
{
	int id;					   //ѧ��
	char name[16];			   //����
	enum Sex sex;			   //�Ա�
	char profession[30];	   //רҵ
	char class[30];			   //�༶
	char direction[30];		   //�о�����
	char teacher[16];		   //��ʦ
	int score[5];			   // 0-4�ֱ�Ϊ�ۺϿγ� ���� �ܳɼ� ������ У����
	struct postGraduate *next; //��һ���ڵ�
}SPG;

SUG *SUGHead = NULL, *SUGTail = NULL; // List:����������ͷ�ڵ�;Tail:β�ڵ�
SPG *SPGHead = NULL, *SPGTail = NULL; // List:�о�������ͷ�ڵ�;Tail:β�ڵ�
SUG SUGpage[30];					  //��ҳ����ã�ÿʮ���ڵ��¼һ��
SPG SPGPage[30];					  //��ҳ����ã�ÿʮ���ڵ��¼һ��

//�����µı������ڵ㣬βָ���Զ���NULL���ɼ���ʼ��Ϊ-1
SUG *newSUGNode()
{
	SUG *new;
	int i;
	if ((new = (SUG *)malloc(SUGLEN)) == NULL)
	{
		printf("�����µı������ڵ�ʧ��.");
		exit(0);
	}
	else
	{
		new->next = NULL;
		for (i = 0; i < 6; i++) //��ʼ���ɼ�
			new->score[i] = -1;
		return new;
	}
}
//�����µ��о����ڵ㣬βָ���Զ���NULL���ɼ���ʼ��Ϊ-1
SPG *newSPGNode()
{
	SPG *new;
	int i;
	if ((new = (SPG *)malloc(SPGLEN)) == NULL)
	{
		printf("�����µ��о����ڵ�ʧ��.");
		exit(0);
	}
	else
	{
		new->next = NULL;
		for (i = 0; i < 5; i++) //��ʼ���ɼ�
			new->score[i] = -1;
		return new;
	}
}
//���ļ���ȡ���ݵ�����
void ReadFromFile()
{
	FILE *fpSUG, *fpSPG;
	SUG *prevSUG = NULL, *nextSUG = NULL;
	SPG *prevSPG = NULL, *nextSPG = NULL;
	if ((fpSUG = fopen("underGraduate.txt", "r")) == NULL)
	{
		printf("�޷������򿪱������ļ�.\n");
		exit(0);
	}
	printf("���ڶ�ȡ�������ļ������Ժ󡭡�\n");
	while (1)
	{
		if ((nextSUG = (SUG *)malloc(SUGLEN)) == NULL)
		{
			printf("�����µı������ڵ�ʧ��\n");
			exit(0);
		}
		if ((fscanf(fpSUG, "%d\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d",
					&nextSUG->id, &nextSUG->name, &nextSUG->sex, &nextSUG->profession, &nextSUG->class,
					&nextSUG->score[0], &nextSUG->score[1], &nextSUG->score[2], &nextSUG->score[3],
					&nextSUG->score[4], &nextSUG->score[5])) == EOF)
			break;
		if (SUGHead == NULL)
		{
			SUGHead = nextSUG;
			SUGTail = SUGHead;
		}
		else
		{
			prevSUG->next = nextSUG;
			SUGTail = nextSUG;
		}
		nextSUG->next = NULL;
		prevSUG = nextSUG;
	}
	fclose(fpSUG);
	printf("�������ļ���ȡ���\n");
	if ((fpSPG = fopen("postGraduate.txt", "r")) == NULL)
	{
		printf("�޷��������о����ļ�\n");
		exit(0);
	}
	printf("���ڶ�ȡ�о����ļ������Ժ󡭡�\n");
	while (1)
	{
		if ((nextSPG = (SPG *)malloc(SPGLEN)) == NULL)
		{
			printf("�����µ��о����ڵ�ʧ��");
			exit(0);
		}
		if ((fscanf(fpSPG, "%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d", 
		&nextSPG->id, &nextSPG->name, &nextSPG->sex, &nextSPG->profession, 
		&nextSPG->class, &nextSPG->direction, &nextSPG->teacher, &nextSPG->score[0], 
		&nextSPG->score[1], &nextSPG->score[2], &nextSPG->score[3], &nextSPG->score[4])) == EOF)
			break;
		if (SPGHead == NULL)
		{
			SPGHead = nextSPG;
			SPGTail = nextSPG;
		}
		else
		{
			prevSPG->next = nextSPG;
			SPGTail = nextSPG;
		}
		nextSPG->next = NULL;
		prevSPG = nextSPG;
	}
	fclose(fpSPG);
	printf("�о����ļ���ȡ���\n");
}
//�����������ݵ��ļ�
void SaveToFile()
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	FILE *fpSUG, *fpSPG;
	if ((fpSUG = fopen("underGraduate_Save.txt", "w")) == NULL)
	{
		printf("������������д�����ļ�ʧ��\n");
		exit(0);
	}
	while (pSUG != NULL)
	{
		fprintf(fpSUG, "%d\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
				pSUG->id, pSUG->name, pSUG->sex, pSUG->profession, pSUG->class,
				pSUG->score[0], pSUG->score[1], pSUG->score[2], pSUG->score[3],
				pSUG->score[4], pSUG->score[5]);
		pSUG = pSUG->next;
	}
	fclose(fpSUG);
	printf("�ɹ����汾�������ݵ��ļ�\n");
	if ((fpSPG = fopen("postGraduate_Save.txt", "w")) == NULL)
	{
		printf("���о�������д�뵽�ļ�ʧ��\n");
		exit(0);
	}
	while (pSPG != NULL)
	{
		fprintf(fpSPG, "%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
				pSPG->id, pSPG->name, pSPG->sex, pSPG->profession,
				pSPG->class, pSPG->direction, pSPG->teacher, pSPG->score[0],
				pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
		pSPG = pSPG->next;
	}
	fclose(fpSPG);
	printf("�ɹ������о������ݵ��ļ�\n");
}