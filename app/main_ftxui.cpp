#include <counter/counter.hpp>
#include <model/model.hpp>

#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/loop.hpp>
#include <ftxui/component/mouse.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include <memory>
#include <string>

using namespace ftxui;

int main()
{
    ::model::model mod{};

    auto buttons = Container::Horizontal({
        Button(
            " - ",
            [&] { mod = ::model::update(mod, ::counter::decrement_action{}); }),
        Button(" . ",
               [&] { mod = ::model::update(mod, ::counter::reset_action{0}); }),
        Button(
            " + ",
            [&] { mod = ::model::update(mod, ::counter::increment_action{}); }),
    });

    auto component = Renderer(buttons, [&] {
        return vbox({
                   text("value = " + std::to_string(mod.counter.value)),
                   separator(),
                   gauge(mod.counter.value * 0.01f + 0.5f),
                   separator(),
                   buttons->Render(),
               }) |
               border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component);

    return 0;
}
