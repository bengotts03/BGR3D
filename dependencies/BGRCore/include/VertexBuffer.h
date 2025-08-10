#pragma once

#include "glad/glad.h"
#include <glm/glm.hpp>
#include <vector>

namespace BGRCore {
    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Colour;
        glm::vec2 TextureCoords;
        glm::vec3 Normals;
    };

    class VertexBuffer {
    public:
        VertexBuffer(std::vector<Vertex>& vertices);
        ~VertexBuffer() = default;

        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint ID;
    };
}