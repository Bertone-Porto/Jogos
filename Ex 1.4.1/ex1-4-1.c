#include <SDL2/SDL.h>

struct Rects{
	SDL_Rect r1;
	int r, g, b;
};


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 60,95, 10,10 };
    SDL_Rect r_aux;
	struct Rects r1[10];
    SDL_Event evt;
    int rodando = 1, x, y, cont=0, i;
    int red, green, blue;

    while (rodando) { 
    	
		
		SDL_SetRenderDrawColor(ren, 255,255,255,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0x00);
        SDL_RenderFillRect(ren, &r);

		for(i=0;i<cont;i++){
			SDL_SetRenderDrawColor(ren, r1[i].r,r1[i].g,r1[i].b,0x00);
			SDL_RenderFillRect(ren, &r1[i].r1);
		}

        SDL_RenderPresent(ren);

		SDL_WaitEvent(&evt);
		switch (evt.type){
			case SDL_KEYDOWN: // caso para mover o rect
				switch (evt.key.keysym.sym) {
					case SDLK_UP:
					if((r.y-5) != -5){
						r.y -= 5;
					}
					break;
						   
					case SDLK_DOWN:
					if((r.y + 5) != 95){
						r.y += 5;
					}
					break;
					
					case SDLK_LEFT:
					if((r.x-5) != -5){
						r.x -= 5;
					}
					break;
						   
					case SDLK_RIGHT:
					if((r.x+5) != 195){
						r.x += 5;
					}
				    break;
				}
				
			case (SDL_MOUSEBUTTONDOWN): //para adicionar o rect na tela
		 		if(evt.button.button == SDL_BUTTON_LEFT){
					
					if(cont <= 10){ //conta quantas rect foram adicionados
						x = evt.button.x;
						y = evt.button.y;
						red = random()%255; green = random()%255; blue = random()%255; //cores aleatórias
						SDL_Rect r_aux = {x, y, 10, 10};
						r1[cont].r1 = r_aux;
						r1[cont].r = red;
						r1[cont].g = green;
						r1[cont].b = blue;
						cont += 1;
					} break;
				}
			
			case SDL_WINDOWEVENT: // para fechar a janela
				if(SDL_WINDOWEVENT_CLOSE == evt.window.event){
					rodando = 0;
				} break;
		}

    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
