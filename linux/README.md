* 110學年度下學期: [Linux作業系統實務](#Linux作業系統實務)、[Linux加分題筆記](#Linux加分題筆記)

* 111學年度上學期: [伺服器架設](#伺服器架設)

  





# Linux作業系統實務

使用 Centos 作業系統，和 Visual Box 虛擬機

|               week                | content                                                      | date       |
| :-------------------------------: | :----------------------------------------------------------- | ---------- |
|   [week01](110semester02/01.md)   | [Centos7環境設定](110semester02/01.md#Centos7環境設定)<br /><ul><li>[使用Centos的好處](110semester02/01.md#使用Centos的好處)</li><li> [virtulBox安裝教學](110semester02/01.md#virtulBox安裝教學)</li></ul> | 2022/02/15 |
|   [week02](110semester02/02.md)   | [Network](110semester02/02.md#Network)<ul><li>NAT</li><li>Bridged AdapterInternal </li><li>Network</li></ul>[遠端操作](110semester02/02.md#遠端操作)<br />[export env](110semester02/02.md#export-env)<br />[Linux指令](110semester02/02.md#Linux指令)<ul><li>開關機指令</li><li>查看編輯檔案內容</li></ul> | 2022/02/22 |
|   [week03](110semester02/03.md)   | [架設簡單伺服器](110semester02/03.md#架設簡單伺服器)<br />[Linux指令](110semester02/03.md#Linux指令)<ul><li>關閉防火牆</li><li>mv、echo、cat、curl</li></ul> | 2022/03/01 |
|   [week04](110semester02/04.md)   | [Linux 發行版本](110semester02/04.md#Linux-發行版本)<br />[shell programming](110semester02/04.md#shell-programming)<br />[Linux 指令](110semester02/04.md#Linux-指令)<br /><ul><li>查看Linux 版本</li><li>查看變數</li><li>修改密碼新</li><li>增使用者</li></ul>[重制root密碼](110semester02/04.md#重制root密碼) | 2022/03/08 |
| **[week05](110semester02/05.md)** | [file system](110semester02/05.md#file-system)<br /><ul><li>[磁碟分割(hard disk partition)](110semester02/05.md#磁碟分割(hard-disk-partition))</li><li>[Linux系統載入](110semester02/05.md#Linux系統載入)[Linux指令](110semester02/05.md#Linux指令)<ul><li>ping</li><li>ifconfig</li><li>關機指令</li><li>重啟指令</li><li>系統操作指令</li></ul></li></ul> | 2022/03/15 |
|   [week06](110semester02/06.md)   | [Linux指令格式](110semester02/06.md#Linux指令格式)<br />[Linux檔案](110semester02/06.md#Linux檔案)<br />[使用遠端破解密碼](110semester02/06.md#使用遠端破解密碼)<br />[Linux指令](110semester02/06.md#Linux指令)<ul><li>顯示使用者指令</li><li>ctrl指令</li><li>`pwd; cd ~; echo; $SHELL、man`</li></ul> | 2022/03/22 |
|   [week07](110semester02/07.md)   | [specific file](110semester02/07.md#specific-file)<br />[Command](110semester02/07.md#Command)<br /><ul><li>[ls</li>](110semester02/07.md#ls)<li>[man](110semester02/07.md#man)</li><li>[tree](110semester02/07.md#tree)</li></ul>[Linux指令](110semester02/06.md#Linux指令)<ul><li>查看帳號文件</li><li>column分割指令</li><li>創建連結指令</li><li>`netstat; touch; kill; stat; ls; cp; cat; tail; head; mkdir; rmdir`</li></ul> | 2022/03/29 |
|              week08               | 放假!                                                        | 2022/04/05 |
|   [week09](110semester02/09.md)   | [切換kernal使用特定版本的功能](110semester02/09.md#切換kernal使用特定版本的功能)<br />[提權](110semester02/09.md#提權)<br />[Linux指令](110semester02/09.md#Linux指令)<ul><li>查看Linux 版本</li><li>判斷前一個指令是否成功</li><li>網路資料抓取</li><li>快速清除文件內容</li><li>`cd; sed; tail; mkdir; cat; mkdir; rmdir`</li></ul> | 2022/04/12 |
|              week10               | 期中考!                                                      | 2022/04/19 |
|   [week11](110semester02/11.md)   | [專有名詞介紹](110semester02/11.md#專有名詞介紹)<ul><li>集縮比</li><li>PT test</li><li>stacking</li></ul>[Linux指令](110semester02/11.md#Linux指令)<ul><li>檔案權限改變、查看檔案權限</li><li>改變Linux預設指令結果</li><li>查看檔案位置</li><li>查看資料使用量</li><li>stdin、stdout、stderr應用操作</li></ul> | 2022/04/26 |
|   [week12](110semester02/12.md)   | [命令管道](110semester02/12.md#命令管道)<br />[撰寫系統腳本](110semester02/12.md#撰寫系統腳本)<br />[搜尋檔案(find)](110semester02/12.md#搜尋檔案(find))<br />[增量備份](110semester02/12.md#增量備份)<br />[Linux指令](110semester02/12.md#Linux指令)<ul><li>檔案權限數字操作</li><li>清空指令輸出到螢幕上的內容</li><li>一次創建多個檔案</li></ul> | 2022/05/03 |
| **[week13](110semester02/13.md)** | [grep](110semester02/13.md#grep)<br /><ul><li>[grep參數](110semester02/13.md#grep參數)</li><li>[正規表達式規則</li>](110semester02/13.md#正規表達式規則)<li>[Linux指令](110semester02/13.md#Linux指令)</li></ul>[vim](110semester02/13.md#vim)<ul><li>[Vi 底行命令](110semester02/13.md#Vi-底行命令)</li></ul>[硬體設備](110semester02/13.md#硬體設備)<ul><li>[mount](110semester02/13.md#mount)</li><li>[Linux指令](110semester02/13.md#Linux指令)<ul><li>查看硬體設備</li><li>查看目前使用的終端信息</li></ul></li></ul> | 2022/05/10 |
| **[week14](110semester02/14.md)** | [掛載格式硬碟](110semester02/14.md#掛載格式硬碟)<br />[掛載磁碟](110semester02/14.md#掛載磁碟)<br />[群組](110semester02/14.md#群組)<br />[Shell](110semester02/14.md#Shell)<br />[Linux指令](110semester02/14.md#Linux指令)<ul><li>echo 高級使用方法</li><li>`xargs; awk`</li></ul> | 2022/05/17 |
|   [week15](110semester02/15.md)   | [使用者權限](110semester02/15.md#使用者權限)<br />[crach](110semester02/15.md#crach)<br />[Linux指令](110semester02/15.md#Linux指令)<ul><li>查看有多少使用者在線上</li><li>新增使用者</li><li>取出`/etc/passwd`文件的用戶名和系統名稱</li><li>查看、改變權限</li></ul> | 2022/05/24 |
|   [week16](110semester02/16.md)   | [process](110semester02/16.md#process)<br />[driver](110semester02/16.md#driver)<br />[Linux指令](110semester02/16.md#Linux指令)<ul><li>查看行程樹、查看記憶體和行程資訊</li><li></li><li>ps指令詳細用法、nice</li><li>`kill; pkill; job; fg; bg; sleep; !!`</li></ul> | 2022/05/31 |
|   [week17](110semester02/17.md)   | [內部指令與外部指令](110semester02/17.md#內部指令與外部指令)<br />[Linux特殊符號](110semester02/17.md#Linux特殊符號)<br />[zombie process](110semester02/17.md#zombie-process)<br />[orphan process](110semester02/17.md#orphan-process)<br />[firework](110semester02/17.md#firework)<br />[Linux指令](110semester02/17.md#Linux指令)<ul><li>`&&`  和 `||` 的應用</li><li></li><li>`set; env`</li><li>`su` vs `su-`</li></ul> | 2022/06/07 |
|              week18               | none                                                         | 2022/06/14 |





# 伺服器架設 

使用 Centos 作業系統，和 Visual Box 虛擬機

使用 Centos 作業系統，和 Visual Box 虛擬機

|                  week                   | content                                                      | date                |
| :-------------------------------------: | :----------------------------------------------------------- | ------------------- |
|      [week01](111semester01/1-.md)      | [SSH server](111semester01/1-.md#SSH-server)<br /><ul><li>set host name</li><li>no password login</li></ul> | 2022/09/05          |
|    [week02](111semester01/2-NFS.md)     | [NFS](111semester01/2-NFS.md#NFS)<ul><li>server setup</li><li>client setup </li><li>查看已安裝軟體</li></ul><br />[檔案壓縮](111semester01/2-NFS.md#檔案壓縮)<ul><li>tar</li><li>zip</li></ul><br />[設定系統時間](111semester01/2-NFS.md#設定系統時間)<br />[排程](111semester01/2-NFS.md#排程)<br />[reference](111semester01/2-NFS.md#reference) | 2022/09/12          |
|   [week03](111semester01/3-SAMBA.md)    | [SAMBA](111semester01/3-SAMBA.md#SAMBA)<ul><li>install SAMBA </li><li>edit SAMBA config</li><li>[加入使用者權限](111semester01/3-SAMBA.md#加入使用者權限)</li></ul><br />[磁碟配額設定](111semester01/3-SAMBA.md#磁碟配額設定)<ul><li>進入單人模式</li></ul> | 2022/09/19          |
|      [week04](111semester01/4-.md)      | [磁碟配額設定(續)](111semester01/4-.md#磁碟配額設定)<ul><li>set quota</li><li>set quota hard limit</li></ul><br />[套件管理](111semester01/4-.md#套件管理)<ul><li>[rpm](111semester01/4-.md#rpm)</li><li>[yum](111semester01/4-.md#yum)</li><li>進入單人模式02</li></ul> | 2022/09/26          |
|      [week05](111semester01/5-.md)      | [ngrok](111semester01/5-.md#ngrok)<ul><li>install ngrok</li><li>get certification</li><li>add ngrok config</li></ul><br />[好用的指令](111semester01/5-.md#好用的指令)<ul><li>[du](111semester01/5-.md#du)</li><li>[df](111semester01/5-.md#df)</li><li>[dd](111semester01/5-.md#dd)</li><li>[wc](111semester01/5-.md#wc)</li><li>[tr](111semester01/5-.md#tr)</li></ul><br />[error (yum lock)](111semester01/5-.md#error)<br />[reference](111semester01/5-.md#reference) | 2022/10/3           |
|    [week06](111semester01/6-國慶.md)    | 國慶日!                                                      | 2022/10/10          |
|  **[week07](111semester01/7-VPN.md)**   | [pptpd](111semester01/7-VPN.md#pptpd)<ul><li>install</li><li>setpu</li><li>set DNS server</li><li>set password and account</li><li>windows client connect</li></ul><br />[L2TP VPN](111semester01/7-VPN.md#L2TP-VPN)<ul><li>install</li><li>setpu</li><li>set PSK public key</li><li>set ppp connection</li><li>set password and account</li><li>windows client connect</li></ul><br />[好用的指令(續)](111semester01/7-VPN.md#好用的指令)<ul><li>[ssh](111semester01/7-VPN.md#ssh)</li><li>[scp](111semester01/7-VPN.md#scp)</li><li>[seq](111semester01/7-VPN.md#seq)</li><li>[sort](111semester01/7-VPN.md#sort)</li><li>[uniq](111semester01/7-VPN.md#uniq)</li><li>[cut](111semester01/7-VPN.md#cut)</li></ul><br />[error](111semester01/7-VPN.md#error)<br />[Reference](111semester01/7-VPN.md#Reference) | 2022/10/17          |
|      [week08](111semester01/8-.md)      | 放假!                                                        | 2022/10/24          |
|   [week09](111semester01/9-期中考.md)   | [期中考](111semester01/9-期中考.md#期中考)<ul><li>[crontab](111semester01/9-期中考.md#第九章)</li><li>[rpm](111semester01/9-期中考.md#第十章)</li><li>[Linux command](111semester01/9-期中考.md#十一章)</li><li>[command testing](111semester01/9-期中考.md#十二章)</li></ul> | 2022/10/31          |
|    [week10](111semester01/10-NAT.md)    | [NAT Server](111semester01/10-NAT.md#NAT-Server)<ul><li>set IP manually</li><li>set router</li><li>test with tcpdump</li></ul><br />[shell](111semester01/10-NAT.md#shell)<ul><li>string comparing</li><li>read parameters</li><li>show the certain type of file in dir</li><li>rename certain type of file</li></ul> | 2022/11/7           |
|  [week11](111semester01/11-Network.md)  | [網路指令與管理](111semester01/11-Network.md#網路指令與管理)<ul><li>network and NetworkManager</li><li>Set network config</li><li>set virtual interface</li></ul><br />[network command](111semester01/11-Network.md#常用指令)<ul><li>change MAC </li><li>set default router</li><li>ping</li></ul><br />[important port](111semester01/11-Network.md#important)<br />[read update and download speed](111semester01/11-Network.md#讀取介面卡傳送速率) | 2022/11/14          |
|     [week12](111semester01/12-.md)      | [系統服務與排程](111semester01/12-.md#系統服務與排程)<ul><li>[Unit](111semester01/12-.md#Unit)</li><li>[target](111semester01/12-.md#target)</li><li>[init_runlevel](111semester01/12-.md#init_runlevel)</li><li>[systemd_Target ](111semester01/12-.md#systemd_Target )</li><li>[systemctl](111semester01/12-.md#systemctl常用服務)</li></ul><br />[TCP/IP server](111semester01/12-.md#架設伺服器練習)<br />[Install_Talnet](111semester01/12-.md#Install_Talnet)<br />[Linux command](111semester01/12-.md#Linux指令) | 2022/11/21          |
|   **[week13](111semester01/13-.md)**    | [LAMP](111semester01/13-.md#LAMP)<ul><li>[Apache](111semester01/13-.md#Apache)</li><li>[MYSQL](111semester01/13-.md#MYSQL)</li><li>[PHP](111semester01/13-.md#PHP)</li><li>[ApacheSetup](111semester01/13-.md#ApacheSetup)</li></ul><ul><br />[Linux command](111semester01/13-.md#Linux指令) | 2022/11/28          |
|   **[week14](111semester01/14-.md)**    | [ApacheSetup(續)](111semester01/14-.md#ApacheSetup)<ul><li>[important Apache file](111semester01/14-.md#重要Apache目錄)</li><li>[virtual host](111semester01/14-.md#virtual-host)</li><li>[httpd.conf](111semester01/14-.md#httpd.conf)</li><li>[link to www/html](111semester01/14-.md#網站位置連接)</li></ul><br />[Linux command](111semester01/14-.md#Linux指令) | 2022/12/05          |
|     [week15](111semester01/15-.md)      | [virtual host(續)](111semester01/15-.md#virtual host)<br />[Access Control](111semester01/15-.md#Access-Control)<ul><li>dir security</li><li>set dir config</li></ul><br />[FTP](111semester01/15-.md#FTP)<ul><li>setup</li><li>connect with anonymous</li></ul><br />[Linux command](111semester01/15-.md#Linux指令) | 2022/12/12          |
| [week16~week18](111semester01/final.md) | [basic](111semester01/16-.md#basic)<ul><li>[network and NetworkManager](111semester01/16-.md#network-and-NetworkManager)</li><li>[SSH](111semester01/16-.md#SSH)</li><li>[FTP](111semester01/16-.md#FTP)</li><li>[SAMBA](111semester01/16-.md#SAMBA)</li><li>[NFS](111semester01/16-.md#NFS)</li><li>[talnet](111semester01/16-.md#talnet)</li><li>[TCP/IP server](111semester01/16-.md#TCP/IP-server)</li><li>[LAMP](111semester01/16-.md#LAMP)</li><li>[Apache user](111semester01/16-.md#Apache-user)</li><li>[virtual host](111semester01/16-.md#virtual-host)</li><li>[ngrok](111semester01/16-.md#ngrok)</li></ul><br />[advance](111semester01/16-.md#advance)<ul><li>[VPN](111semester01/16-.md#VPN)</li><li>[NAT](111semester01/16-.md#NAT)</li></ul> | 2022/12/19~2023/1/2 |



# Linux加分題筆記

| title                                      | content                                                      |
| ------------------------------------------ | ------------------------------------------------------------ |
| [changKernel](BonuschangeKernel)           | 切換Linux的Kernel，可以使用其他版本的功能!                   |
| [decrption .txt](Bonus/decryption_txt)     | 把被加密過的文字進行還原                                     |
| [find word in png](Bonus/find_word_in_png) | 找到藏在圖片中的文字                                         |
| [gif crack](Bonus/gif_crack)               | 抓出gif文件的文字                                            |
| [zip crack](Bonus/zip_crack)               | 破解zip壓縮檔案的密碼                                        |
| [group sort](Bonus/Group.md)               | 課本第七章習題，裡面一共三題                                 |
| [other note](Bonus/hacker.md)              | [暴力破解](Bonus/hacker.md#暴力破解)<br />[hydra](Bonus/hacker.md#hydra)<br />[Medusa](Bonus/hacker.md#Medusa)<br />[John the Ripper(JTR)](Bonus/hacker.md#John-the-Ripper(JTR))<br />[使用遠端破解密碼](Bonus/hacker.md#使用遠端破解密碼)<br />[msfconsole](Bonus/hacker.md#msfconsole)<br />[關閉防火牆和保護裝置](Bonus/hacker.md#關閉防火牆和保護裝置)<br />[破解壓縮檔案密碼](Bonus/hacker.md#破解壓縮檔案密碼)<br />[查看圖片文字](Bonus/hacker.md#查看圖片文字)<br />[else](Bonus/hacker.md#else)<ul><li>重製、修改root 密碼</li><li>修改putty 裡面的vim註釋顏色</li><li>密碼破解法</li></ul> |

