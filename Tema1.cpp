#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"
#include "components/simple_scene.h"

#include <cstdlib> // for rand()

using namespace std;
using namespace m1;


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
   


    // Some initializations
    for (int i = 1; i <= 5; i++) {
        hexagon[i].time_until_spawn = (i * 2) + rand() % (i * 2); // Adjust the range as needed

        int randomcolor = rand() % 4;
        hexagon[i].random_color = randomHexagon[randomcolor];
        hexagon[i].colorIndex = randomcolor + 1;
        hexagon[i].random_translateY = randomY[rand() % 3];

       // cout << "hexagon " << i << " se spawneaza la " << hexagon[i].time_until_spawn << " seconds" << endl;
       // cout << "hexagon " << i << " are culoarea " << hexagon[i].random_color << endl;
       // cout << "hexagon " << i << " are Y " << hexagon[i].random_translateY << endl;
    }

    // Star appearance random
    pinkstar.randomY = rand() % 720;
    pinkstar.randomX = rand() % 1280;
    pinkStarSpawnTime = 1.5f;




    glm::vec3 corner = glm::vec3(0, 0, 0);

    cx = corner.x + 10;
    cy = corner.y + 10;
    float squareSide = 55;
    
    // Creating the green squares
    for (int i = 1; i <= 9; i++) {
        std::string squareName = "square" + std::to_string(i);
        Mesh* square = object2D::CreateSquare(squareName, corner, squareSide, glm::vec3(0, 1, 0), true);
        AddMeshToList(square);
    }

    // Setting the edges of the green squares
    square[1].up = 380 + squareSide;
    square[1].down = 380 - squareSide;
    square[1].right = 150 + squareSide;
    square[1].left = 150 - squareSide;
    square[1].translateX = 140;
    square[1].translateY = 380;


    square[2].up = 380 + squareSide;
    square[2].down = 380 - squareSide;
    square[2].right = 300 + squareSide;
    square[2].left = 300 - squareSide;
    square[2].translateX = 290;
    square[2].translateY = 380;

    square[3].up = 380 + squareSide;
    square[3].down = 380 - squareSide;
    square[3].right = 450 + squareSide;
    square[3].left = 450 - squareSide;
    square[3].translateX = 440;
    square[3].translateY = 380;

    square[4].up = 230 + squareSide;
    square[4].down = 230 - squareSide;
    square[4].right = 150 + squareSide;
    square[4].left = 150 - squareSide;
    square[4].translateX = 140;
    square[4].translateY = 230;

    square[5].up = 230 + squareSide;
    square[5].down = 230 - squareSide;
    square[5].right = 300 + squareSide;
    square[5].left = 300 - squareSide;
    square[5].translateX = 290;
    square[5].translateY = 230;

    square[6].up = 230 + squareSide;
    square[6].down = 230 - squareSide;
    square[6].right = 450 + squareSide;
    square[6].left = 450 - squareSide;
    square[6].translateX = 440;
    square[6].translateY = 230;

    square[7].up = 80 + squareSide;
    square[7].down = 80 - squareSide;
    square[7].right = 150 + squareSide;
    square[7].left = 150 - squareSide;
    square[7].translateX = 140;
    square[7].translateY = 80;

    square[8].up = 80 + squareSide;
    square[8].down = 80 - squareSide;
    square[8].right = 300 + squareSide;
    square[8].left = 300 - squareSide;
    square[8].translateX = 290;
    square[8].translateY = 80;

    square[9].up = 80 + squareSide;
    square[9].down = 80 - squareSide;
    square[9].right = 450 + squareSide;
    square[9].left = 450 - squareSide;
    square[9].translateX = 440;
    square[9].translateY = 80;

    // Creating the three lives
    for (int i = 1; i <= 3; i++) {
        std::string squareName = "red_square" + std::to_string(i);
        Mesh* red_square = object2D::CreateSquare(squareName, corner, 40, glm::vec3(1, 0, 0), true);
        AddMeshToList(red_square);
    }

    // Creating the empty pistol squares
    for (int i = 1; i <= 4; i++) {
        std::string squareName = "pistol_square" + std::to_string(i);
        Mesh* pistol_square = object2D::CreateSquare(squareName, corner, squareSide, glm::vec3(0, 0, 0), false);
        AddMeshToList(pistol_square);
    }

    // Setting the edges of the pistol squares
    square_pistol[1].up = 650 + squareSide;
    square_pistol[1].down = 650 - squareSide;
    square_pistol[1].left = 110 - squareSide;
    square_pistol[1].right = 110 + squareSide;

    square_pistol[2].up = 650 + squareSide;
    square_pistol[2].down = 650 - squareSide;
    square_pistol[2].left = 310 - squareSide;
    square_pistol[2].right = 310 + squareSide;

    square_pistol[3].up = 650 + squareSide;
    square_pistol[3].down = 650 - squareSide;
    square_pistol[3].left = 510 - squareSide;
    square_pistol[3].right = 510 + squareSide;

    square_pistol[4].up = 650 + squareSide;
    square_pistol[4].down = 650 - squareSide;
    square_pistol[4].left = 710 - squareSide;
    square_pistol[4].right = 710 + squareSide;

    // Creating the rectangle
    Mesh* rectangle = object2D::CreateRectangle("rectangle", corner, 63 , glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle);

    // Creating the pistols
    Mesh* pistol1 = object2D::CreatePistol("pistol1", corner, 20, 20, glm::vec3(0.6f, 0, 0.6f), true);
    AddMeshToList(pistol1);

    Mesh* pistol2 = object2D::CreatePistol("pistol2", corner, 20, 20, glm::vec3(1, 0.5f, 0), true);
    AddMeshToList(pistol2);

    Mesh* pistol3 = object2D::CreatePistol("pistol3", corner, 20, 20, glm::vec3(0, 0, 1), true);
    AddMeshToList(pistol3);

    Mesh* pistol4 = object2D::CreatePistol("pistol4", corner, 20, 20, glm::vec3(1, 1, 0), true);
    AddMeshToList(pistol4);


    // Optional pistols to avoid flickering
    Mesh* pistol11 = object2D::CreatePistol("pistol11", corner, 20, 20, glm::vec3(0.6f, 0, 0.6f), true);
    AddMeshToList(pistol11);

    Mesh* pistol22 = object2D::CreatePistol("pistol22", corner, 20, 20, glm::vec3(1, 0.5f, 0), true);
    AddMeshToList(pistol22);

    Mesh* pistol33 = object2D::CreatePistol("pistol33", corner, 20, 20, glm::vec3(0, 0, 1), true);
    AddMeshToList(pistol33);

    Mesh* pistol44 = object2D::CreatePistol("pistol44", corner, 20, 20, glm::vec3(1, 1, 0), true);
    AddMeshToList(pistol44);
    
    Mesh* hexagon_blue = object2D::CreateHexagon("hexagon_blue", corner, 35, 22, glm::vec3(0, 0, 1), glm::vec3(0, 1, 0.5f));
    AddMeshToList(hexagon_blue);

    Mesh* hexagon_purple = object2D::CreateHexagon("hexagon_purple", corner, 35, 22, glm::vec3(0.6f, 0, 0.6f), glm::vec3(0, 1, 0.5f));
    AddMeshToList(hexagon_purple);

    Mesh* hexagon_yellow= object2D::CreateHexagon("hexagon_yellow", corner, 35, 22, glm::vec3(1, 1, 0), glm::vec3(0, 1, 0.5f));
    AddMeshToList(hexagon_yellow);

    Mesh* hexagon_orange = object2D::CreateHexagon("hexagon_orange", corner, 35, 22, glm::vec3(1, 0.5f, 0), glm::vec3(0, 1, 0.5f));
    AddMeshToList(hexagon_orange);
    
    for (int i = 1; i <= 8; i++) {
        std::string starName = "star" + std::to_string(i);
        Mesh* star = object2D::CreateStar(starName, corner, 5, glm::vec3(0.5f, 0.5f, 0.5f));
        AddMeshToList(star);
    }

    for (int i = 1; i <= 15; i++) {
        std::string starName = "starPoints" + std::to_string(i);
        Mesh* starPoints = object2D::CreateStar(starName, corner, 5, glm::vec3(0.5f, 0.5f, 0.5f));
        AddMeshToList(starPoints);
    }


    Mesh* pink_star = object2D::CreateStar("pink_star", corner, 10, glm::vec3(1, 0, 1));
    AddMeshToList(pink_star);

    for (int i = 0; i <= 30; i++) {


        Mesh* projectilepurple = object2D::CreateStar("projectilepurple" + std::to_string(i), corner, 10, glm::vec3(0.6f, 0, 0.6f));
        AddMeshToList(projectilepurple);

        Mesh* projectileorange = object2D::CreateStar("projectileorange" + std::to_string(i), corner, 10, glm::vec3(1, 0.5f, 0));
        AddMeshToList(projectileorange);

        Mesh* projectileblue = object2D::CreateStar("projectileblue" + std::to_string(i), corner, 10, glm::vec3(0, 0, 1));
        AddMeshToList(projectileblue);

        Mesh* projectileyellow = object2D::CreateStar("projectileyellow" + std::to_string(i), corner, 10, glm::vec3(1, 1, 0));
        AddMeshToList(projectileyellow);
    }

}   


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

}


