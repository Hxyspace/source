## Markdown 书写示例
@(标签)[1| 2 | 3]

# 一级标题
‘#’ 后面要加空格
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
####### 没有七级标题

### 列表

- 1
+ 2
* 3
1. 1
2. 2
3. 3

### 引用

>例如这样

>这样

### 图片和链接

![图片](./示例.jpg)

![图片2](http://img1.gtimg.com/comic/pics/hv1/216/225/2210/143762841.jpg)

![图片3](http://pic28.photophoto.cn/20130818/0020033143720852_b.jpg)

[链接](http://www.baidu.com)

[1]

[1]:www.baidu.com

### 斜体和粗体

*这个是斜体*

**这个是粗体**

***这个是斜粗体***

### 分割线

---

或者

---

### 代码块

```c

#include<stdio.h>

int main()
{
	return 0;
}

```
`main()`

	main()

### 表格

| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

```flow
st=>start: Start
e=>end
op=>operation: My Operation
cond=>condition: Yes or No?

st->op->cond
cond(yes)->e
cond(no)->op
```

