#include "displayer.h"

displayer::displayer(const char* title, screen* frame) {
    this->title = title;
    this->frame = frame;
    this->initialize();
}

displayer::~displayer() {
    this->cleanup();
}

void displayer::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL\n");
        return;
    }
    this->sdl_window = SDL_CreateWindow("Hello World!", 100, 100, this->frame->get_width(), this->frame->get_height(), SDL_WINDOW_SHOWN);
    if (this->sdl_window == NULL) {
        printf("Could not create SDL window\n");
        return;
    }
    this->sdl_renderer = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->sdl_texture = SDL_CreateTexture(this->sdl_renderer, SDL_PIXELFORMAT_RGB444, SDL_TEXTUREACCESS_STREAMING, this->frame->get_width(), this->frame->get_height());
    printf("displayer initialized with %d %d\n", this->frame->get_width(), this->frame->get_height());

}

void displayer::cleanup() {
    SDL_DestroyWindow(this->sdl_window);
    SDL_DestroyRenderer(this->sdl_renderer);
    SDL_DestroyTexture(this->sdl_texture);
    SDL_Quit();
}

void displayer::refresh() {
    //float* frame_buffer = this->frame->get_buffer();
    //SDL_UpdateTexture(this->sdl_texture, NULL, frame_buffer, this->frame->get_width() * 3 * sizeof(float));
    SDL_RenderClear(this->sdl_renderer);
    //SDL_RenderCopyEx(this->sdl_renderer, this->sdl_texture, NULL, NULL, 0, 0, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(this->sdl_renderer);
}