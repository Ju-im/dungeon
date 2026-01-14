#include "Weapon.h"
Weapon::Weapon() {
  srand(static_cast<unsigned>(time(NULL)));


}
Weapon::~Weapon() {}

void Weapon::setAttackHeight(int height) {
  attackHeight = height;


}

void Weapon::setAttackWidth(int width)
{
  attackWidth = width;
}

void Weapon::attack() {
	
	



}


bool init() {



	return true;
}