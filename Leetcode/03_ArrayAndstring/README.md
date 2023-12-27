# ArrayAndstring

20231203

> Introduction to Array

題目 Find Pivot Index，先把陣列 nums 裡面的元素全部加總，然後用 for 迴圈從左邊慢慢扣，當扣的值等於右邊的總和，就回傳目前的的 i



20231204

題目 Largest Number At Least Twice of Others，紀錄陣列 nums 裡面前 2 大的數( max1, max2)，透過比較 nums[i] 把數字放入到 max2，如果這個數字比 max1 大，那就 swap(max1, max2)，最後比較 max1 是不是 >= max2

題目 Plus One，從矩陣 digits 後面開始 for 迴圈，當遇到 9 就把它變成 0，其他就都 +1 然後 return，當遇到 9 然後是第一個位數，那就代表要進位，所以就 insert 一個 1 然後把那個 9 變成 0



20231205

>  Introduction to 2D Arrary

題目 Diagonal Traverse，使用一個 while 迴圈，根據題目的規則從對角線開始排列，用 isRT 判斷現在是往右上走還是往左下走

題目 Spiral Matrix，設定上下左右的邊界，當碰到後，邊界慢慢縮小，值到跑完所有元素

題目 Pascal's Triangle，帕斯卡三角型，先創建都是 1 的 arr，然後再填入值，放到答案的 arr 裡面



> Introduction to String

20231207

題目 Add Binary，把兩個字串 a 和 b 以二進位的形式相加。先比較兩字串大小，大的長度當作 for 迴圈的長度，從後面 for 到前面，把兩個字串都從後面開始加，然後推到新字串裡面，最後反轉新字串。



20231210

題目 Implement strStr()，使用 KMP pattern matching 檢查 pattern 有多少跟自己重複的 char，然後再用 while 迴圈比對兩個字串有沒有重複的地方



20231211

題目 Longest Common Prefix，使用雙重 for 迴圈，判斷字串是不是和第一個一樣，如果有不一樣就回傳現在記錄到的字串。



> Two-Pointer Technique

題目 Reverse String，取中間長度做 for 迴圈，做字符互換

題目 Array Partition I，O(n) 的解法，使用大 Vector hashtable 紀錄 20001 個位置，並設初始值為 0，把 nums[i]+10000 的位置 +1，然後再用 for 迴圈，當 hashtable[i]  > 0，另外有 flag 紀錄，是奇數才把值放到 sum 裡面，因為這題有範圍限制 ``-10^4 <= nums[i] <= 10^4`，所以才可以這樣解

題目 Two Sum II - Input array is sorted，使用兩個點下去找，因為陣列已經排序完畢，所以從左右兩邊開始找，如果找到的值比 target 小，那左邊的點就 +1，反之右邊的點 -1



20231218

題目 Minimum Size Subarray Sum，使用 for 迴圈遍歷 nums，利用 left, right 紀錄區域的值， min 紀錄最小大於等於 target 的區塊長度



> Conclusion

題目

題目

題目

題目
