#include <stdio.h>  
#include <stdlib.h>  

// 定义二叉树节点结构  
typedef struct BiNode {
    char data;
    struct BiNode* lchild, * rchild;
} BiNode, * BiTree;

// 创建新节点  
BiNode* createNode(char data) {
    if (data == '$' || data == ' ') { // 统一空节点的表示字符为'$'或空格（这里只保留'$'）  
        return NULL;
    }
    BiNode* newNode = (BiNode*)malloc(sizeof(BiNode));
    if (newNode == NULL) { // 检查内存分配是否成功  
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 根据字符串中的先序遍历序列构建二叉树  
BiNode* buildTree(const char** str) {
    char ch = **str;
    (*str)++; // 移动到下一个字符  
    if (ch == '$') { // 统一空节点的表示字符  
        return NULL;
    }
    BiNode* root = createNode(ch);
    root->lchild = buildTree(str);
    root->rchild = buildTree(str);
    return root;
}

// 先序遍历  
void preTraverse(BiNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preTraverse(root->lchild);
        preTraverse(root->rchild);
    }
}

// 中序遍历  
void inTraverse(BiNode* root) {
    if (root != NULL) {
        inTraverse(root->lchild);
        printf("%c", root->data);
        inTraverse(root->rchild);
    }
}

// 后序遍历  
void postTraverse(BiNode* root) {
    if (root != NULL) {
        postTraverse(root->lchild);
        postTraverse(root->rchild);
        printf("%c", root->data);
    }
}

// 释放二叉树内存的函数（可选，但推荐实现）  
void freeTree(BiNode* root) {
    if (root != NULL) {
        freeTree(root->lchild);
        freeTree(root->rchild);
        free(root);
    }
}

int main() {
    char input[] = "ABC$$DE$G$$F$$$"; // 测试数据  
    const char* ptr = input;
    BiNode* root = buildTree(&ptr);

    printf("preorder: ");
    preTraverse(root);
    printf("\n");

    printf("inorder: ");
    inTraverse(root);
    printf("\n");

    printf("postorder: ");
    postTraverse(root);
    printf("\n");

    // 释放二叉树内存（可选，但推荐执行）  
    freeTree(root);

    return 0;
}