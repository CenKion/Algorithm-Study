#include <bits/stdc++.h>

using namespace std;

const int KING = 0, QUEEN = 1, ROOK = 2, BISHOP = 3,KNIGHT = 4,PAWN = 5;

int dir[8][2]={
	{1 ,0},{-1 ,0},{0 ,1},{0 ,-1},
	{1 ,1},{1 ,-1},{-1 ,1},{-1 ,-1}
};

int KnightMove[8][2]{
	{1 ,-2},{1 ,2},{-1 ,2},{-1 ,-2},
	{2 ,-1},{2 ,1},{-2 ,1},{-2 ,-1}
};

struct Piece{
	int type;
	int color;
};

struct Board{
	Piece a[8][8];
};

struct Move{
	int fr , fc , tr ,tc;
	int promote;
};

Piece emptyPiece = {-1, -1};

int typeFromString(string s){
	for(char &c:s) c = tolower(c);
	if(s == "king") return KING;
	if(s == "queen") return QUEEN;
	if(s == "rook") return ROOK;
	if(s == "bishop") return BISHOP;
	if(s == "knight") return KNIGHT;
	if(s == "pawn") return PAWN;
	return -1;
}

pair <int,int> findKing(const Board& b,int color){
	for(int i = 0;i < 8;i ++){
		for(int j = 0;j < 8;j ++){
			if(b.a[i][j].color == color && b.a[i][j].type == KING){
				return {i ,j};
			}
		}
	}
	return {-1 ,-1};
}

bool canAttack(const Board& b,const Piece& p,int pr, int pc, int tr, int tc){
	int dr = tr - pr;
	int dc = tc - pc;
	if(dr == 0 && dc == 0) return 0;
	
	if(p.type == KING){
		return (abs(dr) <= 1 && abs(dc) <= 1);
	}
	
	if(p.type == QUEEN){
		if(!(abs(dr) == abs(dc) || dr * dc == 0)) return 0;
		int steps = max(abs(dr),abs(dc));
		int sr = (dr > 0)?1 : ((dr < 0)? -1 : 0);
		int sc = (dc > 0)?1 : ((dc < 0)? -1 : 0);
		int nr ,nc;
		for(int i = 1;i < steps;i ++){
			nr = pr + i * sr;
			nc = pc + i * sc;
			if(b.a[nr][nc].type != -1){
				return 0;
			}
		}
		return 1;
	}
	
	if(p.type == ROOK){
		if(!(dr * dc == 0)) return 0;
		int steps = max(abs(dr),abs(dc));
		int sr = (dr > 0)?1 : ((dr < 0)? -1 : 0);
		int sc = (dc > 0)?1 : ((dc < 0)? -1 : 0);
		int nr ,nc;
		for(int i = 1;i < steps;i ++){
			nr = pr + i * sr;
			nc = pc + i * sc;
			if(b.a[nr][nc].type != -1){
				return 0;
			}
		}
		return 1;
	}
	
	if(p.type == BISHOP){
		if(abs(dr) != abs(dc)) return 0;
		int steps = abs(dr);
		int sr = (dr > 0)?1 : -1;
		int sc = (dc > 0)?1 : -1;
		int nr ,nc;
		for(int i = 1;i < steps;i ++){
			nr = pr + i * sr;
			nc = pc + i * sc;
			if(b.a[nr][nc].type != -1){
				return 0;
			}
		}
		return 1;
	}
	
	if(p.type == KNIGHT){
		return abs(dr * dc) == 2;	
	}
	
	if(p.type == PAWN){
		if(abs(dr) != 1 || abs(dc) != 1) return 0;
		if(p.color == 0) return dc == 1;
		if(p.color == 1) return dc == -1;
	}
	return 0;
}

bool isAttacked(const Board& b,int r,int c,int attackerColor){
	for(int i = 0;i < 8;i ++){
		for(int j = 0;j < 8;j ++){
			Piece p = b.a[i][j];
			if(p.color == attackerColor && canAttack(b ,p ,i ,j ,r ,c)) return 1;
		}
	}
	return 0;
}

bool inBoard(int r,int c){
	return r < 8 && r >= 0 && c < 8 && c >= 0;
}

