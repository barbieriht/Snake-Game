#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Menu.hpp"
#include <string>
#include <fstream>
#include "Recordes.hpp"

using namespace sf;

int N=30, M=20;
int size=32;
int w=size*N;
int h=size*M;

int dir, lastkey=5, score=4;

struct Snake
{
    int x,y;
}  s[100];

struct Fruit
{
    int x,y;
} f;

void TocaMaca()
{
    SoundBuffer buffermaca;

    if(!buffermaca.loadFromFile("songs/maca.wav"))
        printf("ERROR MACA\n");

    Sound maca;

    maca.setBuffer(buffermaca);

    maca.play();
}

void TocaComida()
{
    SoundBuffer buffercomida;

    if(!buffercomida.loadFromFile("songs/comida.wav"))
        printf("ERROR COMIDA\n");

    Sound comida;

    comida.setBuffer(buffercomida);

    comida.play();
}

void TocaLapada()
{
    SoundBuffer bufferlapada;

    if(!bufferlapada.loadFromFile("songs/lapada.wav"))
        printf("ERROR LAPADA\n");

    Sound lapada;

    lapada.setBuffer(bufferlapada);

    lapada.play();
}
void Recorde(Recordes rec)
{
    RenderWindow window(VideoMode(w,h),"RECORDES");

   while(window.isOpen())
   {
       Event event;

       while(window.pollEvent(event))
       {
           switch(event.type)
           {
            case (Event::KeyReleased):
               switch(event.key.code)
               {
                    case (Keyboard::Up):
                    break;

                    case (Keyboard::Down):
                    break;

                    case (Keyboard::Left):
                    break;

                    case (Keyboard::Right):
                    break;

                    case (Keyboard::W):
                    break;

                    case (Keyboard::S):
                    break;

                    case (Keyboard::A):
                    break;

                    case (Keyboard::D):
                    break;

                    default:
                        window.close();
               }
               break;
            case Event::Closed:
                window.close();
                break;
           }
       }
       window.clear();

       Texture background;
       background.loadFromFile("images/background.jpg");
       Sprite bg(background);
       window.draw(bg);

       rec.draw(window);
       window.display();
   }
}

int ConfereArquivo(int score)
{
    int highsc;

    std::fstream arq ("Highscore.bin", std::ios_base::in | std::ios_base::binary);

    if(arq.is_open())
        printf("ARQUIVO ABRIU\n");
    arq.read(reinterpret_cast<char*> (&highsc), sizeof(highsc));
    printf("Highsc: %d\n", highsc);
    if(score > highsc)
    {
        std::fstream arq ("Highscore.bin", std::ios_base::out | std::ios_base::binary);
        arq.write((char*)&score, sizeof(score));
        printf("Score: %d\n", score);
        highsc = score;
        printf("High final: %d\n", highsc);
    }
        arq.close();
    return highsc;
}

void game()
{
    srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");

    Texture t1,t2,t3,tright,tup,tleft,tdown;
    t1.loadFromFile("images/fundo.png");
    t2.loadFromFile("images/maca.png");
    t3.loadFromFile("images/snake_body.png");
    tright.loadFromFile("images/snake_right.png");
    tup.loadFromFile("images/snake_up.png");
    tleft.loadFromFile("images/snake_left.png");
    tdown.loadFromFile("images/snake_down.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    Sprite spritup(tup);
    Sprite spritleft(tleft);
    Sprite spritdown(tdown);
    Sprite spritright(tright);

    Clock clock;
    float timer=0, delay=0.085;

    f.x=10;
    f.y=10;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        if (lastkey!=2 && (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)))
        {
            dir=1;
        }
        if (lastkey!=1 && (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)))
        {
            dir=2;
        }
        if (lastkey!=0 && (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)))
        {
            dir=3;
        }
        if (lastkey!=3 && (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)))
        {
            dir=0;
        }

            lastkey = dir;
        if (timer>delay)
        {
            timer=0;
            for (int i=score;i>0;--i)
             {
                 s[i].x=s[i-1].x;
                 s[i].y=s[i-1].y;
            }

            switch(dir){
                case 0:
                        s[0].y+=1;
                        break;
                case 1:
                        s[0].x-=1;
                        break;
                case 2:
                        s[0].x+=1;
                        break;
                case 3:
                        s[0].y-=1;
                        break;
            }

            if ((s[0].x==f.x) && (s[0].y==f.y))
             {
                 TocaComida();
                 score++;
                 f.x=rand()%N;
                 f.y=rand()%M;
            }

            if (s[0].x>N-1)
                s[0].x=0;
            if (s[0].x<0)
                s[0].x=N-1;
            if (s[0].y>M-1)
                s[0].y=0;
            if (s[0].y<0)
                s[0].y=M-1;

            for (int i=1;i<score;i++)
             if (s[0].x==s[i].x && s[0].y==s[i].y)
             {
                 TocaLapada();
                 int HIGHEST = ConfereArquivo(score);
                 Recordes high(score, HIGHEST, window.getSize().x, window.getSize().y);
                 Recorde(high);
                 score = 4;

                 window.close();
                 return;
             }
        }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            sprite1.setPosition(i*size, j*size);
            window.draw(sprite1);
        }
    }

    for (int i=0;i<score;i++)
        {
            if(i == 0 && dir == 2)
            {
                spritright.setPosition(s[i].x*size, s[i].y*size);
                window.draw(spritright);
            }
            else if(i == 0 && dir == 0)
            {
                spritdown.setPosition(s[i].x*size, s[i].y*size);
                window.draw(spritdown);
            }
            else if(i == 0 && dir == 1)
            {
                spritleft.setPosition(s[i].x*size, s[i].y*size);
                window.draw(spritleft);
            }
            else if(i == 0 && dir == 3)
            {
                spritup.setPosition(s[i].x*size, s[i].y*size);
                window.draw(spritup);
            }
            else
            {
                sprite3.setPosition(s[i].x*size, s[i].y*size);
                window.draw(sprite3);
            }
        }

    sprite2.setPosition(f.x*size, f.y*size);

    TocaMaca();

    window.draw(sprite2);

    window.display();
    }
}

int main()
{
   RenderWindow window(VideoMode(w,h),"SFML MENU");

   Menu text(window.getSize().x, window.getSize().y);

   TocaMaca();
   TocaComida();
   TocaLapada();

   Music music;

   if(!music.openFromFile("songs/SnakeMusic.ogg"))
        printf("ERROR MUSIC\n");
   music.play();

   while(window.isOpen())
   {
       Event event;

       while(window.pollEvent(event))
       {
           switch(event.type)
           {
            case (Event::KeyReleased):
               switch(event.key.code)
               {
                    case (Keyboard::Up):
                    text.MoveUp();
                    break;

                    case (Keyboard::Down):
                    text.MoveDown();
                    break;

                    case (Keyboard::W):
                    text.MoveUp();
                    break;

                    case (Keyboard::S):
                    text.MoveDown();
                    break;

                    case (Keyboard::Return):
                        switch(text.GetPressedItem())
                        {
                            case 0:
                                game();
                                break;

                            case 1:
                                window.close();
                                break;
                            default:
                                break;
                        }
               }
               break;
            case Event::Closed:
                window.close();
                break;
           }
       }
       window.clear();

       Texture background;
       background.loadFromFile("images/background.jpg");
       Sprite bg(background);
       window.draw(bg);

       text.draw(window);

       window.display();
   }
}

