#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>

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
	IMG_iNIT(0);
    SDL_Window* win = SDL_CreateWindow("PAC-MAN",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         700, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
	SDL_Texture* img = IMG_LoadTexture(ren, /*imagem*/);
	
	/* EXECUÇÃO */
   
    SDL_Event evt;
    int x=50, y=250, r=100, start=20, end=340, count=0; //pie
    int i, x1=220, y1=250, r1=5; //pontos
    int rodando=1, red=255, green=255, blue=0;
	int espera=100;

	while(rodando){
		if((x+5) >= 800){
		    x = 50;
		}
		SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
		SDL_RenderClear(ren);

		//pontos que somem quando são encostados
		if(x <= 150){ //quando o x chega na posição do ponto 1, ele some
			filledCircleColor(ren, 220, 250, 5, 0xffffffff); //ponto 1
			filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 280){ //quando o x chega na posição do ponto 2, ele some
			filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 440){ //quando o x chega na posição do ponto 3, ele some
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
	   
		filledPieRGBA(ren, x, y, r, start, end, red, green, blue, 255);
		SDL_RenderPresent(ren);

		Uint32 antes = SDL_GetTicks();
		int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
		if(isevt){
			espera -= (SDL_GetTicks() - antes);
			if(espera<0){
				espera = 0;
			}
			if(evt.type == SDL_MOUSEBUTTONDOWN){
				switch(evt.button.button){  //mudar cor a cada click
					case SDL_BUTTON_LEFT:
						red = random()%255; green = random()%255; blue = random()%255;
						break;
				}
			}

		} else{
			espera=100;
			count += 1; //contador para abrir ou fechar a boca
			x += 5;
			if(count % 2 == 0){ //se count for par, fecha a boca
			start = 1;
			end = 358;
			} else{ //se count for impar, abre a boca
			start = 20;
			end = 340;
			}
		}
		switch (evt.type) {
		case SDL_QUIT:
			rodando = 0;
			break;
		}
	}
    
}
			filledCircleColor(ren, 220, 250, 5, 0xffffffff); //ponto 1
			filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 280){ //quando o x chega na posição do ponto 2, ele some
			filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 440){ //quando o x chega na posição do ponto 3, ele some
			filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
	   
		filledPieRGBA(ren, x, y, r, start, end, red, green, blue, 255);
		SDL_RenderPresent(ren);

		Uint32 antes = SDL_GetTicks();
		int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
		if(isevt){
			espera -= (SDL_GetTicks() - antes);
			if(espera<0){
				espera = 0;
			}
			if(evt.type == SDL_MOUSEBUTTONDOWN){
				switch(evt.button.button){  //mudar cor a cada click
					case SDL_BUTTON_LEFT:
						red = random()%255; green = random()%255; blue = random()%255;
						break;
				}
			}

		} else{
			espera=100;
			count += 1; //contador para abrir ou fechar a boca
			x += 5;
			if(count % 2 == 0){ //se count for par, fecha a boca
			start = 1;
			end = 358;
			} else{ //se count for impar, abre a boca
			start = 20;
			end = 340;
			}
		}

	}
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
