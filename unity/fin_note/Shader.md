[使用介面畫視窗控制材質](https://www.youtube.com/watch?v=Ar9eIn4z6XE)

## shader



[shader libary](https://developer.download.nvidia.com/cg/index_stdlib.html)

標準著色器:

```c#
Shader "Custom/02"
{
    Properties  // 處理input
    {
        _Color ("Color", Color) = (1,1,1,1)  // 調整rgba (float/fixed4)
        _MainTex ("Albedo (RGB)", 2D) = "white" {} // 圖片
        _Glossiness ("Smoothness", Range(0,1)) = 0.5
        _Metallic ("Metallic", Range(0,1)) = 0.0
        _hp ("health", Range(0,1)) = 1  // 可以在外面控制
    }
    SubShader 
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        CGPROGRAM
        // Physically based Standard lighting model, and enable shadows on all light types
        #pragma surface surf Standard fullforwardshadows

        // Use shader model 3.0 target, to get nicer looking lighting
        #pragma target 3.0

        sampler2D _MainTex;

        struct Input
        {
            float2 uv_MainTex;
        };
        float _hp; // 自訂義變數，要和上面的名稱相同
        half _Glossiness;
        half _Metallic;
        fixed4 _Color;  // 材質顏色

        // Add instancing support for this shader. You need to check 'Enable Instancing' on materials that use the shader.
        // See https://docs.unity3d.com/Manual/GPUInstancing.html for more information about instancing.
        // #pragma instancing_options assumeuniformscaling
        UNITY_INSTANCING_BUFFER_START(Props)
            // put more per-instance properties here
        UNITY_INSTANCING_BUFFER_END(Props)

        void surf (Input IN, inout SurfaceOutputStandard o)  // output
        {
            // Albedo comes from a texture tinted by color
            float4 c = tex2D (_MainTex, IN.uv_MainTex) ; // 圖片每一快的顏色 rgb
            if (c.r > _hp) {  // 判斷顏色
                c.rgb = 0;
            }
            o.Albedo = c.rgb;  // o = output
            // Metallic and smoothness come from slider variables
            o.Metallic = _Metallic;  // 陰暗度
            o.Smoothness = _Glossiness;  //  光不光滑
            o.Alpha = c.a;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
```





無光照著色器(沒有加任何東西):

```c#
Shader "Unlit/01"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 100

        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            // make fog work
            #pragma multi_compile_fog

            #include "UnityCG.cginc"

            struct appdata  // mesh data
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f  // 傳給fragment shader的物件，也可以不要船
            {
                float2 uv : TEXCOORD0;
                UNITY_FOG_COORDS(1)
                float4 vertex : SV_POSITION;
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;

            v2f vert (appdata v)  // 鎖定三角形區塊(三個點) (vertex shader)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);
                UNITY_TRANSFER_FOG(o,o.vertex);
                return o;
            }

            fixed4 frag (v2f i) : SV_Target  // 每個點 (fragment shader)
            {
                // sample the texture
                fixed4 col = tex2D(_MainTex, i.uv);
                // apply fog
                UNITY_APPLY_FOG(i.fogCoord, col);
                return col;
            }
            ENDCG
        }
    }
}
```



使用標準著色器自製mask

```c#
Shader "Unlit/Mask"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _Mask("Mask",2D) = "white" {}
    }
    SubShader
    {
        Tags {"Queue" = "Transparent" "IgnoreProjector" = "True" "RenderType" = "Transparent"}
        Blend SrcAlpha OneMinusSrcAlpha
        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag

            #include "UnityCG.cginc"

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f
            {
                float2 uv : TEXCOORD0;
                float4 vertex : SV_POSITION;
            };

            sampler2D _MainTex;
            sampler2D _Mask;
            float4 _MainTex_ST;

            v2f vert (appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);
                return o;
            }

            fixed4 frag (v2f i) : SV_Target
            {
                fixed4 col = tex2D(_MainTex, i.uv);
                fixed4 mask = tex2D(_Mask, i.uv);
                
                float4 finalColor = lerp(float4(0, 0, 0, 0), col, mask.a);

                return finalColor;
            }
            ENDCG
        }
    }
}
```



## 使用script控制變數

> https://github.com/Brackeys/2D-Shader-Graph/blob/master/2D%20Shader%20Graph/Assets/Scripts/Dissolve.cs

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dissolve : MonoBehaviour
{
	Material material;

	bool isDissolving = false;
	float fade = 1f;

	void Start()
	{
		// Get a reference to the material
		material = GetComponent<SpriteRenderer>().material;
	}

	void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
		{
			isDissolving = true;
		}

		if (isDissolving)
		{
			fade -= Time.deltaTime;

			if (fade <= 0f)
			{
				fade = 0f;
				isDissolving = false;
			}

			// Set the property
			material.SetFloat("_Fade", fade);
		}
    }
}
```

