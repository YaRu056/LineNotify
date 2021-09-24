# LineNotify

>## 系統功能

#### 系統目標

   當家中沒有人時，家裡的毛小孩常常會被圍在圍籬內避免發生意外和跑出去，但是有時寵物會發生意外翻出圍籬跑出去，導致飼主沒辦法及時掌握寵物的狀態與行動。為了避免類似的情形發生，本偵測系統將會在圍籬上方進行偵測，當偵測到有小動物翻過圍籬之後，將會記錄回傳給飼主，供飼主及時知道小動物現在的狀態。

#### 系統描述
  * 偵測端
  
    感測圍欄上方和攝影圍欄內影像，傳送Email至飼主端。
   * 飼主端

      接收Email的警告訊息，查看圍欄內狀況。
      
#### 系統使用角色
   * 偵測端
  
      觀察端會對圍欄內與圍欄上方進行攝影，只要將樹莓派連上網路後，飼主就可以在手機或電腦，看到觀察圍欄內的攝像頭畫面；而另一個攝像頭感測到物體經過後，樹莓派便會拍攝相片，並傳送警示Email至飼主端，飼主可查看照片和時間，進行緊急處理。
   * 飼主端

      飼主可以遠距離觀察圍籬內的狀況，掌握寵物的即時狀況。當寵物翻出圍籬時，可以即時接收到警告訊息通知飼主，現在寵物已經翻出圍籬了，同時飼主也可以知道寵物翻出圍籬的時間；而另外拍向圍籬內的攝像頭也可以供飼主查看狀況。
      
#### 功能需求
   * 偵測端功能需求
      ![image](https://user-images.githubusercontent.com/82867224/134677913-2636ac1d-2cdd-4ada-8fd6-341c5f646767.png)
   * 飼主端功能需求
      ![image](https://user-images.githubusercontent.com/82867224/134678004-7b3a65a9-dcd5-4b12-9d9f-b777e0773b4e.png)
      
>## 系統架構

#### 使用器材
   * Arduino UNO WiFi板
   
      使用此板安裝上超聲波感測器，當感測數值變化時，便會呼叫攝像頭進行錄影。
   * 超聲波感測器
   
      超聲波感測會發射超聲波出去，當撞到物體時會凡談訊息，告知有物體經過正前方。用此方式便可以辨認是否有物體經果。
   * 樹莓派
   
      樹莓派為單晶片微型電腦，此處主要用於控制攝像頭進行記錄相片、時間與攝影機的功能，並當偵測到有物體經過時，將發送Email至飼主手機，通知飼主毛小孩的現狀，飼主也可以透過樹莓派所安裝的攝影機觀察寵物的現狀。
      
   * 攝像鏡頭
   
      此處會需要兩個攝像鏡頭，一個會拍攝圍欄內，對寵物行為進行影像傳播，讓飼主可以觀察寵物的日常；另外一隻攝像頭會拍攝圍欄上方，當超聲波感測器感受到有物體經過之後，便會呼叫攝像鏡頭進行拍照。
      
#### 架構描述

   * 系統使用情境
   
      ![image](https://user-images.githubusercontent.com/82867224/134679051-65fdd12b-65be-419a-968b-7d93e2365552.png)
      
      圖1 系統使用情境圖
      
      飼主不在家、且未帶寵物出時，會很擔心寵物的現狀，只要手機能連上網路，飼主就可以觀察寵物於圍欄內的狀況，隨時關心寵物日常。當飼主正在忙碌時，沒辦法即時查看寵物現狀，但寵物卻意外從圍欄上方翻出，偵測系統就會開啟功能。系統透過在圍欄上方架設錄影機與超聲波感測器進行感測，當感測到物體經過時，超聲波所感測到的數值就會因為回傳的距離改變而更動。系統會判定當數值變更時，會呼叫攝影機進行拍照，並記錄當下的時間，由樹莓派統一成訊息處理。如果飼主沒辦法即時處理，可以通知在家的家人或者朋友，進行緊急處理，以免寵物失蹤或者造成意外發生。
      
   * 系統架構
    
     ![image](https://user-images.githubusercontent.com/82867224/134679928-b399c02f-8cd8-46b6-abe2-53802a1b8b12.png)
      
      圖2 影像傳送架構圖
      
      飼主可以由樹莓派和攝像頭結合的即時影像，傳至飼主的手機內，提供飼主隨時隨地，只要是連的上網路的地方，即可以觀察寵物狀況。
      
      ![image](https://user-images.githubusercontent.com/82867224/134680227-c834984f-2db8-4041-a313-b2b5583d007a.png)
      
      圖3 偵測拍照架構圖
      
      ![image](https://user-images.githubusercontent.com/82867224/134680254-61a78107-207c-4ad2-b4e1-d179a23cdaa4.png)
      
      圖4 傳送通知架構圖
      
>## 預期效益分析

   * 使用者    
      
      對於使用者來說，只要是有飼養寵物的飼主都可以使用，隨時可以觀察寵物們的日常行為，更可以時常關心動物們的身心狀況，以免當飼主不再家時，沒辦法即時處理動物們的緊急狀況，而造成遺憾。除此之外，本系統可以偵測圍籬上方的狀況，當動物翻落或者闖出時，飼主就會收到來自系統的緊急通知，可以即時查看動物的跑出照片和跑出時間，預估動物會跑出的方向，飼主便可以在第一時間通知朋友或家人馬上進行處理，以免動物發生意外或失蹤，沒辦法及時發現，會讓飼主花更多時間在找尋動物上面。

   * 市場價值
   
      現在生育率下降，很多人因為小孩所帶來的經濟壓力，造成不想生育的情況，改養毛小孩來代替，再加上毛小孩可愛的模樣，發現現在養寵物的概率提升許多。本系統只要是有飼養寵物的人都適用，且會在以後持續提升系統功能，增加相關產業產值。
      
>## 未來應用

   * 嬰幼兒意外翻落
   
      現在新聞中常看到類似報導，嬰幼兒常常因為在窗戶附近遊玩，導致嬰幼兒掛在鐵窗上搖搖欲墜、卡在鐵窗上，而家長們也常常疏忽而沒有注意。本裝置期望可以運用於此狀況上，能讓家長即時將卡在鐵窗上的嬰幼兒搶救下來，以免嬰幼兒因為支撐體力不支，導致墜落的意外發生。

   * 小型動物偵測
   
      當飼主飼養小型動物時(例如：倉鼠或幼貓)，會因為過於小隻而造成疏忽注意，或不清楚小動物是何時從圍欄內跑出，因為沒辦法即時提醒飼主造成意外。而本裝置期望能應用於偵測小型動物上。

   * 防盜
   
      現在小偷大部分會從窗戶闖入，造成屋主財務上的損失，且遭小偷時時常因為窗戶邊沒有裝設攝影機導致不知是何人所為。本系統可以在小偷闖進的時候進行警報通知，並拍下小偷的樣貌方便警方進行比對或通緝，可以加強警察抓到小偷的機率，以免造成被人闖空門卻抓不到兇手的狀況。
