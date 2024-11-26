#include <raylib.h>
#include "grid.h"
#include "Controler.h"
#include <bits/stdc++.h>
using namespace std;


// Button properties
typedef struct {
    int x, y, width, height;
} Button;

// Global button object
Button okButton;
// Fixed Size Of Window
int WIDTH = 750;
int HEIGHT = 500;
// Cell Size
int CELL_SIZE = 12;
// Speed Game
int FPS = 10;
// Function to draw instructions overlay
void DrawInstructions() {
    // Semi-transparent background
    DrawRectangle(0, 0, WIDTH, HEIGHT, Fade(BLACK, 0.7f));

    // Instruction box
    int boxWidth = 450;
    int boxHeight = 450;
    int boxX = (WIDTH - boxWidth) / 2;
    int boxY = (HEIGHT - boxHeight) / 2;

    // Box background
    DrawRectangle(boxX, boxY, boxWidth, boxHeight, RAYWHITE);
    DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, BLACK);

    // Title
    DrawText("Game of Life Rules", boxX + 130, boxY + 20, 20, BLACK);

    // Game Controls
    int textY = boxY + 60;
    DrawText("Game Controls:", boxX + 20, textY, 17, DARKBLUE);
    textY += 17;
    DrawText("1. Click on cells to activate/deactivate", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("2. Press 'R' to randomize cell states", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("3. Press 'S' to Speed up the Game Speed", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("4. Press 'D' to Speed up the Game Speed", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("5. Press 'C' to clear the grid", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("6. Press 'Enter' to start simulation", boxX + 20, textY, 15, BLACK);
    textY += 17;
    DrawText("7. Press 'Space' to stop simulation", boxX + 20, textY, 15, BLACK);

    // Game Rules
    textY += 25;
    DrawText("Game Rules:", boxX + 20, textY, 17, DARKBLUE);
    textY += 25;
    DrawText("For a living cell:", boxX + 20, textY, 15, DARKGREEN);
    textY += 25;
    DrawText("- Dies if 0-1 neighbors (solitude)", boxX + 20, textY, 15, BLACK);
    textY += 25;
    DrawText("- Dies if 4+ neighbors (overpopulation)", boxX + 20, textY, 15, BLACK);
    textY += 25;
    DrawText("- Survives with 2-3 neighbors", boxX + 20, textY, 15, BLACK);

    textY += 25;
    DrawText("For an empty cell:", boxX + 20, textY, 15, DARKGREEN);
    textY += 25;
    DrawText("- Becomes alive with exactly 3 neighbors", boxX + 20, textY, 15, BLACK);

    // OK Button
    okButton.width = 100;
    okButton.height = 40;
    okButton.x = boxX + (boxWidth - okButton.width) / 2;
    okButton.y = boxY + boxHeight - 60;

    DrawRectangle(okButton.x, okButton.y, okButton.width, okButton.height, LIGHTGRAY);
    DrawRectangleLines(okButton.x, okButton.y, okButton.width, okButton.height, BLACK);
    DrawText("OK", okButton.x + 35, okButton.y + 10, 20, BLACK);
}

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(WIDTH, HEIGHT, "Game Of Life");
    SetTargetFPS(FPS);
    // Initialize The Grid
    Controler controler(WIDTH, HEIGHT, CELL_SIZE);
    // Show instructions at start
    bool showInstructions = true;
    bool isFullscreen = false;
    while(!WindowShouldClose())
    {
        // Handle window resizing
        if (IsWindowResized())
        {
            // Update width and height
            WIDTH = GetScreenWidth();
            HEIGHT = GetScreenHeight();

            // Recalculate cell size to fit the screen
            CELL_SIZE = min(WIDTH / 45, HEIGHT / 45);

            // Recreate the controler with new dimensions
            controler = Controler(WIDTH, HEIGHT, CELL_SIZE);
        }
        // Toggle fullscreen
        if (IsKeyPressed(KEY_F))
        {
            isFullscreen = !isFullscreen;
            if (isFullscreen)
            {
                int monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();
            }
            else
            {
                ToggleFullscreen();
                SetWindowSize(WIDTH, HEIGHT);
            }

            // Recalculate cell size
            CELL_SIZE = min(GetScreenWidth() / 45, GetScreenHeight() / 45);
            controler = Controler(GetScreenWidth(), GetScreenHeight(), CELL_SIZE);
        }
        // Instructions screen
        if (showInstructions)
        {
            BeginDrawing();
            ClearBackground(GRAY);
            controler.draw();
            DrawInstructions();
            EndDrawing();

            // Check for mouse click on OK button
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Vector2 mousePos = GetMousePosition();

                // Check if the mouse is within the button's bounds
                if (mousePos.x >= okButton.x && mousePos.x <= okButton.x + okButton.width &&
                    mousePos.y >= okButton.y && mousePos.y <= okButton.y + okButton.height)
                {
                    showInstructions = false;
                }
            }
            continue;
        }

        // Click Event To Toggle The Cell
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            // Get mouse position
            Vector2 mouse_pos = GetMousePosition();
            // Calculate grid row and column based on mouse position
            int row = mouse_pos.y / CELL_SIZE;
            int col = mouse_pos.x / CELL_SIZE;
            // Toggle cell status
            controler.toggle_cell_stat(row, col);

        }
        // Enter KEY R Event to Randomize The Cell's Status
        if(IsKeyPressed(KEY_R))
        {
            controler.fill_random_cell();
        }
        // Enter KEY C Event to Clear All The Cells Status
        if(IsKeyPressed(KEY_C))
        {
            controler.clear();
        }
        // Enter KEY D Event to Speed down The Game
        if(IsKeyPressed(KEY_D))
        {
            if(FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }

        }
        // Enter KEY S Event to Speed up The Game
        if(IsKeyPressed(KEY_S))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        // Enter Event to Start the Game
        if(IsKeyPressed(KEY_ENTER))
        {
            SetWindowTitle("Game has Running...");
            controler.run();
        }
        // Enter Event Space to Stop The Game
        if(IsKeyPressed(KEY_SPACE))
        {
            SetWindowTitle("Game has Stopped.");
            controler.stop();
        }

        controler.update_cell_stat();
        // Start Drawing The Grid
        BeginDrawing();
        ClearBackground(GRAY);
        controler.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
