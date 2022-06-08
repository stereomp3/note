1. 試著建立一個完整的群組與使用者:

   |   群組 : g1    |   群組 : g2    |   群組 : g3    |
   | :------------: | :------------: | :------------: |
   | 使用者 : user1 | 使用者 : user4 | 使用者 : user7 |
   | 使用者 : user2 | 使用者 : user5 | 使用者 : user8 |
   | 使用者 : user3 | 使用者 : user6 | 使用者 : user9 |

   A:

   ```sh
   groupadd g1
   groupadd g2
   groupadd g3
   useradd -g g1 user1
   useradd -g g1 user2
   useradd -g g1 user3
   useradd -g g2 user4
   useradd -g g2 user5
   useradd -g g2 user6
   useradd -g g3 user7
   useradd -g g3 user8
   useradd -g g3 user9
   ```

   

2. 新增以下群組與使用者:

   1. 群組

      | 群組名稱 | 群組ID |
      | :------: | :----: |
      |   acc    |  950   |
      |  sales   |  990   |
      | manager  |  970   |

      A:

      ```sh
      groupadd -g 950 acc
      groupadd -g 990 sales
      groupadd -g 970 manager
      ```

      

   2. 使用者

      | 使用者名稱 | 使用者ID | 群組ID |
      | :--------: | :------: | :----: |
      |    macy    |   800    |  970   |
      |   jerry    |   801    |  970   |
      |   teresa   |   802    |  950   |
      |   julia    |   803    |  950   |
      |    boss    |   804    |  950   |

      A:

      ```sh
      useradd -g 970 -u 800 macy
      useradd -g 970 -u 801 jerry
      useradd -g 950 -u 802 teresa
      useradd -g 950 -u 803 julia
      useradd -g 950 -u 804 boss
      ```

      

   3. 設定密碼

      | 使用者 | 密碼  |
      | :----: | :---: |
      |  tom   | Py989 |
      |  jack  | Ty989 |

      A:
      
      ```sh
      useradd tom
      useradd jack
      passwd tom
      passwd jack
      ```
      
      

3. 於 `/storage/` 下建立以下目錄，並變更擁有者與擁有群組如下

|    建立目錄     |    擁有者     |
| :-------------: | :-----------: |
|  /storage/macy  | macy.manager  |
| /storage/jerry  | jerry.manager |
| /storage/teresa |  teresa.acc   |
| /storage/julia  |   julia.ass   |
|  /storage/boss  |   boss.acc    |

A:

```sh
mkdir /storage
mkdir /storage/macy
mkdir /storage/jerry
mkdir /storage/teresa
mkdir /storage/julia
mkdir /storage/boss
chown macy:manager /storage/macy
chown jerry:manager /storage/jerry
chown teresa:acc /storage/teresa
chown julia:acc /storage/julia
chown boss:acc /storage/boss
```



查看建立的Group: `cat /etc/group`

查看用戶資訊: `cat /etc/shadow`
