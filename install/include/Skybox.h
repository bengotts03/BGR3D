#pragma once

#include "Mesh.h"
#include "Shader.h"

namespace BGR3D {
    class Skybox {
    public:
        Skybox(BGRCore::Camera* cam);
        ~Skybox();

        void Render();
    private:
        BGRCore::Shader* _shader;
        Mesh* _mesh;
        BGRCore::Camera* _camera;
    };
}