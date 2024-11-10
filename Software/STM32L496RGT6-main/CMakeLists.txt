cmake_minimum_required(VERSION 3.22)
#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# OpenOCD scripts path
set(OPENOCD_EXECUTABLE openocd)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# Define the build type
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)
endif()

# Set the project name
set(CMAKE_PROJECT_NAME JxWatch)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Include toolchain file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/gcc-arm-none-eabi.cmake)

# Core project settings
project(${CMAKE_PROJECT_NAME} LANGUAGES C ASM)
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)


# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable

file(GLOB_RECURSE LVGL_SOURCES 
    ./Libraries/lvgl/src/core/*.c
    ./Libraries/lvgl/src/draw/*.c
    ./Libraries/lvgl/src/extra/*.c
    ./Libraries/lvgl/src/font/*.c
    ./Libraries/lvgl/src/hal/*.c
    ./Libraries/lvgl/src/misc/*.c
    ./Libraries/lvgl/src/widgets/*.c
    ./Libraries/lvgl/demos/benchmark/*.c
    ./Libraries/lvgl/demos/music/*.c
    ./Libraries/lvgl/demos/widgets/*.c
)
    
    
# Exclude specific subdirectories by removing their files from LVGL_SOURCES
file(GLOB_RECURSE EXCLUDE_SOURCES 
    ./Libraries/lvgl/src/extra/libs/*.c
    ./Libraries/lvgl/src/draw/arm2d/*.c
    ./Libraries/lvgl/src/draw/nxp/*.c
    ./Libraries/lvgl/src/draw/renesas/*.c
    ./Libraries/lvgl/src/draw/sdl/*.c
    # ./Libraries/lvgl/src/draw/stm32_dma2d/*.c
    ./Libraries/lvgl/src/draw/swm341_dma2d/*.c
)


file(GLOB_RECURSE APP_SOURCES 
    ./App/*.c
    ./App/tasks/*.c
    ./App/gui/*.c
    ./App/gui/fonts/*.c
)

# Remove the excluded files from the LVGL_SOURCES list
list(REMOVE_ITEM LVGL_SOURCES ${EXCLUDE_SOURCES})


target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here

    # APP
    ${APP_SOURCES}

    # Test
    ./Test/test.c
    ./Test/test_cst816t.c

    # BSP
    ./BSP/LCD/st7789v.c
    ./BSP/LCD/cst816t.c

    # FreeRTOS
    ./Libraries/FreeRTOS-Kernel/list.c 
    ./Libraries/FreeRTOS-Kernel/queue.c 
    ./Libraries/FreeRTOS-Kernel/tasks.c 
    ./Libraries/FreeRTOS-Kernel/timers.c 
    ./Libraries/FreeRTOS-Kernel/stream_buffer.c 
    ./Libraries/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c 
    ./Libraries/FreeRTOS-Kernel/portable/MemMang/heap_4.c

    # LVGL
    ./Core/Src/lv_port_disp.c
    ./Core/Src/lv_port_indev.c
    ${LVGL_SOURCES}

    
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths

    # Core
    ./Core/Inc

    # Drivers
    ./Drivers/ST/STM32L4xx/include
    ./Drivers/STM32L4xx_HAL_Driver/Inc

    # BSP
    ./BSP/LCD

    # FreeRTOS
    ./Libraries/FreeRTOS-Kernel/include
    ./Libraries/FreeRTOS-Kernel/portable/GCC/ARM_CM4F

    # LVGL
    ./Libraries/lvgl/src
    ./Libraries/lvgl/demos/benchmark/
    ./Libraries/lvgl/demos/widgets/
    ./Libraries/lvgl/demos/music/

    # APP 
    ./App/tasks # tasks
    ./App/gui # gui
    ./App/gui/fonts # fonts
    ./App/gui/images # images
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
    LV_CONF_INCLUDE_SIMPLE 
    LV_LVGL_H_INCLUDE_SIMPLE
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)



# Execute custom command after compiling
add_custom_command(
    TARGET "${CMAKE_PROJECT_NAME}"
    POST_BUILD
    # Build .hex and .bin files
    COMMAND arm-none-eabi-objcopy -Obinary "${CMAKE_PROJECT_NAME}.elf" "${CMAKE_PROJECT_NAME}.bin"
    COMMAND arm-none-eabi-objcopy -Oihex "${CMAKE_PROJECT_NAME}.elf" "${CMAKE_PROJECT_NAME}.hex"
    COMMENT "Building ${CMAKE_PROJECT_NAME}.bin and ${CMAKE_PROJECT_NAME}.hex"
    # Display sizes
    COMMAND arm-none-eabi-size --format=berkeley ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex
    COMMENT "Invoking: Cross ARM GNU Print Size"
)


add_custom_target(flash
    COMMAND ${OPENOCD_EXECUTABLE} -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd/stlink.cfg -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd/stm32l4x.cfg -c "program ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}.bin verify reset exit 0x08000000"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}.bin
    COMMENT "Flashing ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}.bin"
)


add_custom_target(debug
    COMMAND ${OPENOCD_EXECUTABLE} -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd/stlink.cfg -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd/stm32l4x.cfg
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}.elf
    COMMENT "Debugging ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}.elf"
)
