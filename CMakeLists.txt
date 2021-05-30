project(EVENT_MANAGER)

add_executable(main main.c event_manager.c event_test.c led.c)
add_definitions(-Wall -g)
