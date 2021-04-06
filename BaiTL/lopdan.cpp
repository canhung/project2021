#include"Lopdan.h"

Lopdan:: Lopdan()
{
    x_val_=0;
    y_val_=0;
    is_move_=false;
}
Lopdan::~Lopdan()
{

}
void Lopdan::HandleMove(const int& x_border, const int& y_border)
{
    if(bullet_dir_==DIR_RIGHT)
    {
            rect_.x+=x_val_;
        if(rect_.x>x_border)
        {
            is_move_=false;
        }

    }
    else if(bullet_dir_==DIR_LEFT)
    {
        rect_.x-=x_val_;
        if(rect_.x<0)
        {
            is_move_=false;
        }
    }
    else if(bullet_dir_==DIR_UP)
    {
        rect_.y-=y_val_;
        if(rect_.y<0)
        {
            is_move_=false;
        }
    }
    else if(bullet_dir_==DIR_UP_LEFT)
    {
        rect_.x-=x_val_;
        if(rect_.x<0)
        {
            is_move_=false;
        }
        rect_.y-=y_val_;
         if(rect_.y<0)
        {
            is_move_=false;
        }

    }
    else if(bullet_dir_==DIR_UP_RIGHT)
    {
        rect_.x+=x_val_;
        if(rect_.x>x_border)
        {
            is_move_=false;
        }
        rect_.y-=y_val_;
         if(rect_.y<0)
        {
            is_move_=false;
        }

    }
     else if(bullet_dir_==DIR_DOWN_RIGHT)
    {
        rect_.x+=x_val_;
        if(rect_.x>x_border)
        {
            is_move_=false;
        }
        rect_.y+=y_val_;
         if(rect_.y>y_border)
        {
            is_move_=false;
        }

    }
    else if(bullet_dir_==DIR_DOWN_LEFT)
    {
        rect_.x-=x_val_;
        if(rect_.x<0)
        {
            is_move_=false;
        }
        rect_.y+=y_val_;
         if(rect_.y>y_border)
        {
            is_move_=false;
        }

    }
}
