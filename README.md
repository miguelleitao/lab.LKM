# lab.LKM
Linux Kernel Modules lab handout 

# Howto
```
cp ok/mymodule0.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
```

'''
cp ok/mymodule1.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
rmmod mymodule
'''
'''
cp ok/mymodule2.c mymodule.c
make
modinfo mymodule.ko
insmod mymodule.ko
ls mod |head
dmesg
rmmod mymodule
'''

