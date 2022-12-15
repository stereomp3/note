課本第十三章

# 網路指令與管理

CentOS提供了兩種網路設定模式，只能存在一種模式，一種開，另一種就要關，預設模式是NetworkManager

NetworkManager: 適合動態環境，自動設定

network: 適合動態環境，手動設定，比較仔細

下面講解network的部分



```sh
ifconfig enp03  # 只顯示enp0s3介面卡資訊
systemctl status NetworkManager   # 查看有沒有在用NetworkManager
systemctl status network   # 查看有沒有在用network
systemctl stop NetworkManager
systemctl disable NetworkManager
systemctl start network   # 如果還沒有設定 status 會顯示fail
systemctl enable network


```



centos 網路手動設定位置在: `/etc/sysconfig/network-scripts/`

每個設定檔都是使用 `ifcfg` 做開頭，然後後面設介面卡名稱: `ifcfg-enp0s3`

```sh
cd /etc/sysconfig/network-scripts/

```



下面是sample file，可以按照下面的設定去設網路介面

## 下面的設定可以放到另外一個文件!!!

```sh
[root@example ~]# cat /etc/sysconfig/network-scripts/ifcfg-eth0
DEVICE="eth0"
BOOTPROTO=dhcp
NM_CONTROLLED="no"
PERSISTENT_DHCLIENT=1
ONBOOT="yes"
TYPE=Ethernet
DEFROUTE=yes
PEERDNS=yes
PEERROUTES=yes
IPV4_FAILURE_FATAL=yes
IPV6INIT=yes
IPV6_AUTOCONF=yes
IPV6_DEFROUTE=yes
IPV6_PEERDNS=yes
IPV6_PEERROUTES=yes
IPV6_FAILURE_FATAL=no
NAME="eth0"
[username@hostname]$ cat /etc/sysconfig/network-scripts/ifcfg-eth0
DEVICE="eth0"
HWADDR="00:21:70:10:7E:CD"
NM_CONTROLLED="no"
ONBOOT="yes"
BOOTPROTO=static
# BOOTPROTO=dhcp
IPADDR=10.16.1.106
NETMASK=255.255.255.0
#
# GATEWAY 有時會放在：/etc/sysconfig/network
GATEWAY=10.16.1.1
```



> Centos7 network default

```sh
TYPE=Ethernet
PROXY_METHOD=none
BROWSER_ONLY=no
BOOTPROTO=dhcp
DEFROUTE=yes
IPV4_FAILURE_FATAL=no
IPV6INIT=yes
IPV6_AUTOCONF=yes
IPV6_DEFROUTE=yes
IPV6_FAILURE_FATAL=no
IPV6_ADDR_GEN_MODE=stable-privacy
NAME=enp0s3
UUID=42e70816-ea62-4c55-8319-9c7bb8f68c97
DEVICE=enp0s3
ONBOOT=no
```



> 自己設定網路，DNS設定在別的地方`/etc/resolv.conf`

```sh
ip route show  # 查詢內定路由器(GateWay)
netstat -rn  # 顯示內定路由器  # 0.0.0.0 就是預設路由器的位置
```



```sh
DEVICE="enp0s3"  # 網路卡名稱 
NAME="enp0s3"
HARDWARE="08:00:27:7e:1b:3f"  #  ether 的內容
ONBOOT=yes  # 開機是否啟動  使用: yes
BOOTPROTO=static  # 是否使用DHCP 使用: yes，不用: static
IPADDR="192.168.157.??"   # 設定IP，要在同個區域網路內 inet
NETMASK=255.255.255.0
GATWAY=192.168.157.2
```



```
systemctl restart network
```



> setting

```sh
DEVICE="enp0s3" 
NAME="enp0s3"
HARDWARE="08:00:27:7e:1b:3f" 
ONBOOT=yes 
BOOTPROTO=static
IPADDR=10.0.2.100   
NETMASK=255.255.255.0
GATWAY=10.0.2.2
```



如果失敗，就刪掉有Wired的，或是其他enp系列的



手動設定IP虛擬介面(多新增一個IP位置)

ens33:10，:代表虛擬介面(virtual interface)對應出來是ens33，可以由ens33衍生出虛擬介面ens33:10，可以多一個介面位置

```sh
$ ifconfig enp0s3:10 192.168.157.250 netmask 255.255.255.0
$ ip addr show enp0s3 # 需要使用這個才能看到設定的虛擬介面ifconfig看不到
```



```sh
$ ifconfig enp0s3:10 0  # 移除虛擬介面
```



`ifconfig`: 這是一個比較舊指令，下面示範新的指令，可以不用虛擬介面新增IP，可以直接在介面卡上新增IP，讓其他VM可以連到

brd是代表IP位置支援廣播

```sh
$ ip addr add 192.168.157.250/24 brd + dev enp0s3
$ ip addr show enp0s3  # ip addr 顯示全不介面
$ ip addr del 192.168.157.250/24 brd + dev enp0s3
```



-- 常用指令

Linux可以變成，交換機(switch)，路由器(router)....，所以有時候需要暫時關閉介面(系統維護)，下面介紹這些指令

```sh
ifconfig enp0s3 down   # 暫時關閉介面，ifconfig會隱藏這個介面
ifconfig -a enp0s3  # -a 代表 ALL，可以看到所有介面(包括隱藏介面)
ifconfig enp0s3 up   # 開啟介面
```



改變網路卡卡號。

網路卡卡號在開機時註冊到電腦裡面，所以卡號會記錄在一個file裡面，下面的指令是修改裡面的值

```sh
ifconfig enp0s3 hw ether 00:01:02:03:04:05
```



