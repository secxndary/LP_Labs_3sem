#include "stdafx.h"
namespace Error
{
	//ñåğèè îøèáîê: 0 -  99 - ñèñòåìíûå îøèáêè
	//			  100 - 109 - îøèáêè ïàğàìåòğîâ
	//			  110 - 119 - îøèáêè îòêğûòèÿ è ÷òåíèÿ ôàéëîâ
	ERROR errors[ERROR_MAX_ENTRY] = //òàáëèöà îøèáîê
	{
		ERROR_ENTRY(0, "Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1, "Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Ïàğàìåòğ -in äîëæåí áûòü çàäàí"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"),
		ERROR_ENTRY(105, "Ïğåâûøåí ìàêñèìàëüíûé ğàçìåğ òàáëèöû ëåêñåì"), ERROR_ENTRY(106, "Ïğåâûøåí ğàçìåğ òàáëèöû ëåêñåì"), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY(108, "Ïğåâûøåí ìàêñèìàëüíûé ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"), ERROR_ENTRY_NODEF(109, "Ïğåâûøåí ìàêñèìàëüíûé ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(110, "Îøèáêà ïğè îòêğûòèè ôàéëà ñ èñõîäíûì êîäîì (-in)"),
		ERROR_ENTRY(111, "Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå (-in)"),
		ERROR_ENTRY(112, "Îøèáêà ïğè ñîçäàíèè ôàéëà ïğîòîêîëà (-log)"),
		ERROR_ENTRY(113, "Îøèáêà ëåêñè÷åñêîãî àíàëèçà"), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600), ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)

	};

	ERROR geterror(int id)
	{
		if (id > 0 || id < ERROR_MAX_ENTRY)
			for (int i = 0; i < ERROR_MAX_ENTRY; i++)
			{
				if (errors[i].id == id)
					return errors[i];
			}
		else return errors[0];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 || id < ERROR_MAX_ENTRY)
		{
			for (int i = 0; i < ERROR_MAX_ENTRY; i++)
			{
				ERROR err;
				if (errors[i].id == id)
				{
					err.id = errors[i].id;
					strcpy_s(err.message, errors[i].message);
					err.inext.line = line;
					err.inext.col = col;
					return err;
				}
			}
		}
		else return errors[0];
	}
}