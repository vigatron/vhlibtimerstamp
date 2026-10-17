# vhlibtimerstamp

Lightweight C++ timer library for high-precision microsecond-level benchmarking. 

Supports **PC (POSIX)**, **ESP32**, and **STM32 (DWT cycle counter)**.

## Features
- **Cross-platform**: PC (`clock_gettime`), ESP32 (`esp_timer`), STM32 (DWT `CYCCNT`).
- **High precision**: Microsecond (`us`) and millisecond (`ms`) resolution.
- **STM32 DWT Support**: Direct hardware cycle counting for Cortex-M7 / STM32H7.
- **Benchmarking Utility**: Built-in `TimerAverager` to calculate min, max, and average execution times.
- **Modern C++**: Requires C++17.

## Requirements
- CMake >= 3.16
- C++17 compatible compiler
- Platform-specific headers (e.g., `esp_timer.h` for ESP32, CMSIS for STM32)

## Build & Integration

Add the library to your project via CMake:

```cmake
# Define your target platform before including the library
add_compile_definitions(VHPLATFORM_PC) # or VHPLATFORM_STM32, VHPLATFORM_ESP32

add_subdirectory(vhlibtimerstamp)
target_link_libraries(your_target PRIVATE vhlib_timerstamp)
```

## Usage

### PC / ESP32
```cpp
#include "vhtimerstamp.hpp"

VHTimerStamp timer;
timer.start();
// ... code to benchmark ...
timer.stop();

long long elapsed_us = timer.result_us();
```

### STM32
*Note: DWT requires one-time initialization.*
```cpp
#include "vhtimerstamp.hpp"

// Call once at startup
VHTimerStamp::init(); 

VHTimerStamp timer;
timer.start();
// ... code to benchmark ...
timer.stop();

uint32_t ticks = timer.result_ticks();
uint32_t us = timer.result_us();
```

### Using TimerAverager
```cpp
#include "vhtimeaverager.hpp"
#include "vhtimerstamp.hpp"

VHTimerAverager averager;
VHTimerStamp timer;

for (int i = 0; i < 100; i++) {
    timer.start();
    // ... your function ...
    timer.stop();
    averager.add(timer.result_us());
}

int avg = averager.result(100);
int min = averager.resultmin();
int max = averager.resultmax();
```

## License
Distributed under the MIT License. See `LICENSE` for more information.

GitHub Repository  
[https://github.com/vigatron/vhlibtimerstamp](https://github.com/vigatron/vhlibtimerstamp)

**(C) 2025 V01G04A81**  

