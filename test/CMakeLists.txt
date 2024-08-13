# test目录下的CMakeLists.txt
add_library(test event_test.c)

# 包含EM库
target_link_libraries(test PUBLIC EM)

# 包含头文件目录
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
