!! 如果要在別人的分支下上傳檔案 要先clone ssh的專案 才可以!!(git clone ....)
然後再做下面

資料上傳3步驟

```
git add –A : 把所有資料加進儲存庫
git commit –m ”content” : 加一個訊息到儲存庫顯示頁面
{git commit -m "modify ???" : 可以針對???做修改，no其實是可以改上面的顯示
git commit -m "delet ???" : 先刪文件在上傳?大概}
git commit -m "add ???" : 可以r加入???到github上
git push origin master : 把所有專案推到網站上 (可能要輸入那個網站的帳密)

git clone 網址 可以將git hub 上面的專案 複製到資料夾
```

## create a new repository on the command line
```
echo "# 109-Introduction-and-Practice-of-Internet" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/stereomp3/109-Introduction-and-Practice-of-Internet.git
git push -u origin main
```

## push an existing repository from the command line
```
git remote add origin https://github.com/stereomp3/109-Introduction-and-Practice-of-Internet.git
git branch -M main
git push -u origin main
```

> echo "網址"可以跳到那個位置

## 4部重置硬體分支

```
第一步：git checkout <branch_name>
很明顯，進入那個分支。
第二步 ：git pull -s recursive -X theirs
進行遠程分支更改，並在發生衝突時將其替換。在這裡，如果您這樣做，git status您將得到類似這樣的信息，那麼您的分支將在“提交/主”之前3次提交。
第三步 ：git reset --hard origin/<branch_name>
第四步 ：git fetch
硬重置您的分支(會刪掉文件，要先備份)。

```

> 出現錯誤fatal: not a git repository 使用 : git init

> git pull origin master : 把網路上的抓下來



## 在主分支下面創建新分支

> 這個作筆記很好用

```
git remote -v  // 查看連到的遠端
git checkout -b mynote  // 新增子分支
git add -A   // 添加資料到分支(現在在mynote分支)
git commit -m "mynote init"   // 把資料發布上去
git branch    // 查看分支
git checkout master  // 切換到主分支(不可改的)
git pull origin master
git checkout mynote  // 切換到mynote分支(可改)
```



## warning: LF will be replaced by CRLF 

> **CR是carriage return的意思，也就是\r** 
> **LF是line feed的意思，也就是\n**

```
git config --global core.autocrlf true
```



> 如果出現檔案有改過就 git checkout 那個資料夾
