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

題目 Logger Rate Limiter，付費解鎖，已看線上版



> Practical Application - Design the key

題目 Group Anagrams，使用 sort 過的 `strs`，當作 unordered_map 的 key，value 存原本的樣子，最後再把 map value 放入 ans 的 vector。

插曲 為甚麼 function 要加上 &

題目 Group Shifted String，付費解鎖，已看線上版

題目 

題目 



> Conclusion

題目

題目 

題目 

題目

題目 

題目 

題目 
