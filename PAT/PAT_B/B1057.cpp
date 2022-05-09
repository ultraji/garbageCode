/*
1057 数零壹 （20 分）
给定一串长度不超过 10^5的字符串，本题要求你将其中所有英文字母的序号（字母 a-z 对应序号 1-26，不分大小写）相加，得到
整数 N，然后再分析一下 N 的二进制表示中有多少 0、多少 1。例如给定字符串 PAT (Basic)，其字母序号之和为：16+1+20+2
+1+19+9+3=71，而 71 的二进制是 1000111，即有 3 个 0、4 个 1。

输入格式：
输入在一行中给出长度不超过 10^5、以回车结束的字符串。

输出格式：
在一行中先后输出 0 的个数和 1 的个数，其间以空格分隔。

输入样例：
PAT (Basic)

输出样例：
3 4
*/

#include <iostream>
#include <cstring>
using namespace std;
char str[100002];

int main(){
    int sum = 0, cnt[2] = {0, 0};
    fgets(str, 100002, stdin);
    for(int i = 0; str[i] != '\n'; i++){
        if(isalpha(str[i])){
            sum += tolower(str[i]) - 'a' + 1;
        }
    }
    while(sum > 0){
        cnt[sum%2] ++;
        sum /= 2;
    }
    cout << cnt[0] << ' ' << cnt[1];
    return 0;
}