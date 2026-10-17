/* ======================================================================================
 * Library       : vhlibtimerstamp
 * Description   : Lightweight C++ timer library for high-precision
 *                 microsecond-level benchmarking on PC, ESP32, and STM32 (DWT).
 * Revision      : 0.0.1
 * Source        : https://github.com/vigatron/vhlibtimerstamp
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/vhtimerstamp.hpp
 * Content size  : 770
 * Date / Time   : 17-10-2026 11:22:41
 * MD5           : 98442234afe2e7079918a81c0883df6c
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2025 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once

#ifdef VHPLATFORM_PC

#include <time.h>

#elif defined(VHPLATFORM_STM32)

#include <cstdint>
#include "main.h"

#elif defined(VHPLATFORM_ESP32)

#include <cstdint>
#include "esp_timer.h"

#else

#error "VHPLATFORM_XXX not specified"

#endif

class VHTimerStamp
{

public:
    VHTimerStamp() = default;

#ifdef VHPLATFORM_STM32
    static void init();
    uint32_t result_ticks();
#endif

#ifdef VHPLATFORM_PC
    long long result_us();
    long long result_ms();
#else
    uint32_t result_us();
    uint32_t result_ms();
#endif


    void start();
    void stop();

private:

#ifdef VHPLATFORM_PC
    struct timespec start_time, end_time;
#endif

#if defined(VHPLATFORM_STM32) || defined(VHPLATFORM_ESP32)
    uint32_t _start;
    uint32_t _stop;
#endif
};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibtimerstamp
 * File             : src/vhtimerstamp.hpp
 * Revision         : 0.0.1
 * Content size     : 770
 * Date / Time      : 17-10-2026 11:22:41
 * MD5              : 98442234afe2e7079918a81c0883df6c
 * Copyright        : © 2025 Viktor Glebov
 * ====================================================================== */