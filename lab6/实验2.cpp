#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 31  // ��ϣ���С��ѡ��һ�����������ٳ�ͻ

// ��ϣ��Ԫ�ؽṹ��
typedef struct HashNode {
    char name[50];  // �洢����
    int isOccupied; // ��־��λ���Ƿ��ѱ�ռ��
} HashNode;

// ��ϣ��
HashNode hashTable[TABLE_SIZE];

// ��ϣ������ʹ�ó���������
int hashFunction(const char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash + key[i]) % TABLE_SIZE;
    }
    return hash;
}

// ���뺯��������̽�ⷨ�����ͻ
void insert(const char* name) {
    int index = hashFunction(name);
    int originalIndex = index;  // ��¼ԭʼλ�ã���ֹ��ѭ��
    int i = 0;

    // ����̽�⣺�����ǰλ���ѱ�ռ�ã�������һ��λ��
    while (hashTable[index].isOccupied) {
        // ����ҵ��ظ������֣�ֱ�ӷ���
        if (strcmp(hashTable[index].name, name) == 0) {
            printf("Name %s already exists in the table.\n", name);
            return;
        }
        i++;
        index = (originalIndex + i) % TABLE_SIZE;  // ����̽��
    }

    // ��������
    strcpy(hashTable[index].name, name);
    hashTable[index].isOccupied = 1;  // ��Ǹ�λ���ѱ�ռ��
    printf("Inserted %s at index %d\n", name, index);
}

// ���Һ���
int search(const char* name) {
    int index = hashFunction(name);
    int originalIndex = index;
    int i = 0;

    // ����̽�����
    while (hashTable[index].isOccupied) {
        if (strcmp(hashTable[index].name, name) == 0) {
            return index;  // �ҵ����֣���������
        }
        i++;
        index = (originalIndex + i) % TABLE_SIZE;  // ����̽��
    }
    return -1;  // δ�ҵ�����
}

// ��ӡ��ϣ��
void printHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("Index %d: %s\n", i, hashTable[i].name);
        }
        else {
            printf("Index %d: [empty]\n", i);
        }
    }
}

int main() {
    // ��ʼ����ϣ��
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;  // ���Ϊ��
    }

    // �������ݣ�30���������й�������ƴ����
    const char* names[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i",
        "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "y", "z",
        "ams", "ldl", "zz", "jy", "llj", "zky"
    };

    // �������ֵ���ϣ��
    for (int i = 0; i < 30; i++) {
        insert(names[i]);
    }

    // ��ӡ��ϣ��
    printHashTable();

    // ���Ҳ���
    char searchName[50];
    printf("\nEnter a name to search: ");
    scanf("%s", searchName);

    int index = search(searchName);
    if (index != -1) {
        printf("Found %s at index %d\n", searchName, index);
    }
    else {
        printf("%s not found in the hash table.\n", searchName);
    }

    return 0;
}
