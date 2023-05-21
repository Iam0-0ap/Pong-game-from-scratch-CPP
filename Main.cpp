#include<iostream>
#include <sstream>
#include "Menuu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

int page_number;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"sfml game2");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	//States
	bool up=false;
	bool down=false;


	//Variables
	int yVelocityPad1 =0;
	int xVelocityBall=7;
	int yVelocityBall=7;
	int yVelocityPad2 =2;
	int pad1score=0;
	int pad2score=0;

	Menuu menu(600,600);

	//Images
	sf::Texture tex_background;
	if ( tex_background.loadFromFile("Data/background1.png")==false)
	{
		return -1;
	}
	sf::Texture tex_logo;
	if ( tex_logo.loadFromFile("Data/logo.png")==false)
	{
		return -1;
	}
	sf::Texture tex_pong;
	if ( tex_pong.loadFromFile("Data/pong1.png")==false)
	{
		return -1;
	}

	

				//MAIN MENU MUSIC
	sf::Music theme;
	if (theme.openFromFile("Data/dx.ogg")== 0)
	{
		return 1;
	}
	theme.play();
	
	
	
			//FONT
				sf::Font font1;
				if (font1.loadFromFile("Data/itallic.ttf")==0)
				{
				return 1;
				}
				sf::Text bio;
				bio.setFont(font1);
				bio.setCharacterSize(30);
				bio.setColor(sf::Color::Yellow);
				bio.setPosition(650,550);
				bio.setString("Productions");

				
				
	//background
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(800,600));
	background.setPosition(0,0);
	background.setTexture(&tex_background);

	//Load My logo
	sf::RectangleShape logo;
	logo.setSize(sf::Vector2f(70,70));
	logo.setPosition(595,520);
	logo.setTexture(&tex_logo);

	sf::RectangleShape pong;
	pong.setSize(sf::Vector2f(300,150));
	pong.setPosition(216,-8);
	pong.setFillColor(sf::Color::Blue);
	pong.setTexture(&tex_pong);

	

	bool play=true;

			//Images	
	sf::Texture tex_pad;
	sf::Texture tex_ball;
	sf::Texture tex_backg;
	sf::Texture tex_ap;

	if (tex_pad.loadFromFile("Data/pad.png")==false)
	{
		return -1;
	}

	if (tex_ball.loadFromFile("Data/ball.png")==false)
	{
		return -1;
	}
	if (tex_backg.loadFromFile("Data/foreground.png")==false)
	{
		return -1;
	}
	if (tex_ap.loadFromFile("Data/ap.png")==false)
	{
		return -1;
	}
	//Sounds	
	sf::SoundBuffer buff_hit;
	

	//load the sound
	if (buff_hit.loadFromFile("Data/hit.wav")==0)
	{
	return -1;
	}
	sf::Sound hit;
	hit.setBuffer(buff_hit);
	hit.setVolume(40);


				
	
	


	////////Shapes
	//Background
	sf::RectangleShape backg;
	backg.setSize(sf::Vector2f(800,600));
	backg.setPosition(0,0);
	backg.setTexture(&tex_backg);

	
	//Pad1
	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(20,150));
	pad1.setPosition(50,200);
	pad1.setTexture(&tex_pad);

	//Pad2
	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(20,150));
	pad2.setPosition(700,200);
	pad2.setTexture(&tex_pad);

	//Ball
	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(40,50));
	ball.setPosition(400,200);
	ball.setTexture(&tex_ball);

	//ap(logo)
	sf::RectangleShape ap;
	ap.setSize(sf::Vector2f(70,70));
	ap.setPosition (700,0);
	ap.setTexture(&tex_ap);

	//Font
				sf::Font font;
				if (font.loadFromFile("Data/ariel.ttf")==0)
				{
				return 1;
				}
	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setColor(sf::Color::Red);
	score.setPosition(368,10);
	score.setString("0 : 0");



	//game loop
	while (window.isOpen())
	{
			sf::Event event;
		//Events
		while(window.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
				window.close();
			if (event.type==sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{	menu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{	menu.moveDown();
					break;
				}

			//Choose Page
				if (event.key.code==sf::Keyboard::Return)
				{
					theme.stop();
					if (menu.mainMenuPressed() ==0)
					{
						window.close();
						page_number=0;
					
					}
					if (menu.mainMenuPressed()== 1)
					{
						window.close();
						page_number=1;
					
					}	
				}
			}	
		}

		//rendering
		window.clear();
		window.draw(background);
		window.draw(bio);
		window.draw(logo);
		window.draw(pong);
		menu.draw(window);
		window.display();
	}
			////////////////////////////////////////////////////(((THE MAIN WINDOW FOR GAME))//////////////////////////////////////////////////////

			
			//play
			sf::RenderWindow window_play(sf::VideoMode(800,600),"play");
			window_play.setFramerateLimit(60);
			window_play.setKeyRepeatEnabled(false);
			sf::Event event;
			
			//GAME SCREEN MUSIC
	sf::Music playback;
	if (playback.openFromFile("Data/mma.ogg")== 0)
	{
		return 1;
	}
	playback.play();
	playback.setVolume(70);

	if (page_number == 0)
		{
			while (play == true)
			{
				
				while (window_play.pollEvent(event))
				{
					if (event.type==sf::Event::Closed)
						play=false;
					///key pressed
			if (event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Up)
			{
				up=true;
			}
			if (event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Down)
			{
				down=true;
			}
			///key released
			if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Up)
			{
				up=false;
			}
			if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Down)
			{
				down=false;
			}

				}

				////////////////LOGIC
		//pad1
		if (up == true)
		{
			yVelocityPad1=-10;
		}
		if (down ==true)
		{
			yVelocityPad1=10;
		}
		if (up==true && down==true)
		{
			yVelocityPad1=0;
		}
		if (up==false && down==false)
		{
			yVelocityPad1=0;
		}

		///move
		pad1.move(0,yVelocityPad1);
		
		//Out of bound check
		if (pad1.getPosition().y <0)
		{
			pad1.setPosition(50,0);
		}
		if (pad1.getPosition().y >450)
		{
			pad1.setPosition(50,450);
		}
		///Pad2
		if (ball.getPosition().y < pad2.getPosition().y)
		{
			yVelocityPad2= -4;
		}
		if (ball.getPosition().y > pad2.getPosition().y)
		{
			yVelocityPad2= 4;
		}
		pad2.move(0,yVelocityPad2);
		

		///Ball
		ball.move(xVelocityBall, yVelocityBall);
		//Out of bound check
		if (ball.getPosition().y <0)
		{
			yVelocityBall=-yVelocityBall;			
		}
		if (ball.getPosition().y >550)
		{
			yVelocityBall=-yVelocityBall;
		}
		if (ball.getPosition().x <-50)
		{

			pad2score++;
			ball.setPosition(300,200);
		}
		if (ball.getPosition().x > 800)
		{
			pad1score++;
			ball.setPosition(300,200);
		}
		//collison for pad1
		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds()) == true)
		{
			xVelocityBall = -xVelocityBall;
			hit.play();
		}

		//collison for pad2
		if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
		{
			xVelocityBall = -xVelocityBall;
			hit.play();
		}

			
		//RENDERING
		window_play.clear();
		//drawing shapes
		window_play.draw(backg);
		window_play.draw(pad1);
		window_play.draw(pad2);
		window_play.draw(ball);
		window_play.draw(ap);

		
		window_play.draw(score);
		std::stringstream text;
		text << pad1score <<" : " << pad2score;
		score.setString(text.str());
		window_play.display();
			}

		}
		if (page_number == 1)
		{
			window.close();
			}
		window.close();
	return 0;
}