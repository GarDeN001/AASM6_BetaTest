﻿#include "AASM6.h"
#include "Extensions.h"

namespace AASM6
{
	//График при zeta = 0, eta = inf 
	float Coordinate_zz_v_1(float M, float lambda_c, float chi_05, InputComplex& x_2, InputComplex& x_1)
	{
		static unsigned int Length_3_1 = 49; static float Matrix_3_1[][2] = { {-3.5f,0.710112242105263f}, {-3.25f,0.720384475757828f}, {-3.0f,0.729424671037689f}, {-2.75f,0.737391297186021f}, {-2.5f,0.744422155983204f}, {-2.25f,0.750638728329581f}, {-2.0f,0.756149527621197f}, {-1.75f,0.761052734524203f}, {-1.5f,0.765438311571856f}, {-1.25f,0.769389742870524f}, {-1.0f,0.772985492043129f}, {-0.75f,0.77630026269695f}, {-0.5f,0.779406117511282f}, {-0.25f,0.782373503337182f}, {0.0f,0.785272227960149f}, {0.25f,0.780340937674114f}, {0.5f,0.773329137473399f}, {0.75f,0.764016362410165f}, {1.0f,0.752125364135331f}, {1.25f,0.737297090865829f}, {1.5f,0.719048814712553f}, {1.75f,0.696698521137844f}, {2.0f,0.669214142962817f}, {2.25f,0.657745327035449f}, {2.5f,0.64776096122182f}, {2.75f,0.639030495681641f}, {3.0f,0.631363172084406f}, {3.25f,0.624597710181774f}, {3.5f,0.618594989652969f}, {3.75f,0.613232656897961f}, {4.0f,0.6084010512997f}, {4.25f,0.604000006442044f}, {4.5f,0.59993626248918f}, {4.75f,0.596130834399844f}, {5.0f,0.592559644903333f}, {5.25f,0.589216885950171f}, {5.5f,0.586096793825067f}, {5.75f,0.583193627984222f}, {6.0f,0.580501675349495f}, {6.25f,0.578015247815115f}, {6.5f,0.575728686505011f}, {6.75f,0.573636357329474f}, {7.0f,0.571732657352876f}, {7.25f,0.570012010091121f}, {7.5f,0.56846886842375f}, {7.75f,0.567097715604628f}, {8.0f,0.565893064184069f}, {8.25f,0.564849457161514f}, {8.5f,0.563961469041212f} };
		static unsigned int Length_3_2 = 34; static float Matrix_3_2[][2] = { {-3.5f,0.73849402631579f}, {-3.25f,0.745617394108381f}, {-3.0f,0.751834990545646f}, {-2.75f,0.757246403252759f}, {-2.5f,0.761941741022291f}, {-2.25f,0.766003337830621f}, {-2.0f,0.769507157578453f}, {-1.75f,0.772523971241498f}, {-1.5f,0.775120356408642f}, {-1.25f,0.777359571276354f}, {-1.0f,0.77930232777388f}, {-0.75f,0.781007496399426f}, {-0.5f,0.782532765088852f}, {-0.25f,0.783935271011964f}, {0.0f,0.785272227960149f}, {4.0f,0.786766087859733f}, {4.25f,0.769614531262349f}, {4.5f,0.754987066717354f}, {4.75f,0.74238876797265f}, {5.0f,0.731456357617118f}, {5.25f,0.721912734422362f}, {5.5f,0.713539776892249f}, {5.75f,0.706161076826732f}, {6.0f,0.699630518636337f}, {6.25f,0.693824391250314f}, {6.5f,0.688635766794639f}, {6.75f,0.683970329464903f}, {7.0f,0.67974320854762f}, {7.25f,0.675876435002615f}, {7.5f,0.672296855619158f}, {7.75f,0.668934299140428f}, {8.0f,0.665719883200377f}, {8.25f,0.662584340116583f}, {8.5f,0.659456250470141f} };

		//Значения по комплексу x2
		const float x2_min = 0.0f;
		const float x2_max = 2.0f;

		//Входной комплекс x2
		float x2 = lambda_c * tan(chi_05);

		x_2.Min = x2_min;
		x_2.Value = x2;
		x_2.Max = x2_max;

		//Ограничение по диапазону x2	
		if (x2 < x2_min)
			x2 = x2_min;
		else if (x2 > x2_max)
			x2 = x2_max;

		//Входной комплекс x1
		const float x1_min = -3.5f;
		const float x1_max = 8.5f;
		//Координата по оси х графика
		float x1;
		if (M >= 1)
			x1 = lambda_c * sqrt(sqr(M) - 1.0f);
		else
			x1 = -lambda_c * sqrt(1.0f - sqr(M));

		x_1.Min = x1_min;
		x_1.Value = x1;
		x_1.Max = x1_max;

		//Ограничение по диапазону оси x	
		if (x1 < x1_min)
			x1 = x1_min;
		else if (x1 > x1_max)
			x1 = x1_max;

		//Вычисление
		if (x2 == x2_min)
		{
			//Используем кривую 1		
			float y = Linterp(Matrix_3_1, Length_3_1, x1);

			return y;
		}
		else if (x2_min <= x2 && x2 < x2_max)
		{
			//Интерполяция между кривыми 1 и 2		
			float y1 = Linterp(Matrix_3_1, Length_3_1, x1);
			float y2 = Linterp(Matrix_3_2, Length_3_2, x1);

			return LinterpOnce(x2_min, y1, x2_max, y2, x2);
		}
		else if (x2 == x2_max)
		{
			//Используем кривую 2	
			float y = Linterp(Matrix_3_2, Length_3_2, x1);

			return y;
		}
		else
			return NAN;
	}

