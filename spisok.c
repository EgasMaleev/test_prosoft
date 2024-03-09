#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h> 

// Îïðåäåëåíèå ñòðóêòóðû äëÿ ýëåìåíòà ñïèñêà
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Ñòðóêòóðà äëÿ ïðåäñòàâëåíèÿ ñâÿçíîãî ñïèñêà
typedef struct {
    Node* head;
} LinkedList;

// Ôóíêöèÿ äëÿ èíèöèàëèçàöèè ïóñòîãî ñïèñêà
void initLinkedList(LinkedList* list) {
    list->head = NULL;
}

// Ôóíêöèÿ äëÿ äîáàâëåíèÿ íîâîãî ýëåìåíòà â êîíåö ñïèñêà
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

//äîáàâëåíèå óçëà ïîñëå óêàçàííîãî
void addelem(LinkedList* list, Node* ptr, void* infa)
{
    Node* temp, * p;
    temp = (Node*)malloc(sizeof(Node));
    p = ptr->next; // ñîõðàíåíèå óêàçàòåëÿ íà ñëåäóþùèé óçåë
    ptr->next = temp; // ïðåäûäóùèé óçåë óêàçûâàåò íà ñîçäàâàåìûé
    temp->data = infa; // ñîõðàíåíèå ïîëÿ äàííûõ äîáàâëÿåìîãî óçëà
    temp->next = p; // ñîçäàííûé óçåë óêàçûâàåò íà ñëåäóþùèé ýëåìåíò
}

void deletelem(Node* lst, LinkedList* list)
{
    Node* temp;
    temp = list->head;
    while (temp->next != lst) // ïðîñìàòðèâàåì ñïèñîê íà÷èíàÿ ñ êîðíÿ
    { // ïîêà íå íàéäåì óçåë, ïðåäøåñòâóþùèé lst
        temp = temp->next;
    }
    temp->next = lst->next; // ïåðåñòàâëÿåì óêàçàòåëü
    free(lst); // îñâîáîæäàåì ïàìÿòü óäàëÿåìîãî óçëà
}

void listprint(LinkedList* list)
{
    Node* p;
    p = list->head;
    while (p != NULL)
    {
        printf("%d ", p->data); // âûâîä çíà÷åíèÿ ýëåìåíòà p
        p = p->next; // ïåðåõîä ê ñëåäóþùåìó óçëó
    }
}

void swap(Node* lst1, Node* lst2, LinkedList* list)
{
    // Âîçâðàùàåò íîâûé êîðåíü ñïèñêà
    Node* prev1, * prev2, * next1, * next2;
    prev1 = list->head;
    prev2 = list->head;
    if (prev1 == lst1)
        prev1 = NULL;
    else
        while (prev1->next != lst1) // ïîèñê óçëà ïðåäøåñòâóþùåãî lst1
            prev1 = prev1->next;
    if (prev2 == lst2)
        prev2 = NULL;
    else
        while (prev2->next != lst2) // ïîèñê óçëà ïðåäøåñòâóþùåãî lst2
            prev2 = prev2->next;
    next1 = lst1->next;  // óçåë ñëåäóþùèé çà lst1
    next2 = lst2->next;  // óçåë ñëåäóþùèé çà lst2
    if (lst2 == next1)
    {                       // îáìåíèâàþòñÿ ñîñåäíèå óçëû
        lst2->next = lst1;
        lst1->next = next2;
        if (lst1 != list->head)
            prev1->next = lst2;
    }
    else
        if (lst1 == next2)
        {
            // îáìåíèâàþòñÿ ñîñåäíèå óçëû
            lst1->next = lst2;
            lst2->next = next1;
            if (lst2 != list->head)
                prev2->next = lst2;
        }
        else
        {
            // îáìåíèâàþòñÿ îòñòîÿùèå óçëû
            if (lst1 != list->head)
                prev1->next = lst2;
            lst2->next = next1;
            if (lst2 != list->head)
                prev2->next = lst1;
            lst1->next = next2;
        }
}

// Ïðèìåð èñïîëüçîâàíèÿ API:
int main() {
    // Èíèöèàëèçàöèÿ íîâîãî ñâÿçíîãî ñïèñêà
    LinkedList myList;
    initLinkedList(&myList);

    // Äîáàâëåíèå ýëåìåíòîâ ðàçíîãî òèïà â ñïèñîê
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

    swap(myList.head->next->next, myList.head->next->next->next, &myList);

    listprint(&myList);
    // Èñïîëüçîâàíèå ñïèñêà

    return 0;
}
