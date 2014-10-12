#pragma once 
#include "struct.h"

#define SLOT_MAX 11
#define BOX_MAX 21
#define F_DOCTAG 4
#define S_DOCTAG 5
#define SELECT_DOCTAG 5

void doc_GraphLoad();

void doc_BoxSelect();

void doc_Update();

void doc_Change(int docNext);

int doc_SlotMain();

void doc_Mgr();

void doc_Draw(int TAG,int x,int y,char name[128]);

void doc_Syoki();