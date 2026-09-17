#pragma once

#include "../datatypes/datatypes.h"

#include <glm/glm.hpp>
#include <string>

namespace NodeTypes {
    struct Object
    {
        std::string name;

        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
    };

    struct StaticObject : Object
    {
        bool visible = true;
    };

    struct MeshObject : StaticObject
    {
        DataTypes::Mesh mesh;
    };
}