void Tema1::Update(float deltaTimeSeconds)
{


    // Random star
    if (pinkstar.live == 1) {
        RenderMesh2D(meshes["pink_star"], shaders["VertexColor"], modelMatrixPinkStar);
        modelMatrixPinkStar = glm::mat3(1);
        modelMatrixPinkStar *= transform2D::Translate(pinkstar.randomX, pinkstar.randomY);

        pinkstar.up = pinkstar.randomY + 35;
        pinkstar.down = pinkstar.randomY - 35;
        pinkstar.left = pinkstar.randomX - 35;
        pinkstar.right = pinkstar.randomX + 35;
    }

    if (pinkStarSpawnTime <= 0)
        pinkstar.live = 1;

    if (pinkStarSpawnTime > 0) {
        pinkStarSpawnTime -= deltaTimeSeconds;
        pinkstar.live = 0;
    }

    for (int i = 1; i <= starPoints.starsCollected; i++) {
        std::string starName = "starPoints" + std::to_string(i);
        RenderMesh2D(meshes[starName], shaders["VertexColor"], modelMatrixStar);
        modelMatrixStar = glm::mat3(1);
        modelMatrixStar *= transform2D::Translate(starPoints.actualLength + 40 * i, 580);
    }

    // Hexagon with turret collision and dissappearance
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 5; j++) {
            if (square[i].occupied != 0) {
                if (hexagon[j].translateX <= -650 && hexagon[j].translateX >= -700) {

                    if (hexagon[j].random_translateY == 190) {
                        //square[3].occupied = 0;
                        //square[3].waiting = 0;
                        square[3].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 115) {
                        //square[6].occupied = 0;
                        //square[6].waiting = 0;
                        square[6].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 40) {
                        //square[9].occupied = 0;
                        //square[9].waiting = 0;
                        square[9].destroy = 1;
                    }
                }

                if (hexagon[j].translateX <= -805 && hexagon[j].translateX >= -905) {
                    if (hexagon[j].random_translateY == 190) {
                        //square[2].occupied = 0;
                        //square[2].waiting = 0;
                        square[2].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 115) {
                        //square[5].occupied = 0;
                        //square[5].waiting = 0;
                        square[5].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 40) {
                        //square[8].occupied = 0;
                        //square[8].waiting = 0;
                        square[8].destroy = 1;
                    }
                }

                if (hexagon[j].translateX <= -960 && hexagon[j].translateX >= -1010) {
                    if (hexagon[j].random_translateY == 190) {
                        //square[1].occupied = 0;
                        //square[1].waiting = 0;
                        square[1].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 115) {
                        //square[4].occupied = 0;
                        //square[4].waiting = 0;
                        square[4].destroy = 1;
                    }

                    if (hexagon[j].random_translateY == 40) {
                        //square[7].occupied = 0;
                        //square[7].waiting = 0;
                        square[7].destroy = 1;
                    }
                }
            }
        }
    }



    // Up to 5 hexagons
    for (int i = 1; i <= 5; i++) {
        
        // Rendering the translation animation
        if (hexagon[i].spawned == false && hexagon[i].time_until_spawn <= 0.1f) {
            if (hexagon[i].shouldDie == 0) {
                hexagon[i].time_elapsed += deltaTimeSeconds;
                modelMatrixHexagonNew[i] = glm::mat3(1);
                modelMatrixHexagonNew[i] *= transform2D::Translate(1180, hexagon[i].random_translateY);
                hexagon[i].translateX += deltaTimeSeconds * -164.5;
                modelMatrixHexagonNew[i] *= transform2D::Translate(hexagon[i].translateX, hexagon[i].random_translateY);
            }

            RenderMesh2D(meshes[hexagon[i].random_color], shaders["VertexColor"], modelMatrixHexagonNew[i]);

            if (hexagon[i].shouldDie == 1) {

                modelMatrixHexagonNew[i] *= transform2D::Translate(cx, cy);

                modelMatrixHexagonNew[i] *= transform2D::Scale(hexagon[i].scaleX, hexagon[i].scaleY);

                modelMatrixHexagonNew[i] *= transform2D::Translate(-cx, -cy);


                // Update scaling factors before applying scale transformation
                if (hexagon[i].scaleX >= 1.0 && hexagon[i].scaleY >= 1.0) {
                    hexagon[i].sign2 = -1;
                }
                //cout << hexagon[i].scaleX << " " << hexagon[i].scaleY << endl;

                hexagon[i].scaleX +=  0.2 * (deltaTimeSeconds * hexagon[i].sign2);
                hexagon[i].scaleY +=  0.2 * (deltaTimeSeconds * hexagon[i].sign2);

                if (hexagon[i].scaleX <= 0.8 && hexagon[i].scaleY <= 0.8) {
                    hexagon[i].spawned = true;
                    hexagon[i].translateX = 0;
                    hexagon[i].time_elapsed = 0;
                    hexagon[i].time_until_spawn = (i * 2) + rand() % (i * 2); // Random range
                    int randomcolor = rand() % 4;
                    hexagon[i].random_color = randomHexagon[randomcolor];
                    hexagon[i].random_translateY = randomY[rand() % 3];

                    hexagon[i].colorIndex = randomcolor + 1;

                    hexagones_spawned--;

                    hexagon[i].shouldDie = 0;

                    hexagon[i].scaleY = 1;
                    hexagon[i].scaleX = 1;
                }
            }
        }
        

        // One enemy either dies or (enters in collision with a star)
        if (hexagon[i].translateX <= -1280) {
            hexagon[i].spawned = true;
            hexagon[i].translateX = 0;
            hexagon[i].time_elapsed = 0;
            hexagon[i].time_until_spawn = (i * 2) + rand() % (i * 2); // Random range
            int randomcolor = rand() % 4;
            //cout << "inainte " << randomcolor << endl;
            hexagon[i].random_color = randomHexagon[randomcolor];
            hexagon[i].random_translateY = randomY[rand() % 3];

            hexagon[i].colorIndex = randomcolor + 1;

            hexagones_spawned--;
        }

        // Calculating the time until the next spawn
        else {
            hexagon[i].spawned = false;
            if (hexagon[i].time_until_spawn > 0) {
                hexagon[i].time_until_spawn -= deltaTimeSeconds;
            }
        }
        if (hexagon[i].translateX == -1) {
            hexagones_spawned++;
            hexagon[i].lives = 3;
        }
        
    }


    // Rendering the pistols
    RenderMesh2D(meshes["pistol1"], shaders["VertexColor"], modelMatrixPistol[1]);
    modelMatrixPistol[1] = glm::mat3(1);
    modelMatrixPistol[1] *= transform2D::Translate(100, 650);

    RenderMesh2D(meshes["pistol2"], shaders["VertexColor"], modelMatrixPistol[2]);
    modelMatrixPistol[2] = glm::mat3(1);
    modelMatrixPistol[2] *= transform2D::Translate(300, 650);

    RenderMesh2D(meshes["pistol3"], shaders["VertexColor"], modelMatrixPistol[3]);
    modelMatrixPistol[3] = glm::mat3(1);
    modelMatrixPistol[3] *= transform2D::Translate(500, 650);

    RenderMesh2D(meshes["pistol4"], shaders["VertexColor"], modelMatrixPistol[4]);
    modelMatrixPistol[4] = glm::mat3(1);
    modelMatrixPistol[4] *= transform2D::Translate(700, 650);

    

    // Created these additional pistols to avoid the flickering of the pistol when it is dragged
    RenderMesh2D(meshes["pistol11"], shaders["VertexColor"], modelMatrixPistol[1]);
    modelMatrixPistol[1] = glm::mat3(1);
    modelMatrixPistol[1] *= transform2D::Translate(100, 650);

    RenderMesh2D(meshes["pistol22"], shaders["VertexColor"], modelMatrixPistol[2]);
    modelMatrixPistol[2] = glm::mat3(1);
    modelMatrixPistol[2] *= transform2D::Translate(300, 650);

    RenderMesh2D(meshes["pistol33"], shaders["VertexColor"], modelMatrixPistol[3]);
    modelMatrixPistol[3] = glm::mat3(1);
    modelMatrixPistol[3] *= transform2D::Translate(500, 650);

    RenderMesh2D(meshes["pistol44"], shaders["VertexColor"], modelMatrixPistol[4]);
    modelMatrixPistol[4] = glm::mat3(1);
    modelMatrixPistol[4] *= transform2D::Translate(700, 650);


    // Choosing which pistol is following the mouse
    switch (pressed) {
        case 1:
            RenderMesh2D(meshes["pistol1"], shaders["VertexColor"], modelMatrixPistol[1]);
            modelMatrixPistol[1] = glm::mat3(1);
            modelMatrixPistol[1] *= transform2D::Translate(mouseXglobal, mouseYglobal);
            break;
        case 2:
            RenderMesh2D(meshes["pistol2"], shaders["VertexColor"], modelMatrixPistol[2]);
            modelMatrixPistol[2] = glm::mat3(1);
            modelMatrixPistol[2] *= transform2D::Translate(mouseXglobal, mouseYglobal);
            break;
        case 3:
            RenderMesh2D(meshes["pistol3"], shaders["VertexColor"], modelMatrixPistol[3]);
            modelMatrixPistol[3] = glm::mat3(1);
            modelMatrixPistol[3] *= transform2D::Translate(mouseXglobal, mouseYglobal);
            break;
        case 4:
            RenderMesh2D(meshes["pistol4"], shaders["VertexColor"], modelMatrixPistol[4]);
            modelMatrixPistol[4] = glm::mat3(1);
            modelMatrixPistol[4] *= transform2D::Translate(mouseXglobal, mouseYglobal);
            break;
        default:
            break;
    }


    // Drawing the pistol in the desired square
    for (int i = 1; i <= 9; i++) {
        if (square[i].waiting != 0) {
            std::string pistol_prevName = "pistol" + std::to_string(square[i].waiting);
            RenderMesh2D(meshes[pistol_prevName], shaders["VertexColor"], modelMatrixPistolNew[i]);

            modelMatrixPistolNew[i] = glm::mat3(1);
            modelMatrixPistolNew[i] *= transform2D::Translate(square[i].translateX, square[i].translateY);

            if (square[i].destroy == 1) {
                modelMatrixPistolNew[i] *= transform2D::Translate(cx, cy);

                modelMatrixPistolNew[i] *= transform2D::Scale(square[i].scaleX, square[i].scaleY);

                modelMatrixPistolNew[i] *= transform2D::Translate(-cx, -cy);


                // Update scaling factors before applying scale transformation
                if (square[i].scaleX >= 1.0 && square[i].scaleY >= 1.0) {
                    square[i].sign2 = -1;
                }
               
                square[i].scaleX += (deltaTimeSeconds * square[i].sign2);
                square[i].scaleY += (deltaTimeSeconds * square[i].sign2);

                if (square[i].scaleX <= 0.0 && square[i].scaleY <= 0.0) {
                    square[i].destroy = 0;
                    square[i].occupied = 0;
                    square[i].waiting = 0;
                    square[i].scaleY = 1;
                    square[i].scaleX = 1;
                }
            }

        }

    }


    
    // Collision between the hexagons and the projectiles
    for (int j = 0; j <= 9; j++) {
        for (int i = 1; i <= 5; i++) {
            if (projectile[j][1].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(glm::vec2(projectile[j][1].translateX + 181, square[1].translateY))) <= 2 && (hexagon[i].colorIndex == square[1].colorIndex)) { //SQUARE 1
               // cout << "collision " << j << " 1 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][1].spawn = 0;
                    projectile[j][1].hexagonCollisionIndex = i;
                    //cout << hexagon[i].lives << endl;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][1].collision = 1;
            }

            if (projectile[j][4].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(glm::vec2(projectile[j][4].translateX + 181, square[4].translateY))) <= 2 && (hexagon[i].colorIndex == square[4].colorIndex)) {  //SQUARE 4
                //cout << "collision " << j << " 4 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][4].spawn = 0;
                    projectile[j][4].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][4].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(glm::vec2(projectile[0][4].translateX + 181, square[4].translateY))) << endl; 


            if (projectile[j][7].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(glm::vec2(projectile[j][7].translateX + 181, square[7].translateY))) <= 2 && (hexagon[i].colorIndex == square[7].colorIndex)) {//SQUARE 7
                //cout << "collision " << j << " 7 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][7].spawn = 0;
                    projectile[j][7].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][7].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(glm::vec2(projectile[0][7].translateX + 181, square[7].translateY))) << endl; 


            if (projectile[j][2].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][2].translateX + 331, square[2].translateY)) <= 2 && (hexagon[i].colorIndex == square[2].colorIndex)) { // SQUARE 2
                //cout << "collision " << j << " 2 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][2].spawn = 0;
                    projectile[j][2].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][2].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][2].translateX + 331, square[2].translateY)) << endl;



            if (projectile[j][5].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][5].translateX + 331, square[5].translateY)) <= 2 && (hexagon[i].colorIndex == square[5].colorIndex)) { //SQUARE 5
                //cout << "collision " << j << " 5 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][5].spawn = 0;
                    projectile[j][5].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][5].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][5].translateX + 331, square[5].translateY)) << endl; 


            if (projectile[j][8].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][8].translateX + 331, square[8].translateY)) <= 2 && (hexagon[i].colorIndex == square[8].colorIndex)) { // SQUARE 8
                //cout << "collision " << j << " 8 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][8].spawn = 0;
                    projectile[j][8].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][8].collision = 1;
            }
            // cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][8].translateX + 331, square[8].translateY)) << endl;  


            if (projectile[j][3].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][3].translateX + 481, square[3].translateY)) <= 2 && (hexagon[i].colorIndex == square[3].colorIndex)) { // SQUARE 3
                //cout << "collision " << j << " 3 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][3].spawn = 0;
                    projectile[j][3].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][3].collision = 1;
            }
            // cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][3].translateX + 481, square[3].translateY)) << endl;


            if (projectile[j][6].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][6].translateX + 481, square[6].translateY)) <= 2 && (hexagon[i].colorIndex == square[6].colorIndex)) { // SQUARE 6
                //cout << "collision " << j << " 6 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][6].spawn = 0;
                    projectile[j][6].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][6].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][6].translateX + 481, square[6].translateY)) << endl;


            if (projectile[j][9].spawn && glm::distance(glm::vec2(1280 + hexagon[i].translateX - 85, hexagon[i].random_translateY * 2), glm::vec2(projectile[j][9].translateX + 481, square[9].translateY)) <= 2 && (hexagon[i].colorIndex == square[9].colorIndex)) { // SQUARE 9
                //cout << "collision " << j << " 9 " << endl;
                if (hexagon[i].lives > 1) {
                    //projectile[j][9].spawn = 0;
                    projectile[j][9].hexagonCollisionIndex = i;
                }
                else
                    hexagon[i].shouldDie = 1;
                projectile[j][9].collision = 1;
            }
            //cout << glm::distance(glm::vec2(1280 + hexagon[1].translateX - 85, hexagon[1].random_translateY * 2), glm::vec2(projectile[0][9].translateX + 481, square[9].translateY)) << endl;
        }
    }




    // Rendering the projectiles
    for (int i = 0; i <= 9; i++) {
        if (projectile_spawn_time[i] >= 0)
            projectile_spawn_time[i] -= deltaTimeSeconds;
        if (!square[i].occupied)
            projectile_spawn_time[i] = 3.0f;
    }

    for (int j = 0; j <= 9; j++) {
        for (int i = 1; i <= 5; i++) {

            if (square[j].occupied || projectile[i][j].spawn == 1) {


                if (projectile_spawn_time[j] < 0 && square[j].occupied && projectile[i][j].spawn == 0 && (hexagon[i].colorIndex == square[j].colorIndex)) {
                    projectiles_spawned++;
                    //cout << hexagon[i].colorIndex << endl;
                    //cout << square[j].colorIndex << endl;
                    if (hexagon[i].translateX <= -1 && (projectile[i][j].translateY + square[j].translateY == hexagon[i].random_translateY * 2)) {
                        projectile[i][j].spawn = 1;
                        
                        projectile_spawn_time[j] = 1.5f;
                        //cout << i << endl;
                    }

                }


                if (projectile[i][j].spawn == 1) {
                   
                    modelMatrixProjectile[i] = glm::mat3(1);
                    modelMatrixProjectile[i] *= transform2D::Translate(projectile[i][j].translateX + 40 + square[j].translateX, projectile[i][j].translateY + square[j].translateY);
                    projectile[i][j].translateX += deltaTimeSeconds * 547.5;

                    modelMatrixProjectile[i] *= transform2D::Rotate(angularStep + 10);
                    angularStep += deltaTimeSeconds + 5;

                    RenderMesh2D(meshes[square[j].color + std::to_string(i)], shaders["VertexColor"], modelMatrixProjectile[i]);


                    if ((projectile[i][j].translateX + 40 + square[j].translateX) >= 1280 || projectile[i][j].collision) {
                        projectile[i][j].spawn = 0;
                        projectile[i][j].translateX = 0;
                        projectiles_spawned--;
                        cout << projectile[i][j].collision << endl;
                        modelMatrixProjectile[i] = glm::mat3(1);
                        if (projectile[i][j].collision) {
                            hexagon[projectile[i][j].hexagonCollisionIndex].lives--;
                            projectile[i][j].collision = 0;
                        }
                    }
                }
            }
        }
    }


    // Rendering the bottom squares
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(150, 380);
    
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(300, 380);

    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(450, 380);

    RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(150, 230);

    RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(300, 230);

    RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(450, 230);

    RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(150, 80);

    RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(300, 80);

    RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrixSquare);
    modelMatrixSquare = glm::mat3(1);
    modelMatrixSquare *= transform2D::Translate(450, 80);


    // Rendering the left rectangle
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrixRectangle);
    modelMatrixRectangle = glm::mat3(1);
    modelMatrixRectangle *= transform2D::Translate(10, 25);

   
    // Rendering the top pistol squares
    RenderMesh2D(meshes["pistol_square1"], shaders["VertexColor"], modelMatrixPistolSquare);
    modelMatrixPistolSquare = glm::mat3(1);
    modelMatrixPistolSquare *= transform2D::Translate(110, 650);

    RenderMesh2D(meshes["pistol_square2"], shaders["VertexColor"], modelMatrixPistolSquare);
    modelMatrixPistolSquare = glm::mat3(1);
    modelMatrixPistolSquare *= transform2D::Translate(310, 650);

    RenderMesh2D(meshes["pistol_square3"], shaders["VertexColor"], modelMatrixPistolSquare);
    modelMatrixPistolSquare = glm::mat3(1);
    modelMatrixPistolSquare *= transform2D::Translate(510, 650);

    RenderMesh2D(meshes["pistol_square4"], shaders["VertexColor"], modelMatrixPistolSquare);
    modelMatrixPistolSquare = glm::mat3(1);
    modelMatrixPistolSquare *= transform2D::Translate(710, 650);


    // Rendering the lives
    if (no_lives == 3) {
        RenderMesh2D(meshes["red_square1"], shaders["VertexColor"], modelMatrixRedSquare);
        modelMatrixRedSquare = glm::mat3(1);
        modelMatrixRedSquare *= transform2D::Translate(920, 650);

        RenderMesh2D(meshes["red_square2"], shaders["VertexColor"], modelMatrixRedSquare);
        modelMatrixRedSquare = glm::mat3(1);
        modelMatrixRedSquare *= transform2D::Translate(1050, 650);

        RenderMesh2D(meshes["red_square3"], shaders["VertexColor"], modelMatrixRedSquare);
        modelMatrixRedSquare = glm::mat3(1);
        modelMatrixRedSquare *= transform2D::Translate(1180, 650);
    }
    else if (no_lives == 2) {
		RenderMesh2D(meshes["red_square1"], shaders["VertexColor"], modelMatrixRedSquare);
		modelMatrixRedSquare = glm::mat3(1);
		modelMatrixRedSquare *= transform2D::Translate(920, 650);

		RenderMesh2D(meshes["red_square2"], shaders["VertexColor"], modelMatrixRedSquare);
		modelMatrixRedSquare = glm::mat3(1);
		modelMatrixRedSquare *= transform2D::Translate(1050, 650);
	}
    else if (no_lives == 1) {
		RenderMesh2D(meshes["red_square1"], shaders["VertexColor"], modelMatrixRedSquare);
		modelMatrixRedSquare = glm::mat3(1);
		modelMatrixRedSquare *= transform2D::Translate(920, 650);
	}
    else if (no_lives == 0) {
		cout << "GAME OVER" << endl;
		exit(0);
	}

    //Rendering the stars
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(60, 570);

    RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(260, 570);

    RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(300, 570);

    RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(460, 570);

    RenderMesh2D(meshes["star5"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(500, 570);

    RenderMesh2D(meshes["star6"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(660, 570);

    RenderMesh2D(meshes["star7"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(700, 570);

    RenderMesh2D(meshes["star8"], shaders["VertexColor"], modelMatrixStar);
    modelMatrixStar = glm::mat3(1);
    modelMatrixStar *= transform2D::Translate(740, 570);

}


void Tema1::FrameEnd()
{
}


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
    // TODO(student): Move the logic window with W, A, S, D (up, left, down, right)

}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int cmouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    int mouseY = 720 - cmouseY;

    mouseXglobal = mouseX;
    mouseYglobal = mouseY;

    //cout << mouseX << " " << mouseY << endl;

}


void Tema1::OnMouseBtnPress(int mouseX, int cmouseY, int button, int mods)
{
    // Fixing Y coordinates
    int mouseY = 720 - cmouseY;

    //cout << hexagon[1].translateX << endl;
    //cout << projectile[0][1].translateX + 40 + square[1].translateX << endl;

    // If a pistol is pressed, then pressed takes the number of the pistol
    if (button == 1) {
        for (int i = 1; i <= 4; i++) {
            if (mouseY <= square_pistol[i].up && mouseY >= square_pistol[i].down && mouseX >= square_pistol[i].left && mouseX <= square_pistol[i].right) {
                //std::cout << "Chenar " << i << std::endl;
                pressed = i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= 9; i++) {
            if (mouseYglobal <= square[i].up && mouseYglobal >= square[i].down && mouseXglobal >= square[i].left && mouseXglobal <= square[i].right && square[i].occupied != 0) {
                square[i].RIGHT_PRESSED = 1;
                square[i].destroy = 1;
            }
        }
    }

    // Resetting randoms and despawning the star
    if (button == 1) {
        if (mouseXglobal <= pinkstar.right && mouseXglobal >= pinkstar.left && mouseYglobal >= pinkstar.down && mouseYglobal <= pinkstar.up) {
            pinkstar.live = 0;
            pinkstar.randomY = rand() % 720;
            pinkstar.randomX = rand() % 1280;
            pinkStarSpawnTime = rand() % 2 + 2;
            starPoints.starsCollected++;
            modelMatrixPinkStar = glm::mat3(0);
        }
    }


}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{

    // If a pistol is released on a square, then square[i].waiting value takes the number of
    // the pistol I want to draw inside the square and square[i].occupied takes
    // the number of the pistol that is inside the square    
    if (pressed != 0) {
        for (int i = 1; i <= 9; i++) {
            if (mouseYglobal <= square[i].up && mouseYglobal >= square[i].down && mouseXglobal >= square[i].left && mouseXglobal <= square[i].right && square[i].occupied == 0)
            {
                // Deleting resources when dragging a pistol
                if (pressed == 1 && starPoints.starsCollected >= starPoints.pistol1)
                    starPoints.starsCollected -= starPoints.pistol1;
                else
                    if (pressed == 2 && starPoints.starsCollected >= starPoints.pistol2)
                        starPoints.starsCollected -= starPoints.pistol2;
                    else
                        if (pressed == 3 && starPoints.starsCollected >= starPoints.pistol3)
                            starPoints.starsCollected -= starPoints.pistol3;
                        else
                            if (pressed == 4 && starPoints.starsCollected >= starPoints.pistol4)
                                starPoints.starsCollected -= starPoints.pistol4;
                            else pressed = 0;

                
                square[i].waiting = pressed;
                square[i].occupied = pressed;
                square[i].color = square[i].aux[pressed];
                square[i].colorIndex = pressed;
                
            }
        }
        pressed = 0;
    }

    for (int i = 1; i <= 9; i++) {
        if (square[i].RIGHT_PRESSED == 1) {
            square[i].RIGHT_PRESSED = 0;
        }
    }

    
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
