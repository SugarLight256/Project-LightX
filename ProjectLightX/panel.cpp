#include "DxLib.h"
#include "panel.h"

int panelGraph;

void panel_Syoki(){
	panelGraph=LoadGraph("img/panel.png");
}

void panel_Draw(){
	DrawGraph(-1,350,panelGraph,TRUE);
}
	