#include "DxLib.h"
 
int Pspeed;//�v���C���[����
int Espeed;//�G
int PtamaX,PtamaY;//�e���W
int gamenX,gamenY;//�e��
int PX,EX;//�v���C���[X,�GX�iY�͌Œ�j
int cameraX;//��ʂ̍��W
int cam_idouryou;//��ʂ̈ړ��ʁiMAPX����)
 
 
void camera_calc(){
    cameraX+=cam_idouryou;
}
 
void Psyoki(){
    PX=0;
}
 
void Esyoki(){
    EX=1800;
} 
 
void cam_Move(){
	cam_idouryou=0;
    	if(CheckHitKey(KEY_INPUT_RIGHT)==1 && idouryou>0){
    	    cam_idouryou=-1;                  //��ʂ����ɓ�����
    	}else if(CheckHitKey(KEY_INPUT_LEFT)==1 && idouryou<1800){
    	    cam_idouryou=1;        //��ʂ��E�ɓ�����
    	}
}   	
 
void Map_Draw(){
    DrawGraph(0,0,"mapGraph",FALSE);
}
 
void Pcalc(){//�v�Z
    PX=PX+Pspeed;
}
 
void Ecalc(){
    EX=EX+Espeed;
}
    
 
void PDraw(){
    DrawGraph(PX+idouryou,210,PyotGraph,TRUE);
}
 
void EDraw(){
    DrawGraph(EX+idouryou,210,EyotGraph,TRUE);
}