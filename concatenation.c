#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de la liste chaînée
struct Node {
    int data;
    struct Node* next;
};

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        // Si la première liste est vide, la deuxième liste devient la première
        *head1 = head2;
        return;
    }

    struct Node* current = *head1;
    // Parcourir jusqu'à la fin de la première liste
    while (current->next != NULL) {
        current = current->next;
    }
    // Attacher la deuxième liste à la fin de la première
    current->next = head2;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Ajouter des éléments à la première liste
    push(&head1, 10);
    push(&head1, 20);
    push(&head1, 30);

    // Ajouter des éléments à la deuxième liste
    push(&head2, 40);
    push(&head2, 50);
    push(&head2, 60);

    printf("Liste 1: ");
    printList(head1);

    printf("Liste 2: ");
    printList(head2);

    // Concaténer les deux listes
    concatenate(&head1, head2);

    printf("Liste concaténée: ");
    printList(head1);

    return 0;
}
