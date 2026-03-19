	org $803
hellopeople
	lda #1 
	lda bytesec
	jmp hellopeople		
bytesec
	byte 20
	!include "testinclude.S"
