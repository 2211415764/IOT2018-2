#include"head.h"

//����������
BiTree* createTree(BiTree* root)
{
	char ch;
	ch = getchar();                            
	root = (BiTree*)malloc(sizeof(BiTree));
	if (ch == '#')  return NULL;                   //'#'��ʾû�к��ӣ�ָ�븳��
	else {
		root->data = ch;                           //�����ң����򴴽�������
		root->lchild = createTree(root->lchild);
		root->rchild = createTree(root->rchild);
		return root;
	}
}

//����������������ݹ飩
void rec_Midorder(BiTree* root)
{
	if (root)                                      //�ݹ�ѭ���Ļ��������������ڵ㲻Ϊ��
	{
		rec_Midorder(root->lchild);                //���������ݹ����������
		printf("%c ", root->data);
		rec_Midorder(root->rchild);
	}
}

//����������������ǵݹ顪��ջ��
void Midorder(BiTree* root)
{
	stack<BiTree*> s;                              //����һ�����BiTreeָ�����͵�ջ
	while (root || !s.empty())                     //ѭ���Ľ�����������ָ��Ϊ�ղ���ջΪ��
	{
		if (root)                                  //ָ�벻Ϊ�յ�ʱ�򣬰�ָ����ջ��
		{                                          //���ң������������
			s.push(root);
			root = root->lchild;
		}
		else                                      //���ָ��Ϊ�գ�֤���Ѿ��ߵ�������ߣ����Կ�ʼ�����
		{                               
			root = s.top();                       //ȡջ����Ԫ�ز���ӡ
			printf("%c ", root->data);            
			root = root->rchild;                  //��������ˣ��Լ�Ҳ����ˣ���ʼ��������          
			s.pop();                              //��ջ��Ԫ��ɾ��      
		}
	}
}


//�����������Ĵ���
ThreadBi* createThreatBiTree(ThreadBi* root)
{
	char ch;
	ch = getchar();
	root = (ThreadBi*)malloc(sizeof(ThreadBi));
	if (ch == '#') return NULL;
	else {
		root->data = ch;
		root->ltag = Link;                   //���򴴽��������������
		root->rtag = Link;
		root->lchild = createThreatBiTree(root->lchild);
		root->rchild = createThreatBiTree(root->rchild);
	}
	return root;
}

//������������������ȫ����
ThreadBi* all_Thread(ThreadBi* root)
{
	ThreadBi* top;
	ThreadBi* pre;
	top = (ThreadBi*)malloc(sizeof(ThreadBi));
	pre = top;                                    //top�ڵ�ĳ�ʼ��
	top->ltag = Link;   top->rtag = Thread;
    top->rchild = top;
	if (!root)  top->lchild = top;                //���ڵ�Ϊ�գ�top�ڵ�����ָ���Լ�
	else {
		top->lchild = root;
		pre = rec_Thread(root, pre);					  //����������
		pre->rtag = Thread;                       
		pre->rchild = top;                        //������������һ���ڵ������Ϊtop�ڵ�
		top->rchild = pre;
	}
	return top;
}

//������������������(����β�����������)
ThreadBi* rec_Thread(ThreadBi* root, ThreadBi* pre)     //pre�Ǹ��ڵ���������е�ǰ�����
{
	if(root)
	{
		pre = rec_Thread(root->lchild, pre);
		if (!root->lchild) {                            //��ǰ�ĸ��ڵ����û�����ӣ���ô�ͽ���ǰ��
			root->ltag = Thread;
			root->lchild = pre;
		}
		if (!pre->rchild) {                             //��ǰ���ڵ��ǰ���ڵ����û���Һ��ӣ��������
			pre->rtag = Thread;
			pre->rchild = root;
		}
		pre = root;                                     //ǰ���ڵ���ϸ��ڵ�
		pre = rec_Thread(root->rchild, pre);            
		return pre;
	}
	else {
		return pre;
	}
	
}

//�������������������
void order_Thread(ThreadBi* top)
{
	ThreadBi* p;
	p = top->lchild;
	while (p != top)
	{
		while (p->ltag == Link)  p = p->lchild;         //�����ߵ�ͷ
		printf("%c ", p->data);                         //�����ǰ��������ڵ㣨��
		while (p->rtag == Thread && p->rchild != top)   //��p���������������һ���ڵ��ʱ��
		{                                               //ͨ�������ҵ���ǰ�ڵ��������
			p = p->rchild;
			printf("%c ", p->data);                     //�����̽ڵ㣨����
		}
		p = p->rchild;                                  //�������������ң�
	}
}


//������̬�����������Һ��ӣ�˫�ף���������������,�������������
void TriArr_Huffmantree(){
	int m, n, i;
	printf("������Ȩֵ�ĸ���:\n");
	scanf("%d", &n);
	if (n <= 1) printf("����Ϊ0��1\n");
	else
	{
		m = 2 * n - 1;
		Arr_Huffmantree* p;
		p = (Arr_Huffmantree*)malloc((m+1) * sizeof(Arr_Huffmantree));
		printf("������Ȩֵ:\n");                  //�����㹻�ռ����������ȥ����Ȩֵ
		for (i = 1; i <= n; i++) {
			p[i] = {0,0,0,0};
			scanf("%d", &p[i].weight);
		}
		for (i = n + 1; i <= m; i++) {
			p[i] = {0,0,0,0};
		}                                         //�������������Ҷ�Ӻͷ�Ҷ�ӽڵ�ĳ�ʼ��
		build_Huffmantree(p, n + 1, m);               //���ú������й��������ṹ�
		print_code(p, n);
	}
}

