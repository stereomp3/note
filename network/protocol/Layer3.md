# 傳輸層



## TCP

* 提供reliable的傳輸服務
* 比UDP複雜的標頭格式和定義



### TCP 重要觀念

> * TCP協定序列號碼(Sequence Number)
>
> 每一個封包，一個序號，序號會越來越大

```
Sender                                       Reciver

6、5、4、3、2、1    --------------------->           1

				          ack (收到1之後)
6、5、4、3、2	   <---------------------		
                  

實際上都是傳送封包，資料量很大，所以用資料第一個數字當作序號，確認封包有沒有送到
```



> * 滑動視窗(Sliding Windows)
>
> 用來流量控制(flow-control)，不能讓資料傳送太快

```
等待ack傳過來才傳送下一個檔案，1、2 --> 2、3 --> 3、4....
```



### TCP傳輸

> TCP建立連線的方式: 三向交握(three-way handshake)

```
TCP 是連線導向的協定

three-way handshake  // 建立連線
A ---syn--- B
B ---syn Ack---A     // Ack是確認前面的事情
A ---Ack--- B


close the connection half-close   // 關閉連線
A ---FIN--- B
B ---Ack--- A
    .....          // B可以傳，A不可傳
B ---FIN---A
A ---Ack---B       // 傳輸停止
```

* FTP傳輸是藉由TCP協定傳輸 21port負責控制動作，20 port 負責傳輸資料(要data才會開)
* Wireshark 可以在上面設定filter，像是` ip.dst==192.168.60.15 or ip.src==192.168.60.15`，把封包限定在範圍裡面



## UDP

```
| 來源port (16) | 目的port (16)|
| 訊息長度 (16) |  檢驗和 (16)  |
|       資料內容(payload)      |

1. Source Port
2. Destination Port
3. Length: 紀錄標頭長度
4. Checksun: 判斷傳輸是否正確
```



## port

| port number | function                     |
| ----------- | ---------------------------- |
| 0~1023      | Well-known(公認) Port Number |
| 1024~49151  | Registered(註冊) Port Number |
| 49152~65535 | Dynamic(動態) Port Number    |





## TCP/IP

> TCP協定的複雜度比UDP要高的多(因為TCP的reliable)
>
> TCP沒有option時，也是20個bytes

```
   6+6+2     20   20                                       4      8       bytese
| Ethernet | IP | TCP | Application data(user) |         | FPS || UDP |
		   |    MTU  1500byes                  |
		              |    MSS  1460byes       |
		   
// MTU(Maximum Transmission Unit)  1500
// MSS(Maximum Segment Size)       1460

上面兩個都講同樣的事，就是最長大小，只是不同角度去看
```

> Port很重要，如果要使用網路時，port可以知道電腦有使用那些協定(可以看課本的常用port(9-6))
>
> 常用port:  FTP(20(有資料傳輸才開)、21(控制))、SSH(22)、Telnet(23)、DNS(53)、DHCP(67)、HTTPs(443)、TCP(445)



### TCP/IP 標頭格式

```
|      Source Port Number(16)    |  Destination Port Number(16) |
|                      Sequence Number(32)                      |
|                    Acknowledge Number(ACK; 32)                |
| HLEN(4) | 0000 |C|E|U|A|P|R|S|F|         Windows(16)          | 
|       Checksum(16)             |     Urgent Pointer(16)       |
|            Options             |              padding         |
```

> 駭客可以針對標頭裡面的E去攻擊，讓網路誤以為現在資料傳輸過多，而降速



* Sequence Number

  * 紀錄序號，確保封包的可靠性

    

* ACK(Acknowledgement Number; 回應號碼: 32 bit) 很重要，代表兩個意思

  1.  這之前的資料都確實收到(序號之前)
  2.  下一次送過來的序號是ACK號碼



* HLEN(Header Length; 標頭長度: 4bit): 

  * 如果沒有選擇向 --> HLEN == 5，如果沒有OPT，TCP標頭也是20bytes

  

* Reserved(保留位元; 4bit)

  * 原本是6bit，現在剩4bit



> TCP不會馬上把東西送到應用層，會先進入緩衝區，先放到暫存區，到時候一次送出

