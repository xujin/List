#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int element;
	struct Node *next;
}Node;

//初始化链表
void InitList(Node **pList)
{
	*pList = NULL;
}
//创建链表
Node *CreateList(Node *pList)
{
	Node *p1 = NULL;
	Node *p2 = NULL;

	p1 = p2 = (Node*)malloc(sizeof(Node));
	if(NULL == p1 || NULL == p2)
	{
		printf("内存分配失败.\n");
		exit(1);
	}
	memset(p1, 0, sizeof(Node));
	scanf("%d", &p1->element);
	if(0 >= p1->element)
	{
		printf("输入数据不合法（小于0）\n");
		exit(1);
	}
	p1->next = NULL;
	pList = p1;

	p1 = (Node *)malloc(sizeof(Node));
	if(NULL == p1)
	{
		printf("内存分配失败.\n");
		exit(1);
	}
	memset(p1, 0, sizeof(Node));
	scanf("%d", &p1->element);
	if(0 >= p1->element)
	{
		printf("输入数据不合法(小于0)\n");
		exit(1);
	}
	p1->next = NULL;

	while(p1->element)
	{
		p2->next = p1;
		p2 = p1;

		p1 = (Node *)malloc(sizeof(Node));
		if(NULL == p1 || NULL == p2)
		{
			printf("内存分配失败.\n");
			exit(1);
		}
		memset(p1, 0, sizeof(Node));
		scanf("%d", &p1->element);
		p1->next = NULL;
	}
	return pList;
}
//打印链表
void PrintList(Node *pList)
{
	if(NULL == pList)
	{
		printf("链表为空\n");
	}
	else
	{
		while(pList)
		{
			printf("%d\t", pList->element);
			pList = pList->next;
		}
		printf("\n");
	}
}
//链表长度
unsigned int SizeList(Node *pList)
{
	unsigned int size = 0;
	if(NULL == pList)
	{
		printf("链表为空\n");
		return size;
	}
	while(pList)
	{
		size++;
		pList = pList->next;
	}
	printf("链表长度为:%u\n", size);
	return size;
}
//清空链表
void ClearList(Node *pList)
{
	Node *pNext = NULL;
	if(NULL == pList)
	{
		printf("链表为空\n");
		exit(1);
	}
	else
	{
		while(pList)
		{
			pNext = pList->next;
			free(pList);
			pList = pNext;
		}
	}
}
//检查链表是否为空
int isEmptyList(Node *pList)
{
	return (NULL == pList);
}
//获取链表pos位置的元素数据
int GetElement(Node *pList, int pos)
{
	int size = 0;
	if(NULL == pList)
	{
		printf("链表为空\n");
		exit(1);
	}
	size = SizeList(pList);
	if(0 > pos || (size - 1) < pos)
	{
		printf("pos(%d)数据不合法.\n", pos);
	}
	else
	{
		int index = 0;
		while(pList)
		{
			index++;
			if(pos == index)
			{
				break;
			}
			pList = pList->next;
		}
		if(index < pos)
		{
			printf("pos 超出链表长度");
			return 0;
		}
	}
	return pList->element;
}

