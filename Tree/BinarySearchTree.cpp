#include <bits/stdc++.h>

using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
};

node *root;

void insertNode(int item);
void inOrder(node *p);
void preOrder(node *p);
void postOrder(node *p);
void menu();
void display();
bool searchData(int value);

int main()
{
    node *p;
    int n, choice;

    root = NULL;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value : ");
                scanf("%d", &n);
                insertNode(n);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter a value : ");
                scanf("%d", &n);
                if (searchData(n)) {
                    printf("%d was found.\n", n);
                }
                else {
                    printf("%d was not found.\n", n);
                }
                break;

            case 4:
                printf("Exiting. Thank you.\n");
                break;

            default:
                printf("Invalid choice. Try Again.\n");
        }
    } while (choice != 4);

    return 0;
}

void insertNode(int item)
{
    node *p, *newNode, *temp;

    newNode = (node *) malloc(sizeof(node));
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    p = root;
    while (p != NULL) {
        temp = p;
        if (p->info > item) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if (temp->info > item) {
        temp->left = newNode;
    }
    else {
        temp->right = newNode;
    }
}

void inOrder(node *p)
{
    if (p != NULL) {
        inOrder(p->left);
        printf("%d ", p->info);
        inOrder(p->right);
    }
}

void preOrder(node *p)
{
    if (p != NULL) {
        printf("%d ", p->info);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(node *p)
{
    if (p != NULL) {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->info);
    }
}

void menu()
{
    printf("\nMENU:\n");
    printf("1. Insert data\n");
    printf("2. Display data\n");
    printf("3. Search data\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
}

void display()
{
    if (root != NULL) {
        printf("\nTraversing Tree INorder\n");
        inOrder(root);
        printf("\nTraversing Tree PREorder\n");
        preOrder(root);
        printf("\nTraversing Tree POSTorder\n");
        postOrder(root);
    }
    else {
        printf("\nTREE is empty.\n");
    }
}

bool searchData(int value)
{
    node *p;
    bool found = false;

    p = root;
    while (true) {
        if (p == NULL) {
            break;
        }

        if (p->info == value) {
            found = true;
            break;
        }
        else if (value < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    return found;
}
