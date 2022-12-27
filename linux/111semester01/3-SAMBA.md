# SAMBA

[透過SAMBA讓CentOS與Windows共享目錄 - Joseph's blog (josephjsf2.github.io)](https://josephjsf2.github.io/linux/2019/11/01/share_centos_folder_with_windows.html)

使用SAMBA server，可以在windows存取linux資料夾



> install SAMBA 

```sh
$ yum install samba samba-client samba-common -y
```



```sh
$ cd /
$ mkdir test_samba  # 建立測試資料夾
$ chown nobody ./test_samba/  # 設定權限為nobody(設定沒有擁有者)
$ chmod 777 ./test_samba/  # 設定權限讓其他人可以寫入
$ ll ./test_samba/ -d  # 查看資料夾權限 # 需要加上 -d
```





> 編輯 SAMBA 設定主要設定檔案

// 基本上所有伺服器的設定檔案都在/etc/下面

```sh
$ vim /etc/samba/smb.conf
```



下面是設定測試文件夾的位置，並給權限

```sh
[test]  # 設定進入資料夾名稱(在windows上看到的)
        comment = for test  # 註解，標明用意
        path = /test_samba  # 測試資料夾位置(要設到root下)
        read only = no  # 可以寫入的
        guest ok = yes  # 可以給一般使用者使用
        browseable = yes  # 可以瀏覽的
```



> 測試設定的參數有沒有問題

```sh
$ testparm
```



> 啟動SAMBA

記得要把防火牆關掉才可以連線到

```sh
$ systemctl start smb
```

會使用到 445、139 port



> 查看 samba的 port

```sh
$ netstat -tunlp | grep smb
```



> 建立SAMBA 存取密碼，並加入使用者

```sh
$ smbpasswd -a user
```





-- 進入SAMBA server

然後就可以在Window上輸入windows+R，然後輸入: `\\Linux IP`，就可以存取到Linux SAMBA裡面的東西了



-- 資料夾隱藏

可以把參數的`browseable` 設定成 `No`，就可以把檔案隱藏，只要輸入`\\Linux IP\dirName`，就可以進去隱藏資料夾



-- 切換使用者

windows要切換帳號，必須要把之前的使用者清除(windows + cmd)，使用`net use * /delet`



防火牆關閉: https://github.com/stereomp3/note/blob/main/linux/110semester02/03.md#Linux%E6%8C%87%E4%BB%A4



## 加入使用者權限

```sh
$ groupadd manager  # 創建manager 群組
$ gpasswd -g user manager  # 把user 加入 manager 群組
$ id user  # 查看使用者的群組和 id
$ chmod 775 /test_samba  # 讓不是群組裡的人無法寫入
$ chown root:manager /test_samba
```

`drwxrwxr-x 3 root manager `

root : rwx

manager: rwx

others: r-x，無法寫入 !

設定配置檔案

```sh
$ vim /etc/samba/smb.conf
```



```sh
[test]  # 設定進入資料夾名稱(在windows上看到的)
        comment = for test  # 註解，標明用意
        path = /test_samba  # 測試資料夾位置(要設到root下)
        public = yes
        writeable = yes
        write list = @manager # 設定特定用戶可以寫入
        browseable = yes  # 可以瀏覽的
```

windows 清除站存密碼: `net use * /delet`



`su - user`: 可以切換使用者



課本 9-6 

# 磁碟配額設定

如果要自訂義磁碟分配(/home(5G)、/boot(500M)、/swap(分配記憶體的2被)、/(剩下的))，需要在安裝的時候告訴系統

homework ， put home directory to patition

!!! 這裡要看課本 !!!

quota: 磁碟配額。用來限制使用者的磁碟空間用量

要使用超級使用者才可以進行磁碟操作

```sh
$ vim /boot/grub/grub.config
```

修改時間，跟者課本設定參數

> 進入單人模式

```sh
$ grub2-mkconfig -o /boot/grub2/grub.config
$ reboot  # 重新啟動  # 按下e

# 找到quite，按下f10，進入單人模式，
$ vim /etc/fstab
# usrquota,grpquota   加入到default後面，根據user和group進行分類

$ mount -o remount /  # 掛載到根目錄
$ mount -a
$ cat /etc/mtab  # 檢查quota是否出現，沒有出現(/dev/sda  noquota)就要重新啟動
```



patition 一般有兩個，root和swap，(var、home是最常加入新patition的位置)
