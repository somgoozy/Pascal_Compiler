	This project is one that I’m currently working on in my free time. It
started in my Compilers class at the University of Kentucky, but we were
not required to finish it. The project was to write a Pascal compiler using
C++. Unfortunately, due to the length of the class the project ended early
and I forgot about it. I thought that reviving this project would be a fun
and healthy exercise for me. Due to it being a class project, it had some
weird requirements such as handling compiler errors by returning strings
and some minor omissions to the language. My end goal is to finish writing
the rest of the compiler, fix the quirks that my professor designed, then
have it be able to successfully compile and run project2.pas. The compiler
currently has a working scanner, tokenizer, and parser. I am currently, or
depending on when you have read this, have possibly finished writing the
interpreter.

	The program works by just looping through the file while removing
whitespace and comments, then tokenizing the remainder. This is done by
looking at the FSA state transition table. Any symbols that are found are
pushed onto the symbol table with a custom hashing algorithm that was
required by the professor. The parser then goes to work by pushing the start
of a new program onto the stack. If the stack has a nonterminal at the top,
it pops it and pushes its production, all of which can all be found on the
grammar table. If the top of the stack is not a nonterminal, it is compared
to the next token, and if it matches it is popped off the stack. If it doesn’t
match then it throws a compiler error. 

	I am currently writing the interpreter. The way that it works in my head is
that it will have its own stack. This stack is comprised of only the nonterminals
that have been popped off of the parser’s stack. This will essentially track where
the interpreter is. These nonterminals are stored in a struct with the appropriate
data needed to track their progression through the process. When a nonterminal is
pushed to the interpreter it will preform the actions that are specified by the
grammar that is determined by the interpreter’s stack and increment the progression.

	The only thing holding me back from writing this code is the amount of free time
that I have given my current employment situation, but I hope to have it done soon.
This project has been doing much to help me grow as a programmer. Analyzing and fixing
old code that I don’t remember very well is a great exercise that I have been greatly
enjoying.
