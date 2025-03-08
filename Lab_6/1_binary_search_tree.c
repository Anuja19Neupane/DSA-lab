#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

void inorder(struct BST *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct BST *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BST *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct BST *search(struct BST *root, int key)
{
    if (root == NULL || key == root->data)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct BST *findMax(struct BST *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct BST *findMin(struct BST *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct BST *insert(struct BST *root, int element)
{
    if (root == NULL)
    {
        struct BST *newNode = (struct BST *)malloc(sizeof(struct BST));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = element;
        return newNode;  // Returning new node
    }
    else if (element < root->data)
    {
        root->left = insert(root->left, element);
    }
    else
    {
        root->right = insert(root->right, element);
    }
    return root;  // Ensuring that root is returned
}

struct BST *deleteNode(struct BST *root, int element)
{
    struct BST *temp;
    if (root == NULL)
        return root;
    else if (element < root->data)
        root->left = deleteNode(root->left, element);
    else if (element > root->data)
        root->right = deleteNode(root->right, element);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;  // Make sure the modified root is returned
}

int main()
{
    struct BST *root = NULL;
    int choice, element;
    while (1)
    {
        printf("\nMenu Options:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. SEARCH\n");
        printf("4. FIND MAX\n");
        printf("5. FIND MIN\n");
        printf("6. INORDER\n");
        printf("7. PREORDER\n");
        printf("8. POSTORDER\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element to insert? ");
            scanf("%d", &element);
            root = insert(root, element);
            printf("%d INSERTION\n\n", element);
            break;

        case 2:
            printf("Element to delete? ");
            scanf("%d", &element);
            root = deleteNode(root, element);
            printf("%d DELETION\n\n", element);
            break;

        case 3:
            printf("Element to search? ");
            scanf("%d", &element);
            if (search(root, element) != NULL)
                printf("%d FOUND\n\n", element);
            else
                printf("%d NOT FOUND\n\n", element);
            break;

        case 4:
            if (root != NULL)
                printf("Max: %d\n\n", findMax(root)->data);
            else
                printf("Tree is empty.\n\n");
            break;

        case 5:
            if (root != NULL)
                printf("Min: %d\n\n", findMin(root)->data);
            else
                printf("Tree is empty.\n\n");
            break;

        case 6:
            inorder(root);
            printf("\n\n");
            break;

        case 7:
            preorder(root);
            printf("\n\n");
            break;

        case 8:
            postorder(root);
            printf("\n\n");
            break;

        default:
            printf("Invalid choice.\n\n");
            break;
        }
    }
}