vector <Move> generateMoves(const Board& b,int color){
	vector <Move> moves;
	int nr,nc;
	int enemy = 1 - color;
	for(int r = 0;r < 8;r ++){
		for(int c = 0;c < 8;c ++){
			if(b.a[r][c].color != color) continue;
			if(b.a[r][c].type == KING){
				for(int d = 0;d < 8;d ++){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if(!inBoard(nr,nc)) continue;
					Piece target = b.a[nr][nc];
					if(target.color == color) continue;
					if (target.color != -1 && target.type == KING) continue;
					moves.push_back({r ,c , nr ,nc ,-1});
				}
			}
			else if(b.a[r][c].type == QUEEN){
				for(int d = 0;d < 8;d ++){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					while(inBoard(nr ,nc)){
						Piece target = b.a[nr][nc];
						if(target.color == color) break;
						if (target.color != -1 && target.type == KING) break;
						moves.push_back({r,c,nr,nc,-1});
						if(target.color != -1) break;
						nr += dir[d][0];
						nc += dir[d][1];
					}
				}
			}
			else if(b.a[r][c].type == ROOK){
				for(int d = 0;d < 4;d ++){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					while(inBoard(nr ,nc)){
						Piece target = b.a[nr][nc];
						if(target.color == color) break;
						if (target.color != -1 && target.type == KING) break;
						moves.push_back({r,c,nr,nc,-1});
						if(target.color != -1) break;
						nr += dir[d][0];
						nc += dir[d][1];
					}
				}
			}
			else if(b.a[r][c].type == BISHOP){
				for(int d = 4;d < 8;d ++){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					while(inBoard(nr ,nc)){
						Piece target = b.a[nr][nc];
						if(target.color == color) break;
						if (target.color != -1 && target.type == KING) break;
						moves.push_back({r,c,nr,nc,-1});
						if(target.color != -1) break;
						nr += dir[d][0];
						nc += dir[d][1];
					}
				}
			}
			else if(b.a[r][c].type == KNIGHT){
				for(int d = 0;d < 8;d ++){
					nr = r + KnightMove[d][0];
					nc = c + KnightMove[d][1];
					if(!inBoard(nr ,nc)) continue;
					Piece target = b.a[nr][nc];
					if(target.color == color) continue;
					if (target.color != -1 && target.type == KING) continue;
					moves.push_back({r ,c ,nr ,nc ,-1});
				}
			}
			else if(b.a[r][c].type == PAWN){
				int PawnDir = (b.a[r][c].color == 0)? 1 : -1;
				nc = c + PawnDir;
				if(inBoard(r,nc) && b.a[r][nc].color == -1){
					if(nc == 7 || nc == 0){
						for(int pt = QUEEN;pt < PAWN;pt ++){
							moves.push_back({r ,c ,r ,nc ,pt});
						}
					}
					else{
						moves.push_back({r ,c ,r ,nc ,-1});
					}
				}
				
				for(int dr : {-1 ,1}){
					nr = r + dr;
					if(!inBoard(nr,nc)) continue;
					Piece target = b.a[nr][nc];
					if(target.color == enemy&& target.type != KING){
						if(nc == 7 || nc == 0){
							for(int pt = QUEEN;pt < PAWN;pt ++){
								moves.push_back({r ,c ,nr ,nc ,pt});
							}
						}
						else{
							moves.push_back({r ,c ,nr ,nc ,-1});
						}
					}
				}
			}
		}
	}
	return moves;
}

bool isLegalMove(Board b,const Move& m,int color,int king_r,int king_c){
	Piece formerPiece = b.a[m.fr][m.fc];
	b.a[m.fr][m.fc] = emptyPiece;
	if(m.promote != -1) formerPiece.type = m.promote;
	b.a[m.tr][m.tc] = formerPiece;
	
	king_r = (formerPiece.type == KING)? m.tr : king_r;
	king_c = (formerPiece.type == KING)? m.tc : king_c;
	
	return !isAttacked(b ,king_r, king_c, 1 - color);
}

int main(){
	int T;
	cin >> T;
	int n ,p ,f ,x ,y;
	int r ,c;
	string s;
	Board b;
	while(T --){
		for(int i = 0;i < 8;i ++){
			for(int j = 0;j < 8;j ++){
				b.a[i][j] = emptyPiece;
			}
		}
		
		cin >> n >> p;
		for(int i = 0;i < n;i ++){
			cin >> s >> f >> x>> y;
			r = x - 1;
			c = y - 1;
			b.a[r][c].color = f;
			b.a[r][c].type = typeFromString(s);
		}
		
		pair <int,int> kingPos = findKing(b ,p);
		int king_r = kingPos.first;
		int king_c = kingPos.second;
		
		if(!isAttacked(b ,king_r ,king_c ,1-p)){
			cout << "Not Checkmate\n";
			continue;
		}
		
		vector <Move> moves = generateMoves(b ,p);
		bool hasLegalMove = 0;
		for(Move& m:moves){
			if(isLegalMove(b ,m ,p , king_r ,king_c)){
				hasLegalMove = 1;
				break;
			}
		}
		
		if(hasLegalMove){
			cout << "Not Checkmate\n";
		}
		else{
			if(p == 0){
				cout << "White\n";
			}
			else{
				cout << "Black\n";
			}
		}
	}
	
	return 0;
}
