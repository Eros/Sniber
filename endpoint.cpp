//
// Created by George on 15-Jan-19.
//

#include <windows.h>

BOOL readFromBulkEndpoint(WINUSB_INTERFACE, hDeviceHandle, UCHAR* pID, ULONG cbSize) {
    if(hDeviceHandle == INVALID_HANDLE_VALUE) {
        return false;
    }
}
