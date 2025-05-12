#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
// 定义二叉排序树节点结构体
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新的节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入数据到二叉排序树
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

// 查找数据，返回查找的节点和查找路径长度
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
    return NULL; // 未找到
}

// 前序遍历
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 中序遍历
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 后序遍历
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// 格式化打印树结构
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 10; // 每一层增加10个空格，用于打印树的层次结构

    // 先打印右子树
    printTree(root->right, space);

    // 打印当前节点
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // 最后打印左子树
    printTree(root->left, space);
}

// 主函数
int main() {
    TreeNode* root = NULL;
    int data, key, pathLength;
    int testData[] = {50, 30, 20, 40, 70, 60, 80};  // 测试数据
    int n = sizeof(testData) / sizeof(testData[0]);

    // 构建二叉排序树
    for (int i = 0; i < n; i++) {
        root = insert(root, testData[i]);
    }

    // 格式化打印树的结构
    printf("Binary Search Tree Structure:\n");
    printTree(root, 0);

    // 查找测试
    printf("\nEnter a value to search: ");
    scanf("%d", &key);
    TreeNode* result = search(root, key, &pathLength);
    if (result != NULL) {
        printf("Found %d at path length %d\n", key, pathLength);
    } else {
        printf("Value %d not found, path length %d\n", key, pathLength);
    }

    // 遍历树
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
