#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

/*********************************************/
/* Configurações LEDS 1 a 3                  */
#define LED1_PIO PIOC
#define LED1_PIO_ID ID_PIOC
#define LED1_PIO_IDX 19
#define LED1_PIO_IDX_MASK (1 << LED1_PIO_IDX)

#define LED2_PIO PIOD
#define LED2_PIO_ID ID_PIOD
#define LED2_PIO_IDX 26
#define LED2_PIO_IDX_MASK (1 << LED2_PIO_IDX)

#define LED3_PIO PIOD
#define LED3_PIO_ID ID_PIOD
#define LED3_PIO_IDX 11
#define LED3_PIO_IDX_MASK (1 << LED3_PIO_IDX)
/********************************************/

/*********************************************/
/* Configurações botão 1 a 3                  */
#define BUT1_PIO PIOA
#define BUT1_PIO_ID ID_PIOA
#define BUT1_PIO_IDX 2
#define BUT1_PIO_IDX_MASK (1u << BUT1_PIO_IDX)

#define BUT2_PIO PIOD
#define BUT2_PIO_ID ID_PIOD
#define BUT2_PIO_IDX 30
#define BUT2_PIO_IDX_MASK (1u << BUT2_PIO_IDX)

#define BUT3_PIO PIOC
#define BUT3_PIO_ID ID_PIOC
#define BUT3_PIO_IDX 13
#define BUT3_PIO_IDX_MASK (1u << BUT3_PIO_IDX)
/********************************************/

/***********/
/*Prototype*/
/***********/
volatile char but1_flag;
volatile char but2_flag;
volatile char but3_flag;

void but1_callback(void);
void but2_callback(void);
void but3_callback(void);

/***********/
/*Callback*/
/***********/
volatile char but1_flag = 0;
void but1_callback(void){
	but1_flag = 1;
}

volatile char but2_flag = 1;
void but2_callback(void){
	but2_flag = 0;
}

volatile char but3_flag = 0;
void but3_callback(void){
	but3_flag = 1;
}



int main (void)
{
	board_init();
	sysclk_init();
	delay_init();

  // Init OLED
	gfx_mono_ssd1306_init();
  
  // Escreve na tela um circulo e um texto
	gfx_mono_draw_filled_circle(20, 16, 16, GFX_PIXEL_SET, GFX_WHOLE);
  gfx_mono_draw_string("mundo", 50,16, &sysfont);

  /* Insert application code here, after the board has been initialized. */
	while(1) {

	}
}
