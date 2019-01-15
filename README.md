# Sniber

Sniber is a small C library for reading, listing and at some point manipulating USB devices.

## Download

1) ```/cd include```
2) ```git clone git@github.com:Eros/Sniber.git ```

    This does not require the makelist to be ran

## Required dependencies

tchar > https://docs.microsoft.com/en-us/office/client-developer/outlook/mapi/tchar

setupapi > https://docs.microsoft.com/en-us/windows-hardware/drivers/install/setupapi

initguid > https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/including-guids-in-driver-code

stdio > pre-installed into C library

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