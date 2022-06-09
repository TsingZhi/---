//3.1 所有学生信息按总成绩从高到低排序并显示。
//所有本科生信息按总成绩从高到低排序并显示。
void schoolSort(struct underGraduate* Head);//输出所有学生信息（按排名先后输出）
void schoolSort(struct underGraduate* HEAD) {
	struct underGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1,j,k;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[4] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[3] < p1->score[3])p->score[4]++;
			}
				p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	Head->score[5] = i;
	while (Head != NULL) {
		i++;
		if (Head->next != NULL) {
			if (Head->score[3] == Head->next->score[3])Head->next->score[5] = Head->score[5];
			else Head->next->score[5] = i;
		}
		if(Head->sex==0)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", Head->id, Head->name,"女", 
			Head->profession, Head->class, Head->score[0], Head->score[1], 
			Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
		if(Head->sex==1)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", 
			Head->id, Head->name, "男", Head->profession, Head->class, Head->score[0], 
			Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
		Head = Head->next;
	}
	system("pause");
}
//所有研究生信息按总成绩从高到低排序并显示。
void postSchoolSort(struct postGraduate* Head);//输出所有学生信息（按排名先后输出）
void postSchoolSort(struct postGraduate* HEAD) {
	struct postGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1, j, k;
	int id, score[5];
	enum Sex sex;
	char class[30], profession[20], name[10],direction[20],teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[3] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[2] < p1->score[2])p->score[3]++;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	Head->score[4] = i;
	while (Head != NULL) {
		i++;
		if (Head->next != NULL) {
			if (Head->score[2] == Head->next->score[2])Head->next->score[4] = Head->score[4];
			else Head->next->score[4] = i;
		}
		if (Head->sex == 0)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", Head->id, Head->name, "女", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
		if (Head->sex == 1)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
		Head = Head->next;
	}
	system("pause");
}

//3.2 某个班学生信息按总成绩从高到低排序并显示。
void classSort(struct underGraduate* Head, char Class[]);//查询某个班学生信息（按排名先后输出）
void classSort(struct underGraduate* HEAD, char Class[]) {
	struct underGraduate* Head=NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;
	int id, score[6];
	enum Sex sex;
	char class[30],profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class,p3->class); strcpy(p3->class,p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);

				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}

			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[5] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[3] == p1->next->score[3])p1->next->score[5] = p1->score[5];
			else p1->next->score[5] = i;
		}
		p1 = p1->next;

	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}

	i = 1;
	head->score[4] = i;
	while (head != NULL) {
		i++;
		
		if(head->sex==0)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", head->id, head->name, "女", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
		if(head->sex==1)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", head->id, head->name, "男", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
		if (head->next != NULL) {
			if (head->score[3] == head->next->score[3])head->next->score[4] = head->score[4];
			else head->next->score[4] = i;
		}
		head = head->next;
	}
}
void postClassSort(struct postGraduate* Head, char Class[]);//查询某个班学生信息（按排名先后输出）
void postClassSort(struct postGraduate* HEAD, char Class[]) {
	struct postGraduate* Head = NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;
	int id, score[5];
	enum Sex sex;
	char class[30], profession[30], name[16],direction[20],teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p->score[2] = p->score[0] + p->score[1];
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[4] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[2] == p1->next->score[2])p1->next->score[4] = p1->score[4];
			else p1->next->score[4] = i;
		}
		p1 = p1->next;
	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = 1;
	head->score[3] = i;
	while (head != NULL) {
		i++;
		if (head->sex == 0)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", head->id, head->name, "女", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		if (head->sex == 1)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", head->id, head->name, "男", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		if (head->next != NULL) {
			if (head->score[2] == head->next->score[2])head->next->score[3] = head->score[3];
			else head->next->score[3] = i;
		}
		head = head->next;
	}
}

