#include <functional>
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
    virtual ~Piece() {}

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
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override { // overrider den virtuelle metoden
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

  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(Color color)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;
  function<void(const Piece &piece, const string &square)> after_piece_move;

  /// Move a chess piece if it is a valid move
  bool move_piece(const string &from, const string &to) {
    int from_x = from.at(0) - 'a';
    int from_y = stoi(string() + from.at(1)) - 1;
    int to_x = to.at(0) - 'a';
    int to_y = stoi(string() + to.at(1)) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if(piece) {
      if(piece->valid_move(from_x, from_y, to_x, to_y)) {
        if(on_piece_move)
          on_piece_move(*piece, from, to);
        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if(piece_at_to_pos) {
          if(piece->color != piece_at_to_pos->color) {
            if(on_piece_removed)
              on_piece_removed(*piece_at_to_pos, to);
            if(auto king = dynamic_cast<King *>(piece_at_to_pos.get())) {
              if(on_lost_game)
                on_lost_game(king->color);
            }
          }
          else {
            // piece in the from square has the same color as the piece in the to square
            if(on_piece_move_invalid)
              on_piece_move_invalid(*piece, from, to);
            return false;
          }
        }
        piece_at_to_pos = move(piece);
        if(after_piece_move) {
          after_piece_move(*piece_at_to_pos, to);
        }
        return true;
      }
      else {
        if(on_piece_move_invalid)
          on_piece_move_invalid(*piece, from, to);
        return false;
      }
    }
    else {
      if(on_piece_move_missing)
        on_piece_move_missing(from);
      return false;
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) {
    board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.type() << " is being removed from " << square << endl;
    };
    board.on_lost_game = [](ChessBoard::Color color) {
      if(color == ChessBoard::Color::WHITE)
        cout << "Black";
      else
        cout << "White";
      cout << " won the game" << endl;
    };
    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };
    board.on_piece_move_missing = [](const string &square) {
      cout << "no piece at " << square << endl;
    };
    board.after_piece_move = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.type() << " moved to " << square << endl;
    };
  };
};

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  board.squares.at(4).at(0); // is the same as board.squares[4][0] but with range check
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
