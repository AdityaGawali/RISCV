## RISCV_QEMU

Baremetal kernel development on Virt machine using Riscv Qemu 
 
* Install the latest version of qemu from the [website](https://www.qemu.org/download/#source)
* Install newlib RISCV 64bit toolchain from [Riscv repository](https://github.com/riscv/riscv-gnu-toolchain)
* clone this repository : `https://github.com/AdityaGawali/RISCV.git`
* Inside project folder `make all` to build `kernel` for sifive_u machine
* To run the kernel on qemu  do `make run` 
* When running under WSL make sure `"WINDOWS_EXE"` is set to `".exe"`
* For stand alone Linux set `"WINDOWS_EXE"` to empty `""` 
