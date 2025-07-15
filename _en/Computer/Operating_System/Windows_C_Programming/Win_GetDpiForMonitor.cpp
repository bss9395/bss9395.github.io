/* Win_GetDpiForMonitor.cpp
Author: bss9395
Update: 2025-07-15T10:01:00+08@China-ShangHai+08
*/

#include <iostream>
#include <windows.h>
#include <iostream>
#include <ShellScalingApi.h> // 需要链接 Shcore.lib
#pragma comment(lib, "Shcore.lib")

void _Screen() {
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);  // 启用dpi感知

    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);
    fprintf(stdout, "metrics = (%d, %d)\n", width, height);

    int dpi = GetDpiForSystem();
    fprintf(stdout, "dpi = %d, scale = %f\n", dpi, (double)dpi / 96);
}

void _Monitor() {
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);  // 启用dpi感知

    HWND hwnd = GetDesktopWindow();
    HMONITOR monitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFOEX monitorInfo; 
    monitorInfo.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(monitor, &monitorInfo);

    WCHAR* device = monitorInfo.szDevice;
    fwprintf(stdout, L"device = %s\n", device);

    int left = monitorInfo.rcMonitor.left;
    int right = monitorInfo.rcMonitor.right;
    int top = monitorInfo.rcMonitor.top;
    int bottom = monitorInfo.rcMonitor.bottom;
    fprintf(stdout, "metrics = (%d, %d, %d, %d; %d, %d)\n", left, right, top, bottom, right - left, bottom - top);

    UINT dpiX = 96;
    UINT dpiY = 96;
    GetDpiForMonitor((HMONITOR)monitor, MDT_EFFECTIVE_DPI, &dpiX, &dpiY);
    fprintf(stdout, "dpi = (%d, %d), scale = (%f, %f)\n", dpiX, dpiY, (double)dpiX / 96, (double)dpiY / 96);
}

void _Window() {
    // HDC hdc = GetDC(GetDesktopWindow());
    HDC hdc = GetDC(nullptr);  

    SetProcessDpiAwareness(PROCESS_DPI_UNAWARE);            // 启用再停用dpi感知无效
    int metricsWidth = GetDeviceCaps(hdc, HORZRES);
    int metricsHeight = GetDeviceCaps(hdc, VERTRES);
    fprintf(stdout, "metrics = (%d, %d)\n", metricsWidth, metricsHeight);

    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);  // 启用dpi感知
    int resolutionWidth = GetDeviceCaps(hdc, DESKTOPHORZRES);
    int resolutionHeight = GetDeviceCaps(hdc, DESKTOPVERTRES);
    fprintf(stdout, "resoulution = (%d, %d)\n", resolutionWidth, resolutionHeight);
   
    double scaleX = (double)resolutionWidth / metricsWidth;
    double scaleY = (double)resolutionHeight / metricsHeight;
    fprintf(stdout, "scale = (%f, %f)\n", scaleX, scaleY);

    ReleaseDC(nullptr, hdc);
}

int main() {
    // _Screen();
    _Monitor();
    // _Window();

    return 0;
}