	//График при zeta = 0.5, eta = 2 
	float Coordinate_zz_v_2(float M, float lambda_c, float chi_05, InputComplex& x_2, InputComplex& x_1)
	{
		static unsigned int Length_2_1 = 36; static float Matrix_2_1[][2] = { {-3.5f,0.775459757894737f}, {0.0f,0.785272227960149f}, {0.25f,0.783195368164047f}, {0.5f,0.780353219616061f}, {0.75f,0.776471432300292f}, {1.0f,0.771210741920184f}, {1.25f,0.764105709954227f}, {1.5f,0.754449546488542f}, {1.75f,0.741028624457077f}, {2.0f,0.721334806313447f}, {2.25f,0.727790248178932f}, {2.5f,0.733432046457573f}, {2.75f,0.738345917987521f}, {3.0f,0.742611423686648f}, {3.25f,0.746302955214706f}, {3.5f,0.749490570692096f}, {3.75f,0.752240733005109f}, {4.0f,0.754616953444644f}, {4.25f,0.756680374066188f}, {4.5f,0.758490293477062f}, {4.75f,0.760098023843127f}, {5.0f,0.761570237618637f}, {5.25f,0.762890597878398f}, {5.5f,0.76405817430732f}, {5.75f,0.765065411554304f}, {6.0f,0.765904767052259f}, {6.25f,0.766568712962488f}, {6.5f,0.767049736659777f}, {6.75f,0.76734034300208f}, {7.0f,0.767433054355106f}, {7.25f,0.767320412770269f}, {7.5f,0.766994980576392f}, {7.75f,0.766449341875306f}, {8.0f,0.765676103600608f}, {8.25f,0.764667896490857f}, {8.5f,0.763417377138639f} };
		static unsigned int Length_2_2 = 36; static float Matrix_2_2[][2] = { {-3.5f,0.775459757894737f}, {0.0f,0.785272227960149f}, {0.25f,0.785977919812586f}, {0.5f,0.786722575225822f}, {0.75f,0.787588851138177f}, {1.0f,0.788756655885707f}, {1.25f,0.790558288691795f}, {1.5f,0.793317498278533f}, {1.75f,0.796924083665033f}, {2.0f,0.802298044510173f}, {2.25f,0.810505482791135f}, {2.5f,0.821641847617244f}, {2.75f,0.834662631508346f}, {3.0f,0.836618633458695f}, {3.25f,0.838537897479138f}, {3.5f,0.8401517129859f}, {3.75f,0.841193473058054f}, {4.0f,0.841397062780504f}, {4.25f,0.840584670245736f}, {4.5f,0.838818798853857f}, {4.75f,0.836198657365036f}, {5.0f,0.832936959788207f}, {5.25f,0.829441609228354f}, {5.5f,0.826145087326237f}, {5.75f,0.823443999787715f}, {6.0f,0.821369335307904f}, {6.25f,0.819726058923192f}, {6.5f,0.818321197383607f}, {6.75f,0.816977033332224f}, {7.0f,0.815663937972056f}, {7.25f,0.814449941755663f}, {7.5f,0.813404765677037f}, {7.75f,0.812597895124181f}, {8.0f,0.812098399418758f}, {8.25f,0.811974752385732f}, {8.5f,0.811970455014827f} };
		static unsigned int Length_2_3 = 49; static float Matrix_2_3[][2] = { {-3.5f,0.831546281578947f}, {-3.25f,0.832649794852326f}, {-3.0f,0.833611970570036f}, {-2.75f,0.834375467598546f}, {-2.5f,0.834882935863681f}, {-2.25f,0.835076629368982f}, {-2.0f,0.834898018848543f}, {-1.75f,0.834287395552183f}, {-1.5f,0.833183458235332f}, {-1.25f,0.831540876747343f}, {-1.0f,0.829549798289257f}, {-0.75f,0.827569669557136f}, {-0.5f,0.825962142117351f}, {-0.25f,0.825080000662204f}, {0.0f,0.825209177055422f}, {0.25f,0.826535074072f}, {0.5f,0.829321008551103f}, {0.75f,0.833672771750339f}, {1.0f,0.84005949741539f}, {1.25f,0.848540548080433f}, {1.5f,0.859139835305613f}, {1.75f,0.871891034247527f}, {2.0f,0.886854379169574f}, {2.25f,0.90424149845579f}, {2.5f,0.923766933919282f}, {2.75f,0.939326294322988f}, {3.0f,0.949899872867981f}, {3.25f,0.958409676035555f}, {3.5f,0.966120717845676f}, {3.75f,0.973343068927443f}, {4.0f,0.979778221966399f}, {4.25f,0.969669722022474f}, {4.5f,0.960554611555146f}, {4.75f,0.952302071712454f}, {5.0f,0.94481725166911f}, {5.25f,0.938015842410863f}, {5.5f,0.931822157383871f}, {5.75f,0.926167562624204f}, {6.0f,0.920989221323691f}, {6.25f,0.916229044670052f}, {6.5f,0.911832819879752f}, {6.75f,0.907749451936686f}, {7.0f,0.903930319770464f}, {7.25f,0.900328682732465f}, {7.5f,0.896899156942869f}, {7.75f,0.893597214675163f}, {8.0f,0.890378704674727f}, {8.25f,0.887199376499506f}, {8.5f,0.884014397060402f} };

		//Значения по комплексу x2
		const float x2_min = 0.0f;
		const float x2_2 = 2.0f / 3.0f;
		const float x2_max = 2.0f;

		//Входной комплекс x2
		float x2 = lambda_c * tan(chi_05);

		x_2.Min = x2_min;
		x_2.Value = x2;
		x_2.Max = x2_max;

		//Ограничение по диапазону x2	
		if (x2 < x2_min)
			x2 = x2_min;
		else if (x2 > x2_max)
			x2 = x2_max;

		//Входной комплекс x1
		const float x1_min = -3.5f;
		const float x1_max = 8.5f;
		//Координата по оси х графика
		float x1;
		if (M >= 1)
			x1 = lambda_c * sqrt(sqr(M) - 1.0f);
		else
			x1 = -lambda_c * sqrt(1.0f - sqr(M));

		x_1.Min = x1_min;
		x_1.Value = x1;
		x_1.Max = x1_max;

		//Ограничение по диапазону оси x	
		if (x1 < x1_min)
			x1 = x1_min;
		else if (x1 > x1_max)
			x1 = x1_max;

		//Вычисление
		if (x2 == x2_min)
		{
			//Используем кривую 1		
			float y = Linterp(Matrix_2_1, Length_2_1, x1);

			return y;
		}
		else if (x2_min <= x2 && x2 < x2_2)
		{
			//Интерполяция между кривыми 1 и 2		
			float y1 = Linterp(Matrix_2_1, Length_2_1, x1);
			float y2 = Linterp(Matrix_2_2, Length_2_2, x1);

			return LinterpOnce(x2_min, y1, x2_2, y2, x2);
		}
		else if (x2_2 <= x2 && x2 < x2_max)
		{
			//Интерполяция между кривыми 2 и 3		
			float y1 = Linterp(Matrix_2_2, Length_2_2, x1);
			float y2 = Linterp(Matrix_2_3, Length_2_3, x1);

			return LinterpOnce(x2_2, y1, x2_max, y2, x2);
		}
		else if (x2 == x2_max)
		{
			//Используем кривую 4
			float y = Linterp(Matrix_2_3, Length_2_3, x1);

			return y;
		}
		else
			return NAN;
	}

