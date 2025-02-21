#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <stdio.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield,button;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
char textsaved[20];
HWND TextBox1,TextBox2;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
   // wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    wincl.hbrBackground = CreateSolidBrush(RGB(250, 200, 200)); // Sets background to red


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("My Calculator"),       /* Title Text */
          // WS_OVERLAPPEDWINDOW, /* default window */
          WS_MINIMIZEBOX | WS_SYSMENU,
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           250,                 /* The programs width */
           200,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:

        textfield = CreateWindow("STATIC",
                                 "Please input two numbers",
                                 WS_VISIBLE | WS_CHILD| WS_BORDER,
                                 20,20,200,20,
                                 hwnd,NULL,NULL,NULL);

        /* button = CreateWindow("BUTTON",
                               "This is a button",
                                WS_VISIBLE | WS_CHILD| WS_BORDER,
                                20,50,200,20,
                                hwnd,(HMENU) 1,NULL,NULL);*/


        TextBox1 = CreateWindow("EDIT",
                               " ",
                               WS_VISIBLE | WS_CHILD| WS_BORDER,
                                70,50,100,20,
                               hwnd,NULL, NULL, NULL
                               );
        TextBox2 = CreateWindow("EDIT",
                               " ",
                               WS_VISIBLE | WS_CHILD| WS_BORDER,
                                70,80,100,20,
                               hwnd,NULL, NULL, NULL
                               );
        CreateWindow("BUTTON",
                    "+",
                    WS_VISIBLE | WS_CHILD| WS_BORDER,
                    50,120,25,20,
                    hwnd, (HMENU) 1,NULL,NULL);
       CreateWindow("BUTTON",
                    "-",
                    WS_VISIBLE | WS_CHILD| WS_BORDER,
                    90,120,25,20,
                    hwnd, (HMENU) 2,NULL,NULL);
      CreateWindow("BUTTON",
                    "*",
                    WS_VISIBLE | WS_CHILD| WS_BORDER,
                    130,120,25,20,
                    hwnd, (HMENU) 3,NULL,NULL);
      CreateWindow("BUTTON",
                    "/",
                    WS_VISIBLE | WS_CHILD| WS_BORDER,
                    170,120,25,20,
                    hwnd, (HMENU) 4,NULL,NULL);

        break;

        case WM_COMMAND:



            switch(LOWORD(wParam))

            {


                case 1:{


                    double sum=0;

                     GetWindowText(TextBox1, &textsaved[0], 20);
                     sum = atof(textsaved);
                     GetWindowText(TextBox2, &textsaved[0], 20);
                     sum += atof(textsaved);
                     sprintf(textsaved, "%f", sum);

                    ::MessageBox(hwnd,textsaved, "Result", MB_OK);
                     break;}

                case 2:{
                    double sum=0;

                     GetWindowText(TextBox1, &textsaved[0], 20);
                     sum = atof(textsaved);
                     GetWindowText(TextBox2, &textsaved[0], 20);
                     sum -= atof(textsaved);
                     sprintf(textsaved, "%f", sum);

                    ::MessageBox(hwnd,textsaved, "Result", MB_OK);

                   break;}

                case 3:{
                    double sum=0;

                     GetWindowText(TextBox1, &textsaved[0], 20);
                     sum = atof(textsaved);
                     GetWindowText(TextBox2, &textsaved[0], 20);
                     sum *= atof(textsaved);
                     sprintf(textsaved, "%f", sum);

                    ::MessageBox(hwnd,textsaved, "Result", MB_OK);

                   break;}

                case 4:{
                    double sum=0;

                     GetWindowText(TextBox1, &textsaved[0], 20);
                     sum = atof(textsaved);
                     GetWindowText(TextBox2, &textsaved[0], 20);
                     sum /= atof(textsaved);

                     sprintf(textsaved, "%f", sum);

                    ::MessageBox(hwnd,textsaved, "Result", MB_OK);

                   break;}



            }

        break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
