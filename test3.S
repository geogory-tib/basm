
    LDA #$12 + 3
	
    LDA $20 + 1
    LDA $20 + 2,X
    LDX $20 + 3,Y
	
    LDA $1234 + 4
    LDA $1234 + 5,X
    LDA $1234 + 6,Y
	
    JMP ($1234 + 8)
	
    LDA ($20 + 4,X)
    LDA ($20 + 5),Y
	
    BEQ * + 4
    BNE * - 2

    JSR $9000 + 1
    BRK
