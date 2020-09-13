#ifndef ButtonPress
#define ButtonPress

char PressButton(char ButtonNo, unsigned char PortOfPin, unsigned char PinNo);

char pressed[no_of_button];
unsigned char levelpressed[no_of_button];
unsigned char levelreleased[no_of_button];

char PressButton(char ButtonNo, unsigned char PortOfPin, unsigned char PinNo)
{
	if(bit_is_clear(PortOfPin, PinNo))
	{
		levelpressed[ButtonNo] ++;
		levelreleased[ButtonNo] = 0;
		if(levelpressed[ButtonNo] > 100)
		{
			levelpressed[ButtonNo] = 0;
			if(pressed[ButtonNo] == 0)
			{
				pressed[ButtonNo] = 1;
				return(1);
			}
		}
	}
	else
	{
		levelreleased[ButtonNo] ++;
		levelpressed[ButtonNo] = 0;
		if(levelreleased[ButtonNo] > 100)
		{
			levelreleased[ButtonNo] = 0;
			pressed[ButtonNo] = 0;
		}
	}
	return(0);
}
#endif