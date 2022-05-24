#define SUGLEN sizeof(SUG)
#define SPGLEN sizeof(SPG)

enum Sex{female,male};  // 0为女，1为男
struct underGraduate //本科生
{
	int id;						//学号
	char name[16];				//姓名
	enum Sex sex;				//性别
	char profession[30];		//专业
	char class[30];				//班级
	int score[6];				// 0-5分别为 数学 英语 C语言 总分 班排名 校排名
	struct underGraduate *next; //下一个节点
};
typedef struct underGraduate SUG; //本科生的类型定义

struct postGraduate //研究生
{
	int id;				 //学号
	char name[16];		 //姓名
	enum Sex sex;		 //性别
	char profession[30]; //专业
	char class[30];		 //班级
	char direction[30];	 //研究方向
	char teacher[16];	 //导师
	int score[5];			   // 0-4分别为综合课程 论文 总成绩 班排名 校排名
	struct postGraduate *next; //下一个节点
};
typedef struct postGraduate SPG;//研究生的类型定义

SUG *SUGHead = NULL, *SUGTail = NULL; // List:本科生链表头节点;Tail:尾节点
SPG *SPGHead = NULL, *SPGTail = NULL; // List:研究生链表头节点;Tail:尾节点
SUG SUGpage[30];//分页输出用，每十个节点记录一次
SPG SPGPage[30];//分页输出用，每十个节点记录一次

//申请新的本科生节点，尾指针自动置NULL，成绩初始化为-1
SUG* newSUGNode()
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
		for (i = 0; i < 6; i++)//初始化成绩
			new->score[i] = -1;
		return new;
	}
}
//申请新的研究生节点，尾指针自动置NULL，成绩初始化为-1
SPG* newSPGNode()
{
	SPG *new;
	int i;
	if((new = (SPG*)malloc(SPGLEN)) == NULL)
	{
		printf("申请新的研究生节点失败.");
		exit(0);
	}
	else
	{
		new->next = NULL;
		for (i = 0; i < 5; i++)//初始化成绩
			new->score[i] = -1;
		return new;
	}
}
