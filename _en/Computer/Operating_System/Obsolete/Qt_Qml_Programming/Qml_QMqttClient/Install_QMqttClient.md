
### QMQTT客户端编译安装

编译安装教程参考，https://dsyx.github.io/2021/01/13/add-mqtt-module-for-qt5/

示例程序
qtmqtt/examples/


步骤零：下载QtMQTT源代码
git clone "https://codereview.qt-project.org/qt/qtmqtt" && (cd "qtmqtt" && mkdir -p `git rev-parse --git-dir`/hooks/ && curl -Lo `git rev-parse --git-dir`/hooks/commit-msg https://codereview.qt-project.org/tools/hooks/commit-msg && chmod +x `git rev-parse --git-dir`/hooks/commit-msg)

步骤一：切换分支
cd qtmqtt
git branch -a
git checkout 5.12.9

步骤二：编译安装qtmqtt
qmake
make all
make install

步骤三：编译安装qtmqtt文档
make docs
make install_docs

步骤四：编译安装qtmqtt示例
make sub-examples-install_subtargets

步骤五：Qt使用mqtt模块，pro文件配置
QT+=mqtt
