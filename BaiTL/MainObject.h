#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include"commomfunc.h"
#include"BaseObject.h"

#define tocdoroi 0.8
#define tocdoroimax 10
#define PLAYER_SPEED 6
#define PLAYER_JUMP_VAL 19

class MainObject: public BaseObject
{

public:
    MainObject();
    ~MainObject();

    enum WalkType
    {
        WALK_RIGHT=0,
        WALK_LEFT=1,
    };
    bool LoadImg(std:: string path, SDL_Renderer* screen);
    void Show(SDL_Renderer*des);
    //ham xu li su kien nhan vat
    void HandlInputAction(SDL_Event events, SDL_Renderer* screen);
    //xu li hieu ung hoat hinh nhanvat
    void set_clips();
    //cong tru them 1 luong nhan vat di chuyen
    void DoPlayer(Map& map_data);
    //kiem tra va cham voi map
    void CheckToMap(Map& map_data);
    void SetMapXY(const int map_x,const int map_y){map_x_=map_x;map_y_=map_y;}
    //ham tinh toan thong so cua map khi nv di chuyen
    void CenterEntityOnMap(Map& map_data);


private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8];
    //luu bien trang thai
    Input input_type_;
    //luu chi so frame
    int frame_;
    //luu trang thai status
    int status_;
    bool on_ground_;

    int map_x_;
    int map_y_;

    int come_back_time_; //khi roi xuong cho qua lau se quay tro lai
};

#endif // MAIN_OBJECT_H_
