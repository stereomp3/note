# HashTable

20240221

> Design a Hash Table

題目 Design HashSet，使用 bool 做，開一個很大的 bool vector，位置為 true 代表有這個數字，false 代表沒有

題目 Design HashMap，照上面 hashSet 別人的想法來做，使用 vector int 紀錄位置值，達到 key 和 value 同時儲存



20240225

>  Practical Application - Hash Set

題目 Contains Duplicate，使用 unordered_set 紀錄陣列有沒有重複，有重複就回傳 true

題目 Single Number，利用 XOR 的性質，XOR 0 等於本的數，XOR 兩次等於原本的數字，找出為一出現一次的數字

題目 Intersection of Two Arrays，用 unordered_set 紀錄 nums1，然後再遍歷 nums2，找出一樣的元素

題目 Happy Number，直接使用兩個變數存目前的數和未來的數，當目前等於未來就跳出迴圈，並看數字是否等於 1



20240226

> Practical Application - Hash Map

題目 Two Sum，用暴力解，兩個 for 迴圈，找到等於 target 就推到 vector 裡面，然後回傳。最佳解是使用 unordered_map，利用 index 判斷有沒有補數。

題目 Isomorphic Strings，不用 unordered_map，直接開 256(ASCII) 格存 s 和 t 的 string，key 放字串 value 放存取次數，比較兩個 key 裡面的存取次數

題目 Minimum Index Sum of Two Lists，使用兩個 unordered_map和多個 for 迴圈，一個紀錄第一個字串，另一個紀錄重複的字串，從重複字串的 map 裡面，找出值最小的



20240303

題目 First Unique Character in a String，使用 unordered_map 紀錄字符出現位置，如果出現重複，那位置等於 -1

題目 Intersection of Two Arrays II，使用兩個 unordered_map，紀錄兩個 array 的元素出現次數，最後取其中一個 mp 的值，和另外一個 mp 做比對，取最小出現次數，然後放入 vector，這題做超久...。最佳解 map 用減的求相同值，可以少一次 for 遍歷 map，而且只用到一個 map



20240304

題目 Contains Duplicate II，使用 `unordered_map<int, pair<int, int>>`，key 存放當前數字，pair 第一個紀錄目前位置，第二個紀錄最短的重複數字距離，最後再使用 K 去 for 迴圈減掉 map 裡面數字，就可以知道有沒有 `num` 裡面重複的元素位置相減的絕對值 <= `k`，最佳解直接在第一個 for 迴圈結束，而且不用 pair，直接用 k 和 距離比較。

題目 Logger Rate Limiter，付費解鎖，已看線上版。使用 unordered_map 紀錄 message 和 timestamp 判斷



> Practical Application - Design the key

題目 Group Anagrams，使用 sort 過的 `strs`，當作 unordered_map 的 key，value 存原本的樣子，最後再把 map value 放入 ans 的 vector。

插曲 為甚麼 function 要加上 &

題目 Group Shifted String，付費解鎖，已看線上版。把每個字符的差距使用字串記起來當作 hash map 的 key， 就可以不用比對，直接輸出。



20240305

題目 Valid Sudoku，暴力解，求 row 再求 column 最後求 3*3 有沒有重複的數字，最佳解使用 兩個 for迴圈搞定 O(n^2)，很猛

題目 Find Duplicate Subtrees，解很久最後放棄，最佳解是使用 postorder 讀取 Tree 存在 map 裡面 (`unordered_map<string, vector<TreeNode*>>`)，利用 string 紀錄節點走過的紀錄，並把他當作 key，當 string 相同就代表他們為相同結構，這時就把 node 加入到 map 的 key 裡面，當後面使用一次 for 迴圈讀取 map 裡面的 value，vector 的 size > 1，就代表有重複的結構，就回傳到答案裡面。



值得一看的 [unordered map key 總結](https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1128/): 

* 尋找相同數字或字符: 建議用 sort 過的數字或字符當作 key
* 尋找數字差相同(或是字符差)的內容: 用差額數列當作 key
* 相同結構的樹: 用字串紀錄節點當作 key
* `9*9` 分類根據 `3*3`: `i / 3 * 3 + j / 3` 當作 key
* 斜角統計: 從右往上的斜角: `(i,j) -> i+j` 當作 key、從右往下的斜角:  `(i,j) -> i-j` 當作 key...



20240306

> Conclusion

題目 Jewels and Stones，送分題，使用 unordered map 紀錄 stones 的 char 出現次數， jewels 的 char 出現就加上 stones  的出現次數。最佳解使用 unorder set 存 Jewels 取出有的字符，再使用 for 迴圈遍歷 stones，使用記憶體更少

題目 Longest Substring Without Repeating Characters，超醜寫法，先用 一個 set 紀錄有沒有出現重複字符，等到重複，再利用另一個 set 紀錄前面的字符有沒有重複。最後算出最長子字串有多長。最佳解是用(建議看這題下面我的註解) 開一個 vector 256 個位置，紀錄不同的 char 出現的位置 (這邊也可以用 unordered_map)，出現第二次 start 才會改變(代表 start 位置是第一次出現的位置)，導致後面算的 maxlen 可以根據 i - start 求出最長字串長度。

題目 Two Sum III - Data structure design，付費解鎖，已看線上版。使用 unordered_map 做，map 存 Key: 有出現在 add 裡面的數字， value  add 裡面的數字出現次數。最佳解有用一個很精簡的式子

題目 4Sum II，暴力解，經歷多次 timeLimit，採用 unordered_map 紀錄每個 vector 裡面的數字出現次數 (去重複)，再使用 for 迴圈依序讀 mp，但四個全讀取也會 TL，所以後面把第四個改成直接用 key 去存，key 就是前面三個的值相加加上負號。跟我的作法很像，不過拆成兩部分，讓他變成 O(n^2)

題目 Top K Frequent Elements，使用 unorder_map 紀錄數字出現次數，再把 mp 放到 vector，做排序，最後取出前面 k 個。使用 priority queue，會再快一點點

題目 Unique Word Abbreviation，付費解鎖，已看線上版。使用 unordered_map，和 unordered_set，把縮寫當作 map 的 key，set 當作 map 的值，每個 key 只能對應到 set.size == 1，如果超過 1 就代表縮寫不唯一，回傳 false。最佳解可以不用使用 set，節省空間，使用兩個 string 當作 key 和 value，當縮寫方式已經存在，然後現在這個單字不等於已有的單字，那就把 value 的字串改為空字串。

題目 Insert Delete GetRandom O(1)，算簡單，不過 random 使用 Time 當 seed 會因為時間太快所以都一樣，使用 count 每次跑都 +1 當作 seed 才過，最後使用 next 直接叫 iterator 的位置，才不用使用 for 迴圈拿取，變成 O(n)。最佳解使用 vector 紀錄元素，用 unordered_map 紀錄 vector 元素位置，就可以比 unordered_set 更快。