	//График при zeta = 1, eta = 1 
	float Coordinate_zz_v_3(float M, float lambda_c, float chi_05, InputComplex& x_2, InputComplex& x_1)
	{
		static unsigned int Length_1_1 = 49; static float Matrix_1_1[][2] = { {-3.5f,0.819065855263158f}, {-3.25f,0.813886508603735f}, {-3.0f,0.809322398906702f}, {-2.75f,0.805324797040926f}, {-2.5f,0.801845475390549f}, {-2.25f,0.798836715615037f}, {-2.0f,0.796251317344203f}, {-1.75f,0.794042605229204f}, {-1.5f,0.792164437165355f}, {-1.25f,0.790571209912774f}, {-1.0f,0.789217866142581f}, {-0.75f,0.788059899933988f}, {-0.5f,0.787053362181199f}, {-0.25f,0.786154529827542f}, {0.0f,0.785272227960149f}, {0.25f,0.784217984110857f}, {0.5f,0.782788810325072f}, {0.75f,0.78077407955526f}, {1.0f,0.777949948949761f}, {1.25f,0.774072833819152f}, {1.5f,0.768871370907719f}, {1.75f,0.762036034570655f}, {2.0f,0.753205183896806f}, {2.25f,0.780413742132206f}, {2.5f,0.802242353715097f}, {2.75f,0.82051701034003f}, {3.0f,0.83620227146176f}, {3.25f,0.84988016791729f}, {3.5f,0.861932743270571f}, {3.75f,0.87262562823805f}, {4.0f,0.882151084258653f}, {4.25f,0.890647401485547f}, {4.5f,0.898217050986238f}, {4.75f,0.904947056097485f}, {5.0f,0.910912987901858f}, {5.25f,0.916181123659281f}, {5.5f,0.920810096974627f}, {5.75f,0.924852231293279f}, {6.0f,0.928354596995802f}, {6.25f,0.931359881695604f}, {6.5f,0.933907104408002f}, {6.75f,0.936032223873165f}, {7.0f,0.937768646993129f}, {7.25f,0.939147683140304f}, {7.5f,0.940198939312865f}, {7.75f,0.940950682851816f}, {8.0f,0.941430183407981f}, {8.25f,0.941664039943027f}, {8.5f,0.941678510696388f} };
		static unsigned int Length_1_2 = 49; static float Matrix_1_2[][2] = { {-3.5f,0.89370565f}, {-3.25f,0.886937196152605f}, {-3.0f,0.88114828731582f}, {-2.75f,0.875904892269425f}, {-2.5f,0.871065272360821f}, {-2.25f,0.866569278943288f}, {-2.0f,0.862392632442798f}, {-1.75f,0.858532263867951f}, {-1.5f,0.855001526508645f}, {-1.25f,0.851830148175413f}, {-1.0f,0.849068044505137f}, {-0.75f,0.846794460623485f}, {-0.5f,0.84513752360681f}, {-0.25f,0.844319358585955f}, {0.0f,0.84473738232463f}, {0.25f,0.846829199683807f}, {0.5f,0.850876646316395f}, {0.75f,0.856726638256932f}, {1.0f,0.863685869543269f}, {1.25f,0.870938416576938f}, {1.5f,0.878123217388574f}, {1.75f,0.88520168956574f}, {2.0f,0.89215040657208f}, {2.25f,0.898945438353518f}, {2.5f,0.905559461206091f}, {2.75f,0.911958991601535f}, {3.0f,0.91810113573088f}, {3.25f,0.923948274240567f}, {3.5f,0.929482968983241f}, {3.75f,0.934690662336791f}, {4.0f,0.939558470070228f}, {4.25f,0.944075642785106f}, {4.5f,0.948233993469752f}, {4.75f,0.952028282367669f}, {5.0f,0.955456493950929f}, {5.25f,0.958520024630864f}, {5.5f,0.961223713616363f}, {5.75f,0.963575750440402f}, {6.0f,0.965587439858725f}, {6.25f,0.967272851309025f}, {6.5f,0.968648377450676f}, {6.75f,0.969732239935327f}, {7.0f,0.970543966749328f}, {7.25f,0.971103886663555f}, {7.5f,0.97143265423009f}, {7.75f,0.971550833504645f}, {8.0f,0.971478547318083f}, {8.25f,0.971235197554322f}, {8.5f,0.970839255348194f} };
		static unsigned int Length_1_3 = 24; static float Matrix_1_3[][2] = { {-3.5f,1.0f}, {-3.25f,0.997763458367168f}, {-3.0f,0.995392877848563f}, {-2.75f,0.992797159141701f}, {-2.5f,0.989881956949148f}, {-2.25f,0.98655046551832f}, {-2.0f,0.98270430314735f}, {-1.75f,0.978244480443282f}, {-1.5f,0.973072430213542f}, {-1.25f,0.967091065812268f}, {-1.0f,0.960235172469489f}, {-0.75f,0.953026199040292f}, {-0.5f,0.946523764438563f}, {-0.25f,0.94180676551615f}, {0.0f,0.939937056004296f}, {0.25f,0.941344416270747f}, {0.5f,0.945596102705408f}, {0.75f,0.95216522222595f}, {1.0f,0.960516153783195f}, {1.25f,0.970131671300189f}, {1.5f,0.980534037270268f}, {1.75f,0.991298829061237f}, {1.95f,1.0f}, {8.5f,1.0f} };

		//Значения по комплексу x2
		const float x2_min = 0.0f;
		const float x2_1 = 2.0f;
		const float x2_max = 4.0f;

		//Входной комплекс x2
		float x2 = lambda_c * tan(chi_05);

		x_2.Min = x2_min;
		x_2.Value = x2;
		x_2.Max = x2_max;

		//Ограничение по диапазону x2	
		if (x2 < x2_min)
			x2 = x2_min;
		else if (x2 > x2_max)
			x2 = x2_max;

		//Входной комплекс x1
		const float x1_min = -3.5f;
		const float x1_max = 8.5f;
		//Координата по оси х графика
		float x1;
		if (M >= 1)
			x1 = lambda_c * sqrt(sqr(M) - 1.0f);
		else
			x1 = -lambda_c * sqrt(1.0f - sqr(M));

		x_1.Min = x1_min;
		x_1.Value = x1;
		x_1.Max = x1_max;

		//Ограничение по диапазону оси x	
		if (x1 < x1_min)
			x1 = x1_min;
		else if (x1 > x1_max)
			x1 = x1_max;

		//Вычисление
		if (x2 == x2_min)
		{
			//Используем кривую 1
			float y = Linterp(Matrix_1_1, Length_1_1, x1);
			return y;
		}
		else if (x2_min <= x2 && x2 < x2_1)
		{
			//Интерполяция между кривыми 1 и 2		
			float y1 = Linterp(Matrix_1_1, Length_1_1, x1);
			float y2 = Linterp(Matrix_1_2, Length_1_2, x1);

			return LinterpOnce(x2_min, y1, x2_1, y2, x2);
		}
		else if (x2_1 <= x2 && x2 < x2_max)
		{
			//Интерполяция между кривыми 2 и 3		
			float y1 = Linterp(Matrix_1_2, Length_1_2, x1);
			float y2 = Linterp(Matrix_1_3, Length_1_3, x1);

			return LinterpOnce(x2_1, y1, x2_max, y2, x2);
		}
		else if (x2 == x2_max)
		{
			//Используем кривую 3		
			float y = Linterp(Matrix_1_3, Length_1_3, x1);

			return y;
		}
		else
			return NAN;
	}

