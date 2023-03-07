#include <vector>

class LibraySystem {
public:
    std::vector<std:: string> bookname;
    std::vector<std:: string> author;
    std::vector<std:: string> type;

    void basiclibray();
    void login(int choice);
    void addBook();
    void viewbooks();
    void deletebook();
    void showmenu();

};
