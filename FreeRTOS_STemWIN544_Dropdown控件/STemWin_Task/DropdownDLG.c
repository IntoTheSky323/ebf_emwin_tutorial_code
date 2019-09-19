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

#include "DropdownDLG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_DROPDOWN_0 (GUI_ID_USER + 0x01)
#define ID_DROPDOWN_1 (GUI_ID_USER + 0x02)
#define ID_TEXT_0 (GUI_ID_USER + 0x03)

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
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown1", ID_DROPDOWN_0, 170, 180, 130, 25, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown2", ID_DROPDOWN_1, 500, 180, 130, 25, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "", ID_TEXT_0, 335, 180, 130, 25, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/**
  * @brief 对话框回调函数
  * @note pMsg：消息指针
  * @param 无
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
	int     value;
	char    Dropdown_buf[8] = {0};


  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    /* 初始化Framewin控件 */
    hItem = pMsg->hWin;
    FRAMEWIN_SetFont(hItem, GUI_FONT_32_ASCII);
    FRAMEWIN_SetTitleHeight(hItem, 32);
    FRAMEWIN_SetText(hItem, "STemWIN@EmbeddedFire STM32F429");
    /* 初始化DROPDOWN0 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
    DROPDOWN_SetListHeight(hItem, 100);
	  DROPDOWN_SetFont(hItem, GUI_FONT_24B_1);
    DROPDOWN_AddString(hItem, "Item1-0");
    DROPDOWN_AddString(hItem, "Item1-1");
    DROPDOWN_AddString(hItem, "Item1-2");
    DROPDOWN_AddString(hItem, "Item1-3");
    DROPDOWN_AddString(hItem, "Item1-4");
    DROPDOWN_AddString(hItem, "Item1-5");
    DROPDOWN_AddString(hItem, "Item1-6");
    DROPDOWN_AddString(hItem, "Item1-7");
		DROPDOWN_SetAutoScroll(hItem, 1);
		DROPDOWN_SetScrollbarWidth(hItem, 20);
    /* 初始化DROPDOWN1 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_1);
    DROPDOWN_SetListHeight(hItem, 100);
    DROPDOWN_SetFont(hItem, GUI_FONT_24B_1);
    DROPDOWN_AddString(hItem, "Item2-0");
    DROPDOWN_AddString(hItem, "Item2-1");
    DROPDOWN_AddString(hItem, "Item2-2");
    DROPDOWN_AddString(hItem, "Item2-3");
    DROPDOWN_AddString(hItem, "Item2-4");
    DROPDOWN_AddString(hItem, "Item2-5");
    DROPDOWN_AddString(hItem, "Item2-6");
    DROPDOWN_AddString(hItem, "Item2-7");
		DROPDOWN_SetAutoScroll(hItem, 1);
		DROPDOWN_SetScrollbarWidth(hItem, 20);
		DROPDOWN_SetUpMode(hItem, 1);
		/* 初始化TEXT */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_COMIC24B_ASCII);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_DROPDOWN_0: // Notifications sent by 'Dropdown0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				value = DROPDOWN_GetSel(hItem);
				DROPDOWN_GetItemText(hItem, value, Dropdown_buf, GUI_COUNTOF(Dropdown_buf));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				TEXT_SetText(hItem, Dropdown_buf);
        break;
      }
      break;
    case ID_DROPDOWN_1: // Notifications sent by 'Dropdown1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_1);
				value = DROPDOWN_GetSel(hItem);
				DROPDOWN_GetItemText(hItem, value, Dropdown_buf, GUI_COUNTOF(Dropdown_buf));
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				TEXT_SetText(hItem, Dropdown_buf);
        break;
      }
      break;
    }
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
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
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
	CreateFramewin();

	while (1)
	{
		GUI_Delay(100);
	}
}

/*************************** End of file ****************************/
