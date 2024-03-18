# LinkedList

20240311

> Singly Linked List

題目 Design Linked List，使用 vector 做 list，好像有點犯規，使用 insert、erase 功能完成 list 的操作，沒有用到 next。最佳解建立一個 Node class，裡面有 val 和 *next、以及 Node constructor `Node(int x) { val=x; next=nullptr;}`，裡面有使用 new 動態呼叫 Node，所以要使用 delete 再刪除掉創建好的 Node，還有 destructor ~ 把 Node 清除乾淨。



>  Two Pointer Technique

題目 Linked List Cycle，使用兩個 pointer，一個快(前進兩步)，一個慢(前進一步)，當兩個 point 相遇就代表是循環 Linked List，如果 快的走到 NULL，就代表沒有循環。

題目 Linked List Cycle II，使用 unordered_set，紀錄 Node，如果有重複就 return 那個 Node。最佳解使用 slow 和 fast ，fast(a + b + c + d) 是 slow(a + b) 的兩倍，所以剛好最後可以使用 head 和 slow 碰面 (a = c) 讓 head 變成最後 重複位置的 Node



20240312

題目 Intersection of Two Linked Lists，使用 unordered_set 存 Node，先存 headA，然後只要 headB 有重複 Node，那就是交匯點。我的解法算是其中一個最佳解，還可以使用遍歷兩個 Linked List 得到的長度相減，或是兩個 pointer 的解法。

題目 Remove Nth Node From End of List，跑一次就完成，使用一個 node 紀錄目前的 head，再用一個 int 紀錄 n，當 n 減到 0 然後 head 還沒到 end，node 就往前進，直到 head 到 end，這時 node 就是從後面數來的 n 個節點。最佳解使用反者接點，沒有用到 swap



20240313

> Classic Problems

題目 Reverse Linked List，比想像中的麻煩，先左右交換，在把目前的位置接到第一個上，Node 交換的時候常會出現奇怪錯誤，不是 swap 這麼簡單，要記住 Node 的前後順序，我使用 printf 把全部 print 出來，再慢慢湊，才成功在 run 一次 Linked List 就解決反轉。

題目 Remove Linked List Elements，比上一題簡單很多，只要把等於 val 的值，前面接到 Node 的下一個就好了。有一個很特殊的寫法，很多 *，看起來很猛，有時間可以研究研究。



20240314

題目 Odd Even Linked List，紀錄單數的頭和雙數的頭，各自連成串鍊後，再合併，有一個很重要的是，每次合成都是取前面的 Node，還要把目前的 Node 指向 NULL，不然最後會報錯。最佳解跟我的差不多，不過他沒有使用 if else，直接用 next 解決，簡單明瞭。

題目 Palindrome Linked List，創建兩個 pointer，一個快一個慢，慢的 pointer 在走的時候存值到 vector 裡面，直到快的 pointer 走到底，然後慢的再和 vector 裡面的值比對，看有沒有重複。最佳解跟我的做法第一步驟一樣，都使用兩個 pointer，但是後面他沒有用 vector，而是直接把最後到中間的 Linked List，做反轉指向，然後再判斷左邊到右邊是否相等。



> Doubly Linked List

題目 Design Linked List，上面已做過

array 好處在於 Access，只要呼叫 index 就可以拿取，而 Linked List 好處則再修改，增加刪除的操作時間複雜度比較低

![img](https://assets.leetcode.com/uploads/2020/10/02/comparison_of_time_complexity.png)



> Conclusion

題目 Merge Two Sorted Lists，先比較兩個 Linked List 第一個元素大小，比較小的當作 while 迴圈目標，透過比較節點大小，然後慢慢接節點。和我的很像，不過他是使用 curr 來一個一個接上去，我是直接使用 list1 或是 list2。不過他的接法比較簡單。



20240315

題目 Add Two Numbers，由第一個 Linked List 當作目標，進行 while，把 l1 和 l2 元素相加，用 n 和 c 紀錄相加數字和有沒有進位，然後處裡各種情況，像是 l2 比 l1 長，或是最後一個元素是 9，就要新增節點。和我的寫法差不多，不過他一開始就 new 一個 ListNode，把他當作頭，一直接下去，然後最後再傳回他的 next，然後 delete 掉他，沒有紀錄前一個 node，判斷使用 `l2 = (l2 != nullptr) ? l2->next : nullptr;`。

題目 Flatten a Multilevel Doubly Linked List，有點麻煩，因為結構要和 Node 一樣，所以需要設定好三個方向的值，使用 while 遍歷 head，創建一個 curr，連接整個 Linked List，使用一個 vector 紀錄 parent，如果 child 走到底，那就 pop back，然後 head 等於 parent 的最後一個元素。沒有使用 vector，用一個 for 迴圈，針對 child 的地方做處理，child 的地方使用 while 走到底，然後接到原本的 Linked List。

題目 Insert into a Sorted Circular Linked List，付費解鎖，已看線上版。如果 head 為空，就創建指向自己的 Node，不為空就判斷大小插入到循環鏈結串列裡面。



20240318

題目 Copy List with Random Pointer，這題很麻煩，因為 random 會跳，所以不能直接創建新 Node，因為會有未知的部分。所以看了一下 hint，使用它上面的方法: `A --> A' --> B --> B' `，創建新的 node 在原本的後面 (一個 while)，然後再填入 random 值 (第二個 while)，最後再把原本的 List 復原然後把 新的 List 接上去 (三個 while `A --> B`, `A' --> B'`)。

題目 Rotate List，先用 while 紀錄 Linked List 長度，並把尾端接到第一個 Node，再使用一個 while，根據 K，把第 N-(K%N) 個元素的 next 指向 NULL。
