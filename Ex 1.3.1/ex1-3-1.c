#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main (int argc, char* args[])
{
     /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("PAC-MAN",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         700, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	/* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    SDL_RenderClear(ren);
    
    int x=100, y=250, r=100, start=20, end=340, count=0; //pie
    int i, x1=220, y1=250, r1=5; //pontos

	
    while(x < 800){
	//para reiniciar o ciclo
        if((x+5) >= 800){
               x = 100;
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
    	
    	
	filledPieRGBA(ren, x, y, r, start, end, 255, 255, 0, 255);
	SDL_RenderPresent(ren);
	SDL_Delay(500);
	x += 5; //o pac-man se move a cada loop
	count += 1; //contador para abrir ou fechar a boca
	if(count % 2 == 0){ //se count for par, fecha a boca
		start = 1;
		end = 358;	
	} else{ //se count for impar, abre a boca
		start = 20;
		end = 340;	
	}
	}




    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
