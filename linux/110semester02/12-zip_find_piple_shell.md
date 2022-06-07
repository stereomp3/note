

## 命令管道

> 命令管道 == |

* 管道可以把一系列命令連接起來，意味著第一個命令的輸出將作為第二個命令的輸入，通過管道傳遞給第二個命令，第二個命令的輸出又將作為第三個命令的輸入，以此類推。
* e.g.  
  * `ls /etc | wc -w` : 查看etc下文件數量(一個文件名算一個單詞數)
  * `ls | grep "test"` : 把ls得到的結果丟給grep，看ls結果裡面有沒有test
  * `ifconfig ens33 | grep inet | grep -v inet6 | awk '{print $2}'`
    * `grep -v`: 不包含後面的內容
    * `awk '{print $2}'`: 把第二欄(column)的內容打印到螢幕上



並不是所有東西都可以用管道(|)傳輸，有一些需要使用額外指令才可以執行

`echo "tom" | passwd --stdin tom`





## 撰寫系統腳本

> checkuser.sh

使用`which bash`，可以查看bash的位置，裡面放的是系統腳本

```
#!/usr/bin/bash

id $1 1>/dev/null 2>&1    ## id 第一個參數 前面結果丟到黑洞
result='echo $?'   ## result存取前面的指令是否成功

if [ $result -eq 0 ]     ## result == 0 就顯示用戶存在，不等於就顯示不存在
then
	echo "$1 exists"   
else
	echo "$1 no exists"
fi
```

> usage

```
chmod +x ./checkuer.sh  ## 賦予可執行權限
./checkuser.sh user ## user exit
./checkuser.sh tom  ## tom doesn't exit
```



> getip.sh

```
#!/usr/bin/bash

ip=`ifconfig $1 | grep inet | grep -v inet6 | awk '{print $2}'`
eth=`ifconfig $1 | grep inet | grep -v inet6 | awk '{print $2}'`

echo "ip: $ip"
echo "mac: $eth"
```

> usage

```
chmod +x getip.sh
./getip.sh enp0s8  ## 輸入介面卡名稱
```



## 搜尋檔案(find)



`which`: 只找執行檔，搜尋檔案只會從環境變數($PATH)裡面找。

`whereis`: 跟which差不多，不過whereis的資訊會給比較多，比較少用

`locate`: 可以查詢任何檔案，可以使用部分名稱去做查詢，他是去索要資料庫的內容，所以在執行之前，通常會先輸入`updatedb`

`updatedb`: 讓系統資料與資料庫同步

`find`: 到磁碟裡面一個一個找，可以最任意種搜尋，提供最多功能，但也花最多時間

* [find指令詳細說明](https://blog.gtwang.org/linux/unix-linux-find-command-examples/)，find指令一定會考!!!
* `find /home -name jack`: 找到完全符合的檔案/目錄
* `find /home -iname jack`: 加入-i參數，可以讓查詢不分大小寫，在很多指令，-i 都代表這個含意
* 使用`-type d`可以指定找的檔案類型

  * `d`: 尋找目錄
  * `i`: 尋找連結檔
  * `f`: 尋找一般檔案
* `find / -type f -name "*.txt"`: 尋找目前目錄下是txt檔的文件
* `find . -type f -perm 0777`: 找尋權限全部打開的檔案
  * rwx (4+2+1=7)、rw- (4+2=6)、r-x (4+1=5)、r-- (4)、-w- (2)、--x (1)

  * 前面的0代表 `suid 、sgid 、sticky `全部沒有開(suid (4)、sgid (2)、stick(1))，代表特殊權限
    * suid: 代表在執行檔案時具有最高權限，執行完後變回原來的身分
    * sgid: 應用在一般目錄下，在具有sgid權限的目錄下，創建人和文件都屬目錄的群組
    * sticky: 代表任何人都可以對檔案進行讀寫，但刪除必須創造者才有權限
    * 上面的功能和rwx全開可以寫成`find . -type f -perm 7777`
* `find . -type d -empty -exec rm -f {} \;`: 找到所有空檔案，全部刪除，{}代表前面指令找到的文件集合，最後需要加上`;`，因為是特殊符號所以需要加上反斜槓
* `find . -type f -name "*.txt" -exec chmod 644 {} \;`: 找到所有.txt檔，更改權限
* `find . -type f -name ".*"`: 尋找隱藏檔案
* `find . -mtime +7 -mtime -14`: 修改時間7天以上14天以內
* `find . -mmin -60`: 找尋最近一小時內更改過的檔案，如果要偵測有沒有被存取過要用`-amin`
* `find . -size +100M`: 找出大於100M的檔案



cat 檔案會使檔案的Access 時間改變，可以使用`stat filename`查看



## 增量備份

> 使用參考時間的檔案，讓資料可以分成不同部分做備份

```
## a底下有3個資料夾file1、file2、file3
tar cvfz backup01.tar.gz a/*  ##把a資料夾裡面的資料壓縮(備份)
touch timebase  ##增加時間戳記
cd a
echo "1" > file1.txt
touch file4.txt
cd ..
tree a
tar -cvfz backup02.tar.gz `find . -cnewer ./timebase -type f`  ## ``裡面的內容會優先執行，值再放入裡面，也可以使用$()表示

## 解壓縮(還原)
tar -xvfz backup01.tar.gz
tar -xvfz backup02.tar.gz
```



**``裡面的內容會優先執行，值再放入裡面，也可以使用$()表示**



## Linux指令

* `ls /tmp 1>dev/null 2>&1`: 把2(錯誤並輸出到螢幕)、1(正確並輸出到螢幕)的輸出全部丟到垃圾桶，這個指令只判斷前面指令(1之前)可以正常執行還是不可以

* `echo $?`: 是否正確執行，非0代表執行錯誤

* `id user`:  查看是否有這個使用者

* `chmod -x file`: 為程式碼加上可執行權限

* `echo "tom" | passwd --stdin tom`: passwd需要使用額外指令去完成管道

* `chmod 777 filename`: 代表權限全部開啟

  * rwx (4+2+1=7)、rw- (4+2=6)、r-x (4+1=5)、r-- (4)、-w- (2)、--x (1)
  
* `ll`: 等同於`ls -l`

* `touch {a..z}.txt`: 創建a.txt，b.txt，c.txt........z.txt

* `stat`: 可以查看檔案詳細訊息，裡面有存取時間和修改時間，可以看有沒有人動過資料

* **``裡面的內容會優先執行，值再放入裡面，也可以使用$()表示**

