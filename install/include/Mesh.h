#pragma once
#include "glad/glad.h"

#include "Camera.h"
#include "Material.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

namespace BGR3D {
    enum ProjectionMethod {
        Together,
        Separate
    };

    class Mesh {
    public:
        Mesh(std::vector<BGRCore::Vertex>& vertices, std::vector<GLuint>& indices, Material& material);

        void Draw(BGRCore::Shader& shader, BGRCore::Camera& camera, ProjectionMethod projectionMethod);

        int GetNumVerts() const;
        int GetNumIndices() const;

        void SetCustomDrawMode(int drawMode);

        glm::vec3 Position = glm::vec3(0, 0, 0);
    private:
        std::vector<BGRCore::Vertex> _vertices;
        std::vector<GLuint> _indices;
        Material _material;

        BGRCore::VertexArray _vertexArrayObject;

        int _drawMode = GL_TRIANGLES;
    };
}
