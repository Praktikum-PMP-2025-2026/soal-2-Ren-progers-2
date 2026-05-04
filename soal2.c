#include <stdio.h>
#include <stdlib.h>
struct node {
    int n;
    struct node* next;
};
void input1 (struct node **head1, int N){
    for (int i = 0; i < N; i++){
        struct node* temp = (struct node*) malloc (sizeof (struct node));
        scanf ("%d", &temp->n);
        if (*head1 == NULL){
            *head1 = temp;
            (*head1)->next = NULL;
        }
        else {
            struct node *check = *head1; //Structure code dari TP prajurit
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
}
void input2 (struct node **head2, int M){
    for (int i = 0; i < M; i++){
        struct node* temp = (struct node*) malloc (sizeof (struct node));
        scanf ("%d", &temp->n);
        if (*head2 == NULL){
            *head2 = temp;
            (*head2)->next = NULL;
        }
        else {
            struct node *check = *head2; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
}
void merged1 (struct node **mgd1, struct node **mgd2, struct node **head3){
    while (*mgd1 != NULL && *mgd2 != NULL){
        struct node* temp = (struct node*) malloc (sizeof (struct node));
        if ((*mgd1)->n <= (*mgd2)->n){
            temp->n = (*mgd1)->n;
            *mgd1 = (*mgd1)->next;
        }
        else if ((*mgd2)->n <= (*mgd1)->n){
            temp->n = (*mgd2)->n;
            *mgd2 = (*mgd2)->next;
        }
        if (*head3 == NULL){
            *head3 = temp;
            (*head3)->next = NULL;
        }
        else {
            struct node *check = *head3; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
}
void merged2 (struct node **mgd1, struct node **head3){
    struct node* temp = (struct node*) malloc (sizeof (struct node));
        temp->n = (*mgd1)->n;
        struct node *check = *head3; //Structure code dari TP
        if (*head3 == NULL){
            *head3 = temp;
            (*head3)->next = NULL;
        }
        else {
            struct node *check = *head3; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
        *mgd1 = (*mgd1)->next;
}
void print (struct node *head3){
    struct node* print = head3;
    if (print == NULL){
        printf ("MERGED EMPTY\n");
    }
    else {
        printf ("MERGED ");
        while (print != NULL){
            if (print->next == NULL){
                printf ("%d\n", print->n);
            }
            else {
                printf ("%d ", print->n);
            }
            print = print->next;
        }
    }
}
int main (){
    int N, M;
    scanf ("%d", &N);
    struct node* head1 = (struct node*) malloc (sizeof (struct node));
    struct node* head2 = (struct node*) malloc (sizeof (struct node));
    head1 = NULL, head2 = NULL;
    input1 (&head1, N);
    scanf ("%d", &M);
    input2 (&head2, M);
    struct node* mgd1 = head1;
    struct node* mgd2 = head2;
    struct node* head3 = (struct node*) malloc (sizeof (struct node));
    head3 = NULL;
    merged1 (&mgd1, &mgd2, &head3);
    while (mgd2 == NULL && mgd1 != NULL){
        merged2 (&mgd1,&head3);
    }
    while (mgd1 == NULL && mgd2 != NULL){
        merged2 (&mgd2,&head3);
    }
    print (head3);
    return 0;
}
