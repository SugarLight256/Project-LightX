#ifndef DEF_STRUCT_H
#define DEF_STRUCT_H
#define SHOT_MAX 200
#define UNIT_MAX 200
#define WEP_MAX  15
#define EQUIP_MAX 1
#define ITEM_MAX 10
//#define BOX_MAX 30

struct SHOTDATAP_t{//���̃w�b�_�[�t�@�C���ō\���̂�錾
	int MAXBall;
	int Ball;
    int damage;//�U����
    int type;//���
    int x;//x���W
    int y;//y���W
    double speedX;//����
	double speedY;
	double kaku;
	int Graph;
	int CanTime;
	int FM;//�~�T�C���̂��߂̃t���O
	int MTime;
    int flag;//�o����Ԃ̃t���O
};

struct SHOTDATAE_t{//���̃w�b�_�[�t�@�C���ō\���̂�錾
	int MAXBall;
	int Ball;
    int damage;//�U����
    int type;//���
    int x;//x���W
    int y;//y���W
    double speedX;//����
	double speedY;
	double kaku;
	int Graph;
	int CanTime;
    int flag;//�o����Ԃ̃t���O
};

struct PEQUIP_t{
	int x;
	int w;
	int y;
	int h;
	int flag;
	int type;
	int cool;
	int range;
	int rangeFlag;
	int bull;
	double kakudo;
	struct SHOTDATAP_t dataPS[SHOT_MAX];
};

struct EEQUIP_t{
	int x;
	int w;
	int y;
	int h;
	int flag;
	int type;
	int cool;
	int range;
	int rangeFlag;
	int bull;
	double kakudo;
	struct SHOTDATAE_t dataES[SHOT_MAX];
};

struct UNITDATAP_t{
    int type;//���
    int in_time;//�o������
	int w;//�摜�̕�
	int h;//�摜�̍���
    double x;//x���W
    double lx;//��t���[���O��X
    double y;//y���W
    double speed;//����
    int HP;//HP
	int MAXHP;
    int item;//�A�C�e��
    int range;//���G�͈�
    int flag;//�o����Ԃ̃t���O
    int rangeFlag;//���G�͈͓��ɓG�����邩
	int Ex;
	int Ey;
    int equip;//����
	int wepCool[WEP_MAX];
	struct PEQUIP_t PEquip[EQUIP_MAX];
};

struct UNITDATAE_t{
    int type;//���
    int in_time;//�o������
	int w;//�摜�̕�
	int h;//�摜�̍���
    double x;//x���W
    double lx;//��t���[���O��X
    double y;//y���W
    double speed;//����
    int HP;//HP
	int MAXHP;
    int item;//�A�C�e��
	int add;
    int range;//���G�͈�
    int flag;//�o����Ԃ̃t���O
    int rangeFlag;//���G�͈͓��ɓG�����邩
	int Px;
	int Py;
    int equip;//����
	int wepCool[WEP_MAX];
	struct EEQUIP_t EEquip[EQUIP_MAX];
};

struct  Weapon_t{
        int type;
		int x;
		int y;
};

struct SlotTag_t{
		int x,y;
        char name[32];
        int type;
		int defense;
		int bull;
		int range;
		int Graph;
		int flag;
		Weapon_t wep[WEP_MAX];
};

typedef struct{
        int x;
		int y;
        char name[128];
} docTag_t;

struct ITEMDATA_t{
	char name[64];
	int num;
	int damage;
	int type;
	int place;
};

#endif