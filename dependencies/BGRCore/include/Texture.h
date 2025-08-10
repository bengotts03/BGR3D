#pragma once

#include "glad/glad.h"
#include "stb_image.h"
#include <string>

#include "Shader.h"

namespace BGRCore {
    class Texture {
    public:
        GLuint ID;
        const char* Type;

        Texture(std::string texturePath, const char* type, GLuint slot);
        ~Texture() = default;

        void Bind();
        void Unbind();
        void Delete();
        void TextureUnit(Shader& shader, const char* uniform, GLuint slot);

        int GetWidth() const {
            return _textureWidth;
        }
        int GetHeight() const {
            return _textureHeight;
        }
    private:
        int _textureWidth;
        int _textureHeight;
        int _numberOfColourChannels;
        int _textureSlot;
    };
}