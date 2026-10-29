cmake_minimum_required(VERSION 3.22.1)
project(openfg_clone)

add_library(${PROJECT_NAME} SHARED
    main.cpp
)

find_library(log-lib log)
find_library(android-lib android)
find_library(EGL-lib EGL)
find_library(GLESv2-lib GLESv2)

target_link_libraries(${PROJECT_NAME}
    ${log-lib}
    ${android-lib}
    ${EGL-lib}
    ${GLESv2-lib}
    z
)
