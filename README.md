# BASM — The BAD Assembler for the 6502 CPU
### Written by Samuel A. Johnson

BASM is a very rudimentary assembler for the 6502 CPU. It works *somewhat okay*, but the design is probably terrible. This is my first time writing anything that performs code generation.

I am currently working on adding a **macro preprocessor** (similar to C’s) to the assembler. At the moment there is **no support for**:

- Macros
- Constants
- Comments

(Yeah… I know. I'm working on it.)

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

Currently, it **will not assemble** because support for comments and macros has not yet been implemented. It is intended to serve as a **template and development guide** for features that still need to be added.

---

## Feedback

Please feel free to reach out with:

- Tips
- Suggestions
- Improvements

Thanks for taking a look!

Have a wonderful day, and **God bless**.
