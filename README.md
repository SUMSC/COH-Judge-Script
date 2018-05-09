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

- 关于用户的输入输出：

  只需要使用标准的 cin / cout / scanf / printf ，input / print 就可以

  并且无需考虑多组输入。

- 关于 example：

  是一道无套路的 a + b 题。



### 判题脚本形式

judge.cpp

judge.py

judge.java

出于用户群体考虑，暂时先搁置 java 判题脚本的开发。



### 数据集形式

data (.txt)



### 程序输出形式

out (.txt)



### 正确答案形式

answer (.txt)



### 运行逻辑

1. 判题脚本调用提交代码，如果有时间开发的话就进行关键词过滤。
2. 编译、运行脚本
3. 脚本读入数据集 data，把输出导出到 out 文件中
4. out 与答案集 answer 进行对比
5. 返回正确率



### 还需添加的功能（可能）

1. 关键词过滤（防止恶意代码）
2. 时间判定（防止死循环 / 复杂度太大等）

