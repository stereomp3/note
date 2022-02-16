# 109-Introduction-and-Practice-of-Internet
| 欄位       |                            內容                             |
| ---------- | ---------------------------------------------------------- |
| 學期       |                        109 ~ 110學年                         |
| 學生       | [魏仲彥](https://stereomp3.github.io/wp109b/homework/MyWeb6.0/MyWeb.html) |
| 學號末兩碼 |                              41                              |
| 教師       |     [柯志亨](http://csie.nqu.edu.tw/smallko/index.html)      |
| 學校科系   | [金門大學資訊工程系](https://www.nqu.edu.tw/educsie/index.php) |

<hr>



## 網路基本介紹

> 筆記網址: 
>
> * https://github.com/stereomp3/note/tree/main/network/basic
>
> * https://github.com/stereomp3/note/tree/main/network/network



| NOTE                                          | CONTENT                                                      |
| :-------------------------------------------- | :----------------------------------------------------------- |
| [網路初探](basic/網路初探.md)                 | [網路類型介紹](basic/網路初探.md#網路類型)<br />[網路演進](basic/網路初探.md#網路演進)<br />[網路拓樸](basic/網路初探.md#網路拓樸(Topology))<br />[網路作業環境&OSI參考型](basic/網路初探.md#網路作業環境&OSI參考型)<br />[補充](basic/網路初探.md#補充介紹) |
| [傳輸媒介和設備](basic/傳輸媒介和設備.md)     | [網路傳輸媒介](basic/傳輸媒介和設備.md#網路傳輸媒介)<br />[網路傳輸設備](basic/傳輸媒介和設備.md#網路傳輸設備) |
| [基本通訊概念](basic/基本通訊概念.md)         | [簡介](basic/基本通訊概念.md#簡介)<br />[調變(Modulation)處理](basic/基本通訊概念.md#調變(Modulation)處理)<br />[編碼(Encoding)處理](basic/基本通訊概念.md#編碼(Encodeing)處理)<br />[多工處理](basic/基本通訊概念.md#多工處理)<br />[通訊交換方式](basic/基本通訊概念.md#通訊交換方式) |
| [通訊協定介紹](basic/通訊協定介紹.md)         | [協定的制定](basic/通訊協定介紹.md#協定的制定)<br />[OSI參考模型](basic/通訊協定介紹.md#OSI參考模型)<br />[網路重要圖片](basic/通訊協定介紹.md#網路關係重要圖片) |
| [區域網路加設簡介](basic/區域網路加設簡介.md) | [乙太網路(Ethernet; 802.3)簡介&架設](basic/區域網路加設簡介.md#乙太網路(Ethernet; 802.3)簡介&架設)<br />[無線網路(Wireless network; 802.11)簡介&架設](basic/區域網路加設簡介.md#無線網路(Wireless network; 802.11)簡介&架設)<br />[補充](basic/區域網路加設簡介.md#補充) |
| [區域網路原理](network/區域網路原理.md)       | [簡介](network/區域網路原理.md#簡介)<br />[乙太網路(Ethernet; 802.3)協定](network/區域網路原理.md#乙太網路(Ethernet; 802.3)協定)<br />[無限區域(Wi-Fi; 802.11)網路協定](network/區域網路原理.md#無限區域(Wi-Fi; 802.11)網路協定) |
| [網路切割與合併](network/網路切割與合併.md)   | [IPv4](network/網路切割與合併.md#IPv4)<br />[Address](network/網路切割與合併.md#Adress)<br />[網路切割與合併](network/網路切割與合併.md#網路切割與合併)<br />[補充](network/網路切割與合併.md#補充) |
| [DNS、網路傳輸](network/DNS、網路傳輸.md)     | [NAT](network/DNS、網路傳輸.md#NAT (**N**etwork **A**ddress **T**ranslation))<br />[DNS](network/DNS、網路傳輸.md#DNS (domain name system))<br />[DNS Server](network/DNS、網路傳輸.md#DNS(Domain Name Server))<br />[DNS、網路傳輸](network/DNS、網路傳輸.md#)<br />[補充](network/DNS、網路傳輸.md#補充) |
| [網路安全](network/網路安全.md)               | [網路安全](network/網路安全.md#網路安全)<br />[encryption](network/網路安全.md#encryption)<br />[hash function](network/網路安全.md#hash function)<br />[Authentication](network/網路安全.md#Authentication)<br />[入侵偵測系統(IDS)](network/網路安全.md#入侵偵測系統(IDS))<br />[FireWall](network/網路安全.md#FireWall)<br />[駭客入侵手段](network/網路安全.md#駭客入侵手段)<br />[補充](network/網路安全.md#補充) |
| [Routing](network/Routing.md)                 | [尋徑協定](network/Routing.md#尋徑協定)<br />[補充](network/Routing.md#補充) |





## 通訊協定介紹

> 筆記網址: 
>
> * https://github.com/stereomp3/note/tree/main/network/protocol



| NOTE                         | CONTENT                                                      |
| :--------------------------- | :----------------------------------------------------------- |
| [Layer2](protocol/Layer2.md) | [IP封包介紹](protocol/Layer2.md#IP封包)<br /><ul> <li><a src="./protocol/Layer2.md#DS(Differentiated Service; 差異服務)">DS</a></li> <li><a src="protocol/Layer2.md#TL(total Length; 16bit): 封包總長度">TL</a></li><li><a src="protocol/Layer2.md#fragmentation & Ressemably(分割與重組)">fragmentation & Reassembly</a></li><li><a src="protocol/Layer2.md#TTL(Time to Live; 8bit): 存活時間 Hop count">TTL</a></li><li><a src="protocol/Layer2.md#PROT(Protocol; 8bit): 網路協定">PROT</a></li><li><a src="protocol/Layer2.md#DS(Differentiated Service; 差異服務)">DS</a>[HC](protocol/Layer2.md#HC(Header Checcksum; 16bit): 檢查標頭碼)</li><li></li><li><a src="protocol/Layer2.md#DS(Differentiated Service; 差異服務)">DS</a>[SA](protocol/Layer2.md#SA(Source IP Address; 32bit): 來源端IP位置)</li><li><a src="protocol/Layer2.md#DA(Destination IP Address; 32 bit): 目的端位置">DA</a></li><li><a src="protocol/Layer2.md#OPT(Option; 長度不定): 選擇項">OPT</a></li></ul> |
| [Layer3](protocol/Layer3.md) | * 1 <br />* 2<br />* 3<br />                                 |

