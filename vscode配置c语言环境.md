### 1. 软件介绍

- vscode 简介

  vscode是一个免费的、开源的跨平台的<font color="#1cbbb4">编辑器</font>，vscode平台下有许多插件，对于打代码起着很方便的作用，就像铁甲小宝中卡布达设定最强机器人，强就强在辅助装备多，而vscode就属于这种角色。

- mingw介绍

  mingw是一个<font color="#1cbbb4">解释器</font>(用来将代码翻译成机器语言的工具)

### 2. 运行代码

vscode是一个极其好用的代码编写平台，但是这个平台仅限于编写代码，如果要运行还是要进行一些设置。

### 3. 安装软件

- mingw安装

  1. 在官网下载mingw的exe文件或者压缩包

     额！！！反正我按照教程上的官网ip没找到，我自己搜到的也不知道是不是，反正直接搜下载上就行，我查询别人的教程会发现下载的不同，有的下载的是压缩包形式，将压缩包下载后解压并放到自己建好的文件夹即可，我多说一下exe文件的安装吧！

  2. 安装mingw的exe程序

     - 首先下载好exe后双击安装

     - 一直点击next即可

     - 其中有一个界面如下图

       

       <img src="https://i.loli.net/2021/04/16/kBMcXtm281vK97n.png" style="zoom: 80%;text-align:left" >
       
            version:最新版；
           
            Architecture:x86_64;
           
            Threads:win32;
           
            Exception:sjlj;(这里写错了，如果是x86_64对应着seh)
           
            Build revison:0;
       
       这里我其实也不咋懂，根据我查资料和经验填的！
       
       
       
     - 选择安装路径安装
  3. 配置mingw的环境变量

       - 安装好后配置环境变量，主要是要调用gcc或者g++

       打开安装的mingw的路径，找到bin文件夹，看里面是否存在gcc/g++，然后复制此路径,
       
       - 打开电脑属性，找到系统变量，找到path，新建一条，将刚刚复制的路径粘贴进来（路径到bin为止）,然后 确定——确定——确定，mingw安装完成。
  - 安装后可以做一次检测，打开cmd，输入gcc -v，如果安装成功的话会弹出一大段代码，最后一句代表是gcc的版本。
    
       
    

- vscode安装

  1. 下载vscode
  2. 安装
  3. 下载vscode中文插件
  4. 下载c/c++插件
  5. 完成以上步骤即可以运行c或者c++了，但是仅仅是简单的编译，要想正式用需要一些其他的设置
  

### 4. vscode细节配置 

<font color="lightred">*上述虽然可以运行c了，但是可用性等太差，需要进行更深一步的配置。编译是在输出窗口上，仅仅可以输出并不可以输入。*</font>

##### 问题1. 按照上述操作c语言虽然能够编译，有序现在的输出是在输出窗口上，所以在运行之后输出是没问题，但是遇到输入操作的话会发现不能输入!

```回答
1.打开文件-首选项-设置
2.在这里找到Code Actions On Saved,点开下方的“在setting.json中编辑”
3.看到打开了一个名为setting.json的json文件
4.在这个json文件中输入代码
"code-runner.runInTerminal": true,
一定要将值改为true，就是允许代码在控制台输出
```

##### 问题2. 在我vscode配置中，我发现我的运行虽然是没问题的，但是如果printf的内容中存在汉字的话输出会有乱码。

```回答
1. 乱码的问题第一反应当然是文字编码的问题，可以更换一下编码方式
2. 看窗口右下角编码方式是什么，我这里是“UTF-8"
3. 点击这个“UTF-8”，看到上方出现了两个选项，选择通过编码保存(Save With Encoding)
4.在新弹出的选择框中选择"Simplified Chinese(GB 2313) gb2312"
5. 再次进行编译，发现不再有乱码的问题了
```

##### 问题3. 在每次进行编译准备的时候会发现生成了两个文件，launch.json和tasks.json，这两个文件有什么用呢？

```json
//launch.json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - 生成和调试活动文件",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "E:\\program files\\code_c\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: gcc.exe 生成活动文件"
        }
    ]
}
```

- 以上代码其中 "externalConsole": false,  这句代表是否要额外打开一个外部的终端，key值为true表示run时结果会在一个外部的终端出现。当然如果是这样，一定要在return 0；之前加一行system("pause");的代码，否则结果会一闪而逝。

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe 生成活动文件",
            "command": "E:\\program files\\code_c\\mingw64\\bin\\gcc.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                //以下这行自己加的,意思是这里选择c/c++的标准，能够用最新的c/c++规范。
                "-std=c11"
                
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

##### 问题4. 如果在编译过程中自己确定代码不存在问题，可是机器识别代码存在问题，并自动标出怎么办

```回答
1. 这如同上述说的c/c++的标准是会有变化的，所以要选择最新的标准
2. 打开文件-首选项-设置-扩展-C/C++ 
3. 找到"C_Cpp › Default: C Standard"，这里设置c的标准，如c11
```



### 5.  小建议

- 代码每次运行之前需要进行保存，虽然ctrl+s可以快速保存，但是仍然不能满足需要，可以在vscode菜单栏下打开文件—自动保存功能，即可以实时编译。

### 6. 总结

经过我的实践：

现在新建一个项目的流程如下

```流程
1. 新建一个文件夹
2. 在vscode加载文件夹
3. 在文件夹中新建文件码代码(如果加载之前的代码中文出现乱，可以点击右下角的编码方式，然后在弹出的“通过编码重新打开”，选择简体中文的编码方式即可)
4. 完成代码后按“F5"进行编译
5. 会弹出一个选择环境的对话框，在这里选择"C++(GDB/LLDB)"
6. 选择编译器，“gcc.exe -生成和调试活动文件”
7. 看到在主文件家中生成一个名为.vscode的文件夹，内部有两个文件，分别是launch.json和tasks.json
8. 按照之前的说明编辑一下这两个json文件即可
9.进行编译

```



  