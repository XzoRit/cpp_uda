#pragma once

#include <model/model.hpp>

#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/cereal.hpp>

#include <fstream>

namespace persist
{
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
        return {};
    }
}
}
