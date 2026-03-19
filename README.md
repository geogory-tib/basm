# BASM — The BAD Assembler for the 6502 CPU
### Written by Samuel A. Johnson

BASM is a very rudimentary assembler for the 6502 CPU. It works *somewhat okay*, but the design is probably terrible. This is my first time writing anything that performs code generation.

I am currently working on finishing the **macro preprocessor** to the assembler. At the moment there is **no support for**:
- Macros
(It shouldn't be to hard to finish it)

---

## Syntax Differences

BASM uses slightly different syntax than traditional 6502 assemblers for referencing the **current program counter**.

For example, in assemblers like **DASM**, you might write:

```
beq * + 4
```

In **BASM**, the equivalent syntax is:

```
beq & + 4
```

I chose `&` because it felt more natural coming from a **C programming background**.

---

## Syntax Example File

There is a file included in the repository called:

```
SYNTAX_EXAMPLE.S
```

This file provides a **visual overview of some BASM semantics**.

As of now it should compile but the macro example is commented out, due to macros being in the works.   
I am currently working on creating proper documentation for the assembler.

---

## Feedback

Please feel free to reach out with:

- Tips
- Suggestions
- Improvements

Thanks for taking a look!

Have a wonderful day, and **God bless**.
