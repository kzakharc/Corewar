cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES vp_virtual_machine/vp_virtual_main.c vp_virtual_machine/vp_err_u.c
        vp_virtual_machine/vp_basic.c  vp_virtual_machine/vp_commands.c
        op.c
        vp_virtual_machine/virtualm.h op.h corewar.h)

add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)