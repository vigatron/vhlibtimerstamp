/* ======================================================================================
 * Library       : vhlibtimerstamp
 * Description   : Lightweight C++ timer library for high-precision
 *                 microsecond-level benchmarking on PC, ESP32, and STM32 (DWT).
 * Revision      : 0.0.2
 * Source        : https://github.com/vigatron/vhlibtimerstamp
 * Disclaimer    : Provided "AS IS", without warranty.
 * License       : MIT
 * File          : src/vhtimeaverager.hpp
 * Content size  : 720
 * Date / Time   : 17-10-2026 16:02:02
 * MD5           : 3751ce34946594aa8ad17a499c288f7f
 * Notes         : MD5 = file content without header/footer
 * Encoding      : UTF-8
 * Author        : Viktor Glebov / V01G04A81
 * Copyright     : © 2025-2026 Viktor Glebov
 * ========================[ BEGIN FILE CONTENT ]====================================== */
#pragma once

#include <cstdint>

class VHTimerAverager {

    public:

        VHTimerAverager() {
            reset();
        }

        void reset() {
            idx = 0; min = 0; max = 0; summ = 0;
        }

        void add(int v) {
            if(!idx++) {
                min = v; max = v;
            } else {
                if(v<min) min = v;
                if(v>max) max = v;
            }
            summ += v;
        }

        int resultmin   () const { return min; }
        int resultmax   () const { return max; }
        int result      (int passes_count) const { return summ / passes_count; }

    private:

        int     idx;
        long    summ;
        int     min;
        int     max;
};
/* ========================[  END FILE CONTENT  ]========================
 * Library          : vhlibtimerstamp
 * File             : src/vhtimeaverager.hpp
 * Revision         : 0.0.2
 * Content size     : 720
 * Date / Time      : 17-10-2026 16:02:02
 * MD5              : 3751ce34946594aa8ad17a499c288f7f
 * Copyright        : © 2025-2026 Viktor Glebov / V01G04A81
 * ====================================================================== */