此遊戲完全手工打造，想法是從手遊[轉校生]而來，玩家扮演人(我)和鬼，人可以變成場地上的物件，鬼負責抓人，鬼抓到全部的人(鬼贏)或是時間超過1分半(人贏)就遊戲結束，因為我的伺服器很爛，所以遊戲有延遲是正常的，人數上限我也只調4人而已XD



## program flow chart

> 裡面有些沒有寫入，像是玩家變成其他物件的流程、鬼偵測玩家的邏輯......

![](./picture/WebSocket.png)

## 程式碼介紹

* 核心程式碼

  ```c#
  function StartScence(){
      timer = 0; goast_win = false
      startAnimating(10) // 調整fps
      console.log("in")
      if(id==1) flag = false  // 鬼
      create_player(create_pos[0], start_map) // 創建玩家在初始地圖
      player_pos = set_postion(start_map, __player)
      var loop = function () {
          timestamp = Date.now(); //調整速率
          progress = timestamp - preTimestamp;
          if (progress > fpsInterval) { 
              if(!start_game){
                  game_instruction()
                  game_begin()
              }
              else {
                  MainGame()
                  return 0
              }
              startAnimating(10);
              draw(start_map)
          }
          window.requestAnimationFrame(loop);
      }
      window.requestAnimationFrame(loop);
  }
  
  function MainGame() {
      document.getElementById("instruction").innerHTML = ``
      startAnimating(FPS) // 調整fps
      create_people()
      //random_item(25) // 1/25
      var loop = function () {
          timestamp = Date.now(); //調整速率
          progress = timestamp - preTimestamp;
          if (progress > fpsInterval) { 
              startAnimating(FPS);
              if(game_over){
                  // 遊戲結束跳到 GameOverScence
                  GameOverScence()
                  return 0
              }
              if(flag) {
                  // 人操作邏輯
              }
              else {
                  // 鬼操作邏輯
              }
  
              if((timer > win_time && !detect_game_over()) || goast_win){
                  // 遊戲結束判定讓game_over = true
              } 
              draw(map)
          }
          window.requestAnimationFrame(loop);
      }
      window.requestAnimationFrame(loop);
  }
  
  function GameOverScence(){
      startAnimating(10) // 調整fps
      var loop = function () {
          timestamp = Date.now(); //調整速率
          progress = timestamp - preTimestamp;
          if (progress > fpsInterval) { 
              startAnimating(10);
              if(goast_win){
                  // 鬼獲勝邏輯
              }
              else{
                  // 人獲勝邏輯
              }
              if(game_reset()==-1){
                  // 重新開始遊戲
              }
          }
          window.requestAnimationFrame(loop);
      }
      window.requestAnimationFrame(loop);
  }
  ```

* 核心矩陣處理類

  ```js
  class Vector2{
      constructor(x = 0, y = 0){
          this.x = x
          this.y = y
      }
  
      move(vect_dir){
          this.x += vect_dir.x
          this.y += vect_dir.y
      }
  
      // static method
      static get_left(){
          return new Vector2(0, -1)
      }
      static get_right(){
          return new Vector2(0, 1)
      }
      static get_down(){
          return new Vector2(1, 0)
      }
      static get_up(){
          return new Vector2(-1, 0)
      }
      static stay(){
          return new Vector2(0, 0)
      }
  }
  
  class DoubleListHelper{
      static get_elements(list_target, vect_pos, vect_dir, count = 1){
          let list_result = []
          let dst_x = vect_pos.x, dst_y = vect_pos.y // 不改vect_pos位置，這裡用來定位
          for(let __ = 0; __ < count; __++){
              dst_x += vect_dir.x
              dst_y += vect_dir.y
              let element = list_target[dst_x][dst_y]
              list_result.push(element)
          }
          return list_result
      }
  	// 設定位置
      static set_elements(list_target, vect_pos, vect_dir, element, count = 1){
          let dst_x = vect_pos.x, dst_y = vect_pos.y
          for(let __ = 0; __ < count; __++){
              dst_x += vect_dir.x
              dst_y += vect_dir.y
          }
          list_target[dst_x][dst_y] = element
      }
  }
  ```

