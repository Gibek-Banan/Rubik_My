#include "Cube.hpp"

Cube::Cube(){
	path = "";
	for (char c = 0; c < 6; c++)
		for (int i = 0; i < 9; i++)
			color[c * 9 + i] = colorTabEncode[c];
}

Cube& Cube::operator=(const Cube& a){
	for (int i = 0; i < 8; i++){
		cPos[i] = a.cPos[i];
		cOri[i] = a.cOri[i];
	}
	for (int i = 0; i < 12; i++){
		ePos[i] = a.ePos[i];
		eOri[i] = a.eOri[i];
	}
	path = a.path;
	return *this;
}

bool Cube::operator==(const Cube& a){
	for (int i = 0; i < 8; i++)
		if (cPos[i] != a.cPos[i] || cOri[i] != a.cOri[i])
			return 0;
	for (int i = 0; i < 12; i++)
		if (ePos[i] != a.ePos[i] || eOri[i] != a.eOri[i])
			return 0;
	return 1;
}


Cube::~Cube(){
}

void	Cube::rotCube(char c, int amount, CubeDisplay& cb){
	switch (c){
		case 'F':
			rotFront(amount);
			cb.F(amount);
			break;
		case 'R':
			rotRight(amount);
			cb.R(amount);
			break;
		case 'U':
			rotUp(amount);
			cb.U(amount);
			break;
		case 'B':
			cb.B(amount);
			rotBack(amount);
			break;
		case 'L':
			cb.L(amount);
			rotLeft(amount);
			break;
		case 'D':
			cb.D(amount);
			rotDown(amount);
	}
}

void	Cube::rotUp(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[urf];
		cPos[urf] = cPos[ubr];
		cPos[ubr] = cPos[ulb];
		cPos[ulb] = cPos[ufl];
		cPos[ufl] = tmp;
		
		char tOri = cOri[urf];
		cOri[urf] = cOri[ubr];
		cOri[ubr] = cOri[ulb];
		cOri[ulb] = cOri[ufl];
		cOri[ufl] = tOri;

		tOri = eOri[ub];
		eOri[ub] = eOri[ul];
		eOri[ul] = eOri[uf];
		eOri[uf] = eOri[ur];
		eOri[ur] = tOri;

		edge tmp2 = ePos[ub];
		ePos[ub] = ePos[ul];
		ePos[ul] = ePos[uf];
		ePos[uf] = ePos[ur];
		ePos[ur] = tmp2;
	}
}
		
void	Cube::rotDown(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[dfr];
		cPos[dfr] = cPos[dlf];
		cPos[dlf] = cPos[dbl];
		cPos[dbl] = cPos[drb];
		cPos[drb] = tmp;

		char tOri = cOri[dfr];
		cOri[dfr] = cOri[dlf];
		cOri[dlf] = cOri[dbl];
		cOri[dbl] = cOri[drb];
		cOri[drb] = tOri;

		tOri = eOri[df];
		eOri[df] = eOri[dl];
		eOri[dl] = eOri[db];
		eOri[db] = eOri[dr];
		eOri[dr] = tOri;

		edge tmp2 = ePos[df];
		ePos[df] = ePos[dl];
		ePos[dl] = ePos[db];
		ePos[db] = ePos[dr];
		ePos[dr] = tmp2;
	}
}

void	Cube::rotLeft(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[dlf];
		cPos[dlf] = cPos[ufl];
		cPos[ufl] = cPos[ulb];
		cPos[ulb] = cPos[dbl];
		cPos[dbl] = tmp;

		char tOri = cOri[dlf];
		cOri[dlf] = (1 + cOri[ufl]) % 3;
		cOri[ufl] = (2 + cOri[ulb]) % 3;
		cOri[ulb] = (1 + cOri[dbl]) % 3;
		cOri[dbl] = (2 + tOri) % 3;

		tOri = eOri[bl];
		eOri[bl] = eOri[dl];
		eOri[dl] = eOri[fl];
		eOri[fl] = eOri[ul];
		eOri[ul] = tOri;

		edge tmp2 = ePos[bl];
		ePos[bl] = ePos[dl];
		ePos[dl] = ePos[fl];
		ePos[fl] = ePos[ul];
		ePos[ul] = tmp2;
	}
}

