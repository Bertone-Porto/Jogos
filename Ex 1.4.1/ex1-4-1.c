#include <SDL2/SDL.h>

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
    SDL_Rect r1; 
    SDL_Event evt;
    int rodando = 1, x, y, cont=0;
    int red, green, blue;
    while (rodando) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

		//para fechar a janela
		while(SDL_PollEvent(&evt) != 0){
			if(evt.type == SDL_QUIT){
				rodando = 0;
			}
			else if(evt.type == SDL_MOUSEBUTTONDOWN){
				if(evt.button.button == SDL_BUTTON_LEFT){
					cont += 1;
					if(cont <= 10){ //conta quantas rect foram adicionados 
						x = evt.button.x;
						y = evt.button.y;
						red = random(); green = random(); blue = random(); //cores aleatórias
						SDL_SetRenderDrawColor(ren, red,green,blue,0x00);
						SDL_Rect r1 = {x, y, 10, 10};
						SDL_RenderFillRect(ren, &r1);
						SDL_RenderPresent(ren);
						SDL_Delay(1000);
					}
				}
			}
		}
		
        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
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
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
