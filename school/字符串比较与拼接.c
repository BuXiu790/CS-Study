#include<string.h>
#include<stdio.h>
int main(){

    char a[200];
    char b[200];
    char temp[200];
  scanf("%s", a);
  scanf("%s", b);
  int lenA = strlen(a);
  int lenB = strlen(b);
  if(lenA==lenB){
    return 0;

  }
 if (lenA > lenB) {
        strcat(b, a);
        printf("结果: %s\n", b);
    }
    // 3. 如果 a 长度 < b 长度：a 拼接到 b 之前 (b = a + b)
    else if (lenA < lenB) {
        strcpy(temp, b); // 先备份 b 到 temp
        strcpy(b, a);    // 把 a 复制到 b 的开头
        strcat(b, temp); // 把备份的 b 接在后面
        printf("结果: %s\n", b);
    }
}