//
//  main.c
//  List001
//
//  Created by xujin on 1/4/16.
//  Copyright © 2016 xujin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>




typedef int elemType;

// 定义单链表结点类型
typedef struct Node
{
    elemType element;
    struct Node *next;
}Node;

// 冒泡排序
void bubbleSortList(Node *head);




//1：初始化线性表，即置单链表的表头指针为空
void initList(Node ** pNode)
{
    *pNode = NULL;

}

// 2： 创建线性表，此函数输入负数终止读取数据
Node *createList(Node *pHead)
{
    
    
    
    Node *p1, *p2;
    p1 = p2 = (Node *)malloc(sizeof(Node));
    if (p1 == NULL || p2 == NULL)
    {
        printf("内存分配失败.\n");
        exit(0);
    }
    memset(p1, 0, sizeof(Node));
    
    int num = 10;
    int total = num + 1;
    int data[total];
    srand( (unsigned int)time(0) );
    for (int i = 0; i < num; i++)
    {
        int value = rand()%100;
        if (value <= 0)
        {
            value = 1;
        }
        data[i] = value;
    }
    data[num] = 0;
    
    
    // 输入新结点
    p1->element = data[0];
    
    // 新节点的指针置为空
    p1->next = NULL;
    
    for (int i = 1; i < total; i++)
    {
        if (p1->element > 0)
        {
            if (pHead == NULL)
            {
                pHead = p1;
            }
            else
            {
                p2->next = p1;
            }
            
            p2 = p1;
            
            p1 = (Node *)malloc(sizeof(Node));
            if (p1 == NULL)
            {
                printf("内存分配失败.\n");
                exit(0);
            }
            memset(p1, 0, sizeof(Node));
            
            
            p1->element = data[i];
            p1->next = NULL;
        }
    }
    
    // 返回链表的头指针
    return pHead;
}
// 3 打印链表，链表的遍历
void printList(Node *pHead)
{
    if (NULL == pHead)
    {
        printf("printList函数执行，链表为空\n");
    }
    else
    {
        while (NULL != pHead)
        {
            printf("%d\t", pHead->element);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

// 4 清除线性表L中所有元素，即释放单链表L中所有的结点，使之成为一个空链表
void clearList(Node *pHead)
{
    Node *pNext;
    if (pHead == NULL)
    {
        return;
    }
    while (pHead != NULL)
    {
        pNext = pHead->next;
        free(pHead);
        pHead = NULL;
        pHead = pNext;
    }
}

// 5 返回单链表的长度
int sizeList(Node *pHead)
{
    int size = 0;
    
    while (pHead != NULL)
    {
        size++;
        pHead = pHead->next;
    }
    return size;
}
// 6 检查链表是否为空，空返回1 ，否则，返回0
int isEmptyList(Node *pHead)
{
    if (pHead == NULL)
    {
        return 1;
    }
    return 0;
}

// 7 返回单链表中第pos个结点中的元素，若POS超出返回，则停止程序运行
elemType getElement(Node *pHead, int pos)
{
    int i = 0;
    if (pos < 1)
    {
        printf("getElement函数执行，pos值非法\n");
        return 0;
    }
    if(pHead == NULL)
    {
        printf("getElement函数执行，链表为空\n");
        return 0;
    }
    while (pHead != NULL)
    {
        ++i;
        if (i == pos)
        {
            break;
        }
        
        pHead = pHead->next;
    }
    
    if (i < pos)
    {
        printf("getElement函数执行，pos值超出链表长度\n");
        return 0;
    }
    return pHead->element;
}

// 8 从单链表中查找具有给定值x的第一个元素，成功返回该结点地址，否则返回NULL
elemType *getElemAddr(Node *pHead, elemType x)
{
    if (NULL == pHead)
    {
        printf("getElemAddr函数执行，链表为空\n");
        return NULL;
    }
    if (x <= 0)
    {
        printf("getElemAddr函数执行，给定值X不合法\n");
        return NULL;
    }
    
    
    while (pHead->element != x && NULL != pHead->next)
    {
        pHead = pHead->next;
    }
    if ((pHead->element != x)  && (NULL != pHead))
    {
        printf("getElemAddr函数执行，在链表中未找到x值\n");
        return NULL;
    }
    
    if (pHead->element == x)
    {
        printf("getElemAddr函数执行，元素 %d 的地址为 0x%p\n",x,&(pHead->element));
        return &(pHead->element);
    }
    
    return NULL;
}

// 9 把单链表中第pos个结点的值修改为X的值，成功返回1，否则返回0

int modifyElem(Node *pNode, int pos, elemType x)
{
    Node *pHead;
    pHead = pNode;
    int i = 0;
    if (NULL == pHead)
    {
        printf("modifyElem函数执行，链表为空\n");
    }
    if (pos < 1)
    {
        printf("modifyElem函数执行，pos值非法\n");
        return 0;
    }
    
    while (pHead != NULL)
    {
        ++i;
        if (i == pos)
        {
            break;
        }
        
        // 移动到下一个结点
        pHead = pHead->next;
    }
    if(i < pos)
    {
        printf("modifyElem函数执行，pos值超出链表长度\n");
        return 0;
    }
    
    pNode = pHead;
    pNode->element = x;
    
    return 1;
}
// 10 向单链表头插入一个元素
int insertHeadList(Node **pNode, elemType insertElem)
{
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = insertElem;
    pInsert->next = *pNode;
    *pNode = pInsert;
    
    return 1;
}

// 11 向单链表的末尾添加一个元素
int insertLastList(Node **pNode, elemType insertElem)
{
    Node *pInsert;
    Node *pHead;
    Node *pTmp;
    
    pHead = *pNode;
    pTmp = pHead;
    
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = insertElem;
    
    while (pHead->next != NULL)
    {
        pHead = pHead->next;
    }
    
    pHead->next = pInsert;
    *pNode = pTmp;
    
    return 1;
}

/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
int insertPosElem(Node **pHead, int pos, elemType insertElem)
{
    Node *pNode = *pHead;
    int size = sizeList(pNode);
    if (size < pos)
    {
        printf("insetPosElem函数执行，pos 不合法。\n");
        return 0;
    }
    else if (size <= 0)
    {
        insertHeadList(&pNode, insertElem);
        return 1;
    }
    else if (size == pos + 1)
    {
        insertLastList(&pNode, insertElem);
        return 1;
    }
    
    
    Node *pInsertNode = (Node *)malloc(sizeof(Node));
    memset(pInsertNode, 0, sizeof(Node));
    pInsertNode->element = insertElem;
    pInsertNode->next = NULL;
    
    int i = 0;
    while (pNode != NULL)
    {
        i++;
        if (i == pos - 1)
        {
            Node *pNext = pNode->next;
            pNode->next = pInsertNode;
            pInsertNode->next = pNext;
            
            return 1;
        }
        pNode = pNode->next;
    }
    
    return 0;
}
void swap(int *left, int *right)
{
    int *tmp = left;
    left = right;
    right = tmp;
}
Node *getPartion(Node *pBegin, Node *pEnd)
{
    int key = pBegin->element;
    Node *p = pBegin;
    Node *q = p->next;
    
    while (q != pEnd)
    {
        if (q->element < key)
        {
            p = p->next;
            swap(&p->element, &q->element);
            
        }
        q = q->next;
    }
    swap(&p->element, &pBegin->element);
    return p;
}
// 链表快速排序：使用时只需调用QuickSort(pHead,NULL)即可！
void QuickSortList(Node *pBegin, Node *pEnd)
{
    if (pBegin != pEnd)
    {
        Node *partion = getPartion(pBegin, pEnd);
        QuickSortList(pBegin, partion);
        QuickSortList(partion->next, pEnd);
    }
}
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
void insertElemForSortedList(Node **pNode, elemType x)
{
    Node *pHead = *pNode;
    int size = sizeList(pHead);
    if (size <= 0)
    {
        insertHeadList(pNode, x);
    }
    else
    {
        // 链表进行排序
        bubbleSortList(pHead);
        printList(pHead);
        
        while (pHead != NULL)
        {
            
            if (pHead->element < x)
            {
                pHead = pHead->next;
            }
            else
            {
                Node *pInsertNode = (Node *)malloc(sizeof(Node));
                pInsertNode->element = pHead->element;
                pInsertNode->next = pHead->next;
                
                pHead->element = x;
                pHead->next = pInsertNode;
                
                break;
            }
        }
        
        
    }
}


/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
elemType removeHeadNode(Node **pHead)
{
    Node *pNode = *pHead;
    
    if (pNode == NULL)
    {
        return 0;
    }
    elemType nodeValue;
    if (pNode->next == NULL)
    {
        nodeValue = pNode->element;
        free(pNode);
        pNode = NULL;
        return nodeValue;
    }
   
    nodeValue = pNode->element;
    
    *pHead = pNode->next;
    free(pNode);
    pNode = NULL;
    
    return nodeValue;
}


/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
elemType removeTrailNode(Node **pHead)
{
    Node *pNode = *pHead;
    
    if (pNode == NULL)
    {
        return 0;
    }
    
    elemType nodeValue;
    if (pNode->next == NULL)
    {
        nodeValue = pNode->element;
        free(pNode);
        pNode = NULL;
        return nodeValue;
    }
    
    
    while (pNode->next->next != NULL)
    {
        pNode = pNode->next;
    }
    
    Node *pNext = pNode->next;
    nodeValue = pNext->element;
    free(pNext);
    pNode->next = NULL;
    return nodeValue;
}


/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
elemType removeNodeAtPos(Node **pHead, int pos)
{
    Node *pNode = *pHead;
    int size = sizeList(pNode);
    if (size >= pos)
    {
        
        if(pos == 1)
        {
            removeHeadNode(pHead);
            return pNode->element;
        }
        else if(pos == size)
        {
            removeTrailNode(pHead);
            return pNode->element;
        }
            
        
        int i = 0;
        Node *pNode = *pHead;
        while (pNode)
        {
            i++;
            if (i == pos - 1)
            {
                Node *pNext = pNode->next;
            
                pNode->next = pNext->next;
                
                free(pNext);
                pNext = NULL;
                return pNode->element;
            }
            pNode = pNode->next;
        }
    }
    return 0;
}

/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
int removeNodeWithValue(Node **pList, int value)
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
        return removeHeadNode(pList);
    }
    Node *pTmp = pHead;
    Node *pNode = NULL;
    int size = sizeList(pHead);
    int element = getElement(pHead, size - 1);
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
        return removeTrailNode(pList);
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


/* 18.交换2个元素的位置 : 交换两个节点的值 */
void swapListNodes(Node **pFirstNode, Node **pSecondNode)
{
    Node *pFirst = *pFirstNode;

    Node *pSecond = *pSecondNode;
    
    swap(&pFirst->element, &pSecond->element);
    
}

/* 19.将线性表进行快速排序 */

/* 20 单链表的转置,循环方法 */
Node *reverseByLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node *pre = NULL;
    Node *next = NULL;
    
    while (head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
Node *reverseByRecursion(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node *newHead = reverseByRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

/* 21 倒数第K个节点*/
Node *theKthNode(Node *head, int k)
{
    if (k < 0)
    {
        return NULL;
    }
    Node *slow, *fast;
    slow = fast = head;
    
    
    int i = k;
    
    for (; i > 0 && fast != NULL; i--)
    {
        fast = fast->next;
    }
    if (i > 0)
    {
        return NULL;
    }
    
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
/* 22 链表的中间节点
 *
 *  通过两个指针来完成。用两个指针从链表头节点开始，一个指针每次向后移动两步，一个每次移动一步，直到快指针移到到尾节点，那么慢指针即是所求。
 */
Node *theMiddleNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    Node *slow , *fast;
    slow = fast = head;
    
    //如果要求在链表长度为偶数的情况下，返回中间两个节点的第一个，可以用下面的循环条件
    //while(fast && fast->next != NULL && fast->next->next != NULL)
    
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


/* 23 判断单链表是否存在环
 *  通过两个指针，分别从链表的头节点出发，一个每次向后移动一步，另一个移动两步，两个指针移动速度不一样，如果存在环，那么两个指针一定会在环里相遇
 */

int hasCircle(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
}
/* 24 找到环的入口点
 *  按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和 p1 重合，确定了单向链表有环路了。接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当 p1 和 p2 再次相遇的时候，就是环路的入口了。
 *  为什么？：假定起点到环入口点的距离为 a，p1 和 p2 的相交点M与环入口点的距离为b，环路的周长为L，当 p1 和 p2 第一次相遇的时候，假定 p1 走了 n 步。那么有：
 *  p1走的路径： a+b ＝ n；
 *  p2走的路径： a+b+k*L = 2*n； p2 比 p1 多走了k圈环路，总路程是p1的2倍
 *  根据上述公式可以得到 k*L=a+b=n显然，如果从相遇点M开始，p1 再走 n 步的话，还可以再回到相遇点，同时p2从头开始走的话，经过n步，也会达到相遇点M。
 *  显然在这个步骤当中 p1 和 p2 只有前 a 步走的路径不同，所以当 p1 和 p2 再次重合的时候，必然是在链表的环路入口点上。
 **/
Node *findLoopPort(Node *head)
{
    //如果head为空，或者为单结点，则不存在环
    if(head == NULL || head->next == NULL) return NULL;
    
    Node *slow, *fast;
    slow = fast = head;
    
    // 先判断是否存在环
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    
    if (fast != slow)
    {
        return NULL;// 不存在环
    }
    
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
   
}


/* 25 判断两个链表是否相交
 *  “如果两个没有环的链表相交于某一节点，那么在这个节点之后的所有节点都是两个链表共有的”这个特点，
 *  我们可以知道，如果它们相交，则最后一个节点一定是共有的。而我们很容易能得到链表的最后一个节点，
 *  所以这成了我们简化解法的一个主要突破口。那么，我们只要判断两个链表的尾指针是否相等。相等，则链表相交；否则，链表不相交。
 *  所以，先遍历第一个链表，记住最后一个节点。然后遍历第二个链表，到最后一个节点时和第一个链表的最后一个节点做比较，
 *  如果相同，则相交，否则，不相交。这样我们就得到了一个时间复杂度，它为O((Length(h1) + Length(h2))，
 *  而且只用了一个额外的指针来存储最后一个节点。这个方法时间复杂度为线性O(N)，空间复杂度为O(1)
 */
int isIntersect(Node *h1, Node *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        return 0;
    }
    while (h1->next != NULL)
    {
        h1 = h1->next;
    }
    
    while (h2->next != NULL)
    {
        h2 = h2->next;
    }
    return h1 == h2;
}

/* 26 链表有环，如何判断相交
 *  分析：如果有环且两个链表相交，则两个链表都有共同一个环，即环上的任意一个节点都存在于两个链表上。
 *  因此，就可以判断一链表上俩指针相遇的那个节点，在不在另一条链表上。
 */

int hasCircleExt(Node *head, Node **circleNode)
{
    Node *slow,*fast;
    slow = fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            *circleNode = fast;
            return 1;
        }
    }
    
    return 0;
}
int isIntersectWithLoop(Node *h1, Node *h2)
{
    
    Node *circleNode1, *circleNode2;
    if (!hasCircleExt(h1, &circleNode1))
    {
        return 0;
    }
    if (!hasCircleExt(h2, &circleNode2))
    {
        return 0;
    }
    
    Node *temp = circleNode2->next;
    while (temp != circleNode2)
    {
        if (temp == circleNode1)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


/* 27 求两链表(无环)相交的第一个公共节点
 *  分析：采用对齐的思想。计算两个链表的长度 L1 , L2，分别用两个指针 p1 , p2 指向两个链表的头，
 *  然后将较长链表的 p1（假设为 p1）向后移动L2 - L1个节点，然后再同时向后移动p1 , p2，直到 p1 = p2。相遇的点就是相交的第一个节点。
 */

Node *findIntersectNode(Node *h1, Node *h2)
{
    int len1 = sizeList(h1);
    int len2 = sizeList(h2);
    int offset = abs(len1 - len2);
    
    // 对齐两个链表
    if (len1 > len2)
    {
        for (int i = 0; i < offset; i++)
        {
            h1 = h1->next;
        }
    }
    else
    {
        for (int i = 0; i < offset; i++)
        {
            h2 = h2->next;
        }
    }
    while (h1 != NULL)
    {
        if (h1 == h2)
        {
            return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    
    
    return NULL;
}

/* 28 冒泡排序 */
void bubbleSortList(Node *head)
{
    int len = sizeList(head);
    
    for (int i = 1; i < len; i++)
    {
        Node *p = head;
        for(int j = 0; j < len - i; j++, p = p->next)
        {
            if (p->element > p->next->element)
            {
                int tem = p->element;
                p->element = p->next->element;
                p->next->element = tem;
            }
        }
    }
}

/* 29 归并排序*/

void printNode(Node *node)
{
    printf("%d\n", node->element);
}
int main(int argc, const char * argv[])
{
    Node *pList = NULL;
    
    // 初始化链表
    initList(&pList);
    
    // 打印链表
    printList(pList);
    
    // 创建链表
    pList = createList(pList);
    printList(pList);
    
    printf("list size = %d\n", sizeList(pList));
    
    
    
    printf("pos(3) = %d\n", getElement(pList, 3));
    
//    getElemAddr(pList, 3);
//    
    modifyElem(pList, 3, 20);
//
    insertHeadList(&pList, 333);
    insertLastList(&pList, 888);
    
    insertPosElem(&pList, 4, 4444);
    printList(pList);
    insertElemForSortedList(&pList, 501);
//    pList = reverseByLoop(pList);
    pList = reverseByRecursion(pList);
    printNode(theKthNode(pList, 3));
    printNode(theMiddleNode(pList));
    removeHeadNode(&pList);
    removeTrailNode(&pList);
    removeNodeAtPos(&pList, 3);
    
    
    printList(pList);
    clearList(pList);
    
    return 0;
}
