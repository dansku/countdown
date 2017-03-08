/*

	Days Countdown
	Daniel Andrade _ www.danielandrade.net
	2017

	Code To Display Countdown to a specific date

*/

#include <math.h>

// Date of the countdown in seconds from https://www.epochconverter.com/
const uint32_t final_date = 1517486400; 


// Number Pins Setup (a,b,c,d,e,f,g)
const uint8_t zero[7] 	= {1,1,1,1,1,1,0};
const uint8_t one[7] 	= {0,1,1,0,0,0,0};
const uint8_t two[7] 	= {1,1,0,1,1,0,1};
const uint8_t three[7] 	= {1,1,1,1,0,0,1};
const uint8_t four[7] 	= {0,1,1,0,0,1,1};
const uint8_t five[7] 	= {1,0,1,1,0,1,1};
const uint8_t six[7] 	= {1,0,1,1,1,1,1};
const uint8_t seven[7] 	= {1,1,1,0,0,0,0};
const uint8_t eihgt[7] 	= {1,1,1,1,1,1,1};
const uint8_t nine[7] 	= {1,1,1,0,0,1,1};

void setup()
{
	Serial.begin(9600);
}

void loop()
{

	// DateTime now 		= RTC.now(); 								//get the current date-time
	// current_epoch_time 	= (now.get()); 								//seconds
	uint32_t current_epoch_time = 1488997525;
	uint32_t difference = final_date - current_epoch_time;

	uint32_t days 		= floor(difference / 86400);
	uint32_t hours 		= floor((difference - (days * 86400))/(3600));
	uint32_t minutes 	= floor((difference - (days * 86400) - (hours * 3600))/60);
	uint32_t seconds 	= floor(difference - (days * 86400) - (hours * 3600) - (minutes * 60));

	Serial.print(days);
	Serial.print(" ");
	Serial.print(hours);
	Serial.print(" ");
	Serial.print(minutes);
	Serial.print(" ");
	Serial.println(seconds);


}

