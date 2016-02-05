/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 02/05/16     None  		 New project creation (this project is not tracked).
 *                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Contains main function.
 *
 * This project is used to jam the SOMFY blinds reciever by bombarding it
 *  with header pulses over and over again.
 *                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <msp430.h>				


/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#define TOGGLE_DELAY 209
#define LED_DELAY 200

/******************************************************************************/
/* Global Variable                                                            */
/******************************************************************************/

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P2DIR |= 0x08;					// Set the Jammer pin to output
	P1DIR |= 0x01;					// Set Red LED to output
	P1DIR |= 0x40;					// Set Green LED to output

	P1OUT |= 0x01;					// red led on
	P1OUT &= ~0x40;					// green led off

	while(1)
	{
		volatile unsigned int i,j;	// volatile to prevent optimization

		for(i=0;i<TOGGLE_DELAY;i++)
		{
			__no_operation();
		}

		j++;
		if(j < LED_DELAY)
		{
			j++;
		}
		else
		{
			j=0;
			P1OUT ^= 0x01;					// red led toggle
			P1OUT ^= 0x40;					// green led toggle
		}
		P2OUT ^= 0x08;				// the Jammer pin toggle

	}
	
	return 0;
}
