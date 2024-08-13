# lcd目录下的CMakeLists.txt
add_library(lcd led.c)

# 包含EM库
target_link_libraries(lcd PUBLIC EM)

# 包含头文件目录
target_include_directories(lcd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
