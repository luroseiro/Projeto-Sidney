#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "objetos.h"
#include <stdio.h>
#include <math.h>

const int WIDTH = 839;
const int HEIGHT = 685;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ESC, P};
enum ESTADOS{MENUG, MENUC, JOGO, PAUSE, CONFIGURACOES};
//enum CONTINENTES{AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};
bool keys[7] = {false, false, false, false, false, false, false};

void iniciaAviao(AVIOES *aviao) {
	aviao->x = WIDTH / 2;
	aviao->y = HEIGHT / 2;
	aviao->velocidade = 2;
	aviao->combustivel = 100.0;
}
void desenhaAviao(AVIOES aviao) {                      //desenha nave
	al_draw_filled_rectangle(aviao.x, aviao.y - 9, aviao.x + 10, aviao.y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(aviao.x, aviao.y + 9, aviao.x + 10, aviao.y + 7, al_map_rgb(255, 0, 0));

	al_draw_filled_triangle(aviao.x - 12, aviao.y - 17, aviao.x + 12, aviao.y, aviao.x - 12, aviao.y + 17, al_map_rgb(0, 255, 0));
	al_draw_filled_rectangle(aviao.x - 12, aviao.y - 2, aviao.x + 15, aviao.y + 2, al_map_rgb(0, 0, 255));
}
void mAviaoCima(AVIOES *aviao) {                      //movimenta nave pra cima
	aviao->y -= aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->y < 0) {
		aviao->y = 0;
	}
}
void mAviaoBaixo(AVIOES *aviao) {                      //movimenta nave pra baixo
	aviao->y += aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->y > HEIGHT) {
		aviao->y = HEIGHT;
	}
}
void mAviaoEsq(AVIOES *aviao) {                      //movimenta nave pra esquerda
	aviao->x -= aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->x < 0) {
		aviao->x = 0;
	}
}
void mAviaoDir(AVIOES *aviao) {                      //movimenta nave pra direita
	aviao->x += aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->x > WIDTH) {
		aviao->x = WIDTH;
	}
}
int sorteiaDestino(int continente) {
	int destino = -1;
	
	if (continente == AMERICACN)
		destino = 1 + (rand() % 15);
	else if (continente == AMERICAS)
		destino = 1 + (rand() % 13);
	else if (continente == AFRICA)
		destino = 1 + (rand() % 53);
	else if (continente == EUROPA)
		destino = 1 + (rand() % 53);
	else if (continente == ASIA)
		destino = 1 + (rand() % 35);
	else if (continente == OCEANIA)
		destino = 1 + (rand() % 5);

	return destino;
}
DESTINOS *iniciaPais(DESTINOS *pais, int destino, int continente);              //objetos.h

double calculaDistancia(AVIOES aviao, DESTINOS *pais) {
	double distancia, pontos = 100.0;

	distancia = sqrt(pow((pais->localizacao_x - aviao.x), 2) + pow((pais->localizacao_y - aviao.y), 2));
	
	while (distancia > 0.0 && pontos >= 0.0) {
		pontos -= 0.5;
		distancia -= 0.5;
	}

	return pontos;
}
void restauraCombustivel(AVIOES *aviao, double pontos) {
	aviao->combustivel += pontos;
	if (aviao->combustivel >= 100.0) {
		aviao->combustivel = 100.0;
	}
}

