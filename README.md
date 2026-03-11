# BASM -- The BAD assembler for the 6502 CPU
### Written By Samuel .A Johnson   
	This is a very rudimentary assembler that works somewhat okay. It's design is probably terrible, but It's my first time    
	writing anything that does any code generation. I am working on adding a macro pre processor (much like C's) to the assembler   
	since currently there is no support currently for macros,constants or even comments (yeah. I know I'm getting to work on it)   
	This assembler has slightly different syntax from traditional 6502 assemblers to refer to the current program counter like for    
	instance in this code   
	```   
	beq * + 4 ; like in DASM or many other 6502 assemblers   
	```   
	is done like this in BASM   
	```
	beq & + 4 //did this because I thought it made more sense because I program mainly in c   
	```   
	there is a file named SYNTAX_EXAMPLE.S that provides you a visual overview of some of the semantics of the assembler.   
	Currently it will not assemble because I do not have any support for comments or macros, but I am going to use it as a    
	template for what needs to be implemented.    
	Please feel free to message me for any tips,suggestions or improvements. Please have a wonderful day and God bless.
	
