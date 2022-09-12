#include "AASM6.h"
#include "Extensions.h"

namespace AASM6
{
	float Cx_Cil_N(float M, float alpha, InputComplex& x_1)
	{
		static unsigned int Length_1_1 = 52; static float Matrix_1_1[][2] = { {0.0f,0.463098076788116f}, {0.05f,0.467780037542407f}, {0.1f,0.47524687989581f}, {0.15f,0.490747106253597f}, {0.2f,0.513504864517727f}, {0.25f,0.544381504461633f}, {0.3f,0.59301828394591f}, {0.325f,0.622939881628638f}, {0.35f,0.668408297234503f}, {0.375f,0.735303229156179f}, {0.4f,0.822744728676965f}, {0.425f,0.923833591018805f}, {0.45f,1.02052210978788f}, {0.475f,1.10443541180818f}, {0.5f,1.16688426951767f}, {0.525f,1.21659981412677f}, {0.55f,1.26219344898843f}, {0.575f,1.29562667078424f}, {0.6f,1.32074253754121f}, {0.625f,1.33987011086503f}, {0.65f,1.3573063275018f}, {0.675f,1.37090335961846f}, {0.7f,1.38101515446763f}, {0.75f,1.39685406698503f}, {0.8f,1.40370359421514f}, {0.85f,1.40370432301197f}, {0.9f,1.39829218205472f}, {1.0f,1.38460376663919f}, {1.1f,1.36874198182052f}, {1.2f,1.35288019700185f}, {1.4f,1.32415926975816f}, {1.5f,1.31104206395208f}, {1.6f,1.30196582597894f}, {1.7f,1.292252172832f}, {1.8f,1.28486381930202f}, {1.9f,1.28212981430917f}, {2.0f,1.2798944056506f}, {2.2f,1.27626908421439f}, {2.4f,1.27503359365153f}, {2.6f,1.27542103003869f}, {2.8f,1.27575102511593f}, {3.0f,1.27559374584107f}, {3.2f,1.27520760524322f}, {3.4f,1.27472280181491f}, {3.6f,1.27418764705678f}, {3.8f,1.27362332432331f}, {4.0f,1.27304060140645f}, {4.2f,1.27244556638185f}, {4.4f,1.27184193893975f}, {4.6f,1.27123212817366f}, {4.8f,1.27061776640769f}, {5.0f,1.27f} };

		//������� �������� x1
		const float x1_min = 0.0f;
		const float x1_max = 5.0f;

		//���������� �� ��� � �������
		float x1 = M * sinf(alpha);

		x_1.Min = x1_min;
		x_1.Value = x1;
		x_1.Max = x1_max;

		//����������� �� ��������� ��� x
		if (x1 < x1_min)
			x1 = x1_min;
		else if (x1 > x1_max)
			x1 = x1_max;

		//����������
		float y = Linterp(Matrix_1_1, Length_1_1, x1);

		return y;
	}

	ErrorCode* get_Cx_Cil_N(float& Result, float M, float alpha, InputComplex& x_1)
	{
		static ErrorCode ErrC;
		// ��������: ��������� ��������� �� ������ ���� ������ 0		
		if (M < 0.0f)
		{
			ErrC.ArgNumber = 1;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (alpha < 0.0f)
		{
			ErrC.ArgNumber = 2;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}

		// ��������: ��������� ��������� �� ������ ���� ������ 90 ��������	
		if (alpha > 90.0f / deg)
		{
			ErrC.ArgNumber = 2;
			ErrC.Code = ErrC_AngleMustBeLT90deg;
			return &ErrC;
		}

		// �������� ������� ������������ �������
		Result = Cx_Cil_N(M, alpha, x_1);
		ErrC.ArgNumber = ErrC_OK;
		ErrC.Code = ErrC_OK;

		return &ErrC;
	}
}