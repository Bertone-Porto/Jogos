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
    //SDL_SetRenderDrawColor(ren, 0,0,0,0x00);
    //SDL_RenderClear(ren);
    
    SDL_Event evt;
    int x=50, y=250, r=100, start=20, end=340, count=0; //pie
    int i, x1=220, y1=250, r1=5; //pontos
    int rodando=1, red=255, green=255, blue=0;
	bool selecionado = false;
	
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
		SDL_Delay(100);
		
		
		//evento para mover para direita
		SDL_WaitEvent(&evt);
		switch(evt.type){
			case (SDL_MOUSEBUTTONDOWN): //mudar cor a cada click
				if(evt.button.button == SDL_BUTTON_LEFT){
					red = random()%255; green = random()%255; blue = random()%255;
				}
				break;

			case (SDL_KEYDOWN): //mover para direita
				switch(evt.key.keysym.sym) {
					case SDLK_RIGHT:
						count += 1; //contador para abrir ou fechar a boca
						if(count % 2 == 0){ //se count for par, fecha a boca
							start = 1;
							end = 358;	
						} else{ //se count for impar, abre a boca
							start = 20;
							end = 340;	
						}
						x += 5;
					break;
				}
				case SDL_WINDOWEVENT:
					if(SDL_WINDOWEVENT_CLOSE == evt.window.event){
						rodando = 0;
					}
				break;
			
		    }
	
	}

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
