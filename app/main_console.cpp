#include <console/console.hpp>
#include <model/model.hpp>

#include <iostream>

int main()
{
    ::model::model m{};
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
        }
        ::console::draw(m);
    }
}
