/* ======================================================================================
 * Library       : vhlibtimerstamp
 * Description   : Lightweight C++ timer library for high-precision
 *                 microsecond-level benchmarking on PC, ESP32, and STM32 (DWT).
 * Revision      : 0.0.2
 * Source        : https://github.com/vigatron/vhlibtimerstamp
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/vhtimerstamp.hpp
 * Content size  : 1013
 * Date / Time   : 17-10-2026 16:02:02
 * MD5           : 4f454b62ed93028fad9767a2ff668e6b
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2025-2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once

#ifdef VHPLATFORM_PC

#include <time.h>

#elif defined(VHPLATFORM_STM32)

#include <cstdint>

#if defined(STM32F407xx)
#include "stm32f4xx_hal.h"
#elif defined(STM32F746xx)
#include "stm32f7xx_hal.h"
#elif defined(STM32H750xx)
#include "stm32h7xx_hal.h"
#else 
#error "vhlibtimerstamp: Unknown Platform: STM32F407xx / STM32F746xx / STM32H750xx ?"
#endif

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
 * Revision         : 0.0.2
 * Content size     : 1013
 * Date / Time      : 17-10-2026 16:02:02
 * MD5              : 4f454b62ed93028fad9767a2ff668e6b
 * Copyright        : © 2025-2026 Viktor Glebov / V01G04A81
 * ====================================================================== */