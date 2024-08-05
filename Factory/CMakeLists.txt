cmake_minimum_required(VERSION 3.10)

# 项目信息
project(FactoryProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 添加可执行文件
add_executable(ProductFactory main.cpp Factory.cpp)
