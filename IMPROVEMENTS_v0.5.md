# Improvements in v0.5

## Native Module
- **Dobby Integration**: Added Dobby for proper inline hooking
- **EGL Hooking**: Actual hooking of eglSwapBuffers with Dobby
- **Vulkan Support**: Added vkQueuePresentKHR hooking
- **Config System**: Reads from packages.list and app private files
- **Frame Pipeline**: Enhanced frame processor with viewport capture
- **FSR Framework**: Prepared for FSR 1.0 integration
- **Better Logging**: Improved debug logging

## Issues Fixed
- Added missing source files to Android.mk
- Proper config reading like original OpenFG
- Better module structure

## Files Updated
- hooks.cpp/h - Dobby integration
- config.cpp/h - Enhanced config reading
- frame_processor.cpp - Better implementation
- Android.mk - Dobby static lib + all sources
- main.cpp - Improved entry points