	float Coordinate_zz_v(float M, float lambda_c, float chi_05, float zeta_c, InputComplex& x_3, InputComplex& x_2, InputComplex& x_1)
	{
		//Значения по комплексу x3
		const float x3_min = 0.0f;
		const float x3_2 = 0.5f;
		const float x3_max = 1.0f;

		//Входной комплекс x3
		float x3 = zeta_c;

		x_3.Min = x3_min;
		x_3.Value = x3;
		x_3.Max = x3_max;

		//Ограничение по диапазону x3	
		if (x3 < x3_min)
			x3 = x3_min;
		else if (x3 > x3_max)
			x3 = x3_max;

		//Вычисление
		if (x3 == x3_min)
		{
			//Используем 1-ый график
			float y = Coordinate_zz_v_1(M, lambda_c, chi_05, x_2, x_1);

			return y;
		}
		else if (x3_min <= x3 && x3 < x3_2)
		{
			//Интерполяция между 1-м и 2-м графиком
			float y1 = Coordinate_zz_v_1(M, lambda_c, chi_05, x_2, x_1);
			float y2 = Coordinate_zz_v_2(M, lambda_c, chi_05, x_2, x_1);

			return LinterpOnce(x3_min, y1, x3_2, y2, x3);
		}
		else if (x3_2 <= x3 && x3 < x3_max)
		{
			//Интерполяция между 2-м и 3-м графиком
			float y1 = Coordinate_zz_v_2(M, lambda_c, chi_05, x_2, x_1);
			float y2 = Coordinate_zz_v_3(M, lambda_c, chi_05, x_2, x_1);

			return LinterpOnce(x3_2, y1, x3_max, y2, x3);
		}
		else if (x3 == x3_max)
		{
			//Используем 3-ий график
			float y = Coordinate_zz_v_3(M, lambda_c, chi_05, x_2, x_1);

			return y;
		}
		else
			return NAN;
	}

