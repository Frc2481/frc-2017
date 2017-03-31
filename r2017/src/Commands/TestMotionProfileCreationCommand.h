#ifndef TestMotionProfileCreationCommand_H
#define TestMotionProfileCreationCommand_H

#include "../CommandBase.h"
#include "Components/TalonMotionProfileFollower.h"

class TestMotionProfileCreationCommand : public CommandBase {
private:
	TalonMotionProfileFollower m_follower;
	bool m_first;
public:
	TestMotionProfileCreationCommand() : CommandBase("TestMotionProfileCreationCommand"),
	m_follower(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR), "FLSTEER", 1){
		Requires(m_driveTrain.get());
		//m_follower = TalonMotionProfileFollower(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR));
	}
	void Initialize(){
		m_first = true;
		m_driveTrain->DisableFollower();
		int profileSize = 357;
		double profile[][3] = {
				{0,	0	,10},
				{7.34265734265734E-05,	0.881118881	,10},
				{0.00033041958041958,	2.202797203	,10},
				{0.000844405594405595,	3.965034965	,10},
				{0.00168881118881119,	6.167832168	,10},
				{0.00293706293706294,	8.811188811	,10},
				{0.00466258741258741,	11.8951049	,10},
				{0.00693881118881119,	15.41958042	,10},
				{0.00983916083916084,	19.38461538	,10},
				{0.0134370629370629,	23.79020979	,10},
				{0.0178059440559441,	28.63636364	,10},
				{0.0229825174825175,	33.48251748	,10},
				{0.0289667832167832,	38.32867133	,10},
				{0.0357587412587413,	43.17482517	,10},
				{0.0433583916083916,	48.02097902	,10},
				{0.0517657342657343,	52.86713287	,10},
				{0.0609807692307692,	57.71328671	,10},
				{0.0710034965034965,	62.55944056	,10},
				{0.0818339160839161,	67.40559441	,10},
				{0.093472027972028,	72.25174825	,10},
				{0.105917832167832,	77.0979021	,10},
				{0.119171328671329,	81.94405594	,10},
				{0.133232517482517,	86.79020979	,10},
				{0.148101398601399,	91.63636364	,10},
				{0.163777972027972,	96.48251748	,10},
				{0.180262237762238,	101.3286713	,10},
				{0.197554195804196,	106.1748252	,10},
				{0.21558041958042,	110.1398601	,10},
				{0.234230769230769,	113.6643357	,10},
				{0.253431818181818,	116.7482517	,10},
				{0.27311013986014,	119.3916084	,10},
				{0.293192307692308,	121.5944056	,10},
				{0.313604895104895,	123.3566434	,10},
				{0.334274475524475,	124.6783217	,10},
				{0.355127622377622,	125.5594406	,10},
				{0.376090909090909,	126	,10},
				{0.397090909090909,	126	,10},
				{0.418090909090909,	126	,10},
				{0.439090909090909,	126	,10},
				{0.460090909090909,	126	,10},
				{0.481090909090909,	126	,10},
				{0.502090909090909,	126	,10},
				{0.523090909090909,	126	,10},
				{0.544090909090909,	126	,10},
				{0.565090909090909,	126	,10},
				{0.586090909090909,	126	,10},
				{0.607090909090909,	126	,10},
				{0.628090909090909,	126	,10},
				{0.649090909090909,	126	,10},
				{0.670017482517483,	125.1188811	,10},
				{0.69076048951049,	123.7972028	,10},
				{0.711246503496504,	122.034965	,10},
				{0.731402097902098,	119.8321678	,10},
				{0.751153846153847,	117.1888112	,10},
				{0.770428321678322,	114.1048951	,10},
				{0.789152097902098,	110.5804196	,10},
				{0.807251748251749,	106.6153846	,10},
				{0.824653846153847,	102.2097902	,10},
				{0.841284965034965,	97.36363636	,10},
				{0.857108391608392,	92.51748252	,10},
				{0.872124125874126,	87.67132867	,10},
				{0.886332167832168,	82.82517483	,10},
				{0.899732517482518,	77.97902098	,10},
				{0.912325174825175,	73.13286713	,10},
				{0.92411013986014,	68.28671329	,10},
				{0.935087412587413,	63.44055944	,10},
				{0.945256993006994,	58.59440559	,10},
				{0.954618881118882,	53.74825175	,10},
				{0.963173076923077,	48.9020979	,10},
				{0.970919580419581,	44.05594406	,10},
				{0.977858391608392,	39.20979021	,10},
				{0.983989510489511,	34.36363636	,10},
				{0.989312937062938,	29.51748252	,10},
				{0.993828671328672,	24.67132867	,10},
				{0.997536713286714,	19.82517483	,10},
				{1.00051048951049,	15.86013986	,10},
				{1.00286013986014,	12.33566434	,10},
				{1.00465909090909,	9.251748252	,10},
				{1.00598076923077,	6.608391608	,10},
				{1.0068986013986,	4.405594406	,10},
				{1.00748601398601,	2.643356643	,10},
				{0,	0	,10},
				{7.34265734265734E-05,	0.881118881	,10},
				{0.00033041958041958,	2.202797203	,10},
				{0.000844405594405595,	3.965034965	,10},
				{0.00168881118881119,	6.167832168	,10},
				{0.00293706293706294,	8.811188811	,10},
				{0.00466258741258741,	11.8951049	,10},
				{0.00693881118881119,	15.41958042	,10},
				{0.00983916083916084,	19.38461538	,10},
				{0.0134370629370629,	23.79020979	,10},
				{0.0178059440559441,	28.63636364	,10},
				{0.0229825174825175,	33.48251748	,10},
				{0.0289667832167832,	38.32867133	,10},
				{0.0357587412587413,	43.17482517	,10},
				{0.0433583916083916,	48.02097902	,10},
				{0.0517657342657343,	52.86713287	,10},
				{0.0609807692307692,	57.71328671	,10},
				{0.0710034965034965,	62.55944056	,10},
				{0.0818339160839161,	67.40559441	,10},
				{0.093472027972028,	72.25174825	,10},
				{0.105917832167832,	77.0979021	,10},
				{0.119171328671329,	81.94405594	,10},
				{0.133232517482517,	86.79020979	,10},
				{0.148101398601399,	91.63636364	,10},
				{0.163777972027972,	96.48251748	,10},
				{0.180262237762238,	101.3286713	,10},
				{0.197554195804196,	106.1748252	,10},
				{0.21558041958042,	110.1398601	,10},
				{0.234230769230769,	113.6643357	,10},
				{0.253431818181818,	116.7482517	,10},
				{0.27311013986014,	119.3916084	,10},
				{0.293192307692308,	121.5944056	,10},
				{0.313604895104895,	123.3566434	,10},
				{0.334274475524475,	124.6783217	,10},
				{0.355127622377622,	125.5594406	,10},
				{0.376090909090909,	126	,10},
				{0.397090909090909,	126	,10},
				{0.418090909090909,	126	,10},
				{0.439090909090909,	126	,10},
				{0.460090909090909,	126	,10},
				{0.481090909090909,	126	,10},
				{0.502090909090909,	126	,10},
				{0.523090909090909,	126	,10},
				{0.544090909090909,	126	,10},
				{0.565090909090909,	126	,10},
				{0.586090909090909,	126	,10},
				{0.607090909090909,	126	,10},
				{0.628090909090909,	126	,10},
				{0.649090909090909,	126	,10},
				{0.670090909090909,	126	,10},
				{0.691090909090909,	126	,10},
				{0.712090909090909,	126	,10},
				{0.733090909090909,	126	,10},
				{0.754090909090909,	126	,10},
				{0.775090909090909,	126	,10},
				{0.796090909090909,	126	,10},
				{0.817090909090909,	126	,10},
				{0.838090909090909,	126	,10},
				{0.859090909090909,	126	,10},
				{0.880090909090909,	126	,10},
				{0.901090909090909,	126	,10},
				{0.92209090909091,	126	,10},
				{0.94309090909091,	126	,10},
				{0.96409090909091,	126	,10},
				{0.98509090909091,	126	,10},
				{1.00609090909091,	126	,10},
				{1.02709090909091,	126	,10},
				{1.04809090909091,	126	,10},
				{1.06909090909091,	126	,10},
				{1.09009090909091,	126	,10},
				{1.11109090909091,	126	,10},
				{1.13209090909091,	126	,10},
				{1.15309090909091,	126	,10},
				{1.17409090909091,	126	,10},
				{1.19509090909091,	126	,10},
				{1.21609090909091,	126	,10},
				{1.23709090909091,	126	,10},
				{1.25809090909091,	126	,10},
				{1.27909090909091,	126	,10},
				{1.30009090909091,	126	,10},
				{1.32109090909091,	126	,10},
				{1.34209090909091,	126	,10},
				{1.36309090909091,	126	,10},
				{1.38409090909091,	126	,10},
				{1.40509090909091,	126	,10},
				{1.42609090909091,	126	,10},
				{1.44709090909091,	126	,10},
				{1.46809090909091,	126	,10},
				{1.48909090909091,	126	,10},
				{1.51009090909091,	126	,10},
				{1.53109090909091,	126	,10},
				{1.55209090909091,	126	,10},
				{1.57309090909091,	126	,10},
				{1.59409090909091,	126	,10},
				{1.61509090909091,	126	,10},
				{1.63609090909091,	126	,10},
				{1.65709090909091,	126	,10},
				{1.67809090909091,	126	,10},
				{1.69909090909091,	126	,10},
				{1.72009090909091,	126	,10},
				{1.74109090909091,	126	,10},
				{1.76209090909091,	126	,10},
				{1.78309090909091,	126	,10},
				{1.80409090909091,	126	,10},
				{1.82509090909091,	126	,10},
				{1.84609090909091,	126	,10},
				{1.86709090909091,	126	,10},
				{1.88809090909091,	126	,10},
				{1.90909090909091,	126	,10},
				{1.93009090909091,	126	,10},
				{1.95109090909091,	126	,10},
				{1.97209090909091,	126	,10},
				{1.99309090909091,	126	,10},
				{2.01409090909091,	126	,10},
				{2.03509090909091,	126	,10},
				{2.0560909090909,	126	,10},
				{2.0770909090909,	126	,10},
				{2.0980909090909,	126	,10},
				{2.1190909090909,	126	,10},
				{2.1400909090909,	126	,10},
				{2.1610909090909,	126	,10},
				{2.1820909090909,	126	,10},
				{2.2030909090909,	126	,10},
				{2.2240909090909,	126	,10},
				{2.2450909090909,	126	,10},
				{2.2660909090909,	126	,10},
				{2.2870909090909,	126	,10},
				{2.3080909090909,	126	,10},
				{2.3290909090909,	126	,10},
				{2.3500909090909,	126	,10},
				{2.3710909090909,	126	,10},
				{2.3920909090909,	126	,10},
				{2.4130909090909,	126	,10},
				{2.4340909090909,	126	,10},
				{2.4550909090909,	126	,10},
				{2.4760909090909,	126	,10},
				{2.4970909090909,	126	,10},
				{2.5180909090909,	126	,10},
				{2.5390909090909,	126	,10},
				{2.5600909090909,	126	,10},
				{2.5810909090909,	126	,10},
				{2.6020909090909,	126	,10},
				{2.6230909090909,	126	,10},
				{2.6440909090909,	126	,10},
				{2.6650909090909,	126	,10},
				{2.6860909090909,	126	,10},
				{2.7070909090909,	126	,10},
				{2.7280909090909,	126	,10},
				{2.7490909090909,	126	,10},
				{2.7700909090909,	126	,10},
				{2.7910909090909,	126	,10},
				{2.8120909090909,	126	,10},
				{2.8330909090909,	126	,10},
				{2.8540909090909,	126	,10},
				{2.8750909090909,	126	,10},
				{2.8960909090909,	126	,10},
				{2.9170909090909,	126	,10},
				{2.9380909090909,	126	,10},
				{2.9590909090909,	126	,10},
				{2.9800909090909,	126	,10},
				{3.0010909090909,	126	,10},
				{3.0220909090909,	126	,10},
				{3.0430909090909,	126	,10},
				{3.0640909090909,	126	,10},
				{3.0850909090909,	126	,10},
				{3.1060909090909,	126	,10},
				{3.1270909090909,	126	,10},
				{3.1480909090909,	126	,10},
				{3.1690909090909,	126	,10},
				{3.1900909090909,	126	,10},
				{3.2110909090909,	126	,10},
				{3.2320909090909,	126	,10},
				{3.2530909090909,	126	,10},
				{3.2740909090909,	126	,10},
				{3.2950909090909,	126	,10},
				{3.3160909090909,	126	,10},
				{3.3370909090909,	126	,10},
				{3.3580909090909,	126	,10},
				{3.3790909090909,	126	,10},
				{3.4000909090909,	126	,10},
				{3.4210909090909,	126	,10},
				{3.4420909090909,	126	,10},
				{3.4630909090909,	126	,10},
				{3.4840909090909,	126	,10},
				{3.5050909090909,	126	,10},
				{3.5260909090909,	126	,10},
				{3.5470909090909,	126	,10},
				{3.5680909090909,	126	,10},
				{3.5890909090909,	126	,10},
				{3.6100909090909,	126	,10},
				{3.6310909090909,	126	,10},
				{3.6520909090909,	126	,10},
				{3.6730909090909,	126	,10},
				{3.6940909090909,	126	,10},
				{3.7150909090909,	126	,10},
				{3.7360909090909,	126	,10},
				{3.7570909090909,	126	,10},
				{3.7780909090909,	126	,10},
				{3.7990909090909,	126	,10},
				{3.8200909090909,	126	,10},
				{3.8410909090909,	126	,10},
				{3.8620909090909,	126	,10},
				{3.8830909090909,	126	,10},
				{3.9040909090909,	126	,10},
				{3.9250909090909,	126	,10},
				{3.9460909090909,	126	,10},
				{3.9670909090909,	126	,10},
				{3.9880909090909,	126	,10},
				{4.0090909090909,	126	,10},
				{4.0300909090909,	126	,10},
				{4.0510909090909,	126	,10},
				{4.0720909090909,	126	,10},
				{4.0930909090909,	126	,10},
				{4.1140909090909,	126	,10},
				{4.1350909090909,	126	,10},
				{4.1560909090909,	126	,10},
				{4.1770909090909,	126	,10},
				{4.1980909090909,	126	,10},
				{4.2190909090909,	126	,10},
				{4.2400909090909,	126	,10},
				{4.2610909090909,	126	,10},
				{4.2820909090909,	126	,10},
				{4.3030909090909,	126	,10},
				{4.32409090909089,	126	,10},
				{4.34509090909089,	126	,10},
				{4.36609090909089,	126	,10},
				{4.38709090909089,	126	,10},
				{4.40809090909089,	126	,10},
				{4.42909090909089,	126	,10},
				{4.45009090909089,	126	,10},
				{4.47109090909089,	126	,10},
				{4.49209090909089,	126	,10},
				{4.51309090909089,	126	,10},
				{4.53409090909089,	126	,10},
				{4.55509090909089,	126	,10},
				{4.57609090909089,	126	,10},
				{4.59709090909089,	126	,10},
				{4.61809090909089,	126	,10},
				{4.63909090909089,	126	,10},
				{4.66009090909089,	126	,10},
				{4.68101748251747,	125.1188811	,10},
				{4.70176048951047,	123.7972028	,10},
				{4.72224650349649,	122.034965	,10},
				{4.74240209790208,	119.8321678	,10},
				{4.76215384615383,	117.1888112	,10},
				{4.7814283216783,	114.1048951	,10},
				{4.80015209790208,	110.5804196	,10},
				{4.81825174825173,	106.6153846	,10},
				{4.83565384615383,	102.2097902	,10},
				{4.85228496503495,	97.36363636	,10},
				{4.86810839160837,	92.51748252	,10},
				{4.88312412587411,	87.67132867	,10},
				{4.89733216783215,	82.82517483	,10},
				{4.9107325174825,	77.97902098	,10},
				{4.92332517482516,	73.13286713	,10},
				{4.93511013986012,	68.28671329	,10},
				{4.94608741258739,	63.44055944	,10},
				{4.95625699300698,	58.59440559	,10},
				{4.96561888111886,	53.74825175	,10},
				{4.97417307692306,	48.9020979	,10},
				{4.98191958041956,	44.05594406	,10},
				{4.98885839160837,	39.20979021	,10},
				{4.99498951048949,	34.36363636	,10},
				{5.00031293706292,	29.51748252	,10},
				{5.00482867132865,	24.67132867	,10},
				{5.0085367132867,	19.82517483	,10},
				{5.01151048951047,	15.86013986	,10},
				{5.01386013986012,	12.33566434	,10},
				{5.01565909090907,	9.251748252	,10},
				{5.01698076923075,	6.608391608	,10},
				{5.01789860139858,	4.405594406	,10},
				{5.018486013986,	2.643356643	,10},
				{5.01881643356641,	1.321678322	,10},
				{5.01896328671327,	0.440559441	,10},
				{5.01899999999998,	5.40E-15	,10},
				{5.01899999999998,	0	,10}};

		m_follower.LoadPath(profile, profileSize);
		m_driveTrain->EnableFollower();
	}
	void Execute(){
		m_follower.Periodic();
		if(m_follower.IsReady() && m_first){
			m_follower.RunPath();
			m_first = false;
		}
	}
	bool IsFinished(){
		return m_follower.IsFinished();
	}
	void End(){
		m_driveTrain->DisableFollower();
	}
};

#endif  // TestMotionProfileCreationCommand_H
