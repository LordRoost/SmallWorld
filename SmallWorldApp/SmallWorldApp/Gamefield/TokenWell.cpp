#include "../Headers/Game.h"

TokenWell::TokenWell() {

}

std::vector<MountainPiece*> TokenWell::getMountainPieces() {
	return mountainPieces;
}

void TokenWell::addMountainPieces(MountainPiece *piece) {
	mountainPieces.push_back(piece);
}

MountainPiece* TokenWell::dealMountain() {
	MountainPiece* tempPiece = mountainPieces.back();
	mountainPieces.pop_back();
	return tempPiece;
}

