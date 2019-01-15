//
// Created by George on 15-Jan-19.
//

#include <windows.h>

BOOL readFromBulkEndpoint() {

    WINUSB_INTERFACE hDeviceHandle;
    UCHAR* pID;
    ULONG cbSize;

    if(hDeviceHandle == INVALID_HANDLE_VALUE) {
        return false;
    } else {
        BOOL bResult = true;
        UCHAR* szBuffer = (UCHAR*)LocalAlloc(LPTR, sizeof(UCHAR)*cbSize);
        ULONG cbRead = 0;
        bResult = WinUsb_ReadPipe(hDeviceHandle, *pID, szBuffer, cbSize, &cbRead, 0);

        if(!bResult){
            goto done;
        }

        printf("Read from pipe %d: %s \n Actual data: %d \n", *pID, szBuffer, cbRead);

        done:
            LocalFree(szBuffer);
        return bResult;
    }
}
