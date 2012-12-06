#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
//using namespace std;

float y = 450;
float x = 100;
float squishx = 0;
float squishy = 0;
float width = 30;
float height = 50;
float grav = -9.8*50;
float jumpow = 0;
int isJumping = 0;
float elapsed = 0;
const float u = 30;
float curr = 0;
float vel = 0;
int isGoingRight = 0;
int isGoingLeft = 0;
int isGrounded = 1;
int Squish = 0;

class Main : public AppBasic {
  public:
	void prepareSettings(Settings *setting);
	void setup();
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	gl::Texture imeyj;

};

void Main::setup()
{
		imeyj = gl::Texture(loadImage(loadAsset("4 Spirits.jpg")));
		
}

void Main::mouseDown( MouseEvent event )
{
}

void Main::update()
{
	//x = x + 0.1;
	elapsed = getElapsedSeconds() - curr;
	if(isJumping && !isGrounded)
	{
		jumpow = jumpow + 80 +(grav*elapsed);
	}
	if(jumpow >=100)
	{
		isJumping = 0;
	}
	if(y + height - jumpow < 500)
	{
		jumpow = jumpow + (grav*elapsed);
	}
	else
	{
		jumpow = 0;
		isGrounded = 1;
	}
	if(isGoingRight)
	{
		x = x+ 5;
	}
	if(isGoingLeft)
	{
		x = x- 5;
	}
	if(Squish)
	{
		
		if(squishy+2.5 < height)
		{
			squishx = squishx + 2.5;
			squishy = squishy + 2.5;
		}
	}
	if(!Squish)
	{
		if(squishx >=5)
		{
			squishx =squishx-5;
		}
		else
		{
			squishx = 0;
		}
		if(squishy >=5)
		{
			squishy = squishy -5;
		}
		else
		{
			squishy = 0;
		}
	}
	curr = getElapsedSeconds();
}

void Main::keyDown(KeyEvent event)
{
	if(event.getCode() == KeyEvent::KEY_SPACE)
	{
		if(isGrounded)
		{
			isJumping = 1;
			isGrounded = 0;
		}
	}
	if(event.getCode() == KeyEvent::KEY_RIGHT)
	{
		isGoingRight = 1;
	}
	if(event.getCode() == KeyEvent::KEY_DOWN)
	{
		Squish = 1;
	}
	if(event.getCode() == KeyEvent::KEY_LEFT)
	{
		isGoingLeft = 1;
	}
}

void Main::keyUp(KeyEvent event)
{
	if(event.getCode() == KeyEvent::KEY_SPACE)
	{
		isJumping = 0;
	}
	if(event.getCode() == KeyEvent::KEY_RIGHT)
	{
		isGoingRight = 0;
	}
	if(event.getCode() == KeyEvent::KEY_LEFT)
	{
		isGoingLeft = 0;
	}
	if(event.getCode() == KeyEvent::KEY_DOWN)
	{
		Squish = 0;
	}
}

void Main::draw()
{
	//float wtf = sin(getElapsedSeconds()) *0.3 + 0.6;
	// clear out the window with black
	//float y = sin(getElapsedSeconds())*100 + getWindowHeight()/2;
	//float x = cos(getElapsedSeconds())*100 + getWindowWidth()/2;
	 
	//gl::draw(imeyj,getWindowBounds());
	gl::clear(Color(0,0,0));
	gl::color(0,1,0);
		Rectf ground(0,500,getWindowWidth(),getWindowHeight());
		gl::drawSolidRect(ground);
	gl::color(1,1,1);
	//gl::drawSolidCircle(Vec2f(x,y),50,6);
	Rectf rec(x-squishx,y -jumpow + squishy,x+ width + squishx, y + height -jumpow);
	gl::drawSolidRect(rec);
	//gl::clear( Color( wtf, wtf*0.5, wtf+0.1 ) );
}

void Main::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


CINDER_APP_BASIC( Main, RendererGl )
