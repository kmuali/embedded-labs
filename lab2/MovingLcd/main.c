#include<util/delay.h>
#include"lcd.h"
#include"gpio.h"


int main()
{
	LCD_init();
	LCD_displayString("Embedded Systems    Embedded Systems    ");
	LCD_displayStringRowColumn(1, 0, "     Team 3              Team 3         ");
	for(;;)
	{
			LCD_sendCommand(LCD_SHIFT_DISPLAY_RIGHT);
			_delay_ms(500);
	}
}


