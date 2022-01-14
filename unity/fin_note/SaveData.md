參考影片: https://www.youtube.com/watch?v=mKhetIXa7KA

## unity存檔與讀取檔案形式:

* 資料形式
  1. 直接儲存數據
  2. 序列化(把物件變成一串資料) - Binary、Xml、Json
  3. 自訂一序列化格式

* 儲存方式(最好加密，提升安全性):
  1. PlayerPref
  2. 外部檔案
  3. 連線儲存(存在Server上面)



#### 序列化使用: 將物件變成文件資料

> 序列化通常用在電腦之間的傳輸，電腦傳輸資料，所以物件要先變成資料才能傳遞

```c#
[System.Serializable]
public class PlayerData
{
	public string name;
	public int level;
}
```

* 序列化可以變成3種形式:
  1. Binary
     * 優點: 不容易被竄改
     * 缺點: 不容易維護
  2. Xml
     * 優點: 容易維護
     * 缺點: 體積比較大(多了敘述資料)
  3. Json
     * 優點: 體積小，使用起來也最方便
* 序列化完後，要反序列化還原資料



#### 儲存方式 - PlayerPref

> player preference(玩家偏好設定)，支援資料型態: int、string、float
>
> PlayerPref會儲存在註冊表，可以在官方網站看到存在哪裡，可以更改檔案，所以建議加密

```c#
using UnityEngine.UI;

public class SaveData : MonoBehaviour
{
    [SerializeField] // 顯示資料
    Text ui_text;
    [SerializeField]  // 創建data在編輯器中編輯
    PlayerData data;
    
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Z)) // 儲存
        {
            // PlayerPrefs.SetString(string key, string value)
            // PlayerPrefs.SetInt(string key, int value)
            PlayerPrefs.SetString("name", data.name)
            PlayerPrefs.SetInt("level", data.level)
            ui_text.text = "儲存完成";
        }
        if(Input.GetKeyDown(KeyCode.L)) // 載入
        {
            data.name = GetString("name")
            data.level = GetInt("level")
            // ui_text.text = PlayerPrefs.GetString("name"); // 取出值，把他放入到文字中
        }
    }
    
    [System.Serializable]
    public class PlayerData
    {
        public string name;
        public int level;
    }
}
```



#### 儲存方式 - 外部檔案

> 使用C#的FileSteam/File來做檔案的建創與讀取
>
> 常用路徑: Application.dataPath、Application.persistentDataPath
>
> 上面的也可以去官方網站看，一樣是不同平台不同路徑，像是Application.persistentDataPath會把資料存在:
>
> /User/UserName/AppData/LocalLow/CompamyName/AppName的資料夾底下，遊戲刪了資料還在

```c#
using UnityEngine.UI;
using System.IO; // 需要這個
using System;
using System.Text;

public class SaveData : MonoBehaviour
{
    [SerializeField] // 顯示資料
    Text ui_text;
    [SerializeField]  // 創建data在編輯器中編輯
    PlayerData data;
    
    void Start()
    {
        
    }
    
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Z)) // 儲存
        {
            // filestream是對檔案進行一次一次的撰寫，如果只要操作一次，可以用File.Open
        // Application.dataPath是存在遊戲資料夾底下!! // 這裡附檔名可以用其他的名稱，txt是方便觀看 
            FileStream fs = new FileStream(Application.dataPath + "/Save.txt", FileMode.Create); // 創造檔案
            StreamWriter sw = new StreamWriter(fs);  // 創造寫入點
            sw.WriteLine(data.name);  // 寫入資料
            sw.WriteLine(data.level);
            sw.close();  // 關閉
            fs.close();
            ui_text.text = "儲存完成";
        }
        if(Input.GetKeyDown(KeyCode.L)) // 載入
        {
            FileStream fs = new FileStream(Application.dataPath + "/Save.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fs);
            // 這邊可以全部讀取出來，再去進行字串的拆解與資料的擷取
            data.name = sr.ReadLine();
            data.level = int.Parse(sr.ReadLine());
            // ui_text.text = PlayerPrefs.GetString("name"); // 取出值，把他放入到文字中
        }
    }
    
    [System.Serializable]
    public class PlayerData
    {
        public string name;
        public int level;
    }
}
```



#### 儲存方式 - 連線儲存

> 為了提升遊戲安全性，把重要程式資料、敏感程式邏輯放在伺服器，玩家端的邏輯也要適時驗證!!

1. Binary

