#pragma once

#include "Colour.h"
#include "Texture.h"

namespace BGR3D {
    class Material {
    public:
        explicit Material(std::vector<BGRCore::Texture>& textures);

        void SetColour(BGRCore::Colour& colour);
        BGRCore::Colour GetColour();

        void Apply(BGRCore::Shader& shader);
    private:
        BGRCore::Colour _baseColour = BGRCore::WHITE;
        std::vector<BGRCore::Texture> _textures;
    };
}
