#include <console/console.hpp>
#include <counter/counter.hpp>

#include <iostream>

int main()
{
    ::counter::model m{};
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
            m = ::counter::update(m, act.value());
        }
        ::console::draw(m);
    }
}
