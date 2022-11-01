#include <SDL2/SDL.h>
#include <math.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius){
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 1000, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
	int x=500, y=500, r=100, i;
	while(r > 30){
		circleColor(ren,x,y, r, 0xff0000ff);
		filledCircleColor(ren, x, y, 30, 0xff0000ff);
		r -= 5;

	}
	circleColor(ren,500,500, 100, 0xff0000ff);
	//circleRGBA(ren, 100, 100, 50, 255, 0, 0, 255);
	//ellipseRGBA(ren, 500, 300, 400, 200, 255 ,0,0,255);

	//stringRGBA(ren, 110, 350, "oooiiiii", 255, 0, 0,255);
	//filledPieRGBA(ren, 600, 200,360,0,200,255,0,0,255);
	//roundedRectangleRGBA(ren, 100, 200,250,300,100,255,0,0,255);
	filledCircleColor(ren, 500, 500, 30, 0xff0000ff);


	SDL_RenderPresent(ren);
    SDL_Delay(10000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
