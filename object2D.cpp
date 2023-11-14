#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float size,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(-1.0f, 1.0f, 0.0f) * size, color), // top left
        VertexFormat(glm::vec3(1.0f, 1.0f, 0.0f) * size, color), // top right
        VertexFormat(glm::vec3(1.0f, -1.0f, 0.0f) * size, color), // bottom right
        VertexFormat(glm::vec3(-1.0f, -1.0f, 0.0f) * size, color), // bottom left
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
        0, 1, 2, 3
    };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}


Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float size,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0.0f, 0.0f, 0.0f) * size, color), // bottom left
        VertexFormat(glm::vec3(1.0f, 0.0f, 0.0f) * size, color), // bottom right
        VertexFormat(glm::vec3(1.0f, 6.51f, 0.0f) * size, color), // top right
        VertexFormat(glm::vec3(0.0f, 6.51f, 0.0f) * size, color), // top left
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3,
    };

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreatePistol(
    const std::string& name,
    glm::vec3 center,
    float diamondSize, // size of the diamond
    float rectangleSize, // Height of the rectangle
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        // Rectangle
        VertexFormat(glm::vec3(0.0f, -0.5f, 0.0f) * rectangleSize, color), // bottom left
        VertexFormat(glm::vec3(2.5f, -0.5f, 0.0f) * rectangleSize, color), // bottom right
        VertexFormat(glm::vec3(2.5f, 0.5f, 0.0f) * rectangleSize, color), // top right
        VertexFormat(glm::vec3(0.0f, 0.5f, 0.0f) * rectangleSize, color), // top left

        // Diamond
        VertexFormat(glm::vec3(0.0f, 2.0f, 0.0f) * diamondSize, color), // top
        VertexFormat(glm::vec3(-1.0f, 0.0f, 0.0f) * diamondSize, color), // left
        VertexFormat(glm::vec3(0.0f, -2.0f, 0.0f) * diamondSize, color), // bottom
        VertexFormat(glm::vec3(1.0f, 0.0f, 0.0f) * diamondSize, color), // right

    };

    std::vector<unsigned int> indices = {
        // Rectangle indices
        0, 1, 2,
        0, 2, 3,

        // Diamond indices
        4, 5, 6,
        4, 6, 7,
    };

    Mesh* pistol = new Mesh(name);

    pistol->InitFromData(vertices, indices);
    return pistol;

}


Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 center,
    float size1,
    float size2,
    glm::vec3 color1,
    glm::vec3 color2)
{
    std::vector<VertexFormat> vertices =
    {
        // Small hexagone
        VertexFormat(glm::vec3(0.0f, 0.0f, 0.0f) * size2, color2), // center
        VertexFormat(glm::vec3(-0.5f, sqrt(3 / 2), 0.0f) * size2, color2), // left top
        VertexFormat(glm::vec3(0.5f, sqrt(3 / 2), 0.0f) * size2, color2), // right top
        VertexFormat(glm::vec3(1.0f, 0.0f, 0.0f) * size2, color2), // right
        VertexFormat(glm::vec3(0.5f, -sqrt(3 / 2), 0.0f) * size2, color2), // right bottom
        VertexFormat(glm::vec3(-0.5f, -sqrt(3 / 2), 0.0f) * size2, color2), // left bottom
        VertexFormat(glm::vec3(-1.0f, 0.0f, 0.0f) * size2, color2), // left

        // Big hexagone
        VertexFormat(glm::vec3(0.0f, 0.0f, 0.0f) * size1, color1), // center
        VertexFormat(glm::vec3(-0.5f, sqrt(3 / 2), 0.0f) * size1, color1), // left top
        VertexFormat(glm::vec3(0.5f, sqrt(3 / 2), 0.0f) * size1, color1), // right top
        VertexFormat(glm::vec3(1.0f, 0.0f, 0.0f) * size1, color1), // right
        VertexFormat(glm::vec3(0.5f, -sqrt(3 / 2), 0.0f) * size1, color1), // right bottom
        VertexFormat(glm::vec3(-0.5f, -sqrt(3 / 2), 0.0f) * size1, color1), // left bottom
        VertexFormat(glm::vec3(-1.0f, 0.0f, 0.0f) * size1, color1), // left

    };

    std::vector<unsigned int> indices = {
        // Big hexagone indices
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 1,

        // Small hexagone indices
        7, 8, 9,
        7, 9, 10,
        7, 10, 11,
        7, 11, 12,
        7, 12, 13,
        7, 13, 8,
    };

    Mesh* hexagon = new Mesh(name);

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float size,
    glm::vec3 color)
{
    std::vector<VertexFormat> vertices =
    {
        // Values found on geogebra star search

        VertexFormat(glm::vec3(0.0f, 0.0f, 0.0f), color), // center
        VertexFormat(glm::vec3(-0.08f, 3.36f, 0.0f) * size, color), // A
        VertexFormat(glm::vec3(-2.62f, -3.34f, 0.0f) * size, color), // B
        VertexFormat(glm::vec3(3.56f, 0.88f, 0.0f) * size, color), // C
        VertexFormat(glm::vec3(-3.44f, 0.94f, 0.0f) * size, color), // D
        VertexFormat(glm::vec3(2.28f, -3.38f, 0.0f) * size, color), // E
    };

    // Define the indices for the star
    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 1
    };

    Mesh* star = new Mesh(name);
    star->InitFromData(vertices, indices);

    return star;
}

