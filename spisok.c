#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h> 

// ����������� ��������� ��� �������� ������
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// ��������� ��� ������������� �������� ������
typedef struct {
    Node* head;
} LinkedList;

// ������� ��� ������������� ������� ������
void initLinkedList(LinkedList* list) {
    list->head = NULL;
}

// ������� ��� ���������� ������ �������� � ����� ������
void append(LinkedList* list, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//���������� ���� ����� ����������
void addelem(LinkedList* list, Node* ptr, void* infa)
{
    Node* temp, * p;
    temp = (Node*)malloc(sizeof(Node));
    p = ptr->next; // ���������� ��������� �� ��������� ����
    ptr->next = temp; // ���������� ���� ��������� �� �����������
    temp->data = infa; // ���������� ���� ������ ������������ ����
    temp->next = p; // ��������� ���� ��������� �� ��������� �������
}

void deletelem(Node* lst, LinkedList* list)
{
    Node* temp;
    temp = list->head;
    while (temp->next != lst) // ������������� ������ ������� � �����
    { // ���� �� ������ ����, �������������� lst
        temp = temp->next;
    }
    temp->next = lst->next; // ������������ ���������
    free(lst); // ����������� ������ ���������� ����
}

void listprint(LinkedList* list)
{
    Node* p;
    p = list->head;
    while (p != NULL)
    {
        printf("%d ", p->data); // ����� �������� �������� p
        p = p->next; // ������� � ���������� ����
    }
}

void swap(Node* lst1, Node* lst2, LinkedList* list)
{
    // ���������� ����� ������ ������
    Node* prev1, * prev2, * next1, * next2;
    prev1 = list->head;
    prev2 = list->head;
    if (prev1 == lst1)
        prev1 = NULL;
    else
        while (prev1->next != lst1) // ����� ���� ��������������� lst1
            prev1 = prev1->next;
    if (prev2 == lst2)
        prev2 = NULL;
    else
        while (prev2->next != lst2) // ����� ���� ��������������� lst2
            prev2 = prev2->next;
    next1 = lst1->next;  // ���� ��������� �� lst1
    next2 = lst2->next;  // ���� ��������� �� lst2
    if (lst2 == next1)
    {                       // ������������ �������� ����
        lst2->next = lst1;
        lst1->next = next2;
        if (lst1 != list->head)
            prev1->next = lst2;
    }
    else
        if (lst1 == next2)
        {
            // ������������ �������� ����
            lst1->next = lst2;
            lst2->next = next1;
            if (lst2 != list->head)
                prev2->next = lst2;
        }
        else
        {
            // ������������ ��������� ����
            if (lst1 != list->head)
                prev1->next = lst2;
            lst2->next = next1;
            if (lst2 != list->head)
                prev2->next = lst1;
            lst1->next = next2;
        }
}

// ������ ������������� API:
int main() {
    // ������������� ������ �������� ������
    LinkedList myList;
    initLinkedList(&myList);

    // ���������� ��������� ������� ���� � ������
    int intValue1 = 42;
    int intValue2 = 43;
    int intValue3 = 44;
    int intValue4 = 45;
    int intValue5 = 46;

    append(&myList, &intValue1);
    append(&myList, &intValue2);
    append(&myList, &intValue3);
    append(&myList, &intValue4);
    append(&myList, &intValue5);

    Node* del_node = myList.head->next;

    deletelem(del_node, &myList);

    swap(myList.head->next->next, myList.head->next->next, &myList);

    listprint(&myList);
    // ������������� ������

    return 0;
}