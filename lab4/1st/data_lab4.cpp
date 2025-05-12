#include <stdio.h>  
#include <stdlib.h>  

// ����������ڵ�ṹ  
typedef struct BiNode {
    char data;
    struct BiNode* lchild, * rchild;
} BiNode, * BiTree;

// �����½ڵ�  
BiNode* createNode(char data) {
    if (data == '$' || data == ' ') { // ͳһ�սڵ�ı�ʾ�ַ�Ϊ'$'��ո�����ֻ����'$'��  
        return NULL;
    }
    BiNode* newNode = (BiNode*)malloc(sizeof(BiNode));
    if (newNode == NULL) { // ����ڴ�����Ƿ�ɹ�  
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// �����ַ����е�����������й���������  
BiNode* buildTree(const char** str) {
    char ch = **str;
    (*str)++; // �ƶ�����һ���ַ�  
    if (ch == '$') { // ͳһ�սڵ�ı�ʾ�ַ�  
        return NULL;
    }
    BiNode* root = createNode(ch);
    root->lchild = buildTree(str);
    root->rchild = buildTree(str);
    return root;
}

// �������  
void preTraverse(BiNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preTraverse(root->lchild);
        preTraverse(root->rchild);
    }
}

// �������  
void inTraverse(BiNode* root) {
    if (root != NULL) {
        inTraverse(root->lchild);
        printf("%c", root->data);
        inTraverse(root->rchild);
    }
}

// �������  
void postTraverse(BiNode* root) {
    if (root != NULL) {
        postTraverse(root->lchild);
        postTraverse(root->rchild);
        printf("%c", root->data);
    }
}

// �ͷŶ������ڴ�ĺ�������ѡ�����Ƽ�ʵ�֣�  
void freeTree(BiNode* root) {
    if (root != NULL) {
        freeTree(root->lchild);
        freeTree(root->rchild);
        free(root);
    }
}

int main() {
    char input[] = "ABC$$DE$G$$F$$$"; // ��������  
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

    // �ͷŶ������ڴ棨��ѡ�����Ƽ�ִ�У�  
    freeTree(root);

    return 0;
}