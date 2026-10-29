# Build Guide

## Module (Zygisk)
```bash
cd /home/afrizal/OpenFG-Project/module/src
# With NDK
/home/afrizal/Android/Sdk/ndk/android-ndk-r26d/ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=Android.mk NDK_APPLICATION_MK=Application.mk
# Copy libs/*/libopenfg_clone.so to ../zygisk/
# Zip module
```

## Companion App
- Build with Android Studio/Gradle
- Requires libsu dependency
