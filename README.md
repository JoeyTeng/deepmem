# Deeplang Memory Management System Demo

> Note that this is only a preliminary implementation with severe bug. A better working implementation can be found in the [main repo](https://github.com/deeplang-org/deepvm/blob/dev/src/deep_mem.c).
>
> The evolvement history can be found [here](https://github.com/JoeyTeng/deeplang/commits/wasmvm-memory-management-implementation/src/vm)
>
> And you can find [the design document](https://github.com/JoeyTeng/deeplang/blob/wasmvm-memory-management-implementation/doc/deepvm%20memory%20management.md) from the same repo. A English version can be found in this repo under `/doc`

## How to build

```shell
make
```

You can directly run with `./wasmvm`.

Example logs:

```shell
...
src/deep_main.c:40, main(), <info>, malloc 289 times, @0x102ebe180
src/deep_main.c:40, main(), <info>, malloc 290 times, @0x102ebe180
src/deep_main.c:40, main(), <info>, malloc 291 times, @0x102ebe180
src/deep_main.c:40, main(), <info>, malloc 292 times, @0x102ebe180
src/deep_main.c:40, main(), <info>, malloc 293 times, @0x0
src/deep_main.c:45, main(), <error>, malloc fail @293
```
