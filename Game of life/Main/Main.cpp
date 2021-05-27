#include "Header_Includer.h"

using namespace sf;
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int** MAP;
    int** New_Map;
    int Generation = 1;

    int main_pos_x = 500, main_pos_y = 0;

    New_Map = new int* [SIZE_X];
    for (int i = 0; i < SIZE_X; i++)
        New_Map[i] = new int[SIZE_Y];

    MAP = new int* [SIZE_X];
    for (int i = 0; i < SIZE_X; i++)
        MAP[i] = new int[SIZE_Y];


    sf::RenderWindow window(sf::VideoMode(1920, 1080), " << GAME OF LIFE >> ", Style::Fullscreen);

    Image icon;
    if (!icon.loadFromFile("Resources/Icon.png"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    RectangleShape black(Vector2f(20, 20));  //Создание черного блока
    black.setFillColor(Color::Black);

    RectangleShape white(Vector2f(20, 20)); //Создание белого блока
    Texture white_texture;
    white_texture.loadFromFile("Resources/White.png");
    white.setTexture(&white_texture);
    white.setPosition(main_pos_x, main_pos_y);
    black.setPosition(main_pos_x, main_pos_y);

   

    RectangleShape button(Vector2f(150,100));
    button.setFillColor(Color::White);
    button.setOutlineColor(Color::Black);
    button.setOutlineThickness(2);//button
    button.setPosition(150,900);

    Font font;
    font.loadFromFile("Resources/font.ttf");
    Text Game_Generation("", font, 40);
    Game_Generation.setFillColor(Color::Black);        //generation_txt
    Game_Generation.setStyle(Text::Regular);
    Game_Generation.setString("Generation: ");
    Game_Generation.setPosition(40, 30);
    ostringstream GenerationScore;

    Text Text_exit1("", font, 35);
    Text_exit1.setFillColor(Color::Black);
    Text_exit1.setStyle(Text::Regular);
    Text_exit1.setString("If you want to close:\n Press ESC");
    Text_exit1.setPosition(40, 100);

    Text Text_exit2("", font, 40);
    Text_exit2.setFillColor(Color::Black);
    Text_exit2.setStyle(Text::Regular);
    Text_exit2.setString("Exit");
    Text_exit2.setPosition(180, 920);


    bool Init_Map = true;

    InitMap(MAP);


    while (window.isOpen())
    {
        window.clear(Color::White); // Очистка экрана

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }


        int posx = main_pos_x, posy = main_pos_y; //Начальные позиции сетки



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)    //  Закрие програмы крестиком
                window.close();

            if (IntRect(150, 900, 150, 100).contains(Mouse::getPosition(window))) {
                
                button.setFillColor(Color(80,80,80 ));
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    window.close();
                }
            }else  button.setFillColor(Color::White);
        }

        //Вывод Инициализированого мира 
        if (Init_Map)
        {

            GenerationScore << Generation;
            Game_Generation.setString("Generation: " + GenerationScore.str());

            for (int i = 0; i < SIZE_X; i++) {
                for (int j = 0; j < SIZE_Y; j++) {
                    if (MAP[i][j] == 0) {
                        window.draw(white);
                        posx += 20;
                        white.setPosition(posx, posy);
                        black.setPosition(posx, posy);
                    }
                    else if (MAP[i][j] == 1) {
                        window.draw(black);
                        posx += 20;
                        black.setPosition(posx, posy);
                        white.setPosition(posx, posy);
                    }
                }
                posx = main_pos_x;
                posy += 20;
                black.setPosition(posx, posy);
                white.setPosition(posx, posy);
            }

            window.draw(button);
            window.draw(Text_exit2);
            window.draw(Game_Generation);
            window.draw(Text_exit1);
            window.display();
            Sleep(2000);
            window.clear(Color::White);
            Init_Map = false;
        }

        CheckRules(MAP, New_Map);

        white.setPosition(main_pos_x, main_pos_y);
        black.setPosition(main_pos_x, main_pos_y);
        posx = main_pos_x; posy = main_pos_y;
        Generation++;

        GenerationScore.str("");
        GenerationScore << Generation;
        Game_Generation.setString("Generation: " + GenerationScore.str());

        for (int i = 0; i < SIZE_X; i++)
        {
            for (int j = 0; j < SIZE_Y; j++) {
                if (MAP[i][j] == 0) {
                    window.draw(white);
                    posx += 20;
                    white.setPosition(posx, posy);
                    black.setPosition(posx, posy);
                }
                else if (MAP[i][j] == 1) {
                    window.draw(black);
                    posx += 20;
                    black.setPosition(posx, posy);
                    white.setPosition(posx, posy);
                }
            }
            posx = main_pos_x;
            posy += 20;
            black.setPosition(posx, posy);
            white.setPosition(posx, posy);
        }
        
        window.draw(button);
        window.draw(Text_exit2);
        window.draw(Game_Generation);
        window.draw(Text_exit1);

        window.display();   // Вывод на экран
        Sleep(100);
    }

    for (int i = 0; i < SIZE_X; i++) {
        delete[] New_Map[i];
        delete[] MAP[i];
    }

    delete[] New_Map;
    delete[] MAP;


    exit(0);
}