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
enum ESTADOS{MENUG, MENUC, JOGO, PAUSE, CONFIGURACOES, GAMEOVER};
//enum CONTINENTES{AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};
bool keys[7] = {false, false, false, false, false, false, false};

void iniciaAviao(AVIOES *aviao	) {
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
bool mAviaoCima(AVIOES *aviao) {                      //movimenta nave pra cima
	aviao->y -= aviao->velocidade;
	aviao->combustivel -= 0.1;
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
int sorteiaDestino(int continente) {
	int local;

	if (continente == AMERICACN) {
		local = 1 + (rand() % 15);
	}
	else if (continente == AMERICAS) {
		local = 1 + (rand() % 13);
	}
	else if (continente == AFRICA) {
		local = 1 + (rand() % 53);
	}
	else if (continente == EUROPA) {
		local = 1 + (rand() % 53);
	}
	else if (continente == ASIA) {
		local = 1 + (rand() % 41);
	}
	else if (continente == OCEANIA) {
		local = 1 + (rand() % 5);
	}
	return local;
}

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

	bool done = false, redraw = false, menu1 = false, menu2 = false, pauseTela = false;
	bool acertou = false, perto1 = false, perto2 = false, perto3 = false, longe = false;      //frase da distancia
	bool mCima = false, mBaixo = false, mEsq = false, mDir = false;
	const int FPS = 60;
	int estado = MENUG, continente = -1, destino = -1;
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
	ALLEGRO_BITMAP *menuc = NULL;
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

	imagemAviao = al_load_bitmap("aviao.png");
	if (!imagemAviao) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar aviao!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
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

	menug = al_load_bitmap("menug.jpg");
	menuc = al_load_bitmap("menuc.jpg");
	pause = al_load_bitmap("pause.png");
	configuracoes = al_load_bitmap("configuracoes.png");
	//gameOver = al_load_bitmap("gameover.jpg");
	if (!menuc || !menug || !pause || !configuracoes /*|| !gameOver*/) {
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
					//para aviao
					if (keys[SPACE]) {
						pontos = calculaDistancia(aviao, &pais);
						
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
						if (continente == AMERICACN)
							goto americacn;
						else if (continente == AMERICAS)
							goto americas;
						else if (continente == AFRICA)
							goto africa;
						else if (continente == EUROPA)
							goto europa;
						else if (continente == ASIA)
							goto asia;
						else if (continente == OCEANIA)
							goto oceania;
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
				//clicar em menuc
				if ((evento.mouse.x >= 526 && evento.mouse.x <= 787) && (evento.mouse.y >= 504 && evento.mouse.y <= 575)) {
					estado = MENUC;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 554 && evento.mouse.x <= 762) && (evento.mouse.y >= 594 && evento.mouse.y <= 653)) {
					menu1 = true;
					estado = CONFIGURACOES;
				}
				break;
			case MENUC:
				//clicar em americacn
				if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 94 && evento.mouse.y <= 164)) {
					americacn:
					continente = AMERICACN;
					destino = sorteiaDestino(continente);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, continente);
					printf("%s\n", pais.nome);
					estado = JOGO;
				}
				//clicar em americas
				else if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 183 && evento.mouse.y <= 253)) {
					americas:
					continente = AMERICAS;
					destino = sorteiaDestino(AMERICAS);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, AMERICAS);
					estado = JOGO;
				}
				//clicar em africa
				else if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 276 && evento.mouse.y <= 346)) {
					africa:
					continente = AFRICA;
					destino = sorteiaDestino(AFRICA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, AFRICA);
					estado = JOGO;
				}
				//clicar em europa
				else if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 364 && evento.mouse.y <= 434)) {
					europa:
					continente = EUROPA;
					destino = sorteiaDestino(EUROPA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, EUROPA);
					estado = JOGO;
				}
				//clicar em asia
				else if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 453 && evento.mouse.y <= 523)) {
					asia:
					continente = ASIA;
					destino = sorteiaDestino(ASIA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, ASIA);
					estado = JOGO;
				}
				//clicar em oceania
				else if ((evento.mouse.x >= 290 && evento.mouse.x <= 550) && (evento.mouse.y >= 545 && evento.mouse.y <= 615)) {
					oceania:
					continente = OCEANIA;
					destino = sorteiaDestino(OCEANIA);
					printf("%d\n", destino);
					iniciaPais(&pais, destino, OCEANIA);
					estado = JOGO;
				}
				//clicar em sair
				else if ((evento.mouse.x >= 55 && evento.mouse.x <= 188) && (evento.mouse.y >= 616 && evento.mouse.y <= 662)) {
					estado = MENUG;
				}
				break;
			case JOGO:
				//clicar em pause
				/*if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					estado = PAUSE;
				}*/
				break;
			case PAUSE:
				//clicar em voltar
				if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					estado = JOGO;
				}
				//clicar em sair
				else if ((evento.mouse.x >= 83 && evento.mouse.x <= 344) && (evento.mouse.y >= 473 && evento.mouse.y <= 544)) {
					done = true;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 278 && evento.mouse.x <= 561) && (evento.mouse.y >= 285 && evento.mouse.y <= 378)) {
					pauseTela = true;
					estado = CONFIGURACOES;
				}
				//clicar em voltar ao menu inicial
				else if ((evento.mouse.x >= 278 && evento.mouse.x <= 561) && (evento.mouse.y >= 285 && evento.mouse.y <= 378)) {
					estado = MENUG;
				}
				break;
			case CONFIGURACOES:
				//clicar em voltar
				if ((evento.mouse.x >= 483 && evento.mouse.x <= 744) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
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
				/*else if((evento.mouse.x >= 72 && evento.mouse.x <= 334) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
					tira som;
				}*/
				break;
			case GAMEOVER:
				//clicar em jogar novamente
				/*if((evento.mouse.x >= 72 && evento.mouse.x <= 334) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
					estado = MENUC;
				}*/
				//clicar em sair
				/*else if((evento.mouse.x >= 72 && evento.mouse.x <= 334) && (evento.mouse.y >= 321 && evento.mouse.y <= 391)) {
					done = true;
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
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
				else if (continente == AMERICAS) {
					al_draw_bitmap(americas, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
				else if (continente == AFRICA) {
					al_draw_bitmap(africa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
				else if (continente == EUROPA) {
					al_draw_bitmap(europa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
				else if (continente == ASIA) {
					al_draw_bitmap(asia, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
				else if (continente == OCEANIA) {
					al_draw_bitmap(oceania, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
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
				}
			}
			else if (estado == PAUSE) {
				al_draw_bitmap(pause, 0, 0, 0);
			}
			else if (estado == CONFIGURACOES) {
				al_draw_bitmap(configuracoes, 0, 0, 0);
			}
			/*else if (estado == GAMEOVER) {
				al_draw_bitmap(gameOver, 0, 0, 0);
			}*/

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
	al_destroy_bitmap(gameOver);
	al_destroy_bitmap(imagemAviao);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}