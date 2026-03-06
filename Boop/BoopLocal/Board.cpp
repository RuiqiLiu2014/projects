//
// Created by whale on 2/27/26.
//

#include "Board.h"

#include <optional>
#include <stdexcept>

std::optional<std::vector<Piece>> Board::placePiece(Point p, Piece piece) {
    if (!p.inBounds()) {
        throw std::invalid_argument("Piece is not in bounds");
    }

    if (!isEmpty(p)) {
        return std::nullopt;
    }

    board[p.r][p.c] = piece;
    return boop(p);
}

std::vector<Piece> Board::boop(Point p) {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::boop");
    }

    std::vector<Piece> fallen;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            auto adjacentPoint = Point(p.r + i, p.c + j);
            auto furtherPoint = Point(p.r + 2 * i, p.c + 2 * j);

            if (adjacentPoint.inBounds() && !isEmpty(adjacentPoint)) {
                if (furtherPoint.inBounds() && isEmpty(furtherPoint)) {
                    if (isCat(p) || isKitten(adjacentPoint)) {
                        Piece piece = removePiece(adjacentPoint);
                        board[furtherPoint.r][furtherPoint.c] = piece;
                    }
                } else if (!furtherPoint.inBounds()) {
                    if (isCat(p) || isKitten(adjacentPoint)) {
                        fallen.push_back(removePiece(adjacentPoint));
                    }
                }
            }
        }
    }

    return fallen;
}

std::vector<Piece> Board::graduate(int playerIndex) {
    std::vector<Piece> fallen;
    auto groups = findGroups(playerIndex);

    if (!groups.empty()) {
        for (Point p : groups[0]) {
            fallen.push_back(removePiece(p));
        }
    }
    return fallen;
}

std::vector<std::array<Point, 3>> Board::findGroups(int playerIndex) const {
    std::vector<std::array<Point, 3>> groups;

    auto checkAndAdd = [&](Point p1, Point p2, Point p3) {
        // Only add if all three pieces belong to the requested player
        if (getOwner(pieceAt(p1)) == playerIndex &&
            getOwner(pieceAt(p2)) == playerIndex &&
            getOwner(pieceAt(p3)) == playerIndex) {
            groups.push_back({p1, p2, p3});
            }
    };

    // Iterate through the board (same 4 directions as before)
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            if (c <= 3) checkAndAdd(Point{r, c}, Point{r, c + 1}, Point{r, c + 2});
            if (r <= 3) checkAndAdd(Point{r, c}, Point{r + 1, c}, Point{r + 2, c});
            if (r <= 3 && c <= 3) checkAndAdd(Point{r, c}, Point{r + 1, c + 1}, Point{r + 2, c + 2});
            if (r >= 2 && c <= 3) checkAndAdd(Point{r, c}, Point{r - 1, c + 1}, Point{r - 2, c + 2});
        }
    }

    return groups;
}

Piece Board::removePiece(Point p) {
    Piece piece = board[p.r][p.c];
    board[p.r][p.c] = Piece::EMPTY;
    return piece;
}

int Board::winner() const {
    auto p0Groups = findGroups(0);
    auto p1Groups = findGroups(1);

    int p0Points = 0;
    int p1Points = 0;

    // Filter Player 0's groups: only count it if all 3 are cats
    for (const auto& group : p0Groups) {
        if (isCat(group[0]) && isCat(group[1]) && isCat(group[2])) {
            p0Points++;
        }
    }

    // Filter Player 1's groups
    for (const auto& group : p1Groups) {
        if (isCat(group[0]) && isCat(group[1]) && isCat(group[2])) {
            p1Points++;
        }
    }

    if (p0Points > p1Points) {
        return 0;
    }
    if (p1Points > p0Points) {
        return 1;
    }

    // Keep your original 8-cat fallback logic
    int p0CatCount = 0;
    int p1CatCount = 0;

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            if (pieceAt(Point{r, c}) == Piece::P0_CAT) {
                p0CatCount++;
            } else if (pieceAt(Point{r, c}) == Piece::P1_CAT) {
                p1CatCount++;
            }
        }
    }

    if (p0CatCount == 8) {
        return 0;
    }
    if (p1CatCount == 8) {
        return 1;
    }

    return -1;
}

Piece Board::pieceAt(Point p) const {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::pieceAt");
    }

    return board[p.r][p.c];
}

bool Board::isEmpty(Point p) const {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::isEmpty");
    }

    return board[p.r][p.c] == Piece::EMPTY;
}

bool Board::isCat(Point p) const {
    return pieceAt(p) == Piece::P0_CAT || pieceAt(p) == Piece::P1_CAT;
}

bool Board::isKitten(Point p) const {
    return pieceAt(p) == Piece::P0_KITTEN || pieceAt(p) == Piece::P1_KITTEN;
}