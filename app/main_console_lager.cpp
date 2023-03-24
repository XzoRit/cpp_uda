#include <console/console.hpp>
#include <counter/counter.hpp>
#include <model/model.hpp>

#include <lager/event_loop/manual.hpp>
#include <lager/store.hpp>

int main()
{
    auto store{::lager::make_store<::model::action>(
        ::model::model{.counter = {.value = 0}},
        ::lager::with_manual_event_loop{})};
    ::lager::watch(store, [](auto&& m) { ::console::draw(m); });

    auto event = char{};
    while (std::cin >> event)
    {
        if (auto act{::console::intent(event)}; act.has_value())
        {
            store.dispatch(act.value());
        }
        if (event == 'q')
        {
            break;
        }
    }
}
