```c++
#include <iostream>
using namespace std;

struct PERSON {   // Declare PERSON struct type
    int age;   // Declare member types
    long ss;
    float weight;
    char name[25];
} family_member;   // Define object of type PERSON

struct CELL {   // Declare CELL bit field
    unsigned short character  : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity  : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink      : 1;  // ?0000000 00000000
} screen[25][80];       // Array of bit fields

int main() {
    struct PERSON sister;   // C style structure declaration
    PERSON brother;   // C++ style structure declaration
    sister.age = 13;   // assign values to members
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';
    cout << "brother.age = " << brother.age << '\n';

    CELL my_cell;
    my_cell.character = 1;
    cout << "my_cell.character = " << my_cell.character;
}
```


> 使用struct裡面的operator改變運算符號
```c++
struct Pos{
 Pos(int x,int y):x(x),y(y){}
 
 Pos operator + (Pos a){return Pos(a.x + x,a.y+y);}
 int x;
 int y;
}
Pos a,b;
Pos c =a+b;
```

> priority queue
```c++
struct node {
    int x, y;
    int sq;
     
    node(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
        sq = _x * _x + _y * _y;
    }
}; 
 
struct cmp {
    bool operator()(node a, node b) {
        return a.x < b.x;
    }
};
 
int main(){
    priority_queue <node, vector<node>, cmp> pq;
}
```