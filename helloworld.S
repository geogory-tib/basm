	org $803
helloworld
	lda #$40 * 2 + 1 * 4
	jsr $FDED
	lda #$41 * 2 + 4 / 2 
	jsr $FDED
	lda #$42 + 1 * 4 + 2
	jsr $FDED
	lda #$43 + 2 * 2 / 2
	jsr $FDED
end_loop
	lda #2 + <6942
	lda #1 + >$6942
	lda #0
	beq end_loop	
