#pragma once

#include <counter/counter.hpp>

#include <lager/context.hpp>

#include <imgui.h>

namespace imgui
{
inline void draw(::lager::context<::counter::action> ctx, ::counter::model m)
{
    using namespace ::ImGui;
    Begin("Counter");
    Text("value = %d", m.value);
    ProgressBar(m.value * 0.01f + 0.5f);
    PushButtonRepeat(true);
    if (ArrowButton("##left", ImGuiDir_Left))
    {
        ctx.dispatch(::counter::decrement_action{});
    }
    PopButtonRepeat();
    SameLine(0.0f, GetStyle().ItemInnerSpacing.x);
    if (Button("reset"))
    {
        ctx.dispatch(::counter::reset_action{});
    }
    SameLine(0.0f, GetStyle().ItemInnerSpacing.x);
    PushButtonRepeat(true);
    if (ArrowButton("##right", ImGuiDir_Right))
    {
        ctx.dispatch(::counter::increment_action{});
    }
    PopButtonRepeat();
    End();

    ShowDemoWindow();
}
}
