#ifdef _WIN32
  #include <windows.h>
#endif

#include "SDL.h"

SDL_Surface *screen, *backbuffer;
SDL_Rect     screen_rect;