void	Cube::rotRight(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[urf];
		cPos[urf] = cPos[dfr];
		cPos[dfr] = cPos[drb];
		cPos[drb] = cPos[ubr];
		cPos[ubr] = tmp;

		char tOri = cOri[urf];
		cOri[urf] = (1 + cOri[dfr]) % 3;
		cOri[dfr] = (2 + cOri[drb]) % 3;
		cOri[drb] = (1 + cOri[ubr]) % 3;
		cOri[ubr] = (2 + tOri) % 3;

		tOri = eOri[fr];
		eOri[fr] = eOri[dr];
		eOri[dr] = eOri[br];
		eOri[br] = eOri[ur];
		eOri[ur] = tOri;

		edge tmp2 = ePos[fr];
		ePos[fr] = ePos[dr];
		ePos[dr] = ePos[br];
		ePos[br] = ePos[ur];
		ePos[ur] = tmp2;
	}
}

void	Cube::rotFront(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[urf];
		cPos[urf] = cPos[ufl];
		cPos[ufl] = cPos[dlf];
		cPos[dlf] = cPos[dfr];
		cPos[dfr] = tmp;

		char tOri = cOri[urf];
		cOri[urf] = (2 + cOri[ufl]) % 3;
		cOri[ufl] = (1 + cOri[dlf]) % 3;
		cOri[dlf] = (2 + cOri[dfr]) % 3;
		cOri[dfr] = (1 + tOri) % 3;

		tOri = eOri[uf];
		eOri[uf] = 1 - eOri[fl];
		eOri[fl] = 1 - eOri[df];
		eOri[df] = 1 - eOri[fr];
		eOri[fr] = 1 - tOri;

		edge tmp2 = ePos[uf];
		ePos[uf] = ePos[fl];
		ePos[fl] = ePos[df];
		ePos[df] = ePos[fr];
		ePos[fr] = tmp2;
	}
}

void	Cube::rotBack(int amount){
	if (amount == -1)
		amount = 3;

	for (int i = 0; i < amount; i++){
		corner tmp = cPos[ulb];
		cPos[ulb] = cPos[ubr];
		cPos[ubr] = cPos[drb];
		cPos[drb] = cPos[dbl];
		cPos[dbl] = tmp;

		char tOri = cOri[ulb];
		cOri[ulb] = (2 + cOri[ubr]) % 3;
		cOri[ubr] = (1 + cOri[drb]) % 3;
		cOri[drb] = (2 + cOri[dbl]) % 3;
		cOri[dbl] = (1 + tOri) % 3;

		tOri = eOri[br];
		eOri[br] = 1 - eOri[db];
		eOri[db] = 1 - eOri[bl];
		eOri[bl] = 1 - eOri[ub];
		eOri[ub] = 1 - tOri;

		edge tmp2 = ePos[br];
		ePos[br] = ePos[db];
		ePos[db] = ePos[bl];
		ePos[bl] = ePos[ub];
		ePos[ub] = tmp2;
	}
}

char	Cube::cornerFace(corner c, int offset)
{
	return (cornerNames[cPos[c]][(offset + cOri[c]) % 3]);
}

char	Cube::edgeFace(edge e, int offset)
{
	return (edgeNames[ePos[e]][(offset + eOri[e]) % 2]);
}

