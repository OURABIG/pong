#include "main.hpp"








//pos raquettes
float posRaquettesLeftX = 50;
float posRaquettesRightX = WIN_WIDTH - 70;
float posRaquettesLeftY = WIN_HEIGHT / 2;
float posRaquettesRightY = posRaquettesLeftY;
float raquettesSpeed = 0.35f;
int raquettesHeight = 150;
int raquettesWidth = 20;
//ball
float ballSpeed = 1.f;
Vector2f ballDir = Vector2f(1.5f, 2.0f);
float ballPosX = WIN_WIDTH / 2;
float ballPosY = WIN_HEIGHT / 2;
//score
int score1 = 0;
int score2 = 0;



int main()
{
    Input input;
    RenderWindow window;
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "PONG GAME", Style::Default);
    //load font called
    Text txt;
    Font font;
    font.loadFromFile("res/font.ttf"); 
    txt.setFont(font);
    SetText(txt, to_string(score1) + "|" + to_string(score2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    //pong sound 
    Sound sound;
    SoundBuffer buffer;
    buffer.loadFromFile("res/pong.wav");
    sound.setBuffer(buffer);
    //music
    Music music;
    if(!music.openFromFile("res/music.ogg"))
    {
        cout << "music not working";
    }
    music.play();
    
    music.setVolume(25);

    //ball
    CircleShape circleball(7);
    circleball.setPosition(ballPosX, ballPosY);
    //raquette left
    RectangleShape leftraquet(Vector2f(raquettesWidth, raquettesHeight));
    leftraquet.setPosition(posRaquettesLeftX, posRaquettesLeftY);
    //raquette right
     RectangleShape Rightraquet(Vector2f(raquettesWidth, raquettesHeight));
    Rightraquet.setPosition(posRaquettesRightX, posRaquettesRightY);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckBtn();
        Airaquet();
        music.setLoop(true);
        leftraquet.setPosition(posRaquettesLeftX, posRaquettesLeftY);
        Rightraquet.setPosition(posRaquettesRightX, posRaquettesRightY);
        
        UpdateBall();

        circleball.setPosition(ballPosX, ballPosY);

        window.clear(Color{ 255, 174, 66});
        window.draw(txt);
        window.draw(circleball);
        window.draw(leftraquet);
        window.draw(Rightraquet);
        window.display();

    }
    
    return 0;
}

void SetText(Text& txt, String str)
{
    txt.setString(str);
    txt.setCharacterSize(50);
    txt.setFillColor(Color::Red);
    txt.setPosition((WIN_WIDTH / 2) - 40, 10);
}

void CheckBtn()
{
    Input input;
    //left
    if(input.GetButton().up == true)
    {
        posRaquettesLeftY -= raquettesSpeed;
        if(posRaquettesLeftY < 0)
            posRaquettesLeftY = 0;
    }
    if(input.GetButton().down == true)
    {
        posRaquettesLeftY += raquettesSpeed;
        if(posRaquettesLeftY + raquettesHeight > WIN_HEIGHT)
            posRaquettesLeftY = WIN_HEIGHT - raquettesHeight;
    }
    //Right
    if(input.GetButton().up2 == true)
    {
        posRaquettesRightY -= raquettesSpeed;
        if(posRaquettesRightY < 0)
            posRaquettesRightY = 0;
    }
    if(input.GetButton().down2 == true)
    {
        posRaquettesRightY += raquettesSpeed;
        if(posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
            posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
    }
}

void UpdateBall()
{
    Text txt;
    Sound sound;

    ballPosX += ballDir.x * ballSpeed;
    ballPosY += ballDir.y * ballSpeed;

    //ball collision
    //right or left raquet
    if ((ballPosX < posRaquettesLeftX + raquettesWidth && ballPosX > posRaquettesLeftX
    && ballPosY + 5 < posRaquettesLeftY + raquettesHeight && ballPosY + 5 > posRaquettesLeftY)
    ||
    (ballPosX > posRaquettesRightX - raquettesWidth && ballPosX < posRaquettesRightX
    && ballPosY + 5 < posRaquettesRightY + raquettesHeight && ballPosY + 5 > posRaquettesRightY))
    {
        ballDir.x *= -1;
        sound.play();
    }
    
    //left wall
    if(ballPosX < 0)
    {
        score2++;
        ballPosX = WIN_WIDTH/ 2;
        ballPosY = WIN_HEIGHT / 2;
        ballDir.x = fabs(ballDir.x);
        ballDir.y *= -1;
         SetText(txt, to_string(score1) + "|" + to_string(score2)); 
    }
    //right wall
    if(ballPosX > WIN_WIDTH)
    {
        score1++;
        ballPosX = WIN_WIDTH/ 2;
        ballPosY = WIN_HEIGHT / 2;
        ballDir.x = -fabs(ballDir.x);
        ballDir.y *= -1;
         SetText(txt, to_string(score1) + "|" + to_string(score2)); 
    }

    if(ballPosY > WIN_HEIGHT || ballPosY < 0)
    {
        ballDir.y *= -1;
        sound.play();
    }

}

void Airaquet()
{
    posRaquettesRightY = ballPosY;
    if(posRaquettesRightY < 0)
        posRaquettesRightY = 0;

    if(posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
        posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
}
