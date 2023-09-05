#include "pch.h"
#include "ScreenObject.h"

void ScreenObject::SetObjectByType(int screenType) {
	this->screenType = screenType;
	switch (screenType) {
	case SCR_MENU:
		this->imagePath = _T("./res/screen_menu.png");
		rects = new CRect[2]; // ��ũ�� ���� Rect ������ŭ ���� �Ҵ�
		//memset(rects, 0, sizeof(rects));
		break;
	case SCR_BURGER:
		this->imagePath = _T("./res/screen_burger.png");
		rects = new CRect[30];
		break;
	case SCR_CHICKEN:
		this->imagePath = _T("./res/screen_chicken.png");
		rects = new CRect[28];
		break;
	case SCR_DESSERT:
		this->imagePath = _T("./res/screen_dessert.png");
		rects = new CRect[30];
		break;
	case SCR_DRINK:
		this->imagePath = _T("./res/screen_drink.png");
		rects = new CRect[30];
		break;
	case SCR_SET_DESSERT:
		this->imagePath = _T("./res/screen_set_dessert.png");
		rects = new CRect[30];
		break;
	case SCR_SET_DRINK:
		this->imagePath = _T("./res/screen_set_drink.png");
		rects = new CRect[30];
		break;
	case SCR_PAYMENT_1:
		this->imagePath = _T("./res/screen_payment_1.png");
		rects = new CRect[30];
		break;
	case SCR_PAYMENT_2:
		this->imagePath = _T("./res/screen_payment_2.png");
		rects = new CRect[30];
		break; 
	default:
		break;
	}
}

CString ScreenObject::GetPath() {

	return this->imagePath;
}

void ScreenObject::SetPath(CString imagePath) {
	this->imagePath = imagePath;
}

