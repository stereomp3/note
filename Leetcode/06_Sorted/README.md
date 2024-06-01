# Sorted

20240321

> Introduction to Sorting

題目 Sort Colors，使用 selection sort 排序，因為要存第一個，然後還要在最後與第一個比對，所以使用 `nt *tmp=&nums[i];`，存 vector 的 address，然後後面再 swap。利用題目的特性，使用兩個 pointer 解題 (Dutch National Flag algorithm)，先設定 low (0)、mid (0)、hight (`nums.size() -1`)，使用一個 `while(mid <= high)`，當遇到 2 (num[mid])， 交換 mid hight 位置的數 (把 2 放到最後面)，並把 high 減 1，遇到 1 mid 加 1，0 則是交換 mid low 位置的數(把前面有 1 的往後移)，並把 low、mid 都加 1。這題可以使用 count sort 會快很多 (O(*N*+*K*))

題目 Insertion Sort List，寫有點久，使用三個 while，寫到後面有點用湊的，第一個 while 遍歷 node，第二個 while 跟前面的 Node 比較大小，如果比前面 Node 小就放入節點，在放入的時候使用第三個 while (這步驟卡很久)，讓 preHead while 到目前 head 的前面，才可以使用 `preHead = head->next`。用跟我很像的方式，但它在一開始創建一個 Node，讓變數不用那麼多，整體也比較順，兩個 while 迴圈搞定。



20240325

題目 Heap Sort，本來想要使用 merge sort，但後來發現 merge sort 寫起來沒這麼容易，所以還是使用 Heap sort (參考前面的文章用 python 寫的 Heap sort)。也可以使用 Outplace merge sort (O(n * lgn)；Inplace Merging、quicksort 會 TLE)

題目 Kth Largest Element in an Array，使用 heap sort 排序，從後面取 K 個。也使用  `multiset` 或是 `priority_queue`。



20240327

>  Non-comparision Based Sorts

講解 count sort

題目  Minimum Absolute Difference，使用 multiset 存 `arr` 的數值， multiset 會自動排序，再利用前後相減，求出最小距離(好像因為使用 multiset 效能很差...)。我的方法其實是排序後比較鄰近的數值 (O(NlogN))，可以使用一半的 count sort (沒有用到 startingIndex) 後再比較鄰近的數值，讓整個方法變成 O(N+K)。count sort 先使用 minmax_element，求出最大最小值，並創建一個 最大值-最小值+1 的 `vector<bool>`，再使用 shift (等於最小值)，讓所有數字可以存放到對應的位置，最後遍歷 `vector<bool>`，相減前後兩個元素。

題目

題目



> Summary and Conclusion


