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
cat /proc/arcom
rmmod mymodule
```

```
cp ok/mymodule2.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
lsmod |head
dmesg
ls /sys/module/mymodule/parameters
rmmod mymodule
insmod mymodule.ko num_aluno=1234567 disc=arcop
lsmod |head
dmesg
cat /sys/module/mymodule/parameters/disc
cat /sys/module/mymodule/parameters/num_aluno
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

```
cp ok/mymodule5.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
rmmod mymodule
```

```
cp ok/mymodule6.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
rmmod mymodule
```

