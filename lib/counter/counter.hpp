#pragma once

#include <variant>

namespace counter
{
struct model
{
    int value = 0;
    bool operator==(const model&) const = default;
};
struct increment_action
{
};
struct decrement_action
{
};
struct reset_action
{
    int new_value = 0;
};
using action = std::variant<increment_action, decrement_action, reset_action>;
struct visitor
{
    auto operator()(increment_action) const
    {
        return model{curr_model.value + 1};
    }
    auto operator()(decrement_action) const
    {
        return model{curr_model.value - 1};
    }
    auto operator()(reset_action a) const
    {
        return model{a.new_value};
    }
    model curr_model{};
};
inline model update(model curr_model, action action)
{
    return std::visit(visitor{curr_model}, action);
}
}
