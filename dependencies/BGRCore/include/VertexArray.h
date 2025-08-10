#pragma once

#include <glad/glad.h>
#include "VertexBuffer.h"

namespace BGRCore {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray() = default;

        void LinkAttribute(VertexBuffer& vertexBuffer, GLuint layout, GLuint numberOfComponents, GLenum type, GLsizeiptr stride, void* offset);
        void Bind();
        void Unbind();
        void Delete();
    private:
        GLuint ID;
    };
}
