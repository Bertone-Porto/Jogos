#include <assert.h>
#include <SDL2/SDL.h>

//função do trabalho
int espera = 500;
int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
    if (SDL_WaitEventTimeout(evt, espera)){
    	espera -= (SDL_GetTicks() - *ms);
    	if (espera <= 0) espera = 1;
		return 1;
    } else {
    	espera = 500;
    	return 0;
    }
}


int main (int argc, char* args[])



{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Contando o Tempo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    //int espera = 500;
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        Uint32 antes = SDL_GetTicks();
        int isevt = AUX_WaitEventTimeoutCount(&evt, &antes); // uso da função
        if (isevt) {
            espera -= (SDL_GetTicks() - antes);
            if (espera < 0) {
                espera = 0;
            }
            if (evt.type == SDL_KEYDOWN) {
                switch (evt.key.keysym.sym) {
                    case SDLK_UP:
                        r.y -= 5;
                        break;
                    case SDLK_DOWN:
                        r.y += 5;
                        break;
                    case SDLK_LEFT:
                        r.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        r.x += 5;
                        break;
                }
            }
        } else {
            espera = 500;
            r.x += 2;
            r.y += 2;
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}