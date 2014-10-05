#include "gradientColorPicker.h"
#include"colorPicker.h"

gradientColorPicker::gradientColorPicker(RGBApixel fadeColor1, 
RGBApixel fadeColor2, int radius, int centerX, int centerY) 
{	
	color1=fadeColor1;
	color2=fadeColor2;	
	Tradius=radius;
	TcenterX=centerX;
	TcenterY=centerY;
}

RGBApixel gradientColorPicker::operator()(int x, int y) 
{
	int d= (abs(TcenterX-x)) + (abs(TcenterY-y));
	
	if (d>=Tradius) return color2;
	
	else
		{
		RGBApixel temp;
				
		temp.Red=(int) (color1.Red-floor((d*color1.Red) / Tradius )
		         + floor ((d*color2.Red) / Tradius));
		         
		temp.Green=(int)(color1.Green-floor( (d*color1.Green) / Tradius )
		         + floor((d*color2.Green) / Tradius));
		         
		temp.Blue=(int) (color1.Blue-floor( (d*color1.Blue) / Tradius )
		         + floor((d*color2.Blue) / Tradius));
		         
		return temp;
		}
}
