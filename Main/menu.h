/* 包含所有菜单展示函数 */
/*****************************************/
/**函数声明区，每写完一个就把函数头拿进来
 * 注意：必须是完全完成的才写进来（包括子函数）
 * */

void addBaseData();
void addStudent(int stu, int quantity);
void modifyBaseData();
void modifyStudent(int stu, int id);

/****************************************/
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
			printf("输入有误，请重新输入.\n");
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
		if (option < 1 && option >4)
			printf("输入有误，请重新输入.\n");
		else
			break;
	}
	switch (option)
	{
	case 1:	addBaseData();		break;
	case 2: modifyBaseData();	break;
	case 3: /*删除函数*/break;
	case 4: /*查询函数*/break;
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
		switch (stuOption)
		{
		case 1:	case 2:		break;
		default:
			printf("输入有误，请重新输入.\n");
		}
	}
	printf("添加单个还是多个?\n");
	printf("1.单个 \t 2.多个");
	while (1)
	{
		printf("输入选项:");
		scanf("%d", &quantity);
		switch (quantity)
		{
		case 1:	case 2:		break;
		default:
			printf("输入有误，请重新输入.\n");
		}
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
	static int number;
	if(stu == 1)
	{
		if (quantity == 1)
			printf("输入该本科生的姓名 性别 专业 班级:\n");
		else
			printf("输入若干本科生的姓名 性别 专业 班级:(性别输入-1以结束)\n");
		fflush(stdin);
		while (1)
		{
			printf("输入第%d个学生:", number + 1);
			newSUG = newSUGNode();
			scanf("%s%d%s%s", &newSUG->name, &newSUG->sex, &newSUG->profession, &newSUG->class);
			if (newSUG->sex == -1) break;
			if (SUGHead == NULL) //本科生链表无数据时
			{
				SUGHead = newSUG; //置该节点为头节点
				SUGHead->id = 1;
				SUGTail = newSUG;
			}
			else
			{
				newSUG->id = SUGTail->id + 1;
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
			printf("输入该研究生的姓名 性别 专业 班级 研究方向 导师:\n");
		else
			printf("输入若干研究生的姓名 性别 专业 班级 研究方向 导师:(性别输入-1以结束)\n");
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
				SPGTail = newSPG;
			}
			else
			{
				newSPG->id = SPGTail->id + 1;
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