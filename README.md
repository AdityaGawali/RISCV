## RISCV_QEMU

Baremetal kernel development on Virt machine using Riscv Qemu 
 
* Install the latest version of qemu from their [website](https://www.qemu.org/download/#source)
* Install RISCV 64bit toolchain from [Riscv repository](https://github.com/riscv/riscv-gnu-toolchain)
* clone this repository : `https://github.com/AdityaGawali/RISCV.git`
* Inside project folder `make all` to build `kernel` for Virt machine
* To run the kernel on qemu  do `make run` 
