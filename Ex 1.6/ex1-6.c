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
	int rodando = 1;
	SDL_Event evt;
    SDL_Rect r1 = { 40,50, 10,10 };
	SDL_Rect r2 = { 40,250, 10,10 };
	SDL_Rect r3 = { 40,450, 10,10 };
    int espera = 500;
    while (rodando) {

		while(SDL_PollEvent(&evt) != 0){
			if(evt.type == SDL_QUIT){
				rodando = 0;
			}
		}
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
		SDL_RenderDrawLine(ren, 400, 10, 400, 490); 
        SDL_RenderFillRect(ren, &r1);
		SDL_RenderFillRect(ren, &r2);
		SDL_RenderFillRect(ren, &r3);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        Uint32 antes = SDL_GetTicks();
        int isevt = SDL_WaitEventTimeout(&evt, espera);
        if (isevt) {
            espera -= (SDL_GetTicks() - antes);
            if (espera < 0) {
                espera = 0;
            }
            if (evt.type == SDL_KEYDOWN) {
                switch (evt.key.keysym.sym) {
                    /*case SDLK_UP:
                        r1.y -= 5;
                        break;
                    case SDLK_DOWN:
                        r1.y += 5;
                        break;*/
                    case SDLK_LEFT:
                        r1.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        r1.x += 5;
                        break;
                }
            }
			if(evt.type == SDL_MOUSEMOTION){
				int x, y;
				SDL_GetMouseState(&x, &y);
				r3.x = x;
				r3.y = y;
			}} else {
		        espera = 500;
		        r2.x += 2;
		        //r2.y += 2;
        	}
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
