#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *top=NULL;
struct Node *create(char ch)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ch;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;
    return temp;
}
void inorder(struct Node *top)
{
    if (top == NULL)
        return;
    else
    {
        inorder(top->left);
        printf("%c", top->data);
        inorder(top->right);
    }
}
void push(struct Node *x)
{
    if (top == NULL)
        top = x;
    else
    {
        x->next = top;
        top = x;
    }
}
struct Node *pop()
{
    struct Node *p = top;
    top = top->next;
    return p;
}
int main()
{
    printf("Enter size of expression:\n");
    int size;
    scanf("%d", &size);
    char s[50];
    char temp;
    printf("Enter the elements of the character expression in postfix notation:\n");
    scanf("%s", &s);
    struct Node *x, *y, *z;
    for (int i=0; i<size; i++)
    {
        if (s[i]=='+' || s[i]=='*' || s[i]=='-' || s[i]=='/')
        {
            z = create(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else
        {
            z = create(s[i]);
            push(z);
        }
    }
    printf("inorder traversal is:\n");
    inorder(z);
}