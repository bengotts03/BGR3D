#include "Mesh.h"
#include "IndexBuffer.h"

namespace BGR3D {
    Mesh::Mesh(std::vector<BGRCore::Vertex>& vertices, std::vector<GLuint>& indices, Material& material)
    : _vertices(vertices), _indices(indices), _material(material)
    {
        _vertexArrayObject.Bind();

        auto vertexBufferObject = BGRCore::VertexBuffer(_vertices);
        auto indexBufferObject = BGRCore::IndexBuffer(_indices);

        // Link vertex position as attribute layout 0
        _vertexArrayObject.LinkAttribute(vertexBufferObject, 0, 3,
            GL_FLOAT, 11 * sizeof(float), (void*)0);
        // Link vertex colour as attribute layout 1
        _vertexArrayObject.LinkAttribute(vertexBufferObject, 1, 3,
            GL_FLOAT, 11 * sizeof(float), (void*)(sizeof(float) * 3));
        // Link vertex tex coords as attribute layout 2
        _vertexArrayObject.LinkAttribute(vertexBufferObject, 2, 2,
            GL_FLOAT, 11 * sizeof(float), (void*)(sizeof(float) * 6));
        // Link vertex normals as attribute layout 3
        _vertexArrayObject.LinkAttribute(vertexBufferObject, 3, 3,
            GL_FLOAT, 11 * sizeof(float), (void*)(sizeof(float) * 8));

        _vertexArrayObject.Unbind();
        vertexBufferObject.Unbind();
        indexBufferObject.Unbind();
    }

    void Mesh::Draw(BGRCore::Shader& shader, BGRCore::Camera& camera, ProjectionMethod projectionMethod) {
        shader.Activate();

        _vertexArrayObject.Bind();

        _material.Apply(shader);

        if (projectionMethod == ProjectionMethod::Together) {
            camera.CalculateMatrix(shader, "uCameraMatrix");
        }
        else if (projectionMethod == ProjectionMethod::Separate){
            shader.SetMat4("uView", camera.GetView());
            shader.SetMat4("uProjection", camera.GetProjection());
        }

        auto model = glm::mat4(1);
        model = glm::translate(model, Position);
        shader.SetMat4("uModel", model);

        glDrawElements(_drawMode, _indices.size(), GL_UNSIGNED_INT, 0);
    }

    int Mesh::GetNumVerts() const {
        return static_cast<int>(_vertices.size());
    }

    int Mesh::GetNumIndices() const {
        return static_cast<int>(_indices.size());
    }

    void Mesh::SetCustomDrawMode(int drawMode) {
        _drawMode = drawMode;
    }
}
