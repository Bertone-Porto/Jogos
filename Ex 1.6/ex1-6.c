/*
Faça os objetos se moverem somente no eixo X (feito)
Desenhe uma linha de chegada (feito/beta)
Pare os objetos que atingirem a linha de chegada
Aguarde todos atingirem a linha de chegada
Anuncie o objeto que chegou primeiro
Reinicie a aplicação
*/

#include <assert.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int AUX_WaitEventTimeoutCount (SDL_Event* evt, Uint32* ms){
	//Uint32 tempo = 0;
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
	bool rodando = true, jogo=true, resultado=false;
	SDL_Event evt;
	SDL_Rect r1 = { 40,50, 10,10 };
	SDL_Rect r2 = { 40,250, 10,10 };
	SDL_Rect r3 = { 40,450, 10,10 };
	int espera = 100, vencedor=0;
	while(jogo){
		while (rodando) {
			SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
			SDL_RenderClear(ren);
			SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
			SDL_RenderDrawLine(ren, 400, 0, 400, 500);

			SDL_RenderFillRect(ren, &r1);
			SDL_RenderFillRect(ren, &r2);
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
				    	/*case SDLK_LEFT:
				        r1.x -= 5;
				        break;*/
				      	case SDLK_RIGHT:
							if(r1.x <= 405)
				            	r1.x += 5;
				            if(r2.x <= 405 && r3.x <= 405)
				            	vencedor = 1;
				            break;

				        }
			 	}
				if(evt.type == SDL_MOUSEMOTION){ //RECT MOVIDO PELO MOUSE
					int x, y;
					SDL_GetMouseState(&x, &y);
					if(r3.x <= 405){
						r3.x = x;
						//r3.y = y;
					}
					if(r1.x <= 405 && r2.x <= 405)
				        vencedor = 3;
				} 
			}else { //RECT MOVIDO PELO TEMPO
				espera = 100;
				if(r2.x <= 405){
					r2.x += 50;
				}
				if(r1.x <= 405 && r3.x <= 405)
				    vencedor = 2;

			}
			if(r1.x >=405 && r2.x >= 405 && r3.x >= 405){
				//jogo = false;
				rodando = false;
				resultado == true;
				/*SDL_SetRenderDrawColor(ren, 250,250,250,0x00);
				SDL_RenderClear(ren);
				SDL_RenderPresent(ren);*/
				
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
		while(resultado){
			SDL_SetRenderDrawColor(ren, 240,248,255,0x00);
			SDL_RenderClear(ren);
			SDL_Rect r5 = { 250,250, 50,50 };
			SDL_RenderFillRect(ren, &r5);
			SDL_RenderPresent(ren);
			stringColor(ren, 250, 250, "Vencedor: rect 1", 0x00000000);
			if(vencedor == 1){
				stringColor(ren, 250, 250, "Vencedor: rect 1", 0x00000000);
			} else if(vencedor == 2){
				stringColor(ren, 250, 250, "Vencedor: rect 2", 0x00000000);
			} else{
				stringColor(ren, 250, 250, "Vencedor: rect 3", 0x00000000);
			}
			SDL_Delay(2000);
			resultado = false;

		}
	}
}
		

