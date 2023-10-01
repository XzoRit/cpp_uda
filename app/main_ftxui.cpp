#include <ftx/ftx.hpp>
#include <model/model.hpp>

#include <ftxui/component/screen_interactive.hpp>

#include <memory>
#include <string>

int main()
{
    auto screen{::ftxui::ScreenInteractive::FitComponent()};
    ::ftx::ui ui{::model::model{}};
    screen.Loop(ui.dialog);

    return 0;
}
