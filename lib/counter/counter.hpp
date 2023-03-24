#pragma once

#include <variant>

namespace counter
{
struct model
{
    int value{};
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
    int new_value{};
};
using action = std::variant<increment_action, decrement_action, reset_action>;
struct visitor
{
    model operator()(increment_action) const
    {
        return {.value = curr_model.value + 1};
    }
    model operator()(decrement_action) const
    {
        return {.value = curr_model.value - 1};
    }
    model operator()(reset_action a) const
    {
        return {.value = a.new_value};
    }
    model curr_model{};
};
inline model update(model curr_model, action action)
{
    return std::visit(visitor{.curr_model = curr_model}, action);
}
}

#include <cereal/cereal.hpp>

namespace counter
{
template <class Archive>
inline void serialize(Archive& ar, model& m)
{
    ar(cereal::make_nvp("value", m.value));
}
}