* Control Flag --> |C|E|U|A|P|R|S|F|   ( 8bit

  * E --> ENC (用在網路塞車)

  * R --> Reset (如果ACK和seq對不上(傳輸資料奇怪，可能發生不明錯誤)，就會重新建立連線)

  * U -->  Urgent (如果設置這個，可以讓資料馬上丟到應用層)

  * A --> Acknowledgement (一般都設置為1，表示封包帶有回應確認訊息)

  * P --> Push (跟U很像，不過這個還會在緩衝區，只是被推到前面)

  * S --> Syn  (用在3向交握)

  * F --> Fin  (用在TCP連線終止(單向))

    

* Window(訊窗; 16bit): 

  * 調整一次送的資料大小(調整緩衝區的大小)，如果網路塞車，ECN會讓window變小



* Checksum(檢驗和; 16bit)
  * UDP不一定要檢查，但TCP一定要檢查



* Urgent Point(緊急值標; 16bit): U有設置就會觸發

* Option(選擇向; 32bit)

* padding --> 讓封包變成4的整數倍





### router

```
     A                      路由器可以連接輛個不同網域                     B
192.168.0.1/24    192.168.0.254/24--router--192.168.5.254/24     192.168.5.1
					    可以改變網路遮罩，讓連接網域位置範圍變大
					    
```

![](..\picture\Router.png)





## Attack

> syn Attack: 把伺服器端的記憶體耗光，一直送syn去server，然後不回ATK，伺服器就會卡資源，這是一種DOS。這是早期的方法，現在沒甚麼用。可以使用hping3去做攻擊



> Denial of Service(DOS): 把伺服器流量撐爆，讓一般使用者不能用





# 下面都在網路層

> ARP 沒有在IP後面，ICMP在IP後面



## ARP(Adress Resolution Protocal)

> 在同一個區域網路，可以直接問網路卡卡號，用 "自己" 的 IP，拿  "別人" 的網路卡號
>
> 在不同區域網路，就要問內定路由器(Default Router)的網路卡卡號

```
| ethernet | ARP |     0806 --> ARP   0800 --> IP     0835 --> RARP

| ARP Request(廣播)  | ARP Reply(得到訊息回來) |
```

> ARP Reply回來之後，資料會放在ARP Cache裡面，之後就不用每次都廣播了

* ARP很容易被駭客攻擊，駭客會把錯誤資料丟到ARP Reply裡面。
* **Gratutious ARP** (免費的ARP) 在設定IP(DHCP)之前，系統會發送這個Gratutious ARP，他的功用是不要讓同一個區域網路裡面的IP重複，在設定IP之前，會先廣播讓區域網路的電腦知道，如果IP位置是一樣的，電腦會做回應，Gratutious ARP知道了就會切換到另外一個IP



* 在IPv6，ARP的功能被併入到裡面，因為IPv6沒有廣播



> 查詢ARP Cache:  window --> arp -a，  linux --> arp -n
>
> ARP最好是自己寫，使用靜態的方式，去新增要使用的項目，比較不會被中間人攻擊(user -- hack -- server)
>
> EX: arp -s 157.55.85.212   00-aa-00-62-c6-09



> RARP(Reversed Adress Resolution Protocal; 已過時) 是 ARP的反向操作，用 "自己" MAC去server拿 "自己" IP (之前沒有硬碟(貴))，現在已經被取代(DHCP....)





## ICMP

> 處理封包錯誤，查詢工作，ping指令就是用這個完成的

```
| ethernet | IP | ICMP |   
 --> | ethernet | 0800 | IP .... PROT = 1 ... | ICMP
```

* linux 指令:  netstat -tunlp | grep 22 //tcp udp listen proccess l ssh port = 22

* 可以從 特徵值，行為表現，看出hacker，或是用在加密資料



9-7 ~ 10~4



## ARP

> 設計原理，知道對方第三層(network layer)，取得第二層(physical layer)，在網路戰爭時代發展的產物

> ARP 和 RARP 標頭定義相同，如下

```
|   Haedware Type(16)   |      Protocol Type(16)          |
|   HLEN(8)   |   PLEN(8)   |        Operation(16)        |
|                       Sender HA (48 or Other)                       |  // layer 3
|               Sender LP(32 or Other)                    |
|                       Target HA (48 or Other)                       |  // layer 2
|               Sender LP(32 or Other)                    |

```



* Haedware Type: 硬體類型(硬體類型是ethernet值就是1  `(0001(16))`)
* Protocal: 協定類型(如果欄位是 `0800(16)`  代表使用IPv4進行定址  )
* HLEN: 硬體位置長度(跟IP和TCP不一樣，這裡是用位元組作單位計算，適用於任何網路)
* PLEN: 協定位置長度(這裡也是用位元組作單位計算，適用於任何網路，計算協定網路位置長度)

* Operation: 選擇操作類型(ARP request:1, ARP responce:4, RARP request:2, RARP responce:3)



> 0000代表的含意

```
in protocal 0000  --> 還沒找到位置
in network 0.0.0.0  --> 任意介面的IP位置(1.2.3.4，168.255.0.1....)
```





## ICMP

> 處理封包錯誤，查詢工作，ping指令就是用這個完成的
>
> 無法單獨存在，需要有IP header

```
| ethernet | IP | ICMP | ICMP Message | 

# 查詢訊息標頭:
| 類型(8) | 代碼(8) | checkSum(16) |
|   識別碼(16)  |      序列碼(16)   |
|   內容資料(與類型和內容代碼相關)    |

識別碼和序列碼主要是記位置，知道是第幾次請求，是誰請求


# 錯誤訊息標頭:
| 類型(8) | 代碼(8) | checkSum(16) |  
|        未定義或其他 (32)          |
|      IP標頭+64位元的原始資料       |
```

* ICMP Message
  * 0(echo reply) 和 8(echo request)用在ping上面
  * 傳送多種錯誤

* Redirect(Type 5): 可以重新路由，找到花時間最短的路









## 補充

> * 儲存資料傳輸:  windows下用網路磁碟機，linux用NFS(network file system) ，如果要windows和linux互相傳資料，要用samba

> * 通常Server port是固定的，Client port是不固定的，但有例外: DHCP(port67)



> IPv6取得位置: 
>
> 1. 用DHCPv6自動取得位置
> 2. 用自己的MAC adr和一組亂碼組成(會用到訊息功能的15)



> 追蹤IP狀態

 * window: tracert   (tracert 8.8.8.8)  // 從這個網域到google伺服器會經過那些地方

 * linux: traceroute 
