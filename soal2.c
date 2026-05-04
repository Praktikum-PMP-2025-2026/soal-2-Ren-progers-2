#include <stdio.h>
#include <stdlib.h>
struct smth {
    int n;
    struct smth* next;
};
int main (){
    int N, M;
    scanf ("%d", &N);
    struct smth* head1 = (struct smth*) malloc (sizeof (struct smth));
    struct smth* head2 = (struct smth*) malloc (sizeof (struct smth));
    head1 = NULL, head2 = NULL;
    for (int i = 0; i < N; i++){
        struct smth* temp = (struct smth*) malloc (sizeof (struct smth));
        scanf ("%d", &temp->n);
        if (head1 == NULL){
            head1 = temp;
            head1->next = NULL;
        }
        else {
            struct smth *check = head1; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
    scanf ("%d", &M);
    for (int i = 0; i < M; i++){
        struct smth* temp = (struct smth*) malloc (sizeof (struct smth));
        scanf ("%d", &temp->n);
        if (head2 == NULL){
            head2 = temp;
            head2->next = NULL;
        }
        else {
            struct smth *check = head2; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
    struct smth* mgd1 = head1;
    struct smth* mgd2 = head2;
    struct smth* head3 = (struct smth*) malloc (sizeof (struct smth));
    head3 = NULL;
    while (mgd1 != NULL && mgd2 != NULL){
        struct smth* temp = (struct smth*) malloc (sizeof (struct smth));
        if (mgd1->n <= mgd2->n){
            temp->n = mgd1->n;
            mgd1 = mgd1->next;
        }
        else if (mgd2->n <= mgd1->n){
            temp->n = mgd2->n;
            mgd2 = mgd2->next;
        }
        if (head3 == NULL){
            head3 = temp;
            head3->next = NULL;
        }
        else {
            struct smth *check = head3; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
    }
    while (mgd2 == NULL && mgd1 != NULL){
        struct smth* temp = (struct smth*) malloc (sizeof (struct smth));
        temp->n = mgd1->n;
        struct smth *check = head3; //Structure code dari TP
        if (head3 == NULL){
            head3 = temp;
            head3->next = NULL;
        }
        else {
            struct smth *check = head3; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
        mgd1 = mgd1->next;
    }
    while (mgd1 == NULL && mgd2 != NULL){
        struct smth* temp = (struct smth*) malloc (sizeof (struct smth));
        temp->n = mgd2->n;
        struct smth *check = head3; //Structure code dari TP
        if (head3 == NULL){
            head3 = temp;
            head3->next = NULL;
        }
        else {
            struct smth *check = head3; //Structure code dari TP
                while (check->next != NULL){
                    check = check->next;
                }
                check->next = temp;
                temp->next = NULL;
            }
        mgd2 = mgd2->next;
    }
    struct smth* print = head3;
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
    return 0;
}
