#include <stdio.h>
#include "usb_list.h"
#include "endpoint.cpp"
int main() {
    listAllDevices();
    readFromBulkEndpoint();
    return 0;
}