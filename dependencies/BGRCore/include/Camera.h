#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Window.h"
#include "Shader.h"

namespace BGRCore {
    class Camera {
    public:
        Camera(BGAppCore::Window* window, int width, int height, glm::vec3 pos);
        virtual ~Camera() = default;

        // Sends matrix data to the vertex shader
        void CalculateMatrix(Shader& shader, const char* uniform);
        // Updates the cameras matrix
        void UpdateMatrix(float FOV, float nearPane, float farPane);
        glm::mat4 GetView();
        glm::mat4 GetProjection();
        void RefreshViewport(int width, int height);

        void HandleInput();
        void HandleMovement(glm::vec3 movementDirection);
        void HandleRotation();

        glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Direction = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::mat4 CameraMatrix = glm::mat4(1);
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

        glm::vec3 Right;
        glm::vec3 Forward;
    private:
        float _width;
        float _height;
        float _speed = 2.0f;
        float _lookSensitivity = 100.0f;

        BGAppCore::Window* _window;
    };
}