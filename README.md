#W3Objects

W3Objects是用于操作《魔兽争霸III：冰封王座》的物体信息的一系列类库，它可以读写mpq包以及地图文件(本质上也是mpq包)中的slk(符号链接表)文件、txt(profile)文件以及各种名为war3map.w3*的文件。

在计划中功能：

* 将被压缩成slk+txt+war3map.w3\*的物体数据还原成仅有war3map.w3\*的情况；
* 结合stormlib，可以不必手动解压mpq和地图文件，直接从包中提取这三种文件。