void	Cube::getColor()
{
	int pos = 0;
	//0-8
	color[pos++] = cornerFace(ulb, 0);
	color[pos++] = edgeFace(ub, 0);
	color[pos++] = cornerFace(ubr, 0);
	color[pos++] = edgeFace(ul, 0);
	color[pos++] = 'U';
	color[pos++] = edgeFace(ur, 0);
	color[pos++] = cornerFace(ufl, 0);
	color[pos++] = edgeFace(uf, 0);
	color[pos++] = cornerFace(urf, 0);
	//9-17
	color[pos++] = cornerFace(dlf, 2);
	color[pos++] = edgeFace(fl, 0);
	color[pos++] = cornerFace(ufl, 1);
	color[pos++] = edgeFace(df, 1);
	color[pos++] = 'F';
	color[pos++] = edgeFace(uf, 1);
	color[pos++] = cornerFace(dfr, 1);
	color[pos++] = edgeFace(fr, 0);
	color[pos++] = cornerFace(urf, 2);
	//18-26
	color[pos++] = cornerFace(drb, 1);
	color[pos++] = edgeFace(dr, 1);
	color[pos++] = cornerFace(dfr, 2);
	color[pos++] = edgeFace(br, 1);
	color[pos++] = 'R';	
	color[pos++] = edgeFace(fr, 1);
	color[pos++] = cornerFace(ubr, 2);
	color[pos++] = edgeFace(ur, 1);
	color[pos++] = cornerFace(urf, 1);
	//27-35
	color[pos++] = cornerFace(dbl, 0);
	color[pos++] = edgeFace(db, 0);
	color[pos++] = cornerFace(drb, 0);
	color[pos++] = edgeFace(dl, 0);
	color[pos++] = 'D';
	color[pos++] = edgeFace(dr, 0);
	color[pos++] = cornerFace(dlf, 0);
	color[pos++] = edgeFace(df, 0);
	color[pos++] = cornerFace(dfr, 0);
	//36-44
	color[pos++] = cornerFace(dbl, 1);
	color[pos++] = edgeFace(bl, 0);
	color[pos++] = cornerFace(ulb, 2);
	color[pos++] = edgeFace(db, 1);
	color[pos++] = 'B';
	color[pos++] = edgeFace(ub, 1);
	color[pos++] = cornerFace(drb, 2);
	color[pos++] = edgeFace(br, 0);
	color[pos++] = cornerFace(ubr, 1);
	//45-53
	color[pos++] = cornerFace(dbl, 2);
	color[pos++] = edgeFace(dl, 1);
	color[pos++] = cornerFace(dlf, 1);
	color[pos++] = edgeFace(bl, 1);
	color[pos++] = 'L';
	color[pos++] = edgeFace(fl, 1);
	color[pos++] = cornerFace(ulb, 1);
	color[pos++] = edgeFace(ul, 1);
	color[pos++] = cornerFace(ufl, 2);
}

