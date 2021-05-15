##### 假期我曾自己学过一些git的知识，但是仅仅是关于git的基本知识，对于一些实际的操作具体的东西我还是一头雾水，这次就借助vscode平台对我的知识进行一部分完善吧！

##### 一. vscode的git说明  

1. 加载文件

   先在vscode上加载一个文件夹，在里面放一些简单的代码文件

2. 初始化git存储库

   左侧的菜单中可以看到有一个git的logo(长得和分享的图标似的),点击 这个图标，里面有一个初始化git存储库的按钮-单击
   
3. 初始化后表现

   - git栏里显示了当前所有文件，有多个更改
   - 在文件目录下也生成了一个.git文件夹，放置了当前仓库的所有配置文件

4. 这个git在vscode有一些操作技巧，之后再说

##### 二.连接远程仓库

自己初始个本地仓库没鸡巴卵用，所以还是要连接远程仓库的，对了，这里先要登录github。

1. 在github中新建一个仓库

2. 打开刚刚新建的仓库(刚建完会自动打开)，复制这个仓库的链接

3. 点开vscode中git栏，将鼠标移动到源代码管理右侧的三个小点(移上去才能看到)，选择远程标签，点击添加远程存储库

4. 看到上方提示让输入仓库地址，如我这里是https://github.com/zzr403/c-practice。

5. 根据提示再输入仓库名称，自己之前起的那个，也是地址最后的字符，如我这里的“c-practice”。

6. 在工程文件夹中找到之前初始化生成的.git文件夹，再以记事本形式打开其中的config文件

   ```
   [core]
   	repositoryformatversion = 0
   	filemode = false
   	bare = false
   	logallrefupdates = true
   	ignorecase = true
   ```

      这里是加载仓库之前config的内容

   ```
   [core]
   	repositoryformatversion = 0
   	filemode = false
   	bare = false
   	logallrefupdates = true
   	ignorecase = true
   [remote "c-practice"]
   	url = https://github.com/zzr403/c-practice.git
   	fetch = +refs/heads/*:refs/remotes/c-practice/*
   ```

   ​	这是加载之后config内容，可以明显看出多了仓库的内容

7. 

看到里面生成了当前所有文件的目录，并且提示有多个更改



random something 随机生成一些东西  ctrl+shift+p：random：电话。。。

image preview 直接浏览图片

如果随机生成的图片，那么当然需要imagepreview打开看喽，到外部网页说不定就回不来了呢

power mode打字动画特效，很炫的那种

这个需要在setting开启一些配置

  "powermode.enabled": true,

  "powermode.enableShake": true,

  "powermode.presets": "simple-rift",

  "powermode.shakeIntensity": 3,

  "powermode.explosionDuration": 400,