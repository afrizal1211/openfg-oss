#ifndef FRAME_PROCESSOR_H
#define FRAME_PROCESSOR_H

class FrameProcessor {
public:
    void processFrame();
    void applyUpscaling();
    void generateInterpolatedFrames();
};

#endif