//获取链表中value元素的地址
int *GetElementAddress(Node *pList, int value)
{
	if(NULL == pList)
	{
		printf("链表为空.\n");
		return NULL;
	}
	if(0 > value)
	{
		printf("value(%d)不合法.\n", value);
		return NULL;
	}
	while(pList->element != value && pList->next)
	{
		pList = pList->next;
	}
	if(pList->element != value && pList)
	{
		printf("链表中未找到数值为%d的元素.\n", value);
		return NULL;
	}
	if(pList->element == value)
	{
		printf("地址:0x%x\n", &(pList->element));
		return &(pList->element);
	}
	return NULL;
}
//修改链表中pos位置的元素数据为value
int ModifyElement(Node *pList, int pos, int value)
{
	if(NULL == pList)
	{
		printf("链表为空.\n");
		return 0;
	}
	int size = SizeList(pList);
	if(0 > pos || (size - 1) < pos)
	{
		printf("pos(%d)数值不合法.\n", pos);
		return 0;
	}
	Node *pHead = pList;
	int index = 0;
	while(pHead)
	{
		index++;
		if(index == pos)
		{
			break;
		}
		pHead = pHead->next;
	}
	if(index < pos)
	{
		printf("pos(%d超出链表长度\n", pos);
		return 0;
	}
	pList = pHead;
	pList->element = value;
	return 1;
}
//向链表头插入元素value
int InsertHead(Node **pList, int value)
{
	Node *pNode = (Node *)malloc(sizeof(Node));
	if(NULL == pNode)
	{
		printf("内存分配失败.\n");
		return 0;
	}
	memset(pNode, 0, sizeof(Node));
	
	if(NULL == *pList)
	{
		*pList = (Node *)malloc(sizeof(Node));
		if(NULL == pList)
		{
			printf("内存分配失败.\n");
			return 0;
		}
		memset(*pList, 0, sizeof(Node));
	}
	pNode->element = value;
	pNode->next = *pList;
	*pList = pNode;
	return 1;
}
//向链表尾部插入元素value
int InsertTrail(Node **pList, int value)
{
	if(NULL == *pList)
	{
		return InsertHead(pList, value);
	}
	Node *pInsert = (Node *)malloc(sizeof(Node));
	if(NULL == pInsert)
	{
		printf("内存分配失败.\n");
		return 0;
	}
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = value;
	pInsert->next = NULL;

	Node *pTmp;
	Node *pHead;
	pHead = *pList;
	pTmp = pHead;
	while(pHead->next)
	{
		pHead = pHead->next;
	}
	pHead->next = pInsert;
	*pList = pTmp;
	return 1;
}
//向链表中第pos个结点位置插入元素value,成功返回1， 失败返回0
int InsertNodeWithPos(Node **pList, int pos, int value)
{
	Node *pHead = NULL;
	pHead = *pList;
	if(NULL == pHead)
	{
		printf("链表为空.\n");
		exit(1);
	}
	Node *pNode = pHead;
	int size = SizeList(pHead);
	if(0 > pos || pos > size - 1)
	{
		printf("pos(%d)不合法\n", pos);
		exit(1);
	}
	if(0 == pos)
	{
		return InsertHead(pList ,value);
	}
	else if(size - 1 == pos)
	{
		return InsertTrail(pList, value);
	}
	int index = 0;
	while(pHead)
	{
		index++;
		if(pos - 1 == index)
			break;
		pHead = pHead->next;
	}
	if(index < pos - 1)
	{
		printf("pos(%d) 不合法.\n", pos);
		exit(1);
	}
	else
	{
		Node *pInsertNode = (Node *)malloc(sizeof(Node));
		if(NULL == pInsertNode)
		{
			printf("内存分配失败.\n");
			exit(1);
		}
		memset(pInsertNode, 0, sizeof(Node));
		pInsertNode->element = value;
		pInsertNode->next = pHead->next;
		pHead->next = pInsertNode;
		*pList = pNode;
	}


	return 1;
}
//向有序链表中插入元素value结点，使得插入后仍然有序
void InsertNodeWithSortedList(Node **pList, int value)
{
	
}
//从链表中删除头结点,并返回该结点的值，若删除失败择停止程序运行
int RemoveHead(Node **pList)
{
	Node *pHead;
	Node *pNode;

	pHead = *pList;
	if(NULL == pHead)
	{
		printf("链表为空\n");
		return 0;
	}
	pNode = pHead->next;
	free(pHead);
	pHead = pNode;
	*pList = pHead;
	return 0;
}
//从链表中删除尾结点,并返回该结点的值，若删除失败择停止程序运行
int RemoveTrail(Node **pList)
{
	Node *pHead = *pList;
	if(NULL == pHead)
	{
		printf("链表为空.\n");
		exit(1);
	}
	int size = SizeList(pHead);
	int pos = 0;
	Node *pNode = pHead;
	while(pHead)
	{
		pos++;
		if(pos == size - 1)
			break;
		pHead = pHead->next;
	}
	free(pHead->next);
	pHead->next = NULL;
	*pList = pNode;
	return 0;
}
//从链表中删除第pos个结点,并返回该结点的值，若删除失败择停止程序运行
int RemovePosNode(Node *pList, int pos)
{
	Node *pHead = pList;
	if(NULL == pHead)
	{
		printf("链表为空");
		exit(1);
	}
	int size = SizeList(pList);
	if(0 > pos || (size - 1) < pos)
	{
		printf("pos(%d)不合法.\n", pos);
		exit(1);
	}

	int index = 0;
	while(pHead)
	{
		if((pos - 1) == ++index)
			break;
		pHead = pHead->next;
	}
	if(index > size - 1)
	{
		exit(1);
	}
	Node *pNode = pHead->next->next;
	free(pHead->next);
	pHead->next = pNode;
	return 0;
}
//从链表中删除值为value的第一个结点,成功返回1， 失败返回0
int RemoveNodeWithValue(Node **pList, int value)
{
	Node *pHead;
	pHead = *pList;
	if(NULL == pHead)
	{
		printf("链表为空.\n");
		exit(1);
	}
	if(pHead->element == value)
	{
		return RemoveHead(pList);
	}
	Node *pTmp = pHead;
	Node *pNode = NULL;
	int size = SizeList(pHead);
	int element = GetElement(pHead, size - 1);
	int index = 0;
	while(pHead)
	{
		index++;
		if(pHead->element == value)
			break;
		pNode = pHead;
		pHead = pHead->next;
	}
	if(index == size && element == value)
	{
		return RemoveTrail(pList);
	}
	if(pNode->element == value)
	{
		Node *pNext = pHead->next;
		free(pHead);
		pNode->next = pNext;
		*pList = pTmp;
	}

	return 0;
}
//交换2个元素的位置
void SwapNode(Node **pList, int firstValue, int secondValue)
{

}
void SwapNodeWithPos(Node **pList, int firstPos, int secondPos)
{
	
}
//将线性表进行快速排序
void QuickSortList(Node **pList)
{

}
//链表倒序
void ReverseList(Node **pList)
{
	Node *pHead = NULL;
	Node *pNode = NULL;
	Node *pNext = NULL;
	
	pHead = *pList;
	if(NULL == pHead)
	{
		printf("链表为空.\n");
		exit(1);
	}
	while(pHead)
	{
		pNext = pHead->next;
		pHead->next = pNode;
		pNode = pHead;
		pHead = pNext;
	}
	*pList = pNode;
}
void ListOperation()
{
	Node *pList;
	InitList(&pList);
	pList = CreateList(pList);
	PrintList(pList);
	SizeList(pList);
	
	//第3个元素
	int value = GetElement(pList, 3);
	printf("第3个元素为:%d\n", value);

	GetElementAddress(pList, 10);
	ModifyElement(pList, 3, 2013);
	PrintList(pList);

	InsertHead(&pList, 101);
	PrintList(pList);

	InsertTrail(&pList, 202);
	PrintList(pList);

	RemoveHead(&pList);
	PrintList(pList);

	RemoveTrail(&pList);
	PrintList(pList);

	RemovePosNode(pList, 3);
	PrintList(pList);

	RemoveNodeWithValue(&pList, 4);
	PrintList(pList);

	InsertNodeWithPos(&pList, 3, 4444);
	PrintList(pList);

	ReverseList(&pList);
	PrintList(pList);
}
int main(int argc, const char **argv)
{
	ListOperation();
	return 0;
}
