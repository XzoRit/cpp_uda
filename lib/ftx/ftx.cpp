#include <ftx/ftx.hpp>

#include <counter/counter.hpp>

#include <ftxui/dom/elements.hpp>

#include <string>

using namespace ftxui;

namespace ftx
{
ui::ui(::model::model m)
    : mod{m}
    , buttons{Container::Horizontal({
          Button(" - ",
                 [this] {
                     mod = ::model::update(mod, ::counter::decrement_action{});
                 }),
          Button(" . ",
                 [this] {
                     mod = ::model::update(mod, ::counter::reset_action{0});
                 }),
          Button(" + ",
                 [this] {
                     mod = ::model::update(mod, ::counter::increment_action{});
                 }),
      })}
    , dialog{Renderer(buttons, [this] {
        return vbox({
                   text("value = " + std::to_string(mod.counter.value)),
                   separator(),
                   gauge(mod.counter.value * 0.01f + 0.5f),
                   separator(),
                   buttons->Render(),
               }) |
               border;
    })}
{
}
}
