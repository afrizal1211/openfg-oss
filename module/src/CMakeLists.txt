cmake_minimum_required(VERSION 3.22.1)
project(openfg_clone)

# Define paths
set(DOBBY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third_party/dobby)

add_library(openfg_clone SHARED
    main.cpp
    hooks.cpp
    hooks_vulkan.cpp
    config.cpp
    frame_processor.cpp
    fsr.cpp
    interpolation.cpp
)

# Include directories
target_include_directories(openfg_clone PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${DOBBY_PATH}/include
)

# Link libraries
target_link_libraries(openfg_clone
    log
    android
    EGL
    GLESv3
    dl
    vulkan
    z
)