	ErrorCode* get_Coordinate_zz_v(float& Result, float M, float lambda_c, float chi_05, float zeta_c, InputComplex& x_3, InputComplex& x_2, InputComplex& x_1)
	{
		static ErrorCode ErrC;
		// Проверка: некоторые аргументы не должны быть меньше 0		
		if (M < 0.0f)
		{
			ErrC.ArgNumber = 1;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (lambda_c < 0.0f)
		{
			ErrC.ArgNumber = 2;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (chi_05 < 0.0f)
		{
			ErrC.ArgNumber = 3;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (zeta_c < 0.0f)
		{
			ErrC.ArgNumber = 4;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}

		// Проверка: некоторые аргументы не должны быть больше 1	
		if (zeta_c > 1.0f)
		{
			ErrC.ArgNumber = 4;
			ErrC.Code = ErrC_ArgMustNotBeGT1;
			return &ErrC;
		}

		// Проверка: некоторые аргументы не должны быть больше 90 градусов	
		if (chi_05 > 90.0f / deg)
		{
			ErrC.ArgNumber = 3;
			ErrC.Code = ErrC_AngleMustBeLT90deg;
			return &ErrC;
		}

		// Вызываем функцию интерполяции графика
		Result = Coordinate_zz_v(M, lambda_c, chi_05, zeta_c, x_3, x_2, x_1);
		ErrC.ArgNumber = ErrC_OK;
		ErrC.Code = ErrC_OK;

		return &ErrC;
	}
}