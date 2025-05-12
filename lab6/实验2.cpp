#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 31  // 哈希表大小，选择一个素数，减少冲突

// 哈希表元素结构体
typedef struct HashNode {
    char name[50];  // 存储人名
    int isOccupied; // 标志该位置是否已被占用
} HashNode;

// 哈希表
HashNode hashTable[TABLE_SIZE];

// 哈希函数：使用除留余数法
int hashFunction(const char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash + key[i]) % TABLE_SIZE;
    }
    return hash;
}

// 插入函数：线性探测法解决冲突
void insert(const char* name) {
    int index = hashFunction(name);
    int originalIndex = index;  // 记录原始位置，防止死循环
    int i = 0;

    // 线性探测：如果当前位置已被占用，尝试下一个位置
    while (hashTable[index].isOccupied) {
        // 如果找到重复的名字，直接返回
        if (strcmp(hashTable[index].name, name) == 0) {
            printf("Name %s already exists in the table.\n", name);
            return;
        }
        i++;
        index = (originalIndex + i) % TABLE_SIZE;  // 线性探测
    }

    // 插入名字
    strcpy(hashTable[index].name, name);
    hashTable[index].isOccupied = 1;  // 标记该位置已被占用
    printf("Inserted %s at index %d\n", name, index);
}

// 查找函数
int search(const char* name) {
    int index = hashFunction(name);
    int originalIndex = index;
    int i = 0;

    // 线性探测查找
    while (hashTable[index].isOccupied) {
        if (strcmp(hashTable[index].name, name) == 0) {
            return index;  // 找到名字，返回索引
        }
        i++;
        index = (originalIndex + i) % TABLE_SIZE;  // 线性探测
    }
    return -1;  // 未找到名字
}

// 打印哈希表
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
    // 初始化哈希表
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;  // 标记为空
    }

    // 测试数据：30个常见的中国人名（拼音）
    const char* names[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i",
        "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "y", "z",
        "ams", "ldl", "zz", "jy", "llj", "zky"
    };

    // 插入名字到哈希表
    for (int i = 0; i < 30; i++) {
        insert(names[i]);
    }

    // 打印哈希表
    printHashTable();

    // 查找测试
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
