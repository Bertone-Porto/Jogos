#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main (int argc, char* args[])
{
     /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("PAC-MAN",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

/* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    SDL_RenderClear(ren);
   
    SDL_Event evt;
    int x=30, y=30, r=30, start=20, end=340, count=0; //pie
    int i, x1=220, y1=250, r1=1; //pontos
    int rodando=1;


	while(rodando){
		while(SDL_PollEvent(&evt) != 0){
			if(evt.type == SDL_QUIT){
				rodando = 0;
			}
		}
		    if(x >= 600)
		         x = 30;
		    if(x <= 0)
				x = 570;
			if(y >= 600)
				y=30;
			if(y <= 0)
				y=570;

		SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
		SDL_RenderClear(ren);
		if(!(x == 220 && y == 250))
			filledCircleColor(ren, 100, 60, 3, 0xffffffff);
		//pontos que somem quando são encostados
		/*if(x <= 220 && y <= 250){ //quando o x chega na posição do ponto 1, ele some
		filledCircleColor(ren, 220, 250, 5, 0xffffffff); //ponto 1
		filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
		filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 370 && y <= 250){ //quando o x chega na posição do ponto 2, ele some
		filledCircleColor(ren, 370, 250, 5, 0xffffffff); //ponto 2
		filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}
		if(x <= 440 && y <= 520){ //quando o x chega na posição do ponto 3, ele some
		filledCircleColor(ren, 520, 250, 5, 0xffffffff); //ponto 3
		}*/
	   
	   
		filledPieRGBA(ren, x, y, r, start, end, 255, 255, 0, 255);
		SDL_RenderPresent(ren);
		SDL_Delay(100);

		//contador para abrir ou fechar a boca
		/*if(count % 2 == 0){ //se count for par, fecha a boca
		start = 1;
		end = 358;
		} else{ //se count for impar, abre a boca
		start = 20;
		end = 340;
		}*/
		//evento para mover para direita
		SDL_WaitEvent(&evt);
		if (evt.type == SDL_KEYDOWN) {
		count += 1;
		   switch (evt.key.keysym.sym) {
			case SDLK_RIGHT:
			   x += 5;
			if(count % 2 == 0){ //se count for par, fecha a boca
				start = 2;
				end = 357;
			} else{ //se count for impar, abre a boca
				start = 20;
				end = 340;
			}
			break;

			case SDLK_LEFT:
				x -= 5;
				if(count % 2 == 0){ //se count for par, fecha a boca
					start = 200;
					end = 160;
				} else{ //se count for impar, abre a boca
					start = 180;
					end = 178;
				}
				break;

			case SDLK_UP:
				y -= 5;
				if(count % 2 == 0){ //se count for par, fecha a boca
					start = 290;
					end = 250;
				} else{ //se count for impar, abre a boca
					start = 272;
					end = 268;
				}
				break;

			case SDLK_DOWN:
				y += 5;
				if(count % 2 == 0){ //se count for par, fecha a boca
					start = 110;
					end = 70;
				} else{ //se count for impar, abre a boca
					start = 92;
					end = 88;
				}
				break;
		   }
				}

	}


    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
