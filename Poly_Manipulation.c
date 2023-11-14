#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    //If no node in list or exponent is greater than first node exponent
    if(head==NULL || ex > head->expo)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while(temp->link!=NULL && temp->link->expo >= ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }

    return head;
}

struct node *create(struct node *head)
{
    int n, i;
    float coeff;
    int expo;

    printf("Enter no. of terms: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter Coefficient for term %d: ", i+1);
        scanf("%f", &coeff);

        printf("Enter exponent for term %d: ", (i+1));
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

void display(struct node *head)
{
    if(head==NULL)
        printf("\nNo polynomial exists!");
    else
    {
        struct node *temp = head;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if(temp!=NULL)
                printf(" + ");
            else   
                printf("\n");
        }
    }
}

void polyAdd(struct node* head1, struct node *head2)
{
    struct node *ptr1=head1, *ptr2 = head2, *head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr2->expo>ptr1->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2!=NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("\nAdded polynomial: ");
    display(head3);
}

void polyMult(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1, *ptr2 = head2, *head3=NULL;
    if(head1==NULL || head2==NULL)
    {
        printf("\nZero Polynomial");
        return;
    }
    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
            head3 = insert(head3, ptr1->coeff*ptr2->coeff, ptr1->expo+ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    display(head3);
}

int main()
{
    struct node *head1=NULL, *head2=NULL;
    printf("Enter the first polynomial:\n");
    head1 = create(head1);
    printf("Enter the second polynomial:\n");
    head2 = create(head2);
    int ch=0;
    do
    {
        printf("\n-------------------------------------\n");
        printf("\n1. To add the two polynomials");
        printf("\n2. To multiply the two polynomials");
        printf("\n3. To exit the program.");
        printf("\nMake your choice[1-3]:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            polyAdd(head1, head2);
            break;

            case 2:
            polyMult(head1, head2);
            break;

            case 3:
            printf("\nThank you for using the program!");
            break;

            default:
            printf("\nInvalid Input!");
        }
    }while(ch!=3);
}