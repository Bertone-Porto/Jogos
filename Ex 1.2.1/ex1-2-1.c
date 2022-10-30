#include <SDL2/SDL.h>
int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Um gato",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 150, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 255,255,255,0x00);
    SDL_RenderClear(ren);

	//olhos
    SDL_SetRenderDrawColor(ren, 163,255,127,0x00);
    SDL_Rect r1 = { 60,20,10,10 };
    SDL_RenderFillRect(ren, &r1);
	SDL_Rect r3 = { 100,20,10,10 };
	SDL_RenderFillRect(ren, &r3);

	//nariz
	SDL_SetRenderDrawColor(ren, 60,40,0,0x00);
	SDL_Rect r2 = { 80,40,12,12 };
	SDL_RenderFillRect(ren, &r2);

	//boca
	SDL_SetRenderDrawColor(ren, 200,124,139,0x00);
	SDL_Rect r4 = { 50,50,10,10 };
	SDL_RenderFillRect(ren, &r4);
	SDL_Rect r5 = { 60,60,10,10 };
	SDL_RenderFillRect(ren, &r5);
	SDL_Rect r6 = { 70,60,10,10 };
	SDL_RenderFillRect(ren, &r6);
	SDL_Rect r7 = { 80,70,10,10 };
	SDL_RenderFillRect(ren, &r7);
	SDL_Rect r8 = { 90,60,10,10 };
	SDL_RenderFillRect(ren, &r8);
	SDL_Rect r9 = { 100,60,10,10 };
	SDL_RenderFillRect(ren, &r9);
	SDL_Rect r10 = { 110,50,10,10 };
	SDL_RenderFillRect(ren, &r10);

	//bigode
	SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
	SDL_RenderDrawLine(ren,20,35,70,40);
	SDL_RenderDrawLine(ren,18,38,70,42);
	SDL_RenderDrawLine(ren,20,41,70,44);

	SDL_RenderDrawLine(ren,160,35,110,40);
	SDL_RenderDrawLine(ren,158,38,110,42);
	SDL_RenderDrawLine(ren,160,41,110,44);


    SDL_RenderPresent(ren);
    SDL_Delay(8000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

//bigode
SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
SDL_RenderDrawLine(ren,20,35,70,40);
SDL_RenderDrawLine(ren,18,38,70,42);
SDL_RenderDrawLine(ren,20,41,70,44);

SDL_RenderDrawLine(ren,160,35,110,40);
SDL_RenderDrawLine(ren,158,38,110,42);
SDL_RenderDrawLine(ren,160,41,110,44);


    SDL_RenderPresent(ren);
    SDL_Delay(8000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

