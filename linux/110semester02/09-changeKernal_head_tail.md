切換超級使用者要保持原本的環境變量就使用`su`，如果要使用原本root的環境變量，就使用`su -`，使用tom設定的環境變量就使用`su - tom`

Linux可以架設伺服器、營運工程也可以使用樹莓派，裡面有很多API，需要再去了解，可以使用man指令去查看參數如何使用(`man 2 open`)

## 切換kernal使用特定版本的功能

> [linux kernel官網](https://kernel.org/)，[RHEL/CentOS7編譯核心](https://www.ltsplus.com/linux/rhel-centos-7-compile-kernel)

如果linux kernel版本過高，需要gcc更高的版本編譯

> 安裝可以對kernel進行編譯的工具

```
yum update
yum install -y ncurses-devel make gcc bc bison flex elfutils-libelf-devel openssl-devel grub2
```



> 使用wget下載kernal

```
cd /usr/local/src
wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.17.12.tar.xz
```



> kernel解壓縮

```
tar -xvf linux-4.17.12.tar.xz
cd linux-4.17.12/
```



> 將目前使用的核心設定檔，複製到新版核心目錄下，並改名為 .config，這樣就可以省去很多設定步驟，針對一些新的功能再使用新設定

```
cp -v /boot/config-3.10.0-1160.59.1.el7.x86_64 /usr/local/src/linux-4.17.12/.config
```



> 執行menuconfig命令，執行完下面指令後會跳出客製化設定介面，把需要的功能打開，不要把全部都打開，會非常消耗資源

```
cd /usr/local/src/linux-4.17.12/
make menuconfig
```



> 在開始編譯前, 需要確定 /boot 有足夠的空間, 因為編譯的檔案會放在 /boot 下面, 執行以下指令開始編譯，這邊會消耗很多時間

```
make bzImage 
make modules
make
make modules_install  ## 這個要比 make install 先執行
make install
```



> 編譯完成後, 執行以下指令更新 GRUB:

```
grub2-mkconfig -o /boot/grub2/grub.cfg
```



> 如果是 UEFI 系統, 需要執行以下指令:

```
grub2-mkconfig -o /boot/efi/EFI/centos/grub.cfg
```



> 完成後重啟作業系統



## 提權

有一些kernel會有嚴重的版本漏洞(像是一般使用者可以提權到超級使用者)



> 創建一個user -- tom

```
adduser tom
psswd tom
```



> 並不是所有使用者都可以切換到超級使用者，下面的指令可以看自己可不可以變成超級使用者，並看自己可以使用哪些超級使用者指令，看到ALL就是全部可以執行

```
sudo -l
```



linux常見的支援檔案類型: ext2、ext3、ext4、xta、xfs

不同的file system會有不同的特色

EXT2是傳送的file system

EXT3機器有些會有日誌功能，可以節省電腦掃描整顆硬碟所耗費的時間()

EXT4可以寫入更大的檔案，會盡量把檔案寫在一起，相容EX3

CentOS 7 使用的是最新的XFS系統，在大型檔案傳輸有優勢

檔案記錄檔inode(matadate; 用來描述資料的資料)可以為資料存放庫上一個安全保障，讓使用者不能隨意存取硬碟，必須先看inode有沒有通過



## Linux指令

* `uname -r`: 查看目前使用kernal version
* `wget url`: 直接從網路上下載檔案
* `cd -`: 返回上一個資料夾
* `cd ~`: 回到自己的家目錄，~可加可不加
* `echo $?`: 判斷前面的指令是否執行成功，出現0代表成功
* `cat -n /etc/passwd | head -n 10 | tail -n 6`: 查看etc/passwd裡面5到10筆資料
  * `cat -n` :  -n可以顯示行數
  * `head -n 10`: 查看前面10筆資料
  * `tail -n 5` 查看最後5筆資料
* `sed -n "5, 10p"`: 取5到10筆資料，p代表print
* `tail -f a.txt`: 檔案有變動，立即顯示，f代表follow
* `> a.txt`: 清除文件裡面的內容，>會取代掉檔案所有內容，>>會追加內容
* `mkdir -p a`: 如果沒有資料夾，就創建文件，如果已經有資料夾，不會報錯
* `mkdir -p aa/bb/cc/dd`: 創建資料夾可以創建多層
* `cat <<EOF > a.txt`: 可以直接輸入文字到a.txt裡面
  * `<<EOF`代表是開頭，使用EOF代表輸入結束，也可以使用<<aaa，aaa結束
  * `>`表示把內容填入a.txt



核心的編譯當作加分題!!!!