	org $803
	
HelloWorld
	lsr (ZERO_PAGE),X
	lda #123
	sta $244
	lda ($00),Y
	lsr
	jmp HelloWorld
HelloAgain
	lda #1

