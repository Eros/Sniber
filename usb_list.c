//
// Created by George on 14-Jan-19.
//

#include "usb_list.h"


void listAllDevices() {
    HDEVINFO hDevInfo;
    SP_DEVICE_INTERFACE_DATA devIntfData;
    PSP_DEVICE_INTERFACE_DETAIL_DATA devIntfDetailData;
    SP_DEVINFO_DATA devData;

    DWORD dwSize, dwType, dwMemberId;
    HKEY hKey;
    BYTE lpData[1024];

    hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_USB_DIVICE, NULL, 0, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT);

    if(hDevInfo != INVALID_HANDLE_VALUE) {
        //prepare to iterate all device interfaces information until the function causes GetLastError()
        SetupDiEnumDeviceInterfaces(hDevInfo, NULL &GUID_DEVINTERFACE_USB_DEVICE, dwMemberId, &devIntfData);

        while(GetLastError() != ERROR_NO_MORE_ITEMS) {
            devData.cbSize = sizeof(devData);
            SetupDiGetDeviceInterfaceDetail(hDevInfo, &devIntfData, NULL, 0, &dwSize, NULL);

            //allocate the memory for the interface detail struct
            devIntfDetailData = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwSize);
            devIntfDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

            //start checking if the device has been found by looking for the interface data in the datapath variable
            if(SetupDiGetDeviceInterfaceDetail(hDevInfo, &devIntfData, devIntfDetailData, dwSize, &dwSize, &devData)) {
                //check for the right VID/PID with the string handling routines

                if(NULL != _tcsstr((TCHAR*)devIntfDetailData->DevicePath, _T("vid_10cf&pid_8090"))) {
                    //find out of the serial of the port has K8090. Also need to check the registry also
                    hKey = SetupDiOpenDevRegKey(hDevInfo, &devData, DICS_FLAG_GLOBAL, 0, DIREG_DEV, KEY_READ);

                    dwType = REG_SZ;
                    dwSize = sizeof(lpData);
                    RegQueryValueEx(hKey, _T("PortName"), NULL, &dwType, lpData, &dwSize);
                    RegCloseKey(hKey);
                    printf("Found device >> %d \n", lpData);
                }
            }

            //now free up the memory
            HeapFree(GetProcessHeap(), 0, devIntfDetailData);
            //continue the loop
            SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_USB_DEVICE, ++dwMemberId, &devIntfData);
        }
        SetupDiDestroyDeviceInfoList(hDevInfo);
    }
}