	org $803
!define hello 69
!define byte_val 255
hello_people
	lda #!hello
	jmp hello_people
byte_section
	byte 255
