#W3Objects

W3Objects是用于操作《魔兽争霸III：冰封王座》的物体信息的一系列类库，它可以读写mpq包以及地图文件(本质上也是mpq包)中的slk(符号链接表)文件、txt(profile)文件以及各种名为war3map.w3*的文件。

## SLK文件
通过Sylk相关类来实现读写，其中包括：

* __SylkFile__ 封装了SLK文件的所有内容，其内部实现是一个二维向量；
* __SylkRecord__ SYLK中有4个组成部分：文件头、大小区、数据区、结束符，每一行、每个单元格中的数据，都用一个SylkRecord表示。

## TXT文件
通过Profile相关类来实现TXT文件的读和写，Profile相关类如下：

* __TextFile__ 封装了整个文本文件，由诺干个ProfileNode构成；
* __ProfileNode__ 封装了文本文件中对某个物体的描述，由它的名字以及诺干个ProfileParam构成；
* __ProfileParam__ 封装了物体的某个属性，属性由属性名称和多个值构成。

## W3_文件
通过W3O相关类来实现w3u、w3a等文件的读写，其中包括：

* __W3\_File__ 封装了整个w3*物体文件的信息，由两个ObjectTable构成；
* __ObjectTable__ 封装了物体表结构，由数个ObjectDefinition构成；
* __ObjectDefinition__ 封装了物体的定义信息，由物体编号以及数个Modification；
* __Modification__ 封装了单个数据改动的结构，包括修改编号、值类型、level、data_ptr、改动值、结束符构成；
* __Value__ 封装了最基本的值结构，由int、float、string构成。

## 工具类

* __IW3File__ 文件接口；
* __ObjectIdentity__ 物体的ID，使用在ProfileNode、ObjectDefinition、Modification中。

## 在计划中功能：

* 将被压缩成slk+txt+war3map.w3\*的物体数据还原成仅有war3map.w3\*的情况；
* 结合stormlib，可以不必手动解压mpq和地图文件，直接从包中提取这三种文件。

