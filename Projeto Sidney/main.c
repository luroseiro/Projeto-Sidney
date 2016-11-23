#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "objetos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int WIDTH = 839;
const int HEIGHT = 685;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ESC, P};
enum NUM{F1, F2, F3, F4, F5};
enum ESTADOS{MENUG, AJUDA, PREJOGO, JOGO, PAUSE, CONFIGURACOES, GAMEOVER};
//movimentação
bool keys[7] = {false, false, false, false, false, false, false};
//muda de continente
bool num[5] = {false, false, false, false, false};

void iniciaAviao(AVIOES *aviao) {
	aviao->x = WIDTH / 2;
	aviao->y = HEIGHT / 2;
	aviao->velocidade = 2;
	aviao->combustivel = 100.0;
	aviao->graus = 0.0;
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
double rotaciona(AVIOES *aviao) {
	if (aviao->graus == 0.0) {
		if (keys[LEFT] || keys[UP]) {
			aviao->graus -= 2.0;
		}
		else if (keys[DOWN]) {
			aviao->graus = -360.0;
		}
	}
	else if (aviao->graus < 0.0 && aviao->graus > -90.0) {
		if (keys[RIGHT] && keys[UP]) {
			if (aviao->graus < 0.0 && aviao->graus > -45.0) {
				aviao->graus -= 2.0;
				if (aviao->graus <= -45.0) {
					aviao->graus = -45.0;
				}
			}
			else if (aviao->graus < -45.0 && aviao->graus > -90.0) {
				aviao->graus += 2.0;
				if (aviao->graus >= -45.0) {
					aviao->graus = -45.0;
				}
			}
		}
		else if (keys[LEFT] || keys[UP]) {
			aviao->graus -= 2.0;
			if (aviao->graus <= -90.0) {
				aviao->graus = -90.0;
			}
		}
		else if (keys[RIGHT] || keys[DOWN]) {
			aviao->graus += 2.0;
			if (aviao->graus >= 0.0) {
				aviao->graus = 0.0;
			}
		}
	}
	else if (aviao->graus == -90.0) {
		if (keys[LEFT] || keys[DOWN]) {
			aviao->graus -= 2.0;
		}
		else if (keys[RIGHT]) {
			aviao->graus += 2.0;
		}
	}
	else if (aviao->graus < -90.0 && aviao->graus > -180.0) {
		if (keys[LEFT] && keys[UP]) {
			if (aviao->graus < -90.0 && aviao->graus > -135.0) {
				aviao->graus -= 2.0;
				if (aviao->graus <= -135.0) {
					aviao->graus = -135.0;
				}
			}
			else if (aviao->graus < -135.0 && aviao->graus > -180.0) {
				aviao->graus += 2.0;
				if (aviao->graus >= -135.0) {
					aviao->graus = -135.0;
				}
			}
		}
		else if (keys[LEFT] || keys[DOWN]) {
			aviao->graus -= 2.0;
			if (aviao->graus <= -180.0) {
				aviao->graus = -180.0;
			}
		}
		else if (keys[RIGHT] || keys[UP]) {
			aviao->graus += 2.0;
			if (aviao->graus >= -90.0) {
				aviao->graus = -90.0;
			}
		}
	}
	else if (aviao->graus == -180.0) {
		if (keys[RIGHT] || keys[UP]) {
			aviao->graus += 2.0;
		}
		else if (keys[DOWN]) {
			aviao->graus -= 2.0;
		}
	}
	else if (aviao->graus < -180.0 && aviao->graus > -270.0) {
		if (keys[LEFT] && keys[DOWN]) {
			if (aviao->graus < -180.0 && aviao->graus > -225.0) {
				aviao->graus -= 2.0;
				if (aviao->graus <= -225.0) {
					aviao->graus = -225.0;
				}
			}
			else if (aviao->graus < -225.0 && aviao->graus > -270.0) {
				aviao->graus += 2.0;
				if (aviao->graus >= -225.0) {
					aviao->graus = -225.0;
				}
			}
		}
		else if (keys[LEFT] || keys[UP]) {
			aviao->graus += 2.0;
			if (aviao->graus >= -180.0) {
				aviao->graus = -180.0;
			}
		}
		else if (keys[RIGHT] || keys[DOWN]) {
			aviao->graus -= 2.0;
			if (aviao->graus <= -270.0) {
				aviao->graus = -270.0;
			}
		}
	}
	else if (aviao->graus == -270.0) {
		if (keys[LEFT] || keys[UP]) {
			aviao->graus += 2.0;
		}
		else if (keys[RIGHT]) {
			aviao->graus -= 2.0;
		}
	}
	else if (aviao->graus < -270.0 && aviao->graus > -360.0) {
		if (keys[RIGHT] && keys[DOWN]) {
			if (aviao->graus < -270.0 && aviao->graus > -315.0) {
				aviao->graus -= 2.0;
				if (aviao->graus <= -315.0) {
					aviao->graus = -315.0;
				}
			}
			else if (aviao->graus < -315.0 && aviao->graus > -360.0) {
				aviao->graus += 2.0;
				if (aviao->graus >= -315.0) {
					aviao->graus = -315.0;
				}
			}
		}
		else if(keys[LEFT] || keys[DOWN]) {
			aviao->graus += 2.0;
			if (aviao->graus >= -270.0) {
				aviao->graus = -270.0;
			}
		}
		else if (keys[RIGHT] || keys[UP]) {
			aviao->graus -= 2.0;
			if (aviao->graus <= -360.0) {
				aviao->graus = -360.0;
			}
		}
	}
	else if (aviao->graus == -360.0) {
		if (keys[DOWN]) {
			aviao->graus += 2.0;
		}
		else if (keys[LEFT] || keys[UP]) {
			aviao->graus = 0.0;
		}
	}

	return aviao->graus;
}

int sorteiaDestino(int destinos[]) {
	int local, j = 0;
	bool preenche = false;

	local = 1 + (rand() % 186);

	for (int i = 0; i < sizeof(destinos); i++) {
		verifica:
		if (destinos[i] == local) {
			local = 1 + (rand() % 186);
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
	aviao->graus = 0.0;
}

int main(void) {
	bool done = false, redraw = false, menu = false, pauseTela = false, primeira = true, menus = false, mudo = false;
	//frase de distancia
	bool acertou = false, perto1 = false, perto2 = false, perto3 = false, longe = false;
	//movimentação
	bool mCima = false, mBaixo = false, mEsq = false, mDir = false;
	//mudança de tela
	bool contamericacn = false, contamericas = false, contafrica = false, conteuropa = false, contasia = false, contoceania = false;
	//variaveis de controle
	const int FPS = 60;
	int estado = MENUG, continente = -1, destino = -1, destinos[186], imagemW = 0, imagemH = 0;
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
	//audio
	ALLEGRO_SAMPLE *motor = NULL;
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instance1 = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instance2 = NULL;

	//inicializacao allegro
	if (!al_init()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar Allegro!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//criando display
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
	if (!al_install_audio()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao instalar audio!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
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
	if (!al_init_acodec_addon()) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar addon acodec!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
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

	//sprite aviao
	imagemAviao = al_load_bitmap("aviao.png");
	imagemW = al_get_bitmap_width(imagemAviao);
	imagemH = al_get_bitmap_height(imagemAviao);
	if (!imagemAviao) {
		al_show_native_message_box(janela, "ERRO", "Erro ao iniciar aviao!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//mapas de fundo
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

	al_reserve_samples(10);
	motor = al_load_sample("motor.ogg");
	//musica = al_load_sample("musica.ogg");
	instance1 = al_create_sample_instance(motor);
	//instance2 = al_create_sample_instance(musica);
	if (!motor || !instance1/* || !musica || instance2*/) {
		al_show_native_message_box(janela, "ERRO", "Erro ao criar audios!", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_attach_sample_instance_to_mixer(instance1, al_get_default_mixer());
	//al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());

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
			system("cls");
			done = true;
		}
		else if (evento.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			switch (estado) {
			case MENUG:
				if (!mudo) {
					//al_play_sample_instance(instance2);
				}
				
				if (keys[ESC]) {
					done = true;
				}
				break;
			case AJUDA:
				if (!mudo) {
					//al_play_sample_instance(instance2);
				}

				if (keys[ESC]) {
					estado = MENUG;
					keys[ESC] = false;
				}
				break;
			case JOGO:
				aviao.combustivel -= 0.01;

				//mudar de continente
				if (continente == AMERICACN) {
					//clicar em americas
					if (num[F1]) {
						contamericas = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em africa
					else if (num[F2]) {
						contafrica = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em europa
					else if (num[F3]) {
						conteuropa = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em asia
					else if (num[F4]) {
						contasia = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em oceania
					else if (num[F5]) {
						contoceania = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}
				else if (continente == AMERICAS) {
					//clicar em americacn
					if (num[F1]) {
						contamericacn = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em africa
					else if (num[F2]) {
						contafrica = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em europa
					else if (num[F3]) {
						conteuropa = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em asia
					else if (num[F4]) {
						contasia = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em oceania
					else if (num[F5]) {
						contoceania = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}
				else if (continente == AFRICA) {
					//clicar em americacn
					if (num[F1]) {
						contamericacn = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em americas
					else if (num[F2]) {
						contamericas = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em europa
					else if (num[F3]) {
						conteuropa = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em asia
					else if (num[F4]) {
						contasia = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em oceania
					else if (num[F5]) {
						contoceania = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}
				else if (continente == EUROPA) {
					//clicar em americacn
					if (num[F1]) {
						contamericacn = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em americas
					else if (num[F2]) {
						contamericas = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em africa
					else if (num[F3]) {
						contafrica = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em asia
					else if (num[F4]) {
						contasia = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em oceania
					else if (num[F5]) {
						contoceania = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}
				else if (continente == ASIA) {
					//clicar em americacn
					if (num[F1]) {
						contamericacn = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em americas
					else if (num[F2]) {
						contamericas = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em africa
					else if (num[F3]) {
						contafrica = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em europa
					else if (num[F4]) {
						conteuropa = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em oceania
					else if (num[F5]) {
						contoceania = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}
				else if (continente == OCEANIA) {
					//clicar em americacn
					if (num[F1]) {
						contamericacn = true;
						num[F1] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em americas
					else if (num[F2]) {
						contamericas = true;
						num[F2] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em africa
					else if (num[F3]) {
						contafrica = true;
						num[F3] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em europa
					else if (num[F4]) {
						conteuropa = true;
						num[F4] = false;
						aviao.combustivel -= 1.0;
					}
					//clicar em asia
					else if (num[F5]) {
						contasia = true;
						num[F5] = false;
						aviao.combustivel -= 1.0;
					}
				}

				//pause
				if (keys[ESC] || keys[P]) {
					estado = PAUSE;
					keys[ESC] = false;
					keys[P] = false;
				}

				//jogo principal
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

					//movimenta e toca audio
					if (keys[UP] || keys[DOWN] || keys[LEFT] || keys[RIGHT]) {
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

						if (!mudo) {
							al_play_sample_instance(instance1);
						}
					}
					//para audio
					else {
						al_stop_sample_instance(instance1);
					}
				}
				else {
					al_stop_sample_instance(instance1);
					al_show_native_message_box(janela, "OPS!", "Seu combustivel acabou!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
					estado = GAMEOVER;
				}
				break;
			case PAUSE:
				if (!mudo) {
					//al_play_sample_instance(instance2);
				}

				if (keys[ESC]) {
					estado = JOGO;
					keys[ESC] = false;
				}
				break;
			case CONFIGURACOES:
				if (!mudo) {
					//al_play_sample_instance(instance2);
				}

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
				if (!mudo) {
					//al_play_sample_instance(instance2);
				}

				//controle de movimentação
				keys[UP] = false;
				keys[DOWN] = false;
				keys[LEFT] = false;
				keys[RIGHT] = false;
				
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
			//mudanca de continente
			case ALLEGRO_KEY_F1:
				num[F1] = true;
				break;
			case ALLEGRO_KEY_F2:
				num[F2] = true;
				break;
			case ALLEGRO_KEY_F3:
				num[F3] = true;
				break;
			case ALLEGRO_KEY_F4:
				num[F4] = true;
				break;
			case ALLEGRO_KEY_F5:
				num[F5] = true;
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
				//mudanca de continente
				case ALLEGRO_KEY_F1:
					num[F1] = false;
					break;
				case ALLEGRO_KEY_F2:
					num[F2] = false;
					break;
				case ALLEGRO_KEY_F3:
					num[F3] = false;
					break;
				case ALLEGRO_KEY_F4:
					num[F4] = false;
					break;
				case ALLEGRO_KEY_F5:
					num[F5] = false;
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
					menus = true;
					menu = true;
					estado = CONFIGURACOES;
				}
				break;
			case AJUDA:
				//clicar em jogar
				if ((evento.mouse.x >= 498 && evento.mouse.x <= 609) && (evento.mouse.y >= 574 && evento.mouse.y <= 644)) {
					destino = sorteiaDestino(destinos);
					printf("%d\n", destino);
					iniciaPais(&pais, destino);
					printf("%s\n", pais.nome);
					continente = rand() % 5;
					estado = PREJOGO;
				}
				//clicar em voltar
				else if ((evento.mouse.x >= 80 && evento.mouse.x <= 341) && (evento.mouse.y >= 574 && evento.mouse.y <= 644)) {
					estado = MENUG;
				}
				break;
			case PREJOGO:
				//clicar em jogar
				if ((evento.mouse.x >= 295 && evento.mouse.x <= 557) && (evento.mouse.y >= 584 && evento.mouse.y <= 656)) {
					estado = JOGO;
				}
				break;
			case JOGO:
				//clicar em pause
				switch (continente) {
				case AMERICACN:
					if ((evento.mouse.x >= 665 && evento.mouse.x <= 789) && (evento.mouse.y >= 614 && evento.mouse.y <= 662)) {
						estado = PAUSE;
					}
					break;
				case AMERICAS:
					if ((evento.mouse.x >= 670 && evento.mouse.x <= 798) && (evento.mouse.y >= 608 && evento.mouse.y <= 665)) {
						estado = PAUSE;
					}
					break;
				case AFRICA:
					if ((evento.mouse.x >= 670 && evento.mouse.x <= 798) && (evento.mouse.y >= 608 && evento.mouse.y <= 665)) {
						estado = PAUSE;
					}
					break;
				case EUROPA:
					if ((evento.mouse.x >= 670 && evento.mouse.x <= 798) && (evento.mouse.y >= 608 && evento.mouse.y <= 665)) {
						estado = PAUSE;
					}
					break;
				case ASIA:
					if ((evento.mouse.x >= 691 && evento.mouse.x <= 815) && (evento.mouse.y >= 610 && evento.mouse.y <= 659	)) {
						estado = PAUSE;
					}
					break;
				case OCEANIA:
					if ((evento.mouse.x >= 670 && evento.mouse.x <= 798) && (evento.mouse.y >= 608 && evento.mouse.y <= 665)) {
						estado = PAUSE;
					}
					break;
				}
				break;
			case PAUSE:
				//clicar em voltar
				if ((evento.mouse.x >= 492 && evento.mouse.x <= 755) && (evento.mouse.y >= 369 && evento.mouse.y <= 438)) {
					estado = JOGO;
				}
				//clicar em sair
				else if ((evento.mouse.x >= 83 && evento.mouse.x <= 344) && (evento.mouse.y >= 369 && evento.mouse.y <= 438)) {
					system("cls");
					done = true;
				}
				//clicar em configuracoes
				else if ((evento.mouse.x >= 280 && evento.mouse.x <= 561) && (evento.mouse.y >= 180 && evento.mouse.y <= 273)) {
					menus = false;
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
					if (menus) {
						//al_stop_sample_instance(instance2);
						mudo = true;
					}
					else {
						al_stop_sample_instance(instance1);
						mudo = true;
					}
					al_show_native_message_box(janela, "MUDO", "Jogo silenciado", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
				}
				break;
			case GAMEOVER:
				//clicar em jogar novamente
				if((evento.mouse.x >= 486 && evento.mouse.x <= 747) && (evento.mouse.y >= 342 && evento.mouse.y <= 414)) {
					restauraCombustivel(&aviao, 100.0);
					restauraPosicao(&aviao);
					estado = AJUDA;
					system("cls");
				}
				//clicar em sair
				else if((evento.mouse.x >= 76 && evento.mouse.x <= 337) && (evento.mouse.y >= 342 && evento.mouse.y <= 414)) {
					system("cls");
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
				al_draw_textf(fonte, al_map_rgb(0, 0, 0), WIDTH / 2, HEIGHT - 260, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
			}
			else if (estado == JOGO) {
				if (continente == AMERICACN) {
					damericacn:
					al_draw_bitmap(americacn, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if(!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						restauraPosicao(&aviao);
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
						goto doceania;
					}
				}
				else if (continente == AMERICAS) {
					damericas:
					al_draw_bitmap(americas, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						restauraPosicao(&aviao);
						goto damericacn;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						restauraPosicao(&aviao);
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						restauraPosicao(&aviao);
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
						goto doceania;
					}
				}
				else if (continente == AFRICA) {
					dafrica:
					al_draw_bitmap(africa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						restauraPosicao(&aviao);
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						restauraPosicao(&aviao);
						goto damericas;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						restauraPosicao(&aviao);
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						restauraPosicao(&aviao);
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
						goto doceania;
					}
				}
				else if (continente == EUROPA) {
					deuropa:
					al_draw_bitmap(europa, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH - 315, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), WIDTH - 315, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						restauraPosicao(&aviao);
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						restauraPosicao(&aviao);
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (contasia) {
						contasia = false;
						continente = ASIA;
						restauraPosicao(&aviao);
						goto dasia;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
						goto doceania;
					}
				}
				else if (continente == ASIA) {
					dasia:
					al_draw_bitmap(asia, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH - 315, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), WIDTH - 315, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						restauraPosicao(&aviao);
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						restauraPosicao(&aviao);
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						restauraPosicao(&aviao);
						goto deuropa;
					}
					else if (contoceania) {
						contoceania = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
						goto doceania;
					}
				}
				else if (continente == OCEANIA) {
					doceania:
					al_draw_bitmap(oceania, 0, 0, 0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT - 90, ALLEGRO_ALIGN_CENTRE, "%s", pais.nome);
					//desenha combustivel
					if (aviao.combustivel >= 0.0) {
						al_draw_textf(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: %.1fL", aviao.combustivel);
					}
					else {
						al_draw_text(fonte, al_map_rgb(255, 255, 255), 20, 20, 0, "Combustível: 0.0L");
					}

					//movimentacao
					if (!mCima && !mBaixo && !mEsq && !mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, WIDTH / 2, HEIGHT / 2, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mCima) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mBaixo) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					if (mEsq) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}
					else if (mDir) {
						al_draw_rotated_bitmap(imagemAviao, imagemW / 2, imagemH / 2, aviao.x, aviao.y, rotaciona(&aviao) * 3.14159 / 180, 0);
					}

					al_draw_filled_circle(aviao.x, aviao.y, 1, al_map_rgb(0, 0, 0));

					//frase final
					if (acertou) {
						al_show_native_message_box(janela, "Resultado:", "Destino correto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						acertou = false;
					}
					else if (perto1) {
						al_show_native_message_box(janela, "Resultado:", "Chegou bem perto!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto1 = false;
					}
					else if (perto2) {
						al_show_native_message_box(janela, "Resultado:", "Faltou um pouco!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto2 = false;
					}
					else if (perto3) {
						al_show_native_message_box(janela, "Resultado:", "Foi mais ou menos!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						perto3 = false;
					}
					else if (longe) {
						al_show_native_message_box(janela, "Resultado:", "Errou longe!", NULL, NULL, ALLEGRO_MESSAGEBOX_WARN);
						longe = false;
					}

					//mudar de continente
					if (contamericacn) {
						contamericacn = false;
						continente = AMERICACN;
						restauraPosicao(&aviao);
						goto damericacn;
					}
					else if (contamericas) {
						contamericas = false;
						continente = AMERICAS;
						restauraPosicao(&aviao);
						goto damericas;
					}
					else if (contafrica) {
						contafrica = false;
						continente = AFRICA;
						restauraPosicao(&aviao);
						goto dafrica;
					}
					else if (conteuropa) {
						conteuropa = false;
						continente = EUROPA;
						restauraPosicao(&aviao);
						goto deuropa;
					}
					else if (contasia) {
						contasia = false;
						continente = OCEANIA;
						restauraPosicao(&aviao);
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
	al_destroy_sample(motor);
	al_destroy_sample(musica);
	al_destroy_sample_instance(instance1);
	al_destroy_sample_instance(instance2);
	al_destroy_font(fonte);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_display(janela);

	return 0;

}
