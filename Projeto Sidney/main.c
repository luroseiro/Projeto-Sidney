#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "objetos.h"
#include "mappy_A5.h"

const int WIDTH = 720;
const int HEIGHT = 560;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
bool keys[5] = {false, false, false, false, false};

void iniciaAviao(AVIOES *aviao) {
	aviao->x = WIDTH / 2;
	aviao->y = HEIGHT / 2;
	aviao->velocidade = 1.85;
	aviao->combustivel = 100;
	aviao->placar = 0;
}
void desenhaAviao(AVIOES aviao) {                      //desenha nave
	al_draw_filled_rectangle(aviao.x, aviao.y - 9, aviao.x + 10, aviao.y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(aviao.x, aviao.y + 9, aviao.x + 10, aviao.y + 7, al_map_rgb(255, 0, 0));

	al_draw_filled_triangle(aviao.x - 12, aviao.y - 17, aviao.x + 12, aviao.y, aviao.x - 12, aviao.y + 17, al_map_rgb(0, 255, 0));
	al_draw_filled_rectangle(aviao.x - 12, aviao.y - 2, aviao.x + 15, aviao.y + 2, al_map_rgb(0, 0, 255));
}
void mAviaoCima(AVIOES *aviao, int tela_y) {                      //movimenta nave pra cima
	aviao->y -= aviao->velocidade;
	if (aviao->y < 199) {
		if (tela_y == 0) {
			aviao->y -= aviao->velocidade;
		}
		else {
			aviao->y = 199;
		}
	}
}
void mAviaoBaixo(AVIOES *aviao, int tela_y) {                      //movimenta nave pra baixo
	aviao->y += aviao->velocidade;
	if (aviao->y > HEIGHT - 199) {
		if (tela_y == mapheight * mapblockheight - HEIGHT) {
			aviao->y += aviao->velocidade;
		}
		else {
			aviao->y = HEIGHT - 199;
		}
	}
}
void mAviaoEsq(AVIOES *aviao, int tela_x) {                      //movimenta nave pra esquerda
	aviao->x -= aviao->velocidade;
	if (aviao->x < 199) {
		if (tela_x == 0) {
			aviao->x -= aviao->velocidade;
		}
		else {
			aviao->x = 199;
		}
	}
}
void mAviaoDir(AVIOES *aviao, int tela_x) {                      //movimenta nave pra direita
	aviao->x += aviao->velocidade;
	if (aviao->x > WIDTH - 199) {
		if (tela_x == mapwidth * mapblockwidth - WIDTH) {
			aviao->x += aviao->velocidade;
		}
		else {
			aviao->x = WIDTH - 199;
		}
	}
}
int sorteiaDestino(void) {
	int dificuldadade = 1 + (rand() % 3), destino;
	
	if (dificuldadade == 1)
		destino = rand() % 60;
	else if (dificuldadade == 2)
		destino = 60 + (rand() % 57);
	else if (dificuldadade == 3)
		destino = 117 + (rand() % 48);

	return destino;
}

int main(void) {

	bool done = false, redraw = false, gameOver = false;
	const int FPS = 60;
	int xOff = 0, yOff = 0, destinos;

	AVIOES aviao;
	destinos = sorteiaDestino();
	iniciaDestinos(destinos);

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *fonte = NULL;

	if (!al_init()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar Allegro!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	janela = al_create_display(WIDTH, HEIGHT);
	if (!janela) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar janela!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//addons
	if (!al_install_keyboard()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao instalar teclado!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_install_mouse()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao instalar mouse!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_primitives_addon()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar primitivos!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar addon de imagem!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_font_addon()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar addon de fonte!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_ttf_addon()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar addon de ttf!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (MapLoad("mapa.FMP", 1)) {                        //testa mapa
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar mapa!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}

	fila_de_eventos = al_create_event_queue();
	if (!fila_de_eventos) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar fila de eventos!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar timer!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	srand(time(NULL));
	iniciaAviao(&aviao);

	fonte = al_load_font("fonte.ttf", 27, 0);
	if (!fonte) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar fonte!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//Registrando na fila de eventos
	al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_de_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_de_eventos, al_get_timer_event_source(timer));
	al_register_event_source(fila_de_eventos, al_get_display_event_source(janela));

	al_start_timer(timer);

	//Loop principal
	while (!done) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_de_eventos, &evento);

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		else if (evento.type == ALLEGRO_EVENT_TIMER) {
			if (keys[UP]) {
				mAviaoCima(&aviao, yOff);
			}
			if (keys[DOWN]) {
				mAviaoBaixo(&aviao, yOff);
			}
			if (keys[LEFT]) {
				mAviaoEsq(&aviao, xOff);
			}
			if (keys[RIGHT]) {
				mAviaoDir(&aviao, xOff);
			}
		
			if (aviao.x > WIDTH - 200) {                       // arrumar
				xOff += keys[RIGHT] * 1.75;
			}
			if (aviao.x < 200) {
				xOff -= keys[LEFT] * 1.75;
			}
			if (aviao.y > HEIGHT - 200) {
				yOff += keys[DOWN] * 1.75;
			}
			if (aviao.y < 200) {
				yOff -= keys[UP] * 1.75;
			}

			if (xOff < 0) {
				xOff = 0;
			}
			if (yOff < 0) {
				yOff = 0;
			}
			if (xOff > (mapwidth * mapblockwidth - WIDTH)) {
				xOff = mapwidth * mapblockwidth - WIDTH;
			}
			if (yOff > (mapheight * mapblockheight - HEIGHT)) {
				yOff = mapheight * mapblockheight - HEIGHT;
			}

			redraw = true;
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			if (evento.keyboard.keycode) {
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				}
			}
		}

		if (redraw && al_is_event_queue_empty(fila_de_eventos)) {
			redraw = false;

			if (!gameOver) {
				MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);
				desenhaAviao(aviao);
				al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, 
					ALLEGRO_ALIGN_CENTRE, "%c", );
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	MapFreeMem();
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}