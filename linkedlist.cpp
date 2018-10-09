#include <stddef.h>
#include <stdio.h>

// 链表节点数据结构
struct Node
{
	Node(int value){
		this->value = value;
		next = NULL;
	}
	int value;
	Node *next;
};
// 链表头
static struct Node *listHead = NULL;



void printList(struct Node *head)
{
	struct Node *cur = head;
	while(cur)
	{
		printf("%d, ", cur->value);
		cur = cur->next;
	}
}


// 通过二级指针删除链表所有元素
void deleteAll(struct Node **head)
{
	struct Node **cur = head;
	
	while(*cur) // 当cur指向的指针不为NULL
	{
		struct Node *entry = (*cur);
		*cur = entry->next;
		delete entry;
	}
}

// 翻转链表
void reverse(struct Node **head)
{
	struct Node *pre = NULL;
	struct Node *next = NULL;
	struct Node *cur = *head;
	
	while(cur)
	{
		next = cur->next;
		cur->next  = pre;
		pre = cur;
		cur = next;
	}

	*head = pre;
}

// 删除等于某个值的节点
void deleteValue(struct Node **head, int value)
{
	struct Node **cur = head;
	while(*cur)
	{
		if((*cur)->value == value)
		{
			struct Node *entry = *cur;
			//改变cur指向指针的值
			*cur = entry->next;
			delete entry;
			return;
		}
		//cur指向新的指针
		cur = &((*cur)->next);
	}
}

void deleteAt(struct Node **head, int n)
{
	struct Node **cur = head;
	while(*cur)
	{
		if(n-- == 0)
		{
			struct Node *entry = *cur;
			*cur = entry->next;
			delete entry;
			return;
		}
		cur = &((*cur)->next);
	}
}

// 在第i个位置插入节点，值为value
void insertAt(struct Node **head, int n, int value)
{
	struct Node **cur = head;
	int i = 0;
	
	do{
		if(i == n)
		{
			struct Node *newNode = new Node(value);
			newNode->next = (*cur);
			(*cur) = newNode;
			return;
		}
		cur = &((*cur)->next);
		i++;
	}while(*cur);

	if (i == n)
	{
		struct Node *newNode = new Node(value);
		newNode->next = (*cur);
		(*cur) = newNode;
		return;
	}
}

//合并两个有序链表
struct Node* mergeList(struct Node* list1, struct Node *list2)
{
	//会并后链表的头部指针
	struct Node *newList = NULL;

	struct Node **cur = &newList;

	while(1)
	{
		if(list1 == NULL){
			(*cur) = list2;
			return newList;
		}
		if(list2 == NULL){
			(*cur) = list1;
			return newList;
		}
		
		if(list1->value <= list2->value)
		{
			(*cur) = list1;
			list1 = list1->next;
		}
		else
		{
			(*cur) = list2;
			list2 = list2->next;
		}
		cur = &((*cur)->next);
	}
}

// 删除链表倒数第n个链表
void rDeleteAt(struct Node **head, int n)
{
	struct Node **cur = head;
	struct Node *fast = *head;
	while(n-- > 0)
	{
		if(fast == NULL){
			return;
		}
		fast = fast->next;
	}

	while(1)
	{
		if(fast == NULL){
			struct Node *entry = (*cur);
			*cur = entry->next;
			delete entry;
			return;
		}
		fast = fast->next;
		cur = &((*cur)->next);
	}
}


int main(int argc, char **argv)
{
	listHead = new Node(1);
	listHead->next = new Node(2);
	listHead->next->next = new Node(3);
	listHead->next->next->next = new Node(4);
	listHead->next->next->next->next = new Node(5);
	listHead->next->next->next->next->next = NULL;

	struct Node *list1 = NULL;
	list1 = new Node(1);
	list1->next = new Node(3);
	list1->next->next = new Node(5);
	list1->next->next->next = new Node(7);
	list1->next->next->next->next = new Node(8);
	list1->next->next->next->next->next = NULL;


	struct Node *list2 = NULL;
	list2 = new Node(2);
	list2->next = new Node(4);
	list2->next->next = new Node(7);
	list2->next->next->next = new Node(9);
	list2->next->next->next->next = new Node(10);
	list2->next->next->next->next->next = NULL;
	//删除整个链表
	//deleteAll(&listHead);

	//翻转链表
	//reverse(&listHead);

	//删除某个值的节点
	//deleteValue(&listHead, 3);
	
	//删除链表第n个节点
	//deleteAt(&listHead, 5);

	//在链表第n个位置插入节点
	//insertAt(&listHead, 4, 99);

	//合并两个有序链表
	//listHead = mergeList(list1, list2);

	//删除链表倒数第n个节点(1是最后一个)
	rDeleteAt(&listHead, 6);

	//打印整个链表
	printList(listHead);

	return 0;
}