```c#
using UnityEngine.UI;
using System.Runtime.Serialization.Formatter.Binary; // 需要這個
using System.Xml,Serialization;
using System.IO;
using System;
using System.Text;

public class SaveData : MonoBehaviour
{
    [SerializeField] // 顯示資料
    Text ui_text;
    [SerializeField]  // 創建data在編輯器中編輯
    PlayerData data;
    
    void Start()
    {
        
    }
    
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Z)) // 儲存
        {
            BinaryFormatter bf = new BinaryFormatter();
            // 副檔名可以用sav、dat、ept(取自己的副檔名也可以) // 創造檔案
        	Stream s = File.Open(Application.dataPath + "/Save.txt", FileMode.Create); 
            bf.Serialize(s, data); // 把物件序列化寫到檔案裡 (以二進位方式呈現)
            s.Close();
            ui_text.text = "儲存完成";
        }
        if(Input.GetKeyDown(KeyCode.L)) // 載入
        {
            BinaryFormatter bf = new BinaryFormatter();
        	Stream s = File.Open(Application.dataPath + "/Save.txt", FileMode.Open); 
            data = (PlayerData)bf.Deserialize(s); // 把物件反序列化
            // ui_text.text = PlayerPrefs.GetString("name"); // 取出值，把他放入到文字中
        }
    }
    
    [System.Serializable]
    public class PlayerData
    {
        public string name;
        public int level;
    }
}
```

2. XML

```c#
// 跟上面基本差不多，不過需要using這個
using System.Xml,Serialization;

if(Input.GetKeyDown(KeyCode.Z)) // 儲存
{
    XmlSerializer xml = new XmlSerializer(Data.GetType()); // 這裡需要物件的型態
    Stream s = File.Open(Application.dataPath + "/Save.xml", FileMode.Create); 
    xml.Serialize(s, data); // 把物件序列化寫到檔案裡 (以xml方式呈現)
    s.Close();
    ui_text.text = "儲存完成";
}
if(Input.GetKeyDown(KeyCode.L)) // 載入
{
    XmlSerializer xml = new XmlSerializer(Data.GetType());
    Stream s = File.Open(Application.dataPath + "/Save.xml", FileMode.Open); 
    data = (PlayerData)xml.Deserialize(s); // 把物件反序列化
    // ui_text.text = PlayerPrefs.GetString("name"); // 取出值，把他放入到文字中
}
```

3. Json 最好用!

```c#
if(Input.GetKeyDown(KeyCode.Z)) // 儲存
{
    // JsonUtility.ToJson(data);  --> 可以直接寫入資料 {"name": sting, "level": number}
    // 這裡把他存在PlayerPrefs裡面
    PlayerPrefs.SetString("jsondata", JsonUtility.ToJson(data); )
    ui_text.text = "儲存完成";
}
if(Input.GetKeyDown(KeyCode.L)) // 載入
{
    				// FromJson: 從Json去做讀取
    data = JsonUtility.FromJson<PlayerData>(PlayerPrefs.GetString("jsondata"))
    // ui_text.text = PlayerPrefs.GetString("name"); // 取出值，把他放入到文字中
}
```

可以在上面的資料進行加密，像是AES阿或是其他對稱式加密，把加密後的資料存進C#的檔案或是PlayerPrefs





實戰資料儲存: https://www.youtube.com/watch?v=XOjd_qU2Ido

使用binary存不易修改，好用!

支援sting bool float int[]   serilize後的public Vector3 -使用 float[3] 和public Color

> PlayerData.cs 設定玩家資料

```c#
[System.Serializable]
public class PlayerData{
    public int level;
    public int health;
    public float[] position;
    
    public PlayerData (Player player)
    {
        level = player.level;
        health = player.health;
        
        position = new float[3];
        position[0] = player.transform.position.x;
        position[1] = player.transform.position.y;
        position[2] = player.transform.position.z;
    }
}
```



> SaveSystem.cs 儲存資料

```c#
using UnityEngine.UI;
using System.Runtime.Serialization.Formatter.Binary;
using System.IO;
// 使用static才不會出現資料重複或其他狀況
public static class SaveSystem{
    public static void SavePlayer (Player player)
    {
        BinaryFormatter formatter = new BinaryFormatter();
        string path = Application.persistentDataPath + "/player.fun";  // 副檔案名甚麼都可
        FileStream stream = new FileStream(path, FileMode.Create);
        
        PlayerData data = new PlayerData(player);
        
        formatter.Serialize(stream, data);
        stream.Close();
    }
    
    public static PlayerData LoadPlayer()
    {
        // 這個可以寫在一個函數裡面，讓我們可以只改一個地方
        string path = Application.persistentDataPath + "/player.fun";
        if(File.Exists(path))
        {
            BinaryFormatter formatter = new BinaryFormatter();
            FileStream stream = new FileStream(path, FileMode.Open);
            
            PlayerData data = formatter.Deserialize(stream) as PlayerData;
            stream.Close();
            
            return data;
        }else
        {
            Debug.LogError("Save file not found in " + path);
            return null;
        }
    }
}
```



> Player.cs 可以觸發儲存邏輯，也可以把儲存邏輯寫在GameManeger

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
	public int level = 3;
    public int health = 40;
    
    public void SavePlayer()
    {
        SaveSystem.SavePlayer(this);
    }
    
    public void LoadPlayer()
    {
        PlayerData data = SaveSystem.LoadPlayer();
        
        level = data.level;
        health = data.health;
        
        Vector3 position;
        position.x = data.position[0];
        position.y = data.position[1];
        position.z = data.position[2];
        transform.position = position;
    }
}
```



