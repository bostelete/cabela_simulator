#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#define SRC_FOLDER "src/"
#define CFLAGS "-Wall", \
               "-Wextra"

#define POSIX_FLAGS "-L./raylib/linux", \
                    "-lraylib",         \
                    "-lm"

#define WIN32_FLAGS "-L./raylib/windows/", \
                    "-lraylib",            \
                    "-lm",                 \
                    "-lgdi32",             \
                    "-lwinmm",             \
                    "-lopengl32",          \
                    "-static",             \
                    "-mwindows"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Cmd cmd = {0};

    cmd_append(&cmd, "gcc", "src/main.c", CFLAGS, POSIX_FLAGS, "-o", "cabela");

    if (!nob_cmd_run_sync_and_reset(&cmd))
        return 1;

    cmd_append(&cmd, "x86_64-w64-mingw32-gcc", "src/main.c", CFLAGS, WIN32_FLAGS, "-o", "cabela.exe");

    if (!nob_cmd_run_sync_and_reset(&cmd))
        return 1;

    return 0;
}
