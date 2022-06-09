/* 包含所有菜单展示函数 */


/* 自定义函数 */

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

/* 自定义函数 */


/* 1.A.基本数据管理函数声明 */

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

/* 1.A.基本数据管理函数声明 */


/* 1.B.成绩管理部分声明 */

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

/* 1.B.成绩管理部分声明 */


/* 2.计算排名部分声明 */

void Calculate_rank();
void calculateSUGRank();
void calculateSPGRank();

/* 2.计算排名部分声明 */


/* 3.排序输出部分声明 */

void Sort_print();

/* 3.排序输出部分声明 */


/* 4.查询功能部分声明 */

void Inquire_information();

/* 4.查询功能部分声明 */


/* 5.统计功能菜单声明 */

void Performance_statistic();

/* 5.统计功能菜单声明 */


//检查本科生成绩(数学、英语、C语言)是否有无效成绩（-1），如果有则返回1， 否则返回0
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
//检查研究生成绩(综合课程、论文)是否有无效成绩（-1），如果有则返回1， 否则返回0
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
//输出本科生基本信息组成部分
void printSUGTitle()
{printf("学号\t姓名\t性别\t专业\t\t班级\n");}
//输出一个本科生的基本信息
void printSUGBaseData(SUG *pSUG)
{
	if(pSUG->sex == 0)
		printf("%d\t%s\t女\t%s\t%s\n", pSUG->id, pSUG->name, pSUG->profession, pSUG->class);
	else
		printf("%d\t%s\t男\t%s\t%s\n", pSUG->id, pSUG->name, pSUG->profession, pSUG->class);
}
//输出一个本科生的全部信息
void printSUGInfo(SUG *pSUG)
{
	if (pSUG->sex == 0)
		printf("%d\t%s\t女\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
	else
		printf("%d\t%s\t男\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
			   pSUG->id, pSUG->name, pSUG->profession, pSUG->class, pSUG->score[0], pSUG->score[1],
			   pSUG->score[2], pSUG->score[3], pSUG->score[4], pSUG->score[5]);
}
//输出研究生基本信息组成部分
void printSPGTitle()
{printf("学号\t姓名\t性别\t专业\t班级\t研究方向\t\t导师\\n");}
//输出一个研究生的基本信息
void printSPGBaseData(SPG *pSPG)
{
	if (pSPG->sex == 0)
		printf("%d\t%s\t女\t%s\t%s\t%s\t\t%s\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
	else
		printf("%d\t%s\t男\t%s\t%s\t%s\t%s\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
}
//输出一个研究生的全部信息
void printSPGInfo(SPG *pSPG)
{
	if (pSPG->sex == 0)
		printf("%d\t%s\t女\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
		pSPG->id, pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher,
		pSPG->score[0], pSPG->score[1], pSPG->score[2], pSPG->score[3], pSPG->score[4]);
	else
		printf("%d\t%s\t男\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",
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
	printf("1:本科生\t2:研究生\n");
	while (1)
	{
		printf("输入选项:");
		scanf("%d", &stuOption);
		if (stuOption != 1 && stuOption != 2)
			printf("输入有误，请重新输入.\n");
		else
			break;
	}
	printf("添加单个还是多个?\n");
	printf("1.单个 \t 2.多个\n");
	while (1)
	{
		printf("输入选项:");
		scanf("%d", &quantity);
		if (quantity != 1 && quantity != 2)
			printf("输入有误，请重新输入.\n");
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
					printf("%-5s 女 %-10s %-5s\n", pSUG->name, pSUG->profession, pSUG->class);
				else
					printf("%-5s 男 %-10s %-5s\n", pSUG->name, pSUG->profession, pSUG->class);
				printf("依次输入姓名 性别（0为女1为男） 专业 班级以覆盖:\n");
				scanf("%s%d%s%d", &pSUG->name, &pSUG->sex, &pSUG->profession, &pSUG->class);
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
					printf("%-5s 女 %-10s %-5s %-10s %-5s\n", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				else
					printf("%-5s 男 %-10s %-5s %-10s %-5s\n", pSPG->name, pSPG->profession, pSPG->class, pSPG->direction, pSPG->teacher);
				printf("依次输入姓名 性别（0为女1为男） 专业 班级 研究方向 导师以覆盖:\n");
				scanf("%s%d%s%d", &pSPG->name, &pSPG->sex, &pSPG->profession, &pSPG->class, &pSPG->direction, &pSPG->teacher);
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
			if (pSUG->id == id)
			{
				// system("cls");
				printf("查找成功，学号为%d的本科生基本数据如下:\n", id);
				printSUGTitle();
				printSUGBaseData(pSUG);
				if (checkSUGScore(pSUG) == 1)
					printf("提示:学号为%d的本科生成绩存在无效数据，请检查\n", id);
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG->id != id);
	}
	else //查找研究生数据
	{
		do
		{
			if (pSPG->id == id)
			{
				system("cls");
				printf("查找成功，学号为%d的研究生基本数据如下:\n", id);
				printSPGTitle();
				printSPGBaseData(pSPG);
				if (checkSPGScore(pSPG) == 1)
					printf("提示:学号为%d的研究生成绩存在无效数据，请检查\n", id);
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG->id != id);
	}
}

//成绩数据管理菜单
void PerformanceData_maintenance()
{
	int option;
	printf("-------成绩数据维护菜单-------\n");
	printf("1.添加: 添加学生成绩资料数据\n");
	printf("2.修改：根据学号来修改任意学生的除学号外的其他成绩资料数据\n");
	printf("3.删除：根据学号删除一个学生\n");
	printf("4.查询：根据学号查询一个学生的成绩资料数据\n");
	printf("5.计算：批量计算所有学生的总成绩、班级排名、校级排名。只有各项数据都为有效数据时（-1为无效数据），才能计算.\n");
	while (1)
	{
		printf("输入选项:");
		fflush(stdin);
		scanf("%d", &option);
		if (option < 1 || option > 5)
			printf("输入有误，请重新输入.\n");
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
//输入成绩菜单
void inputPerformanceData()
{
	int option, quantity;
	printf("\t\t请选择添加哪种学生的成绩\n");
	printf("1-本科生 \t 2-研究生\n");
	printf("请输入选项:");
	while (1)
	{
		scanf("%d", &option);
		if(option != 1 && option != 2)
			printf("输入有误，请重新输入：");
		else
			break;
	}
	printf("\t\t请选择添加数量:\n");
	printf("1-单个 \t 2-多个\n");
	printf("请输入选项:");
	while (1)
	{
		scanf("%d", &quantity);
		if(quantity != 1 && quantity != 2)
			printf("输入有误，请重新输入：");
		else
			break;
	}
	inputScore(option, quantity);
}
//参数说明:stu:1-本科生 2-研究生 quantity:1-单个 2-多个
void inputScore(int stu, int quantity)
{
	int index;
	int score[3];
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	int id;
	printf("请输入需要输入成绩的学生的学号:");
	scanf("%d", &id);
	if (stu == 1) //查找本科生
	{
		pSUG = SUGHead;
		if(pSUG == NULL)
		{
			printf("链表中无本科生数据,即将返回上一级\n");
			system("pause");
			return;
		}
		do{
			if(pSUG->id == id)
			{
				if(checkSUGScore(pSUG) == 0)
				{
					printf("学号为%d的本科生已有成绩，无需输入\n", id);
					system("pause");
					return;
				}
				else
				{
					printf("学号为%d本科生的本科生成绩如下:(-1为无效成绩)\n", id);
					printf("学号\t\t姓名\t\t数学\t\t英语\t\tC语言\n");
					printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
					id, pSUG->name, pSUG->score[0], pSUG->score[1], pSUG->score[2]);
					if(quantity == 1) //输入单个成绩
					{
						printf("1-数学 2-英语 3-C语言\n");
						printf("输入要更改的成绩:\n");
						scanf("%d", &index);
						printf("输入分数:");
						fflush(stdin);
						scanf("%d", &score[0]);
						pSUG->score[index - 1] = score[0];
						printf("成绩修改完成\n");
						system("pause");
						return;
					}
					else //输入多个成绩
					{
						printf("请依次输入数学、英语、C语言成绩:");
						fflush(stdin);
						for (index = 0; index < 3; index++)
						{
							scanf("%d", score[index]);
							pSUG->score[index] = score[index];
						}
						printf("该本科生的全部成绩修改完成\n");
						system("pause");
						return;
					}
				}
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("未找到学号为%d的本科生!\n", id);
	}
	else //查找研究生
	{
		pSPG = SPGHead;
		if(pSPG == NULL)
		{
			printf("链表中无研究生数据,即将返回上一级\n");
			system("pause");
			return;
		}
		do{
			if(pSPG->id == id)
			{
				if(checkSPGScore(pSPG) == 0)
				{
					printf("学号为%d的研究生已有成绩，无需输入\n", id);
					system("pause");
					return;
				}
				else
				{
					printf("学号为%d研究生的研究生成绩如下:(-1为无效成绩)\n", id);
					printf("学号\t\t姓名\t\t综合课程\t\t论文\n");
					printf("%d\t\t%s\t\t%d\t\t%d\n",
					id, pSPG->name, pSPG->score[0], pSPG->score[1]);
					if(quantity == 1) //输入单个成绩
					{
						printf("1-综合课程 2-论文成绩\n");
						printf("输入要更改的成绩:\n");
						scanf("%d", &index);
						printf("输入分数:");
						fflush(stdin);
						scanf("%d", &score[0]);
						pSPG->score[index - 1] = score[0];
						printf("成绩修改完成\n");
						system("pause");
						return;
					}
					else //输入多个成绩
					{
						printf("请依次输入综合课程和论文成绩:");
						fflush(stdin);
						for (index = 0; index < 2; index++)
						{
							scanf("%d", &score[index]);
							pSPG->score[index] = score[index];
						}
						printf("该研究生的全部成绩修改完成\n");
						system("pause");
						return;
					}
				}
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("未找到学号为%d的研究生!", id);
	}
}
//修改成绩菜单
void modifyPerformanceData()
{
	int option, id;
	printf("-----修改成绩菜单-----\n");
	printf("1-修改本科生成绩\t2-修改研究生成绩\n");
	printf("请输入选项:");
	do
	{
		scanf("%d", &option);
		if(option != 1 && option != 2)
			printf("输入有误，请重新输入:");
		else
			break;
	} while (1);
	printf("请输入被修改成绩的学生的学号:");
	scanf("%d", &id);
	modifyScore(option, id);
}
//根据学号修改学生的成绩
void modifyScore(int stu, int id)
{
	int index;
	int score[3];
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	if (stu == 1) //修改本科生
	{
		pSUG = SUGHead;
		if (pSUG == NULL)
		{
			printf("链表中无本科生数据,即将返回上一级\n");
			system("pause");
			return;
		}
		do
		{
			if (pSUG->id == id)
			{
				printf("学号为%d的本科生成绩如下:(-1为无效成绩)\n", id);
				printf("学号\t\t姓名\t\t数学\t\t英语\t\tC语言\n");
				printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
					   id, pSUG->name, pSUG->score[0], pSUG->score[1], pSUG->score[2]);
				printf("请依次输入数学、英语、C语言成绩:");
				for (index = 0; index < 3; index++)
				{
					scanf("%d", &score[index]);
					pSUG->score[index] = score[index];
				}
				printf("该本科生的全部成绩修改完成\n");
				system("pause");
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("未找到学号为%d的本科生!\n", id);
	}
	else //查找研究生
	{
		pSPG = SPGHead;
		if(pSPG == NULL)
		{
			printf("研究生链表无数据,即将返回上一层\n");
			system("pause");
			return;
		}
		do
		{
			if (pSPG->id == id)
			{
				printf("学号为%d的研究生成绩如下:(-1为无效成绩)\n", id);
				printf("学号\t\t姓名\t\t综合课程\t\t论文\n");
				printf("%d\t\t%s\t\t%d\t\t%d\n",
					   id, pSPG->name, pSPG->score[0], pSPG->score[1]);
				printf("请依次输入综合课程和论文成绩:");
				fflush(stdin);
				for (index = 0; index < 2; index++)
				{
					scanf("%d", score[index]);
					pSPG->score[index] = score[index];
				}
				printf("该研究生的全部成绩修改完成\n");
				system("pause");
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("未找到学号为%d的研究生.\n", id);
		system("pause");
	}
}
//删除学生成绩数据菜单
void deletePerformanceData()
{
	int stu, id;
	printf("-----删除学生成绩数据菜单-----\n");
	printf("1-本科生\t2-研究生\n");
	printf("请输入选项:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	printf("请输入需要删除学生的学号:");
	scanf("%d", &id);
	deleteScore(stu, id);
}
//根据学号删除一个学生成绩数据（相关数据设置成-1） stu:1-本科生 2-研究生
void deleteScore(int stu, int id)
{
	SUG *pSUG = SUGHead;
	SPG *pSPG = SPGHead;
	int i;
	if (stu == 1) //删除本科生
	{
		do
		{
			if (pSUG->id == id)
			{
				for (i = 0; i < 3; i++)
					pSUG->score[i] = -1;
				printf("学号为%d的本科生的所有成绩已设置为-1\n", id);
				return;
			}
			else
				pSUG = pSUG->next;
		} while (pSUG != NULL);
		if (pSUG == NULL)
			printf("未找到学号为%d的本科生,即将返回\n", id);
	}
	else //删除研究生
	{
		do
		{
			if (pSPG->id == id)
			{
				for (i = 0; i < 2; i++)
					pSPG->score[i] = -1;
				printf("学号为%d的研究生的所有成绩已设置为-1\n", id);
				return;
			}
			else
				pSPG = pSPG->next;
		} while (pSPG != NULL);
		if (pSPG == NULL)
			printf("未找到学号为%d的研究生,即将返回\n", id);
	}
}
//查询成绩菜单
void inquirePerformanceData()
{
	int stu, id;
	printf("-----查询成绩菜单-----\n");
	printf("查询何种学生成绩?\n");
	printf("1-本科生\t2-研究生\n");
	printf("输入选项:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	printf("输入需要查找学生的id:");
	scanf("%d", &id);
	inquireScore(stu, id);
}
//根据学号查找学生成绩 stu:1-本科生 2-研究生 id:需要查找学生的学号
void inquireScore(int stu, int id)
{
	SUG *pSUG = NULL;
	SPG *pSPG = NULL;
	if (stu == 1) //查找本科生
	{
		pSUG = SUGHead;
		do
		{
			if (pSUG->id == id)
			{
				printf("已找到学号为%d的本科生的成绩信息\n", id);
				printf("学号\t\t姓名\t\t数学\t\t英语\t\tC语言\t\t总成绩\t\t班排名\t\t校排名\n");
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
			printf("未找到学号为%d的本科生的成绩信息,即将返回\n", id);
			return;
		}
	}
	else //查找研究生
	{
		pSPG = SPGHead;
		do
		{
			if (pSPG->id == id)
			{
				printf("已找到学号为%d的研究生的成绩信息\n", id);
				printf("学号\t\t姓名\t\t综合课程\t\t论文\t\t总成绩\t\t班排名\t\t校排名\n");
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
			printf("未找到学号为%d的研究生的成绩信息,即将返回\n", id);
			return;
		}
	}
}
//计算成绩函数
void calculatePerformanceData()
{

	SUG *pSUG = SUGHead, *psug;//小写为遍历用
	SPG *pSPG = SPGHead, *pspg;
	printf("正在计算所有学生成绩,请稍后……\n");
	calculateSUGTotalScore();
	while (pSUG != NULL)
	{
		if (checkSUGScore(pSUG) == 0) //当前学生没有无效成绩
		{ //开始计算本科生排名
			pSUG->score[4] = pSUG->score[5] = 1;
			psug = SUGHead;
			while (psug != NULL)
			{
				if (psug->score[3] > pSUG ->score[3])
				{
					if (strcmp(psug->class, pSUG->class) == 0)//二者在同一个班
					{
						pSUG->score[4]++; //当前学生班排名+1
						pSUG->score[5]++; //当前学生校排名+1
					}
					else
						pSUG->score[5]++; //当前学生校排名+1
				}
				psug = psug->next; //被比较节点后移
			}
		}
		pSUG = pSUG->next;
	}
	printf("本科生成绩计算完毕\n");
	printf("正在计算研究生成绩,请稍后……\n");
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
	printf("研究生成绩计算完毕\n");
}
//计算本科生总成绩
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
//计算研究生总成绩
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

//排名功能菜单
void Calculate_rank(){
	int stu/*, option*/;
	printf("-----排名功能菜单-----\n");
	printf("请选择操作的学生类型:\n");
	printf("1-本科生	2-研究生\n");
	printf("请输入选项:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	if (stu == 1)
		calculateSUGRank();
	else
		calculateSPGRank();
}
//计算所有本科生的总成绩和班校排名
void calculateSUGRank()
{
	SUG *pSUG = SUGHead, *psug;
	printf("正在计算所有本科生的总成绩与班校排名,请稍后……\n");
	calculateSUGTotalScore();
	while (pSUG != NULL)
	{
		if (checkSUGScore(pSUG) == 0) //当前学生没有无效成绩
		{ //开始计算本科生排名
			pSUG->score[4] = pSUG->score[5] = 1;
			psug = SUGHead;
			while (psug != NULL)
			{
				if (psug->score[3] > pSUG ->score[3])
				{
					if (strcmp(psug->class, pSUG->class) == 0)//二者在同一个班
					{
						pSUG->score[4]++; //当前学生班排名+1
						pSUG->score[5]++; //当前学生校排名+1
					}
					else
						pSUG->score[5]++; //当前学生校排名+1
				}
				psug = psug->next; //被比较节点后移
			}
		}
		pSUG = pSUG->next;
	}
	printf("所有本科生的总成绩与班校排名计算完毕\n");
}
//计算所有研究生的总成绩和班校排名
void calculateSPGRank()
{
	SPG *pSPG = SPGHead, *pspg;
	printf("正在计算研究生的总成绩和班校排名,请稍后……\n");
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
	printf("所有研究生的总成绩和班校排名计算完毕\n");
}

//3.排序功能菜单
void Sort_print()
{
	int stu, option;
	char class[30];
	printf("-----排序输出菜单-----\n");
	printf("请选择需要操作的学生类型\n");
	printf("1-本科生	2-研究生\n");
	printf("请输入:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	printf("请选择功能.\n");
	printf("1-全校学生信息按总成绩从高到低排序并显示\n");
	printf("2-某个班学生信息按总成绩从高到低排序并显示\n");
	printf("请输入:");
	do
	{
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("输入有误，请重新输入:");
	} while (option != 1 && option != 2);
	if (option == 1) //显示全校学生信息
	{
		if (stu == 1)
			schoolSort(SUGHead);
		else
			postSchoolSort(SPGHead);
	}
	else //按班级显示
	{
		if (stu == 1)
		{
			printf("请输入需要显示的本科生班级:");
			fflush(stdin);
			scanf("%s", &class);
			classSort(SUGHead, class);
		}
		else
		{
			printf("请输入需要显示的研究生班级：");
			fflush(stdin);
			scanf("%s", &class);
			postClassSort(SPGHead, class);
		}
	}
}

//4.查询功能菜单
void Inquire_information()
{
	int stu, option, chose;
	char class[30];
	printf("-----查询功能菜单-----\n");
	printf("请选择需要操作的数据:\n");
	printf("1-本科生	2-研究生\n");
	printf("请选择:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
			printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	printf("请选择需要实现的功能:\n");
	printf("1-分页显示全部学生的信息\n");
	printf("2-按班级显示本班全部学生信息\n");
	printf("3-根据学号或者姓名查询学生信息\n");
	printf("4-在某个班级中查询某门课成绩不及格学生信息\n");
	printf("请输入选项:");
	do
	{
		scanf("%d", &option);
		if (option < 1 || option > 4)
			printf("输入有误，请重新输入:");
	} while (option < 1 || option > 4);
	if (option == 1)//选择了功能1
	{
		if (stu == 1)
			showAll(SUGHead);
		else
			postShowAll(SPGHead);
	}
	else if (option == 2)//选择了功能2
	{
		if (stu == 1)
		{
			printf("请输入要显示的本科生班级:");
			scanf("%s", &class);
			classShow(SUGHead, class);
		}
		else
		{
			printf("请输入要显示的研究生班级:");
			scanf("%s", &class);
			postClassShow(SPGHead, class);
		}
	}
	else if (option == 3)//选择了功能3
	{
		int id;
		char name[20];
		if (stu == 1) //操作本科生数据
		{
			printf("输入本科生学号还是姓名?\n");
			printf("1-学号	2-姓名\n");
			printf("输入:");
			scanf("%d", &chose);
			if (chose == 1)
			{
				printf("输入本科生学号:");
				scanf("%d", &id);
				showOne1(SUGHead, id);
			}
			else
			{
				printf("输入本科生姓名:");
				scanf("%s", &name);
				showOne2(SUGHead, name);
			}
		}
		else //操作研究生数据
		{
			printf("输入研究生学号还是姓名?\n");
			printf("1-学号	2-姓名\n");
			printf("输入:");
			scanf("%d", &chose);
			if (chose == 1)
			{
				printf("输入研究生学号:");
				scanf("%d", &id);
				postShowOne1(SPGHead, id);
			}
			else
			{
				printf("输入研究生姓名:");
				scanf("%s", &name);
				postShowOne2(SPGHead, name);
			}
		}
	}
	else //选择了功能4
	{
		if (stu == 1)
		{
			printf("输入班级和科目，查询该班该科所有不及格的本科生\n");
			printf("输入需要查询的班级:");
			scanf("%s", &class);
			printf("请选择科目:1-高数	2-英语	3-C语言\n");
			scanf("%d", &chose);
			showClassPass(SUGHead, class, chose);
		}
		else
		{
			printf("输入班级和科目，查询该班该科所有不及格的研究生\n");
			printf("输入需要查询的班级:");
			scanf("%s", &class);
			printf("请选择科目:1-综合课程	2-论文成绩\n");
			scanf("%d", &chose);
			showClassPass(SUGHead, class, chose);
		}
	}
}

//5.统计功能菜单
void Performance_statistic()
{
	int stu, option, lesson;
	char class[20];
	printf("-----统计功能菜单-----\n");
	printf("选择功能:\n");
	printf("1-统计并显示某门课每个班的平均成绩\n");
	printf("2-在某个班中统计并显示某门课程不同等级的学生人数\n");
	printf("请输入:");
	do
	{
		scanf("%d", &option);
		if (option != 1 && option != 2)
			printf("输入有误，请重新输入:");
	} while (option != 1 && option != 2);
	printf("请选择操作的学生类型:\n");
	printf("1-本科生	2-研究生\n");
	printf("请输入:");
	do
	{
		scanf("%d", &stu);
		if (stu != 1 && stu != 2)
		printf("输入有误，请重新输入:");
	} while (stu != 1 && stu != 2);
	if (option == 1)
	{
		if (stu == 1)
		{
			printf("请选择显示的课程:\n");
			printf("1-数学	2-英语	3-C语言\n");
			printf("请输入:");
			scanf("%d", &lesson);
			countAverage(SUGHead, lesson);
		}
		else
		{
			printf("请选择显示的课程:\n");
			printf("1-综合课程	2-论文成绩\n");
			printf("请输入:");
			scanf("%d", &lesson);
			postCountAverage(SPGHead, lesson);
		}
	}
	else
	{
		if (stu == 1)
		{
			printf("输入查找的班级:");
			scanf("%s", &class);
			printf("输入查找的课程:\n");
			printf("1-数学	2-英语	3-C语言\n");
			printf("请输入:");
			scanf("%d", &lesson);
			classCourse(SUGHead, class, lesson);
		}
		else
		{
			printf("输入查找的班级:");
			scanf("%s", &class);
			printf("输入查找的课程:\n");
			printf("1-综合课程	2-论文成绩\n");
			printf("请输入:");
			scanf("%d", &lesson);
			postClassCourse(SPGHead, class, lesson);
		}
	}
}