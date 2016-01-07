#include "engine.h"

using namespace std;

static const int SCREEN_WIDTH = 1280;
static const int SCREEN_HEIGHT = 720;

static const int FRAME_CAP = 60;

int main(int argc, char** argv) {
    printf("Hello World!\n");
    engine thirdpillow(SCREEN_WIDTH, SCREEN_HEIGHT, FRAME_CAP);
    thirdpillow.start();
    return 0;
}
