#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -Od -w- -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\ProjectLightX.exe
SRC1=X:\private\Programing\ProjectLightX-v2\load.cpp
OBJ1=Debug\load.obj
SRC2=X:\private\Programing\ProjectLightX-v2\main.cpp
OBJ2=Debug\main.obj
SRC3=X:\private\Programing\ProjectLightX-v2\doc.cpp
OBJ3=Debug\doc.obj
SRC4=X:\private\Programing\ProjectLightX-v2\config.cpp
OBJ4=Debug\config.obj
SRC5=X:\private\Programing\ProjectLightX-v2\game.cpp
OBJ5=Debug\game.obj
SRC6=X:\private\Programing\ProjectLightX-v2\gamenMgr.cpp
OBJ6=Debug\gamenMgr.obj
SRC7=X:\private\Programing\ProjectLightX-v2\icon.cpp
OBJ7=Debug\icon.obj
SRC8=X:\private\Programing\ProjectLightX-v2\map.cpp
OBJ8=Debug\map.obj
SRC9=X:\private\Programing\ProjectLightX-v2\menu.cpp
OBJ9=Debug\menu.obj
SRC10=X:\private\Programing\ProjectLightX-v2\enemy.cpp
OBJ10=Debug\enemy.obj
SRC11=X:\private\Programing\ProjectLightX-v2\player.cpp
OBJ11=Debug\player.obj
SRC12=X:\private\Programing\ProjectLightX-v2\Eshot.cpp
OBJ12=Debug\Eshot.obj
SRC13=X:\private\Programing\ProjectLightX-v2\Pshot.cpp
OBJ13=Debug\Pshot.obj
SRC14=X:\private\Programing\ProjectLightX-v2\EUnit.cpp
OBJ14=Debug\EUnit.obj
SRC15=X:\private\Programing\ProjectLightX-v2\PUnit.cpp
OBJ15=Debug\PUnit.obj
SRC16=X:\private\Programing\ProjectLightX-v2\PHP.cpp
OBJ16=Debug\PHP.obj
SRC17=X:\private\Programing\ProjectLightX-v2\coll.cpp
OBJ17=Debug\coll.obj
SRC18=X:\private\Programing\ProjectLightX-v2\panel.cpp
OBJ18=Debug\panel.obj
SRC19=X:\private\Programing\ProjectLightX-v2\Weapon.cpp
OBJ19=Debug\Weapon.obj
SRC20=X:\private\Programing\ProjectLightX-v2\Source.cpp
OBJ20=Debug\Source.obj
SRC21=X:\private\Programing\ProjectLightX-v2\Key.cpp
OBJ21=Debug\Key.obj
SRC22=X:\private\Programing\ProjectLightX-v2\save.cpp
OBJ22=Debug\save.obj
SRC23=X:\private\Programing\ProjectLightX-v2\class.cpp
OBJ23=Debug\class.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11) $(OBJ12) $(OBJ13) $(OBJ14) $(OBJ15) $(OBJ16) $(OBJ17) $(OBJ18) $(OBJ19) $(OBJ20) $(OBJ21) $(OBJ22) $(OBJ23)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11) $(OBJ12) $(OBJ13) $(OBJ14) $(OBJ15) $(OBJ16) $(OBJ17) $(OBJ18) $(OBJ19) $(OBJ20) $(OBJ21) $(OBJ22) $(OBJ23)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)

$(OBJ2): $(SRC2)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC2)

$(OBJ3): $(SRC3)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC3)

$(OBJ4): $(SRC4)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC4)

$(OBJ5): $(SRC5)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC5)

$(OBJ6): $(SRC6)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC6)

$(OBJ7): $(SRC7)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC7)

$(OBJ8): $(SRC8)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC8)

$(OBJ9): $(SRC9)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC9)

$(OBJ10): $(SRC10)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC10)

$(OBJ11): $(SRC11)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC11)

$(OBJ12): $(SRC12)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC12)

$(OBJ13): $(SRC13)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC13)

$(OBJ14): $(SRC14)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC14)

$(OBJ15): $(SRC15)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC15)

$(OBJ16): $(SRC16)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC16)

$(OBJ17): $(SRC17)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC17)

$(OBJ18): $(SRC18)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC18)

$(OBJ19): $(SRC19)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC19)

$(OBJ20): $(SRC20)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC20)

$(OBJ21): $(SRC21)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC21)

$(OBJ22): $(SRC22)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC22)

$(OBJ23): $(SRC23)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC23)
