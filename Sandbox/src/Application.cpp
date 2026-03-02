#include "Application.h"
#include <iostream>
#include <Windows.h>

#include <chrono> 
#include <thread>

namespace Helicon
{
   
    bool Application::LaunchCoreSystems()
    {
        HINSTANCE hInstance = GetModuleHandle(nullptr);

        m_Window.CreateLaunchWindow(hInstance, 500, 300);

        auto startTime = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - startTime).count() < 5.0f) {
            m_Window.PollEvents();
        }

        if (!m_Window.Initialize(hInstance, HC_WINDOW_WIDTH, HC_WINDOW_HEIGHT, "Banana Farming Simulator"))
            return false;

        if (!m_renderer->Initialize(m_Window.GetHWND()))
            return false;

        m_Window.DestroyLaunchWindow();

        return true;
    }

    bool Application::LaunchModules()
    {
        return HC_SUCCESS;
    }

    void Application::GameLoop()
    {
        while (!m_Window.ShouldClose())
        {
            m_Window.PollEvents();

            // m_renderer->RenderFrame();
        }

        m_Window.Shutdown();
    }

    void Application::ShutdownModules()
    {
    }

    void Application::ShutdownCoreSystems()
    {
    }
}