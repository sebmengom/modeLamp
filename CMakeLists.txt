cmake_minimum_required(VERSION 3.17)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(modeLamp C CXX ASM)
pico_sdk_init()

add_compile_options(-fno-exceptions -fno-rtti)

add_executable(modeLamp buttonControl.cpp pwmController.cpp main.cpp ledControl.cpp)

target_link_libraries(modeLamp pico_stdlib hardware_adc hardware_pwm)

pico_enable_stdio_usb(modeLamp 1)
pico_enable_stdio_uart(modeLamp 0)
pico_add_extra_outputs(modeLamp)

add_custom_target(flash COMMAND cp -x $<TARGET_FILE_DIR:modeLamp>/modeLamp.uf2 /Volumes/RPI-RP2/ DEPENDS modeLamp COMMENT "Flashing modeLamp")
