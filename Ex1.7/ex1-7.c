#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
int AUX_WaitEventTimeoutCount (SDL_Event* evt, Uint32* ms){
	Uint32 antes = SDL_GetTicks();
	int isevt = SDL_WaitEventTimeout(evt, *ms);
	if(isevt){
		Uint32 tempo = (SDL_GetTicks() - antes);
	if(*ms < tempo)
		tempo = *ms;
		*ms -= tempo;
	}
	else
		*ms = 500;
	return isevt;
}

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(0);
    SDL_Window* win = SDL_CreateWindow("Animação",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 200, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_Texture* img = IMG_LoadTexture(ren, "rots-sprite.png");
    assert(img != NULL);

    /* EXECUÇÃO */
    bool continua = true;
    SDL_Event evt;
    int isup = 1;
    int x = 80;
    int espera = 50;
    int yC=390, wC=40, hC=80;
    while (continua) {
        SDL_SetRenderDrawColor(ren, 186,254,202,0);
        SDL_RenderClear(ren);
        SDL_Rect r = { x,140, 70,70 };
        SDL_Rect c;
      	Uint32 antes = SDL_GetTicks();
        int isevt = AUX_WaitEventTimeoutCount(&evt,&espera);       
        if(isevt){       	
		switch (evt.type ) {
		    case SDL_QUIT:
		    	continua = false;
		    	break;		
		}
	
	}
	
	else{   
		switch(isup){
			case 1:
				c = (SDL_Rect) {   0,yC, wC,hC };
			break;
			case 2:
				c = (SDL_Rect) { 32,yC, wC,hC };
			break;
			case 3:
				c = (SDL_Rect) { 72,yC, wC,hC };
			break;
			case 4:
				c = (SDL_Rect) { 112,yC, wC,hC };
			break;
			case 5:
				c = (SDL_Rect) { 142,yC, wC,hC };
			break;
			case 6:
				c = (SDL_Rect) { 176,yC, wC,hC };
			break;
			case 7:
				c = (SDL_Rect) { 256,yC, wC,hC };
			break;
			case 8:
				c = (SDL_Rect) { 288,yC, wC,hC };
			break;
			case 9:
				c = (SDL_Rect) { 328,yC, wC,hC };
			break;

		}
		isup++;
	
		SDL_RenderCopy(ren, img, &c, &r);
		SDL_RenderPresent(ren);
		espera = 220;
		if(isup > 9){
			isup = 1;
		}
		
	}
    }

    /* FINALIZACAO */
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
