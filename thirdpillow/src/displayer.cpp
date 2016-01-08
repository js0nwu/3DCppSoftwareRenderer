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
    this->sdl_window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->frame->get_width(), this->frame->get_height(), SDL_WINDOW_SHOWN);
    if (this->sdl_window == NULL) {
        printf("Could not create SDL window\n");
        return;
    }
    //this->sdl_renderer = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_ACCELERATED);
    this->sdl_surface = SDL_GetWindowSurface(this->sdl_window);
    //this->sdl_texture = SDL_CreateTexture(this->sdl_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, this->frame->get_width(), this->frame->get_height());
    frame_surface = SDL_LoadBMP("res/x.bmp");
    printf("displayer initialized with %d %d\n", this->frame->get_width(), this->frame->get_height());

}

void displayer::cleanup() {
    //SDL_DestroyWindow(this->sdl_window);
    //SDL_DestroyRenderer(this->sdl_renderer);
    //SDL_DestroyTexture(this->sdl_texture);
    //SDL_Quit();
}

void displayer::refresh() {
    unsigned char* frame_buffer = this->frame->get_buffer();
    //SDL_UpdateTexture(this->sdl_texture, NULL, frame_buffer, this->frame->get_width() * sizeof(unsigned char));
    //SDL_RenderClear(this->sdl_renderer);
    //SDL_RenderCopyEx(this->sdl_renderer, this->sdl_texture, NULL, NULL, 0, 0, SDL_FLIP_VERTICAL);
    //SDL_RenderPresent(this->sdl_renderer);
    //SDL_Surface* frame_surface = SDL_CreateRGBSurfaceFrom(frame_buffer, this->frame->get_width(), this->frame->get_height(), 3, this->frame->get_width() * sizeof(unsigned char), 0, 0, 0, 0);

    SDL_BlitSurface(frame_surface, NULL, this->sdl_surface, NULL);
    SDL_UpdateWindowSurface(this->sdl_window);
}