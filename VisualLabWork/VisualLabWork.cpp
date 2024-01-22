// VisualLabWork.cpp : Defines the entry point for the application.
//
#define _USE_MATH_DEFINES

#include "framework.h"
#include "VisualLabWork.h"

#include <cmath>
#include <string>
#include <vector>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

float calculateFunction(float x, float a)
{
	if (x <= 0)
		return powf(x, 4) + 2 * powf(x, 3) - x;
	else if (0 < x <= a)
		return powf(M_E, -x) + powf(x, 1 / 4);
	else if (x > a)
		return log10f(powf(x, 3) + powf(x, 2));
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_VISUALLABWORK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VISUALLABWORK));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VISUALLABWORK));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_VISUALLABWORK);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: {
		//CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_CENTER, 10, 20, 100, 30, hWnd, (HMENU)1, NULL, NULL);
		//CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_CENTER, 10, 60, 100, 30, hWnd, (HMENU)2, NULL, NULL);
		//CreateWindowW(L"EDIT", L"Результат", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_CENTER, 10, 100, 100, 30, hWnd, (HMENU)3, NULL, NULL);
		//CreateWindowW(L"BUTTON", L"Вычислить", WS_VISIBLE | WS_CHILD, 10, 140, 100, 30, hWnd, (HMENU)4, NULL, NULL);

		CreateWindowEx(0, L"STATIC", L"Enter array size:", WS_VISIBLE | WS_CHILD, 50, 50, 150, 20, hWnd, (HMENU)1, NULL, NULL);
		CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_VISIBLE | WS_CHILD, 200, 50, 50, 20, hWnd, (HMENU)2, NULL, NULL);
		CreateWindowEx(0, L"STATIC", L"Enter array elements (separated by space):", WS_VISIBLE | WS_CHILD, 50, 80, 300, 20, hWnd, (HMENU)3, NULL, NULL);
		CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_VISIBLE | WS_CHILD, 50, 110, 300, 20, hWnd, (HMENU)4, NULL, NULL);
		CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Process", WS_VISIBLE | WS_CHILD, 150, 140, 100, 30, hWnd, (HMENU)5, NULL, NULL);
		CreateWindowEx(0, L"STATIC", L"Result:", WS_VISIBLE | WS_CHILD, 50, 180, 150, 20, hWnd, (HMENU)6, NULL, NULL);
		CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL | WS_BORDER | ES_AUTOVSCROLL, 50, 210, 300, 100, hWnd, (HMENU)7, NULL, NULL);
		break;
	}
	case WM_COMMAND:
	{
		//if (LOWORD(wParam) == 4) {
		//	wchar_t buffer[256];
		//	GetWindowText(GetDlgItem(hWnd, 1), buffer, 256);
		//	float x = _wtof(buffer);
		//
		//	GetWindowText(GetDlgItem(hWnd, 2), buffer, 256);
		//	float a = _wtof(buffer);
		//
		//	float result = calculateFunction(x, a);
		//
		//	SetWindowText(GetDlgItem(hWnd, 3), std::to_wstring(result).c_str());
		//}

		if (LOWORD(wParam) == 5) {
			std::vector<int> array;
			HWND sizeInput = GetDlgItem(hWnd, 2);
			int size = GetDlgItemInt(hWnd, 2, NULL, TRUE);
			HWND elementsInput = GetDlgItem(hWnd, 4);
			int length = GetWindowTextLength(elementsInput) + 1;
			TCHAR* elements = new TCHAR[length];
			GetWindowText(elementsInput, elements, length);
			std::wstring strElements = elements;
			delete[] elements;
			size_t pos = 0;
			while ((pos = strElements.find(L' ')) != std::wstring::npos) {
				array.push_back(std::stoi(strElements.substr(0, pos)));
				strElements.erase(0, pos + 1);
			}
			array.push_back(std::stoi(strElements));
			// Process the array
			std::wstring result;
			for (int i : array) {
				result += std::to_wstring(i) + L"\r\n";
			}
			HWND resultOutput = GetDlgItem(hWnd, 7);
			SetWindowText(resultOutput, result.c_str());
		}
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
