#!/bin/bash
# Try to build with gradle if available
if command -v gradle &> /dev/null; then
    cd /home/afrizal/OpenFG-Project/app
    gradle assembleDebug 2>&1 | tail -30
fi
