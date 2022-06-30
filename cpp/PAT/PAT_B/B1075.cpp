/*
1075 链表元素分类 （25 分）
给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而 [0, K] 区
间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 
18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

输入格式：
每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1 个结点的地址；结点总个数，即正整数N (≤10^5)；
以及正整数K (≤10^3)。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址；Data 是该结点保存的数据，为 [−10^5,10^5] 区间内的整数；Next 是下一结点
的地址。题目保证给出的链表不为空。

输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218

输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
    int addr, num, next;
}no;

int main(){
    int start, n, k;
    vector<node> v[3];
    map<int, node> mp;
    cin >> start >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> no.addr >> no.num >> no.next;
        mp[no.addr] = no;
    }
    while(start != -1){
        no = mp[start];
        if(no.num < 0){
            v[0].push_back(no);
        }else if(no.num >= 0 && no.num <= k){
            v[1].push_back(no);
        }else{
            v[2].push_back(no);
        }
        start = no.next;
    }
    for(int i = 1; i < 3; i++){
        for(int j = 0; j < v[i].size(); j++){
            v[0].push_back(v[i][j]);
        }
    }
    int t = v[0].size()-1;
    for(int i = 0; i < t; i++){
        printf("%05d %d %05d\n", v[0][i].addr, v[0][i].num, v[0][i+1].addr);
    }
    printf("%05d %d -1", v[0][t].addr, v[0][t].num);
    return 0;
}