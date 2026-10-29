cmake_minimum_required(VERSION 3.22.1)
project(openfg_clone)

# Dobby sources - focused on arm64
set(DOBBY_SOURCES
    third_party/dobby_src/dobby.cpp
    third_party/dobby_src/Backend/UserMode/PlatformUtil/Linux/ProcessRuntime.cc
    third_party/dobby_src/Backend/UserMode/UnifiedInterface/platform-posix.cc
    third_party/dobby_src/Backend/UserMode/UnifiedInterface/semaphore.cc
    third_party/dobby_src/Backend/UserMode/Thread/PlatformThread.cc
    third_party/dobby_src/Backend/UserMode/Thread/platform-thread-posix.cc
    third_party/dobby_src/TrampolineBridge/Trampoline/trampoline_arm64.cc
    third_party/dobby_src/TrampolineBridge/ClosureTrampolineBridge/arm64/ClosureTrampolineARM64.cc
    third_party/dobby_src/TrampolineBridge/ClosureTrampolineBridge/arm64/closure_bridge_arm64.cc
    third_party/dobby_src/TrampolineBridge/ClosureTrampolineBridge/arm64/helper_arm64.cc
    third_party/dobby_src/InstructionRelocation/arm64/InstructionRelocationARM64.cc
    third_party/dobby_src/core/assembler/assembler-arm.cc
    third_party/dobby_src/core/codegen/codegen-arm.cc
)

add_library(dobby STATIC ${DOBBY_SOURCES})
target_include_directories(dobby PUBLIC third_party/dobby/include)

add_library(openfg_clone SHARED
    main.cpp
    hooks.cpp
    hooks_vulkan.cpp
    config.cpp
    frame_processor.cpp
    fsr.cpp
    interpolation.cpp
)

target_include_directories(openfg_clone PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/dobby/include
)

target_link_libraries(openfg_clone
    dobby
    log
    android
    EGL
    GLESv3
    dl
    vulkan
    z
)
