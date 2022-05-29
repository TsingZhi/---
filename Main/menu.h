/* 包含所有菜单展示函数 */
/*****************************************/
/**函数声明区，每写完一个就把函数头拿进来
 * 注意：必须是完全完成的才写进来（包括子函数）
 * */

int checkSUGScore(SUG *pSUG);
int checkSPGScore(SPG *pSPG);
void printSUGTitle();
void printSPGTitle();
void printSUGBaseData(SUG *pSUG);
void printSPGBaseData(SPG *pSPG);
void printSUGInfo(SUG *pSUG);
void printSPGInfo(SPG *pSPG);
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

/****************************************/
//检查本科生成绩(数学、英语、C语言、总分)是否有无效成绩（-1），如果有则返回1， 否则返回0
int checkSUGScore(SUG *pSUG)
{
	int i;
	for ( i = 0; i < 4; i++)
	{
		if (pSUG->score[i] == -1)
			return 1;
	}
	return 0;
}
//检查研究生成绩(综合课程、论文、总成绩)是否有无效成绩（-1），如果有则返回1， 否则返回0
int checkSPGScore(SPG *pSPG)
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		if (pSPG->score[i] == -1)
			return 1;
	}
	return 0;
}
//输出本科生信息组成部分
void printSUGTitle()
{printf("学号\t\t姓名\t\t性别\t\t专业\t\t班级\t\t数学\t\t英语\t\tC语言\t\t总分\t\t班排名\t\t校排名\n");}
//输出一个本科生的全部信息
void printSUGInfo(SUG *pSUG)
{
	if (pSUG->sex == 0)
		printf("%d\t\t%s\t\t女\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
	else
		printf("%d\t\t%s\t\t男\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
}
//输出研究生信息组成部分
void printSPGTitle()
{printf("学号\t\t姓名\t\t性别\t\t专业\t\t班级\t\t研究方向\t\t导师\t\t综合课程\t\t论文\t\t总成绩\t\t班排名\t\t校排名\\n");}
//输出一个研究生的全部信息
void printSPGInfo(SPG *pSPG)
{
	if (pSPG->sex == 0)
		printf("%d\t\t%s\t\t女\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher,
		pSPG->score[0], pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
	else
		printf("%d\t\t%s\t\t男\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher,
		pSPG->score[0], pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
}
//子菜单1：数据维护
void Data_maintenance()
{
	int option;
	printf("-------数据维护菜单-------\n");
	printf("1:基本资料数据 \t 2:成绩数据\n");
	while (1)
	{
		printf("选择需要管理的数据:");
		fflush(stdin);
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("输入有误，请重新输入:");
		else
			break;
	}
	switch (option)
	{
	case 1:
		BaseData_maintenance();
		break;
	default:
		PerformanceData_maintenance();//成绩数据维护菜单
		break;
	}
}
//基本数据维护菜单
void BaseData_maintenance()
{
	int option;
	printf("-------基本数据维护菜单-------\n");
	printf("1.添加: 添加学生基本资料数据\n");
	printf("2.修改：根据学号来修改任意学生的除学号外的其他基本资料数据\n");
	printf("3.删除：根据学号删除一个学生\n");
	printf("4.查询：根据学号查询一个学生的基本资料数据\n");
	while (1)
	{
		printf("输入选项:");
		fflush(stdin);
		scanf("%d", &option);
		if (option < 1 || option >4)
			printf("输入有误，请重新输入.\n");
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
//添加数据的菜单
void addBaseData()
{
	int stuOption;
	int quantity; //1表示添加单个，2表示添加多个
	printf("添加本科生还是研究生？\n");
	printf("1:本科生\t2:研究生");
	while (1)
	{
		printf("输入选项:");
		scanf("%d", &stuOption);
		if (stuOption != 1 && stuOption != 2)
			printf("输入有误，请重新输入:");
		else
			break;
	}
	printf("添加单个还是多个?\n");
	printf("1.单个 \t 2.多个");
	while (1)
	{
		printf("输入选项:");
		scanf("%d", &quantity);
		if (quantity != 1 && quantity != 2)
			printf("输入有误，请重新输入:");
		else
			break;
	}
	addStudent(stuOption, quantity);
}
/**参数说明：stu为要添加的学生类型， 1-本科生，2-研究生;
 * quantity为添加模式，1-添加单个，2-添加多个（重复执行单个添加)
 * */
void addStudent(int stu, int quantity)
{
	SUG *newSUG = NULL, *p1 = NULL;
	SPG *newSPG = NULL, *p2 = NULL;
	int number = 0;
	if(stu == 1)
	{
		if (quantity == 1)
			printf("输入该本科生的姓名 性别(0-女 1-男 ) 专业 班级:(性别输入-1以结束)\n");
		else
			printf("输入若干本科生的姓名 性别(0-女 1-男) 专业 班级:(性别输入-1以结束)\n");
		fflush(stdin);
		while (1)
		{
			printf("输入第%d个本科生:", number + 1);
			newSUG = newSUGNode();
			scanf("%s%d%s%s", &newSUG->name, &newSUG->sex, &newSUG->profession, &newSUG->class);
			if (newSUG->sex == -1) break;
			if (SUGHead == NULL) //本科生链表无数据时
			{
				SUGHead = newSUG; //置该节点为头节点
				SUGpage[0] = *SUGHead; //本科生头节点存入翻页数组
				SUGHead->id = 1;
				SUGTail = newSUG;
			}
			else
			{
				newSUG->id = SUGTail->id + 1;
				if ((newSUG->id % 10) == 1)
					SUGpage[newSUG->id / 10] = *newSUG; //满足条件则存入翻页数组
				SUGTail->next = newSUG;
				SUGTail = newSUG;
			}
			number++;
			if(quantity == 1) break;
		}
	printf("添加完毕，共添加%d条本科生数据\n", number);
	}
	else
	{
		if (quantity == 1)
			printf("输入该研究生的姓名 性别(0-女 1-男) 专业 班级 研究方向 导师:(性别输入-1以结束)\n");
		else
			printf("输入若干研究生的姓名 性别(0-女 1-男) 专业 班级 研究方向 导师:(性别输入-1以结束)\n");
		fflush(stdin);
		while (1)
		{
			printf("输入第%d个学生:", number + 1);
			newSPG = newSPGNode();
			scanf("%s%d%s%s%s%s", &newSPG->name, &newSPG->sex, &newSPG->profession,
				  &newSPG->class, &newSPG->direction, &newSPG->teacher);
			if (newSPG->sex == -1) break;
			if (SPGHead == NULL) //研究生链表无数据时
			{
				SPGHead = newSPG; //置该节点为头节点
				SPGHead->id = 1;
				SPGPage[0] = *newSPG; //存入翻页数组
				SPGTail = newSPG;
			}
			else
			{
				newSPG->id = SPGTail->id + 1;
				if ((newSPG->id % 10) == 1)
					SPGPage[newSPG->id / 10] = *newSPG; //满足条件则存入翻页数组
				SPGTail->next = newSPG;
				SPGTail = newSPG;
			}
			number++;
			if(quantity == 1) break;
		}
	printf("添加完毕，共添加%d条研究生数据\n", number);
	}
}
//数据修改菜单 用于输入学生类型及学号
void modifyBaseData()
{
	int id, option;
	printf("-------数据修改菜单-------\n");
	printf("需要修改本科生还是研究生？\n");
	printf("1.本科生 \t 2.研究生\n");
	while (1)
	{
		printf("输入选项:");
		fflush(stdin);
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("输入有误，请重新输入.\n");
		else
			break;
	}
	printf("输入学号:");
	scanf("%d", &id);
	modifyStudent(option, id);
}
//参数说明:stu为学生类型  1-本科生 2-研究生; id:待修改学生的学号
void modifyStudent(int stu, int id)
{
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	int flag = 0; //查找成功标志
	if (stu == 1) //修改本科生
	{
		if (SUGHead == NULL)
		{
			printf("无本科生数据可修改，请先添加一条本科生数据\n");
			return;
		}
		for (pSUG = SUGHead; pSUG != NULL; pSUG = pSUG->next)
		{
			if (pSUG->id == id) //查找成功
			{
				flag = 1; //修改查找标志
				printf("学号为%d的本科生基本资料如下:\n", id);
				if (pSUG->sex == 0)
					printf("%-5s 女 %-10s %-5s", pSUG->name, pSUG->profession, pSUG->class);
				else
					printf("%-5s 男 %-10s %-5s", pSUG->name, pSUG->profession, pSUG->class);
				printf("依次输入姓名 性别（0为女1为男） 专业 班级以覆盖:\n");
				scanf("%s%d%s%d", pSUG->name, pSUG->sex, pSUG->profession, pSUG->class);
				printf("修改学号为%d的本科生基本资料成功\n", id);
				return;
			}
		}
		if (flag == 0) //查找失败
			printf("未找到学号为%d的本科生，请检查是否有该学生\n", id);
	}
	else //修改研究生
	{
		if (SPGHead == NULL)
		{
			printf("无研究生数据可修改，请先添加一条研究生数据\n");
			return;
		}
		for (pSPG = SPGHead; pSPG != NULL; pSPG = pSPG->next)
		{
			if (pSPG->id == id)
			{
				flag = 1;
				printf("学号为%d的研究生基本资料如下:\n", id);
				if (pSPG->sex == 0)
					printf("%-5s 女 %-10s %-5s %-10s %-5s", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				else
					printf("%-5s 男 %-10s %-5s %-10s %-5s", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				printf("依次输入姓名 性别（0为女1为男） 专业 班级 研究方向 导师以覆盖:\n");
				scanf("%s%d%s%d", pSPG->name, pSPG->sex, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				printf("修改学号为%d的研究生基本资料成功\n", id);
				return;
			}
		}
		if (flag == 0)
			printf("未找到学号为%d的研究生，请检查是否有该学生\n", id);
	}
}
//删除数据菜单
void deleteBaseData()
{
	int stu, id;
	printf("----------删除数据菜单----------\n");
	printf("删除本科生还是研究生的数据？");
	printf("1-本科生 2-研究生");
	scanf("%d", &stu);
	printf("输入被删除学生的学号:");
	scanf("%d", &id);
	deleteStudent(stu, id);
}
//删除数据函数:学号相符则释放该节点内存
void deleteStudent(int stu, int id)
{
	if (stu == 1)
		deleteUStu(id); // 删除学号为id的本科生
	else
		deletePStu(id); // 删除学号为id的研究生
}
//根据学号删除一个本科生（释放节点内存）
void deleteUStu(int id)
{
	SUG *pFront, *pBehind, *temp = NULL;
	pFront = SUGHead;
	pBehind = pFront->next;
	if (pFront->id == id) //链表头节点就是要删除的对象时
	{
		temp = pFront;
		pFront = pFront->next;
		free(temp);
		printf("该本科生已被删除\n");
		return;
	}
	while(pBehind != NULL && pBehind->id != id) //使用pBehind寻找需要删除的节点
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	if(pBehind == NULL)//未找到被删除的对象,返回
	{
		printf("未找到要被删除的对象\n");
		return;
	}
	else//此时pBehind即需要删除的对象
	{
		temp = pBehind;
		pBehind = pBehind->next;
		pFront->next = pBehind;
		free(temp);
		printf("该本科生已被删除\n");
	}
}
//根据学号删除一个研究生（释放节点内存）
void deletePStu(int id)
{
	SPG *pFront, *pBehind, *temp = NULL;
	pFront = SPGHead;
	pBehind = pFront->next;
	if (pFront->id == id) //链表头节点就是要删除的对象时
	{
		temp = pFront;
		pFront = pFront->next;
		free(temp);
		printf("该研究生已删除\n");
		return;
	}
	while(pBehind != NULL && pBehind->id != id)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	if(pBehind == NULL)//未找到被删除的对象,返回
	{
		printf("未找到要被删除的对象\n");
		return;
	}
	else//此时pBehind即需要删除的对象
	{
		temp = pBehind;
		pBehind = pBehind->next;
		pFront->next = pBehind;
		free(temp);
		printf("该研究生已被删除\n");
	}
}
//查询数据菜单 
void inquireBaseData()
{
	int stu, id;
	printf("----------查询数据菜单----------\n");
	printf("查询本科生还是研究生的数据?\n");
	printf("1-本科生\t2-研究生\n");
	printf("请输入:");
	scanf("%d", &stu);
	while (stu != 1 && stu != 2)
	{
		printf("意外的选项.请重新输入:");
		scanf("%d", &stu);
	}
	printf("请输入需要查找学生的学号:");
	scanf("%d", &id);
	inquireStu(stu, id);
}
//根据接收的学生类型和学号（形参）进行查找并输出基本数据
void inquireStu(int stu, int id)
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	if (stu == 1) //查找本科生数据
	{
		do
		{
			if(pSUG->id == id)
			{
				if(checkSUGScore(pSUG) == 1)
				{
					printf("学号为%d的本科生存在无效数据，请检查:\n", id);
					printSUGTitle();
					printSUGInfo(pSUG);
					return ;
				}
				else
				{
					printf("查找成功,该本科生数据如下:\n");
					printSUGTitle();
					printSUGInfo(pSUG);
				}
			}
			else
				pSUG = pSUG->next;
		} while (pSUG->id != id);
	}
}