//4.查询功能
//4.1分页显示全部学生的信息
void postShowAll(struct postGraduate* Head);//分页输出所有学生信息（按学号）
void postShowAll(struct postGraduate* HEAD) {
	struct postGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL, s[100];
	int i = 1, j, k, n;
	int id, score[5];
	enum Sex sex;
	char class[30], profession[20], name[10],direction[20],teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 ) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[3] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0)
				if (p->score[2] < p1->score[2])p->score[3]++;
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	Head->score[4] = i;
	p = Head;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[2] == p->next->score[2])p->next->score[4] = p->score[4];
			else p->next->score[4] = i;
		}
		p = p->next;
	}
	i = i - 1;

	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->id > p4->id) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 0;
	j = 0;
	while (Head != NULL) {
		s[i++] = *Head;
		Head = Head->next;
	}
	n = i;
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "学号", "姓名", "性别", "专业", "班级", "研究方向", "导师", "综测成绩", "论文成绩", "总成绩","班排名", "校排名");
	for (i = j; i < 10; i++) {
		if (s[i].sex == 0)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class,s[i].direction,s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
		if (s[i].sex == 1)
			printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
		if (i == n)break;
	}
	if (n <= 10) {
		printf("输入5返回上一级菜单\n");
		scanf("%d", &k);
		if (k == 5) {}
	}
	if (n > 10) {
		printf("输入1下一页，输入2尾页");
		scanf("%d", &k);
		system("cls");
		while (1) {
			if (k == 1) {
				j = i;
				for (i = j; i < j + 10; i++) {
					if (s[i].sex == 0)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
					if (s[i].sex == 1)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
					if (i == (n / 10) * 10 + n % 10)break;
				}
			}
			if (k == 2) {
				for (i = (n / 10) * 10; i < (n / 10) * 10 + n % 10; i++) {
					if (s[i].sex == 0)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
					if (s[i].sex == 1)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4]);
				}
			}
			if (k == 3) {
				j = (i / 10 - 1) * 10;
				for (i = j; i < j + 10; i++) {
					if (s[i].sex == 0)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t", s[i].id, s[i].name, "女", s[i].profession, 
						s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], 
						s[i].score[2], s[i].score[3], s[i].score[4]);
					if (s[i].sex == 1)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t", s[i].id, s[i].name, "男", s[i].profession, 
						s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], 
						s[i].score[2], s[i].score[3], s[i].score[4]);
				}
			}
			if (k == 4) {
				for (i = 0; i < 10; i++) {
					if (s[i].sex == 0)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t", s[i].id, s[i].name, "女", s[i].profession, 
						s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], 
						s[i].score[2], s[i].score[3], s[i].score[4]);
					if (s[i].sex == 1)
						printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t", s[i].id, s[i].name, "男", s[i].profession, 
						s[i].class, s[i].direction, s[i].teacher, s[i].score[0], s[i].score[1], 
						s[i].score[2], s[i].score[3], s[i].score[4]);
				}
			}
			if (k == 5) {

			}

			if (i == (n / 10) * 10 + n % 10) {
				printf("输入3上一页，输入4第一页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
			if (i == 10 && i != (n / 10) * 10 + n % 10) {
				printf("输入1下一页，输入2尾页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
			if (i > 10 && i < (n / 10) * 10) {
				printf("输入1下一页，输入2尾页，输入3上一页,输入4第一页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
		}
	}
}
void showAll(struct underGraduate* Head);//分页输出所有学生信息（按学号）
void showAll(struct underGraduate* HEAD) {
	struct underGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL, s[100];
	int i = 1, j, k, n;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[4] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0)
				if (p->score[3] < p1->score[3])p->score[4]++;
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	Head->score[5] = i;
	p = Head;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[3] == p->next->score[3])p->next->score[5] = p->score[5];
			else p->next->score[5] = i;
		}
		/*if (Head->sex == 0)
			printf("%-9d%-9s%-9s%-9s%-9s%-9d%-9d%-9d%-9d%-9d%-9d\n", Head->id, Head->name,"女", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
		if(Head->sex==1)
			printf("%-9d%-9s%-9s%-9s%-9s%-9d%-9d%-9d%-9d%-9d%-9d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
		*/
		p = p->next;
	}
	i = i - 1;

	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->id > p4->id) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 0;
	j = 0;
	while (Head != NULL) {
		s[i++] = *Head;
		Head = Head->next;
	}
	n = i ;
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n","学号","姓名","性别","专业","班级","高数成绩","C语言成绩","英语成绩","总成绩","班排名","校排名");
	for (i = j; i < 10; i++) {
		if (s[i].sex == 0)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
		if (s[i].sex == 1)
			printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
		if (i == n)break;
	}
	if (n <= 10) {
			printf("输入5返回上一级菜单\n");
			scanf("%d",&k);
			if(k==5){}
		}
	if (n > 10) {
		printf("输入1下一页，输入2尾页");
		scanf("%d", &k);
		system("cls");
		while (1) {
			if (k == 1) {
				j = i;
				for (i = j; i < j + 10; i++) {
					if (s[i].sex == 0)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
					if (s[i].sex == 1)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
					if (i == (n / 10) * 10 + n % 10)break;
				}
			}
			if (k == 2) {
				for (i = (n / 10) * 10; i < (n / 10) * 10 + n % 10; i++) {
					if (s[i].sex == 0)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
					if (s[i].sex == 1)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
				}
			}
			if (k == 3) {
				j = (i / 10 - 1) * 10;
				for (i = j; i < j + 10; i++) {
					if (s[i].sex == 0)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
					if (s[i].sex == 1)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
				}
			}
			if (k == 4) {
				for (i = 0; i < 10; i++) {
					if (s[i].sex == 0)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "女", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
					if (s[i].sex == 1)
						printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", s[i].id, s[i].name, "男", s[i].profession, s[i].class, s[i].score[0], s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].score[5]);
				}
			}
			if (k == 5) {
			}

			if (i == (n / 10) * 10 + n % 10) {
				printf("输入3上一页，输入4第一页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
			if (i == 10 && i != (n / 10) * 10 + n % 10) {
				printf("输入1下一页，输入2尾页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
			if (i > 10 && i < (n / 10) * 10) {
				printf("输入1下一页，输入2尾页，输入3上一页,输入4第一页,输入5返回上一级菜单");
				scanf("%d", &k);
				system("cls");
			}
		}
	}
}

//4.2按班级显示本班全部学生信息(按照学号顺序)
void postClassShow(struct postGraduate* Head, char Class[]);//查询某个班级学生信息（按学号先后输出）
void postClassShow(struct postGraduate* HEAD, char Class[]) {
	struct postGraduate* Head = NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;
	int id, score[5];

	enum Sex sex;
	char class[30], profession[20], name[10],direction[20],teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[4] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[2] == p1->next->score[2])p1->next->score[4] = p1->score[4];
			else p1->next->score[4] = i;
		}
		p1 = p1->next;
	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}

	i = 1;
	p = head;
	p->score[3] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[2] == p->next->score[2])p->next->score[3] = p->score[3];
			else p->next->score[3] = i;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	while (head != NULL) {
		if (head->sex == 0)
			printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		if (head->sex == 1)
			printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		head = head->next;

	}
}
void classShow(struct underGraduate* Head,char Class[]);//查询某个班级学生信息
void classShow(struct underGraduate* HEAD, char Class[]) {
	struct underGraduate* Head = NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;

	int id, score[6];

	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[5] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[3] == p1->next->score[3])p1->next->score[5] = p1->score[5];
			else p1->next->score[5] = i;
		}
		p1 = p1->next;
	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}

	i = 1;
	p = head;
	p->score[4] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[3] == p->next->score[3])p->next->score[4] = p->score[4];
			else p->next->score[4] = i;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->id > p4->id) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	while (head != NULL) {
		if (head->sex == 0)
			printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
		if (head->sex == 1)
			printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
		head = head->next;
	}
}

