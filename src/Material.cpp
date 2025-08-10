#include "Material.h"

namespace BGR3D {
    Material::Material(std::vector<BGRCore::Texture>& textures) {
        _textures = textures;
    }

    void Material::SetColour(BGRCore::Colour& colour) {
        _baseColour = colour;
    }

    BGRCore::Colour Material::GetColour() {
        return _baseColour;
    }

    void Material::Apply(BGRCore::Shader& shader) {
        unsigned int numberOfDiffuse = 0;
        unsigned int numberOfSpecular = 0;

        for (int i = 0; i < _textures.size(); ++i) {
            std::string num;
            std::string type = _textures[i].Type;

            if (type == "diffuse") {
                num = std::to_string(numberOfDiffuse++);
                type = "Diffuse";
            }
            else if (type == "specular") {
                num = std::to_string(numberOfSpecular++);
                type = "Specular";
            }

            _textures[i].TextureUnit(shader, ('u' + type + num).c_str(), i);
            _textures[i].Bind();
        }

        float r, g, b;
        _baseColour.ToFloat(r, g, b);
        shader.SetVec3("Colour", r, g, b);
    }
}
