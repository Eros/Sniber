# Sniber

Sniber is a small C library for reading, listing and at some point manipulating USB devices.

## Download

1) ```/cd include```
2) ```git clone git@github.com:Eros/Sniber.git ```

    This does not require the makelist to be ran

## Usage example

```
#include "usb_list.h"

int main() {
   char[] devices = listAllDevices();
   for(int i = 0; i < sizeof(devices) + 1; i++) {
     printf("%d\n", devices[i]);
   }
   return 0;
}
```