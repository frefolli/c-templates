# Templates for C language

Look at `vector.h` as an example of how to define templates and at `tests/vector.c` on usage of such templates.
For now it's limited to 1 template argument.

# Limitations

Since the definition of a template instance depends on static symbols (T, K, F ...) and no versioning/stacking system is implemented in C-pre-processor, recursive template definitions can end in weird behaviour.
For that reason all the templates that I've implemented raise an error if their definition happen when another definition of the same template is occurring and isn't finished.
I strongly encourage to use Composition in the correct way: I consider recursive definitions to be an anti-pattern.
