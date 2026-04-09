#include <stdio.h>
int main() {
    printf("输入一行字符：\n");
    char ch;
    int i,count=0,word=0;
    while((ch=getchar())!='\n') {
        if (ch==' ') {
            word=0;
        } else if (word==0) {
            word=1;
            count++;
        }
    }
    printf("总共有 %d 个单词\n",count);
    return 0;
}

