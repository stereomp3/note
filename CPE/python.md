# python

```python
from operator import itemgetter, attrgetter

scores = [
    ('Jane', 'B', 12),
    ('John', 'A', 15),
    ('Dave', 'B', 11)]

# 依照第三個數字元素排序
print(sorted(scores, key = itemgetter(2)))

# 以第二個元素排序，若相同則以第三個元素排序
print(sorted(scores, key = itemgetter(1, 2)))

# 依照第三個數字元素排序
scores.sort(key=lambda x:x[2])

# 這個等於上面的寫法
scores.sort(key=func01(x))
def func01(x):
    return x[2]
```

```python
f = 0.00001
# 取三位浮點數
print("{:.3f}".format(f))
print(round(f,3))
```

queue
```python
import queue

q = queue.Queue()
q.put(1)  # append
q.get()  # pop
```

```python
dict = {}
dict.__contains__("1")
list = []
list.count("1")
```
宣告初始大小
```
# 1 最快的方法
a = [None] * 10
# 2 第二快
a = [None for _ in range(10)]
# 3 最慢的方法
a = []
for _ in range(10):
    a.append(None)

# 這一般情況會比 1 慢，但在處裡大量資料的時候會比 1 快
from numpy import empty
a = empty(10)
```
> 解決 EOFerror (其實沒有解決 CPE 也會過)
```python
try:
    # code
except EOFError:
    # break
```
