# COH判题脚本

### 提交代码形式

1. C++
```c++
class Solution {
public:
	void solve() {
		解决过程；
	}
};
```

2. Python 3

```python
class Solution:
	def solve(self):
		解决过程
```

3. Java

```java
class Solution {
	public void solve() {
		解决过程；
	}
}
```



### 判题脚本形式

judge.cpp

judge.py

judge.java



### 数据集形式

data (.txt)



### 程序输出形式

out (.txt)



### 正确答案形式

ans (.txt)



### 运行逻辑

1. 判题脚本调用提交代码，如果有时间开发的话就进行关键词过滤。
2. 编译、运行脚本
3. 脚本读入数据集data，把输出导出到out文件中
4. out与答案集ans进行对比
5. 返回正确率

