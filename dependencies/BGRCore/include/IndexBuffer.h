#pragma once

#include <vector>
#include <glad/glad.h>

namespace BGRCore {
    class IndexBuffer {
    public:
        IndexBuffer(std::vector<GLuint>& indices);
        ~IndexBuffer() = default;

        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint ID;
    };
}