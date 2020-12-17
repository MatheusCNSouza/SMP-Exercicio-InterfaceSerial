#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalOut led(p1)
volatile char c = '\0'; // Inicializado com caractere nulo

void onCharReceived() {
    c = pc.getc();
}

int main(){
    pc.attach(&onCharReceived); //Consulta a seria apenas se houver dado
    int pot = 0;
    led.period_ms(1);
    while (1){
        if (c != "\0"){
            switch (c){
                case '+':
                pot += 5;
                led = pot / 100.0;
                break;

                case '-':
                pot -= 5;
                led = pot / 100.0;
                break;

                case '*':
                pot = 100;
                led = pot / 100.0;
                break;

                case '/':
                pot = 0;
                led = pot / 100.0;
                break;

                default:
                pc.printf("ERRO! caractere nao reconhecido")
            }
        }
        pc.printf("Potencia atual do led: %d" led.read());
    }
}