#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_type;

int search(node_type* head, int element) {
    node_type* ptr = head;
    int position = 1;

    while (ptr != NULL) {
        if (ptr->data == element)
            return position;

        ptr = ptr->next;
        position++;
    }

    return -1;
}

node_type* insertInMiddle(node_type* head, int element, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    node_type* new_node = (node_type*)malloc(sizeof(node_type));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = element;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    if (position == 1) {
        new_node->next = head;
        return new_node;
    }

    node_type* ptr = head;
    int ptrPosition = 1;

    while (ptr != NULL && ptrPosition < position - 1) {
        ptr = ptr->next;
        ptrPosition++;
    }

    if (ptr == NULL) {
        printf("Invalid position.\n");
        free(new_node);
        return head;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    return head;
}

node_type* insertAtHead(node_type* head, int element) {
    node_type* new_node = (node_type*)malloc(sizeof(node_type));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = element;
    new_node->next = head;
    return new_node;
}

node_type* insertAtEnd(node_type* head, int element) {
    node_type* new_node = (node_type*)malloc(sizeof(node_type));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = element;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    node_type* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = new_node;

    return head;
}

node_type* deleteFromMiddle(node_type* head, int element) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }

    node_type* current = head;
    node_type* previous = NULL;

    while (current != NULL && current->data != element) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return head;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    return head;
}

node_type* deleteFromHead(node_type* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }

    node_type* temp = head;
    head = head->next;
    free(temp);

    return head;
}

node_type* deleteFromEnd(node_type* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_type* current = head;
    node_type* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);

    return head;
}

void printLinkedList(node_type* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    node_type* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    node_type* head = NULL;

    // Creating the initial linked list
    head = insertAtHead(head, 23);
    head = insertAtEnd(head, 52);
    head = insertAtEnd(head, 19);
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 100);

    // Testing the methods
    printf("Original linked list: ");
    printLinkedList(head);
    
    int element, position;
    
    printf("Enter an element to search: ");
    scanf("%d", &element);
    int positionFound = search(head, element);

    if (positionFound != -1) {
        printf("Element found at position: %d\n", positionFound);
    } else {
        printf("%d\n",positionFound);
    }
    
    printf("Enter an element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    head = insertInMiddle(head, element, position);
    printf("After insertion (in the middle): ");
    printLinkedList(head);

  

    printf("Enter an element to insert at the head: ");
    scanf("%d", &element);
    head = insertAtHead(head, element);
    printf("After insertion (at the head): ");
    printLinkedList(head);
    
    printf("Enter an element to insert at the end: ");
    scanf("%d", &element);
    head = insertAtEnd(head, element);
    printf("After insertion (at the end): ");
    printLinkedList(head);

    printf("Enter an element to delete from the middle: ");
    scanf("%d", &element);
    head = deleteFromMiddle(head, element);
    printf("After deletion (from the middle): ");
    printLinkedList(head);

    printf("Deleting head element.\n");
    head = deleteFromHead(head);
    printf("After deletion (from the head): ");
    printLinkedList(head);

    printf("Deleting last element.\n");
    head = deleteFromEnd(head);
    printf("After deletion (from the end): ");
    printLinkedList(head);

    return 0;
}
