#include "DxLib.h"
#include "gamenMgr.h"
#include "Key.h"
#include "doc.h"

int docSelectNum1;//�I��1
int docSelectNum2;//�I��2
int docSelectNum3;//�I��3
int docSelectNum4;//BoxSelect
int docSelectNum5;//SlotMain
int docSelectNum6;//SlotSelect
int docNow=-1; //���ݑI�𒆂̉��
int docReset=0;//�I���̃��Z�b�g�t���O
int docGraph;

int ShipSelect;//�I�����Ă���D

extern int PyotGraph,PikadaGraph,PkyakusenGraph;

extern int color[3];
extern int Key[256];

SlotTag_t Box[BOX_MAX];

SlotTag_t Slot[SLOT_MAX]={
				{ 60, 25, "Slot 1",1,1,100,150,PyotGraph,1},
				{ 80, 45, "Slot 2",2,1,100,150,PikadaGraph,1},
				{ 80, 65, "Slot 3",3,1,100,200,PkyakusenGraph,1},
				{ 80, 85, "Slot 4"},
				{ 80, 105, "Slot 5"},
				{ 80, 125, "Slot 6"},
				{ 80, 145, "Slot 7"},
				{ 80, 165, "Slot 8"},
				{ 80, 185, "Slot 9"},
				{ 80, 205, "Slot 10"},
				{ 80, 465, "�߂�"   },
};

docTag_t docTagShip[SELECT_DOCTAG]={
				{ 80, 100, "�J�X�^�}�C�Y"  },
				{ 100, 150, "�V�K�쐬"    },
				{ 100, 200, "�Z�b�g"      },
				{ 100, 250, "�폜"        },
				{ 100, 300, "�߂�"        },
};

docTag_t docTagFirst[F_DOCTAG]={
                { 80, 25, "����" }, 
                { 100, 75, "���b" },
				{ 100, 125, "�ݔ�" },
                { 100, 250, "�߂�" },
};

docTag_t docTagSecond[S_DOCTAG]={
				{ 80, 125, "�X���b�g1"  },
				{ 100, 150, "�X���b�g2"  },
				{ 100, 175, "�X���b�g3"  },
				{ 100, 200, "�X���b�g4"  },
				{ 100, 300, "�߂�"       },

};

struct ITEMDATA_t item[ITEM_MAX];


void doc_GraphLoad(){
	
	docGraph=LoadGraph("img/doc.png");
	
}

void doc_Change(int docNext){

	docNow=docNext;
	docGraph=LoadGraph("img/doc.png");
	
}

void doc_Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
		gamenMgr_Change(-1);
	}
}

int doc_Select(int TAG,int docSelectNum){
	KeyCalc();
	if(docSelectNum >= 1 && Key[KEY_INPUT_UP]%5 == 0 && Key[KEY_INPUT_UP]>=60 || Key[KEY_INPUT_UP]==1 && docSelectNum>= 1){ // ��L�[�������ꂽ�u�Ԃ�������

			docSelectNum = docSelectNum - 1; // ���݂̑I�����ڂ����ɂ��炷
	}
	if(docSelectNum <= TAG-2 && Key[KEY_INPUT_DOWN]%5 == 0 && Key[KEY_INPUT_DOWN]>=60 || Key[ KEY_INPUT_DOWN ] == 1 && docSelectNum <= TAG-2){ // ���L�[�������ꂽ�u�Ԃ�������
	
			docSelectNum = docSelectNum + 1; // ���݂̑I�����ڂ�����ɂ��炷
	}
	return docSelectNum;
}

int doc_Draw(int x,int i,int docSelectNum){
		if( i != docSelectNum ){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
			x = 100; // ���W��80�ɂ���
		} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
	       	x = 80;// ���W��100�ɂ���
		}
	return x;
}

void doc_First(){
	int i;
	doc_BoxSelect();
    for(i=0 ; i<F_DOCTAG ;i++){	
		docTagFirst[i].x=doc_Draw(docTagFirst[i].x ,i,docSelectNum1)+40;
		DrawFormatString( docTagFirst[i].x, docTagFirst[i].y, GetColor(30,100,40), docTagFirst[i].name );
	}
	docReset=0;

	if(Key[KEY_INPUT_RETURN]==1){
    	if(docSelectNum1==0){
			docNow=1;
			docReset=1;
			docSelectNum1=0;
		}else if(docSelectNum1==1){
			docNow=2;
		}else if(docSelectNum1==2){
			docNow=3;	
			docSelectNum1=0;
		}else if(docSelectNum1==3){
			docNow=0;
			docSelectNum1=0;
		}
    }
}

void Weapon_Set(int i,int k){
//	for(int j=0;j<UNIT_MAX;j++){	  //����̃A�C�e���\���̂���肻���SLOT�ɑ��
//	}
}

void doc_Weapon(){
	int i;

	for(i=0 ; i<S_DOCTAG ;i++){
		docTagSecond[i].x=doc_Draw(docTagSecond[i].x ,i,docSelectNum2);
		DrawFormatString( docTagSecond[i].x, docTagSecond[i].y, GetColor(30,100,40), docTagSecond[i].name );
    }
	docReset=0;

	if(Key[KEY_INPUT_RETURN]==1){
    	switch(docSelectNum2){
		case 1:
			Weapon_Set(docSelectNum1,1);
			break;
		case 2:
			Weapon_Set(docSelectNum1,2);
			break;
		case 3:
			Weapon_Set(docSelectNum1,3);
			break;
		}
			
    }		
}

