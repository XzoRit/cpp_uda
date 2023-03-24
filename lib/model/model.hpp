#pragma once

#include <counter/counter.hpp>

#include <variant>

namespace model
{
struct model
{
    ::counter::model counter{};
    bool operator==(const model&) const = default;
};
using action = ::counter::action;
struct visitor
{
    auto operator()(::counter::action act) const
    {
        const auto new_counter{::counter::update(curr_model.counter, act)};
        return model{new_counter};
    }
    model curr_model{};
};
inline model update(model curr_model, action act)
{
    return std::visit(visitor{.curr_model = curr_model}, act);
}
}

#include <cereal/cereal.hpp>

namespace model
{
template <class Archive>
inline void serialize(Archive& ar, model& m)
{
    ar(cereal::make_nvp("counter", m.counter));
}
}
