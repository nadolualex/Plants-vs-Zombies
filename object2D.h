#pragma once

#include <string>

#include "core/gpu/mesh.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float size, glm::vec3 color, bool fill = false);

    // Create rectangle with given bottom left corner, length and color
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float size, glm::vec3 color, bool fill);

    // Create a pistol
    Mesh* CreatePistol(const std::string& name, glm::vec3 center, float diamondSize, float rectangleSize, glm::vec3 color, bool fill);

    // Create a hexagone
    Mesh* CreateHexagon(const std::string& name, glm::vec3 center, float size1, float size2, glm::vec3 color1, glm::vec3 color2);

    // Create a star
    Mesh* CreateStar(const std::string& name, glm::vec3 center, float size, glm::vec3 color);
}

#pragma once
