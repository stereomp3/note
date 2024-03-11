# LinkedList

20240311

> Singly Linked List

題目 Design Linked List，使用 vector 做 list，好像有點犯規，使用 insert、erase 功能完成 list 的操作，沒有用到 next。最佳解建立一個 Node class，裡面有 val 和 *next、以及 Node constructor `Node(int x) { val=x; next=nullptr;}`，裡面有使用 new 動態呼叫 Node，所以要使用 delete 再刪除掉創建好的 Node，還有 destructor ~ 把 Node 清除乾淨。



>  Two Pointer Technique

題目 Linked List Cycle，使用兩個 pointer，一個快(前進兩步)，一個慢(前進一步)，當兩個 point 相遇就代表是循環 Linked List，如果 快的走到 NULL，就代表沒有循環。

題目 Linked List Cycle II，使用 unordered_set，紀錄 Node，如果有重複就 return 那個 Node。最佳解使用 slow 和 fast ，fast(a + b + c + d) 是 slow(a + b) 的兩倍，所以剛好最後可以使用 head 和 slow 碰面 (a = c) 讓 head 變成最後 重複位置的 Node

題目

題目



> Classic Problems

題目 

題目 

題目 

題目 



> Doubly Linked List

題目



> Conclusion

題目

題目

題目 

題目 

題目 

題目 