void   Cube::setColor(char* walls) {
	cPos[urf] = cornerID(walls[8] , walls[17] , walls[26]);
	cPos[ubr] = cornerID(walls[2] , walls[24] , walls[44]);
	cPos[dlf] = cornerID(walls[9] , walls[33] , walls[47]);
	cPos[dfr] = cornerID(walls[15] , walls[20] , walls[35]);
	cPos[ulb] = cornerID(walls[0] , walls[38] , walls[50]);
	cPos[ufl] = cornerID(walls[6] , walls[11] , walls[53]);
	cPos[drb] = cornerID(walls[18] , walls[29] , walls[42]);
	cPos[dbl] = cornerID(walls[27] , walls[36] , walls[45]);

	
	
	ePos[uf] = edgeID(walls[7], walls[14]);//7 14
	ePos[ur] = edgeID(walls[5] , walls[25]);//5 25
	ePos[ub] = edgeID(walls[1] , walls[41]);//1 41
	ePos[ul] = edgeID(walls[3] , walls[52]);//3 52
	ePos[df] = edgeID(walls[34] , walls[12]);//34 12
	ePos[dr] = edgeID(walls[32] , walls[19]);//32 19
	ePos[db] = edgeID(walls[28] , walls[39]);//28 39 
	ePos[dl] = edgeID(walls[30] , walls[46]);//30 46
	ePos[fr] = edgeID(walls[16] , walls[23]);//16 23
	ePos[br] = edgeID(walls[43] , walls[21]);//43 21
	ePos[bl] = edgeID(walls[37] , walls[48]);//37 48
	ePos[fl] = edgeID(walls[10] , walls[50]);//10 50
	
}
char Cube::setEdgeOri(char firstFace, string key) {
	if (key[0] == firstFace)
		return 0;
	else
		return 1;
}
edge Cube::edgeID(char face1, char face2) {
	int sum = int(face1 + face2);
	switch (sum)
	{
	case ('U' + 'F'):
		eOri[uf] = setEdgeOri(face1, edgeNames[uf]);
		return uf;
		break;
	case ('U' + 'R'):
		eOri[ur] = setEdgeOri(face1, edgeNames[ur]);
		return ur;
		break;
	case ('U' + 'B'):
		eOri[ub] = setEdgeOri(face1, edgeNames[ub]);
		return ub;
		break;
	case ('U' + 'L'):
		eOri[ul] = setEdgeOri(face1, edgeNames[ul]);
		return ul;
		break;
	case ('D' + 'F'):
		eOri[df] = setEdgeOri(face1, edgeNames[df]);
		return df;
		break;
	case ('D' + 'R'):
		eOri[dr] = setEdgeOri(face1, edgeNames[dr]);
		return dr;
		break;
	case ('D' + 'B'):
		eOri[db] = setEdgeOri(face1, edgeNames[db]);
		return db;
		break;
	case ('D' + 'L'):
		eOri[dl] = setEdgeOri(face1, edgeNames[dl]);
		return dl;
		break;
	case ('F' + 'R'):
		eOri[fr] = setEdgeOri(face1, edgeNames[fr]);
		return fr;
		break;
	case ('B' + 'R'):
		eOri[br] = setEdgeOri(face1, edgeNames[br]);
		return br;
		break;
	case ('B' + 'L'):
		eOri[bl] = setEdgeOri(face1, edgeNames[bl]);
		return bl;
		break;
	case ('F' + 'L'):
		eOri[fl] = setEdgeOri(face1, edgeNames[fl]);
		return fl;
		break;
	default:
		break;
	}
}

char    Cube::setCornerOri(char firstFace, string key) {
	if (key[0] == firstFace)
		return 1;
	else if (key[1] == firstFace)
		return 1;
	else
		return 2;
}
corner Cube::cornerID(char face1, char face2, char face3) {
	int sum = int(face1 + face2 + face3);
	switch (sum)
	{
	case ('U' + 'R' + 'F'):
		cOri[urf] = setCornerOri(face1, cornerNames[urf]);
		return urf;
		break;
	case ('U' + 'B' + 'R'):
		cOri[ubr] = setCornerOri(face1, cornerNames[ubr]);
		return ubr;
		break;
	case ('D' + 'L' + 'F'):
		cOri[dlf] = setCornerOri(face1, cornerNames[dlf]);
		return dlf;
		break;
	case ('D' + 'F' + 'R'):
		cOri[dfr] = setCornerOri(face1, cornerNames[dfr]);
		return dfr;
		break;
	case ('U' + 'L' + 'B'):
		cOri[ulb] = setCornerOri(face1, cornerNames[ulb]);
		return ulb;
		break;
	case ('U' + 'F' + 'L'):
		cOri[ufl] = setCornerOri(face1, cornerNames[ufl]);
		return ufl;
		break;
	case ('D' + 'R' + 'B'):
		cOri[drb] = setCornerOri(face1, cornerNames[drb]);
		return drb;
		break;
	case ('D' + 'B' + 'L'):
		cOri[dbl] = setCornerOri(face1, cornerNames[dbl]);
		return dbl;
		break;
	default:
		break;
	}
}