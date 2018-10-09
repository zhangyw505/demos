#include <stddef.h>
#include <stdio.h>

// ����ڵ����ݽṹ
struct Node
{
	Node(int value){
		this->value = value;
		next = NULL;
	}
	int value;
	Node *next;
};
// ����ͷ
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


// ͨ������ָ��ɾ����������Ԫ��
void deleteAll(struct Node **head)
{
	struct Node **cur = head;
	
	while(*cur) // ��curָ���ָ�벻ΪNULL
	{
		struct Node *entry = (*cur);
		*cur = entry->next;
		delete entry;
	}
}

// ��ת����
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

// ɾ������ĳ��ֵ�Ľڵ�
void deleteValue(struct Node **head, int value)
{
	struct Node **cur = head;
	while(*cur)
	{
		if((*cur)->value == value)
		{
			struct Node *entry = *cur;
			//�ı�curָ��ָ���ֵ
			*cur = entry->next;
			delete entry;
			return;
		}
		//curָ���µ�ָ��
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

// �ڵ�i��λ�ò���ڵ㣬ֵΪvalue
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

//�ϲ�������������
struct Node* mergeList(struct Node* list1, struct Node *list2)
{
	//�Ტ�������ͷ��ָ��
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

// ɾ����������n������
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
	//ɾ����������
	//deleteAll(&listHead);

	//��ת����
	//reverse(&listHead);

	//ɾ��ĳ��ֵ�Ľڵ�
	//deleteValue(&listHead, 3);
	
	//ɾ�������n���ڵ�
	//deleteAt(&listHead, 5);

	//�������n��λ�ò���ڵ�
	//insertAt(&listHead, 4, 99);

	//�ϲ�������������
	//listHead = mergeList(list1, list2);

	//ɾ����������n���ڵ�(1�����һ��)
	rDeleteAt(&listHead, 6);

	//��ӡ��������
	printList(listHead);

	return 0;
}