# Language

## 基本功能
1. 定义结构体object, _is_main 标识是否指向了别的字段, 
2. 定义基本的判断, 返回正确与否
## 状态
状态和指针密切相关, = 意味着某字段指向了另一个字段, =* 则意味着值相同
定义一个事物的状态, 必须在特化时定义, 否则就是修改一个事物的状态了, 按照建议, 修改状态都要在事件中修改
状态->事件/判断
状态, 事件都是可以有返回值的, 返回值目前来说可以都为事物

状态中不包含过程是难以想象的
## 推理机
TODO 推理的结果应该都是状态.

## 断句方法
对于一句话, 比如`object a`, `int add();`, 我们希望的是将各个独立的单词或字符区分开. `object a{}`可以区分成`object`, `a`. `int add();` 则可以区分成`int`, `add`, `(`, `)`, `;`. 

### 字符类型
要想成功断句, 需要发现, 有以下的字符类型:
1. ' ', '\t', '\n'
2. 字母, '_'
3. ',', '.', '/', '<', '>', '?', '\'', ';', ':', '\"', '[', ']', '{', '}', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '|', '\'
4. 数字

有以下的单词类型:
1. 变量名, 以字母或下划线作为开始, 包含字母, 下划线或数字
2. 符号类型, 由符号组成
3. 数字

*目前断词时,会优先断可断的更长的词, 比如`->`会断为`->`, 可能存在问题*
### 断句规则

1. 如果遇到空字符, 那么断词
2. 如果现在是一个变量名, 遇到字符, 则断词并开始分析字符
3. 如果现在是一个字符, 遇到非字符, 则断词并开始分析相应单词
4. 如果现在是一个数字, 遇到非字符, 则断词并开始分析相应单词
5. 到句子结尾, 断词