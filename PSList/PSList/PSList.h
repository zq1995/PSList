#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
typedef int DataType;
struct SListNode
{
	DataType data;
	struct SListNode* pNext;
};
class PSList
{public:
     PSList()
		:pHead(NULL)
	{}
	void DestroyPSList()
	{
		SListNode *cur = pHead;
		while (cur)
		{
			SListNode *temp = cur;
			cur = cur->pNext;
			free(temp);
		}
		pHead = NULL;
	}
	SListNode *BuyNode(DataType data)
	{
		SListNode *temp = (SListNode*)malloc(sizeof(struct SListNode));
		assert(temp);
		temp->data = data;
		temp->pNext = NULL;
		return temp;
	}
	void PushBack(DataType data)
	{
		SListNode* tail = pHead;

		//空和非空
		if (pHead == NULL)
		{
			pHead = BuyNode(data);
		}
		else
		{
			while (tail->pNext != NULL)
			{
				tail = tail->pNext;
			}
			tail->pNext = BuyNode(data);
		}
	}
	void Print()
	{
		SListNode *pNode = pHead;
		while (pNode != NULL)
		{
			printf("%d->", pNode->data);
			pNode = pNode->pNext;
		}

		printf("NULL\n");
	}
	void PopBack()
	{
		//空 一个节点 多个节点
		SListNode* pNode = pHead;
		if (pHead == NULL)
		{
			printf("it is empty");
			return;
		}
		else if (pNode->pNext == NULL)
		{
			free(pNode);
			pHead = NULL;
		}
		else
		{
			SListNode *tail = pHead;
			SListNode *prevtail = NULL;
			while (tail->pNext)
			{
				prevtail = tail;
				tail = tail->pNext;
			}
			prevtail->pNext = NULL;
			free(tail);

		}
	}
	void PushFront(DataType data)
	{
		assert(pHead);
		if (NULL == pHead)
		{
			pHead = BuyNode(data);
		}
		else
		{
			SListNode* pNode = BuyNode(data);
			pNode->pNext = pHead;
			pHead = pNode;
		}
	}
	void PopFront()
	{
		assert(NULL != pHead);
		if (NULL == pHead)
		{
			return;
		}
		else
		{
			SListNode *pNode = pHead;
			pHead = pNode->pNext;
			free(pNode);
		}
	}
	SListNode* Find(DataType data)
	{
		SListNode* pNode = pHead;
		while (pNode)
		{
			if (pNode->data == data)
			{
				return pNode;
			}
			pNode = pNode->pNext;
		}
		return NULL;
	}
	void Erase(SListNode *pos)
	{
		assert(NULL != pHead);
		assert(NULL != pos);
		if (pos == pHead)
		{
			pHead = pos->pNext;
			free(pos);
		}
		else
		{
			SListNode *cur = pHead;
			while (cur)
			{
				if (cur->pNext == pos)
				{
					cur->pNext = pos->pNext;
					free(pos);
					break;
				}

				cur = cur->pNext;
			}
		}
	}
	void Insert( SListNode* pos, DataType data)
	{
		assert(pos);
		assert(pHead);
		if (NULL == pHead)
		{
			return;
		}

		SListNode* pNode = BuyNode(data);
		if (pNode != NULL)
		{
			pNode->pNext = pos->pNext;
			pos->pNext = pNode;
		}
	}
private:
	SListNode*pHead;
};
void Test()
{
	PSList l;
	l.PushBack(7);
	l.PushBack(6);
	l.PushBack(5);
	l.PushBack(4);
	l.PushBack(3);
	l.PushBack(2);
	l.PushBack(1);
    l.PopBack();
	l.PushFront(8);
	cout<<(l.Find(7))->data<<endl;
	l.Erase(l.Find(6));
	l.Insert(l.Find(7), 14);
	l.Print();


}