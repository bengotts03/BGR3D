#pragma once

#include <memory>
#include <vector>

#include "Window.h"
#include "RuntimeLayer.h"

namespace BGAppCore {

    class Application {
    public:
        static Application& GetApplication() {
            return *_instance;
        }

        Application();
        virtual ~Application();

        virtual void Start();

        Window& GetWindow();
    protected:
        void AddLayer(RuntimeLayer* layer);
    private:
        static Application* _instance;

        std::unique_ptr<Window> _window;
        std::unique_ptr<RuntimeLayerStack> _runtimeLayers;

        bool _isRunning;
    };

    Application* CreateApplication();
}
