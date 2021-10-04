
// Project01Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Project01.h"
#include "Project01Dlg.h"
#include "afxdialogex.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProject01Dlg 대화 상자
CProject01Dlg::CProject01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT01_DIALOG, pParent)
	
	, m_tot_grade(0) // 점수 총합 0으로 초기화
	, m_avg_score(_T("")) // 학점 평균 빈 문자열로 초기화
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	//edit control과 변수를 연결
	DDX_Text(pDX, IDC_tot_grade, m_tot_grade); 
	DDX_Text(pDX, IDC_avg_score, m_avg_score);
}

BEGIN_MESSAGE_MAP(CProject01Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(bt_calculate, &CProject01Dlg::OnBnClickedcalculate)
	
	
END_MESSAGE_MAP()


// CProject01Dlg 메시지 처리기

BOOL CProject01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
	
	
	
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CProject01Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProject01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Button event 발생 메서드
void CProject01Dlg::OnBnClickedcalculate()
{
	int grade[10]; // 과목 한개 당 입력된 학점을 받아 저장하는 배열 변수
	
	for (int i = 0; i < 10; i++) {  // edit control 에 입력된 정수를 grade에 차례대로 초기화
		grade[i] = GetDlgItemInt(IDC_grade01 + i); // edit control의 상수에 1씩 더해서 사용
	}
	
	CComboBox *p_score; // 점수 콤보박스 변수
	int index[10];//콤보박스 선택된 값의 인덱스 (10개)
	double hap=0.0,hap2=0.0; // 각각 학점 총합, 점수 총합 평균 변수
	
	for (int i = 0; i < 10; i++) { //콤보박스에서 선택된 주소를 값을 가져와서 그 값의 인덱스를 차례로 초기화
		p_score = (CComboBox *)GetDlgItem(IDC_score01 +i);
		index[i] = p_score->GetCurSel();
		
	}
	for (int i = 0; i < 10; i++) { //학점 총합 계산 반복문
		m_tot_grade += grade[i];
	}
	for (int i = 0; i < 10; i++) { //점수 총합 계산(학점*점수) 반복문
		hap += (grade[i] * getScore(index[i]));
	}
	hap2 = hap / m_tot_grade; //점수 총합 평균 계산(점수 총합 / 학점 총합)
	SetDlgItemInt(IDC_tot_grade,m_tot_grade);  // 학점 총합 출력
	m_avg_score.Format(_T("%.2f"), hap2); // 점수 평균을 edit control에 double형에서 CString형으로 변환하여 초기화
	SetDlgItemText(IDC_avg_score, m_avg_score); // 점수 평균 출력
	
}

double CProject01Dlg::getScore(int a) //점수 반환 메서드
{
	switch (a) { // int a는 콤보박스에서 선택된 값의 인덱스
	case 0: //(A)
		return 4.0; break;
	case 1: //(A+)
		return 4.5; break;
	case 2:  //(B)
		return 3.0; break;
	case 3:  //(B+)
		return 3.5; break;
	case 4: // (C)
		return 2.0; break;
	case 5:  //(C+)
		return 2.5; break;
	case 6:  //(D)
		return 1.0; break;
	case 7: //(D+)
		return 1.5; break;
	case 8: //(F)
		return 0.0; break;
	case 9: //(N)
		return 0.0; break;
	case 10: //(P)
		return 4.5; break;
	}
	return 0.0; //아무것도 선택되지 않았을때
}
