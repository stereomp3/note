## Class

> https://developer.mozilla.org/zh-TW/docs/Web/JavaScript/Reference/Classes

* 創建

  ```js
  class Polygon {
    constructor(height, width) {
      this.height = height;
      this.width = width;
    }
  }
  ```



* method: 使用constructor的變數

   ```js
   class Polygon {
     constructor(height, width) {
       this.height = height;
       this.width = width;
     }
     // Getter
     get area() {
       return this.calcArea();
     }
     // Method
     calcArea() {
       return this.height * this.width;
     }
   }
   ```

  ```js
  // use
  const square = new Polygon(10, 10);
  console.log(square.area); //100
  ```

  

* static method: 使用的變數有constructor以外的變數  !! 靜態方法直接用class呼叫，不能new一個物件呼叫

  ```js
  // def
  class Point {
      constructor(x, y) {
          this.x = x;
          this.y = y;
      }
  
      static distance(a, b) {
          const dx = a.x - b.x;
          const dy = a.y - b.y;
  
          return Math.sqrt(dx*dx + dy*dy);
      }
  }
  ```

  ```js
  // use
  const p1 = new Point(5, 5);
  const p2 = new Point(10, 10);
  
  console.log(Point.distance(p1, p2)); // 7.0710678118654755
  ```



* override

    ```js
    // def parent
    class Cat {
      constructor(name) {
        this.name = name;
      }
    
      speak() {
        console.log(this.name + ' makes a noise.');
      }
    }
    // def child
    class Lion extends Cat {
      // override
      speak() {
        super.speak(); // 使用父類
        console.log(this.name + ' roars.');
      }
    }
    
    
    ```

  ```js
  // use
  var l = new Lion('Fuzzy');
  l.speak();
  // Fuzzy makes a noise.
  // Fuzzy roars.
  ```

  