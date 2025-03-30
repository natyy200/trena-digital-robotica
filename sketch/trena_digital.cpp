// Inclusão das bibliotecas.
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Ultrasonic.h>
/* Cria o objeto de controle para o display OLED. */
Adafruit_SSD1306 display(128, 64);
/* Define os pinos do sensor ultrassônico.         */
#define pino_trig A1
#define pino_echo A0
/* Cria o objeto de controle para o ultrassônico. */
Ultrasonic ultrasonic(pino_trig, pino_echo);
/* Cria a variável que armazenará a medida. */
float medida;
/* Configurações.                                   */
void setup(void) {
/* Inicia o display OLED, através de seu */
/* endereço físico 0X3C. */
display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
}/* Fim das configurações.                          */
/* Looping infinito.                                */
void loop(void) {
/* Faz a leitura da distância e armazena na */
/* variável medida. */
medida = ultrasonic.read();
/* Limpa o display ao iniciar. */
display.clearDisplay();
/* Posiciona o cursor na coordenada informada. */
display.setCursor(8, 0);
/* Define o tamanho da fonte: 1.                  */
display.setTextSize(1);
/* Define a cor da fonte: Claro (1) - Escuro (0). */
display.setTextColor(1);
/* Imprime a palavra -- TRENA DIGITAL --. */
display.print("-- TRENA DIGITAL --");
/* Desenha um retângulo sem preenchimento, com */
/* origem na coordenada (0, 12), com dimensões */
/* 128x40 pixels, raios dos cantos arredondados */
/* 10 pixels na cor clara. */
display.drawRoundRect(0, 12, 128, 40, 10, WHITE);
/* Posiciona o cursor na coordenada informada. */
display.setCursor(20, 55);
/* Imprime a palavra Rob. */
display.print("Rob");
/* Imprime a letra ó. */
display.write(162);
/* Imprime a palavra tica. */
display.print("tica Paran");
/* Imprime a letra á. */
display.write(160);
/* Define o tamanho da fonte: 2.                 */
display.setTextSize(2);
/* Se a medida for menor que 10, faça... */
if (medida < 10) {
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(25, 25);
 /* Imprime a medida. */
 display.print(medida);
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(85, 25);
 /* Imprime a unidade de medida. */
 display.print("cm");
}
/* Se a medida for maior ou igual a 10 e menor */
/* que 100, faça... */
if (medida >= 10 && medida < 100) {
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(13, 25);
 /* Imprime a medida. */
 display.print(medida);
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(85, 25);
/* Imprime a unidade de medida. */
 display.print("cm");
}
/* Se a medida for maior ou igual a 100, faça... */
if (medida >= 100) {
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(25, 25);
 /* Imprime a medida. */
 display.print(medida / 100);
 /* Posiciona o cursor na coordenada informada. */
 display.setCursor(85, 25);
 /* Imprime a unidade de medida. */
 display.print("m");
}
/* Atualiza as informações do display. */
display.display();
/* Pequeno atraso para a leitura da medida. */
delay(100);
}/* Fim do looping infinito.                        */