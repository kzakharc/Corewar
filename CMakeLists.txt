cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncurses")

file(GLOB COR "*.c" "*.h")

file(GLOB LIBFT "libft/src/libft/*.c")

file(GLOB VM "cor/virtual_machine/*.c" "cor/instructions/*.c" "cor/virtual_machine/*.h")

file(GLOB VIS "cor/visualisation/*.c" "cor/visualisation/*.h")

add_executable(corewar ${SOURCE_FILES} ${LIBFT} ${VM} ${VIS} ${COR})

target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)