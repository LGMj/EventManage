# EM目录下的CMakeLists.txt
add_library(EM event_manager.c)

# 包含头文件目录
target_include_directories(EM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
