
// RegisterSoundDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "RegisterSound.h"
#include "RegisterSoundDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "mmsystem.h"


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRegisterSoundDlg 대화 상자



CRegisterSoundDlg::CRegisterSoundDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_REGISTERSOUND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegisterSoundDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

BEGIN_MESSAGE_MAP(CRegisterSoundDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CRegisterSoundDlg::OnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_R, &CRegisterSoundDlg::OnClickedButtonR)
	ON_BN_CLICKED(IDC_BUTTON_S, &CRegisterSoundDlg::OnClickedButtonS)
	ON_BN_CLICKED(IDC_BUTTON_E, &CRegisterSoundDlg::OnClickedButtonE)
END_MESSAGE_MAP()


// CRegisterSoundDlg 메시지 처리기

BOOL CRegisterSoundDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// 변수m_list1 리스트박스에 "도,레,미,파,솔,라,시,도"를 추가한다.

	m_list1.AddString(_T("질문"));
	m_list1.AddString(_T("기본경고음"));
	m_list1.AddString(_T("시스템오류"));
	m_list1.AddString(_T("시스템종료"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRegisterSoundDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRegisterSoundDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRegisterSoundDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegisterSoundDlg::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// m_listM에 있는 목록 중 하나를 선택하면 그 소리가 재생된다.
	int a = 0;

	a = m_list1.GetCurSel();
	switch (a)
	{
	case 0:
		PlaySound("SystemQuestion", NULL, SND_ALIAS | SND_ASYNC);
		break;
	case 1:
		PlaySound("SystemDefault", NULL, SND_ALIAS | SND_ASYNC);
		break;
	case 2:
		PlaySound("SystemHand", NULL, SND_ALIAS | SND_ASYNC);
		break;
	case 3:
		PlaySound("SystemExit", NULL, SND_ALIAS | SND_ASYNC);
		break;
	}
}


void CRegisterSoundDlg::OnClickedButtonR()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		PlaySound("SystemQuestion", NULL, SND_ALIAS | SND_SYNC);
		PlaySound("SystemDefault", NULL, SND_ALIAS | SND_SYNC);
		PlaySound("SystemHand", NULL, SND_ALIAS | SND_SYNC);
		PlaySound("SystemExit", NULL, SND_ALIAS | SND_SYNC);
}


void CRegisterSoundDlg::OnClickedButtonS()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PlaySound(NULL, NULL, NULL);
}


void CRegisterSoundDlg::OnClickedButtonE()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
