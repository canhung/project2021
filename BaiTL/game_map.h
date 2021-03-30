#ifndef GAME_MAP_H
#define GAME_MAP_H
#include"commomfunc.h"
#include"BaseObject.h"

#define MAX_TILES 20
// ke thua hinh anh tu baseobject
class TileMat : public BaseObject
{
public:
    TileMat(){;}
    ~TileMat(){;}
};
//fill vao map
class GameMap
{

public:
    GameMap(){;}
    ~GameMap(){;}
    // doc thong tin file text map
    void LoadMap(char* name);
    //load toan bo hinh anh vd 0 thi load anh 0.png...

    void LoadTiles(SDL_Renderer* screen);
    // ham fill toan bo hinh anh vao cac vi tri
    void DrawMap(SDL_Renderer* screen);
    //set map theo nhan vat
    Map getMap() const {return game_map_;};
    void SetMap(Map& map_data){game_map_= map_data;};
private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
};

#endif // GAME_MAP_H_
