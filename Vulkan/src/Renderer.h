#pragma once
#include "IRenderer.h"
#include "InstanceWrapper.h"
#include "Validation.h"
#include "Surface.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"


class Renderer : public IRenderer {
public:
    Renderer();

    bool Initialize(HWND hwnd, HINSTANCE hInstance) override;
    void Shutdown() override;
private:
    Validation validation_; 
    std::vector<const char*> extensions_;
    InstanceWrapper instance_;
    Surface surface_;
    PhysicalDevice physicalDevice_;
    LogicalDevice logicalDevice_;

    
};
