#include <bits/stdc++.h>
using namespace std;

const int KING = 0, QUEEN = 1, ROOK = 2, BISHOP = 3, KNIGHT = 4, PAWN = 5;

struct Piece {
    int type, color; // color: 0 white, 1 black; type: -1 empty
};

struct Board {
    Piece a[8][8];
};

struct Move {
    int fr, fc, tr, tc;
    int promote; // -1 表示不升变，否则为升变后的棋子类型
};

Piece emptyPiece{-1, -1};

int typeFromString(string s) {
    for (char &c : s) c = tolower(c);
    if (s == "king") return KING;
    if (s == "queen") return QUEEN;
    if (s == "rook") return ROOK;
    if (s == "bishop") return BISHOP;
    if (s == "knight") return KNIGHT;
    if (s == "pawn") return PAWN;
    return -1;
}

bool inBoard(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

bool canAttack(const Board &b, const Piece &p, int pr, int pc, int tr, int tc) {
    int dr = tr - pr, dc = tc - pc;
    if (dr == 0 && dc == 0) return false;

    if (p.type == KING) {
        return abs(dr) <= 1 && abs(dc) <= 1;
    }

    if (p.type == QUEEN) {
        if (!(dr == 0 || dc == 0 || abs(dr) == abs(dc))) return false;
        int steps = max(abs(dr), abs(dc));
        int sr = (dr > 0 ? 1 : (dr < 0 ? -1 : 0));
        int sc = (dc > 0 ? 1 : (dc < 0 ? -1 : 0));
        for (int i = 1; i < steps; ++i) {
            int nr = pr + sr * i, nc = pc + sc * i;
            if (b.a[nr][nc].type != -1) return false;
        }
        return true;
    }

    if (p.type == ROOK) {
        if (!(dr == 0 || dc == 0)) return false;
        int steps = max(abs(dr), abs(dc));
        int sr = (dr > 0 ? 1 : (dr < 0 ? -1 : 0));
        int sc = (dc > 0 ? 1 : (dc < 0 ? -1 : 0));
        for (int i = 1; i < steps; ++i) {
            int nr = pr + sr * i, nc = pc + sc * i;
            if (b.a[nr][nc].type != -1) return false;
        }
        return true;
    }

    if (p.type == BISHOP) {
        if (abs(dr) != abs(dc)) return false;
        int steps = abs(dr);
        int sr = (dr > 0 ? 1 : (dr < 0 ? -1 : 0));
        int sc = (dc > 0 ? 1 : (dc < 0 ? -1 : 0));
        for (int i = 1; i < steps; ++i) {
            int nr = pr + sr * i, nc = pc + sc * i;
            if (b.a[nr][nc].type != -1) return false;
        }
        return true;
    }

    if (p.type == KNIGHT) {
        return (abs(dr) == 1 && abs(dc) == 2) || (abs(dr) == 2 && abs(dc) == 1);
    }

    if (p.type == PAWN) {
        if (p.color == 0) { // 白兵向上攻击
            return dr == 1 && abs(dc) == 1;
        } else { // 黑兵向下攻击
            return dr == -1 && abs(dc) == 1;
        }
    }

    return false;
}

bool isAttacked(const Board &b, int r, int c, int attackerColor) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece p = b.a[i][j];
            if (p.color == attackerColor && p.type != -1) {
                if (canAttack(b, p, i, j, r, c)) return true;
            }
        }
    }
    return false;
}

