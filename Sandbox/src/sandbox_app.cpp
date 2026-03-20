#include "sandbox_app.h"
#include <iostream>

bool app_launch(sandbox_app* app, const char* title)
{
    std::cout << "app_launch\n";

    if (!core_initialize_window(app->core_window, app->core_window.backend,
        CORE_WINDOW_WIDTH, CORE_WINDOW_HEIGHT, title))
    {
        return false;
    }

    if (!renderer_initialize()) 
    {
        return false;
    }

    return true;
}

void app_game_loop(sandbox_app* app)
{
    while (!core_window_should_close(app->core_window)) {
        core_poll_events(app->core_window);
        renderer_draw_frame();
    }
}

// Shutdown in reverse order of initialization 
void app_shutdown(sandbox_app* app)
{
    renderer_shutdown();
    core_shutdown_window(app->core_window);
}
