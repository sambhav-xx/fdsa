#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createLL(int data) {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    return head;
}

void insertAtBeg(struct node **head, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void insertAtEnd(struct node **head, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void printLL(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void add(struct node **head, struct node **head2, struct node **ans) {
    struct node *temp1 = *head;
    struct node *temp2 = *head2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int val1 = (temp1 != NULL) ? temp1->data : 0;
        int val2 = (temp2 != NULL) ? temp2->data : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        insertAtBeg(ans, digit);

        if (temp1 != NULL) temp1 = temp1->next;
        if (temp2 != NULL) temp2 = temp2->next;
    }
}

int main() {
    struct node *head = NULL;
    struct node *head2 = NULL;
    struct node *ans = NULL;

    printf("Enter the number of elements in the first list (m): ");
    int m;
    scanf("%d", &m);

    printf("Enter the number of elements in the second list (n): ");
    int n;
    scanf("%d", &n);

    printf("Enter elements for the first list:\n");
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Enter elements for the second list:\n");
    for (int j = 0; j < n; j++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    add(&head, &head2, &ans);
    printf("Resultant list after addition:\n");
    printLL(ans);

    return 0;
}