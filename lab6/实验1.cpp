#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
// ��������������ڵ�ṹ��
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����µĽڵ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// �������ݵ�����������
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// �������ݣ����ز��ҵĽڵ�Ͳ���·������
TreeNode* search(TreeNode* root, int key, int* pathLength) {
    *pathLength = 0;
    TreeNode* current = root;
    while (current != NULL) {
        (*pathLength)++;
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL; // δ�ҵ�
}

// ǰ�����
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// �������
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// �������
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// ��ʽ����ӡ���ṹ
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 10; // ÿһ������10���ո����ڴ�ӡ���Ĳ�νṹ

    // �ȴ�ӡ������
    printTree(root->right, space);

    // ��ӡ��ǰ�ڵ�
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // ����ӡ������
    printTree(root->left, space);
}

// ������
int main() {
    TreeNode* root = NULL;
    int data, key, pathLength;
    int testData[] = {50, 30, 20, 40, 70, 60, 80};  // ��������
    int n = sizeof(testData) / sizeof(testData[0]);

    // ��������������
    for (int i = 0; i < n; i++) {
        root = insert(root, testData[i]);
    }

    // ��ʽ����ӡ���Ľṹ
    printf("Binary Search Tree Structure:\n");
    printTree(root, 0);

    // ���Ҳ���
    printf("\nEnter a value to search: ");
    scanf("%d", &key);
    TreeNode* result = search(root, key, &pathLength);
    if (result != NULL) {
        printf("Found %d at path length %d\n", key, pathLength);
    } else {
        printf("Value %d not found, path length %d\n", key, pathLength);
    }

    // ������
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
