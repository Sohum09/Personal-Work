#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;
struct Node *create(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        root = create(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
struct Node *min(struct Node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        struct Node *current = root;
        while (current->left != NULL)
            current = current->left;
        return current;
    }
}
struct Node *delete(struct Node *root, int data)
{
    if (root == NULL) return NULL;
    else if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else
    {
        // no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // 1 child ie right
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        // 1 child ie left
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            // 2 children
            struct Node *temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int ch=0;
    int choice;
    int ele;
    int control = 1;
    do
    {
        printf("\n----------------------------------------\n");
        printf("\n1. To perform insertion in BST.");
        printf("\n2. To perform deletion in BST.");
        printf("\n3. To stop operations on BST.");
        printf("\nEnter choice[1-3]:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert:\n");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        case 2:
            printf("\nEnter element to delete:\n");
            scanf("%d", &ele);
            struct Node *temp = delete(root, ele);
            if (temp != NULL)
            {
                printf("Node deleted!\n");
                printf("Verification:\n");
                inorder(root);
            }
            else
                printf("tree is empty!\n");
            break;
        case 3:
            printf("\nThank you for using this program!");
            break;
        default:
            printf("Invalid Input!\n");
        }
    }while(ch!=3);

    printf("\nTraversals:\n");
    printf("\nInorder:\n");
    inorder(root);
    printf("\nPostorder:\n");
    postorder(root);
    printf("\nPreorder:\n");
    preorder(root);
}