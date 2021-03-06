#ifndef LOPDAN_H_
#define LOPDAN_H_

#include"BaseObject.h"
#include"commomfunc.h"

class Lopdan : public BaseObject
{
public:
    Lopdan();
    ~Lopdan();
    enum BulletDir
    {   //gan huong dan ban
        DIR_RIGHT=20,
        DIR_LEFT=21,
        DIR_UP=22,
        DIR_UP_LEFT=23,
        DIR_UP_RIGHT=24,
        DIR_DOWN_LEFT=25,
        DIR_DOWN_RIGHT=26,
        DIR_DOWN=27,

    };

    void set_x_val(const int & xVal){x_val_=xVal;}
    void set_y_val(const int & yVal){y_val_=yVal;}
    int get_x_val() const {return x_val_;}
    int get_y_val()const {return y_val_;}

    void set_is_move(const bool& isMove){is_move_=isMove;}
    bool get_is_move() const {return is_move_;}

    void set_bullet_dir(const unsigned int& bulletDir ){bullet_dir_=bulletDir;}
    int get_bullet_dir()const {return bullet_dir_;}

    //ham xu li di chuyen cho vien dan
    void HandleMove(const int & x_border, const int& y_border);

private:
    int x_val_;
    int y_val_;
    bool is_move_;//kiem tra xem vien dan co nam trong man hinh hay k
    unsigned int bullet_dir_;

};

#endif // LOPDAN_H_
