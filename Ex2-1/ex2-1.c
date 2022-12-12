#include <assert.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>

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
    SDL_Window* win = SDL_CreateWindow("Contando o Tempo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
	bool rodando=true, selecionado=false, cancel=false, arrasta=false, clicado=false;
	int posX=200, posY=200, x, y, xAnterior, yAnterior;
	SDL_Event evt;
	SDL_Rect r1 = { posX, posY, 80,80 };
	int espera = 10, vencedor=0;
	while (rodando) {
		SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
		SDL_RenderClear(ren);
				
		SDL_SetRenderDrawColor(ren, 250, 0, 0, 250);
		SDL_RenderFillRect(ren, &r1);
		
		if(arrasta){
			stringRGBA(ren, 20,20,"arrastando", 250,0,0,255);
		}
		if(!arrasta && !selecionado && !clicado && !cancel){
			stringRGBA(ren, 20,20,"solto", 250,0,0,255);
		} 
		if(!arrasta && !selecionado && clicado && !cancel){
			stringRGBA(ren, 20,20,"clicado", 250,0,0,255);
		}
		if(!selecionado && !arrasta && cancel){
			stringRGBA(ren, 20,20,"cancelado", 250,0,0,255);
		}

		SDL_RenderPresent(ren);

		SDL_Event evt;
		Uint32 antes = SDL_GetTicks();
		int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
		if (isevt) {
			espera -= (SDL_GetTicks() - antes);
			if (espera < 0) {
				espera = 0;
		   	}
		   	
			if (evt.type == SDL_KEYDOWN) {
				switch (evt.key.keysym.sym) {
					case SDLK_ESCAPE:
						r1.x = xAnterior;
						r1.y = yAnterior;
						selecionado = false;
						arrasta = false;
						cancel = true;	
			    	break;
				}
			}
			
			if(evt.type == SDL_MOUSEBUTTONDOWN){ 
				if(evt.button.button == SDL_BUTTON_LEFT){
					SDL_GetMouseState(&x, &y);
					if(x > posX && x < posX+r1.w && y > posY && y < posY + r1.h){
						xAnterior = posX;
						yAnterior = posY;
						selecionado = true;
						clicado = true;
						cancel = false;
					}
				}
			}
			
			if(evt.type == SDL_MOUSEBUTTONUP){
				if(evt.button.button == SDL_BUTTON_LEFT){
					//SDL_GetMouseState(&x, &y);
					if(evt.button.state == SDL_RELEASED){
						selecionado = false;
						arrasta = false;
						cancel = false;
					}
				}	
			}
			
			if(evt.type == SDL_MOUSEMOTION){
				SDL_GetMouseState(&x,&y);
				if(r1.x <= posX  && r1.y <= posY  && selecionado){
					arrasta = true;
					clicado = false;
					posX = evt.button.x-40;
					posY = evt.button.y-40;
					r1.x = posX ;
					r1.y = posY ;	
				}	
			}
		}			
			switch (evt.type) {
				case SDL_QUIT:
					rodando = false;
					break;
		}	
	}
}
