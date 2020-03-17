# QEMU AArch64 baremetal app example

## build

```bash
$ make
```

## run

```bash
$ qemu-system-aarch64 -cpu cortex-a53 -M virt -nographic -semihosting -kernel image.bin
```
