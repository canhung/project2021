#include"commomfunc.h"
#include"BaseObject.h"
#include"game_map.h"
#include"MainObject.h"
#include"Timer.h"
BaseObject g_background;
bool InitData()
{
    bool success = true;
    int ret= SDL_Init(SDL_INIT_VIDEO);
    if(ret<0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
    gwindow=SDL_CreateWindow("GameofCMH",
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH,SCREEN_HEIGHT,
                             SDL_WINDOW_SHOWN);
    if(gwindow== NULL)
    {
        success = false;
    }
    else
    {
        gscreen=SDL_CreateRenderer(gwindow,-1,SDL_RENDERER_ACCELERATED);
        if(gscreen == NULL)
            success= false;
        else
        {
            SDL_SetRenderDrawColor(gscreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags=IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags)&& imgFlags))
                success= false;
        }
    }

    return success;
}
bool LoadBackground()
{
    bool ret= g_background.LoadImg("background.png",gscreen);
    if (ret== false) return false;
    return true;
}
void close()
{
    g_background.Free();
    SDL_DestroyRenderer(gscreen);
    gscreen=NULL;
    SDL_DestroyWindow(gwindow);
    gwindow=NULL;
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[])
{   Timer fps_timer;

    if(InitData()==false)
        return -1;
    if(LoadBackground()==false)
        return -1;

    GameMap game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTiles(gscreen);

    MainObject p_player;
    p_player.LoadImg("img//player_right.png",gscreen);
    p_player.set_clips();

    bool is_quit = false;
    while(!is_quit)
    {
        fps_timer.start();
        while(SDL_PollEvent(&gevent)!=0)
        {
            if(gevent.type == SDL_QUIT)
            {
                is_quit=true;
            }
            p_player.HandlInputAction(gevent,gscreen);
        }
        SDL_SetRenderDrawColor (gscreen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(gscreen);
        g_background.Render(gscreen,NULL);
        Map map_data= game_map.getMap();
        p_player.SetMapXY(map_data.start_x_,map_data.start_y_);
        p_player.DoPlayer(map_data);
        p_player.Show(gscreen);

        game_map.SetMap(map_data);
        game_map.DrawMap(gscreen);
        SDL_RenderPresent(gscreen);
        int real_time=fps_timer.get_ticks();
        int time_one_frame=1000/FRAME_PER_SECOND; //1 frame chay het bao nhieu m
        if(real_time< time_one_frame)
        {
            int delay_time=time_one_frame-real_time;//xem 1 frame tre bao nhieu ms
            if(delay_time>=0)
                SDL_Delay(delay_time);
        }
    }
    close();
    return 0;
}
