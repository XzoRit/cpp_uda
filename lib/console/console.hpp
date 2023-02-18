#pragma once

#include <counter/counter.hpp>

#include <iostream>
#include <optional>

namespace console
{
inline std::optional<::counter::action> intent(char event)
{
    switch (event)
    {
    case '+':
        return ::counter::increment_action{};
    case '-':
        return ::counter::decrement_action{};
    case '.':
        return ::counter::reset_action{0};
    default:
        return std::nullopt;
    }
}
inline void draw(::counter::model m)
{
    std::cout << "current value: " << m.value << '\n';
}
}
