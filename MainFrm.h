// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "View.h"
#include "IMainFrame.h"

class CMainFrame : 
	public CFrameWindowImpl<CMainFrame>, 
	public CUpdateUI<CMainFrame>,
	public CMessageFilter, 
	public CIdleHandler, 
	public IMainFrame {
public:
	DECLARE_FRAME_WND_CLASS(nullptr, IDR_MAINFRAME)
	
	CMainFrame();

	bool IsCPUSetsAvailable() const;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainFrame)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_OPTIONS_ALWAYSONTOP, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_SHOWALLTHREADS, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_ACTIVITY_BUSY, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_ACTIVITY_LOW, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_ACTIVITY_MAXIMUM, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_ACTIVITY_MEDIUM, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_THREAD_SUSPEND, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_THREAD_RESUME, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_THREAD_KILL, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_IDLE, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_BELOWNORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_NORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_ABOVENORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_HIGH, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITYCLASS_REALTIME, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_THREAD_AFFINITY, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_THREAD_IDEALCPU, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_IDLE, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_BELOWNORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_LOWEST, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_NORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_ABOVENORMAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_HIGHEST, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_PRIORITY_TIMECRITICAL, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_THREAD_SELECTEDCPUSETS, UPDUI_MENUPOPUP)

		UPDATE_ELEMENT(0, UPDUI_STATUSBAR)
		UPDATE_ELEMENT(1, UPDUI_STATUSBAR)
		UPDATE_ELEMENT(2, UPDUI_STATUSBAR)
		UPDATE_ELEMENT(3, UPDUI_STATUSBAR)
		UPDATE_ELEMENT(4, UPDUI_STATUSBAR)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		//COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(ID_SYSTEM_CPUSETS, OnSystemCPUSets)
		COMMAND_ID_HANDLER(ID_PROCESS_CPUSETS, OnProcessCPUSets)
		COMMAND_ID_HANDLER(ID_OPTIONS_ALWAYSONTOP, OnAlwaysOnTop)
		COMMAND_ID_HANDLER(ID_HELP_SYSTEMINFORMATION, OnSystemInfo)
		COMMAND_ID_HANDLER(ID_SYSTEM_INFORMATION, OnSystemInfo)
		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		CHAIN_MSG_MAP_ALT_MEMBER(m_view, 2)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

private:
// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	//LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSystemCPUSets(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnProcessCPUSets(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAlwaysOnTop(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSystemInfo(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	// Inherited via IMainFrame
	BOOL ShowContextMenu(HMENU hMenu, POINT pt) override;

private:
	CView m_view;
	CCommandBarCtrl m_CmdBar;
	CMultiPaneStatusBarCtrl m_StatusBar;
};
