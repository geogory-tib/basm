	lsr (ZERO_PAGE,X)
	lda #123
	sta $244
	lda ($00),Y
	lsr
	jmp HelloWorld
	lda #1

