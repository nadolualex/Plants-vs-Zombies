#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
    protected:
        float cx, cy;
        glm::mat3 modelMatrixSquare;
        glm::mat3 modelMatrixRectangle;
        glm::mat3 modelMatrixPistol[5];
        glm::mat3 modelMatrixHexagon;
        glm::mat3 modelMatrixHexagonNew[100]; // PUT A LOWER NUMBER !!!!!!!
        glm::mat3 modelMatrixStar;
        glm::mat3 modelMatrixRedSquare;
        glm::mat3 modelMatrixPistolSquare;
        glm::mat3 modelMatrixPistolNew[10];
        glm::mat3 modelMatrixPinkStar;
        glm::mat3 modelMatrixProjectile[30];
        glm::mat3 modelMatrixProjectilePurple[30];
        glm::mat3 modelMatrixProjectileBlue[30];
        glm::mat3 modelMatrixProjectileOrange[30];
        glm::mat3 modelMatrixProjectileYellow[30];




        int angularStep = 0;
        // Hexagone translation
        int translateY[6] = { 0 };

        // Which pistol is being pressed
        int pressed = 0;

        // Coordinates of the mouse
        int mouseXglobal;
        int mouseYglobal;

        // For randomizing
        int randomY[3] =  { 40, 115, 190 };
        std::string randomHexagon[4] = { "hexagon_purple", "hexagon_orange", "hexagon_blue", "hexagon_yellow" };

        // Initializations for randomizing hexagones spawning
        bool shouldSpawn = true;
        int random_hexagon = 0;
        float time_passed = 0;
        int hexagones_spawned = 0;

        // Number of lives
        int no_lives = 3;

        struct Square {
            // Edges of the square
            int up;
            int down;
            int left;
            int right;

            // Coordinates of the pistol in the square
            int translateX; 
            int translateY;

            int waiting = 0; // Waiting for a pistol to be drawn
            int occupied = 0; // Marking if a square is occupied
            int destroy = 0; // For the scale animation

            float scaleX = 1;
            float scaleY = 1;

            int sign2 = 1;

            std::string aux[10] = {"nothing", "projectilepurple", "projectileorange", "projectileblue", "projectileyellow"};
            std::string color;

            int colorIndex = 0;

            int RIGHT_PRESSED = 0; // Checking if I need to get rid of a pistol
        };

        float spawnTimer = 0.0f;  // Initialize a timer for projectile spawning
        float spawnInterval = 3.0f;  // Set the interval for spawning projectiles

        // Edges of the pistol square (top)
        struct SquarePistol {
            int up;
            int down;
            int left;
            int right;
        };

        // Enemies
        struct Hexagon {
            float time_elapsed = 0;
            float time_until_spawn = 0;
            bool spawned = false;
            int random_translateY = 0;
            int translateX = 0;
            std::string random_color;

            int shouldDie = 0;

            float scaleX = 1;
            float scaleY = 1;

            int sign2 = 1;

            int lives = 3;

            int row = 0;

            int colorIndex = 0;

        };

        struct PinkStar {
            int up;
            int down;
            int left;
            int right;
            int randomX = -1;
            int randomY = -1;
            int live = 0;
            int rendered = 0;
        };

        struct StarPoints {
            int starsCollected = 5;
            int actualLength = 850;
            int pistol1 = 1;
            int pistol2 = 2;
            int pistol3 = 2;
            int pistol4 = 3;
        };

        
        int projectiles_spawned = 0;
        float projectile_spawn_time[20] = { 3.0f };



        struct Projectile {
            int translateX = 0;
            int translateY = 0;
            int spawn = 0;
            int colour;

            int collision = 0;

            int hexagonCollisionIndex = 0;

            int row = 0;
        };

       Projectile projectile[30][30];

       StarPoints starPoints;

       float pinkStarSpawnTime = 1.5f;

       Hexagon hexagon[10];

       SquarePistol square_pistol[5];

       Square square[10];

       PinkStar pinkstar;

        
    };
}   // namespace m1
