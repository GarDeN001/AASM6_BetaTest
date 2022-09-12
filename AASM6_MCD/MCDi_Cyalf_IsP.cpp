﻿#include "pch.h"
#include "MCADINCL.H"
#include "..\AASM6_Library\AASM6\AASM6.h"
#include "ErrorMessages.h"
#include "Extensions.h"

// Исполняемая функция (возвращаемое значение объявляется как первый аргумент, затем - входные аргументы)
LRESULT MCDi_Cyalf_IsP(COMPLEXARRAY* const retVal,	// Возвращаемый массив
	LPCCOMPLEXSCALAR    M,						// 1-й аргумент
	LPCCOMPLEXSCALAR    lambda_c,				// 2-й аргумент
	LPCCOMPLEXSCALAR    cc,						// 3-й аргумент
	LPCCOMPLEXSCALAR    chi_05,					// 4-й аргумент
	LPCCOMPLEXSCALAR    eta_c)					// 5-й аргумент
{

	// Проверка: все аргументы должны быть действительными числами (мнимая часть = 0),
	// иначе вовзращаем ошибку №1 для i-ого аргумента
	if (M->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 1);
	if (lambda_c->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 2);
	if (cc->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 3);
	if (chi_05->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 4);
	if (eta_c->imag != 0.0)
		return MAKELRESULT(ErrMsg::ErrC_NumberMustBeReal, 5);

	float result;
	AASM6::ErrorCode* ErrC; //Указатель на структуру для получения кода ошибки, возвращаемого из функции
	AASM6::InputComplex x_1, x_2, x_3; //Переменные для получения значений и границ входных комплексов, рассчитанных в функции
	//Вызываем функцию интерполяции графика
	ErrC = AASM6::get_Cyalf_IsP(result, M->real, lambda_c->real, cc->real, chi_05->real, eta_c->real, x_3, x_2, x_1);

	//Проверка не вернула ли функция ошибку
	if (ErrC->Code != 0) //Есть ошибка
	{
		return MAKELRESULT(ErrC->Code, ErrC->ArgNumber);
	}

	//Обработка входных комплексов под запись в комплексное число для маткада
	COMPLEXSCALAR x_1_mcd = InputComplexToComplexScalar(x_1);
	COMPLEXSCALAR x_2_mcd = InputComplexToComplexScalar(x_2);
	COMPLEXSCALAR x_3_mcd = InputComplexToComplexScalar(x_3);

	// Выделение памяти под возвращаемый массив (длина массива = 1 (результат) + количество входных комплексов)
	if (!MathcadArrayAllocate(retVal, (unsigned int)4, (unsigned int)1, TRUE, TRUE))
	{
		// При неудачном выделении возвращаем ошибку
		return MAKELRESULT(ErrMsg::ErrC_MemAlloc, 0);
	}

	// При успешном выделении заполняем элементы массива
	// 0 элемент, действительная часть - результат
	retVal->hReal[0][0] = result;	retVal->hImag[0][0] = 0;

	// следующие элементы - входные комплексы. Действительная часть - текущее значение,
	// мнимая часть - граничное значение (верхняя или нижняя граница по данному входному комплексу)
	retVal->hReal[0][1] = x_3_mcd.real;		retVal->hImag[0][1] = x_3_mcd.imag;
	retVal->hReal[0][2] = x_2_mcd.real;		retVal->hImag[0][2] = x_2_mcd.imag;
	retVal->hReal[0][3] = x_1_mcd.real;		retVal->hImag[0][3] = x_1_mcd.imag;

	return 0;
}

FUNCTIONINFO AASM6_Cyalf_IsP = {
	"AASM6_Cyalf_IsP",					// Имя по которому функция будет вызываться в Mathcad
	"\n1: M - число Маха, -; \n2: lambda_c - удлинение консолей, -; \n3: cc - относительная толщина профиля, -; \n4: chi_05 - угол стреловидности по линии середин хорд, рад; \n4: eta_c - сужение консолей, -",			// Список входных параметров функции
	"\n\nФункция для определения производной по углу атаки коэффициента подъёмной силы изолированной несущей поверхности, 1/рад", // Описание функции
	(LPCFUNCTION)MCDi_Cyalf_IsP,		// Ссылка на исполняемый код

	// 1) Тип возвращаемых в Mathcad данных - массив комплексных чисел
	// 2) Количество входных аргументов функции
	COMPLEX_ARRAY, 5,

	// Тип для каждого входного аргумента, для всех - комплексное число (скаляр)
	{COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR, COMPLEX_SCALAR}
};