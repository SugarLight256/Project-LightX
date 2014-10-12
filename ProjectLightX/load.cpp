#include <stdio.h>
#include "doc.h"

extern struct SlotTag_t Box[BOX_MAX];

void BoxLoad(){

	FILE *fpr = fopen("Box.dat","rb");
	
	fread(&Box,sizeof(Box),1,fpr);
	
	fclose(fpr);

}