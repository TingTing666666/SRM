@echo off
REM 切换到Factory目录
cd Factory

REM 删除之前的构建文件
if exist build rd /s /q build
mkdir build
cd build

REM 运行CMake构建
cmake ..
if errorlevel 1 goto :error

REM 编译项目
cmake --build .
if errorlevel 1 goto :error

REM 运行程序
Debug\ProductFactory.exe
if errorlevel 1 goto :error

goto :end

:error
echo 构建或运行失败！
pause

:end
pause
