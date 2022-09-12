#include "AASM6.h"
#include "Extensions.h"

namespace AASM6
{
	float Re_t0_1(float M, float Re, float hh, InputComplex& x_2, InputComplex& x_1)
	{
		// 1_1: M = 0, 1_2: M = 1, 1_3: M = 2, 1_4: M = 3, 1_5: M = 4, 1_6: M = 5
		static unsigned int Length_1_1 = 62; static float Matrix_1_1[][2] = { {10.0f,2948431.83405761f}, {11.8540488374834f,2624495.86413504f}, {14.0518473841441f,2325687.15670159f}, {16.6571285148507f,2053300.6550955f}, {19.7454414907277f,1812349.36365008f}, {23.3910154232062f,1587106.25002598f}, {27.7096666987974f,1389856.88929117f}, {32.8256646693791f,1208423.2356284f}, {38.8862223677807f,1040561.93101611f}, {47.6816836662941f,865232.853488997f}, {58.466542101973f,709337.189140976f}, {67.8553557749417f,603251.925919516f}, {78.7518663120756f,512258.622337134f}, {88.7422479040242f,439532.13584902f}, {99.9999991346456f,376082.796787695f}, {118.25431067843f,290489.467142136f}, {128.595411698276f,243162.863276073f}, {139.840821150425f,190097.788558191f}, {152.069618983826f,125542.473874264f}, {173.449056114054f,12681.3152788257f}, {196.798921273205f,-110581.650853386f}, {220.148786432355f,-233844.616985599f}, {243.498651591506f,-357107.583117811f}, {266.848516750656f,-480370.549250023f}, {290.198381909807f,-603633.515382235f}, {313.548247068957f,-726896.481514447f}, {336.898112228108f,-850159.447646659f}, {360.247977387259f,-973422.413778872f}, {383.597842546409f,-1096685.37991108f}, {406.94770770556f,-1219948.3460433f}, {430.29757286471f,-1343211.31217551f}, {453.647438023861f,-1466474.27830772f}, {476.997303183011f,-1589737.24443993f}, {500.347168342162f,-1713000.21057214f}, {523.697033501312f,-1836263.17670436f}, {547.046898660463f,-1959526.14283657f}, {570.396763819614f,-2082789.10896878f}, {593.746628978764f,-2206052.07510099f}, {617.096494137915f,-2329315.04123321f}, {640.446359297065f,-2452578.00736542f}, {663.796224456216f,-2575840.97349763f}, {687.146089615366f,-2699103.93962984f}, {710.495954774517f,-2822366.90576205f}, {733.845819933668f,-2945629.87189427f}, {757.195685092818f,-3068892.83802648f}, {780.545550251969f,-3192155.80415869f}, {803.895415411119f,-3315418.7702909f}, {827.24528057027f,-3438681.73642311f}, {850.59514572942f,-3561944.70255533f}, {873.945010888571f,-3685207.66868754f}, {897.294876047722f,-3808470.63481975f}, {920.644741206872f,-3931733.60095196f}, {943.994606366023f,-4054996.56708418f}, {967.344471525173f,-4178259.53321639f}, {990.694336684324f,-4301522.4993486f}, {1014.04420184347f,-4424785.46548081f}, {1037.39406700262f,-4548048.43161303f}, {1060.74393216178f,-4671311.39774524f}, {1084.09379732093f,-4794574.36387745f}, {1107.44366248008f,-4917837.33000966f}, {1130.79352763923f,-5041100.29614187f}, {1154.14339279838f,-5164363.26227409f} };
		static unsigned int Length_1_2 = 57; static float Matrix_1_2[][2] = { {10.0f,3679260.57771473f}, {14.0518473841441f,3283638.15659487f}, {19.7454414907277f,2858767.49287279f}, {27.7096666987974f,2423407.41333743f}, {38.8862223677807f,2011192.92907763f}, {58.466542101973f,1543711.13117586f}, {78.7518663120756f,1214938.57591053f}, {99.9999991346456f,946276.60393283f}, {118.25431067843f,736423.186494455f}, {128.595411698276f,647087.324525356f}, {139.840821150425f,548392.820404942f}, {152.069618983826f,451731.039759632f}, {165.367800529509f,358386.256120919f}, {179.828881236796f,267058.723174628f}, {195.554554292491f,180482.905636948f}, {206.105812808632f,100000.0f}, {229.692904393422f,-79917.6527960905f}, {254.103227103802f,-266114.749214654f}, {278.513549814183f,-452311.845633217f}, {302.923872524563f,-638508.942051781f}, {327.334195234943f,-824706.038470344f}, {351.744517945323f,-1010903.13488891f}, {376.154840655704f,-1197100.23130747f}, {400.565163366084f,-1383297.32772603f}, {424.975486076464f,-1569494.4241446f}, {449.385808786844f,-1755691.52056316f}, {473.796131497224f,-1941888.61698172f}, {498.206454207605f,-2128085.71340029f}, {522.616776917985f,-2314282.80981885f}, {547.027099628365f,-2500479.90623741f}, {571.437422338745f,-2686677.00265598f}, {595.847745049126f,-2872874.09907454f}, {620.258067759506f,-3059071.1954931f}, {644.668390469886f,-3245268.29191167f}, {669.078713180266f,-3431465.38833023f}, {693.489035890647f,-3617662.48474879f}, {717.899358601027f,-3803859.58116736f}, {742.309681311407f,-3990056.67758592f}, {766.720004021787f,-4176253.77400448f}, {791.130326732168f,-4362450.87042305f}, {815.540649442548f,-4548647.96684161f}, {839.950972152928f,-4734845.06326017f}, {864.361294863308f,-4921042.15967874f}, {888.771617573688f,-5107239.2560973f}, {913.181940284069f,-5293436.35251586f}, {937.592262994449f,-5479633.44893442f}, {962.002585704829f,-5665830.54535299f}, {986.412908415209f,-5852027.64177155f}, {1010.82323112559f,-6038224.73819012f}, {1035.23355383597f,-6224421.83460868f}, {1059.64387654635f,-6410618.93102724f}, {1084.05419925673f,-6596816.0274458f}, {1108.46452196711f,-6783013.12386437f}, {1132.87484467749f,-6969210.22028293f}, {1157.28516738787f,-7155407.31670149f}, {1181.69549009825f,-7341604.41312006f}, {1206.10581280863f,-7527801.50953862f} };
		static unsigned int Length_1_3 = 60; static float Matrix_1_3[][2] = { {10.0f,4000000.0f}, {14.0518473841441f,3804495.52235223f}, {19.7454414907277f,3576346.17309578f}, {27.7096666987974f,3340209.58298707f}, {38.8862223677807f,3080504.03806261f}, {58.4665421019731f,2720866.42238453f}, {78.7518663120756f,2457166.45182617f}, {99.9999991346456f,2215465.84819352f}, {118.25431067843f,2012173.71934758f}, {128.595411698276f,1916391.87464238f}, {139.840821150425f,1797892.40131988f}, {152.069618983827f,1673631.16566808f}, {165.367800529509f,1544607.43826341f}, {179.828881236796f,1423018.47969851f}, {195.554554292491f,1292562.06992669f}, {232.460657470781f,1032971.4648959f}, {276.331878166963f,778930.799647571f}, {301.281005684365f,608451.988496094f}, {328.482710674943f,440137.026295966f}, {342.991136817049f,358336.215128032f}, {358.140371203487f,276486.55355934f}, {373.958717056259f,198175.736029746f}, {382.127991869404f,160642.793533891f}, {400.0f,100000.0f}, {407.142857142857f,75763.058756961f}, {435.510204081633f,-20492.222179679f}, {463.877551020408f,-116747.503116319f}, {492.244897959184f,-213002.78405296f}, {520.612244897959f,-309258.0649896f}, {548.979591836735f,-405513.34592624f}, {577.34693877551f,-501768.62686288f}, {605.714285714286f,-598023.90779952f}, {634.081632653061f,-694279.18873616f}, {662.448979591837f,-790534.4696728f}, {690.816326530612f,-886789.750609441f}, {719.183673469388f,-983045.031546081f}, {747.551020408163f,-1079300.31248272f}, {775.918367346939f,-1175555.59341936f}, {804.285714285714f,-1271810.874356f}, {832.65306122449f,-1368066.15529264f}, {861.020408163265f,-1464321.43622928f}, {889.387755102041f,-1560576.71716592f}, {917.755102040816f,-1656831.99810256f}, {946.122448979592f,-1753087.2790392f}, {974.489795918367f,-1849342.55997584f}, {1002.85714285714f,-1945597.84091248f}, {1031.22448979592f,-2041853.12184912f}, {1059.59183673469f,-2138108.40278576f}, {1087.95918367347f,-2234363.6837224f}, {1116.32653061225f,-2330618.96465904f}, {1144.69387755102f,-2426874.24559568f}, {1173.0612244898f,-2523129.52653232f}, {1201.42857142857f,-2619384.80746896f}, {1229.79591836735f,-2715640.0884056f}, {1258.16326530612f,-2811895.36934224f}, {1286.5306122449f,-2908150.65027888f}, {1314.89795918367f,-3004405.93121552f}, {1343.26530612245f,-3100661.21215216f}, {1371.63265306122f,-3196916.4930888f}, {1400.0f,-3293171.77402544f} };
		static unsigned int Length_1_4 = 64; static float Matrix_1_4[][2] = { {10.0f,3327972.7692178f}, {14.0518473841441f,3283638.15659487f}, {19.7454414907277f,3158365.94148842f}, {27.7096666987974f,3040272.0218163f}, {38.8862223677807f,2905506.56533469f}, {58.4665421019731f,2720866.42238453f}, {78.7518663120756f,2550714.29363647f}, {99.9999991346457f,2426110.28255497f}, {118.25431067843f,2342111.95124411f}, {128.595411698276f,2289810.95438913f}, {139.840821150425f,2238003.64265902f}, {152.069618983827f,2187537.60035932f}, {165.367800529509f,2142512.03591385f}, {179.828881236796f,2094361.20699365f}, {195.554554292491f,2034213.27833838f}, {232.460657470781f,1905987.16435848f}, {276.331878166963f,1753566.67931005f}, {301.281005684365f,1671813.67188051f}, {328.482710674943f,1589330.1195733f}, {342.991136817049f,1551631.23351175f}, {358.140371203487f,1507696.49539598f}, {373.95871705626f,1464190.49061565f}, {390.47572769423f,1418840.43167565f}, {485.453217820756f,1193285.52704827f}, {603.532588527675f,955182.982034007f}, {650.083650412549f,856449.102127347f}, {700.225241464864f,741717.20904093f}, {754.234302729145f,608742.522861671f}, {812.409135984945f,478722.326964823f}, {853.67011020874f,354571.233553138f}, {897.026664009973f,246548.135428711f}, {919.523834992393f,181229.345777272f}, {949.067957693876f,100000.0f}, {955.761044820074f,81597.8597846768f}, {1005.53794191587f,-55259.9791421512f}, {1055.31483901166f,-192117.818068979f}, {1105.09173610745f,-328975.656995807f}, {1154.86863320325f,-465833.495922635f}, {1204.64553029904f,-602691.334849463f}, {1254.42242739483f,-739549.173776291f}, {1304.19932449063f,-876407.012703119f}, {1353.97622158642f,-1013264.85162995f}, {1403.75311868221f,-1150122.69055677f}, {1453.53001577801f,-1286980.5294836f}, {1503.3069128738f,-1423838.36841043f}, {1553.08380996959f,-1560696.20733726f}, {1602.86070706539f,-1697554.04626409f}, {1652.63760416118f,-1834411.88519091f}, {1702.41450125697f,-1971269.72411774f}, {1752.19139835277f,-2108127.56304457f}, {1801.96829544856f,-2244985.4019714f}, {1851.74519254436f,-2381843.24089823f}, {1901.52208964015f,-2518701.07982505f}, {1951.29898673594f,-2655558.91875188f}, {2001.07588383174f,-2792416.75767871f}, {2050.85278092753f,-2929274.59660554f}, {2100.62967802332f,-3066132.43553237f}, {2150.40657511912f,-3202990.27445919f}, {2200.18347221491f,-3339848.11338602f}, {2249.9603693107f,-3476705.95231285f}, {2299.7372664065f,-3613563.79123968f}, {2349.51416350229f,-3750421.6301665f}, {2399.29106059808f,-3887279.46909333f}, {2449.06795769388f,-4024137.30802016f} };
		static unsigned int Length_1_5 = 56; static float Matrix_1_5[][2] = { {10.0f,2948431.83405761f}, {38.8862223677807f,2929404.71850323f}, {47.6816836662941f,2923672.06248654f}, {58.4665421019731f,2908214.81666961f}, {78.7518663120756f,2879670.70837814f}, {99.9999991346457f,2841194.80403625f}, {118.25431067843f,2811921.45162463f}, {139.840821150425f,2779576.12153377f}, {165.367800529509f,2721048.72224561f}, {195.554554292491f,2663753.68944704f}, {232.460657470781f,2586568.93079422f}, {276.331878166963f,2510128.60260794f}, {328.482710674943f,2414225.87461647f}, {358.140371203487f,2367657.42105187f}, {390.47572769423f,2321987.23508112f}, {485.453217820756f,2162223.52157702f}, {603.532588527675f,1959860.36803529f}, {650.08365041255f,1864629.37100066f}, {700.225241464864f,1774025.71525224f}, {754.234302729146f,1686494.97082906f}, {812.409135984947f,1603283.00890908f}, {853.67011020874f,1533640.1568522f}, {897.026664009975f,1464258.62085567f}, {942.585228558732f,1393473.61598961f}, {1000.0f,1326110.490867f}, {1078.60605201939f,1203280.70738263f}, {1174.59946582926f,1051991.46219483f}, {1279.13606876515f,884084.550880412f}, {1392.97618466124f,693208.5317824f}, {1516.94780439315f,471689.48314737f}, {1651.95260808627f,278349.845099651f}, {1723.89598053903f,179425.265372828f}, {1792.34784498045f,100000.0f}, {1818.64064927494f,69492.2413651262f}, {1885.62733998883f,-8232.97079401507f}, {1952.61403070271f,-85958.1829531564f}, {2019.6007214166f,-163683.395112298f}, {2086.58741213049f,-241408.607271439f}, {2153.57410284437f,-319133.819430581f}, {2220.56079355826f,-396859.031589722f}, {2287.54748427215f,-474584.243748863f}, {2354.53417498603f,-552309.455908005f}, {2421.52086569992f,-630034.668067146f}, {2488.50755641381f,-707759.880226287f}, {2555.4942471277f,-785485.092385429f}, {2622.48093784158f,-863210.30454457f}, {2689.46762855547f,-940935.516703712f}, {2756.45431926936f,-1018660.72886285f}, {2823.44100998324f,-1096385.94102199f}, {2890.42770069713f,-1174111.15318114f}, {2957.41439141102f,-1251836.36534028f}, {3024.4010821249f,-1329561.57749942f}, {3091.38777283879f,-1407286.78965856f}, {3158.37446355268f,-1485012.0018177f}, {3225.36115426656f,-1562737.21397684f}, {3292.34784498045f,-1640462.42613598f} };
		static unsigned int Length_1_6 = 29; static float Matrix_1_6[][2] = { {10.0f,3679266.88459059f}, {78.7518663120756f,3679266.88459059f}, {99.9999991346457f,3654526.37982186f}, {139.840821150425f,3635652.58991639f}, {195.554554292491f,3566418.45309606f}, {276.331878166963f,3430459.39020263f}, {390.47572769423f,3240162.75217165f}, {485.453217820756f,3075013.93092682f}, {603.532588527675f,2894785.16254159f}, {700.225241464864f,2755151.61693073f}, {812.409135984947f,2608106.91881005f}, {897.026664009975f,2498699.83437865f}, {1000.0f,2369257.79217514f}, {1078.60605201939f,2249948.87404659f}, {1174.59946582926f,2115015.33056303f}, {1279.13606876515f,1972631.07650651f}, {1392.97618466124f,1815162.74293112f}, {1516.94780439315f,1662939.68054479f}, {1651.95260808627f,1506361.323989f}, {1798.97252328648f,1348767.86011174f}, {1959.07686679272f,1172107.66768136f}, {2131.77493123062f,961896.894985065f}, {2319.69680947906f,731220.628025095f}, {2524.18452298855f,472131.631062572f}, {2633.09201905649f,343271.054537036f}, {2746.69839612609f,216860.231404202f}, {2805.32668273086f,159686.635244492f}, {2846.05628756034f,100000.0f}, {2850.0f,0.0f} };

		//�������� �� ��������� x2
		const float x2_arg[6] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
				
		//������� �������� x2
		float x2 = M;

		float x2_min = x2_arg[0];
		float x2_max = x2_arg[5];

		x_2.Min = x2_min;
		x_2.Value = x2;
		x_2.Max = x2_max;

		//����������� �� ��������� x2
		if (x2 < x2_arg[0])
			x2 = x2_arg[0];
		else if (x2 > x2_arg[5])
			x2 = x2_arg[5];

		//���������� �� ��� � �������
		float x1 = Re * hh;

		const float x1_min = 10.0f;
		const float x1_max = 3000.0f;

		x_1.Min = x1_min;
		x_1.Value = x1;
		x_1.Max = x1_max;

		//����������� �� ��������� ��� x
		if (x1 < x1_min)
			x1 = x1_min;
		else if (x1 > x1_max)
			x1 = x1_max;

		float y = 0.0f;

		//����������
		if (fabs(x2 - x2_arg[0]) < 1e-3)
		{
			y = Linterp(Matrix_1_1, Length_1_1, x1);
		}
		else if (x2_arg[0] <= x2 && x2 < x2_arg[1])
		{

			float y1 = Linterp(Matrix_1_1, Length_1_1, x1);
			float y2 = Linterp(Matrix_1_2, Length_1_2, x1);

			y = LinterpOnce(x2_arg[0], y1, x2_arg[1], y2, x2);
		}
		else if (x2_arg[1] <= x2 && x2 < x2_arg[2])
		{
			float y1 = Linterp(Matrix_1_2, Length_1_2, x1);
			float y2 = Linterp(Matrix_1_3, Length_1_3, x1);

			y = LinterpOnce(x2_arg[1], y1, x2_arg[2], y2, x2);
		}
		else if (x2_arg[2] <= x2 && x2 < x2_arg[3])
		{
			float y1 = Linterp(Matrix_1_3, Length_1_3, x1);
			float y2 = Linterp(Matrix_1_4, Length_1_4, x1);

			y = LinterpOnce(x2_arg[2], y1, x2_arg[3], y2, x2);
		}
		else if (x2_arg[3] <= x2 && x2 < x2_arg[4])
		{
			float y1 = Linterp(Matrix_1_4, Length_1_4, x1);
			float y2 = Linterp(Matrix_1_5, Length_1_5, x1);

			y = LinterpOnce(x2_arg[3], y1, x2_arg[4], y2, x2);
		}
		else if (x2_arg[4] <= x2 && x2 < x2_arg[5])
		{
			float y1 = Linterp(Matrix_1_5, Length_1_5, x1);
			float y2 = Linterp(Matrix_1_6, Length_1_6, x1);

			y = LinterpOnce(x2_arg[4], y1, x2_arg[5], y2, x2);
		}
		else if (fabs(x2 - x2_arg[5]) < 1e-3)
		{
			y = Linterp(Matrix_1_6, Length_1_6, x1);
		}
		else
			return NAN;
		
		if (y < 1e5f)
			return 0.0f;
		else return y;
	}

	ErrorCode* get_Re_t0_1(float& Result, float M, float Re, float hh, InputComplex& x_2, InputComplex& x_1)
	{
		static ErrorCode ErrC;
		// ��������: ��������� ��������� �� ������ ���� ������ 0		
		if (M < 0.0f)
		{
			ErrC.ArgNumber = 1;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (Re < 0.0f)
		{
			ErrC.ArgNumber = 2;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}
		if (hh < 0.0f)
		{
			ErrC.ArgNumber = 3;
			ErrC.Code = ErrC_NumberMustNotBeNeg;
			return &ErrC;
		}

		// ��������: ��������� ��������� �� ������ ���� ������ 1		
		if (hh > 1.0f)
		{
			ErrC.ArgNumber = 3;
			ErrC.Code = ErrC_ArgMustNotBeGT1;
			return &ErrC;
		}

		// �������� ������� ������������ �������
		Result = Re_t0_1(M, Re, hh, x_2, x_1);
		ErrC.ArgNumber = ErrC_OK;
		ErrC.Code = ErrC_OK;

		return &ErrC;
	}
}