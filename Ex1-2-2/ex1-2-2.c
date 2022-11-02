#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main (int argc, char* args[])
{
     /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	  /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    SDL_RenderClear(ren);
    
    int x=250, y=250, r=100; //circulo
    int x1=50, x2=450, y1=50, y2=450; //retangulo
	  while(r > 30){ //loop para diminuir o raio do circulo e do retangulo
		circleColor(ren, x, y, r, 0xff0000ff);
		r -= 5;
		
		rectangleColor(ren, x1, y1, x2, y2,0xff0000ff);
		x1 += 5;
		x2 -= 5;
		y1 += 5;
		y2 -= 5;
	  }
	  filledCircleColor(ren, x, y, 30, 0xff0000ff); //circulo cheio no meio
	
	  SDL_RenderPresent(ren);
    SDL_Delay(5000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
