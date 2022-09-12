#include "pch.h"
#include "MCADINCL.H"
#include "..\AASM6_Library\AASM6\AASM6.h"
#include "ErrorMessages.h"
#include "Extensions.h"

// ����������� ������� (������������ �������� ����������� ��� ������ ��������, ����� - ������� ���������)
LRESULT MCDi_Cxdon_Cil(COMPLEXARRAY* const retVal,	// ������������ ������
	LPCCOMPLEXSCALAR    M,							// 1-� ��������
	LPCCOMPLEXSCALAR    cc,							// 2-� ��������
	LPCCOMPLEXSCALAR    Re_f06,						// 3-� ��������
	LPCCOMPLEXSCALAR    Re_f,						// 4-� ��������
	LPCCOMPLEXSCALAR    xx_tf,						// 5-� ��������
	LPCCOMPLEXSCALAR    lambda_f)					// 6-� ��������	
{
	// ��������: ��� ��������� ������ ���� ��������������� ������� (������ ����� = 0),
	// ����� ���������� ������ �1 ��� i-��� ���������
	if (M->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 1);
	if (cc->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 2);
	if (Re_f06->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 3);
	if (Re_f->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 4);
	if (xx_tf->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 5);
	if (lambda_f->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 6);

	float result;
	AASM6::ErrorCode* ErrC; //��������� �� ��������� ��� ��������� ���� ������, ������������� �� �������
	AASM6::InputComplex x_1, x_2; //���������� ��� ��������� �������� � ������ ������� ����������, ������������ � �������
	//�������� ������� ������������ �������
	ErrC = AASM6::get_Cxdon_Cil(result, M->real, cc->real, Re_f06->real, Re_f->real, xx_tf->real, lambda_f->real, x_2, x_1);

	//�������� �� ������� �� ������� ������
	if (ErrC->Code != 0) //���� ������
	{
		return MAKELRESULT(ErrC->Code, ErrC->ArgNumber);
	}

	//��������� ������� ���������� ��� ������ � ����������� ����� ��� �������
	COMPLEXSCALAR x_1_mcd = InputComplexToComplexScalar(x_1);
	COMPLEXSCALAR x_2_mcd = InputComplexToComplexScalar(x_2);

	// ��������� ������ ��� ������������ ������ (����� ������� = 1 (���������) + ���������� ������� ����������)
	if (!MathcadArrayAllocate(retVal, (unsigned int)3, (unsigned int)1, TRUE, TRUE))
	{
		// ��� ��������� ��������� ���������� ������
		return MAKELRESULT(ErrMsg::ErrC_MemAlloc, 0);
	}

	// ��� �������� ��������� ��������� �������� �������
	// 0 �������, �������������� ����� - ���������
	retVal->hReal[0][0] = result;	retVal->hImag[0][0] = 0;

	// ��������� �������� - ������� ���������. �������������� ����� - ������� ��������,
	// ������ ����� - ��������� �������� (������� ��� ������ ������� �� ������� �������� ���������)	
	retVal->hReal[0][1] = x_2_mcd.real;		retVal->hImag[0][1] = x_2_mcd.imag;
	retVal->hReal[0][2] = x_1_mcd.real;		retVal->hImag[0][2] = x_1_mcd.imag;

	return 0;
}

FUNCTIONINFO AASM6_Cxdon_Cil = {
	"AASM6_Cxdon_Cil",					// ��� �� �������� ������� ����� ���������� � Mathcad
	"\n1: M - ����� ����, -; \n2: cc - ������������� ������� ������� ������ ������� �����������, -; \n3: Re_f06 - ����� ���������� ��� �������� ��� ��������, ��������������� �=0.6, -; \n4: Re_f - ����� ���������� ��� �������� ��� ��������, ��������������� �, -; \n5: xx_tf - ������������� ���������� ����� �������� ����������� ������������ ���� � ������������ �� ��������, -; \n6: lambda_f - ��������� ��������, -",				// ������ ������� ���������� �������
	"\n\n������� ��� ����������� ������������ ������� ������������� �������� � �������������� �������� ������, -", // �������� �������
	(LPCFUNCTION)MCDi_Cxdon_Cil,			// ������ �� ����������� ���

	// 1) ��� ������������ � Mathcad ������ - ������ ����������� �����
	// 2) ���������� ������� ���������� �������
	COMPLEX_ARRAY, 6,

	// ��� ��� ������� �������� ���������, ��� ���� - ����������� ����� (������)
	{COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR}
};