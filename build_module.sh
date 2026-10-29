#!/bin/bash
MODULE_DIR=/home/afrizal/OpenFG-Project/module
SRC_DIR=$MODULE_DIR/src

# Try to build with NDK if possible
if [ -d "/home/afrizal/Android/Sdk/ndk/android-ndk-r26d" ]; then
    echo "Building with NDK..."
    cd $SRC_DIR
    /home/afrizal/Android/Sdk/ndk/android-ndk-r26d/ndk-build NDK_PROJECT_PATH=$SRC_DIR APP_BUILD_SCRIPT=Android.mk NDK_APPLICATION_MK=Application.mk 2>&1 | tail -20
    # Copy outputs
    if [ -f "libs/arm64-v8a/libopenfg_clone.so" ]; then
        cp libs/arm64-v8a/libopenfg_clone.so $MODULE_DIR/zygisk/arm64-v8a.so
    fi
    if [ -f "libs/armeabi-v7a/libopenfg_clone.so" ]; then
        cp libs/armeabi-v7a/libopenfg_clone.so $MODULE_DIR/zygisk/armeabi-v7a.so
    fi
fi

# Zip the module
cd $MODULE_DIR
zip -r ../openfg_clone.zip . 2>&1 | tail -5
echo "Done"
