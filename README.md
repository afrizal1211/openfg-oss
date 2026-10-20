# OpenFG-OSS

Open-source interpolated frame generation for Android games.

## Architecture
- `module/`: Zygisk native module (`libopenfg.so`) hooks `BufferQueueProducer::queueBuffer`,
  runs optical flow + interpolation, presents with `eglPresentationTimeANDROID`.
- `app/`: Kotlin/Compose companion app selects target packages and writes config to
  `/data/adb/openfg/`.

## Improvements vs OpenFG
- Open source, auditable native code.
- Pluggable flow backends (software CPU, GLES compute, Vulkan).
- Thermal/battery-aware adaptive quality.
- Explicit "no online/anti-cheat" guard.
- Documented, versioned config (`fg_config` v2).

## Status
Skeleton only. Contributions welcome.
