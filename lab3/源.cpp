#include<stdio.h>  

#define MAXSTRLEN 255    
typedef unsigned char SString[256];  // �ַ������ͣ���һ��Ԫ�ش洢�ַ�������  

// ��posλ�ÿ�ʼ����S�в����Ӵ�T������ƥ�俪ʼ��λ�ã���1��ʼ�����������δ�ҵ��򷵻�0  
int Index(SString S, SString T, int pos) {
    int i, j;  // ��������ѭ������  
    for (i = pos - 1, j = 1; i <= S[0] - 1 && j <= T[0] - 1;) {
        // �����洢���ȵĵ�һ��Ԫ�أ��ӵڶ���Ԫ�ؿ�ʼ�Ƚ�  
        if (S[i + 1] == T[j + 1]) {
            j++;  // T�е��ַ�ƥ�䣬�����Ƚ���һ���ַ�  
            i++;  // S�е��ַ�Ҳƥ�䣬��������ƶ�����  
        }
        else {
            i = i - j + 1;  // ��ƥ��ʱ��i��Ҫ���˵���ʼ�Ƚ�T�ĵ�ǰ�ַ���ǰһ��λ�ã���Ҫ���Ǵ�pos-1��ʼ�������  
            j = 0;  // ����j���Ա��T�ĵ�һ���ַ����¿�ʼ�Ƚ�  
        }
        // ֻ�е�j����T�ĳ���ʱ���ű�ʾ�ҵ���ƥ��  
        if (j == T[0] - 1) {
            return i - j + 1;   
        }
    }
    return 0;
}

int main() {
    SString S = { 6, 'a', 'b', 'c', 'a', 'c', 'b' };  
    SString T = { 3, 'a', 'a', 'a' };  
    int index = Index(S, T, 1);  // ��S�ĵ�1���ַ���ʼ����T  
    printf("%d\n", index);  

    SString T2 = { 3, 'a', 'b', 'c' };  
    index = Index(S, T2, 1);  // ��S�ĵ�1���ַ���ʼ����T2  
    printf("%d\n", index);  

    return 0;
}