# lab.LKM
Linux Kernel Modules lab handout 

# Howto
```
cp ok/mymodule0.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
lsmod |head
dmesg
```

```
cp ok/mymodule1.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
lsmod |head
dmesg
rmmod mymodule
```

```
cp ok/mymodule2.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
lsmod |head
dmesg
rmmod mymodule
insmod mymodule.ko num_aluno=12345678 disc=arcom
lsmod |head
dmesg
rmmod mymodule
```

```
cp ok/mymodule3.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
lsmod |head
dmesg
rmmod mymodule
```

```
cp ok/mymodule4.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
rmmod mymodule
```

