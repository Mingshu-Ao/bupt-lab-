#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 自定义打印函数，根据凹入表的要求打印二叉树
void printTree(TreeNode* root, int depth) {
    if (root == NULL) return;

    // 打印空格，用于凹入表示
    for (int i = 0; i < depth; i++) {
        printf("    "); // 每个深度级别打印4个空格
    }

    // 打印节点数据
    printf("%c\n", root->data);

    // 递归打印左子树，深度加1
    printTree(root->left, depth + 1);
}

int main() {
    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');

    printTree(root, 0); // 从根节点开始，深度为0
    return 0;
}