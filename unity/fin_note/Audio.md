參考影片: https://www.youtube.com/watch?v=6OT43pvUyfY

任何物件想要發出聲音需要加上音訊源(Audio Source)

混響區混音(spatial Blend )調到3D會根據物品的遠近去決定音量大小，2D則是都一樣







> AudioManager: 統一管理聲音，使用 instance物件，再呼叫play()函式就可以播放音效

```c#
using UnityEngine;

public class AudioManager : MonoBehaviour
{

	public static AudioManager instance;
	GameObject s_child;

	private void Awake()
    {
		
		if (instance != null) // AudioManager物件已經創建過，就不會再創建
		{
			Destroy(gameObject);
		}
		else
		{
			instance = this;
			DontDestroyOnLoad(gameObject); // 切換場景音樂不會停，物件繼續保持
		}

		Play("MainTheme"); // 播放場景音樂
	}

	public void Play(string sound)
	{
		
		for(int i = 0; i < transform.childCount; i++)
        {
			if(transform.GetChild(i).name == sound)
            {
				s_child = transform.GetChild(i).gameObject;
			}
        }
		AudioSource s = s_child.GetComponent<AudioSource>();
		if (s == null) // 如果使用play()，名字打錯，會return
		{
			Debug.LogWarning("Sound: " + name + "not found!");
			return;
		}

		s.Play();
	}

}
```



下面的使用失敗，所以就用自己改過的ㄅ

> AudioManager: 統一管理聲音，使用 instance物件，再呼叫play()函式就可以播放音效

```c#
using UnityEngine.Audio;
using System;
using UnityEngine;

public class AudioManager : MonoBehaviour {

	public static AudioManager instance;

	public Sound[] sounds;

	void Start ()
	{
		if (instance != null) // AudioManager物件已經創建過，就不會再創建
		{
			Destroy(gameObject);
		} else
		{
			instance = this;
			DontDestroyOnLoad(gameObject); // 切換場景音樂不會停，物件繼續保持
		}

		foreach (Sound s in sounds)
		{
			s.source = gameObject.AddComponent<AudioSource>();
			s.source.clip = s.clip;
            s.source.volume = s.volume;
            s.source.pitch = s.pitch;
			s.source.loop = s.loop;
		}
		Play("MainTheme"); // 播放場景音樂
	}

	public void Play (string sound)
	{
		Sound s = Array.Find(sounds, item => item.name == sound); // 速寫法
		if(s == null) // 如果使用play()，名字打錯，會return
        {
            Debug.LogWarning("Sound: " + name + "not found!");
        	return
        }

		s.source.Play();
	}

}
```



> Sound: 定義聲音模板

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class Sound {

	public string name;

	public AudioClip clip;  // 放入音檔

	[Range(0f, 1f)]
	public float volume;

	[Range(-2f, 2f)]
	public float pitch; // 音調

	public bool loop = false;

	[HideInInspector] // 讓外面無法修改
	public AudioSource source; // 把音效加到AudioManager裡面

}
```



> use

```c#
AudioManager.instance.Play("name");
```

