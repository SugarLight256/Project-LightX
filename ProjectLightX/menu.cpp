#include "DxLib.h"
#include "menu.h"
#include "gamenMgr.h"
#include "Key.h"

#define MENUTAG 4

extern int Key[256];
int SelectNum=0;
int menuGraph;



typedef struct{
        int x, y;
        char name[128];
} menuTag_t;

menuTag_t menuTag[MENUTAG]={
                { 120, 115, "�Q�[���X�^�[�g" }, 
                { 140, 150, "�R���t�B�O" },
				{ 140, 187, "�h�b�N" },
                { 140, 300, "�Q�[���I��" },
};

void menu_Syoki(){
	
	menuGraph=LoadGraph("img/menu.png");
}


void menu_Update(){
	KeyCalc();
    if(CheckHitKey(KEY_INPUT_G)!=0){
        gamenMgr_Change(0);
    }
    if(CheckHitKey(KEY_INPUT_C)!=0){
        gamenMgr_Change(1);
    }
    if(Key[KEY_INPUT_RETURN]==1){
    	if(SelectNum==0){
			gamenMgr_Change(0);
		}else if(SelectNum==1){
			gamenMgr_Change(1);
		}else if(SelectNum==2){
			gamenMgr_Change(2);	
		}else if(SelectNum==3){
			gamenMgr_Change(3);
		}
    }
}
 

void menu_Draw(){
	
	DrawGraph(0,0,menuGraph,TRUE);
	if( Key[ KEY_INPUT_UP ] == 1 && SelectNum >= 1){ // ��L�[�������ꂽ�u�Ԃ�������

			SelectNum = SelectNum - 1; // ���݂̑I�����ڂ����ɂ��炷(�t���[�v����)
	}
	if( Key[ KEY_INPUT_DOWN ] == 1 && SelectNum <= MENUTAG-2){ // ���L�[�������ꂽ�u�Ԃ�������
	
			SelectNum = SelectNum + 1; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
	}	
	if(Key[ KEY_INPUT_DOWN ] == 1 || Key[ KEY_INPUT_UP ] == 1){		
	    for( int i=0; i<MENUTAG; i++ ){              // ���j���[���ڐ��ł���5���[�v����
	        if( i == SelectNum ){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
				menuTag[i].x = 120; // ���W��80�ɂ���
			} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
   	       	 	menuTag[i].x = 140;// ���W��100�ɂ���
   	       	}
		}
	}
	
	for( int i=0; i<MENUTAG; i++ ){
		DrawFormatString( menuTag[i].x, menuTag[i].y, GetColor(180,60,230), menuTag[i].name );
	}
	
}