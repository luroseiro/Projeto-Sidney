#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "objetos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int WIDTH = 839;
const int HEIGHT = 685;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ESC, P};
enum ESTADOS{MENUG, AJUDA, PREJOGO, JOGO, PAUSE, CONFIGURACOES, GAMEOVER};
//enum CONTINENTES{AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};
bool keys[7] = {false, false, false, false, false, false, false};

void iniciaAviao(AVIOES *aviao	) {
	aviao->x = WIDTH / 2;
	aviao->y = HEIGHT / 2;
	aviao->velocidade = 2;
	aviao->combustivel = 100.0;
}
bool mAviaoCima(AVIOES *aviao) {                      //movimenta nave pra cima
	aviao->y -= aviao->velocidade;
	aviao->combustivel -= 0.2;
	if (aviao->y < 0) {
		aviao->y = 0;
	}
	return true;
}
bool mAviaoBaixo(AVIOES *aviao) {                      //movimenta nave pra baixo
	aviao->y += aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->y > HEIGHT - 36) {
		aviao->y = HEIGHT - 36;
	}
	return true;
}
bool mAviaoEsq(AVIOES *aviao) {                      //movimenta nave pra esquerda
	aviao->x -= aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->x < 0) {
		aviao->x = 0;
	}
	return true;
}
bool mAviaoDir(AVIOES *aviao) {                      //movimenta nave pra direita
	aviao->x += aviao->velocidade;
	aviao->combustivel -= 0.1;
	if (aviao->x > WIDTH - 48) {
		aviao->x = WIDTH - 48;
	}
	return true;
}

int sorteiaDestino(int destinos[]) {
	int local, j = 0;
	bool preenche = false;

	local = 1 + (rand() % 187);

	for (int i = 0; i < sizeof(destinos); i++) {
		verifica:
		if (destinos[i] == local) {
			local = 1 + (rand() % 187);
			goto verifica;
		}
	}

	preenche = true;

	if(preenche) {
		destinos[j] = local;
		j++;
		preenche = false;
	}

	return local;
}

double calculaDistancia(AVIOES aviao, DESTINOS *pais, int continente) {
	double distancia, pontos = 100.0;

	if (pais->continente == continente) {
		distancia = sqrt(pow((pais->localizacao_x - aviao.x), 2) + pow((pais->localizacao_y - aviao.y), 2));
	}
	else {
		pontos = 0.0;
		goto fim;
	}
	
	while (distancia > 0.0 && pontos >= 0.0) {
		pontos -= 0.5;
		distancia -= 0.5;
	}

	fim:
	return pontos;
}
void restauraCombustivel(AVIOES *aviao, double pontos) {
	aviao->combustivel += pontos;
	if (aviao->combustivel >= 100.0) {
		aviao->combustivel = 100.0;
	}
}
void restauraPosicao(AVIOES *aviao) {
	aviao->x = WIDTH / 2;
	aviao->y = HEIGHT / 2;
}

