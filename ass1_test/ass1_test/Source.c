#include <stdio.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void print_queue_like(struct node* head) {
    struct node* curr = head;
    printf("Queue like printing : \n");
    while (curr->next) {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
}
void print_stack_like(struct node* head) {
    struct node* curr = head;
    printf("Stack like printing : \n");
    while (curr->next)
        curr = curr->next;
    while (curr != head) {
        printf("%d ->", curr->data);
        curr = curr->prev;
    }
    printf("%d", curr->data);
}

void print_max_min(struct node* head) {
    struct node* curr = head;
    int max = curr->data;
    int min = curr->data;
    if (curr->next)
        curr = curr->next;
    while (curr) {
        if (curr->data > max)
            max = curr->data;
        if (curr->data < min)
            min = curr->data;
        curr = curr->next;
    }
    printf("Max number is : %d \n", max);
    printf("Min number is : %d \n", min);
}

void print_sum_avg_count(struct node* head) {
    struct node* curr = head;
    int sum = 0, count = 0;
    float avg;
    while (curr) {
        sum += curr->data;
        count++;
        curr = curr->next;
    }
    avg = sum / count;
    printf("Sum is : %d \n", sum);
    printf("Avg is : %f \n", avg);
    printf("Count is : %d \n", count);

}

struct node* insert_node(int n, struct node* head) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    if (head == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else {
        struct node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
        temp->next = NULL;
    }
    return head;

}

int main() {
    struct node* head = NULL;
    int cond = 1;
    while (cond) {
        int n;
        printf("Enter the number : ");
        scanf_s("%d", &n);
        head = insert_node(n, head);
        printf("Want to insert more : 1.Yes 2.No : ");
        scanf_s("%d", &cond);
    }
    printf("\n");
    print_queue_like(head);
    printf("\n");
    print_stack_like(head);
    printf("\n");
    print_max_min(head);
    printf("\n");
    print_sum_avg_count(head);

    return 0;
}