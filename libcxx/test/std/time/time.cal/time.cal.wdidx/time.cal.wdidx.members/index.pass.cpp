//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++03, c++11, c++14, c++17

// <chrono>
// class weekday_indexed;

// constexpr unsigned index() const noexcept;
//  Returns: index_

#include <chrono>
#include <cassert>
#include <type_traits>
#include <utility>

#include "test_macros.h"

int main(int, char**)
{
    using weekday         = std::chrono::weekday;
    using weekday_indexed = std::chrono::weekday_indexed;

    ASSERT_NOEXCEPT(                    std::declval<const weekday_indexed>().index());
    ASSERT_SAME_TYPE(unsigned, decltype(std::declval<const weekday_indexed>().index()));

    static_assert( weekday_indexed{}.index() == 0, "");

    // This is the valid range of values defined in [time.cal.wdidx.members]/1.
    for (unsigned i = 0; i <= 7; ++i)
    {
        weekday_indexed wdi(weekday{2}, i);
        assert( static_cast<unsigned>(wdi.index()) == i);
    }

  return 0;
}
