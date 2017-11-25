#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                       if(!ec) {
                         istream read_stream(read_buffer.get());
                         std::string message;
                         getline(read_stream, message);
                         message.pop_back();

                         cout << "Message from a connected client: " << message << endl;
                         if(message == "exit")
                           return;
                         if(message == "GET / HTTP/1.1") {
                           message = "HTTP/1.1 200 OK"
                                     "Content-Type: text/html"
                                     "Connection: Closed\r\n\r\n"
                                     "<html>"
                                     "<body>"
                                     "<h1>Dette er hovedsiden!</h1>"
                                     "</body>"
                                     "</html>";
                         }
                         else if(message == "GET /en_side HTTP/1.1") {
                           message = "HTTP/1.1 200 OK"
                                     "Content-Type: text/html"
                                     "Connection: Closed\r\n\r\n"
                                     "<html>"
                                     "<body>"
                                     "<h1>Dette er en side</h1>"
                                     "</body>"
                                     "</html>";
                         }
                         else {
                           message = "HTTP/1.1 404 Not Found"
                                     "Content-Type: text/html"
                                     "Connection: Closed\r\n\r\n"
                                     "<html>"
                                     "<body>"
                                     "<h1>404 Not Found</h1>"
                                     "</body>"
                                     "</html> ";
                         }

                         auto write_buffer = make_shared<boost::asio::streambuf>();
                         ostream write_stream(write_buffer.get());

                         write_stream << message << "\r\n";
                         cout << "Sending to client: " << message << endl;

                         async_write(connection->socket, *write_buffer,
                                     [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                       if(!ec)
                                         handle_request(connection);
                                     });
                       }
                     });
  }

  void accept() {
    auto connection = make_shared<Connection>(io_service);

    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      if(!ec) {
        handle_request(connection);
      }
    });
  }

public:
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();
    io_service.run();
  }
};

int main() {
  EchoServer echo_server;

  cout << "Starting echo server" << endl
       << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;

  echo_server.start();
}
