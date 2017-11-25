#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color {
    WHITE,
    BLACK
  };

  class Piece {
  public:
    Piece(Color color) : color(color) {}

    Color color;
    string color_string() const {
      if(color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}

    string type() const override {
      return color_string() + " " + "king";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int xDiff = abs(to_x - from_x);
      int yDiff = abs(to_y - from_y);
      return ((xDiff == 1 && yDiff == 0) || (xDiff == 0 && yDiff == 1)) || (xDiff == 1 && yDiff == 1);
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}

    string type() const override {
      return color_string() + " " + "knight";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int xDiff = abs(to_x - from_x);
      int yDiff = abs(to_y - from_y);
      return (xDiff == 1 && yDiff == 2) || (yDiff == 1 && xDiff == 2);
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for(auto &square_column : squares)
      square_column.resize(8);
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move
  bool move_piece(const string &from, const string &to) {
    int from_x = from.at(0) - 'a';
    int from_y = stoi(string() + from.at(1)) - 1;
    int to_x = to.at(0) - 'a';
    int to_y = stoi(string() + to.at(1)) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if(piece) {
      if(piece->valid_move(from_x, from_y, to_x, to_y)) {
        cout << piece->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if(piece_at_to_pos) {
          cout << piece_at_to_pos->type() << " is being removed from " << to << endl;
          if(auto king = dynamic_cast<King *>(piece_at_to_pos.get()))
            cout << king->color_string() << " lost the game" << endl;
        }
        piece_at_to_pos = move(piece);
        return true;
      }
      else {
        cout << "can not move " << piece->type() << " from " << from << " to " << to << endl;
        return false;
      }
    }
    else {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
};

int main() {
  ChessBoard board;

  //board.squares.at(4).at(0) is the same as board.squares[4][0] but with range check
  board.squares.at(4).at(0) = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares.at(1).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares.at(6).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares.at(4).at(7) = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares.at(1).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares.at(6).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
