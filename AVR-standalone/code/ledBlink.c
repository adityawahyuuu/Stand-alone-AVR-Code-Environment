#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#define F_CPU   16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB5);

    while(1)
    {
        PORTB |= (1 << PB5);
        _delay_ms(500);
        PORTB &= ~(1 << PB5);
        _delay_ms(500);
    }

    return 0;
}