int main(void) {

	bool done = false, redraw = false, acertou = false, menu1 = false, menu2 = false, pauseTela = false;
	const int FPS = 60;
	int estado = MENUG, continente = -1, destino = -1;
	double pontos;

	DESTINOS *pais = NULL;
	AVIOES aviao;

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *fonte = NULL;
	//ALLEGRO_BITMAP *imagemAviao = NULL;
	//bitmaps de menus
	ALLEGRO_BITMAP *americacn = NULL;
	ALLEGRO_BITMAP *americas = NULL;
	ALLEGRO_BITMAP *africa = NULL;
	ALLEGRO_BITMAP *europa = NULL;
	ALLEGRO_BITMAP *asia = NULL;
	ALLEGRO_BITMAP *oceania = NULL;
	ALLEGRO_BITMAP *menug = NULL;
	ALLEGRO_BITMAP *menuc = NULL;
	ALLEGRO_BITMAP *pause = NULL;
	ALLEGRO_BITMAP *configuracoes = NULL;

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

	/*imagemAviao = al_load_bitmap("aviao.png");
	if (!imagemAviao) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar aviao!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}*/

	americacn = al_load_bitmap("americacn.jpg");
	americas = al_load_bitmap("americas.jpg");
	africa = al_load_bitmap("africa.jpg");
	europa = al_load_bitmap("europa.jpg");
	asia = al_load_bitmap("asia.jpg");
	oceania = al_load_bitmap("oceania.jpg");
	if (!americacn || !americas || !africa || !europa || !asia || !oceania) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar mapas!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	menug = al_load_bitmap("menug.jpg");
	menuc = al_load_bitmap("menuc.jpg");
	pause = al_load_bitmap("pause.jpg");
	configuracoes = al_load_bitmap("configuracoes.jpg");
	if (!menuc || !menug || !pause || !configuracoes) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniar telas!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
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
			redraw = true;

			switch (estado) {
			case MENUG:
				if (keys[ESC]) {
					done = true;
				}
				break;
			case MENUC:
				if (keys[ESC]) {
					estado = MENUG;
					keys[ESC] = false;
				}
				break;
			case JOGO:
				if (keys[ESC] || keys[P]) {
					estado = PAUSE;
					keys[ESC] = false;
					keys[P] = false;
				}
				if (aviao.combustivel > 0.0) {
					if (keys[SPACE]) {
						pontos = calculaDistancia(aviao, &pais);
						restauraCombustivel(&aviao, pontos);
					}
					if (keys[UP]) {
						mAviaoCima(&aviao);
					}
					else if (keys[DOWN]) {
						mAviaoBaixo(&aviao);
					}
					if (keys[LEFT]) {
						mAviaoEsq(&aviao);
					}
					else if (keys[RIGHT]) {
						mAviaoDir(&aviao);
					}
				}
				break;
			case PAUSE:
				if (keys[ESC]) {
					estado = JOGO;
					keys[ESC] = false;
				}
			case CONFIGURACOES:
				if (keys[ESC]) {
					if (menu1) {
						estado = MENUG;
						menu1 = false;
					}
					if (menu2) {
						estado = MENUC;
						menu2 = false;
					}
					else if (pauseTela) {
						estado = PAUSE;
						pauseTela = false;
					}
					keys[ESC] = false;
				}
			}
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (evento.keyboard.keycode) {  
			case ALLEGRO_KEY_ESCAPE:
				keys[ESC] = true;
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
			case ALLEGRO_KEY_P:
				keys[P] = true;
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
				case ALLEGRO_KEY_ESCAPE:
					keys[ESC] = false;
					break;
				case ALLEGRO_KEY_P:
					keys[P] = false;
					break;
				}
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			switch (estado) {
			case MENUG:
				//clicar em menuc
				if ((evento.mouse.x >= 222 && evento.mouse.x <= 504) && (evento.mouse.y >= 391 && evento.mouse.y <= 518)) {
					estado = MENUC;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 582 && evento.mouse.x <= 812) && (evento.mouse.y >= 584 && evento.mouse.y <= 649)) {
					menu1 = true;
					estado = CONFIGURACOES;
				}
				break;
			case MENUC:
				//clicar em americacn
				if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 144 && evento.mouse.y <= 203)) {
					continente = AMERICACN;
					destino = sorteiaDestino(AMERICACN);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, AMERICACN);
					estado = JOGO;
				}
				//clicar em americas
				else if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 218 && evento.mouse.y <= 273)) {
					continente = AMERICAS;
					destino = sorteiaDestino(AMERICAS);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, AMERICAS);
					estado = JOGO;
				}
				//clicar em africa
				else if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 283 && evento.mouse.y <= 341)) {
					continente = AFRICA;
					//destino = sorteiaDestino(AFRICA);
					iniciaPais(&pais, sorteiaDestino(AFRICA), AFRICA);
					estado = JOGO;
				}
				//clicar em europa
				else if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 352 && evento.mouse.y <= 412)) {
					continente = EUROPA;
					destino = sorteiaDestino(EUROPA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, EUROPA);
					estado = JOGO;
				}
				//clicar em asia
				else if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 422 && evento.mouse.y <= 479)) {
					continente = ASIA;
					destino = sorteiaDestino(ASIA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, ASIA);
					estado = JOGO;
				}
				//clicar em oceania
				else if ((evento.mouse.x >= 180 && evento.mouse.x <= 607) && (evento.mouse.y >= 495 && evento.mouse.y <= 551)) {
					continente = OCEANIA;
					destino = sorteiaDestino(OCEANIA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, OCEANIA);
					estado = JOGO;
				}
				//clicar em sair
				else if ((evento.mouse.x >= 32 && evento.mouse.x <= 236) && (evento.mouse.y >= 606 && evento.mouse.y <= 662)) {
					estado = MENUG;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 634 && evento.mouse.x <= 820) && (evento.mouse.y >= 591 && evento.mouse.y <= 662)) {
					menu2 = true;
					estado = CONFIGURACOES;
				}
				break;
			case JOGO:
				/*if (clicar em 'pause') {
					estado = PAUSE;
				}*/
				break;
			case PAUSE:
				//clicar em voltar
				if ((evento.mouse.x >= 544 && evento.mouse.x <= 791) && (evento.mouse.y >= 432 && evento.mouse.y <= 685)) {
					estado = JOGO;
				}
				//clicar em sair
				if ((evento.mouse.x >= 43 && evento.mouse.x <= 282) && (evento.mouse.y >= 432 && evento.mouse.y <= 526)) {
					done = true;
				}
				//clicar em configuracoes
				if ((evento.mouse.x >= 201 && evento.mouse.x <= 584) && (evento.mouse.y >= 228 && evento.mouse.y <= 332)) {
					pauseTela = true;
					estado = CONFIGURACOES;
				}
				break;
			case CONFIGURACOES:
				//clicar em voltar
				if ((evento.mouse.x >= 514 && evento.mouse.x <= 777) && (evento.mouse.y >= 292 && evento.mouse.y <= 447)) {
					if (menu1) {
						estado = MENUG;
						menu1 = false;
					}
					else if (menu2) {
						estado = MENUC;
						menu2 = false;
					}
					else if (pauseTela) {
						estado = PAUSE;
						configuracoes = false;
					}
				}
				//clicar em mudo
				/*else if((evento.mouse.x >= 63 && evento.mouse.x <= 348) && (evento.mouse.y >= 292 && evento.mouse.y <= 431)) {
					tira som;
				}*/
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(fila_de_eventos)) {
			redraw = false;

			if (estado == MENUG) {
				al_draw_bitmap(menug, 0, 0, 0);
			}
			else if (estado == MENUC) {
				al_draw_bitmap(menuc, 0, 0, 0);
			}
			else if (estado == JOGO) {
				if (continente == AMERICACN) {
					al_draw_bitmap(americacn, 0, 0, 0);
					al_draw_text(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "OI"/*, pais->nome*/);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
				else if (continente == AMERICAS) {
					al_draw_bitmap(americas, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
				else if (continente == AFRICA) {
					al_draw_bitmap(africa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%c", pais->nome);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
				else if (continente == EUROPA) {
					al_draw_bitmap(europa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%c", pais->nome);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
				else if (continente == ASIA) {
					al_draw_bitmap(asia, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%c", pais->nome);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
				else if (continente == OCEANIA) {
					al_draw_bitmap(oceania, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%c", pais->nome);
					//al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					desenhaAviao(aviao);
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
				}
			}
			else if (estado == PAUSE) {
				al_draw_bitmap(pause, 0, 0, 0);
			}
			else if (estado == CONFIGURACOES) {
				al_draw_bitmap(configuracoes, 0, 0, 0);
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	//destruindo
	al_destroy_bitmap(americacn);
	al_destroy_bitmap(americas);
	al_destroy_bitmap(africa);
	al_destroy_bitmap(europa);
	al_destroy_bitmap(asia);
	al_destroy_bitmap(oceania);
	al_destroy_bitmap(menug);
	al_destroy_bitmap(menuc);
	al_destroy_bitmap(pause);
	al_destroy_bitmap(configuracoes);
	//al_destroy_bitmap(imagemAviao);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}