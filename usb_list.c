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
        SetupDiEnumDeviceInterfaces(hDevInfo, NULL &GUID_DEVINTERFACE_USB_DEVICE, dwMemberId, &devIntfData);

    }
}