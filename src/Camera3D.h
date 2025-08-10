#pragma once

#include "glad/glad.h"
#include "Camera.h"
#include "Window.h"

namespace BGR3D {
    class Camera3D : public BGRCore::Camera {
    public:
        Camera3D(BGAppCore::Window* window, int width, int height, glm::vec3 pos);
    };
}