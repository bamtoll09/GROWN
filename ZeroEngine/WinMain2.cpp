#include "stdafx.h"
#include <Windows.h>
#include <Zero.h>
#include "StartScene.h"
#include "BlankScene.h"
#include "resource.h"

//�� ������ �ּ�ó���ϸ� �ܼ�â �ȶ��.
//ZeroConsole g_Console;  

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT )
{
    int WindowWidth = 1024;
    int WindowHeight = 768;

    ZeroApp->RegisterWindowSize(WindowWidth, WindowHeight) ;
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, ZeroApp->MsgProc, 0L, 0L, 
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      L"Engine2D", NULL };
    RegisterClassEx( &wc );

    srand(GetTickCount());

    // WS_EX_TOPMOST | WS_POPUP :: ��üȭ�� ���
    // WS_OVERLAPPEDWINDOW      :: âȭ��	
    HWND hWnd = CreateWindow( L"Engine2D", L"����", 
                              WS_OVERLAPPEDWINDOW , 100, 0, WindowWidth, WindowHeight,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

    ZeroApp->SetHwnd(hWnd);

    if( SUCCEEDED( ZeroApp->InitD3D( hWnd, false ) ) ) //��üȭ���� �Ϸ��� true��
    { 

        ShowWindow( hWnd, SW_SHOWDEFAULT );
        UpdateWindow( hWnd );
		
		auto cursor = LoadCursorFromFile(L"Texture/cursor.cur");
		SetClassLong(hWnd, GCL_HCURSOR, (DWORD)cursor);

		//wc.hIcon = LoadIcon(hInst, (LPCTSTR)IDI_ICON1);
		HICON hIcon = (HICON)LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));//�꫽?������
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

        //���⼭ ó�� �����ϴ� Scene�� ���Ѵ�
		ZeroSceneMgr->ChangeScene(new StartScene(), TR::Fade);


        MSG msg;
            ZeroMemory( &msg, sizeof(msg) );
            while( msg.message!=WM_QUIT )
            {
                if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
                {
                    TranslateMessage( &msg );
                    DispatchMessage( &msg );
                }
                else
                    ZeroApp->Render();
            }
    }
    //����
    ZeroSceneMgr->Clear();

    UnregisterClass( L"Engine2D", wc.hInstance );
    return 0;
}