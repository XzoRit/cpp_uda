#include <counter/counter.hpp>

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

int main(int argc, const char* argv[])
{
    ::counter::model mod{};

    auto buttons = Container::Horizontal({
        Button(" - ",
               [&] {
                   mod = ::counter::update(mod, ::counter::decrement_action{});
               }),
        Button(
            " . ",
            [&] { mod = ::counter::update(mod, ::counter::reset_action{0}); }),
        Button(" + ",
               [&] {
                   mod = ::counter::update(mod, ::counter::increment_action{});
               }),
    });

    auto component = Renderer(buttons, [&] {
        return vbox({
                   text("value = " + std::to_string(mod.value)),
                   separator(),
                   gauge(mod.value * 0.01f + 0.5f),
                   separator(),
                   buttons->Render(),
               }) |
               border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component);

    return 0;

    mod = ::counter::update(mod, ::counter::increment_action{});
}
