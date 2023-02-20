# C++ Project Template
基本的项目结构组织和基本的CMakeLists的编写组织

## Third Parties
包括了几个自用的第三方库fmt，spdlog，boost, Catch2<br/>
- 在我的电脑上，第一次激活cmake配置时总会出Error，再配置一次之后就能成功了

> boost实在是太大了，完全下载配置完成要20min以上。。。。<br/>
> 第一次编译文件时，这里引用的库都需要编译一次，之后就不用了<br/>
> 所以不需要的小伙伴请删除boost的配置

我这里都是比较粗浅的用法，boost的配置也参考下面的仓库，按他说的做即可
> git@github.com:Orphis/boost-cmake.git

然后，我通常会再添加一个下载目录，类似下面这样

```cmake
FetchContent_Declare(
  Boost
  URL ${BOOST_URL}
  URL_HASH SHA256=${BOOST_URL_SHA256}
  # 下面的SOURCE_DIR是我加的，指示将源码下载到哪儿
  SOURCE_DIR        ${CMAKE_SOURCE_DIR}/third_parties/boost
)
```

当然也可以自己去改造他的CMakeLists.txt的设置，比如现在他下载的是1.71版本的boost，可以改成更新版本的
> 第一次下载boost时非常耗时间，没有需要的话建议删除此配置

## VS code
如果你和我一样使用VS code的话，推荐CMake插件<br/>
安装后，Ctrl + Shift + p，输入CMake，选择CMake配置即可<br/>
此时左边应该会有CMake的图标，点击后可以在这里编译等<br/>
最好让插件自己配置，不要手动输入指令，否则很可能出bug。
> Linux下还好，Windows下实在毛病多多

## 测试一下配置是否成功
- CMake配置参见test下的CMakeLists.txt配置。
- 测试代码参见test/test_third_parties.cpp<br/>

这是我在Windows下的运行测试
```bash
10751@doom-desktop MINGW64 /d/Projects/cpp-project-template (main)
$ bin/Debug/test-third-parties.exe
Default format: 42s 100ms
strftime-like format: 03:15:30
[2022-05-25 19:29:41.526] [info] Welcome to spdlog!
[2022-05-25 19:29:41.527] [error] Some error message with arg: 1
[2022-05-25 19:29:41.527] [warning] Easy padding in numbers like 00000012
[2022-05-25 19:29:41.527] [critical] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[2022-05-25 19:29:41.527] [info] Support for floats 1.23
[2022-05-25 19:29:41.527] [info] Positional args are supported too..
[2022-05-25 19:29:41.528] [info] left aligned
[2022-05-25 19:29:41.528] [debug] This message should be displayed..
```

## git 创建远程分支
```bash
git switch <branch>
git push origin <branch>
# 将branch和远程的branch相关联，以后就可以直接用git push来推送branch的更新到远程了
git push --set-upstream origin <branch>
# Branch '<branch>' set up to track remote branch 'dev' from 'origin'.
```


## doxygen配置
没有配置flex和bison会无法编译

```bash
sudo apt-get install flex
sudo apt-get install bison

git clone https://github.com/doxygen/doxygen.git
cd doxygen
cmake -S . -B build
cd build
cmake -G "Unix Makefiles" ..
make
# 等待编译完成
make install
```