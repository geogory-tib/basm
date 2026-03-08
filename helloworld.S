helloworld
	lda #$40
	jsr $FDED
	lda #$41
	jsr $FDED
	lda #$42
	jsr $FDED
	lda #$43
	jsr $FDED
	lda #0
	beq helloworld
