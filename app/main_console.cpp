#include "persist.hpp"

#include <console/console.hpp>
#include <model/model.hpp>

#include <iostream>

///
#include <variant>
#include <vector>

namespace history
{
struct back_action
{
};

struct forward_action
{
};

using action = std::variant<back_action, forward_action>;

template <class Model, class Action>
struct history
{
    Model model;
    std::vector<Model> past{};
    typename std::vector<Model>::size_type idx{past.size() - 1};
    using action = std::variant<::history::action, Action>;
};

template <class Model, class Action>
struct history_visitor
{
    auto operator()(back_action) const
    {
        return model;
    }
    auto operator()(forward_action) const
    {
        return model;
    }
    history<Model, Action> model;
};

template <class Model, class Action>
struct visitor
{
    auto operator()(Action act) const
    {
        auto new_mod{update(model.model, act)};
        model.model = new_mod;
        model.past.push_back(new_mod);
        ++model.idx;
        return model;
    }
    auto operator()(action act) const
    {
        auto new_mod{std::visit(history_visitor{model}, act)};
        return new_mod;
    }
    history<Model, Action> model;
};

template <class Model, class Action>
inline auto update(::history::history<Model, Action> history,
                   typename ::history::history<Model, Action>::action action)
{
    std::visit(visitor{history}, action);
    return history;
}
}
///

int main()
{
    ::history::history<::model::model, ::model::action> _{};
    ::model::model m{::persist::load()};
    ::console::draw(m);
    char event{};
    while (std::cin >> event)
    {
        if (event == 'q')
        {
            break;
        }
        if (auto act{::console::intent(event)}; act.has_value())
        {
            m = ::model::update(m, act.value());
            ::persist::save(m);
        }
        ::console::draw(m);
    }
}
