/*
1124. Raffle for Weibo Followers (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select 
winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers M (<= 1000), N and S, being the total 
number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives 
the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.
Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner 
has won before, we must skip him/her and consider the next one.

Output Specification:
For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print 
"Keep going..." instead.

Sample Input 1:
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
Sample Output 1:
PickMe
Imgonnawin!
TryAgainAgain

Sample Input 2:
2 3 5
Imgonnawin!
PickMe
Sample Output 2:
Keep going...
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
string str[1001];
map<string,int> mp;

int main(){
    int m, n, s;
    cin >> m >> n >> s;
    for(int i = 1; i <= m; i++){
        cin >> str[i];
    }
    while(s <= m){
        if(!mp.count(str[s])){
            cout << str[s] << endl;
            mp[str[s]] = 1;
            s += n;
        }else{
            s ++;
        }
    }
    if(mp.empty()){
        puts("Keep going...");
    }
    return 0;
}