pair<int, int> findKing(const Board &b, int color) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (b.a[i][j].type == KING && b.a[i][j].color == color) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<Move> generateMoves(const Board &b, int color) {
    vector<Move> moves;
    int enemy = 1 - color;
    int pawnDir = (color == 0 ? 1 : -1);

    int dirs[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece p = b.a[r][c];
            if (p.color != color) continue;

            if (p.type == KING) {
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = r + dr, nc = c + dc;
                        if (!inBoard(nr, nc)) continue;

                        Piece target = b.a[nr][nc];
                        if (target.color == color) continue;
                        if (target.color != -1 && target.type == KING) continue;

                        moves.push_back({r, c, nr, nc, -1});
                    }
                }
            } else if (p.type == QUEEN) {
                for (int d = 0; d < 8; ++d) {
                    int nr = r + dirs[d][0], nc = c + dirs[d][1];
                    while (inBoard(nr, nc)) {
                        Piece target = b.a[nr][nc];
                        if (target.color == color) break;
                        if (target.color != -1 && target.type == KING) break;

                        moves.push_back({r, c, nr, nc, -1});

                        if (target.color != -1) break;
                        nr += dirs[d][0];
                        nc += dirs[d][1];
                    }
                }
            } else if (p.type == ROOK) {
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dirs[d][0], nc = c + dirs[d][1];
                    while (inBoard(nr, nc)) {
                        Piece target = b.a[nr][nc];
                        if (target.color == color) break;
                        if (target.color != -1 && target.type == KING) break;

                        moves.push_back({r, c, nr, nc, -1});

                        if (target.color != -1) break;
                        nr += dirs[d][0];
                        nc += dirs[d][1];
                    }
                }
            } else if (p.type == BISHOP) {
                for (int d = 4; d < 8; ++d) {
                    int nr = r + dirs[d][0], nc = c + dirs[d][1];
                    while (inBoard(nr, nc)) {
                        Piece target = b.a[nr][nc];
                        if (target.color == color) break;
                        if (target.color != -1 && target.type == KING) break;

                        moves.push_back({r, c, nr, nc, -1});

                        if (target.color != -1) break;
                        nr += dirs[d][0];
                        nc += dirs[d][1];
                    }
                }
            } else if (p.type == KNIGHT) {
                int offsets[8][2] = {
                    {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
                };
                for (auto &off : offsets) {
                    int nr = r + off[0], nc = c + off[1];
                    if (!inBoard(nr, nc)) continue;

                    Piece target = b.a[nr][nc];
                    if (target.color == color) continue;
                    if (target.color != -1 && target.type == KING) continue;

                    moves.push_back({r, c, nr, nc, -1});
                }
            } else if (p.type == PAWN) {
                // 直走
                int nr = r + pawnDir;
                if (inBoard(nr, c) && b.a[nr][c].type == -1) {
                    if (nr == 0 || nr == 7) {
                        for (int pt = QUEEN; pt <= KNIGHT; ++pt) {
                            moves.push_back({r, c, nr, c, pt});
                        }
                    } else {
                        moves.push_back({r, c, nr, c, -1});
                    }
                }

                // 斜吃
                for (int dc : {-1, 1}) {
                    int nc = c + dc;
                    if (!inBoard(nr, nc)) continue;

                    Piece target = b.a[nr][nc];
                    if (target.color == enemy && target.type != KING) {
                        if (nr == 0 || nr == 7) {
                            for (int pt = QUEEN; pt <= KNIGHT; ++pt) {
                                moves.push_back({r, c, nr, nc, pt});
                            }
                        } else {
                            moves.push_back({r, c, nr, nc, -1});
                        }
                    }
                }
            }
        }
    }

    return moves;
}

bool isLegalMove(Board b, const Move &m, int color, int king_r, int king_c) {
    Piece moved = b.a[m.fr][m.fc];
    bool wasKing = (moved.type == KING);

    // 临时移动棋子
    b.a[m.tr][m.tc] = emptyPiece;
    b.a[m.fr][m.fc] = emptyPiece;

    if (m.promote != -1) moved.type = m.promote;
    b.a[m.tr][m.tc] = moved;

    int nkr = wasKing ? m.tr : king_r;
    int nkc = wasKing ? m.tc : king_c;

    return !isAttacked(b, nkr, nkc, 1 - color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, p;
        cin >> n >> p;

        Board board;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board.a[i][j] = emptyPiece;
            }
        }

        for (int i = 0; i < n; ++i) {
            string s;
            int f, x, y;
            cin >> s >> f >> x >> y;

            int type = typeFromString(s);
            int r = y - 1;
            int c = x - 1;

            board.a[r][c] = {type, f};
        }

        pair<int, int> kingPos = findKing(board, p);
        int king_r = kingPos.first;
        int king_c = kingPos.second;

        int enemy = 1 - p;

        // 如果没有被将军，一定不是将死
        if (!isAttacked(board, king_r, king_c, enemy)) {
            cout << "Not Checkmate\n";
            continue;
        }

        vector<Move> moves = generateMoves(board, p);
        bool hasLegalMove = false;

        for (const Move &m : moves) {
            if (isLegalMove(board, m, p, king_r, king_c)) {
                hasLegalMove = true;
                break;
            }
        }

        if (hasLegalMove) {
            cout << "Not Checkmate\n";
        } else {
            if (p == 0) cout << "White\n";
            else cout << "Black\n";
        }
    }

    return 0;
}
