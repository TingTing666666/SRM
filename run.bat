@echo off
REM �л���FactoryĿ¼
cd Factory

REM ɾ��֮ǰ�Ĺ����ļ�
if exist build rd /s /q build
mkdir build
cd build

REM ����CMake����
cmake ..
if errorlevel 1 goto :error

REM ������Ŀ
cmake --build .
if errorlevel 1 goto :error

REM ���г���
Debug\ProductFactory.exe
if errorlevel 1 goto :error

goto :end

:error
echo ����������ʧ�ܣ�
pause

:end
pause