void doc_ShipSelect(){
	int i;
	for(i=0 ; i<SELECT_DOCTAG ;i++){
		docTagShip[i].x=doc_Draw(docTagShip[i].x ,i,docSelectNum3);
		DrawFormatString( docTagShip[i].x, docTagShip[i].y, GetColor(30,100,40), docTagShip[i].name );
    }
	docReset=0;

	if(Key[KEY_INPUT_RETURN]==1){
    	if(docSelectNum3==0){
			docNow=0;
			docReset=1;
			docSelectNum3=0;
		}else if(docSelectNum3==1){
			//cmg soon
		}else if(docSelectNum3==2){
			docNow=4;
			docReset=1;
			docSelectNum3=0;	
		}else if(docSelectNum3==3){
			//cmg soon
		}else if(docSelectNum3==4){
			gamenMgr_Change(-1);
			docSelectNum3=0;
		}
    }		
}

void doc_BoxSelect(){
	int i;
	for(i=0 ; i<BOX_MAX ;i++){	
		Box[i].x=doc_Draw(Box[i].x ,i,docSelectNum4)-60;
		DrawFormatString( Box[i].x, Box[i].y, GetColor(30,100,40), Box[i].name );
    }
	docReset=0;
	if(Key[KEY_INPUT_RETURN]==1){
		if(docSelectNum4 != 20){
			docNow=1;
			docReset=1;
		}
		switch(docSelectNum4){
		case 0:
			ShipSelect=0;
			break;
		case 1:
			ShipSelect=1;
			break;
		case 2:
			ShipSelect=2;
			break;
		case 3:
			ShipSelect=3;
			break;
		case 4:
			ShipSelect=4;
			break;
		case 5:
			ShipSelect=5;
			break;
		case 6:
			ShipSelect=6;
			break;
		case 7:
			ShipSelect=7;
			break;
		case 8:
			ShipSelect=8;
			break;
		case 9:
			ShipSelect=9;
			break;
		case 10:
			ShipSelect=10;
			break;
		case 11:
			ShipSelect=11;
			break;
		case 12:
			ShipSelect=12;
			break;
		case 13:
			ShipSelect=13;
			break;
		case 14:
			ShipSelect=14;
			break;
		case 15:
			ShipSelect=15;
			break;
		case 16:
			ShipSelect=16;
			break;
		case 17:
			ShipSelect=17;
			break;
		case 18:
			ShipSelect=18;
			break;
		case 19:
			ShipSelect=19;
			break;
		case 20:
			docNow=-1;
			docReset=1;
			docSelectNum4=0;
			break;
		}
    }
}

void doc_Set(int S,int i){
	for(int j=0;j<WEP_MAX;j++){

	Slot[S].type   =Box[i].type;
	Slot[S].defense=Box[i].defense;
	Slot[S].bull   =Box[i].bull;
	Slot[S].range  =Box[i].range;
	Slot[S].Graph  =Box[i].Graph;
	Slot[S].flag   =Box[i].flag;
//	Slot[S].wep[3] =Box[i].wep[3];
	

	}
}

void doc_SlotSelect(){
	int i;
	doc_SlotMain();
	for(i=0 ; i<BOX_MAX ;i++){	
		Box[i].x=doc_Draw(Box[i].x ,i,docSelectNum6)+100;
		DrawFormatString ( Box[i].x, Box[i].y, GetColor(30,100,40), Box[i].name );
    }
	docReset=0;
	if(Key[KEY_INPUT_RETURN]==1){
		if(docSelectNum6 != 20){
			docNow=4;
			doc_Set(docSelectNum5,docSelectNum6);
		}else{
			docNow=4;
			docReset=1;
			docSelectNum6=0;
		}
    }
}

int doc_SlotMain(){
	int i;
	int SelectSlot;
	for(i=0 ; i<SLOT_MAX ;i++){
		Slot[i].x=doc_Draw(Slot[i].x ,i,docSelectNum5);
		DrawFormatString( Slot[i].x, Slot[i].y, GetColor(30,100,40), Slot[i].name );
    }
	docReset=0;
	if(Key[KEY_INPUT_RETURN]==1){
		if(docSelectNum5 != 10){
			docNow=5;
		}else{
			docNow=-1;
			docSelectNum5=0;
			docReset=1;
		}
    }	
}


void doc_Mgr(){

	DrawGraph(0,0,docGraph,TRUE);
	
	switch(docNow){           //�����ǉ�
		case -1:       //�J�X�^�}�C�Y ���� �V�K �I��
			docSelectNum3=doc_Select(SELECT_DOCTAG,docSelectNum3);
			doc_ShipSelect();
			break;
		case 0:               //�D�I��
			docSelectNum4=doc_Select(BOX_MAX,docSelectNum4);
			doc_BoxSelect();
			break;
		case 1:               //�J�X�^�}�C�Y�̑I��
			docSelectNum1=doc_Select(F_DOCTAG,docSelectNum1);
			doc_First();
			break;
		case 2:               //����
			docSelectNum2=doc_Select(S_DOCTAG,docSelectNum2);
			doc_Weapon();
			break;
		case 3:				  //�ݔ�
			break;
		case 4:
			docSelectNum5=doc_Select(SLOT_MAX,docSelectNum5);
			doc_SlotMain();
			break;
		case 5:
			docSelectNum6=doc_Select(BOX_MAX,docSelectNum6);
			doc_SlotSelect();
	}
}

void doc_Syoki(){
	doc_Change(-1);
	docSelectNum1=0;
	docSelectNum2=0;
	docSelectNum3=0;
	docSelectNum4=0;
	docSelectNum5=0;
	docSelectNum6=0;
	docReset=1;
}
