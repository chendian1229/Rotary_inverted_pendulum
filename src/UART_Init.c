#include <msp430G2553.h>

void UART_Init()
{
	  P1SEL = BIT1 + BIT2 ;                     // P1.1 = RXD, P1.2=TXD
	  P1SEL2 = BIT1 + BIT2 ;                    // P1.1 = RXD, P1.2=TXD
	  UCA0CTL1 |= UCSSEL_2;                     // SMCLK,1MHz
	  UCA0BR0 = 104;                            // 1MHz 9600
	  UCA0BR1 = 0;                              // 1MHz 9600
	  UCA0MCTL = UCBRS0;                        // Modulation UCBRSx = 1
	  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	  IE2 |= UCA0RXIE;                          // Enable USCI_A0 RX interrupt
}
