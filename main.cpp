#include "raylib.h"

int main() {
    //- Window dimensions
    int windowWidth{1280};
    int windowHeight{720};

    //- Circle coordinates
    int circle_x{windowWidth/2};
    int circle_y{windowHeight/2};
    float circle_radius{25.0f};
    //- Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //- Axe coordinates
    int axe_x{640};
    int axe_y{0};
     int axe_length{50};
    //- Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    bool collision_with_axe =   (b_axe_y >= u_circle_y) && 
                                (u_axe_y <= b_circle_y) && 
                                (l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x);

    int direction{10};

    //- Initializing the window
    InitWindow(windowWidth,windowHeight,"Test");    

    SetTargetFPS(60);
    //- keeping window open main loop
    while(!WindowShouldClose()) { 
        BeginDrawing();
        ClearBackground(RED);

        if(collision_with_axe) {
            DrawText("GAME OVER! Und ja das Game ist scheiße!", windowWidth/2,windowHeight/2,28,WHITE);
        } else {
            //- Game Logic begins

            //- Update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //- Update collision with axe
            collision_with_axe =    (b_axe_y >= u_circle_y) && 
                                    (u_axe_y <= b_circle_y) && 
                                    (l_axe_x <= r_circle_x) && 
                                    (r_axe_x >= l_circle_x);

            //- Drawing a Rectangle & Circle
            DrawRectangle(axe_x,axe_y,axe_length,axe_length,GREEN);
            DrawCircle(circle_x,circle_y,circle_radius,BLUE);

            //- Move the axe
            axe_y += direction;
            if(axe_y > windowHeight || axe_y < 0) {
                direction = -direction;
            } 

            if(IsKeyDown(KEY_D) && circle_x < windowWidth) {
                circle_x += 10;
            } 
            if (IsKeyDown(KEY_A) && circle_x > 0) {
                circle_x -= 10;
            } 
            if (IsKeyDown(KEY_S) && circle_y < windowHeight) {
                circle_y += 10;
            }
            if (IsKeyDown(KEY_W) && circle_y > 0) {
                circle_y -= 10;
            }
        }
        
        //-Game Logic ends
        EndDrawing();
    }
}