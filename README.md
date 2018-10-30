> "A wondrous great house Valhalla must be; it must often be exceeding crowded before the doors."
> (Gylfaginning, XL)

# Valhalla

Valgrind is unintelligible to new C programmers. Here are some reasons why:
 - It contains a lot of extraneous information. New programmers do not need to know anything that starts with 0x, or what the PID is.
 - The words is uses are long and often hard to understand.
 - The stack it shows does not emphasize important information, and it is often not clear which stack is relevant.
 - The insights it gives require interpreting solutions. This relies on a) understanding the output and b) knowing what to do about it

 Valhalla is a script that wraps Valgrind to give this information. It focuses on making information clear, and providing actionable errors and insights.

## Usage

Valhalla is a wrapper around valgrind, so it is called in the same way. Arguments to valhalla are passed through to valgrind, though the behaviour for those arguments is not defined. Add arguments at your own risk.

```bash
# valgrind ./my_program
valhalla ./my_program
```
