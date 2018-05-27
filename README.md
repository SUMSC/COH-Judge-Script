# COH判题脚本

### 提交代码形式

1. C++
```cpp
class Solution {
public:
	void solve() {
		// 解决过程；
	}
};
```

2. Python 3

```python
class Solution:
	def solve(self):
		# 解决过程
```

3. Java

```java
import java.util.Scanner;

class Solution {
	public void solve(Scanner input) {
		// 解决过程；
	}
}
```

- 关于用户的输入输出：

  只需要使用标准的 cin / cout / scanf / printf ，input / print 就可以，
  Java 直接使用给出的 Scanner 即可，
  并且无需考虑多组输入。

- 关于 example：

  是一道无套路的 a + b 题。


### 判题

#### 判题脚本

- C++: Judge/judge.cpp
- Java: Judge/judge.java
- Python3: Judge/judge.py

#### 脚本使用

判题时需要保持 Repo 中的目录形式（也可自行改动判题脚本中的文件读取位置）。

- Data 目录存放题目数据，
- Judge 目录存放判题脚本和编译文件（.exe .class），
- Source 目录存放需要判断的程序。

C++ 和 Python 的判题脚本可以使用命令行也可以使用 IDE。

Java 判题脚本说明如下。

#### Java 判题说明

编译时在根目录（COH-Judge-Script）中使用命令行：`javac ./Judge/judge.java`。

执行时使用命令：`java Judge.judge`。


### 数据集形式

in (.txt)


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


### TODO List（可能）

1. 关键词过滤（防止恶意代码）
2. 时间判定（防止死循环 / 复杂度太大等）
3. 返回出错的行数