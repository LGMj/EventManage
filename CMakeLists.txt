cmake_minimum_required(VERSION 3.10)

# 项目信息
project(EVENT_MANAGER LANGUAGES C)

# 设置C标准
set(CMAKE_C_STANDARD 11)

# 包含子目录
add_subdirectory(EM)
add_subdirectory(lcd)
add_subdirectory(test)

# 添加主程序源文件
add_executable(${PROJECT_NAME} main.c)

# 链接子目录中的库
target_link_libraries(${PROJECT_NAME} EM lcd test)
