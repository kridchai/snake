#include <iostream>
#include<SFML/Graphics.hpp>
#include<cstdlib>
using namespace sf;
enum movement{Left,Right,Up,Down};

int frame = 0;
int lenght = 1;



movement dir = Down;
struct Snake{
int x = 0;
int y = 0;
};
int row = 20;
int colum = 30;
int main()
{
    sf::Texture t1,t2,t3;
    t1.loadFromFile("white.png");
    t2.loadFromFile("green.png");
    t3.loadFromFile("red.png");
    Sprite s1,s2,s3;
    s1.setTexture(t1);
    s2.setTexture(t2);
    s3.setTexture(t3);
    Snake s[100];

    int x = t1.getSize().x;
    int y = t1.getSize().y;

    int foodx = rand() % colum * x;
    int foody = rand() % row * y;

    RenderWindow window(VideoMode(colum * t1.getSize().x,row * t1.getSize().y),"gdgg");

    while(window.isOpen()){

        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
                window.close();
        }


    if(frame %300 ==0)
    {


        if(s[0].x==foodx && s[0].y==foody)
        {
            lenght++;
            foodx = rand() % colum * x;
            foody = rand() % row * y;
        }


        for(int i =1;i<lenght;i++)
        {
            if(s[0].x==s[i].x && s[0].y==s[i].y)
            {
                lenght = i;
                break;
            }
        }



        for(int i =lenght-1;i>0;i--){
            s[i].x = s[i-1].x;
            s[i].y = s[i-1].y;

        }

        if(s[0].x<0)
            {
                if(dir!=Left)
                    s[0].x = window.getSize().x - x;
                else
                     s[0].x = window.getSize().x;
            }

        else if(s[0].x>window.getSize().x-x)
        {
            if(dir!=Right)
                s[0].x = 0;
            else
                s[0].x = 0 - x;
        }

        else if(s[0].y<0)
        {
            if(dir!=Up)
                s[0].y = window.getSize().y-y;
            else
                s[0].y = window.getSize().y;
        }

        else if(s[0].y>window.getSize().y-y)
            {
                if(dir!=Down)
                    s[0].y = 0;
                else
                    s[0].y = 0 - y;
            }

        if(dir==Down)
        s[0].y+=y;
            else if(dir==Up)
        s[0].y-=y;
            else if(dir==Left)
        s[0].x-=x;
            else if(dir==Right)
        s[0].x+=x;

    }




    if(Keyboard::isKeyPressed(Keyboard::Left))
        dir = Left;
     if(Keyboard::isKeyPressed(Keyboard::Right))
        dir = Right;
     if(Keyboard::isKeyPressed(Keyboard::Up))
        dir = Up;
     if(Keyboard::isKeyPressed(Keyboard::Down))
        dir = Down;





    window.clear();
    for(int i = 0;i<row;i++){
        for(int j = 0;j<colum;j++){
            s1.setPosition(Vector2f(j * t1.getSize().x,i * t1.getSize().y));
            window.draw(s1);
        }
    }
    window.draw(s1);
    for(int i = 0;i<lenght;i++)
    {
        s2.setPosition(s[i].x,s[i].y);
        window.draw(s2);
    }
    s3.setPosition(foodx,foody);
    window.draw(s3);
    window.display();
    frame++;

    }
    return 0 ;
}
