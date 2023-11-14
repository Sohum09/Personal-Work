#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev; // llink -> prev
    struct node *next; // rlink -> next
} *start = 0, *end = 0;

void BInsert()
{
    struct node *nnode;
    int num;
    scanf("%d", &num);
    nnode = malloc(sizeof(struct node));
    nnode->data = num;
    nnode->prev = 0;
    nnode->next = 0;
    if (start == 0)
        start = nnode;
    else
    {
        nnode->next = start;
        start->prev = nnode;
        start = nnode;
    }
}

void EInsert()
{
    struct node *nnode;
    int num;
    scanf("%d", &num);
    nnode = malloc(sizeof(struct node));
    nnode->data = num;
    if (start == 0)
    {
        nnode->prev = 0;
        nnode->next = 0;
        start = nnode;
        end = nnode;
    }
    else
    {
        end->next = nnode;
        nnode->prev = end;
        nnode->next = 0;
        end = nnode;
    }
}

void PInsert()
{
    struct node *nnode, *temp;
    int num, pos, i;
    scanf("%d %d", &num, &pos);
    temp = start;
    if (pos == 1)
        BInsert();
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == 0)
                printf("List has less no. of elements. ");
        }
        nnode = malloc(sizeof(struct node));
        nnode->data = num;
        nnode->next = temp->next;
        nnode->prev = temp;
        temp->next = nnode;
        nnode->next->prev = nnode;
    }
}

void Display()
{
    struct node *temp = start;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void Delete()
{
    struct node *old, *temp;
    int num;
    scanf("%d", &num);
    temp = start;
    old = start;
    while (temp != 0)
    {
        if (temp->data == num)
        {
            if (temp == start)
            {
                start = start->next;
                start->prev = 0;
            }
            else
            {
                old->next = temp->next;
                temp->next->prev = old;
                printf("Deleted data: %d", temp->data);
                free(temp);
            }
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
}

void BDelete()
{
    struct node *ptr;
    if (start == 0)
        printf("\nUnderflow!");
    else if (start->next == 0)
    {
        start = 0;
        free(start);
    }
    else
    {
        ptr = start;
        start = start->next;
        start->prev = 0;
        free(ptr);
    }
}

void EDelete()
{
    struct node *ptr;
    if (start == 0)
    {
        printf("\nUnderflow!");
    }
    else if (start->next == 0)
    {
        start = 0;
        free(start);
    }
    else
    {
        ptr = start;
        while (ptr->next != 0)
            ptr = ptr->next;
        ptr->prev->next = 0;
        free(ptr);
    }
}

void PDelete()
{
    struct node *temp;
    temp = start;
    int pos, ctr = 1;
    scanf("%d", &pos);
    if (start == 0)
        printf("\nUnderflow!");
    else
    {
        if (pos == 1)
            BDelete();
        else
        {
            while (ctr < pos)
            {
                temp = temp->next;
                ctr++;
            }
            if(temp->next==0)
            {
                end = temp->prev;
                end->next = 0;
                free(temp);
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
        }
    }
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  


int main()
{
    int ch = 0;
    do
    {
        printf("\n------------------------------------------");
        printf("\n1. To perform beginning insertion");
        printf("\n2. To perform end insertion");
        printf("\n3. To perform position insertion");
        printf("\n4. To perform beginning deletion");
        printf("\n5. To perform end deletion");
        printf("\n6. To perform position deletion");
        printf("\n7. To perform search");
        printf("\n8. To display the linked list");
        printf("\n9. To end the program");
        printf("\nEnter choice [1-9]: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            BInsert();
            break;

        case 2:
            EInsert();
            break;

        case 3:
            PInsert();
            break;

        case 4:
            BDelete();
            break;

        case 5:
            EDelete();
            break;

        case 6:
            PDelete();
            break;

        case 7: 
            search();
            break; 
            
        case 8:
            Display();
            break;

        case 9:
            printf("\nThank You for using our program!\n");
            break;

        default:
            printf("\nInvalid Input!\n");
        }
    } while (ch != 9);
}
