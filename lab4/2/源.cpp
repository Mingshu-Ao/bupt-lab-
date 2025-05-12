#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �Զ����ӡ���������ݰ�����Ҫ���ӡ������
void printTree(TreeNode* root, int depth) {
    if (root == NULL) return;

    // ��ӡ�ո����ڰ����ʾ
    for (int i = 0; i < depth; i++) {
        printf("    "); // ÿ����ȼ����ӡ4���ո�
    }

    // ��ӡ�ڵ�����
    printf("%c\n", root->data);

    // �ݹ��ӡ����������ȼ�1
    printTree(root->left, depth + 1);
}

int main() {
    TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');

    printTree(root, 0); // �Ӹ��ڵ㿪ʼ�����Ϊ0
    return 0;
}