傳送指定大小封包 

```
ping -s 1200 8.8.8.8
```

mtu是一次可接收的大小，可以使用下面的指令設定，大的封包會被切成大約500多分送

在無線網路有時候會使用到，因為無線網路干擾比較多，所以小的封包比較容易穿透

```
ifconfig ens33 mtu 500
```



設定內定路由器

```sh
ip route add default via 192.168.157.2  
```



顯示介卡統計資料

```sh
ip -s link show enp0s3  # 顯示介卡統計資料
```





Linux ping

```sh
ping -c 1 # 送多少封包
ping -i 0.01  # 多少秒送一次封包
ping -I enp0s3  # 使用哪個介面(interface) 傳送封包
ping -Q  # 設定header，區分不同資料流，測試會用到
ping -t  # 設定ttl(time to life)
ping -s  # 設定一次傳送多少
ping traceroute  # 查看路由
# 查看路由表，現在很多都不會回報(不支援ICMP)，所以會顯示*
# 所以這個指令現在比較少用
traceroute 8.8.8.8 
```



查看電腦連線數量

```sh
netstat -tunp | grep ESTABLISHED | wc -l
netstat -tunp | grep 22 | grep ESTABLISHED | wc -l  # 針對 SSH 連線顯示
```



windows 查看電腦連線數量，但無法統計

```sh
netstat -an | findstr EStABLISHED
```







## important

DNS: `/etc/resolv.conf`

Network: `/etc`

一個IP，可以連接多個介面卡，用在**Network Bonding**，主要用在容錯(fault tolerance)和附載均衡(Load Balance)



**檢查伺服器有沒有開啟**

```sh
natstat -tunlp | grep 80 # 查看http server，如果沒有顯示就代表沒有開 80 port
natstat -tunlp | grep 22 # t:tcp u:udp n:not resolve l:listen p:process id
```

如果沒有寫n，就會寫解析結果(像是22就會寫成ssh)

process id 會寫在Listen後面



常用的port: http://163.30.84.1/admin/ports.htm

| port | protocol  |
| ---- | --------- |
| 21   | FTP       |
| 22   | SSH       |
| 23   | Telnet    |
| 25   | SMTP      |
| 53   | DNS       |
| 80   | HTTP      |
| 443  | HTTPS TCP |



## 讀取介面卡傳送速率(腳本加分題)

https://linux.vbird.org/linux_server/centos6/0140networkcommand.php

https://www.cnblogs.com/klb561/articles/9080151.html

https://gist.github.com/joemiller/4069513

https://blog.gtwang.org/linux/linux-grep-command-tutorial-examples/

```sh
ip -s link show enp0s3  # 顯示介卡統計資料
```

```
RX：網路由啟動到目前為止的封包接收情況
TX：與 RX 相反，為網路由啟動到目前為止的傳送情況
TX是發送數據（Transport），RX是接收數據（Receive）。
```



抓取enp0s3的RX和TX

```
cat /proc/net/dev | grep enp0s3 | sed 's/:/ /g' | awk '{print $2}'
cat /proc/net/dev | grep enp0s3 | sed 's/:/ /g' | awk '{print $10}'
```





```sh
#!/bin/bash

if [ -z "$1" ]; then
        echo
        echo usage: $0 network-interface
        echo
        echo e.g. $0 enp0s3
        echo
        exit
fi

pre_RX=$(ip -s link show enp0s3 | grep -A 1 RX | awk '{print $1}' | grep -v RX)
pre_TX=$(ip -s link show enp0s3 | grep -A 1 TX | awk '{print $1}' | grep -v TX)
pre_TIME=$(date +%M:%S)
ping -c 2 8.8.8.8 1> /dev/null
next_RX=$(ip -s link show enp0s3 | grep -A 1 RX | awk '{print $1}' | grep -v RX)
next_TX=$(ip -s link show enp0s3 | grep -A 1 TX | awk '{print $1}' | grep -v TX)
next_TIME=$(date +%M:%S)

timeStep=$(($next_TIME - $pre_TIME))

TXBPS=`expr (${next_TX} - ${pre_TX})/${timeStep}`
RXBPS=`expr (${pre_TX} - ${pre_RX})/${timeStep}`
TXKBPS=`expr ${TXBPS} / 1024`
RXKBPS=`expr ${RXBPS} / 1024`
echo "TX $1: $TKBPS kB/s RX $1: $RKBPS kB/s"

```



```sh
#!/bin/bash

if [ -z "$1" ]; then
        echo
        echo usage: $0 network-interface
        echo
        echo e.g. $0 enp0s3
        echo
        exit
fi

pre_RX=$(ip -s link show $1 | grep -A 1 RX | awk '{print $1}' | grep -v RX)
pre_TX=$(ip -s link show $1 | grep -A 1 TX | awk '{print $1}' | grep -v TX)
pre_TIME=$(date +%s)
ping -c 2 8.8.8.8 1> /dev/null
next_RX=$(ip -s link show $1 | grep -A 1 RX | awk '{print $1}' | grep -v RX)
next_TX=$(ip -s link show $1 | grep -A 1 TX | awk '{print $1}' | grep -v TX)
next_TIME=$(date +%s)
timeStep=$(($next_TIME - $pre_TIME))

RXBPS=$((($next_RX - $pre_RX)/$timeStep))
TXBPS=$((($next_TX - $pre_TX)/$timeStep))

echo "接收速度: $RXBPS Bytes/second, 傳送速度: $TXBPS Bytes/second"
```





```sh
# 多顯示後一行
grep -A 1 Ubuntu /etc/os-release
```

