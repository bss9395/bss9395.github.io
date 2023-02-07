/* Gamma_Ramp.h
Author: BSS9395
Update: 2023-02-07T23:48:00+08@China-Shanghai+08
Design: Brightness
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Gamma_Ramp_h
#define Gamma_Ramp_h

#define   Header_h
#include "Common.h"

class CGammaRamp {
    typedef BOOL(WINAPI *Type_SetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);

public:
    HMODULE hGDI32 = NULL;
    Type_SetDeviceGammaRamp pGetDeviceGammaRamp = NULL;
    Type_SetDeviceGammaRamp pSetDeviceGammaRamp = NULL;

public:
    explicit CGammaRamp() {

    }

    virtual ~CGammaRamp() {
        FreeLibrary();
    }

    BOOL LoadLibrary() {
        FreeLibrary();
        hGDI32 = ::LoadLibrary(L"gdi32.dll");
        if (hGDI32 != NULL) {
            pGetDeviceGammaRamp = (Type_SetDeviceGammaRamp)GetProcAddress(hGDI32, "GetDeviceGammaRamp");
            pSetDeviceGammaRamp = (Type_SetDeviceGammaRamp)GetProcAddress(hGDI32, "SetDeviceGammaRamp");
            if (pGetDeviceGammaRamp == NULL || pSetDeviceGammaRamp == NULL) {
                FreeLibrary();
            }
        }
        return !(pGetDeviceGammaRamp == NULL || pSetDeviceGammaRamp == NULL);
    }

    BOOL LoadLibraryIfNeeded() {
        if (pGetDeviceGammaRamp != NULL && pSetDeviceGammaRamp != NULL) {
            return TRUE;
        }
        return LoadLibrary();
    }

    void FreeLibrary() {
        if (hGDI32 != NULL) {
            ::FreeLibrary(hGDI32);
            hGDI32 = NULL;
        }
    }

public:
    BOOL SetDeviceGammaRamp(HDC hDC, LPVOID lpRamp) {
        if (LoadLibraryIfNeeded() == TRUE) {
            return pSetDeviceGammaRamp(hDC, lpRamp);
        }
        return FALSE;
    }

    BOOL GetDeviceGammaRamp(HDC hDC, LPVOID lpRamp) {
        if (LoadLibraryIfNeeded() == TRUE) {
            return pGetDeviceGammaRamp(hDC, lpRamp);
        }
        return FALSE;
    }

    BOOL SetBrightness(HDC hDC, WORD wBrightness) {
        // The wBrightness value should be a number between 0 and 255.
        // 128 = Regular brightness
        // above 128 = brighter
        // below 128 = darker
        BOOL bReturn = FALSE;
        HDC hGammaDC = (hDC == NULL) ? GetDC(NULL) : hDC;
        if (hGammaDC != NULL) {
            WORD GammaArray[3][256];
            for (int iIndex = 0; iIndex < 256; iIndex += 1) {
                int iArrayValue = iIndex * (wBrightness + 128);
                if (iArrayValue > 65535) {
                    iArrayValue = 65535;
                }

                GammaArray[0][iIndex] =
                    GammaArray[1][iIndex] =
                    GammaArray[2][iIndex] = (WORD)iArrayValue;
            }
            bReturn = SetDeviceGammaRamp(hGammaDC, GammaArray);
        }
        if (hDC == NULL) {
            ReleaseDC(NULL, hGammaDC);
        }
        return bReturn;
    }
};

#endif // Gamma_Ramp_h
