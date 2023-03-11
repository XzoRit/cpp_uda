#include <console/console.hpp>
#include <model/model.hpp>

#include <iostream>

////
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/cereal.hpp>

#include <fstream>
#include <ios>

using oarch = ::cereal::JSONOutputArchive;
using iarch = ::cereal::JSONInputArchive;

inline void save(::model::model m)
{
    std::ofstream f{"persisted_data"};
    oarch archive{f};
    archive(cereal::make_nvp("model", m));
}

inline ::model::model load()
{
    try
    {
        std::ifstream f{"persisted_data"};
        iarch archive{f};
        ::model::model m{};
        archive(m);
        return m;
    }
    catch (...)
    {
        std::cout << "b";
        return {};
    }
}
////

int main()
{
    ::model::model m{load()};
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
            save(m);
        }
        ::console::draw(m);
    }
}