* server、client程式碼(使用JSON傳遞，並用type判定資料內容，做出對應的操作)

  ```js
  ////////////////////////////////client.js/////////////////////////////////////////////
  var socket = new WebSocket("ws://"+window.location.hostname+":8080")  // 連到server port
  let id = 0  
  // 開啟時觸發
  socket.onopen = async function (event) { 
      console.log()
      console.log('socket:onopen()...') 
      socket.send(JSON.stringify({
          type:'id',
          id: 0
      }))
  }
  socket.onerror = function (event) { console.log('socket:onerror()...') }
  // websocket關閉時觸發
  socket.onclose = function (event) { console.log(event.data) }
  
  
  // 有字串時觸發 // server傳給client
  socket.onmessage = function(event){
      //console.log(event.data);
      var date = JSON.parse(event.data)
      if(date.type == "id"){  // 拿到id 開始遊戲
          console.log(date.id)
          id = date.id
          __player += id
          player = __player
          input_detect()
          StartScence()
      }
      if(date.type == "start"){
          console.log("start!!")
          console.log(__player)
          start_game = true // 開始遊戲
      }
      if(date.type == "game_over"){
          console.log("game over!!")
          console.log(__player)
          start_game = false // 結束遊戲
          game_over = true
          __player = -99
          player = -99
          goast_win = date.flag
      }
      if(date.type == "close"){
          socket.send(JSON.stringify({
              type:'leave',
              id: id
          }))
      }
      if(date.type == "game_map") map = date.m
      if(date.type == "start_map") start_map = date.m
      if(date.type == "p1_start_map") p1_start_map = date.m
      if(date.type == "p2_start_map") p2_start_map = date.m
      if(date.type == "p3_start_map") p3_start_map = date.m
      if(date.type == "p4_start_map") p4_start_map = date.m
      if(date.type == "goast_map") goast_map = date.m // id: 1
      if(date.type == "p1_map") p1_map = date.m // id: 0
      if(date.type == "p2_map") p2_map = date.m // id: 2
      if(date.type == "p3_map") p3_map = date.m // id: 3
  
  
      if(date.type == "get_player_pos" && flag){ // 人回覆位置
          socket.send(JSON.stringify({
              type:'set_player_pos',
              min_x: min_x,
              min_y: min_y
          }))
      }
      if(date.type == "set_player_pos" && !flag){ // 鬼收到位置
          add_player_pos(detect_pos_map, date.min_x, date.min_y)
      }
  
      if(date.type == "timer"){
          timer = date.t
      }
  }
  ////////////////////////////////server.ts/////////////////////////////////////////////
  const wss = new WebSocketServer(8080);
  let seat = [false, false, false, false]
  let id = 0, count = 0, t_tmp = 0// token_move會用到
  let token = [0,0,0,0] // 紀錄client seat位置
  let id_flag = false
  let timer = 0, f_time = Date.now(), b_time
  
  wss.on("connection", function (ws: WebSocketClient) {
  	ws.on("message", function (message: string) { 
  		let text = JSON.parse(message)
  		
  		if(text.type == "start") timer = 0 // 重製時間
  		if(text.type == "id") {
  			count = 0
  			wss.clients.forEach(function each(client) {
  				if (client == ws) {
  					for(let i = 0; i < seat.length; i++){
  						if(!seat[id]){
  							if(id_flag) {
  								token_move(token, count)
  								id_flag = false
  							}
  							seat[id] = true
  							token[count] = id
  							console.log("p"+id+": inGame")
  							console.log(seat, id, "count", count)
  							console.log("token:", token)
  							break
  						}
  						id += 1
  					}
  				}
  				if(!client.isClosed) count += 1
  			});
  			text.id = id 
  			id = 0
  			ws.send(JSON.stringify(text)); // 單向
  		}
  		else{ // map // start
  			// forEach是回乎函數，只要client沒關，這個就還會在，這邊做的效果是任何人傳訊息都會廣播給所有人
  			wss.clients.forEach(function each(client) {
  				if (!client.isClosed) {
  					client.send(message);  // broadcast message
  				}
  			});
  		}			
  
  		if(time_flow()){
  			wss.clients.forEach(function each(client) {
  				if (!client.isClosed) {
  					client.send(JSON.stringify({
  						type:'timer',
  						t: timer
  					}));  // broadcast message
  				}
  			});
  		}
  	}),
  	ws.on("close", function(){ 
  		console.log("close")
  		count = 0
  		wss.clients.forEach(function each(client) {
  			if(!client.isClosed) count += 1
  			if (client == ws) {
  				seat[token[count]] = false
  				console.log(seat, token[count])
  				t_tmp = token[count] // 為了要用token_move()
  				token[count] = -1 
  				id_flag = true
  			}
  		});
  		count = 0
  	})
  });
  
  function token_move(list: number[], count: number){ // 向左移動
  	for(let i = 0; i < count; i++){
  		if(list[i] == -1){
  			list[i] = list[i+1]
  			list[i+1] = -1
  			console.log("list:",list)
  		} 
  	}
  	token[count] = t_tmp
  }
  
  function time_flow(){
  	b_time = Date.now()
  	if(Math.abs(f_time-b_time)>=1000){  // Data.now是ms為單位
  		f_time = Date.now()
  		console.log(f_time)
  		timer += 1
  		return true
  	}
  }
  ```

  