/*
Faça os objetos se moverem somente no eixo X (feito)
Desenhe uma linha de chegada (feito/beta)
Pare os objetos que atingirem a linha de chegada
Aguarde todos atingirem a linha de chegada
Anuncie o objeto que chegou primeiro
Reinicie a aplicação
*/
/*
		SDL_Event evt;
		SDL_WaitEvent(&evt);
		switch(evt.type){
			case SDL_MOUSEBUTTONDOWN:
				posX = evt.button.x;
				posY = evt.button.y;
				if(x >= 100 && x <= 220 && y >= 400 && y <= 440){
					stringRGBA(ren, 50, 50, "Clickei", 0, 0, 0, 250);
					SDL_Delay(2000);
					rodando = 0;
				}
		}
*/

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

void MostraResultado(int vencedor, SDL_Renderer* ren){    
	SDL_SetRenderDrawColor(ren, 210,210,210,0x00);
	SDL_RenderClear(ren);
	if(vencedor == 1){
		rectangleRGBA(ren, 195, 95, 335, 115, 250, 0, 0, 250);
		stringRGBA(ren, 200, 100, "Vencedor: rect 1", 250, 0, 0, 250);

	} else if(vencedor == 2){
		stringRGBA(ren, 200, 100, "Vencedor: rect 2", 0, 100, 0, 250);
		rectangleRGBA(ren, 195, 95, 335, 115, 0, 100, 0, 250);

	} else{
		stringRGBA(ren, 200, 100, "Vencedor: rect 3", 0, 0, 250, 250);
		rectangleRGBA(ren, 195, 95, 335, 115, 0, 0, 250, 250);
	}
	
	SDL_RenderPresent(ren);
	SDL_Delay(4000);

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
	bool rodando = true, jogo=true, resultado=false;
	SDL_Event evt;
	SDL_Rect r1 = { 20,50, 10,10 };
	SDL_Rect r2 = { 20,250, 10,10 };
	SDL_Rect r3 = { 20,450, 10,10 };
	int espera = 100, vencedor=0;
	while (rodando) {
			if((r1.x >= 405) && (r2.x >= 405) && (r3.x >= 405)){
				MostraResultado(vencedor, ren);
				r1.x = 20;
				r2.x = 20;
				r3.x = 20;
				vencedor=0;

				//rodando = false;	
			} else{
				SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
				SDL_RenderClear(ren);
				SDL_SetRenderDrawColor(ren, 0, 0, 0, 250);
				SDL_RenderDrawLine(ren, 400, 0, 400, 500);
				
				SDL_SetRenderDrawColor(ren, 250, 0, 0, 250);
				SDL_RenderFillRect(ren, &r1);
				
				SDL_SetRenderDrawColor(ren, 0, 100, 0, 250);
				SDL_RenderFillRect(ren, &r2);

				SDL_SetRenderDrawColor(ren, 0, 0, 250, 250);
				SDL_RenderFillRect(ren, &r3);

				SDL_RenderPresent(ren);

				SDL_Event evt;
				Uint32 antes = SDL_GetTicks();
				int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
				if (isevt) {
					espera -= (SDL_GetTicks() - antes);
					if (espera < 0) {
						espera = 0;
				   	}
					if (evt.type == SDL_KEYDOWN) { //RECT MOVIDO PELO TECLADO
						switch (evt.key.keysym.sym) {
						  	case SDLK_RIGHT:
								if(r1.x <= 405)
						        	r1.x += 10;
						        if(r2.x <= 405 && r3.x <= 405)
						        	vencedor = 1;
						        break;

						}
				 	}
					if(evt.type == SDL_MOUSEBUTTONDOWN){ //RECT MOVIDO PELO CLICK DO MOUSE
						if(r3.x <= 405){
							r3.x += 30;
						}
						if(r1.x <= 405 && r2.x <= 405)
						    vencedor = 3;
					} 
				}else { //RECT MOVIDO PELO TEMPO
					espera = 100;
					if(r2.x <= 405){
						r2.x += 10;
					}
					if(r1.x <= 405 && r3.x <= 405)
						vencedor = 2;

				}
				
				
				switch (evt.type) {
					case SDL_QUIT:
						rodando = false;
						jogo = false;
						break;
					case SDL_KEYDOWN:
						if(evt.key.keysym.sym == SDLK_F4){
							if(evt.key.keysym.mod == KMOD_LALT){
								rodando = false;
								jogo= false;
								break;
							}	
						}
				}	
			}
		}
	
}
