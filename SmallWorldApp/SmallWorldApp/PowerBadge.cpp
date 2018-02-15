#include "Tokens.h"

PowerInfo powerInfo[TOTAL_POWERS] = { { POWER_ALCHEMIST, "Alchemist", 4 },{ POWER_BERSERK, "Berserk", 4 },{ POWER_BIVOUACKING, "Bivouacking", 5 },
{ POWER_COMMANDO, "Commando", 4 },{ POWER_DIPLOMAT, "Diplomat", 5 },{ POWER_DRAGON_MASTER, "Dragon Master", 5 },{ POWER_FLYING, "Flying", 5 },
{ POWER_FOREST, "Forest", 4 },{ POWER_FORTIFIED, "Fortified", 3 },{ POWER_HEROIC, "Heroic", 5 },{ POWER_HILL, "Hill", 4 },
{ POWER_MERCHANT, "Merchant", 2 },{ POWER_MOUNTED, "Mounted", 5 },{ POWER_PILLAGING, "Pillaging", 5 },{ POWER_SEAFARING, "Seafaring", 5 },
{ POWER_SPIRIT, "Spirit", 5 },{ POWER_STOUT, "Stout", 4 },{ POWER_SWAMP, "Swamp", 4 },{ POWER_UNDERWORLD, "Underworld", 5 },{ POWER_WEALTHY, "Wealthy", 4 } };

PowerBadge::PowerBadge(powers newPower) {
	power = newPower ;
	amountTokensReceived = powerInfo[power].amountTokensReceived;
}

powers PowerBadge::getPower() {
	return power;
}

void PowerBadge::setPower(powers newPower) {
	power = newPower;
}