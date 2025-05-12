#include<stdio.h>  

#define MAXSTRLEN 255    
typedef unsigned char SString[256];  // 字符串类型，第一个元素存储字符串长度  

// 从pos位置开始，在S中查找子串T，返回匹配开始的位置（从1开始计数），如果未找到则返回0  
int Index(SString S, SString T, int pos) {
    int i, j;  // 定义两个循环变量  
    for (i = pos - 1, j = 1; i <= S[0] - 1 && j <= T[0] - 1;) {
        // 跳过存储长度的第一个元素，从第二个元素开始比较  
        if (S[i + 1] == T[j + 1]) {
            j++;  // T中的字符匹配，继续比较下一个字符  
            i++;  // S中的字符也匹配，继续向后移动索引  
        }
        else {
            i = i - j + 1;  // 不匹配时，i需要回退到开始比较T的当前字符的前一个位置（但要考虑从pos-1开始的情况）  
            j = 0;  // 重置j，以便从T的第一个字符重新开始比较  
        }
        // 只有当j等于T的长度时，才表示找到了匹配  
        if (j == T[0] - 1) {
            return i - j + 1;   
        }
    }
    return 0;
}

int main() {
    SString S = { 6, 'a', 'b', 'c', 'a', 'c', 'b' };  
    SString T = { 3, 'a', 'a', 'a' };  
    int index = Index(S, T, 1);  // 从S的第1个字符开始查找T  
    printf("%d\n", index);  

    SString T2 = { 3, 'a', 'b', 'c' };  
    index = Index(S, T2, 1);  // 从S的第1个字符开始查找T2  
    printf("%d\n", index);  

    return 0;
}