int main(void) {
	bool done = false, redraw = false, menu = false, pauseTela = false;
	bool acertou = false, perto1 = false, perto2 = false, perto3 = false, longe = false;      //frase da distancia
	bool mCima = false, mBaixo = false, mEsq = false, mDir = false;
	bool contamericacn = false, contamericas = false, contafrica = false, conteuropa = false, contasia = false, contoceania = false;
	const int FPS = 60;
	int estado = MENUG, continente = -1, destino = -1, destinos[187];
	double pontos;

	DESTINOS pais;
	AVIOES aviao;

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *fonte = NULL;
	ALLEGRO_BITMAP *imagemAviao;;
	//bitmaps de menus
	ALLEGRO_BITMAP *americacn = NULL;
	ALLEGRO_BITMAP *americas = NULL;
	ALLEGRO_BITMAP *africa = NULL;
	ALLEGRO_BITMAP *europa = NULL;
	ALLEGRO_BITMAP *asia = NULL;
	ALLEGRO_BITMAP *oceania = NULL;
	ALLEGRO_BITMAP *menug = NULL;
	ALLEGRO_BITMAP *ajuda = NULL;
	ALLEGRO_BITMAP *prejogo = NULL;
	ALLEGRO_BITMAP *pause = NULL;
	ALLEGRO_BITMAP *configuracoes = NULL;
	ALLEGRO_BITMAP *gameOver = NULL;

	if (!al_init()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar Allegro!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	janela = al_create_display(WIDTH, HEIGHT);
	if (!janela) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar janela!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//inicializando addons
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

	//incializando fila de eventos e timer
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

	imagemAviao = al_load_bitmap("aviao.png");
	if (!imagemAviao) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar aviao!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//mapas de fundo
	americacn = al_load_bitmap("americacn.jpg");
	americas = al_load_bitmap("americas.jpeg");
	africa = al_load_bitmap("africa.jpeg");
	europa = al_load_bitmap("europa.jpeg");
	asia = al_load_bitmap("asia.jpg");
	oceania = al_load_bitmap("oceania.jpeg");
	if (!americacn || !americas || !africa || !europa || !asia || !oceania) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar mapas!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//menus
	menug = al_load_bitmap("menug.jpg");
	ajuda = al_load_bitmap("ajuda.jpg");
	prejogo = al_load_bitmap("prejogo.jpg");
	pause = al_load_bitmap("pause.jpg");
	configuracoes = al_load_bitmap("configuracoes.jpg");
	gameOver = al_load_bitmap("gameover.jpg");
	if (!ajuda || !prejogo || !menug || !pause || !configuracoes || !gameOver) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar telas!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
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
			case AJUDA:
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
					//para aviao
					if (keys[SPACE]) {
						pontos = calculaDistancia(aviao, &pais, continente);
						keys[SPACE] = false;

						//verifica frase final
						if (pontos >= 90.0) {
							acertou = true;
						}
						else if (pontos < 90.0 && pontos >= 70.0) {
							perto1 = true;
						}
						else if (pontos < 70.0 && pontos >= 50.0) {
							perto2 = true;
						}
						else if (pontos < 50.0 && pontos >= 40.0) {
							perto3 = true;
						}
						else if (pontos < 40.0) {
							longe = true;
						}

						//restaura combustivel e comeca de novo
						restauraCombustivel(&aviao, pontos);
						destino = -1;
						destino = sorteiaDestino(destinos);
						printf("%d\n", destino);
						iniciaPais(&pais, destino);
						printf("%s\n", pais.nome);
					}
					//movimento vertical
					if (keys[UP]) {
						mCima = mAviaoCima(&aviao);
					}
					else if (keys[DOWN]) {
						mBaixo = mAviaoBaixo(&aviao);
					}
					//movimento horizontal
					if (keys[LEFT]) {
						mEsq = mAviaoEsq(&aviao);
					}
					else if (keys[RIGHT]) {
						mDir = mAviaoDir(&aviao);
					}
				}
				break;
			case PAUSE:
				if (keys[ESC]) {
					estado = JOGO;
					keys[ESC] = false;
				}
				break;
			case CONFIGURACOES:
				if (keys[ESC]) {
					if (menu) {
						estado = MENUG;
						menu = false;
					}
					else if (pauseTela) {
						estado = PAUSE;
						pauseTela = false;
					}
					keys[ESC] = false;
				}
				break;
			case GAMEOVER:
				if (keys[ESC]) {
					done = true;
					keys[ESC] = false;
				}
				break;
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
				//clicar em jogar
				if ((evento.mouse.x >= 526 && evento.mouse.x <= 787) && (evento.mouse.y >= 504 && evento.mouse.y <= 575)) {
					estado = AJUDA;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 554 && evento.mouse.x <= 762) && (evento.mouse.y >= 594 && evento.mouse.y <= 653)) {
					menu = true;
					estado = CONFIGURACOES;
				}
				break;
			case AJUDA:
				//clicar em jogar
				if ((evento.mouse.x >= 501 && evento.mouse.x <= 783) && (evento.mouse.y >= 520 && evento.mouse.y <= 622)) {
					destino = sorteiaDestino(destinos);
					printf("%d\n", destino);
					iniciaPais(&pais, destino);
					printf("%s\n", pais.nome);
					continente = rand() % 5;
					estado = PREJOGO;
				}
				//clicar em voltar
				else if ((evento.mouse.x >= 132 && evento.mouse.x <= 440) && (evento.mouse.y >= 520 && evento.mouse.y <= 622)) {
					estado = MENUG;
				}
				break;
			case PREJOGO:
				//clicar em jogar
				if ((evento.mouse.x >= 508 && evento.mouse.x <= 812) && (evento.mouse.y >= 564 && evento.mouse.y <= 657)) {
					estado = JOGO;
				}
				break;
			case JOGO:
				//clicar em pause
				/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					estado = PAUSE;
				}*/
				//clicar em um dos outros continentes
				if (continente == AMERICACN) {
					//clicar em americas
					if ((evento.mouse.x >= 773 && evento.mouse.x <= 780) && (evento.mouse.y >= 256 && evento.mouse.y <= 260)) {
						contamericas = true;
					}
					/*//clicar em africa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
						continente = AFRICA;
					}
					//clicar em europa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
						continente = EUROPA;
					}
					//clicar em asia
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
						continente = ASIA;
					}
					//clicar em oceania
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
						continente = OCEANIA;
					}*/
				}
				else if (continente == AMERICAS) {
					//clicar em americacn
					if ((evento.mouse.x >= 178 && evento.mouse.x <= 190) && (evento.mouse.y >= 165 && evento.mouse.y <= 180)) {
						contamericacn = true;
					}
					/*//clicar em africa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AFRICA;
					}
					//clicar em europa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = EUROPA;
					}
					//clicar em asia
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = ASIA;
					}
					//clicar em oceania
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = OCEANIA;
					}*/
				}
				else if (continente == AFRICA) {
					//clicar em americacn
					/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICACN;
					}
					//clicar em americas
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICAS;
					}
					//clicar em europa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = EUROPA;
					}
					//clicar em asia
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = ASIA;
					}
					//clicar em oceania
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = OCEANIA;
					}*/
				}
				else if (continente == EUROPA) {
					//clicar em americacn
					/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICACN;
					}
					//clicar em americas
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICAS;
					}
					//clicar em africa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AFRICA;
					}
					//clicar em asia
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = ASIA;
					}
					//clicar em oceania
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = OCEANIA;
					}*/
				}
				else if (continente == ASIA) {
					//clicar em americacn
					/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICACN;
					}
					//clicar em americas
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICAS;
					}
					//clicar em africa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AFRICA;
					}
					//clicar em europa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = EUROPA;
					}
					//clicar em oceania
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = OCEANIA;
					}*/
				}
				else if (continente == OCEANIA) {
					//clicar em americacn
					/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICACN;
					}
					//clicar em americas
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AMERICAS;
					}
					//clicar em africa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = AFRICA;
					}
					//clicar em europa
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = EUROPA;
					}
					//clicar em asia
					else if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					continente = ASIA;
					}*/
				}
				break;
			case PAUSE:
				//clicar em voltar
				if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 369 && evento.mouse.y <= 438)) {
					estado = JOGO;
				}
				//clicar em sair
				else if ((evento.mouse.x >= 83 && evento.mouse.x <= 344) && (evento.mouse.y >= 369 && evento.mouse.y <= 438)) {
					done = true;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 280 && evento.mouse.x <= 561) && (evento.mouse.y >= 180 && evento.mouse.y <= 273)) {
					pauseTela = true;
					estado = CONFIGURACOES;
				}
				//clicar em voltar ao menu inicial
				else if ((evento.mouse.x >= 288 && evento.mouse.x <= 551) && (evento.mouse.y >= 533 && evento.mouse.y <= 604)) {
					restauraCombustivel(&aviao, 100.0);
					restauraPosicao(&aviao);
					estado = MENUG;
					system("cls");
				}
				break;
			case CONFIGURACOES:
				//clicar em voltar
				if ((evento.mouse.x >= 483 && evento.mouse.x <= 744) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
					if (menu) {
						estado = MENUG;
						menu = false;
					}
					else if (pauseTela) {
						estado = PAUSE;
						pauseTela = false;
					}
				}
				//clicar em mudo
				else if((evento.mouse.x >= 72 && evento.mouse.x <= 334) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
					//tira som;
				}
				break;
			case GAMEOVER:
				//clicar em jogar novamente
				if((evento.mouse.x >= 479 && evento.mouse.x <= 809) && (evento.mouse.y >= 422 && evento.mouse.y <= 512)) {
					restauraCombustivel(&aviao, 100.0);
					restauraPosicao(&aviao);
					estado = PREJOGO;
					system("cls");
				}
				//clicar em sair
				else if((evento.mouse.x >= 100 && evento.mouse.x <= 419) && (evento.mouse.y >= 422 && evento.mouse.y <= 512)) {
					done = true;
				}
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(fila_de_eventos)) {
			redraw = false;

			if (estado == MENUG) {
				al_draw_bitmap(menug, 0, 0, 0);
			}
			else if (estado == AJUDA) {
				al_draw_bitmap(ajuda, 0, 0, 0);
			}
			else if (estado == PREJOGO) {
				al_draw_bitmap(prejogo, 0, 0, 0);
				al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 240, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
			}
			else if (estado == JOGO) {
				if (continente == AMERICACN) {
					damericacn:
					al_draw_bitmap(americacn, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if(!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
						//acertou = false;
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
						//perto1 = false;
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
						//perto2 = false;
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
						//perto3 = false;
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
						//longe = false;
					}

					//mudar de continente
					if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						goto dafrica;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						goto dafrica;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						goto doceania;
					}
				}
				else if (continente == AMERICAS) {
					damericas:
					al_draw_bitmap(americas, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						goto damericacn;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						goto doceania;
					}
				}
				else if (continente == AFRICA) {
					dafrica:
					al_draw_bitmap(africa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						goto damericas;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						goto doceania;
					}
				}
				else if (continente == EUROPA) {
					deuropa:
					al_draw_bitmap(europa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						goto dafrica;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						goto doceania;
					}
				}
				else if (continente == ASIA) {
					dasia:
					al_draw_bitmap(asia, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						goto deuropa;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						goto doceania;
					}
				}
				else if (continente == OCEANIA) {
					doceania:
					al_draw_bitmap(oceania, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_bitmap(imagemAviao, WIDTH / 2, HEIGHT / 2, 0);
					}
					if (mCima) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mBaixo) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					if (mEsq) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}
					else if (mDir) {
						al_draw_bitmap(imagemAviao, aviao.x, aviao.y, 0);
					}

					//frase final
					if (acertou) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Destino correto!");
					}
					else if (perto1) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Chegou bem perto!");
					}
					else if (perto2) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Faltou um pouco!");
					}
					else if (perto3) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Foi mais ou menos!");
					}
					else if (longe) {
						al_draw_text(fonte, al_map_rgb(0, 255, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Errou longe!");
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = OCEANIA;
						goto dasia;
					}
				}
			}
			else if (estado == PAUSE) {
				al_draw_bitmap(pause, 0, 0, 0);
			}
			else if (estado == CONFIGURACOES) {
				al_draw_bitmap(configuracoes, 0, 0, 0);
			}
			else if (estado == GAMEOVER) {
				al_draw_bitmap(gameOver, 0, 0, 0);
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
	al_destroy_bitmap(ajuda);
	al_destroy_bitmap(prejogo);
	al_destroy_bitmap(pause);
	al_destroy_bitmap(configuracoes);
	al_destroy_bitmap(gameOver);
	al_destroy_bitmap(imagemAviao);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}
