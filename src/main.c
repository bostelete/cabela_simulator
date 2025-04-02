#include "../raylib/raylib.h"

#define CABELA_MODEL "src/model/cabela.glb"

int main(void) {

    InitWindow(800, 600, "Cabela");
    SetTargetFPS(60);

    Camera camera = {0};
    camera.position = (Vector3){0, 0.5, -1};
    camera.target = (Vector3){0, 0, 0};
    camera.up = (Vector3){0, 1, 0};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model cabela = LoadModel(CABELA_MODEL);
    Vector3 cabela_pos = {0, 0, 0};
    double rot = 0;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(GetColor(0x181818FF));

        BeginMode3D(camera);

        DrawModelEx(cabela, cabela_pos, (Vector3){0, 1, 0}, rot++, (Vector3){1, 1, 1}, WHITE);

        EndMode3D();

        EndDrawing();
    }

    UnloadModel(cabela);
    CloseWindow();

    return 0;
}
