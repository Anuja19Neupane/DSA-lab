#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    struct Node *lchild;
    int data, height;
    struct Node *rchild;
} *root = NULL;

// Function to get the height of a node
int NodeHeight(struct Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return (hl > hr ? hl + 1 : hr + 1);
}

// Function to get balance factor
int BalanceFactor(struct Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

// LL Rotation
struct Node *LLrotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (root == p) root = pl;
    return pl;
}

// LR Rotation
struct Node *LRrotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    if (root == p) root = plr;
    return plr;
}

// RR Rotation
struct Node *RRrotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if (root == p) root = pr;
    return pr;
}

// RL Rotation
struct Node *RLrotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    if (root == p) root = prl;
    return prl;
}

// Insertion
struct Node *recursive_insert(struct Node *p, int key) {
    if (p == NULL) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = recursive_insert(p->lchild, key);
    else if (key > p->data)
        p->rchild = recursive_insert(p->rchild, key);
    
    p->height = NodeHeight(p);

    // Balance AVL tree
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLrotation(p);
    
    return p;
}

// Find Minimum Node
struct Node *find_min(struct Node *p) {
    while (p->lchild != NULL)
        p = p->lchild;
    return p;
}

// Deletion
struct Node* delete_node(struct Node* p, int key) {
    if (p == NULL) {
        printf("Element not found\n");  // Print "element not found"
        return NULL;
    }

    if (key < p->data)
        p->lchild = delete_node(p->lchild, key);
    else if (key > p->data)
        p->rchild = delete_node(p->rchild, key);
    else {
        if (p->lchild == NULL) {
            struct Node* temp = p->rchild;
            free(p);
            return temp;
        } else if (p->rchild == NULL) {
            struct Node* temp = p->lchild;
            free(p);
            return temp;
        }

        struct Node* temp = find_min(p->rchild);
        p->data = temp->data;
        p->rchild = delete_node(p->rchild, temp->data);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) >= 0)
        return LLrotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) < 0)
        return LRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) <= 0)
        return RRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) > 0)
        return RLrotation(p);

    return p;
}

// Traversals
void inorder(struct Node *p) {
    if (p != NULL) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p) {
    if (p != NULL) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Main function
int main() {
    int key, choice, n, i;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find Minimum\n");
        printf("4. Pre-order Traversal\n");
        printf("5. In-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Ensure tree exists for operations except insert and exit
        if (choice != 1 && choice != 7 && root == NULL) {
            printf("No tree found.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the number of elements to insert: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &key);
                    root = recursive_insert(root, key);
                }
                printf("AVL Tree after insertion (In-order Traversal): ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                root = delete_node(root, key);
                printf("AVL Tree after deletion (In-order Traversal): ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Minimum value: %d\n", find_min(root)->data);
                break;
            case 4:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
