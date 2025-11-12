#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    struct Node* current = root;
    char direction;

    while (1) {
        printf("Insert to left or right of node with data %d? (l/r): ", current->data);
        scanf(" %c", &direction);

        if (direction == 'l') {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            } else {
                current = current->left;
            }
        } else if (direction == 'r') {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            } else {
                current = current->right;
            }
        } else {
            printf("Invalid input. Use 'l' or 'r'.\n");
        }
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Create Root Node\n");
        printf("2. Insert Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("Enter value for root: ");
                    scanf("%d", &value);
                    root = createNode(value);
                    printf("Root node created.\n");
                } else {
                    printf("Root already exists!\n");
                }
                break;

            case 2:
                if (root == NULL) {
                    printf("Create root first!\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insert(root, value);
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
