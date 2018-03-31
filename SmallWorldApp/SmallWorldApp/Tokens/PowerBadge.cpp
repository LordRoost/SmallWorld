#include "../Headers/Tokens.h"

//Instance of PowerInfo struct, contains information related to the various powerBadges
PowerInfo powerInfo[TOTAL_POWERS] = { { POWER_ALCHEMIST, "Alchemist", 4,5 },{ POWER_BERSERK, "Berserk", 4,10 },{ POWER_BIVOUACKING, "Bivouacking", 5,7 },
{ POWER_COMMANDO, "Commando", 4,11 },{ POWER_DIPLOMAT, "Diplomat", 5,8 },{ POWER_DRAGON_MASTER, "Dragon Master", 5,12 },{ POWER_FLYING, "Flying", 5,9 },
{ POWER_FOREST, "Forest", 4,4 },{ POWER_FORTIFIED, "Fortified", 3,4 },{ POWER_HEROIC, "Heroic", 5,9 },{ POWER_HILL, "Hill", 4,4 },
{ POWER_MERCHANT, "Merchant", 2,1 },{ POWER_MOUNTED, "Mounted", 5,9 },{ POWER_PILLAGING, "Pillaging", 5,8 },{ POWER_SEAFARING, "Seafaring", 5,8 },
{ POWER_SPIRIT, "Spirit", 5,9 },{ POWER_STOUT, "Stout", 4,5 },{ POWER_SWAMP, "Swamp", 4,5 },{ POWER_UNDERWORLD, "Underworld", 5,8 },{ POWER_WEALTHY, "Wealthy", 4,4 } };

PowerBadge::PowerBadge(powers newPower) {
	power = newPower ;
	powerName = powerInfo[power].powerName;
	amountTokensReceived = powerInfo[power].amountTokensReceived;
    aggressivePoint=powerInfo[power].aggressivePoint;
}

//getters and setters
powers PowerBadge::getPower() {
	return power;
}

int PowerBadge::getAggressivePoint(){
    return aggressivePoint;
}

void PowerBadge::setPower(powers newPower) {
	power = newPower;
}

std::string PowerBadge::getPowerName() {
	return powerName;
}

void PowerBadge::setPowerName(std::string newName) {
	powerName = newName;
}

int PowerBadge::getAmountTokensReceived() {
	return amountTokensReceived;
}

void PowerBadge::setAmountTokensReceived(int nb) {
	amountTokensReceived = nb;
}
