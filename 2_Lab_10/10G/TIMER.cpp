#include "TIMER.h"
#include <iostream>
void TIMER::Output(){
	std::cout << "Кодичество секунд: "<< (minutes*60)+secounds<<"\n";
}