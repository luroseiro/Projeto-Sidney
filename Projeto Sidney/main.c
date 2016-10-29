#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "objetos.h"
#include <iostream>

const int WIDTH = 839;
const int HEIGHT = 685;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ESC, P};
enum ESTADOS{MENUG, MENUC, JOGO, PAUSE, CONFIGURACOES, GAMEOVER};
enum CONTINENTES{AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};
bool keys[7] = {false, false, false, false, false, false};

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
void mAviaoCima(AVIOES *aviao) {                      //movimenta nave pra cima
	aviao->y -= aviao->velocidade;
	if (aviao->y < 0) {
		aviao->y = 0;
	}
}
void mAviaoBaixo(AVIOES *aviao) {                      //movimenta nave pra baixo
	aviao->y += aviao->velocidade;
	if (aviao->y > HEIGHT) {
		aviao->y = HEIGHT;
	}
}
void mAviaoEsq(AVIOES *aviao) {                      //movimenta nave pra esquerda
	aviao->x -= aviao->velocidade;
	if (aviao->x < 0) {
		aviao->x = 0;
	}
}
void mAviaoDir(AVIOES *aviao) {                      //movimenta nave pra direita
	aviao->x += aviao->velocidade;
	if (aviao->x > WIDTH) {
		aviao->x = WIDTH;
	}
}
int sorteiaDestino(int continente) {
	int  destino;
	
	if (destino == AMERICACN)
		destino = 1 + (rand() % 13);
	else if (destino == AMERICAS)
		destino = 1 + (rand() % 13);
	else if (destino == AFRICA)
		destino = 1 + (rand() % 53);
	else if (destino == EUROPA)
		destino = 1 + (rand() % 53);
	else if (destino == ASIA)
		destino = 1 + (rand() % 35);
	else if (destino == OCEANIA)
		destino = 1 + (rand() % 5);

	return destino;
}
DESTINOS *iniciaPais(DESTINOS *pais, int destino, int continente);

void mudaEstado(int *estado, int novoEstado) {
	if (estado == MENUG) {
		printf("Deixando o estado MENUG\n");
	}
	else if (estado == MENUC) {
		printf("Deixando o estado MENUC\n");
	}
	else if (estado == JOGO) {
		printf("Deixando o estado JOGO\n");
	}
	else if (estado = PAUSE) {
		printf("Deixando o estado PAUSE\n");
	}
	else if (estado == GAMEOVER) {
		printf("Deixando o estado GAMEOVER\n");
	}

	estado = novoEstado;

	if (estado == MENUG) {
		printf("Entrand no estado MENUG\n");
	}
	else if (estado == MENUC) {
		printf("Entrand no estado MENUC\n");
	}
	else if (estado == JOGO) {
		printf("Entrand no estado JOGO\n");
	}
	else if (estado = PAUSE) {
		printf("Entrand no estado PAUSE\n");
	}
	else if (estado == GAMEOVER) {
		printf("Entrand no estado GAMEOVER\n");
	}
}

int main(void) {

	bool done = false, redraw = false, gameOver = false;
	const int FPS = 60;
	int destino, *estado = -1, continente = -1;

	AVIOES aviao;
	DESTINOS *pais;

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *fonte = NULL;
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

	/*menug = al_load_bitmap("menug.jpg");
	menuc = al_load_bitmap("menuc.jpg");
	pause = al_load_bitmap("pause.jpg");
	configuracoes = al_load_bitmap("configuracoes.jpg");
	if (!menuc || !menug || !pause || !configuracoes) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniar telas!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}*/

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

	srand(time(NULL));
	iniciaAviao(&aviao);

	fonte = al_load_font("fonte.ttf", 27, 0);
	if (!fonte) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar fonte!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	mudaEstado(&estado, MENUG);

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
				mAviaoCima(&aviao);
			}
			if (keys[DOWN]) {
				mAviaoBaixo(&aviao);
			}
			if (keys[LEFT]) {
				mAviaoEsq(&aviao);
			}
			if (keys[RIGHT]) {
				mAviaoDir(&aviao);
			}

			if (estado == MENUG) {
				/*if (clicar em 'jogar') {
					mudaEstado(&estado, MENUC);
				}
				else if (clicar em 'configurãcoes') {
					mudaEstado(&estado, CONFIGURACOES);
				}*/
			}
			else if (estado == MENUC) {
				/*if (clicar em qualquer opcao) {
					if(clicar em 'americacn') {
						continente = AMERICACN;
						destino = sorteiaDestino(AMERICACN);
						pais = iniciaPais(&pais, destino, AMERICACN);
					}
					if(clicar em 'americas') {
						continente = AMERICAS;
						destino = sorteiaDestino(AMERICAS);
						pais = iniciaPais(&pais, destino, AMERICAS);
					}
					if(clicar em 'africa') {
						continente = AFRICA;
						destino = sorteiaDestino(AFRICA);
						pais = iniciaPais(&pais, destino, AFRICA);
					}
					if(clicar em 'europa') {
						continente = EUROPA;
						destino = sorteiaDestino(EUROPA);
						pais = iniciaPais(&pais, destino, EUROPA);
					}
					if(clicar em 'asia') {
						continente = ASIA;
						destino = sorteiaDestino(ASIA);
						pais = iniciaPais(&pais, destino, ASIA);
					}
					if(clicar em 'oceania') {
						continente = OCEANIA;
						destino = sorteiaDestino(OCEANIA);
						pais = iniciaPais(&pais, destino, OCEANIA);
					}
					mudaEstado(&estado, JOGO);
				}*/
			}
			else if (estado == JOGO) {
				/*if (keys[ESC] || keys[P] || clicar em 'pause') {
					mudaEstado(&estado, PAUSE);
				}*/
			}
			else if (estado == PAUSE) {
				/*if (keys[ESC] || clicar em 'voltar') {
					mudaEstado(&estado, JOGO);
				}
				else if (clicar em 'sair') {
					mudaEstado(&estado, GAMEOVER);
				}
				else if (clicar em 'configuracoes') {
					mudaEstado(&estado, CONFIGURACOES);
				}*/
			}
			else if (estado == CONFIGURACOES) {
				/*if (clicar em 'voltar') {
					mudaEstado(&estado, JOGO);
				}
				else if(clicar em 'som') {
					tira som;
				}	*/
			}
			else if (estado == GAMEOVER) {
				done = true;
			}
			redraw = true; 
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
				keys[PAUSE] = true;
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
					keys[PAUSE] = false;
					break;
				}
			}
		}

		if (redraw && al_is_event_queue_empty(fila_de_eventos)) {
			redraw = false;

			if (estado == MENUG) {
				//al_draw_bitmap(menug);
			}
			else if (estado == MENUC) {
				//al_draw_bitmap(menuc);
			}
			else if (estado == JOGO) {
				if (!gameOver) {
					if (continente == AMERICACN) {
						al_draw_bitmap(americacn, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
					else if (continente == AMERICAS) {
						al_draw_bitmap(americas, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
					else if (continente == AFRICA) {
						al_draw_bitmap(africa, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
					else if (continente == EUROPA) {
						al_draw_bitmap(europa, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
					else if (continente == ASIA) {
						al_draw_bitmap(asia, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
					else if (continente == OCEANIA) {
						al_draw_bitmap(oceania, 0, 0, 0);
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90,
							ALLEGRO_ALIGN_CENTRE, "%s", pais->nome);
						desenhaAviao(aviao);
					}
				}
			}
			else if (estado == PAUSE) {
				//al_draw_bitmap(pause);
			}
			else if (estado == CONFIGURACOES) {
				//al_draw_bitmap(configuracoes);
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
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}