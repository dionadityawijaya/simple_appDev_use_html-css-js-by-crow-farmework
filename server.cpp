#include "crow.h"
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    crow::SimpleApp app;

    // Serve static file (index.html)
    CROW_ROUTE(app, "/")([]
                         {
                             std::string content = readFile("templates/index.html");
                             return crow::response(content);
                         });

    // Route API example
    CROW_ROUTE(app, "/hello")([](){
        return crow::response("Hello, world!");
    });

    app.port(18080).multithreaded().run();
}
