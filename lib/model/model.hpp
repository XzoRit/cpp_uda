#pragma once

namespace model
{
struct model
{
};
using action = int;
struct visitor
{
    auto operator()(int) const
    {
        return curr_model;
    }
    model curr_model{};
};
inline model update(model curr_model, action)
{
    return curr_model;
}
}
