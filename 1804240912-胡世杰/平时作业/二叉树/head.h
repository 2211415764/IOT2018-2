#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;


//����������ṹ
typedef char ElemType;
typedef struct BiTreeNode{
	ElemType data;
	BiTreeNode* lchild, * rchild;
}BiTree;

//��������������ṹ
enum Pionter{Link , Thread};
typedef struct ThreadNode{
	ElemType data;
	ThreadNode* lchild, * rchild;
	Pionter ltag, rtag;
}ThreadBi;

//��������������ṹ
typedef struct Arr_Huffmantree{
	int weight;
	int parent, lchild, rchild;
}Arr_Huffmantree;




//���ú���
BiTree* createTree(BiTree* root);                              //����������
void rec_Midorder(BiTree* root);                               //�ݹ��������������
void Midorder(BiTree* root);                                   //�ǵݹ��������������
 
ThreadBi* createThreatBiTree(ThreadBi* root);                  //��������������
ThreadBi* all_Thread(ThreadBi* root);                          //����������������
ThreadBi* rec_Thread(ThreadBi* root, ThreadBi* pre);           //��һ�����ú��������������̺���
void order_Thread(ThreadBi* top);                              //�����������������

void TriArr_Huffmantree();                                     //���������������������������
void build_Huffmantree(Arr_Huffmantree* &p,int mark,int max);  //(һ�����ú���)��������������������
void find_min(int& s1, int& s2, int end, Arr_Huffmantree* &p); //���������ú������ҵ���С������Ȩֵ�������
void print_code(Arr_Huffmantree* p, int n);                    //��һ�����ú�������ӡ����������
void menu(BiTree* &root, ThreadBi* &Thread_root,ThreadBi* &top);              //�˵�


