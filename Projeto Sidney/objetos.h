enum CONTINENTES {AMERICACN, AMERICAS, AFRICA, EUROPA, ASIA, OCEANIA};

typedef struct avioes {
	int x;
	int y;
	int velocidade;
	double combustivel;
	double graus;
} AVIOES;
typedef struct destinos {
	char *nome;
	int localizacao_x;
	int localizacao_y;
	int continente;
} DESTINOS;

DESTINOS *iniciaPais(DESTINOS *pais, int destino) {
	switch (destino) {
	//americacn
	case 1:
		pais->nome = "Bahamas";
		pais->localizacao_x = 416;
		pais->localizacao_y = 531;
		pais->continente = AMERICACN;
		break;
	case 2:
		pais->nome = "Canadá";
		pais->localizacao_x = 464;
		pais->localizacao_y = 378;
		pais->continente = AMERICACN;
		break;
	case 3:
		pais->nome = "Estados Unidos";
		pais->localizacao_x = 431;
		pais->localizacao_y = 449;
		pais->continente = AMERICACN;
		break;
	case 4:
		pais->nome = "México";
		pais->localizacao_x = 274;
		pais->localizacao_y = 567;
		pais->continente = AMERICACN;
		break;
	case 5:
		pais->nome = "Cuba";
		pais->localizacao_x = 409;
		pais->localizacao_y = 570;
		pais->continente = AMERICACN;
		break;
	case 6:
		pais->nome = "Belize";
		pais->localizacao_x = 337;
		pais->localizacao_y = 590;
		pais->continente = AMERICACN;
		break;
	case 7:
		pais->nome = "Porto Rico";
		pais->localizacao_x = 468;
		pais->localizacao_y = 588;
		pais->continente = AMERICACN;
		break;
	case 8:
		pais->nome = "Costa Rica";
		pais->localizacao_x = 357;
		pais->localizacao_y = 642;
		pais->continente = AMERICACN;
		break;
	case 9:
		pais->nome = "El Salvador";
		pais->localizacao_x = 333;
		pais->localizacao_y = 618;
		pais->continente = AMERICACN;
		break;
	case 10:
		pais->nome = "Guatemala";
		pais->localizacao_x = 322;
		pais->localizacao_y = 605;
		pais->continente = AMERICACN;
		break;
	case 11:
		pais->nome = "Honduras";
		pais->localizacao_x = 343;
		pais->localizacao_y = 613;
		pais->continente = AMERICACN;
		break;
	case 12:
		pais->nome = "Nicarágua";
		pais->localizacao_x = 351;
		pais->localizacao_y = 627;
		pais->continente = AMERICACN;
		break;
	case 13:
		pais->nome = "Panamá";
		pais->localizacao_x = 384;
		pais->localizacao_y = 649;
		pais->continente = AMERICACN;
		break;
	case 14:
		pais->nome = "Haiti";
		pais->localizacao_x = 430;
		pais->localizacao_y = 589;
		pais->continente = AMERICACN;
		break;
	case 15:
		pais->nome = "República Dominicana";
		pais->localizacao_x = 446;
		pais->localizacao_y = 581;
		pais->continente = AMERICACN;
		break;
	//americas
	case 16:
		pais->nome = "Argentina";
		pais->localizacao_x = 450;
		pais->localizacao_y = 445;
		pais->continente = AMERICAS;
		break;
	case 17:
		pais->nome = "Bolívia";
		pais->localizacao_x = 363;
		pais->localizacao_y = 306;
		pais->continente = AMERICAS;
		break;
	case 18:
		pais->nome = "Brasil";
		pais->localizacao_x = 513;
		pais->localizacao_y = 295;
		pais->continente = AMERICAS;
		break;
	case 19:
		pais->nome = "Chile";
		pais->localizacao_x = 355;
		pais->localizacao_y = 423;
		pais->continente = AMERICAS;
		break;
	case 20:
		pais->nome = "Colômbia";
		pais->localizacao_x = 308;
		pais->localizacao_y = 117;
		pais->continente = AMERICAS;
		break;
	case 21:
		pais->nome = "Equador";
		pais->localizacao_x = 267;
		pais->localizacao_y = 175;
		pais->continente = AMERICAS;
		break;
	case 22:
		pais->nome = "Guiana";
		pais->localizacao_x = 426;
		pais->localizacao_y = 143;
		pais->continente = AMERICAS;
		break;
	case 23:
		pais->nome = "Guiana Francesa";
		pais->localizacao_x = 467;
		pais->localizacao_y = 133;
		pais->continente = AMERICAS;
		break;
	case 24:
		pais->nome = "Paraguai";
		pais->localizacao_x = 457;
		pais->localizacao_y = 362;
		pais->continente = AMERICAS;
		break;
	case 25:
		pais->nome = "Peru";
		pais->localizacao_x = 293;
		pais->localizacao_y = 272;
		pais->continente = AMERICAS;
		break;
	case 26:
		pais->nome = "Suriname";
		pais->localizacao_x = 446;
		pais->localizacao_y = 128;
		pais->continente = AMERICAS;
		break;
	case 27:
		pais->nome = "Uruguai";
		pais->localizacao_x = 473;
		pais->localizacao_y = 442;
		pais->continente = AMERICAS;
		break;
	case 28:
		pais->nome = "Venezuela";
		pais->localizacao_x = 365;
		pais->localizacao_y = 71;
		pais->continente = AMERICAS;
		break;
	//africa
	case 29:
		pais->nome = "África do Sul";
		pais->localizacao_x = 478;
		pais->localizacao_y = 581;
		pais->continente = AFRICA;
		break;
	case 30:
		pais->nome = "Angola";
		pais->localizacao_x = 371;
		pais->localizacao_y = 436;
		pais->continente = AFRICA;
		break;
	case 31:
		pais->nome = "Argélia";
		pais->localizacao_x = 285;
		pais->localizacao_y = 29;
		pais->continente = AFRICA;
		break;
	case 32:
		pais->nome = "Benim";
		pais->localizacao_x = 279;
		pais->localizacao_y = 292;
		pais->continente = AFRICA;
		break;
	case 33:
		pais->nome = "Botswana";
		pais->localizacao_x = 475;
		pais->localizacao_y = 553;
		pais->continente = AFRICA;
		break;
	case 34:
		pais->nome = "Burkina Faso";
		pais->localizacao_x = 247;
		pais->localizacao_y = 246;
		pais->continente = AFRICA;
		break;
	case 35:
		pais->nome = "Burundi";
		pais->localizacao_x = 506;
		pais->localizacao_y = 379;
		pais->continente = AFRICA;
		break;
	case 36:
		pais->nome = "Cabo Verde";
		pais->localizacao_x = 78;
		pais->localizacao_y = 224;
		pais->continente = AFRICA;
		break;
	case 37:
		pais->nome = "Camarões";
		pais->localizacao_x = 355;
		pais->localizacao_y = 320;
		pais->continente = AFRICA;
		break;
	case 38:
		pais->nome = "Chade";
		pais->localizacao_x = 390;
		pais->localizacao_y = 244;
		pais->continente = AFRICA;
		break;
	case 39:
		pais->nome = "Comores";
		pais->localizacao_x = 631;
		pais->localizacao_y = 450;
		pais->continente = AFRICA;
		break;
	case 40:
		pais->nome = "Costa do Marfim";
		pais->localizacao_x = 209;
		pais->localizacao_y = 297;
		pais->continente = AFRICA;
		break;
	case 41:
		pais->nome = "Djibouti";
		pais->localizacao_x = 615;
		pais->localizacao_y = 249;
		pais->continente = AFRICA;
		break;
	case 42:
		pais->nome = "Egito";
		pais->localizacao_x = 508;
		pais->localizacao_y = 89;
		pais->continente = AFRICA;
		break;
	case 43:
		pais->nome = "Eritreia";
		pais->localizacao_x = 574;
		pais->localizacao_y = 215;
		pais->continente = AFRICA;
		break;
	case 44:
		pais->nome = "Etiópia";
		pais->localizacao_x = 581;
		pais->localizacao_y = 272;
		pais->continente = AFRICA;
		break;
	case 45:
		pais->nome = "Gabão";
		pais->localizacao_x = 338;
		pais->localizacao_y = 348;
		pais->continente = AFRICA;
		break;
	case 46:
		pais->nome = "Gâmbia";
		pais->localizacao_x = 126;
		pais->localizacao_y = 236;
		pais->continente = AFRICA;
		break;
	case 47:
		pais->nome = "Gana";
		pais->localizacao_x = 258;
		pais->localizacao_y = 301;
		pais->continente = AFRICA;
		break;
	case 48:
		pais->nome = "Guiné";
		pais->localizacao_x = 148;
		pais->localizacao_y = 267;
		pais->continente = AFRICA;
		break;
	case 49:
		pais->nome = "Guiné-Bissau";
		pais->localizacao_x = 131;
		pais->localizacao_y = 252;
		pais->continente = AFRICA;
		break;
	case 50:
		pais->nome = "Guiné Equatorial";
		pais->localizacao_x = 330;
		pais->localizacao_y = 325;
		pais->continente = AFRICA;
		break;
	case 51:
		pais->nome = "Lesoto";
		pais->localizacao_x = 481;
		pais->localizacao_y = 611;
		pais->continente = AFRICA;
		break;
	case 52:
		pais->nome = "Libéria";
		pais->localizacao_x = 169;
		pais->localizacao_y = 298;
		pais->continente = AFRICA;
		break;
	case 53:
		pais->nome = "Líbia";
		pais->localizacao_x = 370;
		pais->localizacao_y = 65;
		pais->continente = AFRICA;
		break;
	case 54:
		pais->nome = "Madagascar";
		pais->localizacao_x = 651;
		pais->localizacao_y = 512;
		pais->continente = AFRICA;
		break;
	case 55:
		pais->nome = "Malawi";
		pais->localizacao_x = 543;
		pais->localizacao_y = 468;
		pais->continente = AFRICA;
		break;
	case 56:
		pais->nome = "Mali";
		pais->localizacao_x = 199;
		pais->localizacao_y = 240;
		pais->continente = AFRICA;
		break;
	case 57:
		pais->nome = "Marrocos";
		pais->localizacao_x = 208;
		pais->localizacao_y = 56;
		pais->continente = AFRICA;
		break;
	case 58:
		pais->nome = "Maurícia";
		pais->localizacao_x = 729;
		pais->localizacao_y = 536;
		pais->continente = AFRICA;
		break;
	case 59:
		pais->nome = "Mauritânia";
		pais->localizacao_x = 128;
		pais->localizacao_y = 196;
		pais->continente = AFRICA;
		break;
	case 60:
		pais->nome = "Moçambique";
		pais->localizacao_x = 532;
		pais->localizacao_y = 557;
		pais->continente = AFRICA;
		break;
	case 61:
		pais->nome = "Namíbia";
		pais->localizacao_x = 402;
		pais->localizacao_y = 552;
		pais->continente = AFRICA;
		break;
	case 62:
		pais->nome = "Níger";
		pais->localizacao_x = 286;
		pais->localizacao_y = 229;
		pais->continente = AFRICA;
		break;
	case 63:
		pais->nome = "Nigéria";
		pais->localizacao_x = 319;
		pais->localizacao_y = 283;
		pais->continente = AFRICA;
		break;
	case 64:
		pais->nome = "Quênia";
		pais->localizacao_x = 570;
		pais->localizacao_y = 362;
		pais->continente = AFRICA;
		break;
	case 65:
		pais->nome = "Rep. Centro-Africana";
		pais->localizacao_x = 417;
		pais->localizacao_y = 305;
		pais->continente = AFRICA;
		break;
	case 66:
		pais->nome = "Congo";
		pais->localizacao_x = 385;
		pais->localizacao_y = 381;
		pais->continente = AFRICA;
		break;
	case 67:
		pais->nome = "Ruanda";
		pais->localizacao_x = 509;
		pais->localizacao_y = 366;
		pais->continente = AFRICA;
		break;
	case 68:
		pais->nome = "São Tomé e Príncipe";
		pais->localizacao_x = 312;
		pais->localizacao_y = 351;
		pais->continente = AFRICA;
		break;
	case 69:
		pais->nome = "Senegal";
		pais->localizacao_x = 117;
		pais->localizacao_y = 226;
		pais->continente = AFRICA;
		break;
	case 70:
		pais->nome = "Serra Leoa";
		pais->localizacao_x = 146;
		pais->localizacao_y = 281;
		pais->continente = AFRICA;
		break;
	case 71:
		pais->nome = "Seychelles";
		pais->localizacao_x = 728;
		pais->localizacao_y = 403;
		pais->continente = AFRICA;
		break;
	case 72:
		pais->nome = "Somália";
		pais->localizacao_x = 631;
		pais->localizacao_y = 335;
		pais->continente = AFRICA;
		break;
	case 73:
		pais->nome = "Suzilândia";
		pais->localizacao_x = 513;
		pais->localizacao_y = 582;
		pais->continente = AFRICA;
		break;
	case 74:
		pais->nome = "Sudão";
		pais->localizacao_x = 513;
		pais->localizacao_y = 223;
		pais->continente = AFRICA;
		break;
	case 75:
		pais->nome = "Sudão do Sul";
		pais->localizacao_x = 525;
		pais->localizacao_y = 311;
		pais->continente = AFRICA;
		break;
	case 76:
		pais->nome = "Tanzânia";
		pais->localizacao_x = 583;
		pais->localizacao_y = 411;
		pais->continente = AFRICA;
		break;
	case 77:
		pais->nome = "Togo";
		pais->localizacao_x = 269;
		pais->localizacao_y = 396;
		pais->continente = AFRICA;
		break;
	case 78:
		pais->nome = "Tunísia";
		pais->localizacao_x = 335;
		pais->localizacao_y = 23;
		pais->continente = AFRICA;
		break;
	case 79:
		pais->nome = "Uganda";
		pais->localizacao_x = 532;
		pais->localizacao_y = 348;
		pais->continente = AFRICA;
		break;
	case 80:
		pais->nome = "Zâmbia";
		pais->localizacao_x = 479;
		pais->localizacao_y = 482;
		pais->continente = AFRICA;
		break;
	case 81:
		pais->nome = "Zimbabwe";
		pais->localizacao_x = 514;
		pais->localizacao_y = 509;
		pais->continente = AFRICA;
		break;
	//europa
	case 82:
		pais->nome = "Albânia";
		pais->localizacao_x = 418;
		pais->localizacao_y = 520;
		pais->continente = EUROPA;
		break;
	case 83:
		pais->nome = "Alemanha";
		pais->localizacao_x = 339;
		pais->localizacao_y = 360;
		pais->continente = EUROPA;
		break;
	case 84:
		pais->nome = "Andorra";
		pais->localizacao_x = 234;
		pais->localizacao_y = 500;
		pais->continente = EUROPA;
		break;
	case 85:
		pais->nome = "Armênia";
		pais->localizacao_x = 659;
		pais->localizacao_y = 523;
		pais->continente = EUROPA;
		break;
	case 86:
		pais->nome = "Áustria";
		pais->localizacao_x = 354;
		pais->localizacao_y = 428;
		pais->continente = EUROPA;
		break;
	case 87:
		pais->nome = "Azerbaijão";
		pais->localizacao_x = 721;
		pais->localizacao_y = 521;
		pais->continente = EUROPA;
		break;
	case 88:
		pais->nome = "Bélgica";
		pais->localizacao_x = 257;
		pais->localizacao_y = 386;
		pais->continente = EUROPA;
		break;
	case 89:
		pais->nome = "Bielorrúsia";
		pais->localizacao_x = 477;
		pais->localizacao_y = 334;
		pais->continente = EUROPA;
		break;
	case 90:
		pais->nome = "Bósnia e Herzegovina";
		pais->localizacao_x = 405;
		pais->localizacao_y = 483;
		pais->continente = EUROPA;
		break;
	case 91:
		pais->nome = "Bulgária";
		pais->localizacao_x = 453;
		pais->localizacao_y = 499;
		pais->continente = EUROPA;
		break;
	case 92:
		pais->nome = "Cazaquistão";
		pais->localizacao_x = 718;
		pais->localizacao_y = 314;
		pais->continente = EUROPA;
		break;
	case 93:
		pais->nome = "Rep. Tcheca";
		pais->localizacao_x = 353;
		pais->localizacao_y = 395;
		pais->continente = EUROPA;
		break;
	case 94:
		pais->nome = "Chipre";
		pais->localizacao_x = 558;
		pais->localizacao_y = 598;
		pais->continente = EUROPA;
		break;
	case 95:
		pais->nome = "Croácia";
		pais->localizacao_x = 378;
		pais->localizacao_y = 560;
		pais->continente = EUROPA;
		break;
	case 96:
		pais->nome = "Dinamarca";
		pais->localizacao_x = 324;
		pais->localizacao_y = 316;
		pais->continente = EUROPA;
		break;
	case 97:
		pais->nome = "Eslováquia";
		pais->localizacao_x = 388;
		pais->localizacao_y = 418;
		pais->continente = EUROPA;
		break;
	case 98:
		pais->nome = "Eslovênia";
		pais->localizacao_x = 358;
		pais->localizacao_y = 457;
		pais->continente = EUROPA;
		break;
	case 99:
		pais->nome = "Espanha";
		pais->localizacao_x = 183;
		pais->localizacao_y = 528;
		pais->continente = EUROPA;
		break;
	case 100:
		pais->nome = "Estônia";
		pais->localizacao_x = 451;
		pais->localizacao_y = 253;
		pais->continente = EUROPA;
		break;
	case 101:
		pais->nome = "Finlândia";
		pais->localizacao_x = 431;
		pais->localizacao_y = 235;
		pais->continente = EUROPA;
		break;
	case 102:
		pais->nome = "França";
		pais->localizacao_x = 241;
		pais->localizacao_y = 420;
		pais->continente = EUROPA;
		break;
	case 103:
		pais->nome = "Geórgia";
		pais->localizacao_x = 657;
		pais->localizacao_y = 500;
		pais->continente = EUROPA;
		break;
	case 104:
		pais->nome = "Grécia";
		pais->localizacao_x = 460;
		pais->localizacao_y = 560;
		pais->continente = EUROPA;
		break;
	case 105:
		pais->nome = "Hungria";
		pais->localizacao_x = 411;
		pais->localizacao_y = 433;
		pais->continente = EUROPA;
		break;
	case 106:
		pais->nome = "Irlanda";
		pais->localizacao_x = 129;
		pais->localizacao_y = 361;
		pais->continente = EUROPA;
		break;
	case 107:
		pais->nome = "Islândia";
		pais->localizacao_x = 31;
		pais->localizacao_y = 181;
		pais->continente = EUROPA;
		break;
	case 108:
		pais->nome = "Itália";
		pais->localizacao_x = 346;
		pais->localizacao_y = 510;
		pais->continente = EUROPA;
		break;
	case 109:
		pais->nome = "Kosovo";
		pais->localizacao_x = 422;
		pais->localizacao_y = 496;
		pais->continente = EUROPA;
		break;
	case 110:
		pais->nome = "Letônia";
		pais->localizacao_x = 445;
		pais->localizacao_y = 289;
		pais->continente = EUROPA;
		break;
	case 111:
		pais->nome = "Liechtenstein";
		pais->localizacao_x = 320;
		pais->localizacao_y = 440;
		pais->continente = EUROPA;
		break;
	case 112:
		pais->nome = "Lituânia";
		pais->localizacao_x = 444;
		pais->localizacao_y = 319;
		pais->continente = EUROPA;
		break;
	case 113:
		pais->nome = "Luxemburgo";
		pais->localizacao_x = 279;
		pais->localizacao_y = 405;
		pais->continente = EUROPA;
		break;
	case 114:
		pais->nome = "Malta";
		pais->localizacao_x = 471;
		pais->localizacao_y = 597;
		pais->continente = EUROPA;
		break;
	case 115:
		pais->nome = "Moldávia";
		pais->localizacao_x = 492;
		pais->localizacao_y = 432;
		pais->continente = EUROPA;
		break;
	case 116:
		pais->nome = "Mônaco";
		pais->localizacao_x = 291;
		pais->localizacao_y = 484;
		pais->continente = EUROPA;
		break;
	case 117:
		pais->nome = "Montenegro";
		pais->localizacao_x = 407;
		pais->localizacao_y = 500;
		pais->continente = EUROPA;
		break;
	case 118:
		pais->nome = "Noruega";
		pais->localizacao_x = 314;
		pais->localizacao_y = 243;
		pais->continente = EUROPA;
		break;
	case 119:
		pais->nome = "Holanda";
		pais->localizacao_x = 256;
		pais->localizacao_x = 368;
		pais->continente = EUROPA;
		break;
	case 120:
		pais->nome = "Polônia";
		pais->localizacao_x = 414;
		pais->localizacao_y = 367;
		pais->continente = EUROPA;
		break;
	case 121:
		pais->nome = "Portugal";
		pais->localizacao_x = 119;
		pais->localizacao_y = 557;
		pais->continente = EUROPA;
		break;
	case 122:
		pais->nome = "Inglaterra";
		pais->localizacao_x = 205;
		pais->localizacao_y = 377;
		pais->continente = EUROPA;
		break;
	case 123:
		pais->nome = "Escócia";
		pais->localizacao_x = 186;
		pais->localizacao_y = 307;
		pais->continente = EUROPA;
		break;
	case 124:
		pais->nome = "País de Gales";
		pais->localizacao_x = 173;
		pais->localizacao_y = 376;
		pais->continente = EUROPA;
		break;
	case 125:
		pais->nome = "Irlanda do Norte";
		pais->localizacao_x = 151;
		pais->localizacao_y = 333;
		pais->continente = EUROPA;
		break;
	case 126:
		pais->nome = "Macedônia";
		pais->localizacao_x = 433;
		pais->localizacao_y = 511;
		pais->continente = EUROPA;
		break;
	case 127:
		pais->nome = "Romênia";
		pais->localizacao_x = 471;
		pais->localizacao_y = 470;
		pais->continente = EUROPA;
		break;
	case 128:
		pais->nome = "San Marino";
		pais->localizacao_x = 339;
		pais->localizacao_y = 490;
		pais->continente = EUROPA;
		break;
	case 129:
		pais->nome = "Sérvia";
		pais->localizacao_x = 420;
		pais->localizacao_y = 460;
		pais->continente = EUROPA;
		break;
	case 130:
		pais->nome = "Suécia";
		pais->localizacao_x = 396;
		pais->localizacao_y = 242;
		pais->continente = EUROPA;
		break;
	case 131:
		pais->nome = "Suíça";
		pais->localizacao_x = 287;
		pais->localizacao_y = 441;
		pais->continente = EUROPA;
		break;
	case 132:
		pais->nome = "Turquia";
		pais->localizacao_x = 534;
		pais->localizacao_y = 536;
		pais->continente = EUROPA;
		break;
	case 133:
		pais->nome = "Ucrânia";
		pais->localizacao_x = 515;
		pais->localizacao_y = 378;
		pais->continente = EUROPA;
		break;
	//asia
	case 134:
		pais->nome = "Afeganistão";
		pais->localizacao_x = 281;
		pais->localizacao_y = 429;
		pais->continente = ASIA;
		break;
	case 135:
		pais->nome = "Arábia Saudita";
		pais->localizacao_x = 170;
		pais->localizacao_y = 506;
		pais->continente = ASIA;
		break;
	case 136:
		pais->nome = "Armênia";
		pais->localizacao_x = 136;
		pais->localizacao_y = 393;
		pais->continente = ASIA;
		break;
	case 137:
		pais->nome = "Azerbaijão";
		pais->localizacao_x = 165;
		pais->localizacao_y = 391;
		pais->continente = ASIA;
		break;
	case 138:
		pais->nome = "Bangladesh";
		pais->localizacao_x = 418;
		pais->localizacao_y = 498;
		pais->continente = ASIA;
		break;
	case 139:
		pais->nome = "Emirados Árabes";
		pais->localizacao_x = 208;
		pais->localizacao_y = 503;
		pais->continente = ASIA;
	case 140:
		pais->nome = "Brunei";
		pais->localizacao_x = 582;
		pais->localizacao_y = 620;
		pais->continente = ASIA;
		break;
	case 141:
		pais->nome = "Butão";
		pais->localizacao_x = 408;
		pais->localizacao_y = 470;
		pais->continente = ASIA;
		break;
	case 142:
		pais->nome = "Camboja";
		pais->localizacao_x = 512;
		pais->localizacao_y = 573;
		pais->continente = ASIA;
		break;
	case 143:
		pais->nome = "Cazaquistão";
		pais->localizacao_x = 276;
		pais->localizacao_y = 291;
		pais->continente = ASIA;
		break;
	case 144:
		pais->nome = "Chipre";
		pais->localizacao_x = 77;
		pais->localizacao_y = 434;
		pais->continente = ASIA;
		break;
	case 145:
		pais->nome = "Coréia do Norte";
		pais->localizacao_x = 588;
		pais->localizacao_y = 360;
		pais->continente = ASIA;
		break;
	case 146:
		pais->nome = "Coréia do Sul";
		pais->localizacao_x = 611;
		pais->localizacao_y = 391;
		pais->continente = ASIA;
		break;
	case 147:
		pais->nome = "Filipinas";
		pais->localizacao_x = 611;
		pais->localizacao_y = 544;
		pais->continente = ASIA;
		break;
	case 148:
		pais->nome = "Índia";
		pais->localizacao_x = 336;
		pais->localizacao_y = 463;
		pais->continente = ASIA;
		break;
	case 149:
		pais->nome = "Indonésia";
		pais->localizacao_x = 665;
		pais->localizacao_y = 676;
		pais->continente = ASIA;
		break;
	case 150:
		pais->nome = "Irã";
		pais->localizacao_x = 182;
		pais->localizacao_y = 427;
		pais->continente = ASIA;
		break;
	case 151:
		pais->nome = "Iraque";
		pais->localizacao_x = 140;
		pais->localizacao_y = 442;
		pais->continente = ASIA;
		break;
	case 152:
		pais->nome = "Japão";
		pais->localizacao_x = 679;
		pais->localizacao_y = 371;
		pais->continente = ASIA;
		break;
	case 153:
		pais->nome = "Laos";
		pais->localizacao_x = 494;
		pais->localizacao_y = 525;
		pais->continente = ASIA;
		break;
	case 154:
		pais->nome = "Maldivas";
		pais->localizacao_x = 325;
		pais->localizacao_y = 624;
		pais->continente = ASIA;
		break;
	case 155:
		pais->nome = "Mongólia";
		pais->localizacao_x = 468;
		pais->localizacao_y = 306;
		pais->continente = ASIA;
		break;
	case 156:
		pais->nome = "Nepal";
		pais->localizacao_x = 382;
		pais->localizacao_y = 469;
		pais->continente = ASIA;
		break;
	case 157:
		pais->nome = "Paquistão";
		pais->localizacao_x = 303;
		pais->localizacao_y = 438;
		pais->continente = ASIA;
		break;
	case 158:
		pais->nome = "Quirguistão";
		pais->localizacao_x = 298;
		pais->localizacao_y = 369;
		pais->continente = ASIA;
		break;
	case 159:
		pais->nome = "Rússia";
		pais->localizacao_x = 96;
		pais->localizacao_y = 274;
		pais->continente = ASIA;
		break;
	case 160:
		pais->nome = "Sri Lanka";
		pais->localizacao_x = 377;
		pais->localizacao_y = 607;
		pais->continente = ASIA;
		break;
	case 161:
		pais->nome = "Tailândia";
		pais->localizacao_x = 487;
		pais->localizacao_y = 558;
		pais->continente = ASIA;
		break;
	case 162:
		pais->nome = "Tajiquistão";
		pais->localizacao_x = 279;
		pais->localizacao_y = 396;
		pais->continente = ASIA;
		break;
	case 163:
		pais->nome = "Síria";
		pais->localizacao_x = 107;
		pais->localizacao_y = 434;
		pais->continente = ASIA;
		break;
	case 164:
		pais->nome = "Turquemenistão";
		pais->localizacao_x = 221;
		pais->localizacao_y = 403;
		pais->continente = ASIA;
		break;
	case 165:
		pais->nome = "Turquia";
		pais->localizacao_x = 68;
		pais->localizacao_y = 403;
		pais->continente = ASIA;
		break;
	case 166:
		pais->nome = "Uzbequistão";
		pais->localizacao_x = 265;
		pais->localizacao_y = 382;
		pais->continente = ASIA;
		break;
	case 167:
		pais->nome = "Vietnã";
		pais->localizacao_x = 508;
		pais->localizacao_y = 508;
		pais->continente = ASIA;
		break;
	case 168:
		pais->nome = "Omã";
		pais->localizacao_x = 230;
		pais->localizacao_y = 510;
		pais->continente = ASIA;
		break;
	case 169:
		pais->nome = "Catar";
		pais->localizacao_x = 193;
		pais->localizacao_y = 492;
		pais->continente = ASIA;
		break;
	case 170:
		pais->nome = "Iêmen";
		pais->localizacao_x = 157;
		pais->localizacao_y = 562;
		pais->continente = ASIA;
		break;
	case 171:
		pais->nome = "Jordânia";
		pais->localizacao_x = 100;
		pais->localizacao_y = 461;
		pais->continente = ASIA;
		break;
	case 172:
		pais->nome = "Kuwait";
		pais->localizacao_x = 166;
		pais->localizacao_y = 469;
		pais->continente = ASIA;
		break;
	case 173:
		pais->nome = "Singapura";
		pais->localizacao_x = 513;
		pais->localizacao_y = 646;
		pais->continente = ASIA;
		break;
	case 174:
		pais->nome = "Taiwan";
		pais->localizacao_x = 595;
		pais->localizacao_y = 477;
		pais->continente = ASIA;
		break;
	//oceania
	case 175:
		pais->nome = "Austrália";
		pais->localizacao_x = 516;
		pais->localizacao_y = 481;
		pais->continente = OCEANIA;
		break;
	case 176:
		pais->nome = "Ilhas Salomão";
		pais->localizacao_x = 574;
		pais->localizacao_y = 217;
		pais->continente = OCEANIA;
		break;
	case 177:
		pais->nome = "Indonésia";
		pais->localizacao_x = 235;
		pais->localizacao_y = 175;
		pais->continente = OCEANIA;
		break;
	case 178:
		pais->nome = "Nova Zelândia";
		pais->localizacao_x = 691;
		pais->localizacao_y = 532;
		pais->continente = OCEANIA;
		break;
	case 179:
		pais->nome = "Papua-Nova Guiné";
		pais->localizacao_x = 503;
		pais->localizacao_y = 228;
		pais->continente = OCEANIA;
		break;
	case 180:
		pais->nome = "Fiji";
		pais->localizacao_x = 725;
		pais->localizacao_y = 258;
		pais->continente = OCEANIA;
		break;
	case 181:
		pais->nome = "Ilhas Marshall";
		pais->localizacao_x = 639;
		pais->localizacao_y = 171;
		pais->continente = OCEANIA;
		break;
	case 182:
		pais->nome = "Kiribati";
		pais->localizacao_x = 693;
		pais->localizacao_y = 108;
		pais->continente = OCEANIA;
		break;
	case 183:
		pais->nome = "Nauru";
		pais->localizacao_x = 646;
		pais->localizacao_y = 206;
		pais->continente = OCEANIA;
		break;
	case 184:
		pais->nome = "Palau";
		pais->localizacao_x = 392;
		pais->localizacao_y = 205;
		pais->continente = OCEANIA;
		break;
	case 185:
		pais->nome = "Samoa";
		pais->localizacao_x = 591;
		pais->localizacao_y = 334;
		pais->continente = OCEANIA;
		break;
	case 186:
		pais->nome = "Vanuatu";
		pais->localizacao_x = 612;
		pais->localizacao_y = 277;
		pais->continente = OCEANIA;
		break;				
	}
	return pais;
}
