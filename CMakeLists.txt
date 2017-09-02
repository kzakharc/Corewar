cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES cor/virtual_machine/vp_virtual_main.c cor/virtual_machine/vp_err_u.c
        cor/virtual_machine/vp_basic.c cor/virtual_machine/vp_commands.c
        cor/virtual_machine/vp_instructions.c
        op.c
        cor/virtual_machine/virtualm.h op.h corewar.h)

add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)