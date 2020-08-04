## RISCV_QEMU

Baremetal kernel development on sifive_e core using Riscv Qemu 
 
* Install the latest version of qemu from their [website](https://www.qemu.org/download/#source)
* Install RISCV 32bit toolchain from [Riscv repository](https://github.com/riscv/riscv-gnu-toolchain)
* clone this repository : `https://github.com/AdityaGawali/RISCV.git`
* Inside project folder `make all` to build `kernel` for Sifive_e core
* To run the kernel on qemu  do `make run` 