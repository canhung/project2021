#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "demochuyendong";




void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);



    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
struct Box {
    int x;
    int y;
    int size=10;
    int stepx=0;
    int stepy=0;
    void render(SDL_Renderer* renderer){
    SDL_Rect filled_rect;
    filled_rect.x = x;
    filled_rect.y = y;
    filled_rect.w = size;
    filled_rect.h = size;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &filled_rect);

    }
    void move(){
    x+=stepx;
    y+=stepy;
    }
    void turnleft()
    {
        stepx=-5;
        stepy=0;
    }
    void turnright()
    {
        stepx=5;
        stepy=0;
    }
      void turndown()
    {
        stepy=5;
        stepx=0;
    }
    void turnup()
    {
        stepy=-5;
        stepx=0;
    }
    bool inside(int minX,int minY, int maxX, int maxY){
        return (minX<=x && minY<=y && x+size<=maxX && y+size<=maxY);
    }
};
int main(int argc, char* argv[])
{
      SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    Box box;
    box.x=10;
    box.y=10;
    SDL_Event e;
    while(box.inside(0,0,SCREEN_WIDTH, SCREEN_HEIGHT)){
            box.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
         if ( SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break; // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        		// Nếu phím mũi tên trái, dịch sang trái
    	        // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
        		case SDLK_LEFT: box.turnleft();
        			break;
        		// Tương tự với dịch phải, xuống và lên
            	case SDLK_RIGHT: box.turnright();
            		break;
            	case SDLK_DOWN: box.turndown();
					break;
            	case SDLK_UP: box.turnup();
            		break;
        		default: break;}}

    }
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}


