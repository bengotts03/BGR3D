#pragma once
#include<glad/glad.h>
#include<string>
#include<fstream>
#include <iostream>
#include <glm/glm.hpp>

std::string GetFileContents(const char* filename);

namespace BGRCore {
    class Shader
    {
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();

        void SetFloat(const std::string& name, float val);
        void SetInt(const std::string& name, int val);
        void SetBool(const std::string& name, bool val);

        void SetVec2(const std::string& name, const glm::vec2& val);
        void SetVec2(const std::string& name, float x, float y);

        void SetVec3(const std::string& name, const glm::vec3& val);
        void SetVec3(const std::string& name, float x, float y, float z);

        void SetVec4(const std::string& name, const glm::vec4& val);
        void SetVec4(const std::string& name, float x, float y, float z, float w);

        void SetMat2(const std::string& name, const glm::mat2& mat);
        void SetMat3(const std::string& name, const glm::mat3& mat);
        void SetMat4(const std::string& name, const glm::mat4& mat);
    private:
        void CompileErrors(unsigned int shader, const char* type);
    };
}