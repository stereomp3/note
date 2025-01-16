# [Minimize XOR](https://leetcode.com/submissions/detail/1509476933/)

> 問題

給定兩個變數 num1 和 num2，要找出 二進位 bit 數與 num2 一樣，然後與 num1 XOR 為最小的值

EX:

```
# 01
Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

# 02
Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
```

**Constraints:**

- `1 <= num1, num2 <= 109`

> 我的解法

判斷兩個數字的 bit 數量，根據 bit 數量做出不同判斷。

先存 num1 的二進位，然後判斷 num1 與 num2 bit 相減的大小(命名為 compare)

* compare == 0: 直接回傳 num1，也就是最小值為 0 (自己與自己 XOR == 0)
* compare > 0: 因為這邊是 num2 比 num1 的 1 多，所以最後結果一定會比 num1 還要大，所以會根據 num1 出現的 1 次數減去 compare (-=1)，有 0 的地方也填入 1 並減去 compare，如果最後減完還沒有 compare = 0，那就直接補上 1。
* compare < 0: 假設會根據兩個 bit 相差的 bit 數量，去忽略 num1 的 1，因為要求最小值，而存的二進位又是倒過來的，所以最前面的 bit 會是最小，這邊運用 compare 的數字，去把前面的 1 忽視，然後把剩下的 1 乘以 2 的次方加起來，出來的數字是最大，但是與 num1 XOR 就會是最小值。

```c++
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int tmp=num2;
        vector<int> vec;
        int count1 = 0;
        int count2 = 0;
        while(tmp!=0){ // count bit 
            if(tmp%2) count2+= 1;
            tmp /= 2;
        }
        tmp = num1;
        while(tmp!=0){ // record num1 binary
            vec.push_back(tmp%2);
            if(tmp%2) count1+= 1; // count bit
            tmp /= 2;
        }
        cout << "count1: " << count1 << endl;
        cout << "count2: " << count2 << endl;
        
        int times = 1;
        int ans = 0;
        int compare = count2 - count1; // compare>0 -> ans is grater than num1
        cout << "compare: " << compare << endl;
        for(auto it:vec){cout << "ccc: " << it << endl;}
        if(compare == 0){
            return num1;
        }
        else if(compare > 0){
            for(auto it:vec){
                cout << "bi: " << it << endl; 
                if(compare > 0 && it == 0){
                    compare -= 1;
                    ans += 1*times;
                }
                else ans += it*times;
                times *= 2;
            }
            while(compare > 0){
                ans += 1*times;
                times *= 2;
                compare-=1;
            }
        }
        else if(compare < 0){
            for(auto it:vec){
                if(it==1 && compare!=0){
                    compare += 1;
                }
                else{
                    ans += it*times;
                }
                times *= 2;
            }
        }
        cout << "ans: " << ans << endl;
        return ans;
    }
};
```





> 最佳解

太強了...

- **Time complexity**: *O*(32) (constant time for 32-bit integers).
- **Space complexity**: *O*(1).

想法:  最大 2^32 (< 10^9)，所以對每個 bit 做檢查，a > b (num1 bit 數量比 num2 多)就把 num1 的 1 變為 0，a < b (num2 bit 數量比 num1 多)就把 num1 的 0 變為 1。

函數說明 `__builtin_popcount`: 返回 num 裡面 1 的個數

```c++
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        int res = num1;
        for (int i = 0; i < 32; ++i) {
            // (1 << i) & num1 代表在 i 位元的地方 為 1
            if (a > b && (1 << i) & num1) {  // 1 變成 0
                res ^= 1 << i;
                --a;
            }
            if (a < b && !((1 << i) & num1)) { // 0 變成 1
                res ^= 1 << i;
                ++a;
            }
        }
        return res;
    }
};
```



`__builtin_popcount` 原理詳細解說 ref: https://blog.csdn.net/github_38148039/article/details/109598368

核心原理使用 二分法去把 1 的個數求出來

```c++
__builtin_popcount = int
__builtin_popcountl = long int
__builtin_popcountll = long long
```



```c++
unsigned popcount (unsigned u)
{
    u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
    u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
    u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
    u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
    u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
    return u;
}
```





以 8 進位為範例

`0x55555555 -> 01010101`

`0x33333333 -> 00110011`

`0x0F0F0F0F -> 00001111`

```
u = 10110011。
10110011
00010001 // 取偶數位, u & 01010101
01010001 // 取奇數位, (u >> 1) & 01010101  // (u >> 1) 往右位移 -> 01011001
相加偶數位與奇數位的 bit，偶數有兩個，奇數有三個
01100010 // u = 上面兩數相加
我認為這邊包含的資訊分成四塊，兩兩一組 (01, 10, 00, 10)，總共合為 5
---------------
根據上面的兩兩一組，再次分為左右兩邊
00100010 // 每四位數取右邊兩位數， u & 00110011
00010000 // 每四位數取左邊邊兩位數, (u >> 2) & 00110011 // (u >> 2) 往右位移 -> 00011000
00110010 // u = 上面兩數相加
這邊資訊分成兩塊，四個為一組 (0011, 0010)，總和為 5
---------------
最後把左右合併起來
00000010 // 取右邊四位數， u & 00001111 
00000011 // 取左邊四位數，(u >> 4) & 00001111 // (u >> 4) 往右位移 -> 00000011
00000101 // u = 上面兩數相加
把資訊變成一塊，可以得到 5
---------------
最後得到 u = 5，也就是 5 bit
```

