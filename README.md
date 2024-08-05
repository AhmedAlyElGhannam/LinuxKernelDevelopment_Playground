# LinuxKernelDevelopment_Playground

This repo contains 2 simple projects related to kernel development: a kernel module that prints stuff and a character device driver that also prints stuff but repeatedly!

This was done on a machine running Ubuntu 20.04 with kernel version `5.15.0`. Some functions/macros may differ depending in the kernel version you are running so feel free to check ![Bootlin's Website](https://elixir.bootlin.com/linux/v5.15/source/kernel) to know more about the right syntax.

## Preparations

1. In order to check for kernel version, run:

```
uname -r
```

1. Install essentials for kernel development:

```
sudo apt install build-essential linux-headers-$(uname -r)
```

## Loading & Unloading Modules

```
# for loading
sudo insmod hello.ko

# for unloading
sudo rmmod hello.ko
```