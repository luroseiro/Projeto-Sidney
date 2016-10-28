typedef struct avioes {
	int x;
	int y;
	int velocidade;
	int combustivel;
	int placar;
} AVIOES;
typedef struct destinos {
	char *nome;
	int localizacao_x;
	int localizacao_y;
} DESTINOS;

DESTINOS *iniciaDestinos(DESTINOS *pais, int destino) {
	/*switch (destino) {
	//Dificuldade 1
	case 1:
		pais->nome = "Canadá";
		pais->localizacao_x = 513;
		pais->localizacao_y = 341;
		break;
	case 2:
		pais->nome = "Estados Unidos da América";
		pais->localizacao_x = 474;
		pais->localizacao_y = 406;
		break;
	case 3:
		pais->nome = "México";
		pais->localizacao_x = 336;
		pais->localizacao_y = 519;
		break;
	case 4:
		pais->nome = "Caribe";
		pais->localizacao_x = 439;
		pais->localizacao_y = 505;
		break;
	case 5:
		pais->nome = "Porto Rico";
		pais->localizacao_x = 508;
		pais->localizacao_y = 533;
		break;
	case 6:
		pais->nome = "Costa Rica";
		pais->localizacao_x = 407;
		pais->localizacao_y = 585;
		break;
	case 7:
		pais->nome = "Honduras";
		pais->localizacao_x = 395;
		pais->localizacao_y = 554;
		break;
	case 8:
		pais->nome = "Argentina";
		pais->localizacao_x = 566;
		pais->localizacao_y = 854;
		break;
	case 9:
		pais->nome = "Bolívia";
		pais->localizacao_x = 500;
		pais->localizacao_y = 741;
		break;
	case 10:
		pais->nome = "Brasil";
		pais->localizacao_x = 609;
		pais->localizacao_y = 750;
		break;
	case 11:
		pais->nome = "Chile";
		pais->localizacao_x = 497;
		pais->localizacao_y = 833;
		break;
	case 12:
		pais->nome = "Colômbia";
		pais->localizacao_x = 463;
		pais->localizacao_y = 610;
		break;
	case 13:
		pais->nome = "Equador";
		pais->localizacao_x = 437;
		pais->localizacao_y = 649;
		break;
	case 14:
		pais->nome = "Paraguai";
		pais->localizacao_x = 563;
		pais->localizacao_y = 786;
		break;
	case 15:
		pais->nome = "Peru";
		pais->localizacao_x = 451;
		pais->localizacao_y = 716;
		break;
	case 16:
		pais->nome = "Uruguai";
		pais->localizacao_x = 576;
		pais->localizacao_y = 840;
		break;
	case 17:
		pais->nome = "Venezuela";
		pais->localizacao_x = 496;
		pais->localizacao_y = 580;
		break;
	case 18:
		pais->nome = "África do Sul";
		pais->localizacao_x = 1003;
		pais->localizacao_y = 786;
		break;
	case 19:
		pais->nome = "Camarões";
		pais->localizacao_x = 920;
		pais->localizacao_y = 620;
		break;
	case 20:
		pais->nome = "Costa do Marfim";
		pais->localizacao_x = 830;
		pais->localizacao_y = 605;
		break;
	case 21:
		pais->nome = "Egito";
		pais->localizacao_x = 1034;
		pais->localizacao_y = 546;
		break;
	case 22:
		pais->nome = "Gana";
		pais->localizacao_x = 856;
		pais->localizacao_y = 609;
		break;
	case 23:
		pais->nome = "Líbia";
		pais->localizacao_x = 925;
		pais->localizacao_y = 454;
		break;
	case 24:
		pais->nome = "Madagascar";
		pais->localizacao_x = 1110;
		pais->localizacao_y = 742;
		break;
	case 25:
		pais->nome = "Marrocos";
		pais->localizacao_x = 825;
		pais->localizacao_y = 450;
		break;
	case 26:
		pais->nome = "Moçambique";
		pais->localizacao_x = 1035;
		pais->localizacao_y = 782;
		break;
	case 27:
		pais->nome = "Nigéria";
		pais->localizacao_x = 895;
		pais->localizacao_y = 591;
		break;
	case 28:
		pais->nome = "Senegal";
		pais->localizacao_x = 768;
		pais->localizacao_y = 558;
		break;
	case 29:
		pais->nome = "Somália";
		pais->localizacao_x = 1095;
		pais->localizacao_y = 635;
		break;
	case 30:
		pais->nome = "Austrália";
		pais->localizacao_x = 1606;
		pais->localizacao_y = 899;
		break;
	case 31:
		pais->nome = "Nova Zelândia";
		pais->localizacao_x = 1725;
		pais->localizacao_y = 970;
		break;
	case 32:
		pais->nome = "Arábia Saudita";
		pais->localizacao_x = 1104;
		pais->localizacao_y = 510;
		break;
	case 33:
		pais->nome = "Bangladesh";
		pais->localizacao_x = 1331;
		pais->localizacao_y = 501;
		break;
	case 34:
		pais->nome = "Coréia do Norte";
		pais->localizacao_x = 1483;
		pais->localizacao_y = 370;
		break;
	case 35:
		pais->nome = "Coréia do Sul";
		pais->localizacao_x = 1494;
		pais->localizacao_y = 389;
		break;
	case 36:
		pais->nome = "Indonésia";
		pais->localizacao_x = 1430;
		pais->localizacao_y = 681;
		break;
	case 37:
		pais->nome = "Índia";
		pais->localizacao_x = 1249;
		pais->localizacao_y = 480;
		break;
	case 38:
		pais->nome = "Irã";
		pais->localizacao_x = 1120;
		pais->localizacao_y = 434;
		break;
	case 39:
		pais->nome = "Iraque";
		pais->localizacao_x = 1083;
		pais->localizacao_y = 454;
		break;
	case 40:
		pais->nome = "Japão";
		pais->localizacao_x = 1558;
		pais->localizacao_y = 393;
		break;
	case 41:
		pais->nome = "Paquistão";
		pais->localizacao_x = 1229;
		pais->localizacao_y = 441;
		break;
	case 42:
		pais->nome = "Rússia";
		pais->localizacao_x = 1014;
		pais->localizacao_y = 285;
		break;
	case 43:
		pais->nome = "Tailândia";
		pais->localizacao_x = 1392;
		pais->localizacao_y = 551;
		break;
	case 44:
		pais->nome = "Turquia";
		pais->localizacao_x = 1016;
		pais->localizacao_y = 405;
		break;
	case 45:
		pais->nome = "Uzbequistão";
		pais->localizacao_x = 1181;
		pais->localizacao_y = 395;
		break;
	case 46:
		pais->nome = "Vietnã";
		pais->localizacao_x = 1415;
		pais->localizacao_y = 505;
		break;
	case 47:
		pais->nome = "Alemanha";
		pais->localizacao_x = 919;
		pais->localizacao_y = 325;
		break;
	case 48:
		pais->nome = "Áustria";
		pais->localizacao_x = 933;
		pais->localizacao_y = 357;
		break;
	case 49:
		pais->nome = "Dinamarca";
		pais->localizacao_x = 911;
		pais->localizacao_y = 304;
		break;
	case 50:
		pais->nome = "Espanha";
		pais->localizacao_x = 842;
		pais->localizacao_y = 410;
		break;
	case 51:
		pais->nome = "Finlândia";
		pais->localizacao_x = 966;
		pais->localizacao_y = 259;
		break;
	case 52:
		pais->nome = "França";
		pais->localizacao_x = 876;
		pais->localizacao_y = 355;
		break;
	case 53:
		pais->nome = "Grécia";
		pais->localizacao_x = 974;
		pais->localizacao_y = 421;
		break;
	case 54:
		pais->nome = "Itália";
		pais->localizacao_x = 924;
		pais->localizacao_y = 401;
		break;
	case 55:
		pais->nome = "Noruega";
		pais->localizacao_x = 901;
		pais->localizacao_y = 272;
		break;
	case 56:
		pais->nome = "Holanda";
		pais->localizacao_x = 880;
		pais->localizacao_x = 326;
		break;
	case 57:
		pais->nome = "Polônia";
		pais->localizacao_x = 963;
		pais->localizacao_y = 327;
		break;
	case 58:
		pais->nome = "Portugal";
		pais->localizacao_x = 813;
		pais->localizacao_y = 422;
		break;
	case 59:
		pais->nome = "Inglaterra";
		pais->localizacao_x = 861;
		pais->localizacao_y = 331;
		break;
	case 60:
		pais->nome = "Suécia";
		pais->localizacao_x = 939;
		pais->localizacao_y = 267;
		break;
	//Dificuldade 2
	case 61:
		pais->nome = "Bahamas";
		pais->localizacao_x = 452;
		pais->localizacao_y = 495;
		break;
	case 62:
		pais->nome = "El Salvador";
		pais->localizacao_x = 387;
		pais->localizacao_y = 558;
		break;
	case 63:
		pais->nome = "Guatemala";
		pais->localizacao_x = 380;
		pais->localizacao_y = 549;
		break;
	case 64:
		pais->nome = "Nicarágua";
		pais->localizacao_x = 400;
		pais->localizacao_y = 567;
		break;
	case 65:
		pais->nome = "Panamá";
		pais->localizacao_x = 419;
		pais->localizacao_y = 591;
		break;
	case 66:
		pais->nome = "Guiana";
		pais->localizacao_x = 544;
		pais->localizacao_y = 605;
		break;
	case 67:
		pais->nome = "Suriname";
		pais->localizacao_x = 561;
		pais->localizacao_y = 612;
		break;
	case 68:
		pais->nome = "Angola";
		pais->localizacao_x = 932;
		pais->localizacao_y = 692;
		break;
	case 69:
		pais->nome = "Cabo Verde";
		pais->localizacao_x = 738;
		pais->localizacao_y = 563;
		break;
	case 70:
		pais->nome = "Etiópia";
		pais->localizacao_x = 1059;
		pais->localizacao_y = 590;
		break;
	case 71:
		pais->nome = "Guiné";
		pais->localizacao_x = 782;
		pais->localizacao_y = 588;
		break;
	case 72:
		pais->nome = "Guiné-Bissau";
		pais->localizacao_x = 776;
		pais->localizacao_y = 575;
		break;
	case 73:
		pais->nome = "Guiné Equatorial";
		pais->localizacao_x = 905;
		pais->localizacao_y = 623;
		break;
	case 74:
		pais->nome = "Lesoto";
		pais->localizacao_x = 1004;
		pais->localizacao_y = 807;
		break;
	case 75:
		pais->nome = "Mauritânia";
		pais->localizacao_x = 772;
		pais->localizacao_y = 539;
		break;
	case 76:
		pais->nome = "Níger";
		pais->localizacao_x = 876;
		pais->localizacao_y = 562;
		break;
	case 77:
		pais->nome = "Quênia";
		pais->localizacao_x = 1060;
		pais->localizacao_y = 644;
		break;
	case 78:
		pais->nome = "República do Congo";
		pais->localizacao_x = 939;
		pais->localizacao_y = 660;
		break;
	case 79:
		pais->nome = "São Tomé e Príncipe";
		pais->localizacao_x = 898;
		pais->localizacao_y = 634;
		break;
	case 80:
		pais->nome = "Sudão";
		pais->localizacao_x = 1032;
		pais->localizacao_y = 547;
		break;
	case 81:
		pais->nome = "Sudão do Sul";
		pais->localizacao_x = 1027;
		pais->localizacao_y = 604;
		break;
	case 82:
		pais->nome = "Tanzânia";
		pais->localizacao_x = 1069;
		pais->localizacao_y = 684;
		break;
	case 83:
		pais->nome = "Togo";
		pais->localizacao_x = 865;
		pais->localizacao_y = 605;
		break;
	case 84:
		pais->nome = "Zâmbia";
		pais->localizacao_x = 1002;
		pais->localizacao_y = 725;
		break;
	case 85:
		pais->nome = "Zimbabwe";
		pais->localizacao_x = 1017;
		pais->localizacao_y = 742;
		break;
	case 86:
		pais->nome = "Papua-Nova Guiné";
		pais->localizacao_x = 1648;
		pais->localizacao_y = 714;
		break;
	case 87:
		pais->nome = "Omã";
		pais->localizacao_x = 1167;
		pais->localizacao_y = 508;
		break;
	case 88:
		pais->nome = "Afeganistão";
		pais->localizacao_x = 1206;
		pais->localizacao_y = 440;
		break;
	case 89:
		pais->nome = "Azerbaijão";
		pais->localizacao_x = 1101;
		pais->localizacao_y = 401;
		break;
	case 90:
		pais->nome = "Camboja";
		pais->localizacao_x = 1416;
		pais->localizacao_y = 564;
		break;
	case 91:
		pais->nome = "Filipinas";
		pais->localizacao_x = 1505;
		pais->localizacao_y = 545;
		break;
	case 92:
		pais->nome = "Geórgia";
		pais->localizacao_x = 1061;
		pais->localizacao_y = 391;
		break;
	case 93:
		pais->nome = "Maldivas";
		pais->localizacao_x = 1251;
		pais->localizacao_y = 621;
		break;
	case 94:
		pais->nome = "Mongólia";
		pais->localizacao_x = 1374;
		pais->localizacao_y = 325;
		break;
	case 95:
		pais->nome = "Nepal";
		pais->localizacao_x = 1297;
		pais->localizacao_y = 468;
		break;
	case 96:
		pais->nome = "Quirguistão";
		pais->localizacao_x = 1224;
		pais->localizacao_y = 379;
		break;
	case 97:
		pais->nome = "Sri Lanka";
		pais->localizacao_x = 1290;
		pais->localizacao_y = 594;
		break;
	case 98:
		pais->nome = "Albânia";
		pais->localizacao_x = 958;
		pais->localizacao_y = 403;
		break;
	case 99:
		pais->nome = "Armênia";
		pais->localizacao_x = 1078;
		pais->localizacao_y = 405;
		break;
	case 100:
		pais->nome = "Bélgica";
		pais->localizacao_x = 880;
		pais->localizacao_y = 336;
		break;
	case 101:
		pais->nome = "Bulgária";
		pais->localizacao_x = 972;
		pais->localizacao_y = 390;
		break;
	case 102:
		pais->nome = "Cazaquistão";
		pais->localizacao_x = 1208;
		pais->localizacao_y = 327;
		break;
	case 103:
		pais->nome = "República Tcheca";
		pais->localizacao_x = 929;
		pais->localizacao_y = 342;
		break;
	case 104:
		pais->nome = "Croácia";
		pais->localizacao_x = 934;
		pais->localizacao_y = 379;
		break;
	case 105:
		pais->nome = "Eslováquia";
		pais->localizacao_x = 948;
		pais->localizacao_y = 352;
		break;
	case 106:
		pais->nome = "Eslovênia";
		pais->localizacao_x = 928;
		pais->localizacao_y = 369;
		break;
	case 107:
		pais->nome = "Hungria";
		pais->localizacao_x = 954;
		pais->localizacao_y = 363;
		break;
	case 108:
		pais->nome = "Irlanda";
		pais->localizacao_x = 827;
		pais->localizacao_y = 323;
		break;
	case 109:
		pais->nome = "Islândia";
		pais->localizacao_x = 777;
		pais->localizacao_y = 241;
		break;
	case 110:
		pais->nome = "Luxemburgo";
		pais->localizacao_x = 893;
		pais->localizacao_y = 345;
		break;
	case 111:
		pais->nome = "Mônaco";
		pais->localizacao_x = 896;
		pais->localizacao_y = 386;
		break;
	case 112:
		pais->nome = "Escócia";
		pais->localizacao_x = 847;
		pais->localizacao_y = 301;
		break;
	case 113:
		pais->nome = "Irlanda do Norte";
		pais->localizacao_x = 830;
		pais->localizacao_y = 310;
		break;
	case 114:
		pais->nome = "Sérvia";
		pais->localizacao_x = 943;
		pais->localizacao_y = 375;
		break;
	case 115:
		pais->nome = "Suíça";
		pais->localizacao_x = 895;
		pais->localizacao_y = 362;
		break;
	case 116:
		pais->nome = "Ucrânia";
		pais->localizacao_x = 1005;
		pais->localizacao_y = 333;
		break;
	case 117:
		pais->nome = "Guiana Francesa";
		pais->localizacao_x = 579;
		pais->localizacao_y = 615;
		break;
	//Dificuldade 3
	case 118:
		pais->nome = "Belize";
		pais->localizacao_x = 390;
		pais->localizacao_y = 537;
		break;
	case 119:
		pais->nome = "Argélia";
		pais->localizacao_x = 876;
		pais->localizacao_y = 432;
		break;
	case 120:
		pais->nome = "Benim";
		pais->localizacao_x = 871;
		pais->localizacao_y = 600;
		break;
	case 121:
		pais->nome = "Botswana";
		pais->localizacao_x = 991;
		pais->localizacao_y = 773;
		break;
	case 122:
		pais->nome = "Burkina Faso";
		pais->localizacao_x = 852;
		pais->localizacao_y = 571;
		break;
	case 123:
		pais->nome = "Burundi";
		pais->localizacao_x = 1018;
		pais->localizacao_y = 659;
		break;
	case 124:
		pais->nome = "Chade";
		pais->localizacao_x = 943;
		pais->localizacao_y = 579;
		break;
	case 125:
		pais->nome = "Comores";
		pais->localizacao_x = 1098;
		pais->localizacao_y = 704;
		break;
	case 126:
		pais->nome = "Djibouti";
		pais->localizacao_x = 1087;
		pais->localizacao_y = 572;
		break;
	case 127:
		pais->nome = "Eritreia";
		pais->localizacao_x = 1064;
		pais->localizacao_y = 552;
		break;
	case 128:
		pais->nome = "Gabão";
		pais->localizacao_x = 910;
		pais->localizacao_y = 641;
		break;
	case 129:
		pais->nome = "Gâmbia";
		pais->localizacao_x = 774;
		pais->localizacao_y = 566;
		break;
	case 130:
		pais->nome = "Libéria";
		pais->localizacao_x = 800;
		pais->localizacao_y = 607;
		break;
	case 131:
		pais->nome = "Malawi";
		pais->localizacao_x = 1042;
		pais->localizacao_y = 707;
		break;
	case 132:
		pais->nome = "Mali";
		pais->localizacao_x = 819;
		pais->localizacao_y = 567;
		break;
	case 133:
		pais->nome = "Maurícia";
		pais->localizacao_x = 1162;
		pais->localizacao_y = 760;
		break;
	case 134:
		pais->nome = "Namíbia";
		pais->localizacao_x = 946;
		pais->localizacao_y = 775;
		break;
	case 135:
		pais->nome = "República Centro-Africana";
		pais->localizacao_x = 956;
		pais->localizacao_y = 613;
		break;
	case 136:
		pais->nome = "Ruanda";
		pais->localizacao_x = 1020;
		pais->localizacao_y = 650;
		break;
	case 137:
		pais->nome = "Serra Leoa";
		pais->localizacao_x = 789;
		pais->localizacao_y = 595;
		break;
	case 138:
		pais->nome = "Seychelles";
		pais->localizacao_x = 1158;
		pais->localizacao_y = 665;
		break;
	case 139:
		pais->nome = "Suzilândia";
		pais->localizacao_x = 1023;
		pais->localizacao_y = 789;
		break;
	case 140:
		pais->nome = "Tunísia";
		pais->localizacao_x = 906;
		pais->localizacao_y = 426;
		break;
	case 141:
		pais->nome = "Uganda";
		pais->localizacao_x = 1031;
		pais->localizacao_y = 639;
		break;
	case 142:
		pais->nome = "Ilhas Salomão";
		pais->localizacao_x = 1711;
		pais->localizacao_y = 703;
		break;
	case 143:
		pais->nome = "Bahrein";
		pais->localizacao_x = 1115;
		pais->localizacao_y = 483;
		break;
	case 144:
		pais->nome = "Brunei";
		pais->localizacao_x = 1472;
		pais->localizacao_y = 611;
		break;
	case 145:
		pais->nome = "Butão";
		pais->localizacao_x = 1324;
		pais->localizacao_y = 470;
		break;
	case 146:
		pais->nome = "Chipre";
		pais->localizacao_x = 1024;
		pais->localizacao_y = 441;
		break;
	case 147:
		pais->nome = "Laos";
		pais->localizacao_x = 1397;
		pais->localizacao_y = 522;
		break;
	case 148:
		pais->nome = "Tajiquistão";
		pais->localizacao_x = 1202;
		pais->localizacao_y = 405;
		break;
	case 149:
		pais->nome = "Timor-Leste";
		pais->localizacao_x = 1502;
		pais->localizacao_y = 698;
		break;
	case 150:
		pais->nome = "Turquemenistao";
		pais->localizacao_x = 1166;
		pais->localizacao_y = 416;
		break;
	case 151:
		pais->nome = "Andorra";
		pais->localizacao_x = 868;
		pais->localizacao_y = 392;
		break;
	case 152:
		pais->nome = "Bielorrúsia";
		pais->localizacao_x = 991;
		pais->localizacao_y = 315;
		break;
	case 153:
		pais->nome = "Bósnia e Herzegovinia";
		pais->localizacao_x = 949;
		pais->localizacao_y = 384;
		break;
	case 154:
		pais->nome = "Estônia";
		pais->localizacao_x = 970;
		pais->localizacao_y = 273;
		break;
	case 155:
		pais->nome = "Kosovo";
		pais->localizacao_x = 963;
		pais->localizacao_y = 390;
		break;
	case 156:
		pais->nome = "Letônia";
		pais->localizacao_x = 973;
		pais->localizacao_y = 288;
		break;
	case 157:
		pais->nome = "Liechtenstein";
		pais->localizacao_x = 913;
		pais->localizacao_y = 360;
		break;
	case 158:
		pais->nome = "Lituânia";
		pais->localizacao_x = 974;
		pais->localizacao_y = 303;
		break;
	case 159:
		pais->nome = "Malta";
		pais->localizacao_x = 932;
		pais->localizacao_y = 438;
		break;
	case 160:
		pais->nome = "Moldávia";
		pais->localizacao_x = 994;
		pais->localizacao_y = 361;
		break;
	case 161:
		pais->nome = "Montenegro";
		pais->localizacao_x = 953;
		pais->localizacao_y = 392;
		break;
	case 162:
		pais->nome = "País de Gales";
		pais->localizacao_x = 845;
		pais->localizacao_y = 333;
		break;
	case 163:
		pais->nome = "Macedônia";
		pais->localizacao_x = 1400;
		pais->localizacao_y = 620;
		break;
	case 164:
		pais->nome = "Romênia";
		pais->localizacao_x = 984;
		pais->localizacao_y = 377;
		break;
	case 165:
		pais->nome = "San Marino";
		pais->localizacao_x = 917;
		pais->localizacao_y = 381;
		break;
	}
	return pais;*/
}
