#pragma once

#include <glm/glm.hpp>

namespace Renderer {
    class Mesh {
        public:
            glm::vec3* getData();
            void setData(glm::vec3 *data_new);
        private:
            glm::vec3 data[];
    };
}