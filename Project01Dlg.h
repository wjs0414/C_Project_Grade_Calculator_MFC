
// Project01Dlg.h: 헤더 파일
//

#pragma once


// CProject01Dlg 대화 상자
class CProject01Dlg : public CDialogEx
{
// 생성입니다.
public:
	CProject01Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT01_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	
	afx_msg void OnBnClickedcalculate();//버튼 클릭시 발생하는 이벤트 메서드
	int m_tot_grade;	//학점 총합 출력하는 edit control 변수
	double getScore(int a);  // 콤보박스에 있는 리스트를 각 점수로 반환해주는 메서드
	CString m_avg_score;  // 총 성적 평균 출력하는 edit contol 변수
};
