enum CONTINENTES {AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};

typedef struct avioes {
	int x;
	int y;
	int velocidade;
	int pontuacao;
	double combustivel;
} AVIOES;
typedef struct destinos {
	char *nome;
	int localizacao_x;
	int localizacao_y;
} DESTINOS;

DESTINOS *iniciaPais(DESTINOS *pais, int destino, int continente) {
	switch (continente) {
	case AMERICACN:
		switch (destino) {
		case 1:
			pais->nome = "Bahamas";
			pais->localizacao_x = 416;
			pais->localizacao_y = 531;
			break;
		case 2:
			pais->nome = "Canadá";
			pais->localizacao_x = 464;
			pais->localizacao_y = 378;
			break;
		case 3:
			pais->nome = "Estados Unidos da América";
			pais->localizacao_x = 431;
			pais->localizacao_y = 449;
			break;
		case 4:
			pais->nome = "México";
			pais->localizacao_x = 274;
			pais->localizacao_y = 567;
			break;
		case 5:
			pais->nome = "Cuba";
			pais->localizacao_x = 409;
			pais->localizacao_y = 570;
			break;
		case 6:
			pais->nome = "Belize";
			pais->localizacao_x = 337;
			pais->localizacao_y = 590;
			break;
		case 7:
			pais->nome = "Porto Rico";
			pais->localizacao_x = 468;
			pais->localizacao_y = 588;
			break;
		case 8:
			pais->nome = "Costa Rica";
			pais->localizacao_x = 357;
			pais->localizacao_y = 642;
			break;
		case 9:
			pais->nome = "El Salvador";
			pais->localizacao_x = 333;
			pais->localizacao_y = 618;
			break;
		case 10:
			pais->nome = "Guatemala";
			pais->localizacao_x = 322;
			pais->localizacao_y = 605;
			break;
		case 11:
			pais->nome = "Honduras";
			pais->localizacao_x = 343;
			pais->localizacao_y = 613;
			break;
		case 12:
			pais->nome = "Nicarágua";
			pais->localizacao_x = 351;
			pais->localizacao_y = 627;
			break;
		case 13:
			pais->nome = "Panamá";
			pais->localizacao_x = 384;
			pais->localizacao_y = 649;
			break;
		case 14:
			pais->nome = "Haiti";
			pais->localizacao_x = 430;
			pais->localizacao_y = 589;
		case 15:
			pais->nome = "República Dominicana";
			pais->localizacao_x = 446;
			pais->localizacao_y = 581;
		}
		break;
	case AMERICAS:
		switch (destino) {
		case 1:
			pais->nome = "Argentina";
			pais->localizacao_x = 453;
			pais->localizacao_y = 412;
			break;
		case 2:
			pais->nome = "Bolívia";
			pais->localizacao_x = 378;
			pais->localizacao_y = 302;
			break;
		case 3:
			pais->nome = "Brasil";
			pais->localizacao_x = 506;
			pais->localizacao_y = 297;
			break;
		case 4:
			pais->nome = "Chile";
			pais->localizacao_x = 380;
			pais->localizacao_y = 443;
			break;
		case 5:
			pais->nome = "Colômbia";
			pais->localizacao_x = 340;
			pais->localizacao_y = 171;
			break;
		case 6:
			pais->nome = "Equador";
			pais->localizacao_x = 312;
			pais->localizacao_y = 199;
			break;
		case 7:
			pais->nome = "Guiana";
			pais->localizacao_x = 429;
			pais->localizacao_y = 151;
			break;
		case 8:
			pais->nome = "Guiana Francesa";
			pais->localizacao_x = 467;
			pais->localizacao_y = 166;
			break;
		case 9:
			pais->nome = "Paraguai";
			pais->localizacao_x = 454;
			pais->localizacao_y = 352;
			break;
		case 10:
			pais->nome = "Peru";
			pais->localizacao_x = 324;
			pais->localizacao_y = 265;
			break;
		case 11:
			pais->nome = "Suriname";
			pais->localizacao_x = 449;
			pais->localizacao_y = 155;
			break;
		case 12:
			pais->nome = "Uruguai";
			pais->localizacao_x = 473;
			pais->localizacao_y = 412;
			break;
		case 13:
			pais->nome = "Venezuela";
			pais->localizacao_x = 392;
			pais->localizacao_y = 122;
			break;
		}
		break;
	case AFRICA:
		switch (destino) {
		case 1:
			pais->nome = "África do Sul";
			pais->localizacao_x = 405;
			pais->localizacao_y = 588;
			break;
		case 2:
			pais->nome = "Angola";
			pais->localizacao_x = 382;
			pais->localizacao_y = 434;
			break;
		case 3:
			pais->nome = "Argélia";
			pais->localizacao_x = 335;
			pais->localizacao_y = 233;
			break;
		case 4:
			pais->nome = "Benim";
			pais->localizacao_x = 314;
			pais->localizacao_y = 329;
			break;
		case 5:
			pais->nome = "Botswana";
			pais->localizacao_x = 449;
			pais->localizacao_y = 525;
			break;
		case 6:
			pais->nome = "Burkina Faso";
			pais->localizacao_x = 294;
			pais->localizacao_y = 298;
			break;
		case 7:
			pais->nome = "Burundi";
			pais->localizacao_x = 475;
			pais->localizacao_y = 392;
			break;
		case 8:
			pais->nome = "Cabo Verde";
			pais->localizacao_x = 170;
			pais->localizacao_y = 278;
			break;
		case 9:
			pais->nome = "Camarões";
			pais->localizacao_x = 367;
			pais->localizacao_y = 345;
			break;
		case 10:
			pais->nome = "Chade";
			pais->localizacao_x = 392;
			pais->localizacao_y = 307;
			break;
		case 11:
			pais->nome = "Comores";
			pais->localizacao_x = 566;
			pais->localizacao_y = 443;
			break;
		case 12:
			pais->nome = "Costa do Marfim";
			pais->localizacao_x = 265;
			pais->localizacao_y = 333;
			break;
		case 13:
			pais->nome = "Djibouti";
			pais->localizacao_x = 551;
			pais->localizacao_y = 297;
			break;
		case 14:
			pais->nome = "Egito";
			pais->localizacao_x = 478;
			pais->localizacao_y = 180;
			break;
		case 15:
			pais->nome = "Eritreia";
			pais->localizacao_x = 526;
			pais->localizacao_y = 272;
			break;
		case 16:
			pais->nome = "Etiópia";
			pais->localizacao_x = 526;
			pais->localizacao_y = 317;
			break;
		case 17:
			pais->nome = "Gabão";
			pais->localizacao_x = 357;
			pais->localizacao_y = 370;
			break;
		case 18:
			pais->nome = "Gâmbia";
			pais->localizacao_x = 206;
			pais->localizacao_y = 287;
			break;
		case 19:
			pais->nome = "Gana";
			pais->localizacao_x = 297;
			pais->localizacao_y = 334;
			break;
		case 20:
			pais->nome = "Guiné";
			pais->localizacao_x = 216;
			pais->localizacao_y = 311;
			break;
		case 21:
			pais->nome = "Guiné-Bissau";
			pais->localizacao_x = 210;
			pais->localizacao_y = 302;
			break;
		case 22:
			pais->nome = "Guiné Equatorial";
			pais->localizacao_x = 351;
			pais->localizacao_y = 350;
			break;
		case 23:
			pais->nome = "Lesoto";
			pais->localizacao_x = 462;
			pais->localizacao_y = 554;
			break;
		case 24:
			pais->nome = "Libéria";
			pais->localizacao_x = 236;
			pais->localizacao_y = 331;
			break;
		case 25:
			pais->nome = "Líbia";
			pais->localizacao_x = 375;
			pais->localizacao_y = 170;
			break;
		case 26:
			pais->nome = "Madagascar";
			pais->localizacao_x = 575;
			pais->localizacao_y = 493;
			break;
		case 27:
			pais->nome = "Malawi";
			pais->localizacao_x = 501;
			pais->localizacao_y = 454;
			break;
		case 28:
			pais->nome = "Mali";
			pais->localizacao_x = 254;
			pais->localizacao_y = 290;
			break;
		case 29:
			pais->nome = "Marrocos";
			pais->localizacao_x = 251;
			pais->localizacao_y = 164;
			break;
		case 30:
			pais->nome = "Maurícia";
			pais->localizacao_x = 636;
			pais->localizacao_y = 502;
			break;
		case 31:
			pais->nome = "Mauritânia";
			pais->localizacao_x = 204;
			pais->localizacao_y = 260;
			break;
		case 32:
			pais->nome = "Moçambique";
			pais->localizacao_x = 494;
			pais->localizacao_y = 527;
			break;
		case 33:
			pais->nome = "Namíbia";
			pais->localizacao_x = 397;
			pais->localizacao_y = 502;
			break;
		case 34:
			pais->nome = "Níger";
			pais->localizacao_x = 316;
			pais->localizacao_y = 285;
			break;
		case 35:
			pais->nome = "Nigéria";
			pais->localizacao_x = 341;
			pais->localizacao_y = 319;
			break;
		case 36:
			pais->nome = "Quênia";
			pais->localizacao_x = 522;
			pais->localizacao_y = 379;
			break;
		case 37:
			pais->nome = "República Centro-Africana";
			pais->localizacao_x = 411;
			pais->localizacao_y = 338;
			break;
		case 38:
			pais->nome = "República do Congo";
			pais->localizacao_x = 392;
			pais->localizacao_y = 390;
			break;
		case 39:
			pais->nome = "Ruanda";
			pais->localizacao_x = 480;
			pais->localizacao_y = 382;
			break;
		case 40:
			pais->nome = "São Tomé e Príncipe";
			pais->localizacao_x = 339;
			pais->localizacao_y = 369;
			break;
		case 41:
			pais->nome = "Senegal";
			pais->localizacao_x = 199;
			pais->localizacao_y = 280;
			break;
		case 42:
			pais->nome = "Serra Leoa";
			pais->localizacao_x = 221;
			pais->localizacao_y = 320;
			break;
		case 43:
			pais->nome = "Seychelles";
			pais->localizacao_x = 615;
			pais->localizacao_y = 416;
			break;
		case 44:
			pais->nome = "Somália";
			pais->localizacao_x = 564;
			pais->localizacao_y = 361;
			break;
		case 45:
			pais->nome = "Suzilândia";
			pais->localizacao_x = 483;
			pais->localizacao_y = 537;
			break;
		case 46:
			pais->nome = "Sudão";
			pais->localizacao_x = 488;
			pais->localizacao_y = 277;
			break;
		case 47:
			pais->nome = "Sudão do Sul";
			pais->localizacao_x = 492;
			pais->localizacao_y = 339;
			break;
		case 48:
			pais->nome = "Tanzânia";
			pais->localizacao_x = 532;
			pais->localizacao_y = 409;
			break;
		case 49:
			pais->nome = "Togo";
			pais->localizacao_x = 306;
			pais->localizacao_y = 331;
			break;
		case 50:
			pais->nome = "Tunísia";
			pais->localizacao_x = 354;
			pais->localizacao_y = 136;
			break;
		case 51:
			pais->nome = "Uganda";
			pais->localizacao_x = 494;
			pais->localizacao_y = 369;
			break;
		case 52:
			pais->nome = "Zâmbia";
			pais->localizacao_x = 461;
			pais->localizacao_y = 466;
			break;
		case 53:
			pais->nome = "Zimbabwe";
			pais->localizacao_x = 477;
			pais->localizacao_y = 481;
			break;
		}
		break;
	case EUROPA:
		switch (destino) {
		case 1:
			pais->nome = "Albânia";
			pais->localizacao_x = 439;
			pais->localizacao_y = 395;
			break;
		case 2:
			pais->nome = "Alemanha";
			pais->localizacao_x = 398;
			pais->localizacao_y = 310;
			break;
		case 3:
			pais->nome = "Andorra";
			pais->localizacao_x = 336;
			pais->localizacao_y = 385;
			break;
		case 4:
			pais->nome = "Armênia";
			pais->localizacao_x = 571;
			pais->localizacao_y = 399;
			break;
		case 5:
			pais->nome = "Áustria";
			pais->localizacao_x = 413;
			pais->localizacao_y = 348;
			break;
		case 6:
			pais->nome = "Azerbaijão";
			pais->localizacao_x = 599;
			pais->localizacao_y = 394;
			break;
		case 7:
			pais->nome = "Bélgica";
			pais->localizacao_x = 352;
			pais->localizacao_y = 324;
			break;
		case 8:
			pais->nome = "Bielorrúsia";
			pais->localizacao_x = 474;
			pais->localizacao_y = 298;
			break;
		case 9:
			pais->nome = "Bósnia e Herzegovinia";
			pais->localizacao_x = 429;
			pais->localizacao_y = 377;
			break;
		case 10:
			pais->nome = "Bulgária";
			pais->localizacao_x = 358;
			pais->localizacao_y = 384;
			break;
		case 11:
			pais->nome = "Cazaquistão";
			pais->localizacao_x = 718;
			pais->localizacao_y = 314;
			break;
		case 12:
			pais->nome = "República Tcheca";
			pais->localizacao_x = 404;
			pais->localizacao_y = 330;
			break;
		case 13:
			pais->nome = "Chipre";
			pais->localizacao_x = 514;
			pais->localizacao_y = 438;
			break;
		case 14:
			pais->nome = "Croácia";
			pais->localizacao_x = 411;
			pais->localizacao_y = 368;
			break;
		case 15:
			pais->nome = "Dinamarca";
			pais->localizacao_x = 388;
			pais->localizacao_y = 289;
			break;
		case 16:
			pais->nome = "Eslováquia";
			pais->localizacao_x = 426;
			pais->localizacao_y = 343;
			break;
		case 17:
			pais->nome = "Eslovênia";
			pais->localizacao_x = 407;
			pais->localizacao_y = 360;
			break;
		case 18:
			pais->nome = "Espanha";
			pais->localizacao_x = 310;
			pais->localizacao_y = 407;
			break;
		case 19:
			pais->nome = "Estônia";
			pais->localizacao_x = 453;
			pais->localizacao_y = 255;
			break;
		case 20:
			pais->nome = "Finlândia";
			pais->localizacao_x = 445;
			pais->localizacao_y = 245;
			break;
		case 21:
			pais->nome = "França";
			pais->localizacao_x = 341;
			pais->localizacao_y = 337;
			break;
		case 22:
			pais->nome = "Geórgia";
			pais->localizacao_x = 570;
			pais->localizacao_y = 386;
			break;
		case 23:
			pais->nome = "Grécia";
			pais->localizacao_x = 460;
			pais->localizacao_y = 419;
			break;
		case 24:
			pais->nome = "Hungria";
			pais->localizacao_x = 432;
			pais->localizacao_y = 351;
			break;
		case 25:
			pais->nome = "Irlanda";
			pais->localizacao_x = 297;
			pais->localizacao_y = 305;
			break;
		case 26:
			pais->nome = "Islândia";
			pais->localizacao_x = 231;
			pais->localizacao_y = 218;
			break;
		case 27:
			pais->nome = "Itália";
			pais->localizacao_x = 397;
			pais->localizacao_y = 390;
			break;
		case 28:
			pais->nome = "Kosovo";
			pais->localizacao_x = 443;
			pais->localizacao_y = 381;
			break;
		case 29:
			pais->nome = "Letônia";
			pais->localizacao_x = 454;
			pais->localizacao_y = 271;
			break;
		case 30:
			pais->nome = "Liechtenstein";
			pais->localizacao_x = 386;
			pais->localizacao_y = 354;
			break;
		case 31:
			pais->nome = "Lituânia";
			pais->localizacao_x = 455;
			pais->localizacao_y = 290;
			break;
		case 32:
			pais->nome = "Luxemburgo";
			pais->localizacao_x = 363;
			pais->localizacao_y = 331;
			break;
		case 33:
			pais->nome = "Malta";
			pais->localizacao_x = 408;
			pais->localizacao_y = 422;
			break;
		case 34:
			pais->nome = "Moldávia";
			pais->localizacao_x = 481;
			pais->localizacao_y = 351;
			break;
		case 35:
			pais->nome = "Mônaco";
			pais->localizacao_x = 368;
			pais->localizacao_y = 381;
			break;
		case 36:
			pais->nome = "Montenegro";
			pais->localizacao_x = 434;
			pais->localizacao_y = 386;
			break;
		case 37:
			pais->nome = "Noruega";
			pais->localizacao_x = 383;
			pais->localizacao_y = 247;
			break;
		case 38:
			pais->nome = "Países Baixos (Holanda)";
			pais->localizacao_x = 355;
			pais->localizacao_x = 318;
			break;
		case 39:
			pais->nome = "Polônia";
			pais->localizacao_x = 441;
			pais->localizacao_y = 316;
			break;
		case 40:
			pais->nome = "Portugal";
			pais->localizacao_x = 279;
			pais->localizacao_y = 418;
			break;
		case 41:
			pais->nome = "Inglaterra";
			pais->localizacao_x = 326;
			pais->localizacao_y = 316;
			break;
		case 42:
			pais->nome = "Escócia";
			pais->localizacao_x = 319;
			pais->localizacao_y = 287;
			break;
		case 43:
			pais->nome = "País de Gales";
			pais->localizacao_x = 308;
			pais->localizacao_y = 320;
			break;
		case 44:
			pais->nome = "Irlanda do Norte";
			pais->localizacao_x = 295;
			pais->localizacao_y = 294;
			break;
		case 45:
			pais->nome = "Macedônia";
			pais->localizacao_x = 448;
			pais->localizacao_y = 389;
			break;
		case 46:
			pais->nome = "Romênia";
			pais->localizacao_x = 468;
			pais->localizacao_y = 367;
			break;
		case 47:
			pais->nome = "Rússia";
			pais->localizacao_x = 504;
			pais->localizacao_y = 273;
		case 48:
			pais->nome = "San Marino";
			pais->localizacao_x = 397;
			pais->localizacao_y = 377;
			break;
		case 49:
			pais->nome = "Sérvia";
			pais->localizacao_x = 440;
			pais->localizacao_y = 362;
			break;
		case 50:
			pais->nome = "Suécia";
			pais->localizacao_x = 418;
			pais->localizacao_y = 253;
			break;
		case 51:
			pais->nome = "Suíça";
			pais->localizacao_x = 372;
			pais->localizacao_y = 354;
			break;
		case 52:
			pais->nome = "Turquia";
			pais->localizacao_x = 503;
			pais->localizacao_y = 402;
			break;
		case 53:
			pais->nome = "Ucrânia";
			pais->localizacao_x = 494;
			pais->localizacao_y = 321;
			break;
		}
		break;
	case ASIA:
		switch (destino) {
		case 1:
			pais->nome = "Afeganistão";
			pais->localizacao_x = 281;
			pais->localizacao_y = 429;
			break;
		case 2:
			pais->nome = "Arábia Saudita";
			pais->localizacao_x = 170;
			pais->localizacao_y = 506;
			break;
		case 3:
			pais->nome = "Armênia";
			pais->localizacao_x = 136;
			pais->localizacao_y = 393;
			break;
		case 4:
			pais->nome = "Azerbaijão";
			pais->localizacao_x = 165;
			pais->localizacao_y = 391;
			break;
		case 5:
			pais->nome = "Bangladesh";
			pais->localizacao_x = 418;
			pais->localizacao_y = 498;
			break;
		case 6:
			pais->nome = "Emirados Árabes";
			pais->localizacao_x = 208;
			pais->localizacao_y = 503;
		case 7:
			pais->nome = "Brunei";
			pais->localizacao_x = 582;
			pais->localizacao_y = 620;
			break;
		case 8:
			pais->nome = "Butão";
			pais->localizacao_x = 408;
			pais->localizacao_y = 470;
			break;
		case 9:
			pais->nome = "Camboja";
			pais->localizacao_x = 512;
			pais->localizacao_y = 573;
			break;
		case 10:
			pais->nome = "Cazaquistão";
			pais->localizacao_x = 276;
			pais->localizacao_y = 291;
			break;
		case 11:
			pais->nome = "Chipre";
			pais->localizacao_x = 77;
			pais->localizacao_y = 434;
			break;
		case 12:
			pais->nome = "Coréia do Norte";
			pais->localizacao_x = 588;
			pais->localizacao_y = 360;
			break;
		case 13:
			pais->nome = "Coréia do Sul";
			pais->localizacao_x = 611;
			pais->localizacao_y = 391;
			break;
		case 14:
			pais->nome = "Filipinas";
			pais->localizacao_x = 611;
			pais->localizacao_y = 544;
			break;
		case 15:
			pais->nome = "Índia";
			pais->localizacao_x = 336;
			pais->localizacao_y = 463;
			break;
		case 16:
			pais->nome = "Indonésia";
			pais->localizacao_x = 665;
			pais->localizacao_y = 676;
			break;
		case 17:
			pais->nome = "Irã";
			pais->localizacao_x = 182;
			pais->localizacao_y = 427;
			break;
		case 18:
			pais->nome = "Iraque";
			pais->localizacao_x = 140;
			pais->localizacao_y = 442;
			break;
		case 19:
			pais->nome = "Japão";
			pais->localizacao_x = 679;
			pais->localizacao_y = 371;
			break;
		case 20:
			pais->nome = "Laos";
			pais->localizacao_x = 494;
			pais->localizacao_y = 525;
			break;
		case 21:
			pais->nome = "Maldivas";
			pais->localizacao_x = 325;
			pais->localizacao_y = 624;
			break;
		case 22:
			pais->nome = "Mongólia";
			pais->localizacao_x = 468;
			pais->localizacao_y = 306;
			break;
		case 23:
			pais->nome = "Nepal";
			pais->localizacao_x = 382;
			pais->localizacao_y = 469;
			break;
		case 24:
			pais->nome = "Paquistão";
			pais->localizacao_x = 303;
			pais->localizacao_y = 438;
			break;
		case 25:
			pais->nome = "Quirguistão";
			pais->localizacao_x = 298;
			pais->localizacao_y = 369;
			break;
		case 26:
			pais->nome = "Rússia";
			pais->localizacao_x = 96;
			pais->localizacao_y = 274;
			break;
		case 27:
			pais->nome = "Sri Lanka";
			pais->localizacao_x = 377;
			pais->localizacao_y = 607;
			break;
		case 28:
			pais->nome = "Tailândia";
			pais->localizacao_x = 487;
			pais->localizacao_y = 558;
			break;
		case 29:
			pais->nome = "Tajiquistão";
			pais->localizacao_x = 279;
			pais->localizacao_y = 396;
			break;
		case 30:
			pais->nome = "Síria";
			pais->localizacao_x = 107;
			pais->localizacao_y = 434;
			break;
		case 31:
			pais->nome = "Turquemenistao";
			pais->localizacao_x = 221;
			pais->localizacao_y = 403;
			break;
		case 32:
			pais->nome = "Turquia";
			pais->localizacao_x = 68;
			pais->localizacao_y = 403;
			break;
		case 33:
			pais->nome = "Uzbequistão";
			pais->localizacao_x = 265;
			pais->localizacao_y = 382;
			break;
		case 34:
			pais->nome = "Vietnã";
			pais->localizacao_x = 508;
			pais->localizacao_y = 508;
			break;
		case 35:
			pais->nome = "Omã";
			pais->localizacao_x = 230;
			pais->localizacao_y = 510;
			break;
		case 36:
			pais->nome = "Catar";
			pais->localizacao_x = 193;
			pais->localizacao_y = 492;
			break;
		case 37:
			pais->nome = "Iêmen";
			pais->localizacao_x = 157;
			pais->localizacao_y = 562;
			break;
		case 38:
			pais->nome = "Jordânia";
			pais->localizacao_x = 100;
			pais->localizacao_y = 461;
			break;
		case 39:
			pais->nome = "Kuwait";
			pais->localizacao_x = 166;
			pais->localizacao_y = 469;
			break;
		case 40:
			pais->nome = "Singapura";
			pais->localizacao_x = 513;
			pais->localizacao_y = 646;
			break;
		case 41:
			pais->nome = "Taiwan";
			pais->localizacao_x = 595;
			pais->localizacao_y = 477;
			break;
		}
		break;
	case OCEANIA:
		switch (destino) {
		case 1:
			pais->nome = "Austrália";
			pais->localizacao_x = 481;
			pais->localizacao_y = 404;
			break;
		case 2:
			pais->nome = "Ilhas Salomão";
			pais->localizacao_x = 574;
			pais->localizacao_y = 217;
			break;
		case 3:
			pais->nome = "Indonésia";
			pais->localizacao_x = 265;
			pais->localizacao_y = 201;
			break;
		case 4:
			pais->nome = "Nova Zelândia";
			pais->localizacao_x = 588;
			pais->localizacao_y = 521;
			break;
		case 5:
			pais->nome = "Papua-Nova Guiné";
			pais->localizacao_x = 503;
			pais->localizacao_y = 228;
			break;
		case 6:
			pais->nome = "Fiji";
			pais->localizacao_x = 725;
			pais->localizacao_y = 258;
			break;
		case 7:
			pais->nome = "Ilhas Marshall";
			pais->localizacao_x = 639;
			pais->localizacao_y = 171;
			break;
		case 8:
			pais->nome = "Kiribati";
			pais->localizacao_x = 693;
			pais->localizacao_y = 108;
			break;
		case 9:
			pais->nome = "Nauru";
			pais->localizacao_x = 646;
			pais->localizacao_y = 206;
			break;
		case 10:
			pais->nome = "Palau";
			pais->localizacao_x = 392;
			pais->localizacao_y = 144;
			break;
		case 11:
			pais->nome = "Samoa";
			pais->localizacao_x = 591;
			pais->localizacao_y = 334;
			break;
		case 12:
			pais->nome = "Vanuatu";
			pais->localizacao_x = 612;
			pais->localizacao_y = 277;
			break;				
		}
		break;
	}
	return pais;
}
