#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace DataTypes {

    struct Vertex
    {
        glm::vec3 position;
        //More later
    };

    struct Mesh
    {
        std::vector<Vertex> verticies;
    };
}