//4.3根据学号或姓名查询学生信息
//4.3.1根据学号查询学生信息
void showOne1(struct underGraduate* Head,int o);//按学号查询学生信息
void showOne1(struct underGraduate* HEAD, int o) {
	struct underGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1, j, k;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[4] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[3] < p1->score[3])p->score[4]++;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p = Head;
	p->score[5] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[3] == p->next->score[3])p->next->score[5] = p->score[5];
			else p->next->score[5] = i;
		}
		p = p->next;
	}
	while (Head != NULL) {
		if (Head->id==o) {
			if (Head->sex == 0)
				printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", Head->id, Head->name, "女", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
			if (Head->sex == 1)
				printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
			j = 0;
			break;
		}
		Head = Head->next;
	}
	if (j != 0) {
		printf("查无此人！\n");
	}
}
void postShowOne1(struct postGraduate* Head, int o);//按学号查询学生信息
void postShowOne1(struct postGraduate* HEAD, int o) {
	struct postGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1, j, k;
	int id, score[5];
	enum Sex sex;
	char class[30], profession[30], name[10],direction[20],teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 ) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[3] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[2] < p1->score[2])p->score[3]++;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p = Head;
	p->score[4] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[2] == p->next->score[2])p->next->score[4] = p->score[4];
			else p->next->score[4] = i;
		}
		p = p->next;
	}
	while (Head != NULL) {
		if (Head->id == o) {
			if (Head->sex == 0) 
				printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", Head->id, Head->name, "女", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
				if (Head->sex == 1)
					printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
				j = 0;
				break;
			
		}
		Head = Head->next;
	}
	if (j != 0) {
		printf("查无此人！\n");
	}
}
//4.3.2根据姓名查询学生信息
void postShowOne2(struct postGraduate* Head, char name[]);//按姓名输出学生信息
void postShowOne2(struct postGraduate* HEAD, char Name[]) {
	struct postGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1, j, k;
	int id, score[5];
	enum Sex sex;
	char class[30], profession[30], name[10], direction[20], teacher[20];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[3] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[2] < p1->score[2])p->score[3]++;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p = Head;
	p->score[4] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[2] == p->next->score[2])p->next->score[4] = p->score[4];
			else p->next->score[4] = i;
		}
		p = p->next;
	}
	while (Head != NULL) {
		if (strcmp(Head->name,Name)==0) {
			if (Head->sex == 0)
				printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", Head->id, Head->name, "女", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
			if (Head->sex == 1)
				printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->direction, Head->teacher, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4]);
			j = 0;
			break;
		}
		Head = Head->next;
	}
	if (j != 0) {
		printf("查无此人！\n");
	}
}
void showOne2(struct underGraduate* Head,char name[]);//按姓名输出学生信息
void showOne2(struct underGraduate* HEAD, char Name[]) {
	struct underGraduate* Head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;
	int i = 1, j, k;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			p1->score[4] = 1;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	p = Head;
	while (p != NULL) {
		p1 = Head;
		while (p1 != NULL) {
			if (strcmp(p->class, p1->class) == 0) {
				if (p->score[3] < p1->score[3])p->score[4]++;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p = Head;
	p->score[5] = i;
	while (p != NULL) {
		i++;
		if (p->next != NULL) {
			if (p->score[3] == p->next->score[3])p->next->score[5] = p->score[5];
			else p->next->score[5] = i;
		}
		p = p->next;
	}
	while (Head != NULL) {
		if (strcmp(Head->name, Name)==0) {
			if (Head->sex == 0)
				printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", Head->id, Head->name, "女", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
			if (Head->sex == 1)
				printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", Head->id, Head->name, "男", Head->profession, Head->class, Head->score[0], Head->score[1], Head->score[2], Head->score[3], Head->score[4], Head->score[5]);
			j = 0;
			break;
		}
		Head = Head->next;
	}
	if (j != 0) {
		printf("查无此人！\n");
	}
}

//4.4在某个班级中查询某门课成绩不及格学生信息
void postShowClassPass(struct postGraduate* Head, char class[], int i);//查询某个班级某个科目不及格的学生信息  
void postShowClassPass(struct postGraduate* HEAD, char Class[], int pass) {
	struct postGraduate* Head = NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[20], name[10], direction[20], teacher[20];
	p = HEAD;
	while (p != NULL)
	{
		if (p->score[0] != -1 && p->score[1] != -1)
		{
			if ((p1 = (struct postGraduate *)malloc(sizeof(struct postGraduate))) == NULL)
			{
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)
				Head = p1;
			else
				p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++)
	{
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[2] < p4->score[2]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				strcpy(direction, p3->direction); strcpy(p3->direction, p4->direction); strcpy(p4->direction, direction);
				strcpy(teacher, p3->teacher); strcpy(p3->teacher, p4->teacher); strcpy(p4->teacher, teacher);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[4] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[2] == p1->next->score[2])p1->next->score[4] = p1->score[4];
			else p1->next->score[4] = i;
		}
		p1 = p1->next;
	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct postGraduate*)malloc(sizeof(struct postGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}

	i = 1;
	head->score[3] = i;
	while (head != NULL) {
		i++;
		if (pass == 1) {
			if (head->score[0] < 60) {
				if (head->sex == 0)
					printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
				if (head->sex == 1)
					printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
			}
		}
		if (pass == 2) {
			if (head->score[1] < 60) {
				if (head->sex == 0)
					printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
				if (head->sex == 1)
					printf("%d	%s	%s	%s	%s	%s	%s	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
			}
		}
		// if (pass == 3) {
		// 	if (head->score[2] < 60) {
		// 		if (head->sex == 0)
		// 			printf("%-9d%-9s%-9s%-9s%-9s%-9s%-9s%-9d%-9d%-9d%-9d%-9d\n", head->id, head->name, "女", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		// 		if (head->sex == 1)
		// 			printf("%-9d%-9s%-9s%-9s%-9s%-9s%-9s%-9d%-9d%-9d%-9d%-9d\n", head->id, head->name, "男", head->profession, head->class, head->direction, head->teacher, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4]);
		// 	}
		// }
		if (head->next != NULL) {
			if (head->score[2] == head->next->score[2])head->next->score[3] = head->score[3];
			else head->next->score[3] = i;
		}
		head = head->next;
	}
}
void showClassPass(struct underGraduate* Head, char name[],int i);//查询某个班级某个科目不及格的学生信息  
void showClassPass(struct underGraduate* HEAD, char Class[], int pass) {
	struct underGraduate* Head = NULL, * head = NULL, * p, * p1, * p2 = NULL, * p3, * p4;
	int i = 1, j, k;
	int id, score[6];
	enum Sex sex;
	char class[30], profession[30],name[16];
	p = HEAD;
	while (p != NULL) {
		if (p->score[0] != -1 && p->score[1] != -1 && p->score[2] != -1) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)Head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}
	i = i - 1;
	for (j = 1; j < i; j++) {
		p3 = Head; p4 = p3->next;
		for (k = 0; k < i - j; k++) {
			if (p3->score[3] < p4->score[3]) {
				id = p3->id; p3->id = p4->id; p4->id = id;
				sex = p3->sex; p3->sex = p4->sex; p4->sex = sex;
				strcpy(profession, p3->profession); strcpy(p3->profession, p4->profession); strcpy(p4->profession, profession);
				strcpy(class, p3->class); strcpy(p3->class, p4->class); strcpy(p4->class, class);
				strcpy(name, p3->name); strcpy(p3->name, p4->name); strcpy(p4->name, name);
				score[0] = p3->score[0]; p3->score[0] = p4->score[0]; p4->score[0] = score[0];
				score[1] = p3->score[1]; p3->score[1] = p4->score[1]; p4->score[1] = score[1];
				score[2] = p3->score[2]; p3->score[2] = p4->score[2]; p4->score[2] = score[2];
				score[3] = p3->score[3]; p3->score[3] = p4->score[3]; p4->score[3] = score[3];
				score[4] = p3->score[4]; p3->score[4] = p4->score[4]; p4->score[4] = score[4];
				score[5] = p3->score[5]; p3->score[5] = p4->score[5]; p4->score[5] = score[5];
			}
			p3 = p4; p4 = p4->next;
		}
	}
	i = 1;
	p1 = Head;
	p1->score[5] = i;
	while (p1 != NULL) {
		i++;
		if (p1->next != NULL) {
			if (p1->score[3] == p1->next->score[3])p1->next->score[5] = p1->score[5];
			else p1->next->score[5] = i;
		}
		p1 = p1->next;
	}
	p = Head;
	i = 1;
	while (p != NULL) {
		if (strcmp(p->class, Class) == 0) {
			if ((p1 = (struct underGraduate*)malloc(sizeof(struct underGraduate))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			p1->next = NULL;
			*p1 = *p;
			if ((i++) == 1)head = p1; else p2->next = p1;
			p2 = p1;
		}
		p = p->next;
	}

	i = 1;
	head->score[4] = i;
	while (head != NULL) {
		i++;
		if (pass == 1) {
			if (head->score[0] < 60) {
				if (head->sex == 0)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
				if (head->sex == 1)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
			}
		}
		if (pass == 2) {
			if (head->score[1] < 60) {
				if (head->sex == 0)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
				if (head->sex == 1)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
			}
		}
		if (pass == 3) {
			if (head->score[2] < 60) {
				if (head->sex == 0)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "女", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
				if (head->sex == 1)
					printf("%d	%s	%s	%s	%s	%d	%d	%d	%d	%d	%d\n", head->id, head->name, "男", head->profession, head->class, head->score[0], head->score[1], head->score[2], head->score[3], head->score[4], head->score[5]);
			}
		}
		if (head->next != NULL) {
			if (head->score[3] == head->next->score[3])head->next->score[4] = head->score[4];
			else head->next->score[4] = i;
		}
		head = head->next;
	}
}

// 5.统计功能
//5.1统计某门科目每个班的平均分并显示
void postCountAverage(struct postGraduate *Head, int i); //统计某门科目每个班的平均分并显示
void postCountAverage(struct postGraduate *Head, int n)
{
	struct postGraduate *p, *p1;
	int count;
	float aver;
	p = Head;
	p1 = Head->next;
	while (p != NULL)
	{
		count = 1;
		aver = 0;
		p1 = p->next;
		while (p1 != NULL)
		{
			if (strcmp(p->class, p1->class) == 0)
			{
				if (p1->score[n - 1] != -1)
				{
					count++;
					p->score[n - 1] += p1->score[n - 1];
					p1->score[3] = 0;
				}
			}
			p1 = p1->next;
		}
		aver = (float) p->score[n - 1] / (float) count;
		if (p->score[3] != 0)
			printf("%s——%f\n", p->class, aver);
		p = p->next;
	}
}
void countAverage(struct underGraduate *Head, int i); //统计某门科目每个班的平均分并显示
void countAverage(struct underGraduate *Head, int n)
{
	struct underGraduate *p, *p1;
	int count;
	float aver;
	p = Head;
	p1 = Head->next;
	while (p != NULL)
	{
		count = 1;
		aver = 0;
		p1 = p->next;
		while (p1 != NULL)
		{
			if (strcmp(p->class, p1->class) == 0)
			{
				if (p1->score[n - 1] != -1)
				{
					count++;
					p->score[n - 1] += p1->score[n - 1];
					p1->score[3] = 0;
				}
			}
			p1 = p1->next;
		}
		aver = (float) p->score[n - 1] / (float) count;
		if (p->score[3] != 0)
			printf("%s——%f\n", p->class, aver);
		p = p->next;
	}
}
//5.2在某个班中统计并显示某门课程不同等级的学生人数
void postClassCourse(struct postGraduate* Head, char class[], int i);//统计并显示某个班某门科目不同等级的学生人数*/
void postClassCourse(struct postGraduate* Head, char class[], int n) {
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	while (Head != NULL) {
		if (strcmp(Head->class, class) == 0) {
			if (n == 1) {
				if (Head->score[0] >= 90)a++;
				else if (Head->score[0] >= 80 && Head->score[0] < 90)b++;
				else if (Head->score[0] >= 70 && Head->score[0] < 80)c++;
				else if (Head->score[0] < 70 && Head->score[0] >= 60)d++;
				else if (Head->score[0] < 60 && Head->score[0] != -1)e++;
			}
			if (n == 2) {
				if (Head->score[1] >= 90)a++;
				else if (Head->score[1] >= 80 && Head->score[1] < 90)b++;
				else if (Head->score[1] >= 70 && Head->score[1] < 80)c++;
				else if (Head->score[1] < 70 && Head->score[1] >= 60)d++;
				else if (Head->score[1] < 60 && Head->score[1] != -1)e++;
			}
			
		}
		Head = Head->next;
	}
	printf("优——%d人\n良——%d人\n中——%d人\n及格——%d人\n不及格——%d人\n", a, b, c, d, e);
}
void classCourse(struct underGraduate* Head, char class[], int i);//统计并显示某个班某门科目不同等级的学生人数
void classCourse(struct underGraduate* Head, char class[], int n) {
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	while (Head != NULL) {
		if (strcmp(Head->class, class) == 0) {
			if (n == 1) {
				if (Head->score[0] >= 90)a++;
				else if (Head->score[0] >= 80 && Head->score[0] < 90)b++;
				else if (Head->score[0] >= 70 && Head->score[0] < 80)c++;
				else if (Head->score[0] < 70 && Head->score[0] >= 60)d++;
				else if (Head->score[0] < 60 && Head->score[0] != -1)e++;
			}
			if (n == 2) {
				if (Head->score[1] >= 90)a++;
				else if (Head->score[1] >= 80 && Head->score[1] < 90)b++;
				else if (Head->score[1] >= 70 && Head->score[1] < 80)c++;
				else if (Head->score[1] < 70 && Head->score[1] >= 60)d++;
				else if (Head->score[1] < 60 && Head->score[1] != -1)e++;
			}
			if (n == 3) {
				if (Head->score[2] >= 90)a++;
				else if (Head->score[2] >= 80 && Head->score[2] < 90)b++;
				else if (Head->score[2] >= 70 && Head->score[2] < 80)c++;
				else if (Head->score[2] < 70 && Head->score[2] >= 60)d++;
				else if (Head->score[2] < 60 && Head->score[2] != -1)e++;
			}
		}
		Head = Head->next;
	}
	printf("优——%d人\n良——%d人\n中——%d人\n及格——%d人\n不及格——%d人\n",a,b,c,d,e);
}

