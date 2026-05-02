#define F_CPU 16000000UL

#define REG(addr)  (*(volatile unsigned char *)(addr))

#define DDRB   REG(0x24)
#define PORTB  REG(0x25)
#define PB5    5

static void delay_ms(unsigned int ms) {
    while (ms--) {
        unsigned int i = 4000;
        while (i--) {
            __asm__ volatile ("nop");
        }
    }
}

int main(void) {
    DDRB |= (1 << PB5);
    while (1) {
        PORTB |=  (1 << PB5);
        delay_ms(1000);
        PORTB &= ~(1 << PB5);
        delay_ms(1000);
    }
}
