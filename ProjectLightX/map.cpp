#include "DxLib.h"
#include "map.h"
 
#define SHOT_MAX 200 
 
int Pspeed;//�v���C���[����
int Espeed;//�G
int PtamaX,PtamaY;//�e���W
int gamenX,gamenY;//�e��
int PX,EX;//�v���C���[X,�GX�iY�͌Œ�j
int cameraX;//��ʂ̍��W
int cam_idouryou;//��ʂ̈ړ��ʁiMAPX����j
int mapGraph;    //�}�b�v�摜
int mapX;        //�}�b�v�̍��\
 
 
void camera_calc(){
    cameraX=cameraX+cam_idouryou;
}

void map_calc(){
	mapX=mapX+cam_idouryou;
}

void Map_Syoki(){
	mapGraph=LoadGraph("img/stage.png");
}
 
void Psyoki(){
    PX=0;
}
 
void Esyoki(){
    EX=1800;
} 
 
void cam_Move(){                          //��ʂ̈ړ�
	cam_idouryou=0;
    	if(CheckHitKey(KEY_INPUT_RIGHT)==1 && mapX+1800 && mapX+1795 >=640){
    	    cam_idouryou=-5;                  //��ʂ����ɓ�����
    	}else if(CheckHitKey(KEY_INPUT_LEFT)==1 &&  mapX+5<=0){
    	    cam_idouryou=5;        //��ʂ��E�ɓ�����
    	}
}   	
 
void Map_Draw(){
    DrawGraph(mapX,0,mapGraph,FALSE);
}
 
    
 
void PDraw(int x,int y,int Graph){
    DrawGraph(x+cameraX,y,Graph,TRUE);//map��ɕ`�ʂ���̂�map�̍��W�𑫂��ĕԂ�
}
 
void EDraw(int x,int y,int Graph){
    DrawGraph(x+cameraX,y,Graph,TRUE);
}

int Stop(int x){
	x=x+cameraX;					//���`�ʂ��Ă�����W�𑫂��Ď~�܂��Ă���悤�ɕ`��
	return (x);
}

//int GetShotX(int i){
//	int j;
//	for(j=0;j>SHOT_MAX;j++){
//		return (dataP[i].dataPS[j].x);
//	}
//}

int DrawX(int x){
	return (x+cameraX);
}
	
	