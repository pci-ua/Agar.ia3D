#include <string>
#include <iostream>

class TestError: public std::exception
{
public:
    explicit TestError(const char* message)
        : msg_(message) {}
    explicit TestError(const std::string& message)
        : msg_(message) {}

    virtual ~TestError() noexcept {}
    virtual const char* what() const noexcept {
       return msg_.c_str();
    }

protected:
    std::string msg_;
};

void log_noError(std::string groupe,std::string categorie,int step,int max) {
  std::cout << " ✓ " << groupe << " : " << categorie << " (" << step << "/" << max << ") " << std::endl;
}
