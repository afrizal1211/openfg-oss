# Step 2: Hook EGL functions to intercept frames

Goals:
1. Hook eglSwapBuffers - called every frame when swapping buffers to display
2. Detect if we're in a target app (read config)
3. Log/intercept frames
4. Store reference to original function

Approach:
- Use PLT hooking or inline hooking (Dobby)
- Need to install hooks early in injection
- Track display/surface/context
