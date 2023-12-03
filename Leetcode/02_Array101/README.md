# Array101

20231120

> introduction

題目 lock. Max Consecutive Ones，for 迴圈紀錄最長連續 1

題目 1295. Find Numbers with Even Number of Digits，使用迴圈判斷位數，然後對位數 % 2 判斷機偶數，有一個解法很猛，使用 log10 判斷位數，然後用 &1 判斷機偶數

題目 lock. Squares of a Sorted Array，利用數列性質(已經 sort 好了)，從左右拿取數字並平方就可以得到 sort 好的平方數列

> inserting item into an array

題目 1089. Duplicate Zeros，創建一個 list，有 0 就再加入一個 0，把這個 list 複製到題目的 arr



20231128

題目 Merge Sorted Array，使用兩個 pos 紀錄目前位置，並放到矩陣裡面



> deleting items from an array

題目 Remove Element，利用一個 index 紀錄目前位置，如果有和 val 重複的數字，index就不往前，反之則往前



20231129

題目 Remove Duplicates from Sorted Array，從 1 開始判斷，判斷前面的數是不是和目前一樣，如果不一樣代表這個數可以放到 nums 而不重複



20231130

> search for items in an array

題目 Check If N and Its Double Exist，使用兩個 for 迴圈 (bubble sort 的概念)，比較兩個數有沒有符合 `arr[i] == 2 * arr[j]` 

題目 Valid Mountain Array，使用兩個變數一個從後面一個從前面，當兩個變數交會就代表是 Mountain Array

> in-place operations

題目 Replace Elements with Greatest Element on Right Side，從後面開始跑只需要 O(n)，前面開始則會變 O(n^2)

題目  Move Zeroes 利用一個變數 index 存非 0 的次數，當 nums[index] == 0 然後 nums[當前位置] != 0，就讓兩個數互換

題目 Sort Array By Parity，利用一個變數 index 存非 0 的次數，當 nums[index] % 2 == 0(偶數) 就讓 index 往前，nums[index] % 2 == 1(奇數)當前位置是偶數 nums[i] % 2 == 0，就讓兩個數互換



20231202

> Conclusion

題目  Height Checker 給一個陣列 heights，回傳排序後的陣列與原陣列有多少數字不同。創一個 heights 的複製 vector，使用 bubble sort 對他排序，然後跟原本的 heights 進行比較

題目 Third Maximum Number，使用 set，長度小於三回傳最大，長度大於三把最大前兩個從 set 去除，取第三大的

題目 Find All Numbers Disappeared in an Array，創建一個 range [1, nums.size()] 的陣列 tmp，對 nums 陣列進行 for，當裡面元素與 tmp 一樣，就把 tmp 那個元素設為 0，最後用 for 迴圈，跳過 0 元素，把答案放到新的 vector ans

題目 (這題因為 II 要訂閱解鎖，所以寫 III) 1004. Max Consecutive Ones III，使用 Sliding Window 下去解，兩個變數 right 和 left，right 會一直往前，left 要等 right 走過的 0 (使用 numZeroes 紀錄) 超過 K 才會增加，當 left 走一步，且走過的是 0 ，numZeroes 就減一
