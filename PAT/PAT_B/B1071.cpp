/*
1071 小赌怡情 （15 分）
常言道“小赌怡情”。这是一个很简单的小游戏：首先由计算机给出第一个整数；然后玩家下注赌第二个整数将会比
第一个数大还是小；玩家下注 t 个筹码后，计算机给出第二个数。若玩家猜对了，则系统奖励玩家 t 个筹码；否
则扣除玩家 t 个筹码。
注意：玩家下注的筹码数不能超过自己帐户上拥有的筹码数。当玩家输光了全部筹码后，游戏就结束。

输入格式：
输入在第一行给出 2 个正整数 T 和 K（≤ 100），分别是系统在初始状态下赠送给玩家的筹码数、以及需要处理
的游戏次数。随后 K 行，每行对应一次游戏，顺序给出 4 个数字：
n1 b t n2
其中 n1 和 n2 是计算机先后给出的两个[0, 9]内的整数，保证两个数字不相等。b 为 0 表示玩家赌小，为 1 
表示玩家赌大。t 表示玩家下注的筹码数，保证在整型范围内。

输出格式：
对每一次游戏，根据下列情况对应输出（其中 t 是玩家下注量，x 是玩家当前持有的筹码量）：

玩家赢，输出 Win t! Total = x.；
玩家输，输出 Lose t. Total = x.；
玩家下注超过持有的筹码量，输出 Not enough tokens. Total = x.；
玩家输光后，输出 Game Over. 并结束程序。

输入样例 1：
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8

输出样例 1：
Win 100!  Total = 200.
Lose 50.  Total = 150.
Not enough tokens.  Total = 150.
Not enough tokens.  Total = 150.

输入样例 2：
100 4
8 0 100 2
3 1 200 1
5 1 200 6
7 0 200 8

输出样例 2：
Win 100!  Total = 200.
Lose 200.  Total = 0.
Game Over.
*/

// Tip: 两句话之间有两个空格
#include <iostream>
using namespace std;

int main(){
    int total, k, n1, b, t, n2;
    cin >> total >> k;
    for(int i = 0; i < k; i++){
        if(total == 0){
            printf("Game Over.\n");
            break;
        }
        cin >> n1 >> b >> t >> n2;
        if(t > total){
            printf("Not enough tokens.  ");
        }else if((b == 0 && n2 < n1) || (b == 1 && n2 > n1)){
            printf("Win %d!  ", t);
            total += t;
        }else{
            printf("Lose %d.  ", t);
            total -= t;
        }
        printf("Total = %d.\n", total);
    }
    return 0;
}