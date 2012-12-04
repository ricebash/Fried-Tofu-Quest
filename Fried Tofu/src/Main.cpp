#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
//using namespace std;

float y = 400;
float x = 100;
float width = 30;
float height = 50;
float grav = 0.1;
float jumpow = 0;
float limit = 0;

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
	if(y + height - jumpow < 500 && limit == 0)
	{
		jumpow = jumpow - 5;
	}
	else
	{
		limit = 1;
	}
}

void Main::keyDown(KeyEvent event)
{
	if(event.getChar() == 'w')
	{
		if(jumpow < 40 && limit == 1)
		{
			jumpow = jumpow + 5;
		}
		if(jumpow >=40)
		{
			limit = 0;
		}
	}
	if(event.getCode() == KeyEvent::KEY_RIGHT)
	{
		x = x + 5;
	}
}

void Main::keyUp(KeyEvent event)
{
	if(event.getChar() == 'w')
	{
		limit = 0;
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
	Rectf rec(x,y -jumpow,x+ width, y + height -jumpow);
	gl::drawSolidRect(rec);
	//gl::clear( Color( wtf, wtf*0.5, wtf+0.1 ) );
}

void Main::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


CINDER_APP_BASIC( Main, RendererGl )
