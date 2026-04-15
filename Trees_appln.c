#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert (Binary Tree - level wise)
struct Node* insert(struct Node* root, char name[]) {
    if (root == NULL) {
        return createNode(name);
    }

    if (root->left == NULL)
        root->left = createNode(name);
    else if (root->right == NULL)
        root->right = createNode(name);
    else
        insert(root->left, name);

    return root;
}

// Preorder Traversal
void display(struct Node* root) {
    if (root != NULL) {
        printf("%s -> ", root->name);
        display(root->left);
        display(root->right);
    }
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Search node
int search(struct Node* root, char key[]) {
    if (root == NULL)
        return 0;

    if (strcmp(root->name, key) == 0)
        return 1;

    return search(root->left, key) || search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];

    while (1) {
        printf("\n--- Employee Tree Menu ---\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees\n");
        printf("3. Count Employees\n");
        printf("4. Search Employee\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee name: ");
                scanf("%s", name);
                root = insert(root, name);
                break;

            case 2:
                printf("Employee Hierarchy:\n");
                display(root);
                break;

            case 3:
                printf("Total Employees: %d\n", countNodes(root));
                break;

            case 4:
                printf("Enter name to search: ");
                scanf("%s", name);
                if (search(root, name))
                    printf("Employee Found\n");
                else
                    printf("Employee Not Found\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
