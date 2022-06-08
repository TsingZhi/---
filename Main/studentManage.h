#define SUGLEN sizeof(SUG)
#define SPGLEN sizeof(SPG)
#include<stdlib.h>

enum Sex{female,male};			// 0为女，1为男
typedef struct underGraduate 	//本科生结构体
{
	int id;						//学号
	char name[16];				//姓名
	enum Sex sex;				//性别
	char profession[30];		//专业
	char class[30];				//班级
	int score[6];				// 0-5分别为 数学 英语 C语言 总分 班排名 校排名
	struct underGraduate *next; //下一个节点
}SUG;

typedef struct postGraduate 	//研究生结构体
{
	int id;					   //学号
	char name[16];			   //姓名
	enum Sex sex;			   //性别
	char profession[30];	   //专业
	char class[30];			   //班级
	char direction[30];		   //研究方向
	char teacher[16];		   //导师
	int score[5];			   // 0-4分别为综合课程 论文 总成绩 班排名 校排名
	struct postGraduate *next; //下一个节点
}SPG;

SUG *SUGHead = NULL, *SUGTail = NULL; // List:本科生链表头节点;Tail:尾节点
SPG *SPGHead = NULL, *SPGTail = NULL; // List:研究生链表头节点;Tail:尾节点
SUG SUGpage[30];					  //分页输出用，每十个节点记录一次
SPG SPGPage[30];					  //分页输出用，每十个节点记录一次

//申请新的本科生节点，尾指针自动置NULL，成绩初始化为-1
SUG *newSUGNode()
{
	SUG *new;
	int i;
	if ((new = (SUG *)malloc(SUGLEN)) == NULL)
	{
		printf("申请新的本科生节点失败.");
		exit(0);
	}
	else
	{
		new->next = NULL;
		for (i = 0; i < 6; i++) //初始化成绩
			new->score[i] = -1;
		return new;
	}
}
//申请新的研究生节点，尾指针自动置NULL，成绩初始化为-1
SPG *newSPGNode()
{
	SPG *new;
	int i;
	if ((new = (SPG *)malloc(SPGLEN)) == NULL)
	{
		printf("申请新的研究生节点失败.");
		exit(0);
	}
	else
	{
		new->next = NULL;
		for (i = 0; i < 5; i++) //初始化成绩
			new->score[i] = -1;
		return new;
	}
}
//从文件读取数据到链表
void ReadFromFile()
{
	FILE *fpSUG, *fpSPG;
	SUG *prevSUG = NULL, *nextSUG = NULL;
	SPG *prevSPG = NULL, *nextSPG = NULL;
	if ((fpSUG = fopen("underGraduate.txt", "r")) == NULL)
	{
		printf("无法正常打开本科生文件.\n");
		exit(0);
	}
	while (1)
	{
		if ((nextSUG = (SUG *)malloc(SUGLEN)) == NULL)
		{
			printf("申请新的本科生节点失败\n");
			exit(0);
		}
		if ((fscanf(fpSUG, "%d\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d",
					&nextSUG->id, &nextSUG->name, &nextSUG->sex, &nextSUG->profession, &nextSUG->class,
					&nextSUG->score[0], &nextSUG->score[1], &nextSUG->score[2], &nextSUG->score[3],
					&nextSUG->score[4], &nextSUG->score[5])) == EOF)
			break;
		if (SUGHead == NULL)
		{
			SUGHead = nextSPG;
			SUGTail = SUGHead;
		}
		else
		{
			prevSUG->next = nextSUG;
			SUGTail = nextSUG;
		}
		prevSUG = nextSUG;
	}
	fclose(fpSUG);
	printf("本科生文件读取完成\n");
	if ((fpSPG = fopen("postGraduate.txt", "r")) == NULL)
	{
		printf("无法正常打开研究生文件\n");
		exit(0);
	}
	while (1)
	{
		if ((nextSPG = (SPG *)malloc(SPGLEN)) == NULL)
		{
			printf("申请新的研究生节点失败");
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
		prevSPG = nextSPG;
	}
	fclose(fpSPG);
	printf("研究生文件读取完成\n");
}
//从链表保存数据到文件
void SaveToFile()
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	FILE *fpSUG, *fpSPG;
	if ((fpSUG = fopen("underGraduate_Save.txt", "w")) == NULL)
	{
		printf("将本科生数据写入至文件失败\n");
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
	printf("成功保存本科生数据到文件\n");
	if ((fpSPG = fopen("postGraduate_Save.txt", "w")) == NULL)
	{
		printf("将研究生数据写入到文件失败\n");
		exit(0);
	}
	while (pSPG != NULL)
	{
		fprintf(fpSPG, "%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d",
				pSPG->id, pSPG->name, pSPG->sex, pSPG->profession,
				pSPG->class, pSPG->direction, pSPG->teacher, pSPG->score[0],
				pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
		pSPG = pSPG->next;
	}
	fclose(fpSPG);
	printf("成功保存研究生数据到文件\n");
}