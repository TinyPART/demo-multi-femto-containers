# demo-multi-femto-containers

Femto-Containers are small containers hosting a virtual machine based on the
Linux eBPF architecture, running on microcontroller-type devices. This makes it
a suitable tool for secure DevOps workflows with small applications deployed on
low-power IoT devices. Check out this paper for a description of
Femto-Containers in details. If you want to cite this work, please cite it as
such:

[K. Zandberg, E. Baccelli, S. Yuan, F. Besson, JP Talpin. Femto-Containers:
Lightweight Virtualization and Fault Isolation For Small Software Functions on
Low-Power IoT Microcontrollers. In Proc. of 23rd ACM/IFIP MIDDLEWARE, Nov.
2022.](https://inria.hal.science/hal-03888109v1)

## Examples

Two examples are provided in this repository as demonstrators of
Femto-Containers.

1. A [small benchmark application](./bench_bpf_unit) demonstrating the
   performance of different eBPF instructions as implemented in
   Femto-Containers.
2. A [full example](./suit_femtocontainer) demonstrating multiple
   Femto-Containers running inside a single instance, with each instance
   updateable over the air via SUIT and CoAP.
