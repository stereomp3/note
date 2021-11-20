期中製作2D遊戲([下載遊戲](/stereomp3/note/raw/main/unity/Game/V2.0.2.rar))

遊戲概述(有些功能未完成):

玩家生命180，頭部60，身體60，尾巴60

頭

激光(Laser): 用方形，長度變長(10)

普通子彈(Bullet): 不穿透，攻擊高，面對一些敵人會擊退(50)

多重子彈(Multi): (小)，不穿透(10)

分裂彈(Split): 分裂成兩個，不穿透(30)

刀(Sword): 可以揮(80)



慢速子彈 -- 泡泡槍(Bubble): 散彈，不穿透

快速子彈 -- 狙擊槍(Sniper): 穿透快速，大

地雷(Landmine): 會爆炸



身體

Shield: 護盾



尾巴

Shift: 位移

推進器(Booster): 加速

 

    // head
    weapon_head_text.Add(0, "1. Laser");
    weapon_head_text.Add(1, "2. Bullet");
    weapon_head_text.Add(2, "3. Sword"); 
    
    // body
    weapon_body_text.Add(0, "1. Shield");
    weapon_body_text.Add(1, "2. Laser");
    weapon_body_text.Add(2, "3. Muti");
    
    // foot
    weapon_foot_text.Add(0, "1. Shift");
    weapon_foot_text.Add(1, "2. Booster");
    weapon_foot_text.Add(2, "3. Laser");

Boss

單人: 強化: 物件變大、物件變多

雙人

雙人闖關

連線遊戲





敵人:

1. 藍: HP: 20，只會衝向玩家，7秒後會自滅，攻擊10
2. 藍大: 三種型態，第一種跟藍一樣，第二種會生怪+射子彈，第三種會撞玩家+射子彈+有護頓
3. 小綠1: 負責攻擊，可以和小綠2合體
4. 小綠2: 負責防禦，可以和小綠1合體
5. 綠大: 可以召喚前面的怪物進行合體
6. 小黃1
7. 小黃2
8. 小黃3
9. 飛船: 可以召喚所有怪物，打完一波會往前，打到後面會讓船變成背景









難度描述(Difficulty)

1. Beginner
2. Easy
3. Normal
4. Hard
5. Very hard



每種武器針對不同Boss

Boss針對一種武器進行防禦

IEnumerator / StartCoroutine



配件升級(寫在sup)

* 頭部:  可以多射2條激光(時間限制久)
* 身體:  會清理周遭的敵人(轉一圈 傷害高;時間限制久)
* 腳部:  走過的地方留下子彈



```
角色生成: Script/Game/init_data_button           (stage1)
角色生成: Script/Game/s2_init_data_button        (stage2)
控制模式: Script/Canvas/controller/ButtonOnclcik
控制血條: Script/Canvas/controller/bloodController
敵人模式: Script/Game/enemy/ Enemy
控制輸入: Script/Option/inputField  && Script/Game/Bullet/JudgeInput
控制子彈: Script/Game/Bullet/Weapon
開啟敵人: Prefabs/Canvas/GameGUI
控制輔助: Script/Game/SupController
控制靜態變數(有沒有輔助，套件位置....): Script/Game/StaticController




Enemyswiter 裡面的 GameStage 關系到蠻多東西的，要注意!!
```


Bug

!! 第二關boss會無敵，不知道原因，隨從沒有尾線，static controller裡面要注意(目前放在一開始的canvas裡面)
