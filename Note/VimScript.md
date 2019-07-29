#  Vim Script

vim 脚本语言，主要讨论语言基础内容和特性。

## 符号

符号的命名规则和 C 语言一样（由 ASCII 字母组成，不支持 Unicode 字符），但是 Vim Script 变量名前可以添加作用域前缀（作用域前缀适用于所有文法符号 symbols，如函数名、变量名），如全局变量可以写作：`g:var_name`

Vim Script 中符号的作用域包含以下几种：

1. 全局作用域，这是默认情况下的作用域，在 vim 运行期间，前缀为 `g:`
2. buffer 作用域，前缀 `b:`
3. window 作用域，前缀 `w:`
4. vim 预定义变量，前缀 `v:` ，具有全局作用域。

除了通常的类 C 符号名规则外，Vim Script 还支持运行计算符号名或者理解为符号名拼接: `my_{adjective}_variable` 。Vim Script 会先计算 `adjective` 的值，如果 `adjective == 'noisy'` 那么完整变量名为 `my_nosiy_variable。`