//�����ĵ��ú������ھ�̬�����������Һ��ӣ�˫�ף��ڽ��нṹ�
void build_Huffmantree(Arr_Huffmantree* &p,int mark,int max)
{
	while (mark <= max)                     
	{
		int s1, s2;
		find_min(s1,s2,mark-1,p);             //���ú����ҵ�������˫�׵���СҶ�ӽڵ���±�
		p[s1].parent = mark; p[s2].parent = mark;
		p[mark].lchild = s1; p[mark].rchild = s2;
		p[mark].weight = p[s1].weight + p[s2].weight;
		mark++;                               //������СҶ�ӽڵ�ƴ�ӳ����ǵ�˫�ף�markָ�����һλ
	}
}

//���ĵ��ú�����Ѱ��������С����û��˫�׵ĵ�Ҷ�ӽڵ���±�s1��s2��
void find_min(int& s1, int& s2,int end,Arr_Huffmantree* &p)
{
	int i = 1;                              //s1Ϊ��С��s2Ϊ�ڶ�С
	s1 = s2 = 0;                            //����0�±��s1,s2��Ȩֵ��Ϊ���
	p[0].weight = 99999;
	for (i = 1; i <= end; i++)              //��1��ʼ��end�������αȽ�
	{
		if (!p[i].parent)                   //������˫�׵Ľڵ�
		{
			if (p[i].weight < p[s1].weight) //���i��Ȩֵ��s1ҪС
			{
				s2 = s1;
				s1 = i;                     //ͬʱ����������Сֵ
			}
			else if (p[i].weight < p[s2].weight)  s2 = i;
		}                                    //���i��Ȩֵ��s1����ȴ��s2С����ô��������s2
	}
}

//���ú�������ò�������������룩
void print_code(Arr_Huffmantree* p,int n)
{
	char** code;
	code = (char**)malloc(sizeof(char*) * (n + 1));  //��̬�����ά�����ű��� 
	char* save;
	save = (char*)malloc((n+1) * sizeof(char));    //��̬����һά�����ŵ�ǰ���еı��� 
	save[n] = '\0';                //����ֹͣ�� 
	int child = 0 , parent = 0 , start = 0;
	int i, j;
	for (i = 1; i <= n; i++) {
		start = n;
		child = i;
		for (parent = p[child].parent; parent != 0; parent = p[parent].parent)
		{
			if (child == p[parent].lchild)  save[--start] = '0';
			else if (child == p[parent].rchild) save[--start] = '1';
			child = parent;       //��0��1���б��� 
		}
		code[i] = (char*)malloc((n+1-start) * sizeof(char));   //���������ڴ� 
		memcpy(code[i], &save[start], n+ 1 - start);   //��save�еı��뿽����code�� 
		printf("��%d��Ȩֵ��Ӧ�ı���Ϊ:", i);
		j = 0;
		while (code[i][j])
		{
			printf("%c ", code[i][j]);  //������� 
			j++;
		}
		printf("\n");
	}
}



void menu(BiTree* &root,ThreadBi* &Thread_root, ThreadBi*& top)
{
	int opt;
	int flag = 0;
	while (flag == 0) 
	{
		printf("********************************************\n");
		printf("*******  1.�������Ľ���               ******\n");
		printf("*******  2.������������������ݹ飩   ******\n");
		printf("*******  3.������������������ǵݹ飩 ******\n");
		printf("*******  4.�����������Ľ��������     ******\n");
		printf("*******  5.�������������             ******\n");
		printf("*******  0.�˳�����                   ******\n");
		printf("********************************************\n");
		printf("����������ʵ�ֵĹ���:\n");
		scanf("%d",&opt);

		switch (opt)
		{
		case 1:
			getchar();
			printf("���������빹��Ķ��������������У���#��ʾ��:\n");
			root = createTree(root);
			printf("������������ɣ���ִ��ѡ��2��3��\n");
			break;

		case 2:
			if (!root) printf("����δ�����������������Ƚ��е�һ��������\n");
			else
			{
				printf("�õݹ��㷨��������˶������Ľ��Ϊ:");
				rec_Midorder(root);
			}
			printf("\n");
			break;
		
		case 3:
			if (root)
			{
				printf("�÷ǵݹ��㷨��������˶������Ľ��Ϊ:");
				Midorder(root);
				printf("\n");
			}
			else printf("����δ�����������������Ƚ��е�һ��������\n");
			break;
		
		case 4:
			getchar();
			printf("���������빹����������������������У���#��ʾ��:\n");
			Thread_root = createThreatBiTree(Thread_root);
			top = all_Thread(Thread_root);
			printf("����������������ϣ�������������������Ľ��Ϊ:\n");
			order_Thread(top);
			printf("\n");
			break;

		case 5:
			TriArr_Huffmantree();
			break;

		case 0:
			flag = 1;
			break;

		default:
			printf("����������������������\n");
			break;
		}
	} 
}
