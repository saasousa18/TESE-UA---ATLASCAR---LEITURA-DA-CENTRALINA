/**
 *       @file  pcolor.c
 *      @brief  File to set printf() colors
 *
 * Not much on detailed description about pcolor
 *
 *     @author  Vitor Santos, vitor@ua.pt
 *
 * =====================================================================
 */

#include <stdio.h>
#include "pcolor.h"


/**
 * @brief  Set the color of text that follows upon the next printf.
 *
 * @param  attr Type of attribute (RESET, BRIGHT, BLINK, etc...)
 * @param  fg Color of foreground
 * @param  bg Color of background
 * @return Nothing
 */
void textcolor(int attr, int fg, int bg)
{
	printf("%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
}

/**
 * @brief  printf of an horizontal separator red line 
 *
 * @return Nothing
 */
void PrintRedLine(void)
{
	textcolor(RESET, RED, WHITE);	
	printf("======================================== \n",textcolor);
}

/**
 * @brief  Reset color text to usual defaults (Black letter on white back)
 *
 * @return Nothing
 */
void ResetTextColors(void)
{
	textcolor(RESET, WHITE, WHITE); 
}

/**
 * @brief  Make some sort of highlight text (e.g. yellow text on blue back)
 *
 * @return Nothing
 */
void HighLightText(void)
{
	textcolor(RESET, YELLOW, WHITE);
}



