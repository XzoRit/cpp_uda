#pragma once

#include <model/model.hpp>

#include <ftxui/component/component.hpp>

namespace ftx
{
struct ui
{
  public:
    ui(::model::model m);

  private:
    ::model::model mod;
    ::ftxui::Component buttons;

  public:
    ::ftxui::Component dialog;
};
}
