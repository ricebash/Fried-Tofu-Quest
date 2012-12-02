#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
//using namespace std;
	 

class Main : public AppBasic {
  public:
	void prepareSettings(Settings *setting);
	void setup();
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
}

void Main::draw()
{
	float wtf = sin(getElapsedSeconds()) *0.3 + 0.6;
	// clear out the window with black
	float y = sin(getElapsedSeconds())*100 + getWindowHeight()/2;
	float x = cos(getElapsedSeconds())*100 + getWindowWidth()/2;
	 
	//gl::draw(imeyj,getWindowBounds());
	gl::clear(Color(0,0,0));
	gl::color(1,1,1);
	gl::drawSolidCircle(Vec2f(x,y),50,6);
	
	//gl::clear( Color( wtf, wtf*0.5, wtf+0.1 ) );
}

void Main::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


CINDER_APP_BASIC( Main, RendererGl )