void ScreenObject::SetRectsPosition(CPoint window_pt) {
	
	if (this->screenType == SCR_MENU) { //�޴�ȭ��
		this->rects[0] = CRect(		// ���ӹ��
			int(window_pt.x * 0.25),
			int(window_pt.y * 0.64),
			int(window_pt.x * 0.25) + int(window_pt.x * 0.22),
			int(window_pt.y * 0.64) + int(window_pt.y * 0.1)
		);
		this->rects[1] = CRect(		// ���ӽ���
			int(window_pt.x * 0.53),
			int(window_pt.y * 0.64),
			int(window_pt.x * 0.53) + int(window_pt.x * 0.22),
			int(window_pt.y * 0.64) + int(window_pt.y * 0.1)
		);
	}
	else { //�÷��� ȭ��
		/* �÷��� ȭ�� ����(���� �ʿ� ���� Rect) */
		this->rects[0] = CRect(		// �ð�
			int(window_pt.x * 0.052),
			int(window_pt.y * 0.115),
			int(window_pt.x * 0.052) + int(window_pt.x * 0.05),
			int(window_pt.y * 0.115) + int(window_pt.y * 0.065)
		);
		this->rects[1] = CRect(		// ����
			int(window_pt.x * 0.927),
			int(window_pt.y * 0.065),
			int(window_pt.x * 0.927) + int(window_pt.x * 0.05),
			int(window_pt.y * 0.065) + int(window_pt.y * 0.065)
		);
		this->rects[2] = CRect(		// �̼�1
			int(window_pt.x * 0.15),
			int(window_pt.y * 0.483),
			int(window_pt.x * 0.15) + int(window_pt.x * 0.11),
			int(window_pt.y * 0.483) + int(window_pt.y * 0.035)
		);
		this->rects[3] = CRect(		// �̼�2
			int(window_pt.x * 0.15),
			int(window_pt.y * 0.538),
			int(window_pt.x * 0.15) + int(window_pt.x * 0.11),
			int(window_pt.y * 0.538) + int(window_pt.y * 0.035)
		);
		this->rects[4] = CRect(		// �̼�3
			int(window_pt.x * 0.15),
			int(window_pt.y * 0.593),
			int(window_pt.x * 0.15) + int(window_pt.x * 0.11),
			int(window_pt.y * 0.593) + int(window_pt.y * 0.035)
		);
		this->rects[5] = CRect(		// �̼� - ���� ���
			int(window_pt.x * 0.15),
			int(window_pt.y * 0.648),
			int(window_pt.x * 0.15) + int(window_pt.x * 0.11),
			int(window_pt.y * 0.648) + int(window_pt.y * 0.07)
		);
		if (this->screenType == SCR_PAYMENT_1 || this->screenType == SCR_PAYMENT_2) { // ����ȭ��
			for (int i = 0; i < 3; i++) {
				this-> rects[6+i] = CRect( //�ֹ����� 1, 2, 3
					int(window_pt.x * 0.387),
					int(window_pt.y * 0.176) + int((window_pt.y * 0.05) * i),
					int(window_pt.x * 0.387) + int(window_pt.x * 0.07),
					int(window_pt.y * 0.176) + int((window_pt.y * 0.05) * (i+1))
				);
				this->rects[9 + i] = CRect( // �ݾ� 1, 2, 3
					int(window_pt.x * 0.45),
					int(window_pt.y * 0.178) + int((window_pt.y * 0.051) * i),
					int(window_pt.x * 0.45) + int(window_pt.x * 0.05),
					int(window_pt.y * 0.178) + int((window_pt.y * 0.051) * (i + 1))
				);
			}
			this->rects[12] = CRect( // �ֹ��ݾ�
				int(window_pt.x * 0.44),
				int(window_pt.y * 0.426),
				int(window_pt.x * 0.44) + int(window_pt.x * 0.055),
				int(window_pt.y * 0.426) + int(window_pt.y * 0.032)
			);
			this->rects[13] = CRect( // ���αݾ�
				int(window_pt.x * 0.44),
				int(window_pt.y * 0.46),
				int(window_pt.x * 0.44) + int(window_pt.x * 0.055),
				int(window_pt.y * 0.46) + int(window_pt.y * 0.032)
			);
			this->rects[14] = CRect( // ������ �ݾ�
				int(window_pt.x * 0.456),
				int(window_pt.y * 0.508),
				int(window_pt.x * 0.456) + int(window_pt.x * 0.038),
				int(window_pt.y * 0.508) + int(window_pt.y * 0.029)
			);
			this->rects[15] = CRect( // ����
				int(window_pt.x * 0.508),
				int(window_pt.y * 0.172),
				int(window_pt.x * 0.508) + int(window_pt.x * 0.05),
				int(window_pt.y * 0.172) + int(window_pt.y * 0.142)
			);
			this->rects[16] = CRect( // ����
				int(window_pt.x * 0.558),
				int(window_pt.y * 0.172),
				int(window_pt.x * 0.558) + int(window_pt.x * 0.05),
				int(window_pt.y * 0.172) + int(window_pt.y * 0.142)
			);
			this->rects[17] = CRect( // �ſ�üũī��
				int(window_pt.x * 0.51),
				int(window_pt.y * 0.36),
				int(window_pt.x * 0.51) + int(window_pt.x * 0.03),
				int(window_pt.y * 0.36) + int(window_pt.y * 0.235)
			);
			this->rects[18] = CRect( // ����� ���ڵ�
				int(window_pt.x * 0.542),
				int(window_pt.y * 0.36),
				int(window_pt.x * 0.542) + int(window_pt.x * 0.03),
				int(window_pt.y * 0.36) + int(window_pt.y * 0.235)
			);
			this->rects[19] = CRect( // �Ｚ����
				int(window_pt.x * 0.575),
				int(window_pt.y * 0.36),
				int(window_pt.x * 0.575) + int(window_pt.x * 0.03),
				int(window_pt.y * 0.36) + int(window_pt.y * 0.235)
			);
			this->rects[20] = CRect(		// ���ڵ�
				int(window_pt.x * 0.465),
				int(window_pt.y * 0.737),
				int(window_pt.x * 0.465) + int(window_pt.x * 0.073),
				int(window_pt.y * 0.737) + int(window_pt.y * 0.243)
			);
			this->rects[21] = CRect(		// ī�����Ա�
				int(window_pt.x * 0.538),
				int(window_pt.y * 0.737),
				int(window_pt.x * 0.538) + int(window_pt.x * 0.073),
				int(window_pt.y * 0.737) + int(window_pt.y * 0.114)
			);
			this->rects[22] = CRect(		// �Ｚ����
				int(window_pt.x * 0.538),
				int(window_pt.y * 0.852),
				int(window_pt.x * 0.538) + int(window_pt.x * 0.073),
				int(window_pt.y * 0.852) + int(window_pt.y * 0.115)
			);
			this->rects[23] = CRect(		// �������
				int(window_pt.x * 0.497),
				int(window_pt.y * 0.662),
				int(window_pt.x * 0.497) + int(window_pt.x * 0.051),
				int(window_pt.y * 0.662) + int(window_pt.y * 0.026)
			);
			this->rects[24] = CRect(		// �߰��ֹ�
				int(window_pt.x * 0.55),
				int(window_pt.y * 0.662),
				int(window_pt.x * 0.55) + int(window_pt.x * 0.051),
				int(window_pt.y * 0.662) + int(window_pt.y * 0.026)
			);
		}//@
		else {
			/* �޴� ȭ�� ���� Rect */
			this->rects[6] = CRect(		// ���� <
				int(window_pt.x * 0.385),
				int(window_pt.y * 0.06),
				int(window_pt.x * 0.385) + int(window_pt.x * 0.015),
				int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
			);
			this->rects[7] = CRect(		// ������ > 
				int(window_pt.x * 0.6),
				int(window_pt.y * 0.06),
				int(window_pt.x * 0.6) + int(window_pt.x * 0.015),
				int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
			);
			
			if (this->screenType == SCR_SET_DESSERT || this->screenType == SCR_SET_DRINK) {
				/* ��Ʈ �޴� ���� ȭ�� */
				this->rects[8] = CRect(		// ��Ʈ_����Ʈ
					int(window_pt.x * 0.417),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.417) + int(window_pt.x * 0.067),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				this->rects[9] = CRect(		// ��Ʈ_����
					int(window_pt.x * 0.507),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.507) + int(window_pt.x * 0.067),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				for (int i = 0; i < 8; i++) { // �޴�
					this->rects[10 + i] = CRect(
						int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * (i % 2)),
						int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * (i / 2)),
						int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * ((i % 2) + 1)),
						int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * ((i / 2) + 1))
					);
				}
				this->rects[18] = CRect( // ����ϱ�
					int(window_pt.x * 0.4),
					int(window_pt.y * 0.655),
					int(window_pt.x * 0.4) + int(window_pt.x * 0.067),
					int(window_pt.y * 0.655) + int(window_pt.y * 0.059)
				);
				this->rects[19] = CRect( // �����ϱ�
					int(window_pt.x * 0.533),
					int(window_pt.y * 0.655),
					int(window_pt.x * 0.533) + int(window_pt.x * 0.067),
					int(window_pt.y * 0.655) + int(window_pt.y * 0.059)
				);
			}
			else {
				/* �⺻ �޴� ���� ȭ�� */
				for (int i = 0; i < 3; i++) {
					this->rects[8+i] = CRect(		// �ֹ�����1,2,3
						int(window_pt.x * 0.4),
						int(window_pt.y * 0.596) + int(window_pt.y * 0.03 * i),
						int(window_pt.x * 0.4) + int(window_pt.x * 0.227),
						int(window_pt.y * 0.596) + int(window_pt.y * 0.03 * (i+1))
					);
				}
				this->rects[11] = CRect(		// �ܹ���
					int(window_pt.x * 0.41),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.41) + int(window_pt.x * 0.045),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				this->rects[12] = CRect(		// ġŲ
					int(window_pt.x * 0.455),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.455) + int(window_pt.x * 0.045),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				this->rects[13] = CRect(		// ����Ʈ
					int(window_pt.x * 0.5),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.5) + int(window_pt.x * 0.045),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				this->rects[14] = CRect(		// ����/Ŀ��
					int(window_pt.x * 0.545),
					int(window_pt.y * 0.06),
					int(window_pt.x * 0.545) + int(window_pt.x * 0.045),
					int(window_pt.y * 0.06) + int(window_pt.y * 0.075)
				);
				this->rects[15] = CRect(		// �ֹ�����(��)
					int(window_pt.x * 0.445),
					int(window_pt.y * 0.557),
					int(window_pt.x * 0.445) + int(window_pt.x * 0.04),
					int(window_pt.y * 0.557) + int(window_pt.y * 0.03)
				);
				this->rects[16] = CRect(		// �ݾ�(����)
					int(window_pt.x * 0.5),
					int(window_pt.y * 0.557),
					int(window_pt.x * 0.5) + int(window_pt.x * 0.11),
					int(window_pt.y * 0.557) + int(window_pt.y * 0.03)
				);
				this->rects[17] = CRect(		// ����ϱ�
					int(window_pt.x * 0.5),
					int(window_pt.y * 0.687),
					int(window_pt.x * 0.5) + int(window_pt.x * 0.052),
					int(window_pt.y * 0.687) + int(window_pt.y * 0.031)
				);
				this->rects[18] = CRect(		// �����ϱ�
					int(window_pt.x * 0.556),
					int(window_pt.y * 0.687),
					int(window_pt.x * 0.556) + int(window_pt.x * 0.052),
					int(window_pt.y * 0.687) + int(window_pt.y * 0.031)
				);
				this->rects[19] = CRect(		// ���ڵ�
					int(window_pt.x * 0.463),
					int(window_pt.y * 0.737),
					int(window_pt.x * 0.463) + int(window_pt.x * 0.073),
					int(window_pt.y * 0.737) + int(window_pt.y * 0.243)
				);
				this->rects[20] = CRect(		// ī�����Ա�
					int(window_pt.x * 0.536),
					int(window_pt.y * 0.737),
					int(window_pt.x * 0.536) + int(window_pt.x * 0.073),
					int(window_pt.y * 0.737) + int(window_pt.y * 0.114)
				);
				this->rects[21] = CRect(		// �Ｚ����
					int(window_pt.x * 0.536),
					int(window_pt.y * 0.852),
					int(window_pt.x * 0.536) + int(window_pt.x * 0.073),
					int(window_pt.y * 0.852) + int(window_pt.y * 0.115)
				);
				if (this->screenType == SCR_CHICKEN) { // �޴� 6��
					for (int i = 0; i < 6; i++) {
						this->rects[22 + i] = CRect(
							int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * (i % 2)),
							int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * (i / 2)),
							int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * ((i % 2) + 1)),
							int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * ((i / 2) + 1))
						);
					}
				}
				else { // �޴� 8��
					for (int i = 0; i < 8; i++) {
						this->rects[22 + i] = CRect(
							int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * (i % 2)),
							int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * (i / 2)),
							int(window_pt.x * 0.385) + (int(window_pt.x * 0.113) * ((i % 2) + 1)),
							int(window_pt.y * 0.142) + (int(window_pt.y * 0.096) * ((i / 2) + 1))
						);
					}
				}
			}
		}
		
	}	
}