/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "WindowDLG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_0   (GUI_ID_USER + 0x01)


/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 30, 20, 520, 40, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    /* 初始化Window */
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, GUI_BLUE);
    /* 初始化Text */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "STemWIN@EmbeddedFire STM32F429");
    TEXT_SetFont(hItem, GUI_FONT_32_1);
    TEXT_SetTextColor(hItem, GUI_WHITE);
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
 /**
  * @brief 以对话框方式间接创建控件
  * @note 无
  * @param 无
  * @retval hWin：资源表中第一个控件的句柄
  */
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/**
  * @brief GUI主任务
  * @note 无
  * @param 无
  * @retval 无
  */
void MainTask(void)
{
	/* 创建窗口 */
	CreateWindow();
	/* 显示光标 */
	GUI_CURSOR_Show();
	while(1)
	{
		GUI_Delay(10);
	}
}

/*************************** End of file ****************************/
