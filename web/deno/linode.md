> **ssh root@172.104.91.57  // 進入localhost**

* root@localhost:~# history

```
    1. ls  `列出目前資料夾下面的內容`
    2. pwd  `顯示目前資料夾位置`
    3. ls /
    4. git clone git@github.com:stereomp3/ws110a.git // 到網路上clone自己的專案到遠端電腦
    5.  ssh-keygen
    6.  cat /root/.ssh/id_rsa.pub
    7.  git clone git@github.com:stereomp3/ws110a.git
    8.  ls
    9.  curl -fsSL https://deno.land/x/install/install.sh | sh
   10.  sudo apt install unzip  // sudo是ubando裡面的高級權限指令
   11.  sudo apt update
   12. sudo apt install unzip
   13.  curl -fsSL https://deno.land/x/install/install.sh | sh 
   14.  deno  // 確認有沒有裝deno
   15.  vim ~/.bash_profile   // vim 是編輯資料夾，按l可以編輯，esc取消，shift+:，w(保存)q(離開)編輯完畢取消
   16. source ~/.bash_profile  // source 指令稿執行
   18.  history // 看之前打過的
```

> cd到clone的資料夾，然後vim編輯新增run然後用pm2執行

```
先用 sudo apt install nodejs
	sudo apt install npm 安裝好這兩個之後再裝pm2
	npm install pm2 -g
```

```
root@localhost:~/pub6# vim run1.sh
root@localhost:~/pub6# ls
app          _footer.md  README.md  run.sh       static
favicon.ico  pm2run.sh   run1.sh    _sidebar.md  web

把run1.sh變得可以直接使用: chmod +x run1.sh /*顏色會變綠*/
查看pm2run.sh的內容: cat pm2run.sh
開啟: pm2 start ./run.sh -f --cron= */30 * * * *" /*deno有時會小當機，每30分鐘重啟一次*/
關掉使用: pm2 stop ./run.sh
刪掉: pm2 delete 名字
```

* deno run -A --unstable app/app.js 80



> 把github上的東西拉回來

```
git pull git@github.com:stereomp3/ws110a.git
如果報錯 --> Your local changes to the following files would be overwritten by merge
就用
git checkout 有錯的資料夾
然後再pull一次
```

> 刪除文件

```
rm 刪除文件
rm -r 刪除資料夾
```



> 退出linode `exit`



## port useage

```
8000 放行事曆
8666 放主網頁
6020 放phaser Game
5432 postgreSQL預設port
8881 放文字遊戲
8080 放文字遊戲的websocket

```



## server安裝PostgreSQL

> https://blog.gtwang.org/linux/centos-linux-install-postgresql-database-tutorial/

```
# 安裝 PostgreSQL 伺服器
sudo yum install postgresql-server postgresql-contrib

# 初始化 PostgreSQL 資料庫
sudo postgresql-setup initdb

# 啟動 PostgreSQL 伺服器
sudo systemctl start postgresql

# 設定開機自動啟動 PostgreSQL 伺服器
sudo systemctl enable postgresql
```



建創資料夾: mkdir [資料夾名稱]
