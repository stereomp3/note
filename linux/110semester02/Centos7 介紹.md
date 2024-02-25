這學期主要使用的 軟體: `virtualbox + centos 7`

# Centos7環境設定

## 使用Centos的好處

* centos 對於伺服器的架設很穩定，維護一次可以稱比較久，而且有long term support

> centos 和 ubuntu有些指令不太一樣，不過基本操作和觀念是一樣的

> 在linux的世界裡不是最新就是最好，**穩定度**才是最重要的



## virtulBox安裝教學

* 下載virtulBox: https://www.virtualbox.org/wiki/Downloads

* 下載兩個 VirtualBox 6.1.32 platform packages 和VirtualBox6.1.32 Oracle VM VirtualBox Extension Pack

* 把Extension Pack加到VM Virtual Box，建立新的虛擬機
* 選擇redhat 或是 other linux，記憶體分配1024以上，磁碟使用預設8GB
* 硬碟類型也選預設 [VDI(給Virtaul Box)、VHD(給VM ware)]
* 存放硬碟(50G以上)如果是動態就會根據使用狀況分配，一般都選這個，如果硬碟空間夠大，也可以選擇固定大小，速度會比較快一點。



* 創建完畢把系統裡面的選項改一下
  * set floppy to false
  * 想要速度快一點可以把處裡器的核心用多一點



## centos7 設定教學

> 可以參考: [CentOS 7 的 Linux 系統安裝步驟教學 - G. T. Wang (gtwang.org)](https://blog.gtwang.org/linux/centos-7-installation-tutorial/)

* 開啟後把centos7的光碟選入，選擇install centos7

* 建立centos7之後，**選擇英文版**
* 把SoftWare Selection的地方改成**GNOME desktop**(如果是用最小安裝，就會只有終端機，沒有桌面)
* 把最初創建的使用者賦予administrator







